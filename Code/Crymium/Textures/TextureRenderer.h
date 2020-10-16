#pragma once
#include "Textures/Core/ITextureRenderer.h"
#include "Textures/Core/ITextureCreator.h"
#include "Textures/Core/ITextureDrawer.h"

namespace Crymium::Textures
{
	class TextureRenderer
		:
		public ITextureRenderer
	{
	public:
		__declspec(dllexport) TextureRenderer(
			ITextureCreator* textureCreator,
			ITextureDrawer* textureDrawer
		);

		__declspec(dllexport) void Render() override;

	private:
		ITextureCreator* _textureCreator;
		ITextureDrawer* _textureDrawer;
	};
}

using namespace Crymium::Textures;