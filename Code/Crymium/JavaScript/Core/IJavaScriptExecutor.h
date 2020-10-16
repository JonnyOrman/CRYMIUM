#pragma once

namespace Crymium::JavaScript::Core
{
	struct IJavaScriptExecutor
	{
		virtual ~IJavaScriptExecutor() = default;

		virtual void Execute(const char* javaScript) = 0;
	};
}

using namespace Crymium::JavaScript::Core;