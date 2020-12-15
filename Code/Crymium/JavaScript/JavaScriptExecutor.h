#pragma once
#include "Crymium/Browsers/Core/IBrowser.h"
#include "Crymium/JavaScript/Core/IJavaScriptExecutor.h"

namespace Crymium::JavaScript
{
	class JavaScriptExecutor
		: public IJavaScriptExecutor
	{
	public:
		JavaScriptExecutor(
			IBrowser* crymiumBrowser
		);

		void Execute(const char* javaScript) override;

	private:
		IBrowser* _crymiumBrowser;
	};
}

using namespace Crymium::JavaScript;