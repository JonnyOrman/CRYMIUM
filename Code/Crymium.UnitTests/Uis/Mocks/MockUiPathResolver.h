#pragma once
#include "gmock/gmock.h"
#include "Crymium/Uis/Core/IUiPathResolver.h"

namespace Crymium::UnitTests::Uis::Mocks
{
	class MockUiPathResolver : public IUiPathResolver
	{
	public:
		MOCK_METHOD(std::string, Resolve, (std::string uiName), (override));
	};
}

using namespace Crymium::UnitTests::Uis::Mocks;