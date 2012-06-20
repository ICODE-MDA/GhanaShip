// OpenCV functions
#include <opencv/cv.h>
#include <opencv/highgui.h>


// For writing to cout
#include <iostream>			// For writing to streams (for example the cout stream, which we will discuss)
#include <fstream>			// Also for writing to streams

#include <vector>	// vector
#include <math.h>	// math

void CFARDetect(IplImage* input_image, IplImage* output_image);
void imshow (IplImage* input);
bool isShip(IplImage* target, IplImage* guard, IplImage* background);
double ImageMean(IplImage* inputImage);
double ImageStandardDeviation(IplImage* inputImage);

