#include <gtest/gtest.h>
#include "Crymium/Inputs/KeyIdMapper.h"

namespace Crymium::UnitTests::Inputs::GivenKeyIdMapper
{
	class Parameters
	{
	public:
		Parameters(
			const EKeyId keyId,
			const int keyCode
		)
			:
			KeyId(keyId),
			KeyCode(keyCode)
		{}

		const EKeyId KeyId;

		const int KeyCode;
	};

	class WhenKeyIdIsMapped
		:
		public testing::TestWithParam<Parameters>
	{
	protected:
		KeyIdMapper _sut;
	};

	TEST_P(WhenKeyIdIsMapped, ShouldMapToCorrectKeyCode)
	{
		const auto keyId = GetParam().KeyId;
		const auto keyCode = GetParam().KeyCode;

		const auto result = _sut.Map(keyId);

		ASSERT_EQ(keyCode, result);
	}

	INSTANTIATE_TEST_SUITE_P(ShouldMapToCorrectKeyCode, WhenKeyIdIsMapped, testing::Values(
		Parameters(eKI_Down, 40),
		Parameters(eKI_XI_DPadDown, 40),
		Parameters(eKI_Up, 38),
		Parameters(eKI_XI_DPadUp, 38),
		Parameters(eKI_Enter, 13),
		Parameters(eKI_XI_A, 13),
		Parameters(eKI_Escape, 27),
		Parameters(eKI_XI_B, 27)
	));
}