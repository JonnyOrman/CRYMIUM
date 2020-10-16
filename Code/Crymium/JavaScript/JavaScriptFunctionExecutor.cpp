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

void JavaScriptFunctionExecutor::Execute(const char* functionName, const std::vector<std::string>& parameters)
{
	auto newVec = std::vector<std::string>();
	
	auto size = parameters.size();
	
	for(auto i = 0; i < size; i++)
	{
		auto param = parameters[i];
		
		newVec.push_back(param);
	}

	auto javaScriptString = _javaScriptFunctionCallBuilder->Build(functionName, newVec);

	//auto javaScriptString = "alert('Built JavaScript string')";
	
	//_javaScriptExecutor->Execute(javaScriptString.c_str());
}
