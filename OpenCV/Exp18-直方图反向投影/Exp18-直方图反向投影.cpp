#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
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

		calcHist(&image,
		         1, channels, Mat(), hist, 1, histSize, ranges);

		return hist;
	}

	Mat getHistogramImage(const Mat& image,
	                      int zoom = 1)
	{
		Mat hist = getHistogram(image);

		return getImageOfHistogram(hist, zoom);
	}

	static Mat getImageOfHistogram(
		const Mat& hist, int zoom)
	{
		double maxVal = 0;
		double minVal = 0;
		minMaxLoc(hist,
		          &minVal, &maxVal, nullptr, nullptr);

		int histSize = hist.rows;
		Mat histImg(histSize * zoom, histSize * zoom,
		            CV_8U, Scalar(255));

		int hpt = static_cast<int>(0.9 * histSize);

		for (int h = 0; h < histSize; h++)
		{
			float binVal = hist.at<float>(h);
			if (binVal > 0)
			{
				int intensity = static_cast<int>(binVal * hpt / maxVal);
				line(histImg, Point(h * zoom, histSize * zoom),
				     Point(h * zoom, (histSize - intensity) * zoom),
				     Scalar(0), zoom);
			}
		}

		return histImg;
	}

	void backProject(const Mat& image, const Mat& hist, Mat& result)
	{
		calcBackProject(&image,
		                1, channels, hist, result, ranges, 255.0);
	}
};

class ContentFinder
{
private:
	float hranges[2];
	const float* ranges[3];
	int channels[3];

	float threshold;
	SparseMat histogram;
public:
	ContentFinder() : threshold(0.1f)
	{
		ranges[0] = hranges;
		ranges[1] = hranges;
		ranges[2] = hranges;
	}

	void setThreshold(float t)
	{
		threshold = t;
	}

	float getThreshold()
	{
		return threshold;
	}

	void setHistogram(const SparseMat& h)
	{
		histogram = h;
		normalize(histogram, histogram, 1.0, NORM_L1);
	}

	Mat find(const Mat& image)
	{
		Mat result;

		hranges[0] = 0.0;
		hranges[1] = 256.0;
		channels[0] = 0;
		channels[1] = 1;
		channels[2] = 2;

		return find(image, hranges[0], hranges[1], channels);
	}

	Mat find(const Mat& image,
	         float minValue, float maxValue,
	         int* channels)
	{
		Mat result;

		hranges[0] = minValue;
		hranges[1] = maxValue;

		for (int i = 0; i < histogram.dims(); i++)
			this->channels[i] = channels[i];

		calcBackProject(&image,
		                1, channels, histogram, result, ranges, 255.0);

		if (threshold > 0.0)
			cv::threshold(result, result,
			              255.0 * threshold, 255.0, THRESH_BINARY);

		return result;
	}
};

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

	SparseMat getHistogram(const Mat& image)
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
};

void main()
{
	ColorHistogram hc;
	//Mat color = imread("cloud.jpg");
	Mat color = imread("cloud2.jpg");
	//Rect rect(245, 60, 50, 50);
	Rect rect(150, 60, 42, 25);
	Mat imgROI = color(rect);

	Mat imgShown = color.clone();
	rectangle(imgShown, rect, Scalar(0, 0, 255));
	imshow("Ô­Í¼", imgShown);

	hc.setSize(8);
	SparseMat shist = hc.getHistogram(imgROI);

	ContentFinder finder;

	finder.setHistogram(shist);
	finder.setThreshold(0.05f);

	Mat result = finder.find(color);
	imshow("¼ì²â½á¹û", result);
	waitKey();
}
