#pragma once


#include "Material.h"
#include "Uniform.h"

namespace tezcat
{
	class UniversalMaterial : public Material
	{
	public:
		UniversalMaterial(const unsigned int &pass_id,
			const int &queue_id,
			const std::string &name,
			const std::string &shader_name);
		UniversalMaterial();
		~UniversalMaterial();

		template<class UniformValue>
		typename std::enable_if<std::is_base_of<UniformBaseValue, UniformValue>::value, UniformValue>::type *getUniformValue(const std::string &name)
		{
			return static_cast<UniformValue *>(m_Proerty[name]);
		}

		virtual void uploadUniform(Program *program) override;

		UniversalMaterial *copy();

		UniformBaseProperty &getUniforms() { return m_Proerty; }

	public:
		void setInt1Fast(const std::string &name, const int &value);
		void setUInt1Fast(const std::string &name, const unsigned int &value);
		void setFloat1Fast(const std::string &name, const float &value);
		void setBool1Fast(const std::string &name, const bool &value);

		void setInt1(const std::string &name, const int &value);
		void setUInt1(const std::string &name, const unsigned int &value);
		void setFloat1(const std::string &name, const float &value);
		void setBool1(const std::string &name, const bool &value);

		void cacheBool1(const std::string &name, const bool &value, const int &location);
		void cacheInt1(const std::string &name, const int &value, const int &location);
		void cacheFloat1(const std::string &name, const float &value, const int &location);
		void cacheUInt1(const std::string &name, const unsigned int &value, const int &location);

		void cacheBool1(const std::string &name, const int &location);
		void cacheInt1(const std::string &name, const int &location);
		void cacheFloat1(const std::string &name, const int &location);
		void cacheUInt1(const std::string &name, const int &location);

	public:
		void setInt2Fast(const std::string &name, const int &value1, const int &value2);
		void setUInt2Fast(const std::string &name, const unsigned int &value1, const unsigned int &value2);
		void setFloat2Fast(const std::string &name, const float &value1, const float &value2);
		void setBool2Fast(const std::string &name, const bool &value1, const bool &value2);

		void setInt2(const std::string &name, const int &value1, const int &value2);
		void setUInt2(const std::string &name, const unsigned int &value1, const unsigned int &value2);
		void setFloat2(const std::string &name, const float &value1, const float &value2);
		void setBool2(const std::string &name, const bool &value1, const bool &value2);

		void cacheInt2(const std::string &name, const int &value1, const int &value2, const int &location);
		void cacheUInt2(const std::string &name, const unsigned int &value1, const unsigned int &value2, const int &location);
		void cacheFloat2(const std::string &name, const float &value1, const float &value2, const int &location);
		void cacheBool2(const std::string &name, const bool &value1, const bool &value2, const int &location);

		void cacheBool2(const std::string &name, const int &location);
		void cacheInt2(const std::string &name, const int &location);
		void cacheFloat2(const std::string &name, const int &location);
		void cacheUInt2(const std::string &name, const int &location);

	public:
		void setInt3Fast(const std::string &name, const int &value1, const int &value2, const int &value3);
		void setUInt3Fast(const std::string &name, const unsigned int &value1, const unsigned int &value2, const unsigned int &value3);
		void setFloat3Fast(const std::string &name, const float &value1, const float &value2, const float &value3);
		void setBool3Fast(const std::string &name, const bool &value1, const bool &value2, const bool &value3);

		void setInt3(const std::string &name, const int &value1, const int &value2, const int &value3);
		void setUInt3(const std::string &name, const unsigned int &value1, const unsigned int &value2, const unsigned int &value3);
		void setFloat3(const std::string &name, const float &value1, const float &value2, const float &value3);
		void setBool3(const std::string &name, const bool &value1, const bool &value2, const bool &value3);

		void cacheInt3(const std::string &name, const int &value1, const int &value2, const int &value3, const int &location);
		void cacheUInt3(const std::string &name, const unsigned int &value1, const unsigned int &value2, const unsigned int &value3, const int &location);
		void cacheFloat3(const std::string &name, const float &value1, const float &value2, const float &value3, const int &location);
		void cacheBool3(const std::string &name, const bool &value1, const bool &value2, const bool &value3, const int &location);

		void cacheBool3(const std::string &name, const int &location);
		void cacheInt3(const std::string &name, const int &location);
		void cacheFloat3(const std::string &name, const int &location);
		void cacheUInt3(const std::string &name, const int &location);

	public:
		void setInt4Fast(const std::string &name, const int &value1, const int &value2, const int &value3, const int &value4);
		void setUInt4Fast(const std::string &name, const unsigned int &value1, const unsigned int &value2, const unsigned int &value3, const unsigned int &value4);
		void setFloat4Fast(const std::string &name, const float &value1, const float &value2, const float &value3, const float &value4);
		void setBool4Fast(const std::string &name, const bool &value1, const bool &value2, const bool &value3, const bool &value4);

		void setInt4(const std::string &name, const int &value1, const int &value2, const int &value3, const int &value4);
		void setUInt4(const std::string &name, const unsigned int &value1, const unsigned int &value2, const unsigned int &value3, const unsigned int &value4);
		void setFloat4(const std::string &name, const float &value1, const float &value2, const float &value3, const float &value4);
		void setBool4(const std::string &name, const bool &value1, const bool &value2, const bool &value3, const bool &value4);

		void cacheInt4(const std::string &name, const int &value1, const int &value2, const int &value3, const int &value4, const int &location);
		void cacheUInt4(const std::string &name, const unsigned int &value1, const unsigned int &value2, const unsigned int &value3, const unsigned int &value4, const int &location);
		void cacheFloat4(const std::string &name, const float &value1, const float &value2, const float &value3, const float &value4, const int &location);
		void cacheBool4(const std::string &name, const bool &value1, const bool &value2, const bool &value3, const bool &value4, const int &location);

		void cacheBool4(const std::string &name, const int &location);
		void cacheInt4(const std::string &name, const int &location);
		void cacheFloat4(const std::string &name, const int &location);
		void cacheUInt4(const std::string &name, const int &location);

	public:
		void genTexture2DBuffer(const std::string &name, const unsigned int &width, const unsigned int &height);
		void updataTexture2D(
			const std::string &name,
			const unsigned int &width, const unsigned int &height,
			const unsigned int &x_offset, const unsigned int &y_offset,
			unsigned char *data);
		void setTexture2D(const std::string &name, const std::string &pack_dot_name);
		void setTextureCube(const std::string &name,
			const std::string &positive_x, const std::string &negative_x,
			const std::string &positive_y, const std::string &negative_y,
			const std::string &positive_z, const std::string &negative_z);

		void setTextureCube(const std::string &name, const std::string &cubemap_name);

		void cacheTexture2D(const std::string &name, const std::string &pack_name, const int &location);
		void cacheCubeMap(const std::string &name, const std::string &pack_name, const int &location);

		void cacheCubeMap(const std::string &name, const std::string pack_name);
		void cacheCubeMap(const std::string &name, const int &location);
		void cacheTexture2D(const std::string &name, const int &location);

		void setTexture2DName(const std::string &name, const std::string &tex_name);
		void cacheTexture2D(const std::string &name, const std::string pack_name);
		void setCubeMapName(const std::string &name, const std::string &tex_name);

	private:
		UniformBaseProperty m_Proerty;
		unsigned int m_TextrueCount;

	public:
		static UniversalMaterial *DefaultMaterial;
	};
}
