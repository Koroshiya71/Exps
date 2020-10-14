#include<opencv2\highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
void sharpen(const cv::Mat &image, cv::Mat &result) {
	// �ж��Ƿ�Ҫ���·���ͼ�����ݡ������Ҫ���ͷ���
	result.create(image.size(), image.type());
	int nchannels = image.channels();	// ���ͨ����
	// ����������(���˵�һ�к����һ��)
	for (int j = 1; j < image.rows - 1; j++) {
		const uchar* previous = 
			image.ptr<const uchar>(j - 1);// ��һ��
		const uchar* current =
			image.ptr<const uchar>(j);	  // ��ǰ��
		const uchar* next =
			image.ptr<const uchar>(j + 1);// ��һ��
		uchar* output = result.ptr<uchar>(j);  // �����
			// ������ǰ�е�ÿ��Ԫ��(��ȥ��һ�к����һ�����ض�Ӧ��Ԫ��)
	for (int i = nchannels; i < (image.cols - 1) * nchannels; i++){
		// �񻯴���satureate_castʹ�õ��Ľ��һ����uchar		// ��Χ��
		*output++ = cv::saturate_cast<uchar>(
			5 * current[i] - current[i - nchannels] -
			current[i + nchannels] - previous[i] - next[i]
			);
		}
	}

	// ��δ�����������Ϊ0
	result.row(0).setTo(cv::Scalar(0));
	result.row(result.rows - 1).setTo(cv::Scalar(0));
	result.col(0).setTo(cv::Scalar(0));
	result.col(result.cols - 1).setTo(cv::Scalar(0));
}
void main()
{
	Mat img=imread("test.jpg");
	Mat image =img.clone();
	int64 time=getTickCount();
	sharpen(image,image);
	double deltaTime= (cv::getTickCount() -time) / cv::getTickFrequency();
	imshow("sharpen",image);
	cout<<"sharpen:"<<deltaTime<<"s"<<endl;
	Mat kernel(3, 3, CV_32F, cv::Scalar(0));
	// ���ں˸�ֵ
	kernel.at<float>(1, 1) = 5.0;
	kernel.at<float>(0, 1) = -1.0;
	kernel.at<float>(2, 1) = -1.0;
	kernel.at<float>(1, 0) = -1.0;
	kernel.at<float>(1, 2) = -1.0;
	image=img.clone();
	time=getTickCount();
	filter2D(image,image,image.depth(),kernel);
	deltaTime= (getTickCount() -time) / getTickFrequency();
	imshow("filter2D",image);
	cout<<"filter2D:"<<deltaTime<<"s"<<endl;
	waitKey();
}