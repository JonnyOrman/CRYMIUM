#pragma once
#include "Crymium/Browsers/Core/IBrowserSettingsCreator.h"

namespace Crymium::Browsers
{
	class BrowserSettingsCreator
		: public IBrowserSettingsCreator
	{
	public:
		BrowserSettingsCreator() = default;

		CefBrowserSettings Create() override;
	};
}

using namespace Crymium::Browsers;