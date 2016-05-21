#pragma once

#include "xsystem/XSingleton.h"
//#include "xsystem/XList.h"
#include <vector>

namespace tezcat
{
	class RenderQueue;
	class RenderObject;
	class RenderPass;
	class Camera;
	class RenderSystem : public XSingleton<RenderSystem>
	{
	public:
		RenderSystem();
		~RenderSystem();

		void render();

		void attachRenderObject(RenderObject *object);

		void attachRenderPass(RenderPass *pass);

		void initSystem();

	private:
		RenderQueue *m_Background;
		RenderQueue *m_Geometry;
		RenderQueue *m_Alpha;
		RenderQueue *m_Overlay;

		std::vector<Camera *> *m_NowCameraList;
	};
}