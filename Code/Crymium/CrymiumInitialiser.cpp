#include "CrymiumInitialiser.h"

CrymiumInitialiser::CrymiumInitialiser(
	ICrymiumCefInitialiser* crymiumCefInitialiser,
	ICryInitialiser* cryInitialiser
)
:
_crymiumCefInitialiser(crymiumCefInitialiser),
_cryInitialiser(cryInitialiser)
{
}

void CrymiumInitialiser::Initialise()
{
	_crymiumCefInitialiser->Initialise();

	_cryInitialiser->Initialise();
}
