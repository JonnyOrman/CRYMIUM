#pragma once
#include "gmock/gmock.h"
#include "Crymium/Inputs/Core/IInputStateMapper.h"

namespace Crymium::UnitTests::Inputs::Mocks
{
	class MockInputStateMapper : public IInputStateMapper
	{
	public:
		MOCK_METHOD(cef_key_event_type_t, Map, (EInputState inputState), (override));
	};
}

using namespace Crymium::UnitTests::Inputs::Mocks;