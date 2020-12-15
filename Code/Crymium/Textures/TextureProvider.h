#pragma once
#include "Crymium/Textures/Core/ITextureProvider.h"

namespace Crymium::Textures
{
	class TextureProvider
		:
		public ITextureProvider
	{
	public:
		TextureProvider() = default;

		void Set(ITexture* texture) override;

		int GetTextureId() override;

		int GetTextureWidth() override;

		int GetTextureHeight() override;

		bool TextureExists() override;

	private:
		ITexture* _texture;
	};
}

using namespace Crymium::Textures;