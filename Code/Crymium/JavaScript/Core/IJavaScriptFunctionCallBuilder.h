#pragma once
#include <string>
#include <vector>

namespace Crymium::JavaScript::Core
{
	struct IJavaScriptFunctionCallBuilder
	{
		virtual ~IJavaScriptFunctionCallBuilder() = default;

		virtual std::string Build(std::string functionName, const std::vector<std::string>& parameters) = 0;
	};
}

using namespace Crymium::JavaScript::Core;