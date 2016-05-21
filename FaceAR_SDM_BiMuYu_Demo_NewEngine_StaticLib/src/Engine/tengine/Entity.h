#pragma once

#include <cstdint>
#include <functional>
#include <cassert>
#include <unordered_set>
#include <vector>
#include <algorithm>

#include "xsystem/XIDCreator.h"
#include "xsystem/XComponentWapper.h"

#include "RenderObject.h"
#include "Transform.h"

namespace tezcat
{
	class Entity
	{
	public:
		Entity(Entity *parent = nullptr);
		~Entity();

		//
		//静态组件
		//************************************
		// 函数名:  hasStatic
		// 返回值:  bool
		// 功能:
		//************************************
		template<typename XCom>
		bool hasStatic()
		{
			return m_StaticComponent.hasComponent<XCom>();
		}

		//************************************
		// 函数名:  getStatic
		// 返回值:  XCom *
		// 功能:
		//************************************
		template<typename XCom>
		XCom *getStatic()
		{
			return m_StaticComponent.getComponent<XCom>();
		}

		//************************************
		// 函数名:  attachStatic
		// 返回值:  void
		// 参数名:  XCom * com
		// 功能:
		//************************************
		template<typename XCom>
		void attachStatic(XCom *com)
		{
			m_StaticComponent.attachComponent<XCom>(com);
		}

		//************************************
		// 函数名:  detachStatic
		// 返回值:  void
		// 功能:
		//************************************
		template<typename XCom>
		void detachStatic()
		{
			m_StaticComponent.detachComponent<XCom>();
		}

		//
		//动态组件
		//************************************
		// 函数名:  hasDynamic
		// 返回值:  bool
		// 功能:
		//************************************
		template<typename XCom>
		bool hasDynamic()
		{
			return m_DynamicComponent.hasComponent<XCom>();
		}

		//************************************
		// 函数名:  getDynamic
		// 返回值:  XCom *
		// 功能:
		//************************************
		template<typename XCom>
		XCom *getDynamic()
		{
			return m_DynamicComponent.getComponent<XCom>();
		}

		//************************************
		// 函数名:  attachDynamic
		// 返回值:  void
		// 参数名:  XCom * com
		// 功能:
		//************************************
		template<typename XCom>
		void attachDynamic(XCom *com)
		{
			m_DynamicComponent.attachComponent<XCom>(com);
		}

		//************************************
		// 函数名:  detachDynamic
		// 返回值:  void
		// 功能:
		//************************************
		template<typename XCom>
		void detachDynamic()
		{
			m_DynamicComponent.detachComponent<XCom>();
		}


		//************************************
		// 函数名:  updataDynamicComponent
		// 返回值:  void
		// 功能:
		//************************************
		void updataDynamicComponent()
		{
// 			auto it = m_DynamicComponent.getLogic()->resetIterator();
// 			while (it->hasNext())
// 			{
// 				if (OnUpdataDynamicComponent)
// 				{
// 					OnUpdataDynamicComponent(it->value());
// 				}
// 				it->value()->logic();
// 				it->next();
// 			}

			auto begin = m_DynamicComponent.getLogic().begin();
			auto end = m_DynamicComponent.getLogic().end();
			while (begin != end)
			{
				(*begin)->logic();
				++begin;
			}
		}

		//************************************
		// 函数名:  addChild
		// 返回值:  void
		// 参数名:  XEntity * entity
		// 功能:
		//************************************
		void addChild(Entity *entity)
		{
			assert(entity->getParent() == nullptr);
			entity->setParent(this);
			entity->getRenderObject()->getTransform()->setParent(this->m_RenderObject->getTransform());
			m_Children.push_back(entity);
		}

		//************************************
		// 函数名:  removeChild
		// 返回值:  void
		// 参数名:  XEntity * entity
		// 功能:
		//************************************
		void removeChild(Entity *entity)
		{
			assert(entity->getParent() == this);
			entity->setParent(nullptr);
			m_Children.erase(std::remove(m_Children.begin(), m_Children.end(), entity));
		}

		//************************************
		// 函数名:  removeSelf
		// 返回值:  void
		// 功能:
		//************************************
		void removeSelf() { m_Parent->removeChild(this); }

		std::vector<Entity *> &getChildren() { return m_Children; }

		//************************************
		// 函数名:  hasChild
		// 返回值:  bool
		// 功能:
		//************************************
		const bool hasChild() const { return !m_Children.empty(); }

		//************************************
		// 函数名:  getGlobalID
		// 返回值:  size_t &
		// 功能:
		//************************************
		const size_t &getGlobalID() { return m_GlobalID; }

		//************************************
		// 函数名:  getGroupID
		// 返回值:  size_t &
		// 功能:
		//************************************
		const size_t &getGroupID() { return m_GroupID; }

		//************************************
		// 函数名:  getIDInGroup
		// 返回值:  size_t &
		// 功能:
		//************************************
		const size_t &getIDInGroup() { return m_IDInGroup; }

		//************************************
		// 函数名:  getParent
		// 返回值:  tezcat::Entity *
		// 功能:
		//************************************
		Entity *getParent() const { return m_Parent; }

		//************************************
		// 函数名:  setParent
		// 返回值:  void
		// 参数名:  Entity * val
		// 功能:
		//************************************
		void setParent(Entity * val) { m_Parent = val; }

		//************************************
		// 函数名:  buildEntity
		// 返回值:  void
		// 功能:
		//************************************
		void buildEntity()
		{
// 			auto it = m_DynamicComponent.getLogic()->resetIterator();
// 			while (it->hasNext())
// 			{
// 				it->value()->buildComponent(&m_DynamicComponent, &m_StaticComponent);
// 				it->next();
// 			}
//
// 			it = m_StaticComponent.getLogic()->resetIterator();
// 			while (it->hasNext())
// 			{
// 				it->value()->buildComponent(&m_DynamicComponent, &m_StaticComponent);
// 				it->next();
// 			}

			auto begin = m_DynamicComponent.getLogic().begin();
			auto end = m_DynamicComponent.getLogic().end();
			while (begin != end)
			{
				(*begin)->buildComponent(&m_DynamicComponent, &m_StaticComponent);
				++begin;
			}

			begin = m_StaticComponent.getLogic().begin();
			end = m_StaticComponent.getLogic().end();
			while (begin != end)
			{
				(*begin)->buildComponent(&m_DynamicComponent, &m_StaticComponent);
				++begin;
			}
		}

		void sort(const glm::vec3 &std_value)
		{
// 			std::sort(m_Children.begin(), m_Children.end(), [&](Entity *first, Entity *second)
// 			{
// 				return first->getRenderObject()->getTransform()->getPosition()
// 			});
		}

	public:
		void addStringTag(const std::string &tag)
		{
			m_StringTags.insert(tag);
		}

		void removeStringTag(const std::string &tag)
		{
			m_StringTags.erase(tag);
		}

		bool hasStringTag(const std::string &tag)
		{
			return m_StringTags.find(tag) != m_StringTags.end();
		}

		void setName(const std::string &name)
		{
			m_Name = name;
		}

		void setRenderObject(RenderObject *render_object)
		{
			m_RenderObject = render_object;
		}

		RenderObject *getRenderObject() { return m_RenderObject; }

	private:
		RenderObject *m_RenderObject;

	private:
		XComponentWapper m_DynamicComponent;					//动态组件
		XComponentWapper m_StaticComponent;						//静态组件

		size_t m_GlobalID;										//全局ID
		size_t m_GroupID;										//组ID;
		size_t m_IDInGroup;										//组内ID;
		Entity *m_Parent;										//父节点
		std::string m_Name;

		std::vector<Entity *> m_Children;

	private:
		std::unordered_set<std::string> m_StringTags;
	};
}
