#pragma once
#include <memory>
#include "include/internal/cef_win.h"

namespace Crymium::Cef::Core
{
	struct ICrymiumCefMainArgsCreator
	{
		virtual ~ICrymiumCefMainArgsCreator() = default;

		virtual std::unique_ptr<CefMainArgs> Create() = 0;
	};
}

using namespace Crymium::Cef::Core;