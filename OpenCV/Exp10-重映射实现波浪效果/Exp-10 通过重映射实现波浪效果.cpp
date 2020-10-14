#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void wave(const Mat& image, Mat& result)
{
	// 映射矩阵
	Mat srcX(image.rows, image.cols, CV_32F); // 定义x坐标的映射
	Mat srcY(image.rows, image.cols, CV_32F); // 定义y坐标的映射
	//设置映射矩阵像素值
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			//(i, j)像素的新位置
			srcX.at<float>(i, j) = j; // 保持在同一列
			// 原来在第i行的像素，现在根据一个正弦曲线移动
			srcY.at<float>(i, j) = i + 5 * sin(j / 10.0);
		}
	}
	// 应用映射矩阵
	remap(
		image, // 源图像
		result, // 结果图像
		srcX, // x坐标映射矩阵
		srcY, // y坐标映射矩阵
		INTER_LINEAR // 插值方式，线性插值
	);
}

void main()
{
	Mat image = imread("wolf.png");
	Mat result;
	wave(image, result);
	imshow("origin", image);
	imshow("Wave", result);
	waitKey();
}
