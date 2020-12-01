#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;
int s = 10;
class CLaplacian
{
private:
	int aperture;

public:
	CLaplacian():aperture(3){}

	void setAperture(int a)
	{
		aperture = a;
	}

	Mat computeLaplacian(const Mat &img)
	{
		Mat laplace;
		Laplacian(img, laplace, CV_32F, aperture);
		return laplace;
	}

	Mat getLaplacianImg(const Mat &img,double scale=-1.0)
	{
		Mat laplace = computeLaplacian(img);
		if(scale<0)
		{
			double lapMin, lapMax;
			minMaxLoc(laplace, &lapMin, &lapMax);
			scale = 127 / max(-lapMin, lapMax);

		}
		Mat laplaceImg;
		laplace.convertTo(laplaceImg, CV_8U, scale, 128);
		return laplaceImg;
	}

	Mat getZeroCrossings(Mat laplace)
	{
		Mat signImg;
		threshold(laplace, signImg, 0, 255, THRESH_BINARY);

		Mat binary;
		signImg.convertTo(binary, CV_8U);

		Mat dilated;
		dilate(binary, dilated, Mat());
		return dilated - binary;
	}

	Mat getLaplacianEnhancedImg(const Mat &img,const float factor=1)
	{
		Mat fImg;
		img.convertTo(fImg,CV_32F);
		Mat laplace= computeLaplacian(img);

		Mat result = fImg - factor * laplace;
		result.convertTo(result, CV_8U);

		return result;
	}
};
static void onTrackBar(int, void*)
{
	Mat image = imread("test.jpg");
	Mat result2;
	CLaplacian laplacian;
	laplacian.setAperture(3);

	
	result2 = laplacian.getLaplacianEnhancedImg(image,(double)(s/50.0));
	imshow("增强结果", result2);
}
void main()
{
	Mat img = imread("test.jpg");
	imshow("原图", img);

	Mat result;
	CLaplacian laplacian;

	laplacian.setAperture(3);
	Mat laplaceImg = laplacian.getLaplacianEnhancedImg(img,0.2);
	imshow("增强结果",laplaceImg);
	createTrackbar("增强幅度", "增强结果", &s, 50, onTrackBar);
	waitKey();
}