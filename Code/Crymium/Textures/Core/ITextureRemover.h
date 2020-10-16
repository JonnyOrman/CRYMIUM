#pragma once

namespace Crymium::Textures::Core
{
	struct ITextureRemover
	{
		virtual ~ITextureRemover() = default;

		virtual void Remove() = 0;
	};
}

using namespace Crymium::Textures::Core;