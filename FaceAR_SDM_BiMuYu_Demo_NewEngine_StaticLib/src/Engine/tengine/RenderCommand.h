#pragma once

#include "GLConfig.h"
#include "QueuePassConfig.h"

namespace tezcat
{
	class Program;
	class Camera;
	class RenderCommand
	{
	public:
		RenderCommand();
		virtual ~RenderCommand();

		virtual void render() = 0;
		virtual void sendData2GL(VertexData *data = nullptr) = 0;

		const RenderQueueType &getQueueType() const { return m_QueueType; }
		void setQueueType(RenderQueueType val) { m_QueueType = val; }

	protected:
		RenderQueueType m_QueueType;
	};
}