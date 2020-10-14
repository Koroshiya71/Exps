#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Point2f srcTri[3];
	Point2f dstTri[3];

	Mat rot_mat(2, 3, CV_32FC1);
	Mat warp_mat(2, 3, CV_32FC1);
	Mat srcImage, warp_dstImage,  rotate_dstImage;
	double angle = 0;
	double scale = 1;
	srcImage = imread("wolf.png");

	if (srcImage.empty())
	{
		cout << "Í¼Ïñ¼ÓÔØÊ§°Ü!" << endl;
		return -1;
	}
	cout << "Í¼Ïñ¼ÓÔØ³É¹¦!" << endl << endl;
	warp_dstImage = Mat::zeros(srcImage.rows, srcImage.cols, srcImage.type());
	srcTri[0] = Point2f(0, 0);
	srcTri[1] = Point2f(srcImage.cols - 1, 0);
	srcTri[2] = Point2f(0, srcImage.rows - 1);

	dstTri[0] = Point2f(srcImage.cols * 0.0, srcImage.rows * 0.33);
	dstTri[1] = Point2f(srcImage.cols * 0.85, srcImage.rows * 0.25);
	dstTri[2] = Point2f(srcImage.cols * 0.15, srcImage.rows * 0.7);
	warp_mat = getAffineTransform(srcTri, dstTri);
	warpAffine(srcImage, warp_dstImage, warp_mat, warp_dstImage.size());
	Point center = Point(warp_dstImage.cols / 2, warp_dstImage.rows / 2);
	while (angle <= 360)
	{
		rot_mat = getRotationMatrix2D(center, angle, scale);
		warpAffine(srcImage, rotate_dstImage, rot_mat, srcImage.size());
		imshow("rotate", rotate_dstImage);
		waitKey(1);
		angle+=2;
	}
	waitKey(0);
	return 0;
}
