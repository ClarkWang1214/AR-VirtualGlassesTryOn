#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"


#include "glew.h"

#include <vector>
#include <string>

namespace tezcat
{
    const std::string SL_Tex_Color = "myTexColor";					//颜色贴图
    const std::string SL_Tex_Diffuse = "myTexDiffuse";				//漫反射贴图贴图
    const std::string SL_Tex_Specular = "myTexSpecular";			//高光贴图
    const std::string SL_Tex_Environment = "myTexEnvironment";		//环境贴图
    const std::string SL_Tex_Normal = "myTexNormal";				//法线贴图
    const std::string SL_Mat4_M = "myMat4M";						//模型矩阵
    const std::string SL_Mat4_V = "myMat4V";						//视图矩阵
    const std::string SL_Mat4_P = "myMat4P";						//投以矩阵
    const std::string SL_Mat4_MV = "myMat4MV";						//模型视图矩阵
    const std::string SL_Mat4_MVP = "myMat4MVP";					//模型视图投影矩阵
    const std::string SL_Mat3_Normal = "myMat3Normal";				//模型法线正规化矩阵
    const std::string SL_Vec3_VPosition = "myVec3VPosition";		//相机位置

    const std::string SL_DLight_Ambient = "myDLight.ambient";		//区域光环境光
    const std::string SL_DLight_Diffuse = "myDLight.diffuse";		//区域光满反色
    const std::string SL_DLight_Specular = "myDLight.specular";		//区域光高光
    const std::string SL_DLight_Direction = "myDLight.direction";	//区域光方向

    static const size_t ComponentCount = 32;

    enum class AttributeID : unsigned int
    {
        Position,	 //0
        Normal,		 //1
        UV,			 //2
        Color,		 //3
    };

#define GLAttributeID(ID) static_cast<unsigned int>(ID)
// #ifndef GLSL
// #define GLSL(version, A) "#version " #version "\n" #A
// #endif

    struct Vertex_PNU2TC
    {
        glm::vec3 position;				//顶点
        glm::vec3 normal;				//法线
        glm::vec2 uv;					//贴图UV
        glm::vec3 tangent;				//切线
        glm::vec3 bitTangent;			//副切线
        glm::vec4 color;				//颜色
    };

    typedef std::vector<Vertex_PNU2TC> Vertex_PCNUType;

    struct Vertex_PNU
    {
        glm::vec3 position;				//顶点
        glm::vec3 normal;				//法线
        glm::vec2 uv;					//贴图UV
    };
    typedef std::vector<Vertex_PNU> Vertex_PNUType;


    typedef std::vector<unsigned int> Index_uintType;
    typedef unsigned int Index_uint;


    struct Data
    {
        Vertex_PCNUType Vertices;
        Index_uintType Indices;
    };

    class GLBuffers
    {
    public:

        static void bindVAO_PNUC()
        {
            glEnableVertexAttribArray(GLAttributeID(AttributeID::Position));
            glVertexAttribPointer(GLAttributeID(AttributeID::Position), 3, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNU2TC), (void *)offsetof(Vertex_PNU2TC, position));

            glEnableVertexAttribArray(GLAttributeID(AttributeID::Normal));
            glVertexAttribPointer(GLAttributeID(AttributeID::Normal), 3, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNU2TC), (void *)offsetof(Vertex_PNU2TC, normal));

            glEnableVertexAttribArray(GLAttributeID(AttributeID::UV));
            glVertexAttribPointer(GLAttributeID(AttributeID::UV), 2, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNU2TC), (void *)offsetof(Vertex_PNU2TC, uv));

            glEnableVertexAttribArray(GLAttributeID(AttributeID::Color));
            glVertexAttribPointer(GLAttributeID(AttributeID::Color), 4, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNU2TC), (void *)offsetof(Vertex_PNU2TC, color));
        }


        static void bindVAO_PNU()
        {
            glEnableVertexAttribArray(GLAttributeID(AttributeID::Position));
            glVertexAttribPointer(GLAttributeID(AttributeID::Position), 3, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNU2TC), (void *)offsetof(Vertex_PNU2TC, position));

            glEnableVertexAttribArray(GLAttributeID(AttributeID::Normal));
            glVertexAttribPointer(GLAttributeID(AttributeID::Normal), 3, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNU2TC), (void *)offsetof(Vertex_PNU2TC, normal));

            glEnableVertexAttribArray(GLAttributeID(AttributeID::UV));
            glVertexAttribPointer(GLAttributeID(AttributeID::UV), 2, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNU2TC), (void *)offsetof(Vertex_PNU2TC, uv));
        }
    };


    class GLConfig
    {
    public:
        enum Masks : unsigned short
        {
            Disabled = 0,
            Layer1 = 1,
            Layer2 = 1 << 1,
            Layer3 = 1 << 2,
            Layer4 = 1 << 3,
            Layer5 = 1 << 4,
            Layer6 = 1 << 5,
            Layer7 = 1 << 6,
            Layer8 = 1 << 7,
            Layer9 = 1 << 8,
            Layer10 = 1 << 9,
            Layer11 = 1 << 10,
            Layer12 = 1 << 11,
            Layer13 = 1 << 12,
            Layer14 = 1 << 13,
            Layer15 = 1 << 14,
            Layer16 = 1 << 15,
        };

    public:
        static int getGLVersion()
        {
            if (m_GLVersion == 0)
            {
                int majorVersion;
                int minorVersion;

                glGetIntegerv(GL_MAJOR_VERSION, &majorVersion);
                glGetIntegerv(GL_MINOR_VERSION, &minorVersion);

                m_GLVersion = majorVersion * 100 + minorVersion * 10;
            }

            return m_GLVersion;
        }


    private:
        static int m_GLVersion;
    };
}
