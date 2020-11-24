#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;

void main()
{
	Mat img = imread("test.jpg"),result,result2;
	imshow("原图", img);
	blur(img, result, Size(3, 3));
	imshow("平滑3x3", result);
	blur(img, result, Size(5, 5));
	imshow("平滑5x5", result);

	GaussianBlur(img, result, Size(5, 5), 0);
	imshow("高斯σ0", result);

	GaussianBlur(img, result, Size(5, 5), 5);
	imshow("高斯σ5", result);

	GaussianBlur(img, result, Size(5, 5), 10);
	imshow("高斯σ10", result);

	waitKey();
	destroyAllWindows();
	
	Mat img4k = imread("4k.jpg");
	imshow("4K原图", img4k);
	resize(img4k, result, Size(img4k.cols/8,img4k.rows/8));
	imshow("resize1/8", result);
	
	resize(result, result2, Size(result.cols * 2, result.rows * 2), INTER_NEAREST);//最近邻插值
	imshow("最近邻差值", result2);
	resize(result, result2, Size(result.cols * 2, result.rows * 2), INTER_LINEAR);//双线性插值
	imshow("双线性插值", result2);

	

	pyrDown(img4k, result);
	pyrDown(result, result);
	pyrDown(result, result);
	imshow("pyrDown1/8", result);
	
	waitKey();

	destroyAllWindows();

	Mat salt = imread("salt.png");
	imshow("盐噪声原图", salt);
	medianBlur(salt, result,3);
	imshow("中值滤波", result);

	blur(salt, result, Size(7, 7));
	imshow("均值滤波", result);

	GaussianBlur(salt, result, Size(7, 7), 0);
	imshow("高斯滤波", result);

	waitKey();
}