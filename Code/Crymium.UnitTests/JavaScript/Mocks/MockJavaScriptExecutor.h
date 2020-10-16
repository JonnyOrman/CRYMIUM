#pragma once
#include "gmock/gmock.h"
#include "JavaScript/Core/IJavaScriptExecutor.h"

namespace Crymium::UnitTests::JavaScript::Mocks
{
	class MockJavaScriptExecutor : public IJavaScriptExecutor
	{
	public:
		MOCK_METHOD(void, Execute, (const char* javaScript), (override));
	};
}

using namespace Crymium::UnitTests::JavaScript::Mocks;