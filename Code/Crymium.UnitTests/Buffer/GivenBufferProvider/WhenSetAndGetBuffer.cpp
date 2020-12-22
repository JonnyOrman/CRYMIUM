#include <gtest/gtest.h>
#include "Crymium/Buffer/BufferProvider.h"
#include "Crymium/Buffer/BufferRenderHandler.h"
#include "Crymium.UnitTests/Buffer/Mocks/MockBufferSizeProvider.h"

namespace Crymium::UnitTests::Buffer::GivenBufferProvider
{
	TEST(DISABLED_WhenSetAndGetBuffer, ShouldSetAndReturnBuffer)
	{
		MockBufferSizeProvider mockBufferSizeProvider;

		CefRefPtr<CefBrowser> cefBrowser;
		CefRect cefRect;

		EXPECT_CALL(mockBufferSizeProvider, Get).WillOnce(testing::Return(123456789));

		unsigned char* buffer;
		
		BufferProvider sut(
			&mockBufferSizeProvider
		);

		sut.Set(buffer);

		EXPECT_EQ(buffer, sut.Get());
	}
}