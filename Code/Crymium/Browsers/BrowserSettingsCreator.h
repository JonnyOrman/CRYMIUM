#pragma once
#include "Crymium/Browsers/Core/IBrowserSettingsCreator.h"

namespace Crymium::Browsers
{
	class BrowserSettingsCreator
		: public IBrowserSettingsCreator
	{
	public:
		__declspec(dllexport) BrowserSettingsCreator() = default;

		__declspec(dllexport) CefBrowserSettings Create() override;
	};
}

using namespace Crymium::Browsers;