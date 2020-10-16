#pragma once
#include "gmock/gmock.h"
#include "Rendering/Core/ICrymiumRendererInitialiser.h"

namespace Crymium::UnitTests::Rendering::Mocks
{
	class MockCrymiumRendererInitialiser : public ICrymiumRendererInitialiser
	{
	public:
		MOCK_METHOD(void, Initialise, (), (override));
	};
}

using namespace Crymium::UnitTests::Rendering::Mocks;