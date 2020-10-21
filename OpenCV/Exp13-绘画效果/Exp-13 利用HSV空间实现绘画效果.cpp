#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

void main()
{
	Mat img = imread("test2.jpg");
	imshow("Origin", img);
	Mat result;
	cvtColor(img, result, CV_BGR2HSV);
	vector<Mat> channels;
	split(result, channels);
	imshow("H", channels[0]);
	imshow("S", channels[1]);
	imshow("V", channels[2]);
	channels[2] = 255;
	merge(channels, result);
	cvtColor(result, result, CV_HSV2BGR);
	imshow("Painting", result);
	waitKey();
}
