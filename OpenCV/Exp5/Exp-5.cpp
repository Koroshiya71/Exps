#include<iostream>
#include<opencv2\highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace std;
using namespace cv;
void salt(cv::Mat image, int n){
    int i, j; 
    for (int k = 0; k < n; k++) {
	i = rand() % image.cols;   // 随机产生1列号
	j = rand() % image.rows;  // 随机产生1行号
	if (image.type() == CV_8UC1)  // 灰度图像(CV_8UC1=CV_8U)
		image.at<uchar>(j, i) = 255;  // 将像素值设为白色
	else if (image.type() == CV_8UC3) { // 彩色图像
		// 将像素值设为白色
		image.at<cv::Vec3b>(j, i)[0] = 255;// 蓝色通道像素值
		image.at<cv::Vec3b>(j, i)[1] = 255;// 绿色通道像素值
		image.at<cv::Vec3b>(j, i)[2] = 255;// 红色通道像素值
	}
    }
}

int main()
{
	Mat image=imread("test2.png");
	imshow("Origin",image);
	salt(image,7000);
	imshow("Salt",image);
	waitKey();
	return 0;
}