class ColorHistogram {
private:
	int histSize[3];		// 每个维度的大小
	float hranges[2];		// 值的范围
	const float* ranges[3];	// 每个维度的范围
	int channels[3];		// 需要处理的通道

public:
	ColorHistogram() {
		// 准备用于彩色图像的默认参数
		// 每个维度的大小和范围是相等的
		histSize[0] = histSize[1] = histSize[2] = 256;
		hranges[0] = 0.0;	// BGR范围为0~256
		hranges[1] = 256.0;	
		// 这个类中，所有通道的范围都相等
		ranges[0] = hranges;
		ranges[1] = hranges;
		ranges[2] = hranges;
		// 三个通道
		channels[0] = 0;
		channels[1] = 1;
		channels[2] = 2;
	}

	//计算直方图
	cv::SparseMat getHistogram(const cv::Mat &image) {
		cv::SparseMat hist(3,	// 维数
			histSize,			// 每个维度的大小
			CV_32F);

		// 计算直方图
		cv::calcHist(&image,
			1,			// 仅为一个图像的直方图
			channels,	// 使用的通道
			cv::Mat(),	// 不使用掩码
			hist,		// 得到的直方图
			3,			// 这是一个三维的直方图
			histSize,	// 条目数量
			ranges		// 像素值的范围
		);

		return hist;
	}
};