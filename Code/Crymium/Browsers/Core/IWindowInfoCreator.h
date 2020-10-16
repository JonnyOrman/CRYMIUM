#pragma once
#include <memory>
#include <include/internal/cef_win.h>

namespace Crymium::Browsers::Core
{
	struct IWindowInfoCreator
	{
		virtual ~IWindowInfoCreator() = default;

		virtual std::unique_ptr<CefWindowInfo> Create() = 0;
	};
}

using namespace Crymium::Browsers::Core;