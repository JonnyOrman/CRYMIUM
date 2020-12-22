#pragma once
#include "Crymium/Cef/Core/ICrymiumCefSettings.h"

namespace Crymium::Cef
{
    class CrymiumCefSettings
        : public ICrymiumCefSettings
    {
    public:
        __declspec(dllexport) CrymiumCefSettings(
			const char* browserSubprocessPath,
            int commandLineArgsDisabled,
            cef_log_severity_t logSeverity,
            int remoteDebuggingPort,
            cef_color_t backgroundColour
        );

        __declspec(dllexport) const char* GetBrowserSubprocessPath() override;

        __declspec(dllexport) bool GetCommandLineArgsDisabled() override;

        __declspec(dllexport) cef_log_severity_t GetLogSeverity() override;

        __declspec(dllexport) int GetRemoteDebuggingPort() override;

        __declspec(dllexport) cef_color_t GetBackgroundColour() override;

    private:
        const char* _browserSubprocessPath;
        bool _commandLineArgsDisabled;
        cef_log_severity_t _logSeverity;
        int _remoteDebuggingPort;
        cef_color_t _backgroundColour;
    };
}

using namespace Crymium::Cef;