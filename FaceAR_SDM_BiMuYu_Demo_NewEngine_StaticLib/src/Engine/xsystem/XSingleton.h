#pragma once

namespace tezcat
{
	template<class CLASS>
	class XSingleton
	{
	public:
		static CLASS *getInstance()
		{
			return m_Instance;
		}

		static void initInstance()
		{
			if (m_Instance == nullptr)
			{
				m_Instance = new CLASS();
			}
		}

		static void deleteInstance()
		{
			if (m_Instance != nullptr)
			{
				delete m_Instance;
			}
		}

		XSingleton() = default;
		virtual ~XSingleton() = default;
		XSingleton(const XSingleton &other) = delete;
		XSingleton &operator = (const XSingleton &other) = delete;

	private:
		static CLASS *m_Instance;
	};

	template<class CLASS> CLASS *XSingleton<CLASS>::m_Instance = nullptr;
}