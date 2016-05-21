#pragma once

#include "Tezcat.h"
#include "xsystem/XComponent.h"
#include "Transform.h"
#include "Entity.h"


// OpenCV stuff   opencv2/
#include <core/core.hpp>
#include <objdetect.hpp>
#include <calib3d.hpp>
#include <imgcodecs.hpp>
#include <imgproc.hpp>
#include <highgui/highgui.hpp>
#include <videoio/videoio.hpp>  // Video write  opencv2/
#include <videoio/videoio_c.h>  // Video write  opencv2/
#include <viz/vizcore.hpp> ///*opencv2/*/


// C++ stuff
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>




using namespace std;
using namespace cv;
namespace tezcat{
    class GlassController : public XComponent<GlassController,XDynamicFlag> {
    public:
        GlassController(Entity *entity);
        ~GlassController();

        virtual void logic() override;


        void setPoseInfo(vector<int> imgIdxVec, vector<float> scaleVec, vector<CvPoint2D32f> midEyeVec, vector<glm::mat4> rotateMatrixVec);

    private:
        Transform *m_Transform;

        Entity *m_Entity;

        vector<int> imgIdxVec;
        vector<float> scaleVec;
        vector<CvPoint2D32f> midEyeVec;
        vector<glm::mat4> rotateMatrixVec;

        int count;



    };
}
