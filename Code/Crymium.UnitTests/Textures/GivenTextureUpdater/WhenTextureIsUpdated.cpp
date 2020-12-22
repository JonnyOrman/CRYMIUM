#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "Crymium.UnitTests/Textures/Mocks/MockTextureRemover.h"
#include "Crymium.UnitTests/Textures/Mocks/MockTextureRenderer.h"
#include "Crymium/Textures/TextureUpdater.h"

namespace Crymium::UnitTests::Textures::GivenTextureUpdater
{
	TEST(WhenTextureIsUpdated, ShouldProvideCorrectSettings)
	{
		MockTextureRemover mockTextureRemover;
		MockTextureRenderer mockTextureRenderer;

		{
			testing::InSequence s;

			EXPECT_CALL(mockTextureRemover, Remove()).Times(1);
			EXPECT_CALL(mockTextureRenderer, Render()).Times(1);
		}

		TextureUpdater sut(
			&mockTextureRemover,
			&mockTextureRenderer
		);

		sut.UpdateTexture();
	}
}
