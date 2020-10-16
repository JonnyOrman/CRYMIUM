#pragma once
#include "Cef/Core/ICrymiumCefSettings.h"
#include "Cef/Core/ICrymiumCefSettingsCreator.h"

namespace Crymium::Cef
{
    class CrymiumCefSettingsCreator
        : public ICrymiumCefSettingsCreator
    {
    public:
        __declspec(dllexport) CrymiumCefSettingsCreator(
			ICrymiumCefSettings* crymiumCefSettings
        );

        __declspec(dllexport) CefSettings Create() override;

    private:
        ICrymiumCefSettings* _crymiumCefSettings;
    };
}

using namespace Crymium::Cef;