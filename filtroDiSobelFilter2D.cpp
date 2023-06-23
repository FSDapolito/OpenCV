#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>
#include <cmath>


using namespace std;
using namespace cv;

int main()
{
	string imageName = "landscape.png";
	Mat image; 
	image = imread(samples::findFile(imageName),IMREAD_COLOR);


	if(image.empty())
	{
		cout << "IMPOSSIBILE APRIRE L'IMMAGINE" << endl;
		return -1;	
	}


	Mat SobelFilterGX = (Mat_<double>(3,3) << -1,-2,-1,0,0,0,1,2,1);
	Mat SobelFilterGY = (Mat_<double>(3,3) << -1,0,1,-2,0,2,-1,0,1);

	Mat ImageWithSobelFilterGX;
	Mat ImageWithSobelFilterGY;
	Mat sobel;


	filter2D(image,ImageWithSobelFilterGX,-1,SobelFilterGX,Point(-1,-1),0,4);
	filter2D(image,ImageWithSobelFilterGY,-1,SobelFilterGX,Point(-1,-1),0,4);
	Sobel(image,sobel,CV_32F,0,1);
	
	
	
	imshow("FILTER GX",ImageWithSobelFilterGX);
	imshow("FILTER GY",ImageWithSobelFilterGY);
	imshow("SOBEL",sobel);



	Mat magnetudoGradiente = (Mat_<double>(3,3));

	for(int i=0;i<SobelFilterGX.rows; i++){
		for(int j=0; j<SobelFilterGX.cols; j++){
		SobelFilterGX.at<double>(i,j) = pow(SobelFilterGX.at<double>(i,j),2);
		SobelFilterGY.at<double>(i,j) = pow(SobelFilterGY.at<double>(i,j),2);
		} cout << endl;
		}

	for(int i=0;i<SobelFilterGX.rows; i++){
		for(int j=0; j<SobelFilterGX.cols; j++){
		magnetudoGradiente.at<double>(i,j) = sqrt ( SobelFilterGX.at<double>(i,j) + SobelFilterGY.at<double>(i,j) );
		}
	}
	

	filter2D(image,magnetudoGradiente,-1,SobelFilterGX,Point(-1,-1),0,4);

	imshow("MAGNETUDO",magnetudoGradiente);
	
	

	waitKey(0);


	return 0;
}
