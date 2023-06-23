#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main(int argc, char** argv)
{
	string imageName = argc > 2 ? argv[1] : "inter.png";

	//ORIGINAL IMAGE
	Mat image;
	image = imread(samples :: findFile(imageName), IMREAD_COLOR);

	if(image.empty())
	{
		cout << "CANNOT OPEN IMAGE OR IT'S NOT IN THIS PC" << endl;
		return -1;
	}

	//IMAGE WITH GAUSSIAN BLUR FILTER 3X3
	Mat image1;
	GaussianBlur(image,image1,Size(9,9),0);

	//IMAGE WITH GAUSSIAN BLUR FILTER 5X5
	Mat image2;
	GaussianBlur(image,image2,Size(15,15),0);

	string 	window_original_image 		= "ORIGINAL IMAGE WINDOW";
	string 	window_gaussinaBlur3x3_image 	= "GAUSSIAN BLUR 3X3 WINDOW";
	string 	window_gaussinaBlur5x5_image 	= "GAUSSIAN BLUR 5X5 WINDOW";
	
	namedWindow(window_original_image);
	namedWindow(window_gaussinaBlur3x3_image);
	namedWindow(window_gaussinaBlur5x5_image);


	imshow(window_original_image,image);
	imshow(window_gaussinaBlur3x3_image,image1);
	imshow(window_gaussinaBlur5x5_image,image2);

	waitKey(0);
	destroyAllWindows();


	return 0;
}
