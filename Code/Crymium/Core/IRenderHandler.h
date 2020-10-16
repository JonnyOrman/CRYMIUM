#pragma once
//#include <include/cef_render_handler.h>
//#include <CryRenderer/IRenderer.h>

namespace Crymium
{
	namespace Core
	{
		struct IRenderHandler
			/*:
			CefRenderHandler,
			ICaptureFrameListener*/
		{
			virtual ~IRenderHandler() = default;
		};
	}
}

using namespace Crymium::Core;