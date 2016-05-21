#ifndef FACEAR_DETECT_H
#define FACEAR_DETECT_H

#include<vector>
#include"opencv2/opencv.hpp"
using namespace cv;
using namespace std;

class FaceAR_Detect
{

public:
    FaceAR_Detect();

    static int init();
    static int init(cv::VideoCapture &cap,int device);
    static int init(cv::VideoCapture &cap,string device);

    static int dectectFace(Mat &img,Rect &rect);

    static vector<cv::Point> dectectLandmark(Mat &img);//use this
    static vector<cv::Point> dectectLandmark(Mat &image,cv::Rect rect);

    static void close();
    static void close(cv::VideoCapture &cap);

    static void draw_Face(Mat &img,Rect rect);
    static void draw_landmark(Mat &img,vector<cv::Point> landmarks);


};

#endif // FACEAR_DETECT_H
