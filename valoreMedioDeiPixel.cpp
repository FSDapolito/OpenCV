#include <opencv2/opencv.hpp>

int main() {
    cv::Mat image = cv::imread("/home/frank/Desktop/OpenCV_exercises/inter.png", cv::IMREAD_COLOR);
    cv::Mat result = image.clone();

    for (int i = 1; i < image.rows - 1; i++) {
        for (int j = 1; j < image.cols - 1; j++) {
            cv::Scalar mean = cv::mean(image(cv::Rect(j - 1, i - 1, 3, 3)));
            result.at<uchar>(i, j) = static_cast<uchar>(mean[0]);
        }
    }

    cv::imshow("Original", image);
    cv::imshow("Result", result);
    cv::waitKey(0);

    return 0;
}

