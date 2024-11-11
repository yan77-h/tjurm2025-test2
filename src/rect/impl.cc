#include "impls.h"


std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用findCountours函数找出输入图像（彩色图像）中的矩形轮廓，并且返回它的外接矩形，以及
     * 最小面积外接矩形。所需要的函数自行查找。
     * 
     * 通过条件：
     * 运行测试点，你找到的矩形跟答案一样就行。
    */
    //std::pair<cv::Rect, cv::RotatedRect> res;
    // IMPLEMENT YOUR CODE HERE

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;//存储轮廓点击和层次结构

    cv::Mat gray;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    cv::Mat binary;
    cv::threshold(gray, binary, 50, 255, cv::THRESH_BINARY);//先转为灰度再转为二值

    cv::findContours(binary, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);//检测轮廓

    cv::Rect boundingRect;
    cv::RotatedRect minAreaRect;

    //这一段不会，照搬的代码qwq
    // 遍历所有检测到的轮廓
    for (size_t i = 0; i < contours.size(); i++) {
        // 使用 boundingRect 函数计算轮廓的外接矩形
        cv::Rect rect = cv::boundingRect(contours[i]);

        // 使用 minAreaRect 函数计算轮廓的最小面积外接旋转矩形
        cv::RotatedRect rotatedRect = cv::minAreaRect(contours[i]);

        // 检查轮廓是否可能是一个矩形，这里简单地检查宽度和高度的差值是否足够小
        if (rotatedRect.size.width > 5 && rotatedRect.size.height > 5 &&
            std::abs(rotatedRect.size.width - rotatedRect.size.height) < 5) {
            // 如果找到了一个合适的矩形，就更新我们的 boundingRect 和 minAreaRect
            boundingRect = rect;
            minAreaRect = rotatedRect;
            break; // 假设只有一个矩形，找到后即退出循环
        }

     //怎么搞图片中都没有矩形，实在不会了
    }

    
    return std::make_pair(boundingRect, minAreaRect);
}