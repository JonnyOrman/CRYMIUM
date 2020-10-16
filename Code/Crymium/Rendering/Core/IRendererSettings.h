#pragma once

namespace Crymium::Rendering::Core
{
	struct IRendererSettings
	{
		virtual ~IRendererSettings() = default;

		virtual int GetWidth() = 0;

		virtual int GetHeight() = 0;
	};
}

using namespace Crymium::Rendering::Core;