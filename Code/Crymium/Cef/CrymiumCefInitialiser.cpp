#include "CrymiumCefInitialiser.h"

CrymiumCefInitialiser::CrymiumCefInitialiser(
	ICrymiumCefAppInitialiser* crymiumCefAppInitialiser,
	IBrowser* crymiumBrowser
)
:
_crymiumCefAppInitialiser(crymiumCefAppInitialiser),
_crymiumBrowser(crymiumBrowser)
{
}

void CrymiumCefInitialiser::Initialise()
{
	_crymiumCefAppInitialiser->Initialise();

	_crymiumBrowser->Initialise();
}
