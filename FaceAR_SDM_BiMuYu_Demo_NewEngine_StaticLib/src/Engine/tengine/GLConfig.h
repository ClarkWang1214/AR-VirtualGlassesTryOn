#pragma once

#include "GLHead.h"
#include "MatrixConfig.h"
#include <vector>
#include <iostream>


namespace tezcat
{
	enum class AttributeID : unsigned int
	{
		Position,	//0
		Normal,		//1
		UV,			//2
		Color,		//3
		Tangent,	//4
		BitTangent	//5
	};

#define GLAttributeID(ID) static_cast<unsigned int>(ID)


	struct Vertex_PNUCTB
	{
		glm::vec3 Layout_Position;
		glm::vec3 Layout_Normal;
		glm::vec2 Layout_UV;
		glm::vec4 Layout_Color;
		glm::vec3 Layout_Tangent;
		glm::vec3 Layout_BitTangent;
	};
	typedef std::vector<Vertex_PNUCTB> Vertex_PNUCTBType;

	typedef unsigned int Index_uint;
	typedef std::vector<Index_uint> Index_uintType;

	struct VertexData
	{
		Vertex_PNUCTBType Vertices;
		Index_uintType Indices;
	};

	class GL
	{
	public:
		static int getGLVersion()
		{
			if (m_GLVersion == 0)
			{
				int majorVersion;
				int minorVersion;

				glGetIntegerv(GL_MAJOR_VERSION, &majorVersion);
				glGetIntegerv(GL_MINOR_VERSION, &minorVersion);

				m_GLVersion = majorVersion * 100 + minorVersion * 10;
			}

			return m_GLVersion;
		}

		static void bindVAO_PNUCTB()
		{
// 			std::cout << sizeof(Vertex_PNUCTB) << std::endl;
// 			std::cout << offsetof(Vertex_PNUCTB, Layout_Position) << std::endl;
// 			std::cout << offsetof(Vertex_PNUCTB, Layout_Normal) << std::endl;
// 			std::cout << offsetof(Vertex_PNUCTB, Layout_UV) << std::endl;
// 			std::cout << offsetof(Vertex_PNUCTB, Layout_Color) << std::endl;
// 			std::cout << offsetof(Vertex_PNUCTB, Layout_Tangent) << std::endl;
// 			std::cout << offsetof(Vertex_PNUCTB, Layout_BitTangent) << std::endl;

			glEnableVertexAttribArray(GLAttributeID(AttributeID::Position));
			glVertexAttribPointer(GLAttributeID(AttributeID::Position), 3, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNUCTB), (void *)offsetof(Vertex_PNUCTB, Layout_Position));

			glEnableVertexAttribArray(GLAttributeID(AttributeID::Normal));
			glVertexAttribPointer(GLAttributeID(AttributeID::Normal), 3, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNUCTB), (void *)offsetof(Vertex_PNUCTB, Layout_Normal));

			glEnableVertexAttribArray(GLAttributeID(AttributeID::UV));
			glVertexAttribPointer(GLAttributeID(AttributeID::UV), 2, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNUCTB), (void *)offsetof(Vertex_PNUCTB, Layout_UV));

			glEnableVertexAttribArray(GLAttributeID(AttributeID::Color));
			glVertexAttribPointer(GLAttributeID(AttributeID::Color), 4, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNUCTB), (void *)offsetof(Vertex_PNUCTB, Layout_Color));

			glEnableVertexAttribArray(GLAttributeID(AttributeID::Tangent));
			glVertexAttribPointer(GLAttributeID(AttributeID::Tangent), 3, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNUCTB), (void *)offsetof(Vertex_PNUCTB, Layout_Tangent));

			glEnableVertexAttribArray(GLAttributeID(AttributeID::BitTangent));
			glVertexAttribPointer(GLAttributeID(AttributeID::BitTangent), 3, GL_FLOAT, GL_FALSE, sizeof(Vertex_PNUCTB), (void *)offsetof(Vertex_PNUCTB, Layout_BitTangent));
		}

	private:
		static int m_GLVersion;
	};
}