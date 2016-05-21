#pragma once

#include "RenderCommand.h"
#include "SkyboxMaterial.h"

namespace tezcat
{
	class SkyboxCommand : public RenderCommand
	{
	public:
		SkyboxCommand();
		~SkyboxCommand();

		virtual void sendData2GL(VertexData *data) override;

		virtual void render() override;

	private:
		GLuint m_VAOID;
		GLuint m_VBOID;
		size_t m_VertexSize;
	};
}