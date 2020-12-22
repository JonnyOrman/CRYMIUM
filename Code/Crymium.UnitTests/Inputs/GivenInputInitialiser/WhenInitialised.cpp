//#include <CrySchematyc/Env/IEnvElement.h>
#include <gtest/gtest.h>
#include "Crymium.UnitTests/Cry/Mocks/MockInput.h"
#include "Crymium.UnitTests/Cry/Mocks/MockSystemGlobalEnvironment.h"
#include "gmock/gmock.h"
#include "Crymium/Inputs/InputInitialiser.h"
#include "Crymium.UnitTests/Inputs/Mocks/MockInputEventListener.h"

namespace Crymium::UnitTests::Inputs::GivenInputInitialiser
{
	TEST(DISABLED_WhenInitialised, ShouldMapInputWithCorrectProperties)
	{
		MockInputEventListener mockInputEventListener;
		MockSystemGlobalEnvironment mockSystemGlobalEnvironment;
		MockInput mockInput;

		mockSystemGlobalEnvironment.pInput = &mockInput;
		//gEnv = &mockSystemGlobalEnvironment;

		EXPECT_CALL(mockInput, AddEventListener(&mockInputEventListener)).Times(1);
		
		InputInitialiser sut(
			&mockInputEventListener
		);

		sut.Initialise();
	}
}
