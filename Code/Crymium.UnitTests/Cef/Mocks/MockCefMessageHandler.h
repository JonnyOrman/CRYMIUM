#pragma once
#include "Crymium/Cef/Core/ICefMessageHandler.h"
#include "gmock/gmock.h"

namespace Crymium::UnitTests::Cef::Mocks
{
	class MockCefMessageHandler : public ICefMessageHandler
	{
	public:
		MOCK_METHOD(void, Handle, (const std::string& request), (override));

		MOCK_METHOD(void, AddCefQueryHandler, (ICefQueryHandler* cefQueryHandler), (override));
	};
}

using namespace Crymium::UnitTests::Cef::Mocks;