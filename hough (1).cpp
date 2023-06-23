#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc,char**argv)
{
    // Carica l'immagine da analizzare
    Mat image = imread(argv[1], IMREAD_GRAYSCALE);
    if (image.empty())
    {
        std::cout << "Impossibile caricare l'immagine." << std::endl;
        return -1;
    }

    // Applica il filtro di Canny per rilevare i bordi nell'immagine
    Mat edges;
    Canny(image, edges, 50, 150);

    // Applica l'algoritmo di Hough per rilevare le linee
    std::vector<Vec2f> lines;
    HoughLines(edges, lines, 1, CV_PI / 180, 100);

    // Disegna le linee rilevate sull'immagine originale
    Mat imageWithLines = image.clone();
    for (size_t i = 0; i < lines.size(); i++)
    {
        float rho = lines[i][0];
        float theta = lines[i][1];

        double cosTheta = cos(theta);
        double sinTheta = sin(theta);
        double x0 = rho * cosTheta;
        double y0 = rho * sinTheta;

        Point pt1(cvRound(x0 + 1000 * (-sinTheta)), cvRound(y0 + 1000 * cosTheta));
        Point pt2(cvRound(x0 - 1000 * (-sinTheta)), cvRound(y0 - 1000 * cosTheta));

        line(imageWithLines, pt1, pt2, Scalar(0, 0, 255), 2);
    }

    // Mostra l'immagine originale e l'immagine con le linee rilevate
    imshow("Original Image", image);
    imshow("Image with Lines", imageWithLines);
    waitKey(0);

    return 0;
}
