#include "CryInitialiser.h"

CryInitialiser::CryInitialiser(
	ICrymiumRendererInitialiser* crymiumRendererInitialiser,
	IInputInitialiser* inputInitialiser
)
:
_crymiumRendererInitialiser(crymiumRendererInitialiser),
_inputInitialiser(inputInitialiser)
{
}

void CryInitialiser::Initialise()
{
	_crymiumRendererInitialiser->Initialise();

	_inputInitialiser->Initialise();
}
