#include <opencv2/opencv.hpp>

int main() {
    // Load an image from file
    cv::Mat image = cv::imread("example.jpg");

    // Check if the image was loaded successfully
    if (image.empty()) {
        std::cerr << "Error: Unable to load image." << std::endl;
        return 1;
    }

    // Resize the image to make it smaller
    cv::Mat resizedImage;
    cv::resize(image, resizedImage, cv::Size(), 0.2, 0.2); // 50% smaller in both dimensions

    // Convert the resized image to HSV color space
    cv::Mat hsvImage;
    cv::cvtColor(resizedImage, hsvImage, cv::COLOR_BGR2HSV);

    // Define lower and upper bounds for blue color in HSV
    cv::Scalar lowerBlue = cv::Scalar(100, 50, 50); // Lower bound for blue color
    cv::Scalar upperBlue = cv::Scalar(130, 255, 255); // Upper bound for blue color

    // Create a mask for blue color
    cv::Mat blueMask;
    cv::inRange(hsvImage, lowerBlue, upperBlue, blueMask);

    // Define lower and upper bounds for green color in HSV
    cv::Scalar lowerGreen = cv::Scalar(40, 50, 50); // Lower bound for green color
    cv::Scalar upperGreen = cv::Scalar(80, 255, 255); // Upper bound for green color

    // Create a mask for green color
    cv::Mat greenMask;
    cv::inRange(hsvImage, lowerGreen, upperGreen, greenMask);

    // Define lower and upper bounds for red color in HSV
    cv::Scalar lowerRed1 = cv::Scalar(0, 50, 50); // Lower bound for red color (hue range 0-10)
    cv::Scalar upperRed1 = cv::Scalar(10, 255, 255); // Upper bound for red color (hue range 0-10)
    cv::Scalar lowerRed2 = cv::Scalar(160, 50, 50); // Lower bound for red color (hue range 160-180)
    cv::Scalar upperRed2 = cv::Scalar(180, 255, 255); // Upper bound for red color (hue range 160-180)

    // Create masks for red color (combining hue ranges)
    cv::Mat redMask1, redMask2;
    cv::inRange(hsvImage, lowerRed1, upperRed1, redMask1);
    cv::inRange(hsvImage, lowerRed2, upperRed2, redMask2);
    cv::Mat redMask = redMask1 | redMask2;

    // Convert the original image to grayscale
    cv::Mat grayImage;
    cv::cvtColor(resizedImage, grayImage, cv::COLOR_BGR2GRAY);

    // Convert the grayscale image to BGR color space
    cv::Mat grayBGRImage;
    cv::cvtColor(grayImage, grayBGRImage, cv::COLOR_GRAY2BGR);

    // Create a copy of the original image for each color
    cv::Mat blueImage = resizedImage.clone();
    cv::Mat greenImage = resizedImage.clone();
    cv::Mat redImage = resizedImage.clone();

    // Apply the masks to the corresponding images
    blueImage.setTo(cv::Scalar(255, 0, 0), blueMask); // Blue color
    greenImage.setTo(cv::Scalar(0, 255, 0), greenMask); // Green color
    redImage.setTo(cv::Scalar(0, 0, 255), redMask); // Red color

    // Combine the colored images with the grayscale image using the masks
    cv::Mat resultImage1;
    cv::Mat resultImage2;
    cv::Mat resultImage3;
    cv::bitwise_and(grayBGRImage, blueImage, resultImage1, blueMask);
    cv::bitwise_and(grayBGRImage, greenImage, resultImage2, greenMask);
    cv::bitwise_and(grayBGRImage, redImage, resultImage3, redMask);

    // Display the result
    cv::imshow("Result", resultImage1);
    cv::waitKey(0);
    cv::imshow("Result", resultImage2);
    cv::waitKey(0);
    cv::imshow("Result", resultImage3);
    cv::waitKey(0);

    return 0;
}
