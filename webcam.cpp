#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main()
{
 VideoCapture cap(0);
 Mat img;
 while(true){
	
	cap.read(img);
	imshow("WEBCAMERA",img);
	waitKey(10);
	}

return 0;}
