#include "impls.h"


float compute_area_ratio(const std::vector<cv::Point>& contour) {
    /**

     * 要求：
     *      计算输入的轮廓的面积与它的最小外接矩形面积的比例。自行查找
     * 获得轮廓面积的函数。这个量可以用来判断一个轮廓到底有多靠近一个矩形。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件:
     * 运行测试点，通过即可。
     */

     double contour_area = cv::contourArea(contour);//轮廓的面积

     cv::RotatedRect bounding_rect = cv::minAreaRect(contour);//最小外接矩形.boundingRect是水平矩形,minArea可以倾斜

     double rect_area = bounding_rect.size.width * bounding_rect.size.height;//外接矩形面积

     double area_ratio = static_cast<float>(contour_area) / rect_area;

    return area_ratio;
}