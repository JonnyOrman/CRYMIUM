#include <gtest/gtest.h>
#include "Crymium/Browsers/BrowserSettingsCreator.h"

namespace Crymium::UnitTests::Browsers::GivenBrowserSettingsCreator
{
	TEST(WhenBrowserSettingsAreCreated, ShouldReturnBrowserSettingsWithCorrectProperties)
	{
		BrowserSettingsCreator sut;

		auto result = sut.Create();

		ASSERT_EQ(STATE_DISABLED, result.web_security);
	}
}