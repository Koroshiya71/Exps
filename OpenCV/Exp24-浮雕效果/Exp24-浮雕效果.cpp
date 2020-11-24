#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;

void main()
{
	Mat img = imread("test.jpg");
	imshow("原图", img);

	Mat gray = imread("test.jpg", IMREAD_GRAYSCALE);

	Mat sobelX;
	Sobel(gray, sobelX, CV_8U, 1, 0, 7, 0.005, 128);
	imshow("水平", sobelX);

	Mat sobelY;
	Sobel(gray, sobelY, CV_8U, 0, 1, 7, 0.005, 128);
	imshow("垂直", sobelY);
	waitKey();


	Mat kernel(3, 3, CV_32F, Scalar(0));
	kernel.at<float>(0, 0) = 0.0;
	kernel.at<float>(0, 1) = 1.0;
	kernel.at<float>(0, 2) = 2.0;
	kernel.at<float>(1, 0) = -1.0;
	kernel.at<float>(1, 1) = 0.0;
	kernel.at<float>(1, 2) = 1.0;
	kernel.at<float>(2, 0) = -2.0;
	kernel.at<float>(2, 1) = -1.0;
	kernel.at<float>(2, 2) = 0.0;

	Mat result;
	filter2D(gray, result, CV_16S, kernel);
	result.convertTo(result, CV_8U, 0.4, 128);
	imshow("45度", result);
	waitKey();

}
