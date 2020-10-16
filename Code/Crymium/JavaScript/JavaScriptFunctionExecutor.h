#pragma once
#include "JavaScript/Core/IJavaScriptFunctionExecutor.h"
#include "JavaScript/Core/IJavaScriptFunctionCallBuilder.h"
#include "JavaScript/Core/IJavaScriptExecutor.h"

namespace Crymium::JavaScript
{
	class JavaScriptFunctionExecutor
		: public IJavaScriptFunctionExecutor
	{
	public:
		__declspec(dllexport) JavaScriptFunctionExecutor(
			IJavaScriptFunctionCallBuilder* javaScriptFunctionCallBuilder,
			IJavaScriptExecutor* javaScriptExecutor
		);

		__declspec(dllexport) void Execute(const char* functionName, const std::vector<std::string>& parameters) override;

	private:
		IJavaScriptFunctionCallBuilder* _javaScriptFunctionCallBuilder;
		IJavaScriptExecutor* _javaScriptExecutor;
	};
}

using namespace Crymium::JavaScript;