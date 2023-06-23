#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main(int argc, char**argv){

	string path1 = argv[1];	
	string path2 = argv[1];

	//CHECK WITHOUT SECOND PARAMETER
	//Mat image1 = imread(path1,IMREAD_COLOR);
	//Mat image2 = imread(path2,IMREAD_COLOR);

	Mat image1 = imread(path1);
	Mat image2 = imread(path2);

	if( image1.empty() || image2.empty() )
	{
		cout << "COULD NOT READ THE IMAGE" << endl;
		return 1; 	
	}	


	//rotate function COUNTERCLOCKWISE
	//rotate(image2,image2,ROTATE_90_COUNTERCLOCKWISE);
	
	rotate(image2,image2,ROTATE_90_CLOCKWISE);


	//RESIZE FUNCTION (LENGHT,WIDTH)	
	resize(image2,image2,Size(500,500));

	//GRAY SCALE IMAGE
	for(int i=0; i<image2.rows; i++) {
		for(int j=0; j<image2.cols; j++) {

			Vec3b bgrPixel = image2.at<Vec3b>(i,j);
			unsigned char grayScale = (bgrPixel[0] + bgrPixel[1] + bgrPixel[2]) / 3;
			image2.at<Vec3b>(i,j) = {grayScale, grayScale, grayScale};
			//Vec3b greyPixel = image2.at<Vec3b>(i,j);
		}
	}


	imshow("FIRST",image1);
	imshow("SECOND",image2);

	int k = waitKey(0);
	if(k == 's'){
		imwrite("starry_night.png",image2);
	}

	return 0;
}







