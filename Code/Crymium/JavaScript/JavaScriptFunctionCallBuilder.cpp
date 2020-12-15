#include "JavaScriptFunctionCallBuilder.h"

std::string JavaScriptFunctionCallBuilder::Build(std::string functionName, std::vector<std::string> parameters)
{
	auto javaScriptString = std::string("window.angularComponentRef.zone.run(() => {window.angularComponentRef.component.") + functionName + "(";

	auto parameterCount = parameters.size();

	auto parameterMaxIndex = parameterCount - 1;

	for (auto parameterIndex = 0; parameterIndex < parameterCount; parameterIndex++)
	{
		auto parameter = parameters[parameterIndex];

		auto parameterString = parameter;

		javaScriptString += parameterString;

		if (parameterIndex < parameterMaxIndex)
		{
			javaScriptString += ",";
		}
	}

	javaScriptString += ");})";

	return javaScriptString;
}
