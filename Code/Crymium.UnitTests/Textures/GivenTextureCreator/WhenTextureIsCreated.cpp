#include <gtest/gtest.h>
#include "Buffer/Mocks/MockBufferProvider.h"
#include "Cry/Mocks/MockTexture.h"
#include "gmock/gmock.h"
#include "Rendering/Mocks/MockCrymiumRenderer.h"
#include "Textures/Mocks/MockTextureProvider.h"
#include "Textures/Mocks/MockTextureSettings.h"
#include "Textures/TextureCreator.h"

namespace Crymium::UnitTests::Textures::GivenTextureCreator
{
	TEST(WhenTextureIsCreated, ShouldExecuteJavaScriptOnBrowser)
	{
		MockTextureSettings mockTextureSettings;
		MockBufferProvider mockBufferProvider;
		MockTextureProvider mockTextureProvider;
		MockCrymiumRenderer mockCrymiumRenderer;
		MockTexture mockTexture;
		
		const char* textureName = "TextureName";
		auto textureWidth = 1024;
		auto textureHeight = 720;
		auto textureNumberOfMips = 1;
		auto textureEtexFormat = eTF_B8G8R8A8;
		auto textureFlags = FILTER_LINEAR;

		unsigned char bufferChar = 'a';
		unsigned char* buffer = &bufferChar;

		EXPECT_CALL(mockTextureSettings, GetName()).WillOnce(testing::Return(textureName));
		EXPECT_CALL(mockTextureSettings, GetWidth()).WillOnce(testing::Return(textureWidth));
		EXPECT_CALL(mockTextureSettings, GetHeight()).WillOnce(testing::Return(textureHeight));
		EXPECT_CALL(mockTextureSettings, GetNumberOfMips()).WillOnce(testing::Return(textureNumberOfMips));
		EXPECT_CALL(mockTextureSettings, GetEtexFormat()).WillOnce(testing::Return(textureEtexFormat));
		EXPECT_CALL(mockTextureSettings, GetFlags()).WillOnce(testing::Return(textureFlags));

		EXPECT_CALL(mockBufferProvider, Get()).WillOnce(testing::Return(buffer));

		EXPECT_CALL(mockCrymiumRenderer, CreateTexture(
			textureName,
			textureWidth,
			textureHeight,
			textureNumberOfMips,
			buffer,
			textureEtexFormat,
			textureFlags
		)).WillOnce(testing::Return(&mockTexture));

		EXPECT_CALL(mockTextureProvider, Set(&mockTexture)).Times(1);
		
		TextureCreator sut(
			&mockTextureSettings,
			&mockBufferProvider,
			&mockTextureProvider,
			&mockCrymiumRenderer
		);

		sut.Create();
	}
}
