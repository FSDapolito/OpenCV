#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>


using namespace std;
using namespace cv;

int main()
{
 string path = "/home/frank/Desktop/OpenCV_exercises/inter.png";
 Mat img = imread(path);
 Mat imgGray;
 cvtColor(img,imgGray,COLOR_BGR2GRAY);
 imshow("Normal logo", img);
 imshow("Gray logo", imgGray);
 waitKey(0);

 return 0;
}
