#include <gtest/gtest.h>
#include "Buffer/BufferRenderHandler.h"
#include "Buffer/Mocks/MockBufferProvider.h"

namespace Crymium::UnitTests::Buffer::GivenBufferRenderHandler
{
	TEST(DISABLED_WhenPaint, ShouldSetBuffer)
	{
		MockBufferProvider mockBufferProvider;

		CefRefPtr<CefBrowser> cefBrowser;
		CefRect cefRect;

		EXPECT_CALL(mockBufferProvider, Set);
		
		BufferRenderHandler sut(
			nullptr,
			nullptr,
			&mockBufferProvider
		);

		const void* buffer;
		
		sut.OnPaint(
			nullptr,
			PET_VIEW,
			std::vector<CefRect>(),
			buffer,
			0,
			0
		);

	}
}
