//#include <CrySchematyc/Env/IEnvElement.h>
#include <gtest/gtest.h>
#include "Cry/Mocks/MockInput.h"
#include "Cry/Mocks/MockSystemGlobalEnvironment.h"
#include "gmock/gmock.h"
#include "Inputs/InputInitialiser.h"
#include "Inputs/Mocks/MockInputEventListener.h"

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
