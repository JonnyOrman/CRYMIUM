#pragma once
#include "gmock/gmock.h"
#include "Buffer/Core/IBufferSettings.h"

namespace Crymium::UnitTests::Buffer::Mocks
{
	class MockBufferSettings : public IBufferSettings
	{
	public:
		MOCK_METHOD(int, GetSizeMultiplier, (), (override));
	};
}

using namespace Crymium::UnitTests::Buffer::Mocks;