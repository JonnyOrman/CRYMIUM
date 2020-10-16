#pragma once
#include "gmock/gmock.h"
#include "Inputs/Core/IInputInitialiser.h"

namespace Crymium::UnitTests::Inputs::Mocks
{
	class MockInputInitialiser : public IInputInitialiser
	{
	public:
		MOCK_METHOD(void, Initialise, (), (override));
	};
}

using namespace Crymium::UnitTests::Inputs::Mocks;