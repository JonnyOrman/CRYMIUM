#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "Crymium.UnitTests/Rendering/Mocks/MockRendererSettings.h"
#include "Crymium/Textures/TextureSettings.h"

namespace Crymium::UnitTests::Textures::GivenTextureSettings
{
	TEST(WhenConstructed, ShouldProvideCorrectSettings)
	{
		MockRendererSettings mockRendererSettings;

		auto name = "textureName";
		auto numberOfMips = 2;
		auto flags = FILTER_LINEAR;
		auto etexFormat = eTF_B8G8R8A8;
		auto width = 1024;
		auto height = 720;
		
		EXPECT_CALL(mockRendererSettings, GetWidth()).WillOnce(testing::Return(width));
		EXPECT_CALL(mockRendererSettings, GetHeight()).WillOnce(testing::Return(height));

		TextureSettings sut(
			name,
			numberOfMips,
			flags,
			etexFormat,
			&mockRendererSettings
		);

		EXPECT_EQ(name, sut.GetName());
		EXPECT_EQ(numberOfMips, sut.GetNumberOfMips());
		EXPECT_EQ(flags, sut.GetFlags());
		EXPECT_EQ(etexFormat, sut.GetEtexFormat());
		EXPECT_EQ(width, sut.GetWidth());
		EXPECT_EQ(height, sut.GetHeight());
	}
}