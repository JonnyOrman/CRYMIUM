#pragma once

namespace Crymium::Cef::Core
{
	struct ICrymiumCefRectSettings
	{
		virtual ~ICrymiumCefRectSettings() = default;

		virtual int GetX() = 0;

		virtual int GetY() = 0;
	};
}

using namespace Crymium::Cef::Core;