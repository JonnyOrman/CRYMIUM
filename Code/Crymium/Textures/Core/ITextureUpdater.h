#pragma once

namespace Crymium::Textures::Core
{
	struct ITextureUpdater
	{
		virtual ~ITextureUpdater() = default;

		virtual void UpdateTexture() = 0;
	};
}

using namespace Crymium::Textures::Core;