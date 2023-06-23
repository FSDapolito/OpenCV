#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <cstdlib>
#include <iostream>
using namespace std;
using namespace cv;


int main(int args, char** argv)
{
	Mat image;
	image = imread(samples :: findFile(argv[1]),IMREAD_COLOR);

	if(image.empty())
	{cout << "NON E' STATO POSSIBILE APRIRE L'IMMAGINE"<<endl; return EXIT_FAILURE;}

	Mat imageRBG[3];
	split(image,imageRBG);

	imshow("ORIGINAL",image);
	imshow("RED",imageRBG[0]);
	imshow("BLUE",imageRBG[1]);
	imshow("GREEN",imageRBG[2]);

	waitKey(0);

	return 0;
}
