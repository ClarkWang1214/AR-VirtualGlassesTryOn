#pragma once

#include "Tezcat.h"
#include "opencv2/opencv.hpp"

#include "PoseEstimation/PoseEstimation.h"

////////SDM Header Files/////////
//#include "superviseddescent/superviseddescent.hpp"
//#include "superviseddescent/regressors.hpp"

//#include "rcr/landmarks_io.hpp"
//#include "rcr/model.hpp"
//#include "rcr/pre_frame_params.hpp"
//#include "rcr/landmarks_stabilize.hpp"

#include "cereal/cereal.hpp"

#include "boost/program_options.hpp"
#include "boost/filesystem.hpp"

////////SDM Header Files/////////

#include "facear_detect.h"
#include "FaceAR_PoseEstimation.h"

namespace tezcat
{
	class CVHelper
	{
	public:
		CVHelper();
		~CVHelper();

		void openCamera();

        void setBackground(cv::Mat _Image);
		void getImage();

		Entity *createCVVideo();

	private:
		tezcat::Entity *m_CVVideo;

		cv::Mat m_Image;
		cv::VideoCapture m_Capture;

        FaceAR_Detect fd;
        FaceAR_PoseEstimation fp;

        int flag;

	};
}
