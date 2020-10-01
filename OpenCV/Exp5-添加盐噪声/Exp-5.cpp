#include<iostream>
#include<opencv2\highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace std;
using namespace cv;
void salt(cv::Mat image, int n){
    int i, j; 
    for (int k = 0; k < n; k++) {
	i = rand() % image.cols;   // �������1�к�
	j = rand() % image.rows;  // �������1�к�
	if (image.type() == CV_8UC1)  // �Ҷ�ͼ��(CV_8UC1=CV_8U)
		image.at<uchar>(j, i) = 255;  // ������ֵ��Ϊ��ɫ
	else if (image.type() == CV_8UC3) { // ��ɫͼ��
		// ������ֵ��Ϊ��ɫ
		image.at<cv::Vec3b>(j, i)[0] = 255;// ��ɫͨ������ֵ
		image.at<cv::Vec3b>(j, i)[1] = 255;// ��ɫͨ������ֵ
		image.at<cv::Vec3b>(j, i)[2] = 255;// ��ɫͨ������ֵ
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