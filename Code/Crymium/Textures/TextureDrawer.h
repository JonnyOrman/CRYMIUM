#pragma once
#include "Textures/Core/ITextureProvider.h"
#include "Textures/Core/ITextureDrawer.h"

namespace Crymium::Textures
{
	class TextureDrawer
		:
		public ITextureDrawer
	{
	public:
		__declspec(dllexport) TextureDrawer(
			ITextureProvider* textureProvider
		);

		__declspec(dllexport) void Draw() override;

	private:
		ITextureProvider* _textureProvider;
	};
}

using namespace Crymium::Textures;