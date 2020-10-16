#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "JavaScript/JavaScriptExecutor.h"
#include "Browsers/Mocks/MockBrowser.h"

namespace Crymium::UnitTests::JavaScript::GivenJavaScriptExecutor
{
	TEST(WhenJavaScriptIsExecuted, ShouldExecuteJavaScriptOnBrowser)
	{
		MockBrowser mockBrowser;

		const auto javaScript = "alert('Some JavaScript string')";

		EXPECT_CALL(mockBrowser, ExecuteJavaScriptString(javaScript)).Times(1);

		JavaScriptExecutor sut(&mockBrowser);

		sut.Execute(javaScript);
	}
}