#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    // Carica l'immagine in scala di grigi
    cv::Mat image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    if (image.empty())
    {
        std::cout << "Impossibile caricare l'immagine." << std::endl;
        return -1;
    }

    // Applica l'algoritmo di Otsu per ottenere la soglia ottimale
    double otsuThreshold;
    cv::threshold(image, image, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

    // Dividi l'immagine in due soglie utilizzando la soglia di Otsu
    cv::Mat threshold1, threshold2;
    cv::threshold(image, threshold1, 0, 127, cv::THRESH_BINARY);
    cv::threshold(image, threshold2, 128, 255, cv::THRESH_BINARY_INV);

    // Visualizza le immagini risultanti
    cv::imshow("Threshold 1", threshold1);
    cv::imshow("Threshold 2", threshold2);
    cv::waitKey(0);

    return 0;
}
