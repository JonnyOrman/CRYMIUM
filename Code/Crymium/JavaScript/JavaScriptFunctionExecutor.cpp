#include "JavaScriptFunctionExecutor.h"

JavaScriptFunctionExecutor::JavaScriptFunctionExecutor(
	IJavaScriptFunctionCallBuilder* javaScriptFunctionCallBuilder,
	IJavaScriptExecutor* javaScriptExecutor
)
:
_javaScriptFunctionCallBuilder(javaScriptFunctionCallBuilder),
_javaScriptExecutor(javaScriptExecutor)
{
}

void JavaScriptFunctionExecutor::Execute(const char* functionName, std::vector<std::string> parameters)
{
	auto javaScriptString = _javaScriptFunctionCallBuilder->Build(functionName, parameters);

	_javaScriptExecutor->Execute(javaScriptString.c_str());
}
