#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "Textures/TextureProvider.h"

namespace Crymium::UnitTests::Textures::GivenTextureProvider
{
	TEST(WhenTextureIsNotSet, ShouldProvideDefaultValues)
	{
		TextureProvider sut;

		EXPECT_EQ(-1, sut.GetTextureId());
		EXPECT_EQ(-1, sut.GetTextureWidth());
		EXPECT_EQ(-1, sut.GetTextureHeight());
		EXPECT_FALSE(sut.TextureExists());
	}
}
