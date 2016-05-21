#pragma once

#include <type_traits>
#include <iostream>

namespace tezcat
{
	template<typename BelongTo>
	class XIDCreator
	{
	public:
		static unsigned int give()
		{
			return m_ID++;
		}

		static void reset()
		{
			m_ID = 0;
		}

	private:
		static unsigned int m_ID;
	};

	template<typename BelongTo>
	unsigned int XIDCreator<BelongTo>::m_ID = 0;

#define XIDCREATOR_GIVE_ID(BelongTo, IDType)\
const static IDType &BelongTo##GiveID()\
{\
	const static IDType id = XIDCreator<BelongTo, IDType>::give();\
	return id;\
}

// 	class TestID
// 	{
//
// 	};
//
// 	class TestID1 : public TestID
// 	{
// 	public:
// 		XIDCREATOR_GIVE_ID(TestID, size_t);
//
// 		static size_t getClassID()
// 		{
// 			static size_t id = XIDCreator<TestID, size_t>::give();
// 			return id;
// 		}
// 	};
//
// 	class TestID2 : public TestID
// 	{
// 	public:
// 		static size_t getClassID()
// 		{
// 			static size_t id = XIDCreator<TestID, size_t>::give();
// 			return id;
// 		}
// 	};
}

