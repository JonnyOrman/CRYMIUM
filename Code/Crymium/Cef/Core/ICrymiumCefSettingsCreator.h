#pragma once
#include "include/internal/cef_types_wrappers.h"

namespace Crymium::Cef::Core
{
	struct ICrymiumCefSettingsCreator
	{
		virtual ~ICrymiumCefSettingsCreator() = default;

		virtual CefSettings Create() = 0;
	};
}

using namespace Crymium::Cef::Core;