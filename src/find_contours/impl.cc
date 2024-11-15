#include "impls.h"


std::vector<std::vector<cv::Point>> find_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用cv::findContours函数，从输入图像（3个通道）中找出所有的最内层轮廓。
     * 将它们保存起来作为函数返回值就行。contours的中文意思就是轮廓。
     * 
     * 提示：
     * 1. 使用cv::imshow来查看输入图像。
     * 2. 使用cv::drawContours来在一张图上绘制轮廓。
     * 3. 直接使用原图一般而言不利于轮廓的寻找，可以做一些简单的处理。
     * 4. findContours函数可以返回轮廓的层次结构，理解层次结构的保存方式并使用它（重点）。
     * 
     * 通过条件：
     * 运行测试点，你找到的轮廓与答案的轮廓一样就行。
     */
    
    std::vector<std::vector<cv::Point>> res;
    // IMPLEMENT YOUR CODE HERE

    // std::vector<cv::Point> contour;//临时存储单个轮廓
    // std::vector<std::vector<cv::Point>> contours;//存储所有轮廓
    // std::vector<cv::Vec4i> hierarchy;//存储轮廓层次结构

    // cv::Mat gray;
    // if (input.channels() == 3) {
    //     // 如果图像是3个通道的彩色图，转换为灰度图
    //     cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    // } else {
    //     // 如果图像已经是灰度图，直接使用
    //     gray = input;
    // }

    // //cv::GaussianBlur(gray, gray, cv::Size(5, 5), 0);

    // cv::Mat canny_output;

    // cv::Canny(gray, canny_output, 50, 150);//canny边缘检测

    // cv::findContours(canny_output, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);

    // // 分析层次结构以找到最内层轮廓
    // for (size_t i = 0; i < hierarchy.size(); i++) {
    //     // 检查是否为最内层轮廓（没有父节点且不是其他轮廓的子节点）
    //     if (hierarchy[i][3] == -1) {
    //         res.push_back(contours[i]);
    //     }
    // }

    std::vector<cv::Vec4i> hierarchy;

    cv::Mat gray1, erzhi1;
    cv::cvtColor(input, gray1, cv::COLOR_BGR2GRAY);
    cv::threshold(gray1, erzhi1, 50, 255, cv::THRESH_BINARY);

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(erzhi1, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    cv::Mat drawing = erzhi1.clone();
    cv::drawContours(drawing, contours, -1, cv::Scalar(0, 255, 0), 2);

    for(size_t i = 0; i < hierarchy.size(); i++){
        if (hierarchy[i][2] == -1){//2是内一层轮廓，3是外一层轮廓
            res.push_back(contours[i]);
        }

    }

    cv::imshow("Contours", drawing);
    cv::waitKey(0);

    return res;
}