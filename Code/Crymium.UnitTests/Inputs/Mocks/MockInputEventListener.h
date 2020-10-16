#pragma once
#include <CryInput/IInput.h>
#include "gmock/gmock.h"

namespace Crymium::UnitTests::Inputs::Mocks
{
	class MockInputEventListener : public IInputEventListener
	{
	public:
		MOCK_METHOD(bool, OnInputEvent, (const SInputEvent& event), (override));

		MOCK_METHOD(bool, OnInputEventUI, (const SUnicodeEvent& event), (override));
	};
}

using namespace Crymium::UnitTests::Inputs::Mocks;