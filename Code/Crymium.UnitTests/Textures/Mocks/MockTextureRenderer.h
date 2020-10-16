#pragma once
#include "gmock/gmock.h"
#include "Textures/Core/ITextureRenderer.h"

namespace Crymium::UnitTests::Textures::Mocks
{
	class MockTextureRenderer : public ITextureRenderer
	{
	public:
		MOCK_METHOD(void, Render, (), (override));
	};
}

using namespace Crymium::UnitTests::Textures::Mocks;