#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <iostream>


using namespace cv;
using namespace std; 
using namespace samples;


int main() {

	Mat image = imread (findFile("inter.png"), IMREAD_COLOR);
	

	if(!image.data)
	{
		cout << "Could not open or find the image" << endl;
		return -1;
	}

	blur(image,image,Size(100,100));
	
	namedWindow("window_name",CV_WINDOW_NORMAL);

	imshow("PHOTO",image);

	waitKey(0);

		
    return 0;
}

