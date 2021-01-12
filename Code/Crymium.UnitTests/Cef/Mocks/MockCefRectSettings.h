#pragma once
#include "Crymium/Cef/Core/ICefRectSettings.h"
#include "gmock/gmock.h"

namespace Crymium::UnitTests::Cef::Mocks
{
	class MockCrymiumCefRectSettings : public ICrymiumCefRectSettings
	{
	public:
		MOCK_METHOD(int, GetX, (), (override));

		MOCK_METHOD(int, GetY, (), (override));
	};
}

using namespace Crymium::UnitTests::Cef::Mocks;