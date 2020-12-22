#pragma once
#include "gmock/gmock.h"
#include "Crymium/Textures/Core/ITextureProvider.h"

namespace Crymium::UnitTests::Textures::Mocks
{
	class MockTextureProvider : public ITextureProvider
	{
	public:
		MOCK_METHOD(void, Set, (ITexture* texture), (override));

		MOCK_METHOD(int, GetTextureId, (), (override));

		MOCK_METHOD(int, GetTextureWidth, (), (override));

		MOCK_METHOD(int, GetTextureHeight, (), (override));

		MOCK_METHOD(bool, TextureExists, (), (override));
	};
}

using namespace Crymium::UnitTests::Textures::Mocks;