#pragma once

#include <string>
#include <vector>
#include <functional>

namespace tezcat
{
	class Entity;
	class ModelManager;
	class Camera;
	class Entity;
	class Scene
	{
	public:
		Scene(const std::string &name);
		Scene(
			const std::string &name,
			const std::function<void(Scene *)> &onbuild,
			const std::function<void(Scene *)> &ondestroy,
			const std::function<void(Scene *)> &onpush,
			const std::function<void(Scene *)> &onpop);
		~Scene();

		//************************************
		// 函数名:  addChild
		// 返回值:  void
		// 参数名:  Entity * entity
		// 功能:    
		//************************************
		void addChild(Entity *entity);

		//************************************
		// 函数名:  getName
		// 返回值:  const std::string &
		// 功能:    
		//************************************
		const std::string &getName() const { return m_Name; }

		//************************************
		// 函数名:  logic
		// 返回值:  void
		// 功能:    
		//************************************
		void logic();

		//************************************
		// 函数名:  onBuild
		// 返回值:  void
		// 功能:    
		//************************************
		void onBuild();

		//************************************
		// 函数名:  onDestroy
		// 返回值:  void
		// 功能:    
		//************************************
		void onDestroy();

		//************************************
		// 函数名:  onPush
		// 返回值:  void
		// 功能:    
		//************************************
		void onPush();

		//************************************
		// 函数名:  onPop
		// 返回值:  void
		// 功能:    
		//************************************
		void onPop();

		//************************************
		// Method:    getCameras
		// FullName:  tezcat::Scene::getCameras
		// Access:    public 
		// Returns:   std::vector<Camera *> &
		// Qualifier:
		//************************************
		std::vector<Camera *> &getCameras() { return m_Cameras; }

	private:
		std::function<void(Scene *)> OnBuild;
		std::function<void(Scene *)> OnDestroy;
		std::function<void(Scene *)> OnPush;
		std::function<void(Scene *)> OnPop;

	private:
		friend class SceneSystem;
		std::string m_Name;
		Entity *m_TheWorld;
		std::vector<Camera *> m_Cameras;
		std::vector<std::pair<std::vector<Entity *>::iterator, std::vector<Entity *>::iterator>> m_EntityStack;
		std::vector<Entity *>::iterator m_CurrentIt, m_CurrentEnd;
	};
}