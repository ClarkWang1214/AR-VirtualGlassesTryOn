#pragma once

#include "GLHead.h"
#include <vector>
#include <unordered_map>
#include <string>

namespace tezcat
{
	class Program
	{
	public:
		enum FixedLocation : unsigned int
		{
			//自定义位置
			//mat4
			Mat4_Model = 0,
			Mat4_ModelView,
			Mat4_MVP,
			Mat4_View,
			Mat4_Projection,
			Mat4_ViewProjection,

			//mat3
			Mat3_ModelNormal,


			//vec3
			Vec3_ViewPos,

			//tex
			Texture_Ambient,
			Texture_Diffuse,
			Texture_Normal,
			Texture_Spaculer,
			Texture_Reflection,
			Texture_Lightmap,
			Texture_Skybox,

			//float
			Float_DeltaTime,

			//Custom
			Uniform0,	Uniform1,	Uniform2,	Uniform3,	Uniform4,
			Uniform5,	Uniform6,	Uniform7,	Uniform8,	Uniform9,
			Uniform10,	Uniform11,	Uniform12,	Uniform13,	Uniform14,
			Uniform15,	Count
		};

		const std::string &getShaderName() const { return m_ShaderName; }
		void setShaderName(const std::string &val) { m_ShaderName = val; }

	public:
		Program()
		{
			m_FixedLocation.resize(FixedLocation::Count, -1);
		}

		//************************************
		// 函数名:  setMatrix4fv
		// 返回值:  void
		// 参数名:  const GLint & location
		// 参数名:  const GLfloat * matrix
		// 功能:    
		//************************************
		void setMatrix4fv(const GLint &location, const GLfloat *matrix)
		{
			glUniformMatrix4fv(location, 1, GL_FALSE, matrix);
		}

		//************************************
		// 函数名:  setValue1iv
		// 返回值:  void
		// 参数名:  const GLint & location
		// 参数名:  const GLint * value
		// 功能:    
		//************************************
		void setValue1iv(const GLint &location, const GLint *value)
		{
			glUniform1iv(location, 1, value);
		}

		//************************************
		// 函数名:  setValue1fv
		// 返回值:  void
		// 参数名:  const GLint & location
		// 参数名:  const GLfloat * value
		// 功能:    
		//************************************
		void setValue1fv(const GLint &location, const GLfloat *value)
		{
			glUniform1fv(location, 1, value);
		}

		//************************************
		// 函数名:  setValue3fv
		// 返回值:  void
		// 参数名:  const GLint & location
		// 参数名:  const GLfloat * value
		// 功能:    
		//************************************
		void setValue3fv(const GLint &location, const GLfloat *value)
		{
			glUniform3fv(location, 1, value);
		}

		//************************************
		// 函数名:  setMatrix4fv
		// 返回值:  void
		// 参数名:  const FixedLocation & fixed
		// 参数名:  const GLfloat * matrix
		// 功能:    
		//************************************
		void setMatrix4fv(const FixedLocation &fixed, const GLfloat *matrix)
		{
			auto &index = m_FixedLocation[fixed];
			if (index != -1)
			{
				glUniformMatrix4fv(index, 1, GL_FALSE, matrix);
			}
		}

		void setMatrix3fv(const FixedLocation &fixed, const GLfloat *matrix)
		{
			auto &index = m_FixedLocation[fixed];
			if (index != -1)
			{
				glUniformMatrix3fv(index, 1, GL_FALSE, matrix);
			}
		}

		//************************************
		// 函数名:  setValue1iv
		// 返回值:  void
		// 参数名:  const FixedLocation & fixed
		// 参数名:  const GLint * value
		// 功能:    
		//************************************
		void setValue1iv(const FixedLocation &fixed, const GLint *value)
		{
			auto &index = m_FixedLocation[fixed];
			if (index != -1)
			{
				glUniform1iv(index, 1, value);
			}
		}

		//************************************
		// 函数名:  setValue1fv
		// 返回值:  void
		// 参数名:  const FixedLocation & fixed
		// 参数名:  const GLfloat * value
		// 功能:    
		//************************************
		void setValue1fv(const FixedLocation &fixed, const GLfloat *value)
		{
			auto &index = m_FixedLocation[fixed];
			if (index != -1)
			{
				glUniform1fv(index, 1, value);
			}
		}

		//************************************
		// 函数名:  setValue3fv
		// 返回值:  void
		// 参数名:  const FixedLocation & fixed
		// 参数名:  const GLfloat * value
		// 功能:    
		//************************************
		void setValue3fv(const FixedLocation &fixed, const GLfloat *value)
		{
			auto &index = m_FixedLocation[fixed];
			if (index != -1)
			{
				glUniform3fv(index, 1, value);
			}
		}

		//************************************
		// 函数名:  use
		// 返回值:  void
		// 功能:    
		//************************************
		void use() { glUseProgram(m_ProgramID); }

		//************************************
		// 函数名:  useDefault
		// 返回值:  void
		// 功能:    
		//************************************
		void useDefault() { glUseProgram(0); }

		const GLuint convert2SLLocation(const std::string &name) const
		{
			return m_FixedLocation[String2FixedID[name]];
		}

	public:

		GLuint getProgramID() { return m_ProgramID; }
		void setProgramID(GLuint id) { m_ProgramID = id; }

		void setLocation(const Program::FixedLocation &index, const GLint &location)
		{
			m_FixedLocation[index] = location;
		}

	private:
		friend class ShaderManager;
		GLuint m_ProgramID;
		std::string m_ShaderName;
		std::vector<GLint> m_FixedLocation;
		static unsigned int m_CustomFixedID;

	public:
		static unsigned int addFixedLocation(const std::string &fixed_name);
		static std::unordered_map<std::string, Program::FixedLocation> String2FixedID;
		
	};
}