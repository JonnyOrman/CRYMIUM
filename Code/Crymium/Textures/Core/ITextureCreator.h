#pragma once

namespace Crymium::Textures::Core
{
	struct ITextureCreator
	{
		virtual ~ITextureCreator() = default;

		virtual void Create() = 0;
	};
}

using namespace Crymium::Textures::Core;