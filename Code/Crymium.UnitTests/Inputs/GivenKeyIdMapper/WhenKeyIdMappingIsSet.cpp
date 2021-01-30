#include <gtest/gtest.h>
#include "Crymium/Inputs/KeyIdMapper.h"

namespace Crymium::UnitTests::Inputs::GivenKeyIdMapper
{
	TEST(WhenKeyIdMappingIsSet, ShouldMapToCorrectKeyCode)
	{
		KeyIdMapper keyIdMapper;

		keyIdMapper.SetMapping(EKeyId::eKI_Left, KeyCode::Left);

		const auto keyCode = keyIdMapper.Map(EKeyId::eKI_Left);

		ASSERT_EQ(keyCode, KeyCode::Left);
	}
}