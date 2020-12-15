#pragma once
#include "Crymium/Cef/Core/ICrymiumCefSettings.h"
#include "Crymium/Cef/Core/ICrymiumCefSettingsCreator.h"

namespace Crymium::Cef
{
    class CrymiumCefSettingsCreator
        : public ICrymiumCefSettingsCreator
    {
    public:
        CrymiumCefSettingsCreator(
			ICrymiumCefSettings* crymiumCefSettings
        );

    	CefSettings Create() override;

    private:
        ICrymiumCefSettings* _crymiumCefSettings;
    };
}

using namespace Crymium::Cef;