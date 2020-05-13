#include<opencv2/opencv.hpp>
using namespace cv;
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