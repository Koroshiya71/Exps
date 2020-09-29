#include<opencv2\highgui\highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
	cv::Mat image1,image2,image3;
	image3=imread("test.jpg",IMREAD_GRAYSCALE);
	image1=imread("test.jpg",IMREAD_COLOR);
	flip(image1,image2,1);
	cout<<"图片的大小为:"<<image1.cols<<"x"<<image1.rows<<endl;
	imshow("orgin",image1);
	imshow("flipped",image2);
	imshow("grayscale",image3);
	imwrite("output_flip.jpg",image2);
	imwrite("output_grayscale.jpg",image3);
	waitKey();
}
