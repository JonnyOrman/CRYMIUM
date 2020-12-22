#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "Crymium.UnitTests/Uis/Mocks/MockUiDirectoryProvider.h"
#include "Crymium.UnitTests/Uis/Mocks/MockUiSettings.h"
#include "Crymium/Uis/UiPathResolver.h"

namespace Crymium::UnitTests::Uis::GivenUiPathResolver
{
	TEST(DISABLED_WhenUIPathIsResolved, ShouldReturnPathToUI)
	{
		MockUiSettings mockUiSettings;
		MockUiDirectoryProvider mockUiDirectoryProvider;

		const auto uiName = "UIName";
		const auto uiDirectory = "C:/UI/Directory";
		const auto uiDirectoryString = std::string(uiDirectory);
		const auto defaultFileName = "Index";
		const auto defaultFileType = "html";

		EXPECT_CALL(mockUiSettings, GetDefaultFileName()).WillOnce(testing::Return(defaultFileName));
		EXPECT_CALL(mockUiSettings, GetDefaultFileType()).WillOnce(testing::Return(defaultFileType));
		EXPECT_CALL(mockUiDirectoryProvider, Get()).WillOnce(testing::Return(uiDirectory));
		
		UiPathResolver sut(
			&mockUiSettings,
			&mockUiDirectoryProvider
		);

		const auto result = sut.Resolve(uiName);

		EXPECT_EQ("C:/UI/Directory/UIName/Index.html", result);
	}
}