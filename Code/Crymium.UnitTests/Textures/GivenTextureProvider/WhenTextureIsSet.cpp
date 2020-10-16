#include <gtest/gtest.h>
#include "Cry/Mocks/MockTexture.h"
#include "gmock/gmock.h"
#include "Textures/TextureProvider.h"

namespace Crymium::UnitTests::Textures::GivenTextureProvider
{
	TEST(WhenTextureIsSet, ShouldProvideTextureProperties)
	{
		MockTexture mockTexture;

		auto textureId = 123;
		auto textureWidth = 456;
		auto textureHeight = 789;
		
		EXPECT_CALL(mockTexture, GetTextureID()).WillOnce(testing::Return(textureId));
		EXPECT_CALL(mockTexture, GetWidth()).WillOnce(testing::Return(textureWidth));
		EXPECT_CALL(mockTexture, GetHeight()).WillOnce(testing::Return(textureHeight));
		
		TextureProvider sut;

		sut.Set(&mockTexture);

		EXPECT_EQ(textureId, sut.GetTextureId());
		EXPECT_EQ(textureWidth, sut.GetTextureWidth());
		EXPECT_EQ(textureHeight, sut.GetTextureHeight());
		EXPECT_TRUE(sut.TextureExists());
	}
}
