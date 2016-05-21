/////////////////////////////////////////////////////////////////////////////////

#define USE_CV
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
#include <functional>


#include "tengine/Tezcat.h"
#include "CVHelper.h"
#include "GLFW/glfw3.h"


#include "facear_detect.h"
#include "FaceAR_PoseEstimation.h"


#define PI (22/7.0)

#define USE_CV

using namespace std;
using namespace cv;
using namespace tezcat;
using namespace clarkPoseEsti;


extern tezcat::Camera *MainCamera = nullptr;
bool keys[1024];
bool firstMouse = true;

double lastX = 0;
double lastY = 0;
int CURSOR = GLFW_CURSOR_DISABLED;

//extern auto camera;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if (action == GLFW_PRESS)
        keys[key] = true;
    else if (action == GLFW_RELEASE)
        keys[key] = false;

    if (keys[GLFW_KEY_SPACE])
    {
        if (CURSOR == GLFW_CURSOR_NORMAL)
        {
            CURSOR = GLFW_CURSOR_DISABLED;
        }
        else
        {
            CURSOR = GLFW_CURSOR_NORMAL;
        }
        glfwSetInputMode(window, GLFW_CURSOR, CURSOR);
    }
}

void Do_Movement()
{
    float speed = 10;

    if (keys[GLFW_KEY_W])
        MainCamera->forward(tezcat::GlobalConfiguration::DeltaTime);
    if (keys[GLFW_KEY_S])
        MainCamera->back(tezcat::GlobalConfiguration::DeltaTime);
    if (keys[GLFW_KEY_A])
        MainCamera->left(tezcat::GlobalConfiguration::DeltaTime);
    if (keys[GLFW_KEY_D])
        MainCamera->right(tezcat::GlobalConfiguration::DeltaTime);

}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    GLfloat xoffset = static_cast<float>(xpos - lastX);
    GLfloat yoffset = static_cast<float>(lastY - ypos);

    lastX = xpos;
    lastY = ypos;

    MainCamera->onMouse(xoffset, yoffset);
}



int main (int argc, char **argv)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_SAMPLES, 8);


    tezcat::GlobalConfiguration::ScreenWidth=640;
    tezcat::GlobalConfiguration::ScreenHegiht=480;
    tezcat::GlobalConfiguration::WindowName="FaceAR_Engine_Final";
    cout<<tezcat::GlobalConfiguration::ScreenWidth<<"  "<<tezcat::GlobalConfiguration::ScreenHegiht<<endl;
    GLFWwindow* window = glfwCreateWindow(tezcat::GlobalConfiguration::ScreenWidth, tezcat::GlobalConfiguration::ScreenHegiht, tezcat::GlobalConfiguration::WindowName.c_str(), nullptr, nullptr); // Windowed
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);
//    glfwSetCursorPosCallback(window, mouse_callback);
    glViewport(0, 0, tezcat::GlobalConfiguration::ScreenWidth, tezcat::GlobalConfiguration::ScreenHegiht);


    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }


    tezcat::EngineEntry engineEntry;
    engineEntry.init("");

    glViewport(0, 0, tezcat::GlobalConfiguration::ScreenWidth, tezcat::GlobalConfiguration::ScreenHegiht);


    tezcat::CVHelper* cvHelper = new tezcat::CVHelper();
    cvHelper->openCamera();


    tezcat::SceneSystem::getInstance()->pushScene(
        "myScene",
        [&](tezcat::Scene *scene)
    {

//		//创建天空盒
//		tezcat::UniversalMaterial *skybox_material = tezcat::ResourceSystem::getInstance()->createUniversalMaterialFromPackage("skybox.skybox");

//		auto skybox_shader = tezcat::ResourceSystem::getInstance()->createProgramFromPackage("skybox");
//		auto *skybox_pass = new tezcat::SkyboxPass();
//		skybox_pass->setProgram(skybox_shader);
//		skybox_pass->setPassID(skybox_material->getPassID());

//		tezcat::RenderSystem::getInstance()->attachRenderPass(skybox_pass);

//		auto skybox = tezcat::ResourceSystem::getInstance()->createSkyBox();
//		skybox->setName("skybox");
//		auto skybox_render = skybox->getRenderObject();
//		skybox_render->setMaterial(skybox_material);
////		skybox_render->setVisible(false);
//		scene->addChild(skybox);

        auto cvvideo_shader = tezcat::ResourceSystem::getInstance()->createProgramFromPackage("cvvideo");
        auto *cvvideo_pass = new tezcat::ScreenPass();
        cvvideo_pass->setProgram(cvvideo_shader);
        cvvideo_pass->setPassID(0);
        tezcat::RenderSystem::getInstance()->attachRenderPass(cvvideo_pass);
        scene->addChild(cvHelper->createCVVideo());


        //
        //
        auto pbr_shader = tezcat::ResourceSystem::getInstance()->createProgramFromPackage("MyPBR");
        auto *mesh_pass = new tezcat::PBRPass();
        mesh_pass->setProgram(pbr_shader);
        mesh_pass->setPassID(0);
        tezcat::RenderSystem::getInstance()->attachRenderPass(mesh_pass);

        auto glass_shader = tezcat::ResourceSystem::getInstance()->createProgramFromPackage("Glass");
        auto *glass_pass = new tezcat::GlassPass();
        glass_pass->setBelong2Queue(tezcat::RenderQueueType::Queue_Alpha);
        glass_pass->setProgram(glass_shader);
        glass_pass->setPassID(1);
        tezcat::RenderSystem::getInstance()->attachRenderPass(glass_pass);

        auto model = tezcat::ResourceSystem::getInstance()->createModelFromPackage("Glasses2");
        tezcat::GlassController *controller = new tezcat::GlassController(model);
        model->attachDynamic(controller);
        model->getRenderObject()->getTransform()->setRotationX(-90);
        model->getRenderObject()->setVisible(false);
        scene->addChild(model);

        auto camera = tezcat::ResourceSystem::getInstance()->createCamera("MainCamera");
        MainCamera = camera->getRenderObject()->getCamera();
        MainCamera->getPosition().z = 200;
        MainCamera->setSpeed(30);
        scene->addChild(camera);
    },
        nullptr,
        nullptr,
        nullptr);

    double lastFrame = 0;
    double currentFrame = 0;

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        Do_Movement();

        currentFrame = glfwGetTime();
        tezcat::GlobalConfiguration::DeltaTime = static_cast<float>(currentFrame - lastFrame);
        lastFrame = currentFrame;

        cvHelper->getImage();

        engineEntry.logic();
        engineEntry.render();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}


