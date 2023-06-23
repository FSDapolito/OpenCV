#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	string path1 = "/home/frank/Desktop/OpenCV_exercises/inter.png";
	string path2 = "/home/frank/Desktop/OpenCV_exercises/inter.png";


	Mat image1 = imread(path1,IMREAD_COLOR);
	Mat image2 = imread(path2,IMREAD_COLOR);

	if(image1.empty() || image2.empty())
	{
		cout << "Could not read the image : " << endl;
		return 1;
	}

	rotate(image2,image2,ROTATE_180);
	resize(image2,image2,Size(500,500));

 /*
	for(int i=0;i<image2.rows;i++)
	{
		 for(int j=0; j<image2.cols;j++)
			{
			 Vec3b bgrPixel = image2.at<Vec3b>(i,j);
			unsigned char grayScale = (bgrPixel [2] +
						   bgrPixel [1] +
						   bgrPixel [0] ) / 3;

			image2.at<Vec3b>(i,j) = {grayScale,grayScale,grayScale};
			Vec3b grayPixel = image2.at<Vec3b>(i,j);
			}
	}

*/
	imshow("First",image1);
	imshow("Second",image2);

	

	if(waitKey(0) =='s')
	{
		imwrite("starry-night.png",image2);
	}

	return 0;
}

