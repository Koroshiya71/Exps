#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;
using namespace std;

int s=50;

static void onTrackBar(int,void *)
{
	Mat img = imread("test.jpg");
	Mat result=img.clone();
	double k = getTrackbarPos("饱和度", "饱和度调节")/50.0;
	result.create(img.size(), img.type());
	for(int row=0;row<img.rows;row++)
	{
		const Vec3b* input = img.ptr<Vec3b>(row);
		Vec3b* output = result.ptr<Vec3b>(row);
		for(int col=0;col<img.cols;col++)
		{
			uchar Y = input[col][0] * 0.114 + input[col][1] * 0.587 + input[col][2] * 0.299;
			output[col] = Vec3b
			(saturate_cast<uchar>(Y + k * (input[col][0] - Y)),
				saturate_cast<uchar>(Y + k * (input[col][1] - Y)),
				saturate_cast<uchar>(Y + k * (input[col][2] - Y)));
		}
	}
	imshow("饱和度调节", result);
}


void main()
{
	Mat image = imread("test.jpg");
	imshow("饱和度调节", image);
	createTrackbar("饱和度", "饱和度调节",&s,100,onTrackBar);
	waitKey();
}
