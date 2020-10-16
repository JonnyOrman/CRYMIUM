#pragma once
#include "gmock/gmock.h"
#include "Textures/Core/ITextureCreator.h"

namespace Crymium::UnitTests::Textures::Mocks
{
	class MockTextureCreator : public ITextureCreator
	{
	public:
		MOCK_METHOD(void, Create, (), (override));
	};
}

using namespace Crymium::UnitTests::Textures::Mocks;