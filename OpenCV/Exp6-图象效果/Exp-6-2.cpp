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
		ccol = rng.uniform(0, img1.cols - 100);//左上角x随机坐标
		crow = rng.uniform(0, img1.rows - 100);//左上角y随机坐标
		Roi = img2(Rect(ccol, crow, 100, 100));//选择原图的(x,y)位置
		Boi = img1(Rect(ccol, crow, 100, 100));//选择白板的(x,y)位置
		Roi.copyTo(Boi);//原图 拷贝至 白板 所设定的区域
		//imshow("test 1", img2);
		imshow("test 3", img1);
		waitKey(1);
	}
	waitKey();
}