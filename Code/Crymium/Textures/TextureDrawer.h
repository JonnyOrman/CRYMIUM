#pragma once
#include "Crymium/Textures/Core/ITextureProvider.h"
#include "Crymium/Textures/Core/ITextureDrawer.h"

namespace Crymium::Textures
{
	class TextureDrawer
		:
		public ITextureDrawer
	{
	public:
		TextureDrawer(
			ITextureProvider* textureProvider
		);

		void Draw() override;

	private:
		ITextureProvider* _textureProvider;
	};
}

using namespace Crymium::Textures;