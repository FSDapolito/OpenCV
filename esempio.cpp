/*
Programma che testa l'individuazione degli edge di una immagine attraverso
l'algoritmo di Canny
*/

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cmath>
using namespace std; 
using namespace cv;

int main(){

Mat image; 
image = imread(samples :: findFile("/home/frank/Desktop/OpenCV_exercises/inter.png"),IMREAD_COLOR);

if(image.empty()){
	cout << "ERROR: Can't open image" << endl; 
	return -1;
}

//convoluzione dell'immagine con un filtro gaussiano
Mat dst;
filter2D(image,dst,CV_32F,getGaussianKernel(2,19));

//calcolare il gradiente del risultato 
for(int i=0; i<dst.rows; i++){
	for(int j=0; j<dst.cols; j++){
		dst.at<int>(i,j) = sqrt( pow(dst.at<int>(i,j),2) + pow(dst.at<int>(i,j),2) );
		}
	}



//visualizzazione dell'immagine
namedWindow("ORIGINAL",WINDOW_AUTOSIZE);
imshow("ORIGINAL",image);
//visualizzazione dell'immagine con filtro
namedWindow("FILTER2D",WINDOW_AUTOSIZE);
imshow("FILTER2D",dst);

/*
//creazione del filtro
Mat filtro1 = (Mat_<double>(3,3) << 0,1,0,1,-4,1,0,1,0);

//creazione di una nuova immagine a cui sottoporre il filtro
Mat immagineFiltro;

//funzione filter2D utile per applicare il filtro all'immagine
filter2D(image,immagineFiltro,-1,filtro1,Point(-1,-1),0,4);

//creazione di una nuova immagine a cui applicare il filtro GaussianBlur
Mat Gauss;
//funzione GaussianBlur
GaussianBlur(image,Gauss,Size(9,9),0);

//creazione di una nuova immagine a cui applicare il filtro Sobel (utile per il riconoscimento dei contorni)
Mat Sobel;
namedWindow("Interphoto",WINDOW_NORMAL);
Mat imageGray;
int dx  = 1;
int dy = 0;
int ksize = 3;
int scale = 1;
int delta = 0;
//convert original image in grayscale image
cvtColor(image,imageGray,COLOR_BGR2GRAY);
cv :: Sobel(image,Sobel,CV_8U,dx,dy,ksize,scale,delta,BORDER_DEFAULT);

while(1){
imshow("Interphoto",Sobel);
char key = (char)waitKey(0);

    if(key == 27)
    {
      return EXIT_SUCCESS;
    }
    if (key == 'k' || key == 'K')
    {
      ksize = ksize < 30 ? ksize+2 : -1;
    }
    if (key == 's' || key == 'S')
    {
      scale++;
    }
    if (key == 'd' || key == 'D')
    {
      delta++;
    }
    if (key == 'r' || key == 'R')
    {
      scale =  1;
      ksize = -1;
      delta =  0;
	}
}
 
//imshow("INTER",image);
//imshow("INTER filtro",immagineFiltro);
//imshow("INTER Gauss",Gauss);
imshow("Interphoto",Sobel);
*/
waitKey(0);

return 0;
}
