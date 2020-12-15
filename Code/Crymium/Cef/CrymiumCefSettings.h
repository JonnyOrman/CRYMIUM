#pragma once
#include "Crymium/Cef/Core/ICrymiumCefSettings.h"

namespace Crymium::Cef
{
    class CrymiumCefSettings
        : public ICrymiumCefSettings
    {
    public:
        CrymiumCefSettings(
			const char* browserSubprocessPath,
            int commandLineArgsDisabled,
            cef_log_severity_t logSeverity,
            int remoteDebuggingPort,
            cef_color_t backgroundColour
        );

    	const char* GetBrowserSubprocessPath() override;

    	bool GetCommandLineArgsDisabled() override;

    	cef_log_severity_t GetLogSeverity() override;

    	int GetRemoteDebuggingPort() override;

    	cef_color_t GetBackgroundColour() override;

    private:
        const char* _browserSubprocessPath;
        bool _commandLineArgsDisabled;
        cef_log_severity_t _logSeverity;
        int _remoteDebuggingPort;
        cef_color_t _backgroundColour;
    };
}

using namespace Crymium::Cef;