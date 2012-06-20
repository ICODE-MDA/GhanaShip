#include <iostream>
#include <opencv\highgui.h>
#include <opencv\cv.h>
#include "CFARFilter.h"
using namespace std;

void CFARDetect(IplImage* input_image, IplImage* output_image)
{
	bool isShip = false;
	bool debug = false;

	// --------------------  BEGIN CODE TO PERFORM LAND MASKING ----------------
	
	IplImage* bw_detect = cvCreateImage(cvGetSize(input_image),IPL_DEPTH_8U,1);
	
 

	if (debug)
		 cout << "Starting ship detection6" <<endl;

	
	int image_size_width = input_image->width;
	int image_size_height = input_image->height;
	

	IplImage *bw_sub_image;
	IplImage *target;
	IplImage *guard;
	IplImage *background;
	IplImage *separation;
	IplImage *backgroundMask;

	int targetSize = 20;
	int guardSize = 35;
	int backgroundSize = 45; 

	// CFAR algorithm implemented here   ------>  

	for (int i=0; i<image_size_width; i+=targetSize)
	{
			for (int j=0; j<image_size_height; j+=targetSize)
			{
				// Creating the target Window
				cvSetImageROI(input_image, cvRect(i, j,targetSize, targetSize));
				CvRect target_ROI;
				target_ROI = cvGetImageROI(input_image);
				target = cvCreateImage(cvSize(target_ROI.width, target_ROI.height), input_image->depth,1);
				bw_sub_image = cvCreateImage(cvSize(target_ROI.width, target_ROI.height), IPL_DEPTH_8U,1);
				cvCopy(input_image, target);
				cvResetImageROI(input_image);


				// Creating The Guard Window
				cvSetImageROI(input_image, cvRect(i, j,guardSize, guardSize));
				CvRect guard_ROI;
				guard_ROI = cvGetImageROI(input_image);
				guard = cvCreateImage(cvSize(guard_ROI.width, guard_ROI.height), input_image->depth,1);
				cvCopy(input_image, guard);
				cvResetImageROI(input_image);


				//Creating The Background Window
				cvSetImageROI(input_image, cvRect(i, j,backgroundSize, backgroundSize));
				CvRect background_ROI;
				background_ROI = cvGetImageROI(input_image);
				background = cvCreateImage(cvSize(background_ROI.width, background_ROI.height), input_image->depth,1);
				cvCopy(input_image, background);
				cvResetImageROI(input_image);


				cvSetImageROI(bw_detect, cvRect(i, j,targetSize, targetSize));
					if(isShip){
						cvSet(bw_detect,cvScalar(255));
					}else{
						cvSet(bw_detect,cvScalar(0)); // You can use cvZero(bw_detect);
					}
				cvResetImageROI(bw_detect);
			}
	}

	if (debug) imshow(bw_detect);
	cvReleaseImage(&bw_sub_image);
	cvCopy(bw_detect,output_image);
	cvReleaseImage(&bw_detect);

	return;
}
bool isShip(IplImage* target, IplImage* guard, IplImage* background){


	return true;
}
double ImageMean(IplImage* inputImage){
	int inputStep = inputImage->widthStep/sizeof(uchar);
	int pixelValue;
	long pixelSum = 0;

	uchar* inputData = (uchar*) inputImage->imageData;
		for (long i = 0; i < inputImage->height; ++i)
		{
			for (long j = 0; j < inputImage->width; ++j)
			{	
				pixelValue = (int)inputData[j * inputStep + i];
				pixelSum += pixelValue;
			}
		}
	int pixelCount = inputImage->width * inputImage->height;
	double mean = pixelSum/(double) pixelCount;

	//Return The calculated Mean
	return mean;
}
double ImageStandardDeviation(IplImage* inputImage){

	return 0.0;
}

void imshow (IplImage* input)
{
	cvNamedWindow( "WINDOW", 1 ); 
	cvShowImage( "WINDOW", input );
	cvWaitKey(0);
	cvDestroyWindow( "WINDOW" ); 

return;
}