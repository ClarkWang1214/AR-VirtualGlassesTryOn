#pragma once

#include <string>


namespace tezcat
{
	class GlobalConfiguration
	{
	public:
		static void loadConfig(const std::string &path);

	public:
		static int ScreenWidth;
		static int ScreenHegiht;
		static std::string WindowName;
		static float DeltaTime;


	};
}
