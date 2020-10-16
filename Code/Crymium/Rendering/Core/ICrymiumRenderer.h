#pragma once
#include <CryRenderer/IRenderer.h>
#include <CryRenderer/ITexture.h>

namespace Crymium::Rendering::Core
{
	struct ICrymiumRenderer
	{
		virtual ~ICrymiumRenderer() = default;

		virtual ITexture* CreateTexture(
			const char* getName, 
			int getWidth, 
			int getHeight,
			int getNumberOfMips,
			unsigned char* get,
			ETEX_Format etexFormat,
		    int getFlags
		) = 0;

		virtual CRY_HWND GetHWND() = 0;

		virtual void RegisterCaptureFrame(ICaptureFrameListener* captureFrameListener) = 0;

		virtual void RemoveTexture(int textureId) = 0;
	};
}

using namespace Crymium::Rendering::Core;