#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

class ColorDetector
{
private:
	int maxDist; // ����������ɫ���
	Vec3b target; // Ŀ����ɫ
public:
	ColorDetector() : maxDist(100), target(0, 0, 0)
	{
	}

	// ����������ɫ֮��ľ���
	int getColorDistance(const Vec3b& color1,
	                     const Vec3b& color2) const
	{
		// ����ŷʽ����
		return static_cast<int>(
			norm<int, 3>(Vec3i(color1[0] - color2[0],
			                   color1[1] - color2[1], color1[2] - color2[2]))
		);
	}

	// ������Ŀ����ɫ�Ĳ��
	int getDistanceToTargetColor(const Vec3b& color) const
	{
		return getColorDistance(color, target);
	}

	Mat process(const Mat& image)
	{
		Mat result;
		// ���·����ֵ���ͼ��
		// ������ͼ��ĳߴ���ͬ�������ǵ�ͨ��
		result.create(image.size(), CV_8U);
		// ����ͼ�񣬴���ÿ������
		for (int j = 0; j < image.rows; j++)
		{
			// ȡ����j���׵�ַ
			const Vec3b* input = image.ptr<Vec3b>(j);
			uchar* output = result.ptr<uchar>(j);
			// �������е�ÿһ������
			for (int i = 0; i < image.cols; i++)
			{
				// �Ƚ���Ŀ����ɫ�Ĳ��
				if (getDistanceToTargetColor(input[i]) <= maxDist)
					output[i] = 255;
				else
					output[i] = 0;
			}
		}
		return result;
	}

	// ������ɫ������ֵ
	// ��ֵ�������������������Ϊ0
	void setColorDistanceThreshold(int distance)
	{
		if (distance < 0)
			distance = 0;
		maxDist = distance;
	}

	// ȡ����ɫ������ֵ
	int getColorDistanceThreshold() const
	{
		return maxDist;
	}

	// ������Ҫ������ɫ
	void setTargetColor(uchar blue, uchar green, uchar red)
	{
		// ����ΪBGR
		target = Vec3b(blue, green, red);
	}

	// ������Ҫ������ɫ
	void setTargetColor(Vec3b color)
	{
		target = color;
	}

	// ��ȡ��Ҫ������ɫ
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
