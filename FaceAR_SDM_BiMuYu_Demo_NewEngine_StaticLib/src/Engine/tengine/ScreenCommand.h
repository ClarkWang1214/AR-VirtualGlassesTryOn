#pragma once

#include "RenderCommand.h"

namespace tezcat
{
	class ScreenCommand : public RenderCommand
	{
	public:
		ScreenCommand();
		~ScreenCommand();

		virtual void sendData2GL(VertexData *mesh = nullptr) override;
		virtual void render() override;

	private:
		GLuint m_VAOID;
		GLuint m_VBOID;
	};
}
