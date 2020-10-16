#include <gtest/gtest.h>
#include "Buffer/BufferProvider.h"
#include "Buffer/BufferRenderHandler.h"
#include "Buffer/Mocks/MockBufferSizeProvider.h"

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