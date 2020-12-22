#pragma once
#include "Crymium/Textures/Core/ITextureRenderer.h"
#include "Crymium/Textures/Core/ITextureRemover.h"
#include "Crymium/Textures/Core/ITextureUpdater.h"

namespace Crymium::Textures
{
	class TextureUpdater
		:
		public ITextureUpdater
	{
	public:
		__declspec(dllexport) TextureUpdater(
			ITextureRemover* textureRemover,
			ITextureRenderer* textureRenderer
		);

		__declspec(dllexport) void UpdateTexture() override;

	private:
		ITextureRemover* _textureRemover;
		ITextureRenderer* _textureRenderer;
	};
}

using namespace Crymium::Textures;