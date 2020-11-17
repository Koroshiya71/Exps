#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

class ColorDetector
{
private:
	int maxDist; // 允许的最大颜色差距
	Vec3b target; // 目标颜色
public:
	ColorDetector() : maxDist(100), target(0, 0, 0)
	{
	}

	// 计算两个颜色之间的距离
	int getColorDistance(const Vec3b& color1,
	                     const Vec3b& color2) const
	{
		// 计算欧式距离
		return static_cast<int>(
			norm<int, 3>(Vec3i(color1[0] - color2[0],
			                   color1[1] - color2[1], color1[2] - color2[2]))
		);
	}

	// 计算与目标颜色的差距
	int getDistanceToTargetColor(const Vec3b& color) const
	{
		return getColorDistance(color, target);
	}

	Mat process(const Mat& image)
	{
		Mat result;
		// 重新分配二值结果图像
		// 与输入图像的尺寸相同，不过是单通道
		result.create(image.size(), CV_8U);
		// 遍历图像，处理每个像素
		for (int j = 0; j < image.rows; j++)
		{
			// 取得行j的首地址
			const Vec3b* input = image.ptr<Vec3b>(j);
			uchar* output = result.ptr<uchar>(j);
			// 遍历该行的每一个像素
			for (int i = 0; i < image.cols; i++)
			{
				// 比较与目标颜色的差距
				if (getDistanceToTargetColor(input[i]) <= maxDist)
					output[i] = 255;
				else
					output[i] = 0;
			}
		}
		return result;
	}

	// 设置颜色差距的阈值
	// 阈值必须是正数，否则就置为0
	void setColorDistanceThreshold(int distance)
	{
		if (distance < 0)
			distance = 0;
		maxDist = distance;
	}

	// 取得颜色差距的阈值
	int getColorDistanceThreshold() const
	{
		return maxDist;
	}

	// 设置需要检测的颜色
	void setTargetColor(uchar blue, uchar green, uchar red)
	{
		// 次序为BGR
		target = Vec3b(blue, green, red);
	}

	// 设置需要检测的颜色
	void setTargetColor(Vec3b color)
	{
		target = color;
	}

	// 获取需要检测的颜色
	Vec3b getTargetColor() const
	{
		return target;
	}
};

void main()
{
	ColorDetector cdt;
	Mat img = imread("test.jpg"), result;
	if (img.empty())
		return;
	imshow("Origin", img);
	cdt.setTargetColor(137, 108, 164);
	cdt.setColorDistanceThreshold(80);
	Mat target(200, 200,CV_8UC3, cdt.getTargetColor());
	imshow("Target Color", target);
	result = cdt.process(img);
	imshow("Result", result);
	waitKey();
}
