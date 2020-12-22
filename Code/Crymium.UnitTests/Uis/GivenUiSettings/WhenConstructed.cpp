#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "Crymium/Uis/UiSettings.h"

namespace Crymium::UnitTests::Uis::GivenUiSettings
{
	TEST(DISABLED_WhenConstructed, ShouldProviderCorrectSettings)
	{
		const auto defaultFileName = "Index";
		const auto defaultFileType = "html";

		UiSettings sut(
			defaultFileName,
			defaultFileType
		);

		EXPECT_EQ(defaultFileName, sut.GetDefaultFileName());
		EXPECT_EQ(defaultFileType, sut.GetDefaultFileType());
	}
}