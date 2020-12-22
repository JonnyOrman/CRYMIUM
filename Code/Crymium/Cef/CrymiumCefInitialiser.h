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
        __declspec(dllexport) CrymiumCefInitialiser(
            ICrymiumCefAppInitialiser* crymiumCefAppInitialiser,
            IBrowser* crymiumBrowser
        );

        __declspec(dllexport) void Initialise() override;

    private:
        ICrymiumCefAppInitialiser* _crymiumCefAppInitialiser;
        IBrowser* _crymiumBrowser;
    };
}

using namespace Crymium::Cef;