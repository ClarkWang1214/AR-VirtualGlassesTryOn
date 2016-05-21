#pragma once

//#include "opencv.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>


#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio/videoio.hpp>  // Video write  opencv2/

#include <iostream>

using namespace cv;
using namespace std;

namespace clarkPoseEsti
{
//struct facegeometry{

//    double LeftEye_Nose_distance;
//    double RightEye_Nose_distance;
//    double LeftEye_RightEye_distance;
//    double Nose_Mouth_distance;

//    double init_LeftEye_Nose_distance;
//    double init_RightEye_Nose_distance;
//    double init_LeftEye_RightEye_distance;
//    double init_Nose_Mouth_distance;

//    double init_Mean_Feature_distance;
//    double Mean_Feature_distance;

//};
//typedef struct facegeometry FaceGeom;

//struct pose{

//    double pitch, yaw, roll;
//    double slant;
//    double zaxis, xaxis, yaxis;


////        //Kalman filer
////        double kpitch, kyaw;
////        double kpitch_pre, kyaw_pre;

//    //float pitch[900];
//    //float yaw[900];
//    //float roll[900];

//};
//typedef struct pose Pose;

//struct facefeatures{
//    //create CvPoint structures to hold the located feature coordinates
//    //centre points
//    CvPoint2D32f 	Face;
//    CvPoint2D32f	LeftEye;
//    CvPoint2D32f	RightEye;
//    CvPoint2D32f	Nose;
//    CvPoint2D32f 	Mouth;

//    CvPoint2D32f	NoseBase;
//    CvPoint2D32f 	MidEyes;

//    CvRect* FaceBox;
//    CvRect* NoseBox;
//    CvRect* EyeBox1;
//    CvRect* EyeBox2;
//    CvRect* MouthBox;

//};
//typedef struct facefeatures Face;

    class FaceGeom{
    public:
        double LeftEye_Nose_distance;
        double RightEye_Nose_distance;
        double LeftEye_RightEye_distance;
        double Nose_Mouth_distance;

        double init_LeftEye_Nose_distance;
        double init_RightEye_Nose_distance;
        double init_LeftEye_RightEye_distance;
        double init_Nose_Mouth_distance;

        double init_Mean_Feature_distance;
        double Mean_Feature_distance;

    };

    class Pose{
    public:
        double pitch, yaw, roll;
        double slant;
        double zaxis, xaxis, yaxis;


    //        //Kalman filer
    //        double kpitch, kyaw;
    //        double kpitch_pre, kyaw_pre;

        //float pitch[900];
        //float yaw[900];
        //float roll[900];

    };

    class Face{
    public:
        //create CvPoint structures to hold the located feature coordinates
        //centre points
        CvPoint2D32f 	Face;
        CvPoint2D32f	LeftEye;
        CvPoint2D32f	RightEye;
        CvPoint2D32f	Nose;
        CvPoint2D32f 	Mouth;

        CvPoint2D32f	NoseBase;
        CvPoint2D32f 	MidEyes;

        CvRect* FaceBox;
        CvRect* NoseBox;
        CvRect* EyeBox1;
        CvRect* EyeBox2;
        CvRect* MouthBox;

    };


    class PoseEsti{

        public:
            PoseEsti();
            ~PoseEsti();


        public:
//            Face *FPtr;
            //create CvPoint structures to hold the located feature coordinates
            //centre points
            CvPoint2D32f 	Face;
            CvPoint2D32f	LeftEye;
            CvPoint2D32f	RightEye;
            CvPoint2D32f	Nose;
            CvPoint2D32f 	Mouth;

            CvPoint2D32f	NoseBase;
            CvPoint2D32f 	MidEyes;

            CvRect* FaceBox;
            CvRect* NoseBox;
            CvRect* EyeBox1;
            CvRect* EyeBox2;
            CvRect* MouthBox;



//            FaceGeom *GPtr;
            double LeftEye_Nose_distance;
            double RightEye_Nose_distance;
            double LeftEye_RightEye_distance;
            double Nose_Mouth_distance;

            double init_LeftEye_Nose_distance;
            double init_RightEye_Nose_distance;
            double init_LeftEye_RightEye_distance;
            double init_Nose_Mouth_distance;

            double init_Mean_Feature_distance;
            double Mean_Feature_distance;



//            Pose *PPtr;
            double pitch, yaw, roll;
            double slant;
            double zaxis, xaxis, yaxis;


            CvPoint rand_coord;

            float  R_m;
            float  R_n;
            float  R_e;
            double pi;
            float scale;

            CvMemStorage *storage;
            CvSeq *seq;

            CvPoint pointer_2d;
            CvPoint mouse;

            bool flag;

        //function
        public:
            //Function to return distance between 2 points in image
            float FindDistance(CvPoint pt1, CvPoint pt2);

            //Function to return distance between 2 points in image
            double FindDistance2D32f(CvPoint2D32f pt1, CvPoint2D32f pt2);

            //Function to return angle between 2 points in image
            float FindAngle(CvPoint2D32f pt1, CvPoint2D32f pt2);

            //Function to find slant angle in image 'Gee & Cipolla'
            double Find_slant(int ln, int lf, float Rn, float tita);

            void draw_trail(IplImage* img, CvPoint* pt);

            void draw_crosshair(IplImage* img, CvPoint centre, int circle_radius, int line_radius, CvScalar colour);

            void draw_pin(IplImage* img, CvPoint3D32f normal, float slant, float tita, CvScalar colour);

            void print_text(IplImage* img, int counter, CvScalar colour);

            void init_geometric_model();

            glm::mat4  poseEstimation(Mat_<double> detected_landmarks);

    };
}
