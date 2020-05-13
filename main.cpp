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
#include "Util.h"
using namespace std;
using namespace cv;

// CONSTANTS
#define WIDTH 200

//List functions
void drawBoundingBox(Mat img, int posX, int posY, int width, int height);

int main() {
	Mat img = imread("img1.png");
	// origin of image is top left corner with regular x and y axes
	drawBoundingBox(img, 200, 150, 15, 10);
	/*
	Mat grayImg;
	cvtColor(img, grayImg, COLOR_BGR2GRAY);
	namedWindow("image", WINDOW_NORMAL);
	imshow("image", grayImg);
	waitKey(0);
	*/
	return 0;
}

/*
Purpose:	draws a bounding box (ellipse) on a given image with a provided position
			and size
Param:		img		-	image that we want to draw on
			posX	-	position of the bounding ellipse in the x direction
			posY	-	position of the boudning ellipse in the y direction
			width	-	width of bounding ellipse
			height	-	height of bounding ellipse
*/
void drawBoundingBox(Mat img, int posX, int posY, int width, int height) {
	int thickness = 2;
	int lineType = 8;
	int angle = 0;
	Scalar color = Scalar(0, 0, 255); // BGR

	ellipse(img, Point(posX, posY), Size(width, height), angle, 0, 360, color, thickness, lineType);
	imshow("image2", img);
	waitKey();
}