#pragma once
#include <string>
#include <vector>

namespace Crymium::JavaScript::Core
{
	struct IJavaScriptFunctionExecutor
	{
		virtual ~IJavaScriptFunctionExecutor() = default;

		virtual void Execute(const char* functionName, std::vector<std::string> parameters) = 0;
	};
}

using namespace Crymium::JavaScript::Core;