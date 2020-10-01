#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace std;
using namespace cv;
int main()
{
	Mat img = imread("test2.png");
	Mat blank(img.size(), img.type(), Scalar(255, 255, 255));
	Mat Roi;
	RNG rng;
	int row, col;
	int count =1500;
	while (count>0)
	{
		count--;
		row=rng.uniform(0,img.rows-100);
		col = rng.uniform(0, img.cols-100);
		Roi = img(Rect(col,row, 100, 100));
		Roi = Scalar(255, 255, 255);
		img.copyTo(blank);
		imshow("a", img);
		waitKey(1);
	}

	return 0;
}
