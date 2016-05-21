#pragma once

namespace tezcat
{
	enum class RenderQueueType : int
	{
		Queue_Null = -1,
		Queue_Background,
		Queue_Geometry,
		Queue_Alpha,
		Queue_Overlay
	};
}

