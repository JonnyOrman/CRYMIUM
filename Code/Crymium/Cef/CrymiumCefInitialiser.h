#pragma once
#include "Cef/Core/ICrymiumCefInitialiser.h"
#include "Cef/Core/ICefInitialiser.h"
#include "Browsers/Core/IBrowser.h"

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