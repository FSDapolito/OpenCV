#include <opencv2/opencv.hpp>
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace cv;

int main( int argc, char** argv ){

	int dim;
	
	if( argc < 2){
        cout<<"usage: "<<argv[0]<<" image_name"<<endl;
        exit(0);
    }
    String imageName = argv[1];

	//Lettura immagine    
    Mat image;
    image = imread(imageName, IMREAD_COLOR );
    if( image.empty() ){
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    //Lettura dimensione filtro
    cout<<"Inserire dimensione filtro: ";
    cin>>dim;

    //Gaussian filter
    Mat output;
    GaussianBlur(image,output,Size(dim,dim),0,0);

    Mat imageHSV;
    cvtColor(image,imageHSV,COLOR_BGR2HSV);
    
    Mat hsv[3];
    split(imageHSV,hsv);
    GaussianBlur(hsv[2],hsv[2],Size(dim,dim),0,0);
    merge(hsv,3,imageHSV);

    Mat imageBGR;
    cvtColor(imageHSV,imageBGR,COLOR_HSV2BGR);

    cv::imshow("Original image",image);
	cv::imshow("GaussianBlur image",output);
	cv::imshow("GaussianBlur Vimage",imageBGR);
	cv::waitKey(0);

	return 0;
}
