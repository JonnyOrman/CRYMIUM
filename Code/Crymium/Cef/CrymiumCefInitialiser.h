#pragma once
#include "Crymium/Cef/Core/ICrymiumCefInitialiser.h"
#include "Crymium/Cef/Core/ICefInitialiser.h"
#include "Crymium/Browsers/Core/IBrowser.h"

namespace Crymium::Cef
{
    class CrymiumCefInitialiser
        : public ICrymiumCefInitialiser
    {
    public:
        CrymiumCefInitialiser(
            ICrymiumCefAppInitialiser* crymiumCefAppInitialiser,
            IBrowser* crymiumBrowser
        );

    	void Initialise() override;

    private:
        ICrymiumCefAppInitialiser* _crymiumCefAppInitialiser;
        IBrowser* _crymiumBrowser;
    };
}

using namespace Crymium::Cef;