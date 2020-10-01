#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
#include<ranges>
using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("test.png");
	Mat logo = imread("logo.png");
	Mat mask(logo);
	Mat imageRoi = image(Range(image.rows - logo.rows, image.rows),
	                     Range(image.cols - logo.cols, image.cols));
	imshow("Origin", image);
	imshow("Logo", logo);
	logo.copyTo(imageRoi, mask);
	imshow("Inserted", image);
	waitKey();
}
