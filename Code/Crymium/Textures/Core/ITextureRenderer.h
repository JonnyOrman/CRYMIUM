#pragma once

namespace Crymium::Textures::Core
{
	struct ITextureRenderer
	{
		virtual ~ITextureRenderer() = default;

		virtual void Render() = 0;
	};
}

using namespace Crymium::Textures::Core;