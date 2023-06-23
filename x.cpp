#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace cv;
using namespace std;
/// Global variables
Mat src, dst, tmp;
string window_name = "Workshop : Pyramids Demo";
int main(int argc, char** argv)
{
/// General instructions
cout << "Zoom In-Out demo"<<endl;    
cout << " ------------------"<<endl;
cout<<" * [u] -> Zoom in"<<endl;
cout<<" * [d] -> Zoom out"<<endl;
cout << " * [q] -> Close program" << endl;
/// Test image - Make sure it s divisible by 2^{n}
src = imread("inter.png");
if (!src.data)
{
printf(" No data! -- Exiting the program n");
return -1;
}
tmp = src;
dst = tmp;
/// Create window
namedWindow(window_name, CV_WINDOW_NORMAL);
imshow(window_name, dst);
/// Loop
while (char(waitKey(1) != 'q'))
{
int c;
c = waitKey(1);
if ((char)c == 'u')
{
pyrUp(tmp, dst, Size(tmp.cols * 2, tmp.rows * 2));
cout << " ** Zoom In: Image x 2"<<endl;
}
else if ((char)c == 'd')
{
pyrDown(tmp, dst, Size(tmp.cols / 2, tmp.rows / 2));
cout<<" ** Zoom Out: Image / 2"<<endl;
}
imshow(window_name, dst);
tmp = dst;
}
return 0;
}
