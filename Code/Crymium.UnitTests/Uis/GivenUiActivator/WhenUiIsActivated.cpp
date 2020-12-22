#include <gtest/gtest.h>
#include "Crymium.UnitTests/Browsers/Mocks/MockBrowser.h"
#include "gmock/gmock.h"
#include "Crymium.UnitTests/Uis/Mocks/MockUiPathResolver.h"
#include "Crymium/Uis/UiActivator.h"

namespace Crymium::UnitTests::Uis::GivenUiActivator
{
	TEST(DISABLED_WhenUIIsActivated, ShouldResolveUIPathAndGoToIt)
	{
		MockUiPathResolver mockUiPathResolver;
		MockBrowser mockBrowser;

		auto uiName = "SomeUI";
		auto uiPath = std::string("C:/Path/To/SomeUI/index.html");
		
		EXPECT_CALL(mockUiPathResolver, Resolve(uiName)).WillOnce(testing::Return(uiPath));
		EXPECT_CALL(mockBrowser, GoTo(uiPath)).Times(1);

		UiActivator sut(
			&mockUiPathResolver,
			&mockBrowser
		);

		sut.Activate(uiName);
	}
}
