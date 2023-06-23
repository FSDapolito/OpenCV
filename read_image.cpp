#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
 string path = "/home/frank/Desktop/OpenCV_exercises/inter.png";
 Mat img = imread(path);
 imshow("INTER IMAGE", img);
 waitKey(0);

return 0;}
