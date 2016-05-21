#pragma once


#include "Entity.h"
#include "xsystem/XSingleton.h"
#include <list>

namespace tezcat
{
	class RenderObject;
	class EntityManager : public XSingleton<EntityManager>
	{
	public:
		EntityManager();
		~EntityManager();

		//************************************
		// 函数名:  create
		// 返回值:  Entity *
		// 参数名:  Entity * parent
		// 参数名:  EntityType type
		// 功能:    
		//************************************
		Entity *create(Entity *parent);

		//************************************
		// 函数名:  create
		// 返回值:  Entity *
		// 参数名:  EntityType type
		// 功能:    
		//************************************
		Entity *create();

		//************************************
		// 函数名:  recycle
		// 返回值:  void
		// 参数名:  Entity * entity
		// 功能:    
		//************************************
		void recycle(Entity *entity);


		//************************************
		// Method:    createModel
		// FullName:  tezcat::EntityManager::createModel
		// Access:    public 
		// Returns:   tezcat::Entity *
		// Qualifier:
		// Parameter: const std::string & name
		// Parameter: Entity * parent
		//************************************
		Entity *createModel(const std::string &name, Entity *parent = nullptr);

	private:
		std::list<Entity *> m_Entities;
	};
}
