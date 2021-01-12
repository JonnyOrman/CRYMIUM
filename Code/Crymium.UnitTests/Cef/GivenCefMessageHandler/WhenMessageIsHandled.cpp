#include <gtest/gtest.h>
#include "Cef/Mocks/MockCefQueryHandler.h"
#include "Crymium/Cef/CefMessageHandler.h"

namespace Crymium::UnitTests::Cef::GivenCefMessageHandler
{
	TEST(WhenMessageIsHandled, ShouldBeHandledByRelevantQueryHandlers)
	{
		MockCefQueryHandler mockCefQueryHandler1;
		MockCefQueryHandler mockCefQueryHandler2;
		MockCefQueryHandler mockCefQueryHandler3;

		std::vector<ICefQueryHandler*> cefQueryHandlers;
		cefQueryHandlers.push_back(&mockCefQueryHandler1);
		cefQueryHandlers.push_back(&mockCefQueryHandler2);
		cefQueryHandlers.push_back(&mockCefQueryHandler3);
		
		const auto request = "new-game";

		EXPECT_CALL(mockCefQueryHandler1, CanHandle(request)).WillOnce(testing::Return(false));
		EXPECT_CALL(mockCefQueryHandler2, CanHandle(request)).WillOnce(testing::Return(true));
		EXPECT_CALL(mockCefQueryHandler3, CanHandle(request)).WillOnce(testing::Return(false));

		EXPECT_CALL(mockCefQueryHandler1, Handle(testing::_)).Times(0);
		EXPECT_CALL(mockCefQueryHandler2, Handle(request)).Times(1);
		EXPECT_CALL(mockCefQueryHandler3, Handle(testing::_)).Times(0);

		CefMessageHandler sut(
			cefQueryHandlers
		);

		sut.Handle(request);
	}
}
