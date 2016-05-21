#pragma once


namespace tezcat
{
	class GlobalConfig
	{
	public:
		static void aspect()
		{
			Aspect = static_cast<float>(ScreenWidth) / static_cast<float>(ScreenHeight);
		}

		static unsigned int ScreenWidth;		//屏幕宽
		static unsigned int ScreenHeight;		//屏幕高
		static float Aspect;					//比例


		static float MainCameraFOV;				//视角度数
		static float MainCameraNear;			//近平面
		static float MainCameraFar;				//远平面
	};
}
