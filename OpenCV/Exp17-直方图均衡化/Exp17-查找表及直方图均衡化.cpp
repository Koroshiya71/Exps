#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;

Mat applyLookUp(const Mat &image,const Mat &lookup)
{
	Mat result;

	LUT(image,lookup,result);

	return result;
}

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
		histSize[0]=256;
		hranges[0]=0.0;
		hranges[1]=256.0;
		ranges[0]=hranges;
		channels[0]=0;
	}

	Mat getHistogramImage(const cv::Mat &image,
		int zoom = 1) {
		cv::Mat hist = getHistogram(image);
		return getImageOfHistogram(hist, zoom);
	}
	Mat getHistogram(const Mat &image)
	{
		Mat hist;
		calcHist(&image,1,channels,Mat(),hist,1,histSize,ranges);
		return hist;
	}

	static Mat getImageOfHistogram(const Mat &hist,int zoom)
	{	
											// 取得条目值的最大值和最小值
		double maxVal = 0;
		double minVal = 0;
		cv::minMaxLoc(hist,
			&minVal,	// 存最小值的指针
			&maxVal,	// 存最大值的指针
			NULL,		// 最小值位置指针	
			NULL		// 最大值位置指针
		);

		// 取得直方图的大小
		int histSize = hist.rows; // 直方图是n行1列的图像
								  //cout << hist.rows << "X" << hist.cols;

								  // 用于显示直方图的方形图像
		cv::Mat histImg(histSize * zoom, histSize * zoom,
			CV_8U, cv::Scalar(255));

		// 设置最高点为90%(即图像高度)的条目个数
		int hpt = static_cast<int>(0.9 * histSize);

		// 为每个条目画垂直线
		for (int h = 0; h < histSize; h++) {
			float binVal = hist.at<float>(h);
			if (binVal > 0) { // 大于0才需要画
				int intensity = static_cast<int>(binVal * hpt / maxVal);
				cv::line(histImg, cv::Point(h * zoom, histSize * zoom),
					cv::Point(h * zoom, (histSize - intensity) * zoom),
					cv::Scalar(0), zoom);
			}
		}

		return histImg;
	}

	Mat stretch(const Mat &image, float minPercent=0)
	{
		float minValue=minPercent*image.rows*image.cols;

		Mat hist =getHistogram(image);

		int imin=0;
		float sum=0;
		for(;imin<histSize[0];imin++)
		{
			sum+=hist.at<float>(imin);
			if(sum>minValue)
				break;
		}

		int imax=histSize[0]-1;
		sum=0;
		for(;imax>=0;imax--)
		{
			sum+=hist.at<float>(imax);
			if(sum>minValue)
				break;
		}

		int dim(256);
		Mat lookup(1,&dim,CV_8U);

		for(int i=0;i<256;i++)
		{
			if(i<imin)
				lookup.at<uchar>(i)=0;
			else if(i>imax)lookup.at<uchar>(i)=255;
			else lookup.at<uchar>(i)=
				cvRound(255.0*(i-imin)/(imax-imin));

		}
		Mat result;
		result=applyLookUp(image,lookup);
		return result;
	}

};

void main()
{
	Mat image=imread("test.jpg");
	imshow("原图",image);
	int dim(256);
	Mat lut(1,&dim,CV_8U);

	uchar *data=lut.ptr<uchar>(0);
	for(int i=0;i<256;i++)
		data[i]=255-i;
	Mat result=applyLookUp(image,lut);
	imshow("颜色反转",result);


	cvtColor(image,result,CV_BGR2HSV);
	Mat channels[3];
	split(result,channels);
	Histogram1D h;
	Mat temp=channels[2].clone();
	imshow("原始亮度直方图",h.getHistogramImage(channels[2]));
	channels[2]=h.stretch(channels[2],0.01f);
	imshow("拉伸后亮度直方图",h.getHistogramImage(channels[2]));

	merge(channels,3,result);
	cvtColor(result,result,CV_HSV2BGR);
	imshow("拉伸最终结果",result);

	channels[2]=temp;
	equalizeHist(channels[2],channels[2]);
	imshow("均衡化后亮度直方图",h.getHistogramImage(channels[2]));
	merge(channels,3,result);
	cvtColor(result,result,CV_HSV2BGR);
	imshow("均衡化最终结果",result);
	waitKey(0);
}