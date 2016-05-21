#ifndef FACEAR_POSEESTIMATION_H
#define FACEAR_POSEESTIMATION_H

#include<vector>
#include"opencv2/opencv.hpp"

// glm
#include <glm/glm.hpp>

using namespace cv;
using namespace std;

class FaceAR_PoseEstimation
{

public:
    FaceAR_PoseEstimation();
    glm::mat4 getRT(vector<cv::Point> detected_landmarks, Mat &img);

};








#endif // FACEAR_POSEESTIMATION_H
