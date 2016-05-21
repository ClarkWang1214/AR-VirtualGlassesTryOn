#pragma once

#include "xsystem/XSingleton.h"
#include "Scene.h"
#include <vector>
#include <string>
#include <functional>

namespace tezcat
{
	class SceneSystem : public XSingleton<SceneSystem>
	{
	public:
		SceneSystem();
		~SceneSystem();

		//************************************
		// 函数名:  createScene
		// 返回值:  Scene *
		// 参数名:  const std::string & name
		// 参数名:  const std::function<void Scene *> & onbuild
		// 参数名:  const std::function<void Scene *> & ondestroy
		// 参数名:  const std::function<void Scene *> & onpush
		// 参数名:  const std::function<void Scene *> & onpop
		// 功能:    
		//************************************
		Scene *createScene(
			const std::string &name,
			const std::function<void(Scene *)> &onbuild,
			const std::function<void(Scene *)> &ondestroy,
			const std::function<void(Scene *)> &onpush,
			const std::function<void(Scene *)> &onpop);

		//************************************
		// 函数名:  replaceScene
		// 返回值:  Scene *
		// 参数名:  const std::string & name
		// 参数名:  const std::function<void Scene *> & onbuild
		// 参数名:  const std::function<void Scene *> & ondestroy
		// 参数名:  const std::function<void Scene *> & onpush
		// 参数名:  const std::function<void Scene *> & onpop
		// 功能:    
		//************************************
		Scene *replaceScene(
			const std::string &name,
			const std::function<void(Scene *)> &onbuild,
			const std::function<void(Scene *)> &ondestroy,
			const std::function<void(Scene *)> &onpush,
			const std::function<void(Scene *)> &onpop);

		//************************************
		// 函数名:  popScene
		// 返回值:  Scene *
		// 功能:    
		//************************************
		Scene *popScene();

		//************************************
		// 函数名:  pushScene
		// 返回值:  Scene *
		// 参数名:  const std::string & name
		// 参数名:  const std::function<void Scene *> & onbuild
		// 参数名:  const std::function<void Scene *> & ondestroy
		// 参数名:  const std::function<void Scene *> & onpush
		// 参数名:  const std::function<void Scene *> & onpop
		// 功能:    
		//************************************
		Scene *pushScene(
			const std::string &name,
			const std::function<void(Scene *)> &onbuild,
			const std::function<void(Scene *)> &ondestroy,
			const std::function<void(Scene *)> &onpush,
			const std::function<void(Scene *)> &onpop);

		//************************************
		// 函数名:  logic
		// 返回值:  void
		// 功能:    
		//************************************
		void logic();

	private:
		Scene *m_CurrentScene;
		std::vector<Scene *> m_Scenes;
	};
}