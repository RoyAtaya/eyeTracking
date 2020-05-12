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

// CONSTANTS
#define W 200

//List functions
void drawBoundingBoxes(Mat img, int posX, int posY, int width, int height);

int main() {
	Mat img = imread("img1.png");
	drawBoundingBoxes(img, 100, 100, 30, 40);
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
Purpose:
Param:	img		-	image that we want to draw the bounding boxes (ellipses)
					on (multidimensional array)
		posX	-	position of the bounding ellipse in the x direction
		posY	-	position of the boudning ellipse in the y direction
		width	-	width of bounding ellipse
		height	-	height of bounding ellipse
*/
void drawBoundingBoxes(Mat img, int posX, int posY, int width, int height) {
	int thickness = 2;
	int lineType = 8;
	int angle = 30;
	Scalar color = Scalar(0, 0, 255); // BGR

	ellipse(img, Point(posX, posY), Size(width, height), angle, 0, 360, color, thickness, lineType);
	imshow("image2", img);
	waitKey();
}