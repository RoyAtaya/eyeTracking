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
#include "imageManipulation.h"
using namespace std;
using namespace cv;

// CONSTANTS
#define WIDTH 200

//List functions
void drawBoundingBox(Mat img, int posX, int posY, int width, int height);

int main() {
	//initialize and allocate memory to load the video stream from camera 
	VideoCapture camera(0);

	if (!camera.isOpened()) return 1;

	Mat frame;
	int count = -1;
	while (true) {
		camera.read(frame);
		flip(frame, frame, 1);

		imshow("Video", frame);

		++count;

		imwrite("test" + to_string(count) + ".jpg", frame); // A JPG FILE IS BEING SAVED

		waitKey();

		//exit the loop if user press "Esc" key  (ASCII value of "Esc" is 27) 
		if (27 == char(waitKey(10))) break;
	}

	//Mat img = imread("img1.png");
	//origin of image is top left corner with regular x and y axes
	//drawBoundingBox(img, 200, 150, 15, 10);
	/*
	Mat grayImg;
	cvtColor(img, grayImg, COLOR_BGR2GRAY);
	namedWindow("image", WINDOW_NORMAL);
	imshow("image", grayImg);
	waitKey(0);
	*/
	return 0;
}