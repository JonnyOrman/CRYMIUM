#pragma once
#include <CryRenderer/IRenderer.h>
#include "Crymium/Textures/Core/ITextureUpdater.h"

namespace Crymium::Cef
{
	class CrymiumCefCaptureFrameListener
		:
		public ICaptureFrameListener
	{
	public:
		__declspec(dllexport) CrymiumCefCaptureFrameListener(
			ITextureUpdater* textureUpdater
		);

		__declspec(dllexport) bool OnNeedFrameData(unsigned char*& pConvertedTextureBuf) override;

		__declspec(dllexport) void OnFrameCaptured() override;

		__declspec(dllexport) int OnGetFrameWidth() override;

		__declspec(dllexport) int OnGetFrameHeight() override;

		__declspec(dllexport) int OnCaptureFrameBegin(int* pTexHandle) override;

	private:
		ITextureUpdater* _textureUpdater;
	};
}

using namespace Crymium::Cef;