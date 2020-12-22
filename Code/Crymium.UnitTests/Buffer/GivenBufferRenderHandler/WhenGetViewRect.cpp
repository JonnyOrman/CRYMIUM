#include <gtest/gtest.h>
#include "Crymium/Buffer/BufferRenderHandler.h"
#include "Crymium.UnitTests/Cef/Mocks/MockCefRectSettings.h"
#include "Crymium.UnitTests/Rendering/Mocks/MockRendererSettings.h"

namespace Crymium::UnitTests::Buffer::GivenBufferRenderHandler
{
	TEST(WhenGetViewRect, ShouldSetCefRectWithCorrectProperties)
	{
		MockCrymiumCefRectSettings mockCrymiumCefRectSettings;
		MockRendererSettings mockRendererSettings;

		CefRefPtr<CefBrowser> cefBrowser;
		CefRect cefRect;

		EXPECT_CALL(mockCrymiumCefRectSettings, GetX).WillOnce(testing::Return(1));
		EXPECT_CALL(mockCrymiumCefRectSettings, GetY).WillOnce(testing::Return(2));

		EXPECT_CALL(mockRendererSettings, GetWidth).WillOnce(testing::Return(1024));
		EXPECT_CALL(mockRendererSettings, GetHeight).WillOnce(testing::Return(720));
		
		BufferRenderHandler sut(
			&mockCrymiumCefRectSettings,
			&mockRendererSettings,
			nullptr
		);

		sut.GetViewRect(
			cefBrowser,
			cefRect
		);

		EXPECT_EQ(1, cefRect.x);
		EXPECT_EQ(2, cefRect.y);
		EXPECT_EQ(1024, cefRect.width);
		EXPECT_EQ(720, cefRect.height);
	}
}
