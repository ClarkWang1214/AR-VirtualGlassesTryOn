#pragma once

#include <exception>
#include "XIDCreator.h"


namespace tezcat
{
	class XDynamicFlag {};
	class XStaticFlag {};
	template<typename Seed>
	class XComponentSeed {};

	class XComponentWapper;
	class XBaseComponent
	{
	public:
		XBaseComponent():m_ComponentID(0) { }
		virtual ~XBaseComponent()
		{
//			delete m_XListNode;
		}

		const size_t &getComponentID() const { return m_ComponentID; }
		void setComponentID(const size_t &val) { m_ComponentID = val; }

//		XList<XBaseComponent *>::Node *getXListNode() { return m_XListNode; }

		virtual void buildComponent(XComponentWapper *dynamic_com, XComponentWapper *static_com) {}
		virtual void logic() {}

	private:
		size_t m_ComponentID;
//		XList<XBaseComponent *>::Node *m_XListNode;
	};

	//
	//
	template<typename Component, typename Belong2Entity = XStaticFlag>
	class XComponent : public XBaseComponent
	{
	public:
		typedef Belong2Entity B2E;
		typedef Component Self;

	public:
		static const size_t &getClassIDStatic()
		{
			static size_t m_ClassID = XIDCreator<XComponentSeed<Belong2Entity>>::give();
			return m_ClassID;
		}

		const size_t &getUserID() const { return m_UserID; }
		void setUserID(const size_t &val) { m_UserID = val; }

	private:
		size_t m_UserID;
	};
}
