#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

/* https://phoenixnap.com/kb/installing-opencv-on-ubuntu */

#include <iostream>

using namespace cv;
using namespace std;

static void help(const char* programName)
{
    cout <<
    "\nA program using pyramid scaling, Canny, contours, and contour simplification\n"
    "to find squares in a video capture.\n"
    "Press ESC to exit.\n"
    "Using OpenCV version " << CV_VERSION << "\n" << endl;
}

int thresh = 100, N = 11; // Increased threshold for edge detection
const char* wndname = "Square Detection Demo";

static double angle(Point pt1, Point pt2, Point pt0)
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1*dx2 + dy1*dy2) / sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

static void findSquares(const Mat& image, vector<vector<Point> >& squares)
{
    squares.clear();

    Mat pyr, timg, gray0(image.size(), CV_8U), gray;

    pyrDown(image, pyr, Size(image.cols / 2, image.rows / 2));
    pyrUp(pyr, timg, image.size());
    vector<vector<Point> > contours;

    for (int c = 0; c < 3; c++)
    {
        int ch[] = { c, 0 };
        mixChannels(&timg, 1, &gray0, 1, ch, 1);

        for (int l = 0; l < N; l++)
        {
            if (l == 0)
            {
                // Use Canny edge detector with a higher threshold
                Canny(gray0, gray, 0, thresh, 5);
                dilate(gray, gray, Mat(), Point(-1, -1));
            }
            else
            {
                gray = gray0 >= (l + 1) * 255 / N;
            }

            findContours(gray, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

            vector<Point> approx;

            for (size_t i = 0; i < contours.size(); i++)
            {
                // Increase the accuracy of contour approximation
                approxPolyDP(contours[i], approx, arcLength(contours[i], true) * 0.04, true);

                if (approx.size() == 4 &&
                    fabs(contourArea(approx)) > 1000 &&
                    isContourConvex(approx))
                {
                    double maxCosine = 0;

                    for (int j = 2; j < 5; j++)
                    {
                        double cosine = fabs(angle(approx[j % 4], approx[j - 2], approx[j - 1]));
                        maxCosine = MAX(maxCosine, cosine);
                    }

                    // Increase the threshold for identifying squares
                    if (maxCosine < 0.2)
                        squares.push_back(approx);
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
    help(argv[0]);

    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cerr << "Error: Unable to open camera." << endl;
        return -1;
    }

    Mat frame;
    namedWindow(wndname, 1);

    while (true)
    {
        cap >> frame;
        if (frame.empty())
        {
            cerr << "Error: Unable to read frame." << endl;
            break;
        }

        vector<vector<Point> > squares;
        findSquares(frame, squares);

        polylines(frame, squares, true, Scalar(0, 255, 0), 3, LINE_AA);
        imshow(wndname, frame);

        int key = waitKey(30);
        if (key == 27) // ESC key
            break;
    }

    return 0;
}
