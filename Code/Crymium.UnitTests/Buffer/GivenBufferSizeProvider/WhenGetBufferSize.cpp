#include <gtest/gtest.h>
#include "Crymium/Buffer/BufferSizeProvider.h"
#include "Crymium.UnitTests/Buffer/Mocks/MockBufferSettings.h"
#include "Crymium.UnitTests/Rendering/Mocks/MockRendererSettings.h"

namespace Crymium::UnitTests::Buffer::GivenBufferSizeProvider
{
	TEST(WhenGetBufferSize, ShouldReturnCorrectBufferSize)
	{
		MockRendererSettings mockRendererSettings;
		MockBufferSettings mockBufferSettings;

		EXPECT_CALL(mockRendererSettings, GetWidth).WillOnce(testing::Return(1024));
		EXPECT_CALL(mockRendererSettings, GetHeight).WillOnce(testing::Return(720));

		EXPECT_CALL(mockBufferSettings, GetSizeMultiplier).WillOnce(testing::Return(4));
		
		BufferSizeProvider sut(
			&mockRendererSettings,
			&mockBufferSettings
		);

		auto result = sut.Get();

		ASSERT_EQ(2949120, result);
	}
}
