#include <gtest/gtest.h>
#include "Cef/Mocks/MockCefMessageHandler.h"
#include "Crymium/Cef/MessageHandler.h"

namespace Crymium::UnitTests::Cef::GivenMessageHandler
{
	TEST(WhenAQueryIsReceived, ShouldHandleRequestAndReturnFalse)
	{
		MockCefMessageHandler mockCefMessageHandler;

		const auto request = "new-game";
		
		EXPECT_CALL(mockCefMessageHandler, Handle(request)).Times(1);
		
		MessageHandler sut(
			&mockCefMessageHandler
		);

		auto result = sut.OnQuery(
			nullptr,
			nullptr,
			0,
			request,
			false,
			nullptr);

		EXPECT_FALSE(result);
	}
}
