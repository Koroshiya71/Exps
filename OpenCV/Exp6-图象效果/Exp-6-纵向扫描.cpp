#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

void main()
{
	Mat img1 = imread("test2.png");
	Mat white(img1.size(), img1.type(), Scalar(255, 255, 255));
	Mat buffer = white.clone();
	Mat Roi, Boi;
	RNG rng;
	int ccol, crow, ncol = 0, nrow = 0;

	ccol = rng.uniform(0, img1.cols - white.cols);
	crow = rng.uniform(0, img1.rows - white.rows);
	Roi = img1(Rect(ccol, crow, white.cols, white.rows));
	Roi.copyTo(buffer);
	Boi = Roi.clone();
	while (nrow != buffer.rows)
	{
		Mat mask(white);
		nrow = buffer.rows - white.rows;

		Mat imgRoi(buffer(Rect(ncol, nrow, white.cols, white.rows)));
		white.copyTo(imgRoi, mask);
		buffer.copyTo(Roi);
		white.rows--;
		
		Boi.copyTo(buffer);
		imshow("×ÝÏòÉ¨Ãè", img1);
		waitKey(2);
	}

}