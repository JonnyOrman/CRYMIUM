#pragma once
#include "gmock/gmock.h"
#include "Uis/Core/IUiDirectoryProvider.h"

namespace Crymium::UnitTests::Uis::Mocks
{
	class MockUiDirectoryProvider : public IUiDirectoryProvider
	{
	public:
		MOCK_METHOD(std::string, Get, (), (override));
	};
}

using namespace Crymium::UnitTests::Uis::Mocks;