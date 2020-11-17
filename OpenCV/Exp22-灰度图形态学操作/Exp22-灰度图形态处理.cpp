#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;


void main()
{
	Mat image = imread("test.jpg");
	imshow("原图", image);
	Mat gray = imread("test.jpg", IMREAD_GRAYSCALE);
	
	imshow("原灰度图", gray);

	Mat result,result2;
	morphologyEx(gray, result, MORPH_GRADIENT,Mat());
	threshold(result, result, 40, 255, CV_THRESH_BINARY_INV);

	imshow("Beucher梯度", result);

	dilate(gray, result,Mat());
	
	result2 = result-gray;
	threshold(result2, result2, 25, 255, CV_THRESH_BINARY_INV);
	imshow("膨胀减原图", result2);

	erode(gray, result, Mat());
	result2 = gray - result;
	threshold(result2, result2, 25, 255, CV_THRESH_BINARY_INV);
	imshow("原图减腐蚀", result2);

	waitKey();

	destroyAllWindows();

	Mat text = imread("text.jpg",IMREAD_GRAYSCALE);
	imshow("文本原图", text);
	threshold(text, result, 65, 255, CV_THRESH_BINARY);
	imshow("阈值法结果", result);

	Mat element(12 ,12, CV_8U, Scalar(1));
	morphologyEx(text, result,MORPH_BLACKHAT, element);
	threshold(result, result, 25, 255, CV_THRESH_BINARY_INV);
	

	imshow("黑帽", result);

	waitKey();

}