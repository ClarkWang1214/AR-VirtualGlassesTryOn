#pragma once

#include "xsystem/XSingleton.h"
#include "EntityManager.h"
#include <string>



namespace tezcat
{	
	class Entity;
	class MeshManager;
	class ImageManager;
	class ShaderManager;
	class GLTextureManager;
	class GLTextureCube;
	class GLTexture2D;
	class Program;
	class MaterialManager;
	class UniversalMaterial;
	class ResourceSystem : public XSingleton<ResourceSystem>
	{
	public:
		ResourceSystem();
		~ResourceSystem();

		//************************************
		// 函数名:  loadConfiguration
		// 返回值:  void
		// 参数名:  const std::string & root_path
		// 参数名:  const std::string & relative_path
		// 功能:    
		//************************************
		void loadConfiguration(const std::string &root_path, const std::string &relative_path);

		//************************************
		// 函数名:  getResRootPath
		// 返回值:  std::string
		// 功能:    
		//************************************
		std::string getResRootPath() const { return m_ResRootPath; }

		//==================================================================
		//
		//	Model
		//
	public:
		//************************************
		// 函数名:	createModel
		// 全名:		tezcat::ResourceSystem::createModel
		// 权限:		public 
		// 返回值:   tezcat::Entity *
		// 限定符:	
		// 参数:		const std::string & name
		// 参数:		const int & pass_id
		// 功能:		
		//************************************
		Entity *createModel(const std::string &name, const int &pass_id);

		//************************************
		// 函数名:	createModelFromPackage
		// 全名:		tezcat::ResourceSystem::createModelFromPackage
		// 权限:		public 
		// 返回值:   tezcat::Entity *
		// 限定符:	
		// 参数:		const std::string & pack_name
		// 功能:		
		//************************************
		Entity *createModelFromPackage(const std::string &pack_name);

		//************************************
		// 函数名:  createSkyBox
		// 返回值:  tezcat::Entity *
		// 参数名:  const std::string & name
		// 功能:    
		//************************************
		Entity *createSkyBox();

		//************************************
		// 函数名:  createCamera
		// 返回值:  tezcat::Entity * 
		// 参数名:  const std::string & name
		// 功能:    
		//************************************
		Entity *createCamera(const std::string &name);

		//======================================================
		//
		//	Texture
		//
	public:
		GLTexture2D *createTexture2D(const std::string &file);

		//************************************
		// Method:    createCubeTexture
		// FullName:  tezcat::ResourceSystem::createCubeTexture
		// Access:    public 
		// Returns:   tezcat::GLTextureCube *
		// Qualifier:
		// Parameter: const std::string & name
		// Parameter: const std::string & positive_x
		// Parameter: const std::string & negative_x
		// Parameter: const std::string & positive_y
		// Parameter: const std::string & negative_y
		// Parameter: const std::string & positive_z
		// Parameter: const std::string & negative_z
		//************************************
		GLTextureCube *createCubeMap(
			const std::string &name,
			const std::string &positive_x, const std::string &negative_x,
			const std::string &positive_y, const std::string &negative_y,
			const std::string &positive_z, const std::string &negative_z);

		//************************************
		// Method:    createCubeTexture
		// FullName:  tezcat::ResourceSystem::createCubeTexture
		// Access:    public 
		// Returns:   tezcat::GLTextureCube *
		// Qualifier:
		// Parameter: const std::string & cubemap_name
		//************************************
		GLTextureCube *createCubeMapFromPackage(const std::string &cubemap_name);

		//************************************
		// Method:    createTexture2D
		// FullName:  tezcat::ResourceSystem::createTexture2D
		// Access:    public 
		// Returns:   tezcat::GLTexture2D *
		// Qualifier:
		// Parameter: const std::string & name
		//************************************
		GLTexture2D *createTexture2DFromPackage(const std::string &pack_dot_name);

		//========================================================
		//
		//	Shader
		//
	public:
		Program *createProgram(
			const std::string &name,
			const int &queue_id,
			const std::string &vs,
			const std::string &fs,
			const std::string &gs = "",
			const std::string &tcs = "",
			const std::string &tes = "");

		//************************************
		// 函数名:	createProgramFromPackage
		// 全名:		tezcat::ResourceSystem::createProgramFromPackage
		// 权限:		public 
		// 返回值:   tezcat::Program *
		// 限定符:	
		// 参数:		const std::string & pack_name
		// 功能:		
		//************************************
		Program *createProgramFromPackage(const std::string &pack_name);

		//************************************
		// 函数名:	confirmShaderIsLoaded
		// 全名:		tezcat::ResourceSystem::confirmShaderIsLoaded
		// 权限:		public 
		// 返回值:   bool
		// 限定符:	
		// 参数:		const std::string & pack_name
		// 功能:		
		//************************************
		bool confirmShaderIsLoaded(const std::string &pack_name);

		//======================================================
		//
		//	Material
		//
	public:

		//************************************
		// 函数名:	createUniversalMaterialFromPackage
		// 全名:		tezcat::ResourceSystem::createUniversalMaterialFromPackage
		// 权限:		public 
		// 返回值:   tezcat::UniversalMaterial *
		// 限定符:	
		// 参数:		const std::string & pack_name
		// 功能:		
		//************************************
		UniversalMaterial *createUniversalMaterialFromPackage(const std::string &pack_name);

		//************************************
		// 函数名:	createUniversalMaterialGroupFromPackage
		// 全名:		tezcat::ResourceSystem::createUniversalMaterialGroupFromPackage
		// 权限:		public 
		// 返回值:   std::unordered_map<std::string, UniversalMaterial *> *
		// 限定符:	
		// 参数:		const std::string & pack_name
		// 功能:		
		//************************************
		std::unordered_map<std::string, UniversalMaterial *> *createUniversalMaterialGroupFromPackage(const std::string &pack_name);

		//************************************
		// 函数名:	getMaterialManager
		// 全名:		tezcat::ResourceSystem::getMaterialManager
		// 权限:		public 
		// 返回值:   tezcat::MaterialManager *
		// 限定符:	
		// 功能:		
		//************************************
		MaterialManager *getMaterialManager() { return m_MaterialManager; }

	private:

		//************************************
		// 函数名:	loadTextureFromPackage
		// 全名:		tezcat::ResourceSystem::loadTextureFromPackage
		// 权限:		private 
		// 返回值:   void
		// 限定符:	
		// 参数:		const std::string & pack_file
		// 功能:		
		//************************************
		void loadTextureFromPackage(const std::string &pack_file);

		//************************************
		// 函数名:	loadMaterialFromPackage
		// 全名:		tezcat::ResourceSystem::loadMaterialFromPackage
		// 权限:		private 
		// 返回值:   void
		// 限定符:	
		// 参数:		const std::string & pack_file
		// 功能:		
		//************************************
		void loadMaterialFromPackage(const std::string &pack_file);

		//************************************
		// 函数名:	loadModelFromPackage
		// 全名:		tezcat::ResourceSystem::loadModelFromPackage
		// 权限:		private 
		// 返回值:   void
		// 限定符:	
		// 参数:		const std::string & pack_name
		// 功能:		
		//************************************
		void loadModelFromPackage(const std::string &pack_file);

		//************************************
		// 函数名:	loadShaderFromPackage
		// 全名:		tezcat::ResourceSystem::loadShaderFromPackage
		// 权限:		private 
		// 返回值:   void
		// 限定符:	
		// 参数:		const std::string & pack_file
		// 功能:		
		//************************************
		void loadShaderFromPackage(const std::string &pack_file);

	private:
		MeshManager *m_MeshManager;
		ImageManager *m_ImageManager;
		ShaderManager *m_ShaderManager;
		GLTextureManager *m_GLTextureManager;
		MaterialManager *m_MaterialManager;

		//资源根路径
		std::string m_ResRootPath;
	};
}