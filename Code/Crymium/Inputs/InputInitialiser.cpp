#include "InputInitialiser.h"

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
