#include <iostream>
//#include "glew.h"
#include "GlassMini.h"
#include <GLFW/glfw3.h>

///
#define USE_CV

#ifdef USE_CV
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#endif // USE_CV

using namespace std;
using namespace tezcat;

bool keys[1024];
GLfloat lastX = 400, lastY = 300;
bool firstMouse = true;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;


void Do_Movement()
{
    float speed = 10;

    // Camera controls
    if (keys[GLFW_KEY_W])
        Singleton<GlassMini>::getInstance()->getCamera().ProcessKeyboard(FORWARD, deltaTime * speed);
    if (keys[GLFW_KEY_S])
        Singleton<GlassMini>::getInstance()->getCamera().ProcessKeyboard(BACKWARD, deltaTime * speed);
    if (keys[GLFW_KEY_A])
        Singleton<GlassMini>::getInstance()->getCamera().ProcessKeyboard(LEFT, deltaTime * speed);
    if (keys[GLFW_KEY_D])
        Singleton<GlassMini>::getInstance()->getCamera().ProcessKeyboard(RIGHT, deltaTime * speed);
    if (keys[GLFW_KEY_X])
        Singleton<GlassMini>::getInstance()->setRotationByOffset(0.01f, 0, 0);
    if (keys[GLFW_KEY_Y])
        Singleton<GlassMini>::getInstance()->setRotationByOffset(0, 0.01f, 0);
    if (keys[GLFW_KEY_Z])
        Singleton<GlassMini>::getInstance()->setRotationByOffset(0, 0, 0.01f);
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if (key == GLFW_KEY_1 && action == GLFW_PRESS)
        Singleton<GlassMini>::getInstance()->load("./2162t600.3DS");
    if (key == GLFW_KEY_2 && action == GLFW_PRESS)
        Singleton<GlassMini>::getInstance()->load("cube.obj");
    if (key == GLFW_KEY_3 && action == GLFW_PRESS)
        Singleton<GlassMini>::getInstance()->load("Sylvanas.obj");
    if (key == GLFW_KEY_4 && action == GLFW_PRESS)
        Singleton<GlassMini>::getInstance()->load("big.obj");
    if (key == GLFW_KEY_5 && action == GLFW_PRESS)
        Singleton<GlassMini>::getInstance()->load("333.3ds");
    if (action == GLFW_PRESS)
        keys[key] = true;
    else if (action == GLFW_RELEASE)
        keys[key] = false;
}

int main()
{
    Singleton<GlassMini>::init();
    Singleton<GlassMini>::getInstance()->init(960, 640);

    // Init GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    //	glfwWindowHint(GLFW_SAMPLES, 16);

    GLFWwindow* window = glfwCreateWindow(Singleton<GlassMini>::getInstance()->getScreenWidth(), Singleton<GlassMini>::getInstance()->getScreenHeight(), "Test", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // Set the required callback functions
    glfwSetKeyCallback(window, key_callback);

    // Options
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);



    // Initialize GLEW to setup the OpenGL Function pointers
    glewExperimental = GL_TRUE;
    //glewInit();
    if (glewInit() != GLEW_OK)
    {
        abort();
    }

    Singleton<GlassMini>::getInstance()->afterInit();
    // Define the viewport dimensions
    glViewport(0, 0, Singleton<GlassMini>::getInstance()->getScreenWidth(), Singleton<GlassMini>::getInstance()->getScreenHeight());
    //glViewport(0, 0, 800, 600);

    //	glClearColor(0.5, 0.5, 0.5, 1.0f);
#ifdef USE_CV
    cv::Mat m_CVImage;
    cv::VideoCapture m_VideoCapture(0);
#endif // USE_CV
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    while (!glfwWindowShouldClose(window))
    {
        // Set frame time
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glfwPollEvents();
        Do_Movement();

#ifdef USE_CV
        m_VideoCapture   >> m_CVImage;
//        cv::imshow("1", m_CVImage);
//        cv::waitKey(10);
        cv::resize(m_CVImage, m_CVImage, cv::Size(960, 640), 0, 0, CV_INTER_LINEAR);
        cv::cvtColor(m_CVImage, m_CVImage, CV_BGR2RGBA);
        cv::flip(m_CVImage, m_CVImage, 0);

        Singleton<GlassMini>::getInstance()->Render(deltaTime, m_CVImage.cols, m_CVImage.rows , 0, 0, m_CVImage.data);
//        Singleton<GlassMini>::getInstance()->Render(deltaTime, 640 ,  960, 0, 0, m_CVImage.data);
#else
        Singleton<GlassMini>::getInstance()->Render(deltaTime);
#endif // USE_CV
        // Swap the buffers
        glfwSwapBuffers(window);
    }


    glfwTerminate();
}
