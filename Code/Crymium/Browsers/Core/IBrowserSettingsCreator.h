#pragma once
#include "include/internal/cef_types_wrappers.h"

namespace Crymium::Browsers::Core
{
	struct IBrowserSettingsCreator
	{
		virtual ~IBrowserSettingsCreator() = default;

		virtual CefBrowserSettings Create() = 0;
	};
}

using namespace Crymium::Browsers::Core;