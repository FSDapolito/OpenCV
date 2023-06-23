#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//IN THIS CODE I USE THE FUNCTION FOR PADDING AN IMAGE [copyMakeBorder]
//FUNCTION ARGUMENT
/*
	*SRC		INPUT ARRAY
	*DST		RESULT
	*TOP		TOP SIDE PADDING
	*BOTTOM		BOTTOM SIDE PADDING
	*LEFT		LEFT SIDE PADDING
	*RIGHT		RIGHT SIDE PADDING
	*BORDERTYPE	PIXEL EXTRAPOLATION METHOD
	*VALUE		USED FOR CONSTANT BORDER	SCALAR& VALUE	
*/

//IMAGE 
string image = "/home/frank/Desktop/OpenCV_exercises/inter.png";

int main(int argc, char** argv)
{
	
	string window_name = "copyMakeBorder DEMO";

	Mat SRC, DST;
	int TOP,BOTTOM,LEFT,RIGHT, BORDERTYPE=BORDER_CONSTANT;
	RNG rng(1);

	string imageName = argc >=2 ? argv[1] : image;

	//LOADS AN IMAGE 
	SRC = imread(samples :: findFile(imageName), IMREAD_COLOR);

	//CHECK IF IMAGE IS LOADED FINE
	
	if(SRC.empty())
	{
		cout << "ERROR OPENING IMAGE" << endl;
		cout << "Program Arguments : [image_name -- default inter.png]" << endl;
		return -1;
	}


	//BRIEF HOW TO FOR THIS PROGRAM
	
	cout << "\n\tCOPY MAKE BORDER DEMO :" << endl;
	cout << "\t --------------------------------" << endl;
	cout << "** press 'ESC' to exit the program" << endl;
	cout << "** press 'c'	to set the border to a random constant value" << endl;
	cout << "** press 'r'	to set the border to be replicated" << endl;

	namedWindow(window_name, WINDOW_NORMAL);



	//INITIALIZE ARGUMENTS FOR THE FILTER
	TOP = (int) (0.1 * SRC.rows);
	BOTTOM = TOP; 
	LEFT = (int) (0.1 * SRC.cols);
	RIGHT = LEFT; 

	for(;;)
	{
		Scalar value ( rng.uniform(0,255), rng.uniform(0,255), rng.uniform(0,255) );

		copyMakeBorder(SRC, DST, TOP, BOTTOM, LEFT, RIGHT, BORDERTYPE, value);

		imshow(window_name,DST);
		char c = (char)waitKey(500);
		
		if(c==27){break;}
		//27 IN ASCII TABLE IS 'ESC' COMMAND		
		
		else if (c == 'c') {BORDERTYPE = BORDER_CONSTANT;}
		else if (c == 'r') {BORDERTYPE = BORDER_REPLICATE;}
	
	}



	//the function clone, copy the DST Mat in the result Mat
    Mat result = DST.clone();

    for (int i = 1; i < DST.rows - 1; i++) 
	{
		for (int j = 1; j < DST.cols - 1; j++) 
		{
		   cv::Scalar mean = cv::mean(DST(cv::Rect(j - 1, i - 1, 3, 3)));
		    result.at<uchar>(i, j) = static_cast<uchar>(mean[1]);
	        }
    	}	


	namedWindow(window_name, WINDOW_NORMAL);

    //imshow("Original", DST);
    imshow("Result", result);
    waitKey(0);
	


	return 0;
}
