/*
Programma che testa l'individuazione degli edge di una immagine attraverso
l'algoritmo di Canny
*/

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std; 
using namespace cv;
using namespace samples;


//ERROR MESSAGE
int msgError(string msg)
{
	cerr << "!!! ERROR !! " << msg << endl;
	return -1;
}

//VARIABLES DECLARATION
string	window = "CANNY EDGE DETECTION";
int	lowThreshold=0;
int 	maxThreshold=100;
int	kernel_size=3;

//INPUT IMAGE and  DETECTED EDGE IMAGE
cv::Mat input; 
cv::Mat edge;

//CANNY ALGO
void CannyEdgeDetection(int,void*)
{
	//reduce noisy
	GaussianBlur(input,edge,Size(5,5),0);
	//canny function
	Canny(edge,edge,lowThreshold,maxThreshold,kernel_size,true);
	//show image
	imshow(window,edge);
}




int main(int argc,char**argv)
{
	if(argc<2){msgError("FORGOT TO WRITE IMAGE NAME");}

	//read image
	input = imread(findFile(argv[1]),IMREAD_GRAYSCALE);
	//check image
	if(input.empty()){msgError("COULDN'T OPEN IMAGE");}

	//create window to display image
	//namedWindow(window,WINDOW_AUTOSIZE);
	
	//canny algorithm
	CannyEdgeDetection(0,0);

	waitKey(0);
return 0;
}


