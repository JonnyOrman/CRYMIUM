#pragma once
#include <CryRenderer/ITexture.h>

namespace Crymium::Textures::Core
{
	struct ITextureProvider
	{
		virtual ~ITextureProvider() = default;

		virtual void Set(ITexture* texture) = 0;
		
		virtual int GetTextureId() = 0;

		virtual int GetTextureWidth() = 0;

		virtual int GetTextureHeight() = 0;

		virtual bool TextureExists() = 0;
	};
}

using namespace Crymium::Textures::Core;