#pragma once

namespace Crymium::Rendering::Core
{
	struct IRendererProvider
	{
		virtual ~IRendererProvider() = default;

		virtual IRenderer* Get() = 0;
		
		virtual int GetRendererWidth() = 0;

		virtual int GetRendererHeight() = 0;
	};
}

using namespace Crymium::Rendering::Core;