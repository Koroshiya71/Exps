#include<opencv2\highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
void sharpen(const cv::Mat &image, cv::Mat &result) {
	// 判断是否要重新分配图像数据。如果需要，就分配
	result.create(image.size(), image.type());
	int nchannels = image.channels();	// 获得通道数
	// 处理所有行(除了第一行和最后一行)
	for (int j = 1; j < image.rows - 1; j++) {
		const uchar* previous = 
			image.ptr<const uchar>(j - 1);// 上一行
		const uchar* current =
			image.ptr<const uchar>(j);	  // 当前行
		const uchar* next =
			image.ptr<const uchar>(j + 1);// 下一行
		uchar* output = result.ptr<uchar>(j);  // 输出行
			// 遍历当前行的每个元素(除去第一列和最后一列像素对应的元素)
	for (int i = nchannels; i < (image.cols - 1) * nchannels; i++){
		// 锐化处理，satureate_cast使得到的结果一定在uchar		// 范围内
		*output++ = cv::saturate_cast<uchar>(
			5 * current[i] - current[i - nchannels] -
			current[i + nchannels] - previous[i] - next[i]
			);
		}
	}

	// 把未处理的像素设为0
	result.row(0).setTo(cv::Scalar(0));
	result.row(result.rows - 1).setTo(cv::Scalar(0));
	result.col(0).setTo(cv::Scalar(0));
	result.col(result.cols - 1).setTo(cv::Scalar(0));
}
void main()
{
	Mat img=imread("test.jpg");
	Mat image =img.clone();
	int64 time=getTickCount();
	sharpen(image,image);
	double deltaTime= (cv::getTickCount() -time) / cv::getTickFrequency();
	imshow("sharpen",image);
	cout<<"sharpen:"<<deltaTime<<"s"<<endl;
	Mat kernel(3, 3, CV_32F, cv::Scalar(0));
	// 对内核赋值
	kernel.at<float>(1, 1) = 5.0;
	kernel.at<float>(0, 1) = -1.0;
	kernel.at<float>(2, 1) = -1.0;
	kernel.at<float>(1, 0) = -1.0;
	kernel.at<float>(1, 2) = -1.0;
	image=img.clone();
	time=getTickCount();
	filter2D(image,image,image.depth(),kernel);
	deltaTime= (getTickCount() -time) / getTickFrequency();
	imshow("filter2D",image);
	cout<<"filter2D:"<<deltaTime<<"s"<<endl;
	waitKey();
}