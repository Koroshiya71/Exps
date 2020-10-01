#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
void colorReduce(cv::Mat image, int div = 64)
{
	int nr = image.rows; // 行数
	// 每行的元素数量(注意不是像素数量)
	int nc = image.cols * image.channels();
	for (int j = 0; j < nr; j++) { // 遍历每一行
		// 取得行j的地址
		uchar* data = image.ptr<uchar>(j);
		// 遍历当前行每一个元素
		for (int i = 0; i < nc; i++) {
			// 处理每个元素---------------------
			data[i] = data[i] / div * div + div / 2;
			// 元素处理结束---------------------
		} // 一行结束
	}
}
int main()
{
	Mat image = imread("photo.jpg");
	imshow("Origin", image);
	colorReduce(image);
	imshow("Reduced", image);
	waitKey();
	return 0;
}