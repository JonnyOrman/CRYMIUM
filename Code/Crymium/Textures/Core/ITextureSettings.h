#pragma once
#include <CryRenderer/ITexture.h>

namespace Crymium::Textures::Core
{
	struct ITextureSettings
	{
		virtual ~ITextureSettings() = default;

		virtual const char* GetName() = 0;

		virtual int GetNumberOfMips() = 0;

		virtual int GetFlags() = 0;

		virtual ETEX_Format GetEtexFormat() = 0;

		virtual int GetWidth() = 0;

		virtual int GetHeight() = 0;
	};
}

using namespace Crymium::Textures::Core;