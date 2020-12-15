#pragma once
#include "Crymium/Rendering/Core/ICrymiumRenderer.h"

namespace Crymium::Rendering
{
	class CrymiumRenderer
		:
		public ICrymiumRenderer
	{
	public:
		CrymiumRenderer() = default;

		ITexture* CreateTexture(
			const char* name, 
			int width, 
			int height, 
			int numberOfMips,
			unsigned char* data,
			ETEX_Format etexFormat, 
			int flags
		) override;

		CRY_HWND GetHWND() override;

		void RegisterCaptureFrame(ICaptureFrameListener* captureFrameListener) override;

		void RemoveTexture(int textureId) override;
	};
}

using namespace Crymium::Rendering;