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
		CrymiumCefCaptureFrameListener(
			ITextureUpdater* textureUpdater
		);

		bool OnNeedFrameData(unsigned char*& pConvertedTextureBuf) override;

		void OnFrameCaptured() override;

		int OnGetFrameWidth() override;

		int OnGetFrameHeight() override;

		int OnCaptureFrameBegin(int* pTexHandle) override;

	private:
		ITextureUpdater* _textureUpdater;
	};
}

using namespace Crymium::Cef;