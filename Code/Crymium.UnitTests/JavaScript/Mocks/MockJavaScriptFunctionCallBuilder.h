#pragma once
#include "gmock/gmock.h"
#include "JavaScript/Core/IJavaScriptFunctionCallBuilder.h"

namespace Crymium::UnitTests::JavaScript::Mocks
{
	class MockJavaScriptFunctionCallBuilder : public IJavaScriptFunctionCallBuilder
	{
	public:
		MOCK_METHOD(std::string, Build, (std::string functionName, const std::vector<std::string>& parameters), (override));
	};
}

using namespace Crymium::UnitTests::JavaScript::Mocks;