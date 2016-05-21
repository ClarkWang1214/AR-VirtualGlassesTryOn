#pragma once

#include "XComponent.h"
#include <vector>
#include <list>
#include <cassert>
#include <bitset>

namespace tezcat
{
	class XComponentWapper
	{
	public:
		XComponentWapper()
		{
//			m_Mask.reset();
			m_Search.resize(ComponentCount, nullptr);
			m_Search.shrink_to_fit();
		}
		~XComponentWapper()
		{}

		template<typename XCom>
		bool hasComponent()
		{
			return m_Search[XCom::getClassIDStatic()] != nullptr;
		}

		template<typename XCom>
		XCom *getComponent()
		{
			return static_cast<XCom *>(m_Search[XCom::getClassIDStatic()]);
		}

		template<typename XCom>
		void attachComponent(XCom *com)
		{
			assert(this->hasComponent<XCom>() == false);
			auto &id = XCom::getClassIDStatic();
			m_Search[id] = com;
//			m_Mask.set(id);
			m_Logic.push_back(com);
		}

		template<typename XCom>
		XCom *attachComponent()
		{
			assert(this->hasComponent<XCom>() == false);
			XCom *com = new XCom();
			auto &id = XCom::getClassIDStatic();
			m_Search[id] = com;
//			m_Mask.set(id);
			m_Logic.push_back(com);

			return com;
		}

		template<typename XCom>
		void detachComponent()
		{
			assert(this->hasComponent<XCom>() == true);
			auto &id = XCom::getClassIDStatic();
			auto temp = m_Search[id];
			m_Search[id] = nullptr;
//			m_Mask.set(id, false);
//			com->getXListNode()->remove();
			m_Logic.erase(temp);
		}

		std::list<XBaseComponent *>& getLogic() { return m_Logic; }

	private:
		static size_t ComponentCount;

		friend class Entity;
		std::vector<XBaseComponent *> m_Search;
//		XList<XBaseComponent *> m_Logic;
		std::list<XBaseComponent *> m_Logic;
//		std::bitset<ComponentCount> m_Mask;
	};
}