#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{

	cv::Mat img = cv::imread("C:/Users/andre/OneDrive/Desktop/qual-e-il-mare-piu-bello-della-sardegna.jpg");

	if (img.empty()) {
		std::cout << "Could not open or find the image";
		return -1;
	}
	else {
		cv::namedWindow("Original");
		std::cout << img.channels();
		cv::imshow("Original", img);
		cv::waitKey(0);
	}

	if (img.channels() == 3) {
		cv::Mat red, green, blue;
		cv::extractChannel(img, blue, 2);
		cv::insertChannel(blue, img, 0);
		cv::imshow("Green channel", img);
		cv::waitKey(0);
	}

	return 0;
}