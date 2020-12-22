#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "Crymium.UnitTests/Textures/Mocks/MockTextureCreator.h"
#include "Crymium.UnitTests/Textures/Mocks/MockTextureDrawer.h"
#include "Crymium/Textures/TextureRenderer.h"

namespace Crymium::UnitTests::Textures::GivenTextureRenderer
{
	TEST(WhenTextureIsRendered, ShouldCreateAndDrawTexture)
	{
		MockTextureCreator mockTextureCreator;
		MockTextureDrawer mockTextureDrawer;

		{
			testing::InSequence s;

			EXPECT_CALL(mockTextureCreator, Create()).Times(1);
			EXPECT_CALL(mockTextureDrawer, Draw()).Times(1);
		}

		TextureRenderer sut(
			&mockTextureCreator,
			&mockTextureDrawer
		);

		sut.Render();
	}
}
