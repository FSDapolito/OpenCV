#include <opencv2/opencv.hpp>
#include <iostream>
#include <stack>

using namespace cv;
using namespace std;

void regionGrowing(const Mat& image, Mat& segmented, const Point seedPoint, const int threshold) {
    segmented = Mat::zeros(image.size(), CV_8UC1);

    // Create a stack to store the seed points
    stack<Point> seedStack;
    seedStack.push(seedPoint);

    // Get the intensity value of the seed point
    const uchar seedIntensity = image.at<uchar>(seedPoint);

    // Process the stack until it becomes empty
    while (!seedStack.empty()) {
        // Pop the top element from the stack
        Point currentPoint = seedStack.top();
        seedStack.pop();

        // Check if the current point is within the image boundaries
        if (currentPoint.x < 0 || currentPoint.x >= image.cols ||
            currentPoint.y < 0 || currentPoint.y >= image.rows)
            continue;

        // Check if the current pixel is unvisited and within the threshold
        if (segmented.at<uchar>(currentPoint) == 0 &&
            abs(image.at<uchar>(currentPoint) - seedIntensity) <= threshold) {
            // Mark the current pixel as visited and part of the region
            segmented.at<uchar>(currentPoint) = 255;

            // Push the neighboring pixels onto the stack
            seedStack.push(Point(currentPoint.x + 1, currentPoint.y));
            seedStack.push(Point(currentPoint.x - 1, currentPoint.y));
            seedStack.push(Point(currentPoint.x, currentPoint.y + 1));
            seedStack.push(Point(currentPoint.x, currentPoint.y - 1));
        }
    }
}

int main(int argc, char**argv) {
    // Read the image file
    Mat image = imread(argv[1], IMREAD_GRAYSCALE);

    // Check if the image was successfully loaded
    if (image.empty()) {
        cout << "Could not open or find the image." << endl;
        return -1;
    }

    // Perform region growing starting from the seed point (100, 100) with threshold 30
    Mat segmented;
    regionGrowing(image, segmented, Point(100, 100), 30);

    // Display the original image and the segmented result
    imshow("Original Image", image);
    imshow("Segmented Image", segmented);
    waitKey(0);

    return 0;
}
