#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
using namespace cv;
void detectHScolor(const cv::Mat &image,	// 输入图像
	double minHue, double maxHue,			// 色调区间
	double minSat, double maxSat,			// 饱和度区间
	cv::Mat &mask) {						// 输出掩码
	// 转换到HSV空间
	cv::Mat hsv;
	cv::cvtColor(image, hsv, CV_BGR2HSV);

	// 分割3个通道，并存进3幅图像
	std::vector<cv::Mat> channels;
	cv::split(hsv, channels);

	// 色调掩码
	cv::Mat mask1;	// 小于maxHue
	// channels[0]中像素值小于maxHue则将mask1中对应像素值置255
	cv::threshold(channels[0], mask1, maxHue, 255, 
		cv::THRESH_BINARY_INV);
	cv::Mat mask2;	// 大于minHue
	// channels[0]中像素值小于minHue则将mask2中对应像素值置255
	cv::threshold(channels[0], mask2, minHue, 255,
		cv::THRESH_BINARY);

	cv::Mat hueMask;	// 色调掩码
	if (minHue < maxHue)
		hueMask = mask1 & mask2; // 按位与
	else // 如果区间穿越0度中轴线
		hueMask = mask1 | mask2; // 按位或

	// 饱和度掩码
	// channels[1]中像素值小于maxSat则将mask1中对应像素值置255
	cv::threshold(channels[1], mask1, maxSat, 255,
		cv::THRESH_BINARY_INV);
	// channels[1]中像素值大于minSat则将mask2中对应像素值置255
	cv::threshold(channels[1], mask2, minSat, 255,
		cv::THRESH_BINARY);

	cv::Mat satMask;	// 饱和度掩码
	satMask = mask1 & mask2;

	// 组合掩码
	mask = hueMask & satMask;
}


// 在YCrCb空间用椭圆皮肤模型进行肤色检测
void detectSkinColor(const cv::Mat &image,	// 输入图像
	cv::Mat &mask) {						// 输出掩码
	
	/*初始化椭圆皮肤模型*/
	// 用于肤色检测的掩码图像，256×256大小，初始为全0
	cv::Mat skinCrCb(cv::Size(256, 256), CV_8UC1, cv::Scalar(0));
	// 在掩码图像中绘制一白色椭圆
	cv::ellipse(skinCrCb, // 目标图像
		cv::Point(113, 155.6), // 椭圆中心坐标
		cv::Size(23.4, 15.2),  // 椭圆长短轴的长度
		43.0,				   // 椭圆长轴与水平方向夹角
		0.0,				   // 起始角度
		360.0,                 // 终止角度
		cv::Scalar(255),	   // 椭圆为白色
		-1					   // 线框宽度，为负数表示绘制填充椭圆
	);
	
	// 转换到YCrCb空间
	cv::Mat matYCrCb;
	cv::cvtColor(image, matYCrCb, CV_BGR2YCrCb);

	// 有必要的话重新分配mask的数据空间
	mask.create(image.size(), CV_8UC1);

	// 遍历图像，检测每个像素颜色是否位于椭圆内部
	for (int j = 0; j < matYCrCb.rows; j++) {
		cv::Vec3b *input = matYCrCb.ptr<cv::Vec3b>(j);
		uchar *output = mask.ptr<uchar>(j);
		for (int i = 0; i < matYCrCb.cols; i++) {
			// 将像素的CrCb值作为坐标访问skinCrCb图像，在椭圆内部则表面是肤色
			if (skinCrCb.at<uchar>(input[i][1], input[i][2]) > 0)
				output[i] = 255;
			else
				output[i] = 0;
		}
	}
}

void main()
{
	Mat img=imread("test.jpg");
	Mat mask;
	detectHScolor(img,160,10,25,166,mask);
	Mat detected(img.size(), CV_8UC3,Scalar(0,0,0)) ;
	img.copyTo(detected,mask);
	imshow("原图",img);
	imshow("HSV空间肤色检测",detected);

	detected=Scalar(0,0,0);
	detectSkinColor(img,mask);
	img.copyTo(detected,mask);
	imshow("椭圆皮肤模型肤色检测",detected);
	waitKey(); 
}