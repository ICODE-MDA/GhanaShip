// CFARImplementation.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include "CFARFilter.h"
using namespace std;


int main(){
	IplImage *inputImage = cvLoadImage("SOLA.png",0);
	IplImage *outputImage = cvCreateImage(cvSize(inputImage->width,inputImage->height),IPL_DEPTH_8U,1);
	ImageMean(inputImage);

	//CFARDetect(inputImage,outputImage);
	/*cvNamedWindow("myWindow",1);
	cvShowImage("myWindow",inputImage);
	cvReleaseImage(&inputImage);
	cvWaitKey(0);
	*/
	return 0;
}