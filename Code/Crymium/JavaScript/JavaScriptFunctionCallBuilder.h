#pragma once
#include "Crymium/JavaScript/Core/IJavaScriptFunctionCallBuilder.h"

namespace Crymium::JavaScript
{
	class JavaScriptFunctionCallBuilder
		: public IJavaScriptFunctionCallBuilder
	{
	public:
		JavaScriptFunctionCallBuilder() = default;

		std::string Build(std::string functionName, std::vector<std::string> parameters) override;
	};
}

using namespace Crymium::JavaScript;