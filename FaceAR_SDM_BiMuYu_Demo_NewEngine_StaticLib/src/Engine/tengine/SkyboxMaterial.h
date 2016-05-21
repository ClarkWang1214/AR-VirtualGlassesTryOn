#pragma once

#include "Material.h"

namespace tezcat
{
	
	class SkyboxMaterial : public Material
	{
	public:
		SkyboxMaterial();

		virtual void uploadUniform(Program *program) override;
		virtual void unbindUniform();

		void setImage(
			const std::string &positive_x, const std::string &negative_x,
			const std::string &positive_y, const std::string &negative_y,
			const std::string &positive_z, const std::string &negative_z);

	private:
		GLTextureCube *m_CubeMap;
		int m_Location;
	};
}