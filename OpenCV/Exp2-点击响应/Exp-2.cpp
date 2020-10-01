#include<opencv2/highgui/highgui.hpp>
#include<iostream>
#include<opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

void Click(int event, int x, int y, int flags, void* param)
{
	Mat* im = reinterpret_cast<Mat*>(param);
	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
		switch (im->channels())
		{
		case 1:

			cout << "Position(" << x << "," << y << ")  Pixels value:" << static_cast<int>(im->at<uchar>(Point(x, y)))
				<< endl;
			break;
		case 3:
			cout << "Position(" << x << "," << y << ")  Pixels value:" <<
				"B" << static_cast<int>(im->at<Vec3b>(Point(x, y))[0]) <<
				"  G" << static_cast<int>(im->at<Vec3b>(Point(x, y))[1]) <<
				"  R" << static_cast<int>(im->at<Vec3b>(Point(x, y))[2]) << endl;
			break;
		}
	}
}

int main()
{
	Mat image;
	int choice;
	cout << "ÊäÈë1ÒÔ²ÊÉ«Í¼¶ÁÈ¡Í¼Æ¬£¬ÊäÈë2ÒÔ»Ò¶ÈÍ¼¶ÁÈ¡Í¼Æ¬" << endl;
	cin >> choice;
	if (choice == 1)
		image = imread("12.jpg");
	else if (choice == 2)
		image = imread("12.jpg", IMREAD_GRAYSCALE);
	if (image.empty())
	{
		cout << "Î´¶ÁÈ¡µ½Í¼Æ¬" << endl;
		return 0;
	}
	namedWindow("GrayScale");
	setMouseCallback("GrayScale", Click, reinterpret_cast<void*>(&image));
	imshow("GrayScale", image);
	circle(image, Point(90, 336), 100, 0, 3);
	putText(image, "COLA", Point(120, 336), CV_FONT_BLACK, 2.0, Scalar(0, 0, 0), 2);
	imshow("Circle", image);
	waitKey(0);
	return 0;
}
