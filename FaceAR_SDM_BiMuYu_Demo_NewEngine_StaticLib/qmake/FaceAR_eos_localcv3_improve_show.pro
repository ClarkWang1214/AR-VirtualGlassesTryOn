TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += static

DEFINES += Linux

QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11

DESTDIR = ../../bin

INCLUDEPATH += \
    /usr/local/include/opencv2 \
    /usr/local/include/opencv \
    /usr/local/include \
    /usr/include/boost \
    /usr/include/tbb \
    /usr/include/eigen3

INCLUDEPATH += \
    ../src/ \
    ../src/FaceAR/ \
    ../src/Engine \
    ../src/objshow \
    ../src/FaceAR/include \
    ../src/FaceAR/src \
    ../src/OBJModel \
    ../src/GetGoodFrame \
    ../src/3rdParty/cereal-1.1.1/include \
    ../src/3rdParty/glm-0.9.7.0 \

INCLUDEPATH +=  \
                ../src/Engine/tengine/ \
                ../src/Engine/xsystem/ \
                ../src/3rdParty \
                ../src/3rdParty/glew \
                ../src/3rdParty/glm \

LIBS += \
        /home/clark/Documents/backup_code/[lib]/libFaceAR_Detect_0420.a \
        /home/clark/Documents/backup_code/[Completed]/PoseEstimation/FaceAR_PoseEstimation_StaticLib/bin/libFaceAR_PoseEstimation_StaticLib.a


LIBS += \
        /home/clark/Documents/backup_code/[Completed]/BiMuYu/FaceAR_SDM_BiMuYu_Demo_NewEngine_StaticLib/bin/libtengine.so

LIBS += \
            /usr/lib/libglfw.so.3 \
            -lGL -lGLU

LIBS += \
            -ltbb -lpthread \
            -lboost_filesystem -lboost_system -lboost_thread -lboost_program_options

LIBS += \
            /usr/local/lib/libopencv_calib3d.so.3.0.0 \
            /usr/local/lib/libopencv_objdetect.so.3.0.0 \
            /usr/local/lib/libopencv_core.so.3.0.0 \
            /usr/local/lib/libopencv_videoio.so.3.0.0 \
            /usr/local/lib/libopencv_video.so.3.0.0 \
            /usr/local/lib/libopencv_features2d.so.3.0.0 \
            /usr/local/lib/libopencv_highgui.so.3.0.0 \
            /usr/local/lib/libopencv_imgcodecs.so.3.0.0 \
            /usr/local/lib/libopencv_imgproc.so.3.0.0



## lib-opencv 2.4.11
#LIBS += \
#    -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc
##    -L/usr/local/lib -lopencv_calib3d -lopencv_contrib -lopencv_core \
##    -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui \
##    -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree \
##    -lopencv_objdetect -lopencv_ocl -lopencv_photo -lopencv_stitching \
##    -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab \
##    -lopencv_viz #-lpthread -lm -ldl
## CONFIG += link_pkgconfig
## PKGCONFIG += opencv

HEADERS += \
#    ../src/objshow/camera.h \
#    ../src/objshow/GlassMini.h \
#    ../src/objshow/GLConfig.h \
#    ../src/objshow/glew.h \
#    ../src/objshow/GlobalConfig.h \
#    ../src/objshow/glxew.h \
#    ../src/objshow/Singleton.h \
    ../src/PoseEstimation/PoseEstimation.h \
#    ../src/FaceAR/include/CCNF_patch_expert.h \
#    ../src/FaceAR/include/DetectionValidator.h \
#    ../src/FaceAR/include/Patch_experts.h \
#    ../src/FaceAR/include/PAW.h \
#    ../src/FaceAR/include/PDM.h \
#    ../src/FaceAR/include/stdafx.h \
#    ../src/FaceAR/include/SVR_patch_expert.h \
#    ../src/FaceAR/include/FaceAR.h \
#    ../src/FaceAR/include/FaceAR_core.h \
#    ../src/FaceAR/include/FaceAR_utils.h \
#    ../src/FaceAR/include/FaceARParameters.h \
#    ../src/FaceAR/include/FaceARTracker.h \
#    ../src/FaceAR/include/solvePnP.hpp \
#    ../src/FaceAR/include/LandmarksImproved.hpp \
#    ../src/eos/core/Landmark.h \
#    ../src/eos/core/LandmarkMapper.h \
#    ../src/eos/fitting/affine_camera_estimation.h \
#    ../src/eos/fitting/linear_shape_fitting.h \
#    ../src/eos/fitting/nonlinear_camera_estimation.h \
#    ../src/eos/fitting/detail/nonlinear_camera_estimation_detail.h \
#    ../src/eos/morphablemodel/MorphableModel.h \
#    ../src/eos/morphablemodel/PcaModel.h \
#    ../src/eos/morphablemodel/io/cvssp.h \
#    ../src/eos/morphablemodel/io/malGLUt_cerealisation.h \
#    ../src/eos/render/Mesh.h \
#    ../src/eos/render/render.h \
#    ../src/eos/render/render_affine.h \
#    ../src/eos/render/texture_extraction.h \
#    ../src/eos/render/utils.h \
#    ../src/eos/render/detail/render_affine_detail.h \
#    ../src/eos/render/detail/render_detail.h \
#    ../src/eos/render/detail/texture_extraction_detail.h \
#    ../src/GetGoodFrame/GetGoodFrame.h \
#    ../src/GetGoodFrame/polyfit.hpp \
#    ../src/GetGoodFrame/solve.h \
#    ../src/dlib/image_processing/frontal_face_detector.h \
#    ../src/dlib/opencv.h \
#    ../src/dlib/image_processing/frontal_face_detector_abstract.h \
#    ../src/dlib/image_processing/object_detector.h \
#    ../src/dlib/image_processing/scan_fhog_pyramid.h \
#    ../src/dlib/compress_stream.h \
#    ../src/dlib/base64.h \
#    ../src/dlib/opencv/cv_image.h \
#    ../src/dlib/opencv/cv_image_abstract.h \
#    ../src/dlib/opencv/to_open_cv.h \
#    ../src/dlib/opencv/to_open_cv_abstract.h \
#    ../src/rcr/adaptive_vlhog.hpp \
#    ../src/rcr/helpers.hpp \
#    ../src/rcr/hog.h \
#    ../src/rcr/landmark.hpp \
#    ../src/rcr/landmarks_io.hpp \
#    ../src/rcr/landmarks_stabilize.hpp \
#    ../src/rcr/model.hpp \
#    ../src/rcr/pre_frame_params.hpp \
#    ../src/rcr/pre_frame_prams.hpp \
#    ../src/superviseddescent/regressors.hpp \
#    ../src/superviseddescent/superviseddescent.hpp \
#    ../src/superviseddescent/verbose_solver.hpp \
#    ../src/superviseddescent/utils/mat_cerealisation.hpp \
#    ../src/superviseddescent/utils/mat_serialization.hpp \
#    ../src/superviseddescent/utils/ThreadPool.h \
    ../src/FaceAR/FaceAR_PoseEstimation.h \
    ../src/FaceAR/facear_detect.h

HEADERS += \
    ../src/Engine/tengine/Camera.h \
    ../src/Engine/tengine/EngineConfiguration.h \
    ../src/Engine/tengine/EngineEntry.h \
    ../src/Engine/tengine/Entity.h \
    ../src/Engine/tengine/EntityManager.h \
    ../src/Engine/tengine/GLConfig.h \
    ../src/Engine/tengine/GLHead.h \
    ../src/Engine/tengine/GlobalConfiguration.h \
    ../src/Engine/tengine/GLTexture.h \
    ../src/Engine/tengine/Material.h \
    ../src/Engine/tengine/MatrixConfig.h \
    ../src/Engine/tengine/Program.h \
    ../src/Engine/tengine/QueuePassConfig.h \
    ../src/Engine/tengine/RenderCommand.h \
    ../src/Engine/tengine/RenderObject.h \
    ../src/Engine/tengine/RenderPass.h \
    ../src/Engine/tengine/RenderSystem.h \
    ../src/Engine/tengine/ResourceSystem.h \
    ../src/Engine/tengine/Scene.h \
    ../src/Engine/tengine/SceneSystem.h \
    ../src/Engine/tengine/SkyboxCommand.h \
    ../src/Engine/tengine/SkyboxMaterial.h \
    ../src/Engine/tengine/Tezcat.h \
    ../src/Engine/tengine/Transform.h \
    ../src/Engine/tengine/Uniform.h \
    ../src/Engine/tengine/UniversalMaterial.h \
    ../src/Engine/xsystem/XComponent.h \
    ../src/Engine/xsystem/XComponentWapper.h \
    ../src/Engine/xsystem/XIDCreator.h \
    ../src/Engine/xsystem/XSingleton.h \
    ../src/Engine/tengine/CVHelper.h \
    ../src/Engine/tengine/ScreenCommand.h \
    ../src/Engine/tengine/GlassController.h


SOURCES += \
    ../src/run/SimpleFaceAR/FaceAR_main.cpp \
    ../src/Engine/tengine/CVHelper.cpp \
    ../src/Engine/tengine/GlassController.cpp

