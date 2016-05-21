#pragma once

#include "RenderObject.h"
#include "QueuePassConfig.h"
#include <vector>

namespace tezcat
{
	class Program;
	class Camera;
	class RenderPass
	{
	public:
		RenderPass();
		virtual ~RenderPass();

		virtual void render(Camera *camera) {}

		void setProgram(Program *program);

		void setEnabled(bool enabled) { m_Enabled = enabled; }
		const bool &getEnabled() const { return m_Enabled; }

		void setMustBeClear(bool clear) { m_MustBeClear = clear; }
		const bool &getMustBeClear() const { return m_MustBeClear; }

		void attachRenderObject(RenderObject *object)
		{
			m_Renderables.push_back(object);
		}

		const RenderQueueType &getBelong2Queue() const { return m_Belong2Queue; }
		void setBelong2Queue(RenderQueueType val) { m_Belong2Queue = val; }

		const int &getPassID() const { return m_ID; }
		void setPassID(const int &val) { m_ID = val; }

		void clear() { m_Renderables.clear(); }

	protected:
		int m_ID;
		bool m_Enabled;
		bool m_MustBeClear;
		std::vector<RenderObject *> m_Renderables;
		Program *m_Program;
		RenderQueueType m_Belong2Queue;
	};

	class ScreenPass : public RenderPass
	{
	public:
		ScreenPass();

		virtual void render(Camera *camera);

	private:

	};

	class SkyboxPass : public RenderPass
	{
	public:
		SkyboxPass();
		virtual void render(Camera *camera);
	};

	class MeshPass : public RenderPass
	{
	public:
		virtual void render(Camera *camera);
	};


	class PBRPass : public RenderPass
	{
	public:
		PBRPass();
		virtual void render(Camera *camera);
	};

	class GlassPass : public RenderPass
	{
	public:
		GlassPass();
		virtual void render(Camera *camera);
	};
}