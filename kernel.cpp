#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include <cmath>

using namespace std; 
using namespace cv; 

int main(int numero_argomenti_riga_di_comando, char** argomenti_riga_di_comando )
{

	string imageName = numero_argomenti_riga_di_comando > 2 ? argomenti_riga_di_comando[1] : "inter.png";
	Mat image;
	image = imread(samples :: findFile(imageName), IMREAD_COLOR);
	if(image.empty())
	{
		cout << "Cannot load the image" << endl;
		return 1;	
	}

	//first kernel
	Mat kernel1 = (Mat_<double>(3,3) << 0,1,0,1,-4,1,0,1,0);
	//second kernel
	Mat kernel2 = (Mat_<double>(3,3) << cos(360),-sin(360),0,sin(360),cos(360),0,0,0,1);
	//third kernel
	Mat kernel3 = (Mat_<double>(3,3) << 2,1,0,1,1,-1,0,-1,-2);

	Mat imageWithFilter; 
	filter2D(image, imageWithFilter,-1,kernel2,Point(0,0),0,4);
	//Sobel(image,imageWithFilter,CV_32F,1,0);	
	imshow("ORIGINAL",image);
	imshow("ORIGINAL WITH FILTER",imageWithFilter);

	//Gaussian Blur 
	

	waitKey(0);


	return 0; 
}
