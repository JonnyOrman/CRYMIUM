#pragma once
#include "Browsers/Core/IBrowser.h"
#include "JavaScript/Core/IJavaScriptExecutor.h"

namespace Crymium::JavaScript
{
	class JavaScriptExecutor
		: public IJavaScriptExecutor
	{
	public:
		__declspec(dllexport) JavaScriptExecutor(
			IBrowser* crymiumBrowser
		);

		__declspec(dllexport) void Execute(const char* javaScript) override;

	private:
		IBrowser* _crymiumBrowser;
	};
}

using namespace Crymium::JavaScript;