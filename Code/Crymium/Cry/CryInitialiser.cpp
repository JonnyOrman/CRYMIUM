#include "CryInitialiser.h"

CryInitialiser::CryInitialiser(
	ICrymiumRendererInitialiser* crymiumRendererInitialiser,
	IInputInitialiser* crymiumInputInitialiser
)
:
_crymiumRendererInitialiser(crymiumRendererInitialiser),
_crymiumInputInitialiser(crymiumInputInitialiser)
{
}

void CryInitialiser::Initialise()
{
	_crymiumRendererInitialiser->Initialise();

	_crymiumInputInitialiser->Initialise();
}
