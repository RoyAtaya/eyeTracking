/*
##################################################
					PLANNING
##################################################
NECESSARY FUNCTIONS:
- main function
- draws a bounding box around the eye and displays it in a separate windowm (output image)
- function to get images from video feed
- function to process input images
- other helper functions

OTHER NOTES:
- need to determine a method of finding eye in image
	- maybe ORB or SIFT (if available in c++ and free)
- should we track both eyes? or just one eye?
- how to tell if there is no eye?
- could be done with machine learning
- Should we use objects? I don't think we need objects...
*/

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	Mat img = imread("fatSquirttle.jpg");
	Mat grayImg;
	cvtColor(img, grayImg, COLOR_BGR2GRAY);
	namedWindow("image", WINDOW_NORMAL);
	imshow("image", grayImg);
	waitKey(0);
	return 0;
}