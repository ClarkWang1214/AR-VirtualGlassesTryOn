#pragma once

#include "glew.h"

//#include "opencv.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>




#include "camera.h"

#include "Singleton.h"
#include "GLConfig.h"
#include <functional>


namespace tezcat
{

class Mesh;
class Shader;
class GLRender2Textrue;

class GlassMini : public Singleton<GlassMini>
{
public:
    GlassMini();
    ~GlassMini();

    void *operator new (size_t size)
    {
        return new std::aligned_storage<sizeof(GlassMini), std::alignment_of<GlassMini>::value>::type();
    }

    //
    void init3D(int screen_width, int screen_height);
    //after the glewinit
    void afterInit();

    //load Model
    void load(std::string file);

    unsigned int getScreenWidth() { return m_ScreenWidth; }
    unsigned int getScreenHeight() { return m_ScreenHeigh; }

    void setScreenWidth(unsigned int width) { m_ScreenWidth = width; }
    void setScreenHeight(unsigned int height) { m_ScreenHeigh = height; }

    //=====================================================================
    //
    //      Camera
    //
public:
    //aspect
    void setProjection();
    void setNear(float near)
    {
        m_Near = near;
    }
    void setFar(float fat)
    {
        m_Far = fat;
    }
    void setFOV(float fov)
    {
        m_FOV = fov;
    }
    void setScreenWH(unsigned int width, unsigned int height)
    {
        m_ScreenWidth = width;
        m_ScreenHeigh = height;
        m_Aspect = float(m_ScreenWidth) / float(m_ScreenHeigh);
    }

public:
    void setCVMatrix(
            float row11, float row12, float row13, float row14,
            float row21, float row22, float row23, float row24,
            float row31, float row32, float row33, float row34);
    void setCVMatrix(const glm::mat4 &mat)
    {
        this->setCVMatrix(
                    mat[0][0], mat[0][1], mat[0][2],
                mat[1][0], mat[1][1], mat[1][2],
                mat[2][0], mat[2][1], mat[2][2],
                mat[3][0], mat[3][1], mat[3][2] );
    }

public:
    //========================================================================
    void setRotationX(const float &value);
    void setRotationY(const float &value);
    void setRotationZ(const float &value);
    void setRotation(const float &x, const float &y, const float &z);
    void setRotationByOffset(const float &x, const float &y, const float &z);
    float getRotationX();
    float getRotationY();
    float getRotationZ();

    //=========================================================================
    void setScaleX(const float &value);
    void setScaleY(const float &value);
    void setScaleZ(const float &value);
    void setScale(const float &x, const float &y, const float &z);
    void setScale(const float &value)
    {
        setScale(value, value, value);
    }
    void setScaleByOffset(const float &x, const float &y, const float &z);
    void setScaleByOffset(const float &value)
    {
        setScaleByOffset(value, value, value);
    }
    float getScaleX();
    float getScaleY();
    float getScaleZ();
    //=========================================================================
    void setPositionX(const float &value);
    void setPositionY(const float &value);
    void setPositionZ(const float &value);
    void setPosition(const float &x, const float &y, const float &z);
    void setPositionByOffset(const float &x, const float &y, const float &z);
    float getPositionX();
    float getPositionY();
    float getPositionZ();

public:
    void Render(float dt, const unsigned int &width, const unsigned int &height, const unsigned int &xoffset, const unsigned int &yoffset, unsigned char *data);

    void setOnCallBack(const std::function<void(glm::vec3 &, glm::vec3 &, glm::vec3 &, glm::mat4 &)> &function);

    Camera &getCamera() { return m_Camera; }
private:

    Camera m_Camera;
    Shader *m_Shader;

    GLuint m_ScreenWidth, m_ScreenHeigh;
    float m_Aspect;
    float m_Near;
    float m_Far;
    float m_FOV;

    Mesh* m_RootMesh;
    glm::mat4 m_TheWorld;
    glm::mat4 m_Projection;

    glm::mat4 IdentifyMat4;
    glm::quat IdentifyQuat;
    glm::vec3 AxisX;
    glm::vec3 AxisY;
    glm::vec3 AxisZ;

    GLRender2Textrue *m_R2T;
    //	GLTexture2D *m_ModelTexture;
    Shader *m_SR2T;

    //	cv::Mat m_CVImage;
    //	cv::VideoCapture m_VideoCapture;
};
}
