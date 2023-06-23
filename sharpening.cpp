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

    Mat output;
    Laplacian(image,output,image.type());

    imshow("Original image",image);
    imshow("Laplacian image",output);

    waitKey(0);
}
