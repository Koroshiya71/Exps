#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

void main()
{
	Mat img=imread("test.jpg");
	Mat rain=imread("rain.jpg");
	Mat result;
	resize(rain,rain,img.size());
	result=0.8*img+0.2*rain;
	imshow("origin",img);
	imshow("rain",rain);
	imshow("added",result);
	Mat result2;
	result2=result-Scalar(20,20,20);
	imshow("降低亮度",result2);
	Mat rain2=imread("rain.jpg",IMREAD_GRAYSCALE);
	resize(rain2,rain2,img.size());
	vector<Mat>planes;
	split(result,planes);
	planes[0]+=rain2;
	Mat result3;
	merge(planes,result3);
	imshow("蓝通道叠加效果",result3);
	waitKey();
}