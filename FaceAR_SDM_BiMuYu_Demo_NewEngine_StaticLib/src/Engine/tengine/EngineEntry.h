#pragma once

#include <thread>
#include <string>

namespace tezcat
{

	class EngineEntry
	{
	public:
		EngineEntry();
		~EngineEntry();

		void init(const std::string &res_dir);

		//************************************
		// 函数名:  render
		// 返回值:  void
		// 功能:    
		//************************************
		void render();

		//************************************
		// 函数名:  logic
		// 返回值:  void
		// 功能:    
		//************************************
		void logic();


	public:
		EngineEntry(const EngineEntry &other) = delete;
		EngineEntry &operator = (const EngineEntry &other) = delete;

	private:
		bool m_EngineClose;

		std::thread m_RenderThread;
		std::thread m_LogicThread;
	};
}