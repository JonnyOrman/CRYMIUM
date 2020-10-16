#pragma once

namespace Crymium::Textures::Core
{
	struct ITextureDrawer
	{
		virtual ~ITextureDrawer() = default;

		virtual void Draw() = 0;
	};
}

using namespace Crymium::Textures::Core;