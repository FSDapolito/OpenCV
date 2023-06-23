#include <opencv2/opencv.hpp>
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace cv;

int main( int argc, char** argv ){

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

    Mat bgr[3];
    split(image,bgr);

    cv::imshow("Original image",image);
    cv::imshow("BGR_Blue image",bgr[0]);
    cv::imshow("BGR_Green image",bgr[1]);
    cv::imshow("BGR_Red image",bgr[2]);
	cv::waitKey(0);
    destroyAllWindows();

    Mat imageBGR;
    merge(bgr,3,imageBGR);

    Mat imageRGB;
    cvtColor(imageBGR,imageRGB,COLOR_BGR2RGB);
    
    Mat rgb[3];
    split(imageRGB,rgb);
    cv::imshow("Original image",image);
    cv::imshow("RGB_Red image",rgb[0]);
    cv::imshow("RGB_Green image",rgb[1]);
    cv::imshow("RGB_Blue image",rgb[2]);
    cv::waitKey(0);
    destroyAllWindows();

    Mat imageHSV;
    cvtColor(imageRGB,imageHSV,COLOR_RGB2HSV);
    
    Mat hsv[3];
    split(imageHSV,hsv);
    cv::imshow("Original image",image);
    cv::imshow("Hue image",hsv[0]);
    cv::imshow("Saturation image",hsv[1]);
    cv::imshow("Value image",hsv[2]);
    cv::waitKey(0);

	return 0;
}
