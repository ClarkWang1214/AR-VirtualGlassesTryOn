#include "GlassController.h"

extern glm::mat4 rotateMatrixGlobal;
extern glm::mat4 rotateMatrixGlobal_Prev;

extern tezcat::Camera *MainCamera;
namespace tezcat {
GlassController::GlassController(Entity *entity)
{
    count = 0;
    m_Entity = entity;
    m_Transform = m_Entity->getRenderObject()->getTransform();
}

GlassController::~GlassController()
{

}

void GlassController::setPoseInfo(vector<int> _imgIdxVec, vector<float> _scaleVec,
                                  vector<CvPoint2D32f> _midEyeVec, vector<glm::mat4> _rotateMatrixVec){
    imgIdxVec.assign(_imgIdxVec.begin(), _imgIdxVec.end());
    scaleVec.assign(_scaleVec.begin(), _scaleVec.end());
    midEyeVec.assign(_midEyeVec.begin(), _midEyeVec.end());
    rotateMatrixVec.assign(_rotateMatrixVec.begin(), _rotateMatrixVec.end());
}


std::function<void(tezcat::Entity *, bool)> setVisible = [&](tezcat::Entity *entity, bool visible){
    entity->getRenderObject()->setVisible(visible);
    for(auto child:entity->getChildren()){
        setVisible(child, visible);
    }
};

void GlassController::logic()
{
    //        setVisible(m_Entity, true);
    count ++;
//    cout<<"count: "<<count<<endl;


    //        glm::mat4 rotateMatrixTMP = rotateMatrixVec[count];
    //        cout<<"rotateMatrixVec size "<<rotateMatrixVec.size()<<endl;
    float scaleTMP = 1.1 * rotateMatrixGlobal[2][3];
    CvPoint2D32f midEyeTMP;//////////////////////TODO
    midEyeTMP.x = rotateMatrixGlobal[0][3];
    midEyeTMP.y = rotateMatrixGlobal[1][3];

    // rotateMatrix[1][0]: -0.5 ~ 0.5
    double dd=0;

    if(rotateMatrixGlobal[1][0]!=0)
        dd = 30*rotateMatrixGlobal[1][0];


    //        m_Transform->setMatrix(glm::transpose(rotateMatrixTMP));
    m_Transform->setMatrix(rotateMatrixGlobal[0][0], -rotateMatrixGlobal[0][1], -rotateMatrixGlobal[0][2],
            -rotateMatrixGlobal[1][0], rotateMatrixGlobal[1][1], -rotateMatrixGlobal[1][2],
            -rotateMatrixGlobal[2][0], -rotateMatrixGlobal[2][1], rotateMatrixGlobal[2][2],
            rotateMatrixGlobal[3][0], rotateMatrixGlobal[3][1], rotateMatrixGlobal[3][2] );

    //        m_Transform->setMatrix(glm::transpose(rotateMatrixTMP));
//    m_Transform->setMatrix( rotateMatrixGlobal[0][0], rotateMatrixGlobal[0][1], rotateMatrixGlobal[0][2],
//                            rotateMatrixGlobal[1][0], rotateMatrixGlobal[1][1], rotateMatrixGlobal[1][2],
//                            rotateMatrixGlobal[2][0], rotateMatrixGlobal[2][1], rotateMatrixGlobal[2][2],
//                            rotateMatrixGlobal[3][0], rotateMatrixGlobal[3][1], rotateMatrixGlobal[3][2] );


//    double dd2 = 0;
//    if(rotateMatrixGlobal[1][0]!=0)
//        dd2 = 30*rotateMatrixGlobal[1][0];

//    cout<<"                 -(midEyeTMP.x - 320)/320.0f * 30: "<<-(midEyeTMP.x - 320)/320.0f * 30<<endl;
//    cout<<"                 30*rotateMatrixGlobal[1][0]: "<<30*rotateMatrixGlobal[1][0]<<endl;
//    m_Transform->setRotationByOffset(0,  0,  dd2);
    m_Transform->setRotationByOffset(0,  0,  -(midEyeTMP.x - 320)/320.0f * 30);

    m_Transform->setPositionX(midEyeTMP.x - 320  + dd); // right(large) left(small)
    m_Transform->setPositionY(230 - midEyeTMP.y);  // up(large) down(small)
    m_Transform->setPositionZ(-200); // far(large) near(small)

//    MainCamera->getPosition().x = midEyeTMP.x - 320  + dd;
//    MainCamera->getPosition().y = 230 - midEyeTMP.y;

//    m_Transform->setPositionX(midEyeTMP.x - 320  + dd); // right(large) left(small)
//    m_Transform->setPositionY(230 - midEyeTMP.y);  // up(large) down(small)




//    m_Transform->setPositionX(-100); // right(large) left(small)
//    m_Transform->setPositionY(-50);  // up(large) down(small)
//    m_Transform->setPositionZ(-100); // far(large) near(small)


    // TODO:  update the offsets...


    m_Transform->setScale(scaleTMP, scaleTMP, scaleTMP);

    m_Transform->setRotationByOffset(-90.0f,  0, 0);
//    m_Transform->setRotationByOffset(0,  0, 40);


    cv::waitKey(33);

}
}

