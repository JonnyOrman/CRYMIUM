#pragma once
#include "gmock/gmock.h"
#include "Inputs/Core/IKeyIdMapper.h"

namespace Crymium::UnitTests::Inputs::Mocks
{
	class MockKeyIdMapper : public IKeyIdMapper
	{
	public:
		MOCK_METHOD(int, Map, (EKeyId keyId), (override));
	};
}

using namespace Crymium::UnitTests::Inputs::Mocks;