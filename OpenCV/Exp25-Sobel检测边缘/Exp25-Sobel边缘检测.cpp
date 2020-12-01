#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;

void main()
{
	Mat img = imread("test.jpg");
	imshow("原图", img);

	Mat gray = imread("test.jpg", IMREAD_GRAYSCALE);

	Mat sobelH, sobelV;

	Sobel(gray, sobelH, CV_16S, 1, 0);
	Sobel(gray, sobelV, CV_16S, 0, 1);

	Mat sobel;
	sobel = abs(sobelH) + abs(sobelV);

	double sobMin, sobMax;
	minMaxLoc(sobel, &sobMin, &sobMax);

	Mat sobelL1;

	sobel.convertTo(sobelL1, CV_8U, -255. / sobMax, 255);
	imshow("L1模", sobelL1);

	Mat result;

	threshold(sobelL1, result, 200, 255, THRESH_BINARY);
	imshow("L1阈值化结果", result);


	Sobel(gray, sobelH, CV_32F, 1, 0);
	Sobel(gray, sobelV, CV_32F, 0, 1);
	Mat sobelL2, norm, dir;
	cartToPolar(sobelH, sobelV, norm, dir);
	minMaxLoc(norm, &sobMin, &sobMax);
	norm.convertTo(sobelL2, CV_8U, -255. / sobMax, 255);

	imshow("L2模", sobelL2);
	threshold(sobelL2, result, 200, 255, THRESH_BINARY);
	imshow("L2阈值化结果", result);
	waitKey();
}
