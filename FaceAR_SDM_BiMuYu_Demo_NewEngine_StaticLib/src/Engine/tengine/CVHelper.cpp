#include "CVHelper.h"
//#include "solvePnP.hpp"
//#include "LandmarksImproved.hpp"

glm::mat4 rotateMatrixGlobal;
glm::mat4 rotateMatrixGlobal_Prev;

namespace tezcat
{
    CVHelper::CVHelper()
    {
        flag = 1;
    }

    CVHelper::~CVHelper()
    {

    }

    void CVHelper::openCamera()
    {
        fd.init(m_Capture, 0);
//        m_Capture = cv::VideoCapture(0);
//        if (!m_Capture.isOpened())
//        {
//            abort();
//        }
    }

    void CVHelper::setBackground(cv::Mat _Image){
        m_Image = _Image.clone();
        cv::cvtColor(m_Image, m_Image, CV_BGR2RGBA);
        cv::flip(m_Image, m_Image, 0);
        cv::resize(m_Image, m_Image, cv::Size(GlobalConfiguration::ScreenWidth, GlobalConfiguration::ScreenHegiht));
        m_CVVideo->getRenderObject()->getMaterial<UniversalMaterial>()->updataTexture2D("cvvideo", m_Image.cols, m_Image.rows, 0, 0, m_Image.data);
    }

    void CVHelper::getImage()
    {
        m_Capture >> m_Image;



        if(!m_Image.empty())
        {
            //int isD=dectectFace(img,rect);
            //if(isD!=0)
            //{
            //    draw_Face(img,rect);
            //}
            //imshow("v",img);
            flip(m_Image, m_Image, 1);
            vector<cv::Point> landmarks=fd.dectectLandmark(m_Image);

            for(int i=0;i<landmarks.size();++i){
                cout<<landmarks[i]<<endl;
            }


            fd.draw_landmark(m_Image,landmarks);

            imshow("v",m_Image);
            waitKey(1);


            cout<<"TODO : poseEstimation"<<endl;
            glm::mat4 rotateMatrix = fp.getRT(landmarks, m_Image);
            rotateMatrixGlobal = rotateMatrix;

            if(flag == 1){
                rotateMatrixGlobal_Prev = rotateMatrix;
            }


            cout<<"rotateMatrix"<<endl<<
                                    rotateMatrix[0][0]<<" "<<rotateMatrix[0][1]<<" "<<rotateMatrix[0][2]<<" "<<rotateMatrix[0][3]<<endl<<
                                    rotateMatrix[1][0]<<" "<<rotateMatrix[1][1]<<" "<<rotateMatrix[1][2]<<" "<<rotateMatrix[1][3]<<endl<<
                                    rotateMatrix[2][0]<<" "<<rotateMatrix[2][1]<<" "<<rotateMatrix[2][2]<<" "<<rotateMatrix[2][3]<<endl<<
                                    rotateMatrix[3][0]<<" "<<rotateMatrix[3][1]<<" "<<rotateMatrix[3][2]<<" "<<rotateMatrix[3][3]<<endl;

            cv::cvtColor(m_Image, m_Image, CV_BGR2RGBA);
            cv::flip(m_Image, m_Image, 0);
//            cv::resize(m_Image, m_Image, cv::Size(GlobalConfiguration::ScreenWidth, GlobalConfiguration::ScreenHegiht));
            m_CVVideo->getRenderObject()->getMaterial<UniversalMaterial>()->updataTexture2D("cvvideo", m_Image.cols, m_Image.rows, 0, 0, m_Image.data);


        }
    }


    Entity * CVHelper::createCVVideo()
    {
        m_CVVideo = EntityManager::getInstance()->create();

        ScreenCommand *cmd = new ScreenCommand();
        cmd->setQueueType(RenderQueueType::Queue_Background);
        cmd->sendData2GL();

        UniversalMaterial *um = new UniversalMaterial();
        um->genTexture2DBuffer("cvvideo", GlobalConfiguration::ScreenWidth, GlobalConfiguration::ScreenHegiht);
        um->setPassID(0);

        RenderObject *screen_object = new RenderObject();
        screen_object->setObjectType(RenderObject::ObjectType::Type_Mesh);
        screen_object->setRenderCommand(cmd);
        screen_object->setTransform(Transform::create());
        screen_object->setMaterial(um);
        m_CVVideo->setRenderObject(screen_object);

        return m_CVVideo;
    }

}

