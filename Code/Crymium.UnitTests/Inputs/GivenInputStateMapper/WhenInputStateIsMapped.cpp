#include <gtest/gtest.h>
#include "Inputs/InputStateMapper.h"

namespace Crymium::UnitTests::Inputs::GivenInputStateMapper
{
	class Parameters
	{
	public:
		Parameters(
			const EInputState inputState,
			const cef_key_event_type_t cefKeyEventType
		)
			:
			InputState(inputState),
			CefKeyEventType(cefKeyEventType)
		{}

		const EInputState InputState;

		const cef_key_event_type_t CefKeyEventType;
	};

	class WhenInputStateIsMapped
		:
		public testing::TestWithParam<Parameters>
	{
	protected:
		InputStateMapper _sut;
	};

	TEST_P(WhenInputStateIsMapped, ShouldMapToCorrectCefKeyEventType)
	{
		const auto inputState = GetParam().InputState;
		const auto cefKeyEventType = GetParam().CefKeyEventType;

		const auto result = _sut.Map(inputState);

		ASSERT_EQ(cefKeyEventType, result);
	}

	INSTANTIATE_TEST_SUITE_P(ShouldMapToCorrectCefKeyEventType, WhenInputStateIsMapped, testing::Values(
		Parameters(eIS_Pressed, KEYEVENT_KEYDOWN),
		Parameters(eIS_Released, KEYEVENT_KEYUP)
	));
}