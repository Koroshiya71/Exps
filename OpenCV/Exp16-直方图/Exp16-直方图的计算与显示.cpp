#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

class Histogram1D
{
private:
	int histSize[1];
	float hranges[2];
	const float* ranges[1];
	int channels[1];

public:
	Histogram1D()
	{
		histSize[0] = 256;
		hranges[0] = 0.0;
		hranges[1] = 256.0;
		ranges[0] = hranges;
		channels[0] = 0;
	}

	Mat getHistogram(const Mat& image)
	{
		Mat hist;

		calcHist(&image, 1, channels, Mat(), hist, 1, histSize, ranges);

		return hist;
	}

	Mat getHistogramImage(const Mat& image, int zoom = 1)
	{
		Mat hist = getHistogram(image);

		return getImageOfHistogram(hist, zoom);
	}

	static Mat getImageOfHistogram(const Mat& hist, int zoom)
	{
		double maxVal = 0;
		double minVal = 0;
		minMaxLoc(hist, &minVal, &maxVal, nullptr, nullptr);

		int histSize = hist.rows;

		Mat histImg(histSize * zoom, histSize * zoom, CV_8UC3, Scalar(255,255,255));
		int hpt = static_cast<int>(0.9 * histSize);

		for (int h = 0; h < histSize; h++)
		{
			float binVal = hist.at<float>(h);
			
			if (binVal > 0)
			{
				int intensity = static_cast<int>(binVal * hpt / maxVal);
				line(histImg, Point(h * zoom, histSize * zoom),
				     Point(h * zoom, (histSize - intensity * zoom)),
				     Scalar(0), zoom);
				if (h == 30)
					line(histImg, Point(h * zoom, histSize * zoom),
						Point(h * zoom, (histSize - intensity * zoom)),
						Scalar(0, 0, 255), zoom);
			}
			
		}
		return histImg;
	}
};

void main()
{
	Mat img = imread("test.jpg", IMREAD_GRAYSCALE);
	imshow("原图", img);
	Histogram1D h;
	Mat histo = h.getHistogram(img);
	for (int i = 0; i < 256; i++)
		cout << "Value" << i << "=" << histo.at<float>(i) << endl;
	
	imshow("Histogram", h.getHistogramImage(img));

	Mat thresholded;
	threshold(img, thresholded, 30, 255, THRESH_BINARY);
	imshow("分割结果", thresholded);
	waitKey();
}
