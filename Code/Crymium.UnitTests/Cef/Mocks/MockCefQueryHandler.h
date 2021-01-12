#pragma once
#include "Crymium/Cef/Core/ICefQueryHandler.h"
#include "gmock/gmock.h"

namespace Crymium::UnitTests::Cef::Mocks
{
	class MockCefQueryHandler : public ICefQueryHandler
	{
	public:
		MOCK_METHOD(bool, CanHandle, (const std::string& request), (override));

		MOCK_METHOD(void, Handle, (const std::string& request), (override));
	};
}

using namespace Crymium::UnitTests::Cef::Mocks;