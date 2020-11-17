#include <opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;


void main()
{
	Mat img = imread("test.bmp");

	imshow("原图", img);

	waitKey();

	Mat eroded;
	erode(img, eroded, Mat());
	imshow("3x3腐蚀", eroded);

	Mat dilated;

	dilate(img, dilated, Mat());
	imshow("3x3膨胀", dilated);
	waitKey();

	Mat element7x7(7, 7, CV_8U, Scalar(1));
	erode(img, eroded, element7x7);
	imshow("7x7腐蚀",eroded);

	dilate(img, dilated, element7x7);
	imshow("7x7膨胀",dilated);
	waitKey();


	erode(img, eroded, Mat(), Point(-1, -1), 3);
	imshow("3x3腐蚀三次", eroded);
	dilate(img, eroded, Mat(), Point(-1, -1), 3);
	imshow("3x3膨胀三次", dilated);
	waitKey();


	Mat element5x5(5, 5, CV_8U, Scalar(1));
	Mat closed, opened;

	morphologyEx(img, opened, MORPH_OPEN, element5x5);
	morphologyEx(img, closed, MORPH_CLOSE, element5x5);

	imshow("开运算结果", opened);
	imshow("闭运算结果", closed);
	waitKey();

	Mat result;

	morphologyEx(opened, result, MORPH_CLOSE, element5x5);
	imshow("先开后闭", result);
	morphologyEx(closed, result, MORPH_OPEN, element5x5);
	imshow("先闭后开", result);

	waitKey();

	morphologyEx(img, opened, MORPH_OPEN, element5x5);
	morphologyEx(opened, result, MORPH_OPEN, element5x5);

	imshow("连续两次开运算", result);
	morphologyEx(img, closed, MORPH_CLOSE, element5x5);
	morphologyEx(closed, result, MORPH_CLOSE, element5x5);
	imshow("连续两次闭运算", result);

	waitKey();

}