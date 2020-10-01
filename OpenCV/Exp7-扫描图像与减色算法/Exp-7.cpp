#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
void colorReduce(cv::Mat image, int div = 64)
{
	int nr = image.rows; // ����
	// ÿ�е�Ԫ������(ע�ⲻ����������)
	int nc = image.cols * image.channels();
	for (int j = 0; j < nr; j++) { // ����ÿһ��
		// ȡ����j�ĵ�ַ
		uchar* data = image.ptr<uchar>(j);
		// ������ǰ��ÿһ��Ԫ��
		for (int i = 0; i < nc; i++) {
			// ����ÿ��Ԫ��---------------------
			data[i] = data[i] / div * div + div / 2;
			// Ԫ�ش������---------------------
		} // һ�н���
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