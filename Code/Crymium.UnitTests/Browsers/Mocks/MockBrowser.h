#pragma once
#include "gmock/gmock.h"
#include "Browsers/Core/IBrowser.h"

namespace Crymium::UnitTests::Browsers::Mocks
{
	class MockBrowser : public IBrowser
	{
	public:
		MOCK_METHOD(void, Initialise, (), (override));

		MOCK_METHOD(void, SendInputEvent, (const SInputEvent& inputEvent), (override));

		MOCK_METHOD(void, GoTo, (std::string url), (override));

		MOCK_METHOD(void, Set, (ICefMessageHandler* cefMessageHandler), (override));

		MOCK_METHOD(void, ExecuteJavaScriptString, (const char* javaScript), (override));

		MOCK_METHOD(void, ExecuteJavaScriptFunction, (const char* functionName, std::vector<std::string> parameters), (override));

		MOCK_METHOD(bool, IsReady, (), (override));

		MOCK_METHOD(void, Update, (), (override));

		MOCK_METHOD(std::string, GetCurrentUrl, (), (override));
	};
}

using namespace Crymium::UnitTests::Browsers::Mocks;