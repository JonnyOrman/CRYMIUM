#pragma once
#include "gmock/gmock.h"
#include "Crymium/Textures/Core/ITextureDrawer.h"

namespace Crymium::UnitTests::Textures::Mocks
{
	class MockTextureDrawer : public ITextureDrawer
	{
	public:
		MOCK_METHOD(void, Draw, (), (override));
	};
}

using namespace Crymium::UnitTests::Textures::Mocks;