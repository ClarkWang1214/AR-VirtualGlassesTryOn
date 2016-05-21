#pragma once

#include <string>
#include <unordered_map>
#include <iostream>

namespace tezcat
{
	class Program;
	class GLTextureCube;
	class GLTexture2D;
	class UniformBaseValue;
	class Material
	{
	public:
		Material();
		virtual ~Material();

		virtual void uploadUniform(Program *program) { std::cout << "no material" << std::endl; }
		virtual void unbindUniform() {}

		const std::string &getName() const { return m_Name; }
		void setName(const std::string &val) { m_Name = val; }

		const std::string &getShaderName() const { return m_ShaderName; }
		void setShaderName(const std::string &val) { m_ShaderName = val; }

		void setPassID(const unsigned int &id) { m_PassID = id; }
		const unsigned int &getPassID() const { return m_PassID; }

		const int &getQueueID() const { return m_QueueID; }
		void setQueueID(const int &val) { m_QueueID = val; }

		const unsigned int &getProgramID() const { return m_ProgramID; }
		void setProgramID(const unsigned int &val) { m_ProgramID = val; }

	protected:
		unsigned int m_PassID;
		unsigned int m_ProgramID;
		int m_QueueID;
		std::string m_Name;
		std::string m_ShaderName;
	};
}

