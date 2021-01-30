#include <gtest/gtest.h>
#include "Crymium/Inputs/DefaultKeyIdMapperComposer.h"

namespace Crymium::UnitTests::Inputs::GivenDefaultKeyIdMapperComposer
{
	TEST(WhenDefaultKeyIdMapperIsComposed, ShouldComposeKeyIdMapperWithDefaultMappings)
	{
		auto defaultKeyIdMapper = DefaultKeyIdMapperComposer::Compose();

		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Enter), Enter);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Escape), KeyCode::Escape);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Left), Left);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Up), Up);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Right), Right);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Down), Down);
	}
}