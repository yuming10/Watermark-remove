#include "opencv2/opencv.hpp"
#include "iostream"
#include "WatermarkRemove.h"

using namespace cv;
using namespace std;

void WatermarkRemove::Auto(string filename, double thresh_num) {
	Mat src = imread(filename, 1);
	if (!src.data) {
		cout << "There is no picture!";
	}
	int src_height = src.cols, src_width = src.rows;
	int r_max = 0, g_max = 0, b_max = 0;
	int r, g, b;
	int pixel_max;
	for (int i = 0; i <= src_width - 1; i++) {
		for (int j = 0; j <= src_height - 1; j++) {

			b = src.at<Vec3b>(i, j)[0];
			g = src.at<Vec3b>(i, j)[1];
			r = src.at<Vec3b>(i, j)[2];
			if (r > r_max)
				r_max = r;
			else
				r_max = r_max;
			if (g > g_max)
				g_max = g;
			else
				g_max = g_max;
			if (b > b_max)
				b_max = b;
			else
				b_max = b_max;
		}
	}
	if (b_max >= r_max && b_max >= g_max)
		pixel_max = b_max;
	else if (r_max >= b_max && r_max >= g_max)
		pixel_max = r_max;
	else if (g_max >= b_max && g_max >= r_max)
		pixel_max = g_max;

	int thresh = (int)(pixel_max * thresh_num);

	Mat gray;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	/*imshow("original", gray);
	waitKey(0);*/

	Mat dst;
	threshold(gray, dst, thresh, 255, THRESH_BINARY);
	
	/*namedWindow("original", WINDOW_NORMAL);
	imshow("original", dst);
	waitKey(0);*/
	imwrite("C:\\Users\\chenym-c\\Desktop\\Removed.png",dst);
}



int main(void) {
	WatermarkRemove source;
	source.Auto("C:\\Users\\chenym-c\\Desktop\\验证文件\\有水印\\c35ec4d3e54e9e360af816761b9c537d.jpeg", 0.7);
}



