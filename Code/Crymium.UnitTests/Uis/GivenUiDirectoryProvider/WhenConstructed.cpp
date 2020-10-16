#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "Uis/UiDirectoryProvider.h"

namespace Crymium::UnitTests::Uis::GivenUiDirectoryProvider
{
	TEST(DISABLED_WhenConstructed, ShouldResolveUIPathAndGoToIt)
	{
		const auto uiDirectory = "C:/UI/Directory";
		const auto uiDirectoryString = std::string(uiDirectory);

		Crymium::Uis::UiDirectoryProvider sut(
			uiDirectoryString
		);

		EXPECT_EQ(uiDirectory, sut.Get());
	}
}
