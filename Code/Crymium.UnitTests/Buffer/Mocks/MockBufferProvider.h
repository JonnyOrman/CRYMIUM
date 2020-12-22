#pragma once
#include "Crymium/Buffer/Core/IBufferProvider.h"
#include "gmock/gmock.h"

namespace Crymium::UnitTests::Buffer::Mocks
{
	class MockBufferProvider : public IBufferProvider
	{
	public:
		MOCK_METHOD(void, Set, (const void* buffer), (override));

		MOCK_METHOD(unsigned char*, Get, (), (override));
	};
}

using namespace Crymium::UnitTests::Buffer::Mocks;