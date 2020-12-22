#pragma once
#include "Crymium/Rendering/Core/ICrymiumRenderer.h"

namespace Crymium::Rendering
{
	class CrymiumRenderer
		:
		public ICrymiumRenderer
	{
	public:
		__declspec(dllexport) CrymiumRenderer() = default;

		__declspec(dllexport) ITexture* CreateTexture(
			const char* name, 
			int width, 
			int height, 
			int numberOfMips,
			unsigned char* data,
			ETEX_Format etexFormat, 
			int flags
		) override;

		__declspec(dllexport) CRY_HWND GetHWND() override;

		__declspec(dllexport) void RegisterCaptureFrame(ICaptureFrameListener* captureFrameListener) override;

		__declspec(dllexport) void RemoveTexture(int textureId) override;
	};
}

using namespace Crymium::Rendering;