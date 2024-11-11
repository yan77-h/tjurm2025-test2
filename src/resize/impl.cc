#include "impls.h"


cv::Mat my_resize(const cv::Mat& input, float scale) {
    /**
     * 要求：
     *      实现resize算法，只能使用基础的语法，比如说for循环，Mat的基本操作。不能
     * 用cv::resize。resize算法的内容自行查找学习，不是很难。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件：
     * 运行测试点，你的结果跟答案长的差不多就行。
     */
    int new_rows = static_cast<int>(input.rows * scale);
    int new_cols = static_cast<int>(input.cols * scale);
    // IMPLEMENT YOUR CODE HERE
    cv::Mat output(new_rows,new_cols,input.type());//放置缩放后的图像

    for (int i = 0;i < new_rows;i++){
        for(int j = 0;j < new_cols;j++){
            float y = i/scale;
            float x = j/scale;

            int x_nearest = static_cast<int>(x);//找到最接近的像素
            int y_nearest = static_cast<int>(y);

            output.at<cv::Vec3b>(i,j) = input.at<cv::Vec3b>(y_nearest,x_nearest);
        }
    }


    //return cv::Mat::zeros(new_rows, new_cols, input.type());
    return output;
}