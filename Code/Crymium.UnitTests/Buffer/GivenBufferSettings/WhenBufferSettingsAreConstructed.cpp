#include <gtest/gtest.h>
#include "Buffer/BufferSettings.h"

namespace Crymium::UnitTests::Buffer::GivenBufferSettings
{
	TEST(WhenBufferSettingsAreConstructed, ShouldHaveCorrectProperties)
	{
		BufferSettings sut(123);

		ASSERT_EQ(123, sut.GetSizeMultiplier());
	}
}
