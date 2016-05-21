#pragma once

#include "GLHead.h"

#include <unordered_map>
#include <string>

namespace tezcat
{
	class Image;
	//===============================================
	//
	//	贴图
	//
	class GLTexture
	{
	public:
		GLTexture();
		virtual ~GLTexture();

		const GLenum &getType() const { return m_TexType; }

		const GLuint &getTexID() const { return m_TexID; }

		void bind(const unsigned int &index, const int &location)
		{
			glActiveTexture(GL_TEXTURE0 + index);
			glUniform1i(location, index);
			glBindTexture(m_TexType, m_TexID);
		}

		void unbind()
		{
			glBindTexture(m_TexType, 0);
		}

	protected:
		GLuint m_TexID;
		GLenum m_TexType;
	};


	//===============================================
	//
	//	2D贴图
	//
	class GLTexture2D : public GLTexture
	{
	public:
		GLTexture2D();
		~GLTexture2D();

		void setTexParameter(GLenum filer, GLuint mode)
		{
			glTexParameteri(m_TexType, filer, mode);
		}

		void setTextureMinFilter(GLuint mode)
		{
			glTexParameteri(m_TexType, GL_TEXTURE_MIN_FILTER, mode);
		}

		void setTextureMagFilter(GLuint mode)
		{
			glTexParameteri(m_TexType, GL_TEXTURE_MAG_FILTER, mode);
		}

	public:
		void genMipMap() { glGenerateMipmap(m_TexType); }

		void genTexture(Image *image);

		void genTextureBuffer(const unsigned int &width, const unsigned int &height, GLint internalformat, GLenum format, GLenum precision);

		void genDepthBuffer(const unsigned int &width, const unsigned int &height);

		void genStencilBuffer(const unsigned int &width, const unsigned int &height, GLenum format, GLenum precision);

		void genCustomBuffer(const unsigned int &width, const unsigned int &height, GLint internalformat, GLenum format, GLenum precision);

		bool isTextureCache() { return m_Image == nullptr; }

		void updata(const unsigned int &width, const unsigned int &height, unsigned char *data);

		void updata(const unsigned int &width, const unsigned int &height, const unsigned int &xoffset, const unsigned int &yoffset, unsigned char *data);

		void updata(GLTexture2D *tex);

	private:
		Image *m_Image;

		GLenum m_Internalformat;
		GLenum m_ExternalFormat;
		GLenum m_ExternalType;
	};

	//================================================
	//
	//	立方体贴图
	//
	class GLTextureCube : public GLTexture
	{
	public:
		enum Position
		{
			POSITIVE_X,		//x正
			NEGATIVE_X,		//x负
			POSITIVE_Y,
			NEGATIVE_Y,
			POSITIVE_Z,
			NEGATIVE_Z,
			Count,
		};

	public:
		GLTextureCube();
		~GLTextureCube();

		void genTexture(
			Image *positive_x, Image *negative_x,
			Image *positive_y, Image *negative_y,
			Image *positive_z, Image *negative_z);

	private:
		Image *m_Images[Position::Count];
	};
}