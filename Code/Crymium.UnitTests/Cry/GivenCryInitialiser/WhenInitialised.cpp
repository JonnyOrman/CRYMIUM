#include <gtest/gtest.h>
#include "Cry/CryInitialiser.h"
#include "gmock/gmock.h"
#include "Inputs/Mocks/MockInputInitialiser.h"
#include "Rendering/Mocks/MockCrymiumRendererInitialiser.h"

namespace Crymium::UnitTests::Cry::GivenCryInitialiser
{
	TEST(WhenInitialised, ShouldMapInputWithCorrectProperties)
	{
		MockCrymiumRendererInitialiser mockCrymiumRendererInitialiser;
		MockInputInitialiser mockInputInitialiser;

		EXPECT_CALL(mockCrymiumRendererInitialiser, Initialise()).Times(1);
		EXPECT_CALL(mockInputInitialiser, Initialise()).Times(1);

		CryInitialiser sut(
			&mockCrymiumRendererInitialiser,
			&mockInputInitialiser
		);

		sut.Initialise();
	}
}
