#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

class ColorHistogram
{
private:
	int histSize[3];
	float hranges[2];
	const float* ranges[3];
	int channels[3];
public:
	ColorHistogram()
	{
		histSize[0] = histSize[1] = histSize[2] = 256;
		hranges[0] = 0.0;
		hranges[1] = 256.0;
		ranges[0] = hranges;
		ranges[1] = hranges;
		ranges[2] = hranges;
		channels[0] = 0;
		channels[1] = 1;
		channels[2] = 2;
	}

	Mat getHistogram(const Mat& image)
	{
		Mat hist(3, histSize, CV_32F);

		calcHist(&image,
		         1, channels, Mat(), hist, 3, histSize, ranges);

		return hist;
	}

	SparseMat getSparseHistogram(const Mat& image)
	{
		SparseMat hist(3, histSize, CV_32F);

		calcHist(&image,
		         1, channels, Mat(), hist, 3, histSize, ranges);

		return hist;
	}

	void setSize(int size)
	{
		histSize[0] = histSize[1] = histSize[2] = size;
	}

	Mat getHueHistogram(const Mat& image,
	                    int minSaturation = 0)
	{
		Mat hist;

		Mat hsv;
		cvtColor(image, hsv, CV_BGR2HSV);

		Mat mask;
		if (minSaturation > 0)
		{
			std::vector<Mat> v;
			split(hsv, v);

			threshold(v[1], mask, minSaturation, 255, THRESH_BINARY);
		}

		hranges[0] = 0.0;
		hranges[1] = 180.0;
		channels[0] = 0;
		calcHist(&hsv,
		         1, channels, mask, hist, 1, histSize, ranges);

		return hist;
	}
};


class ImageComparator
{
private:
	Mat refH;
	Mat inputH;
	ColorHistogram hist;
	int nBins;

public:
	ImageComparator(): nBins(8)
	{
	}

	void setNumberOfBins(int bins)
	{
		nBins = bins;
	}

	void setReferenceImage(const Mat& img)
	{
		hist.setSize(nBins);
		refH = hist.getHistogram(img);
		refH = refH / (img.rows * img.cols);
		normalize(refH, refH, 1.0, 0.0, cv::NORM_L1);
	}

	double compare(const Mat img)
	{
		inputH = hist.getHistogram(img);
		inputH = inputH / (img.rows * img.cols);
		normalize(inputH, inputH, 1.0, 0.0, cv::NORM_L1);
		return compareHist(refH, inputH, CV_COMP_INTERSECT);
		
	}
};

void main()
{
	Mat img = imread("base.jpg");
	imshow("基准", img);
	ImageComparator IC;
	IC.setReferenceImage(img);

	double sim;
	Mat imgC[6];
	imgC[0] = imread("1.jpg");
	imgC[1] = imread("2.jpg");
	imgC[2] = imread("3.jpg");
	imgC[3] = imread("4.jpg");
	imgC[4] = imread("5.jpg");
	imgC[5] = imread("6.jpg");
	imshow("图像1", imgC[0]);
	imshow("图像2", imgC[1]);
	imshow("图像3", imgC[2]);
	imshow("图像4", imgC[3]);
	imshow("图像5", imgC[4]);
	imshow("图像6", imgC[5]);
	for (int i = 0; i < 6; i++)
	{
		sim = IC.compare(imgC[i]);
		cout << "与图像" << i + 1 << "相似度：" << sim << endl;
	}

	waitKey();
}
