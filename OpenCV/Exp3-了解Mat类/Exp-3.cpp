#include<iostream>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
using namespace cv;

Mat function()
{
 Mat ima(500,500,CV_8U,50);
 return ima;
}

int main()
{
 Mat image1(240,320,CV_8U,100);//1
 imshow("Image",image1);
 waitKey();

 image1.create(200,200,CV_8U);//2
 image1=200;

 imshow("Image",image1);
 waitKey();

 //Mat image2(240,320,CV_8UC3,Scalar(0,0,255));

 Mat image2(Size(320,240),CV_8UC3);//3
 image2=Scalar(0,0,255);

 imshow("Image",image2);
 waitKey();

 Mat image3=imread("12.jpg");//4
 Mat image4(image3);
 image1=image3;

 image3.copyTo(image2);//5
 Mat image5=image3.clone();//6

 flip(image3,image3,1);//?

 imshow("Image 3",image3);
 imshow("Image 1",image1);
 imshow("Image 2",image2);
 imshow("Image 4",image4);
 imshow("Image 5",image5);
 waitKey();

 Mat gray = function();//7

 imshow("Image",gray);
 waitKey();

 image1=imread("12.jpg",IMREAD_GRAYSCALE);//8
 image1.convertTo(image2,CV_32F,1/255.0,0.0);//9

 imshow("Image",image2);
 waitKey();

 return 0;
}