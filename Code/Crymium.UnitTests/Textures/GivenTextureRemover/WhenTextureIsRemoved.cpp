#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "Crymium.UnitTests/Rendering/Mocks/MockCrymiumRenderer.h"
#include "Crymium.UnitTests/Textures/Mocks/MockTextureProvider.h"
#include "Crymium/Textures/TextureRemover.h"

namespace Crymium::UnitTests::Textures::GivenTextureRemover
{
	TEST(WhenTextureIsRemoved, ShouldRemoveTextureIfExists)
	{
		MockTextureProvider mockTextureProvider;
		MockCrymiumRenderer mockCrymiumRenderer;

		auto textureId = 123;

		EXPECT_CALL(mockTextureProvider, TextureExists()).WillOnce(testing::Return(true));
		EXPECT_CALL(mockTextureProvider, GetTextureId()).WillOnce(testing::Return(textureId));
		EXPECT_CALL(mockCrymiumRenderer, RemoveTexture(textureId)).Times(1);

		TextureRemover sut(
			&mockTextureProvider,
			&mockCrymiumRenderer
		);

		sut.Remove();
	}

	TEST(WhenTextureIsRemoved, ShouldNotRemoveTextureIfDoesntExist)
	{
		MockTextureProvider mockTextureProvider;
		MockCrymiumRenderer mockCrymiumRenderer;

		EXPECT_CALL(mockTextureProvider, TextureExists()).WillOnce(testing::Return(false));
		EXPECT_CALL(mockCrymiumRenderer, RemoveTexture(::testing::_)).Times(0);

		TextureRemover sut(
			&mockTextureProvider,
			&mockCrymiumRenderer
		);

		sut.Remove();
	}
}