#pragma once
#include "gmock/gmock.h"
#include "Crymium/Textures/Core/ITextureRemover.h"

namespace Crymium::UnitTests::Textures::Mocks
{
	class MockTextureRemover : public ITextureRemover
	{
	public:
		MOCK_METHOD(void, Remove, (), (override));
	};
}

using namespace Crymium::UnitTests::Textures::Mocks;