#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void wave(const Mat& image, Mat& result)
{
	// ӳ�����
	Mat srcX(image.rows, image.cols, CV_32F); // ����x�����ӳ��
	Mat srcY(image.rows, image.cols, CV_32F); // ����y�����ӳ��
	//����ӳ���������ֵ
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			//(i, j)���ص���λ��
			srcX.at<float>(i, j) = j; // ������ͬһ��
			// ԭ���ڵ�i�е����أ����ڸ���һ�����������ƶ�
			srcY.at<float>(i, j) = i + 5 * sin(j / 10.0);
		}
	}
	// Ӧ��ӳ�����
	remap(
		image, // Դͼ��
		result, // ���ͼ��
		srcX, // x����ӳ�����
		srcY, // y����ӳ�����
		INTER_LINEAR // ��ֵ��ʽ�����Բ�ֵ
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
