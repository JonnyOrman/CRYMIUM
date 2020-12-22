#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "Crymium/Inputs/InputMapper.h"
#include "Crymium.UnitTests/Inputs/Mocks/MockInputStateMapper.h"
#include "Crymium.UnitTests/Inputs/Mocks/MockKeyIdMapper.h"

namespace Crymium::UnitTests::Inputs::GivenInputMapper
{
	TEST(WhenInputIsMapped, ShouldMapInputWithCorrectProperties)
	{
		MockKeyIdMapper mockKeyIdMapper;
		MockInputStateMapper mockInputStateMapper;

		SInputEvent inputEvent;
		inputEvent.keyId = eKI_1;
		inputEvent.state = eIS_Pressed;
		
		EXPECT_CALL(mockKeyIdMapper, Map(eKI_1)).WillOnce(testing::Return(123));
		EXPECT_CALL(mockInputStateMapper, Map(eIS_Pressed)).WillOnce(testing::Return(KEYEVENT_KEYDOWN));

		InputMapper sut(
			&mockKeyIdMapper,
			&mockInputStateMapper
		);

		auto result = sut.Map(inputEvent);

		ASSERT_EQ(123, result.native_key_code);
		ASSERT_EQ(123, result.windows_key_code);
		ASSERT_EQ(KEYEVENT_KEYDOWN, result.type);
		ASSERT_EQ('\0', result.character);
		ASSERT_EQ('\0', result.unmodified_character);
		ASSERT_EQ(0, result.modifiers);
		ASSERT_EQ(0, result.is_system_key);
		ASSERT_EQ(0, result.focus_on_editable_field);
	}
}
