#pragma once
#include "gmock/gmock.h"
#include "Buffer/Core/IBufferSizeProvider.h"

namespace Crymium::UnitTests::Buffer::Mocks
{
	class MockBufferSizeProvider : public IBufferSizeProvider
	{
	public:
		MOCK_METHOD(int, Get, (), (override));
	};
}

using namespace Crymium::UnitTests::Buffer::Mocks;