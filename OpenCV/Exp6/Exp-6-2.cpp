#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

void main()
{
	Mat img1 = imread("test2.png");
	Mat img2 = img1.clone();
	Mat white(img1.size(), img1.type(), Scalar(255, 255, 255));
	Mat mask(white);
	Mat imageROI(img1, Rect(0, 0, white.cols, white.rows));
	Mat Roi,Boi;
	RNG rng;
	int ccol, crow;
	int count=1000;
	white.copyTo(img1, mask);
	//imshow("test", img1);
	while (count >0)
	{
		count--;
		ccol = rng.uniform(0, img1.cols - 100);//���Ͻ�x�������
		crow = rng.uniform(0, img1.rows - 100);//���Ͻ�y�������
		Roi = img2(Rect(ccol, crow, 100, 100));//ѡ��ԭͼ��(x,y)λ��
		Boi = img1(Rect(ccol, crow, 100, 100));//ѡ��װ��(x,y)λ��
		Roi.copyTo(Boi);//ԭͼ ������ �װ� ���趨������
		//imshow("test 1", img2);
		imshow("test 3", img1);
		waitKey(1);
	}
	waitKey();
}