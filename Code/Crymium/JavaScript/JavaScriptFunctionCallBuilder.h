#pragma once
#include "Crymium/JavaScript/Core/IJavaScriptFunctionCallBuilder.h"

namespace Crymium::JavaScript
{
	class JavaScriptFunctionCallBuilder
		: public IJavaScriptFunctionCallBuilder
	{
	public:
		__declspec(dllexport) JavaScriptFunctionCallBuilder() = default;

		__declspec(dllexport) std::string Build(std::string functionName, const std::vector<std::string>& parameters) override;
	};
}

using namespace Crymium::JavaScript;