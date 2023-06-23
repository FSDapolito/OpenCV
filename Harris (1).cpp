/*

	HARRIS ALGORITHM CORNER DETECTED
*/

//LIBRERIE
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;


//VARIABILI
Mat src, src_gray;
int thresh = 200;
int max_thresh = 255;
const char* source_window = "Source image";
const char* corners_window = "Corners detected";

//DICHIARAZIONE DELLA FUNZIONE CORNER HARRIS
void cornerHarris_demo();


//FUNZIONE MAIN
int main( int argc, char** argv )
{
//LETTURA DELL'IMMAGINE
    src = imread(argv[1]);
//CHECK DELLA LETTURA    
if ( src.empty() )
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }
//INSERISCI NELLA NUOVA MATRICE L'IMMAGINE IN SCALA DI GRIGIO
    cvtColor( src, src_gray, COLOR_BGR2GRAY );
//DICHIARA LA FINESTRA PER L'IMMAGINE ORIGINALE 
   namedWindow( source_window );
//MOSTRA L'IMMAGINE ORIGINALE
    imshow( source_window, src );
//CHIAMATA ALLA FUNZIONE CORNER HARRIS
    cornerHarris_demo();
    waitKey();
    return 0;
}

//DEFINIZIONE DELLA FUNZIONE CORNER HARRIS
void cornerHarris_demo()
{
//VARIABILI DELLA FUNZIONE CORNER HARRIS
    int blockSize = 2;
    int apertureSize = 3;
    double k = 0.04;
//INIZIALIZZAZIONE A ZERO DEI VALORI DELLA MATRICE DESTINAZIONE
    Mat dst = Mat::zeros( src.size(), CV_32FC1 );
//FUNZIONE CORNER HARRIS CON GLI ARGOMENTI DELLA CHIAMATA
    cornerHarris( src_gray, dst, blockSize, apertureSize, k );
//DICHIARAZIONE DELLE MATRICI DA NORMALIZZARE E SOGLIARE
    Mat dst_norm, dst_norm_scaled;
//NORMALIZZAZIONE DELLA MATRICE IN UN RANGE DI VALORI DA 0,255
    normalize( dst, dst_norm, 0, 255,NORM_MINMAX);
//SOGLIATURA    
convertScaleAbs( dst_norm, dst_norm_scaled );
    
//CICLI FOR SULLA MATRICE APPENA SOGLIATA PER CERCHIARI I VALORI CHE SUPERANO LA SOGLIATURA "THRESH"
for( int i = 0; i < dst_norm.rows ; i++ )
    {
        for( int j = 0; j < dst_norm.cols; j++ )
        {
            if(dst_norm.at<float>(i,j) > thresh )
            {
		//CERCHIO AI VALORI CON LA CHIAMATA CIRCLE
                circle( dst_norm_scaled, Point(j,i), 5, Scalar(0,255,0));
            }
        }
    }
//FINESTRA PER L'IMMAGINE CORNER DETECTED
    namedWindow( corners_window,WINDOW_AUTOSIZE );
    imshow( corners_window, dst_norm_scaled );
}










