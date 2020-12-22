#include "InputInitialiser.h"
#include <CrySchematyc/Env/IEnvElement.h>

InputInitialiser::InputInitialiser(
	IInputEventListener* inputEventListener
)
:
_inputEventListener(inputEventListener)
{
}

void InputInitialiser::Initialise()
{
	gEnv->pInput->AddEventListener(_inputEventListener);
}
