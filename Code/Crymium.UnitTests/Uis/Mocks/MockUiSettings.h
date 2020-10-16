#pragma once
#include "gmock/gmock.h"
#include "Uis/Core/IUiSettings.h"

namespace Crymium::UnitTests::Uis::Mocks
{
	class MockUiSettings : public IUiSettings
	{
	public:
		MOCK_METHOD(std::string, GetDefaultFileName, (), (override));

		MOCK_METHOD(std::string, GetDefaultFileType, (), (override));
	};
}

using namespace Crymium::UnitTests::Uis::Mocks;