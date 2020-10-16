#include "CrymiumCefSettingsCreator.h"

CrymiumCefSettingsCreator::CrymiumCefSettingsCreator(
    ICrymiumCefSettings* crymiumCefSettings
)
:
_crymiumCefSettings(crymiumCefSettings)
{
}

CefSettings CrymiumCefSettingsCreator::Create()
{
    CefSettings settings;

    CefString(&settings.browser_subprocess_path).FromASCII(_crymiumCefSettings->GetBrowserSubprocessPath());
    settings.command_line_args_disabled = _crymiumCefSettings->GetCommandLineArgsDisabled();
    settings.log_severity = _crymiumCefSettings->GetLogSeverity();
    settings.remote_debugging_port = _crymiumCefSettings->GetRemoteDebuggingPort();
    settings.background_color = _crymiumCefSettings->GetBackgroundColour();

    return settings;
}
