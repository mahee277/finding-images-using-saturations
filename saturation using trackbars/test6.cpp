#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


///////////////  Images  //////////////////////
Mat imgHSV,mask;
int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;
void main() {

    string path = "Resources/shapes.png";
    Mat img = imread(path);
    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    namedWindow("trackbars", (640, 200));
    createTrackbar("hue min", "trackbars", &hmin, 179);
    createTrackbar("hue max", "trackbars", &hmax, 179);
    createTrackbar("sat min", "trackbars", &smin, 255);
    createTrackbar("sat max", "trackbars", &smax, 255);
    createTrackbar("val min", "trackbars", &vmin, 255);
    createTrackbar("val max", "trackbars", &vmax, 255);

    while (true)
    {
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        inRange(imgHSV, lower, upper, mask);

       
        imshow("Image", img);
        imshow("image HSV", imgHSV);
        imshow("image mask", mask);
        waitKey(1);
    }
    

}