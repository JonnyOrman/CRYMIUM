#include "CrymiumCefSettings.h"

CrymiumCefSettings::CrymiumCefSettings(
	const char* browserSubprocessPath, 
	int commandLineArgsDisabled,
	cef_log_severity_t logSeverity, 
	int remoteDebuggingPort, 
	cef_color_t backgroundColour
)
:
_browserSubprocessPath(browserSubprocessPath),
_commandLineArgsDisabled(commandLineArgsDisabled),
_logSeverity(logSeverity),
_remoteDebuggingPort(remoteDebuggingPort),
_backgroundColour(backgroundColour)
{
}

const char* CrymiumCefSettings::GetBrowserSubprocessPath()
{
	return _browserSubprocessPath;
}

bool CrymiumCefSettings::GetCommandLineArgsDisabled()
{
	return _commandLineArgsDisabled;
}

cef_log_severity_t CrymiumCefSettings::GetLogSeverity()
{
	return _logSeverity;
}

int CrymiumCefSettings::GetRemoteDebuggingPort()
{
	return _remoteDebuggingPort;
}

cef_color_t CrymiumCefSettings::GetBackgroundColour()
{
	return _backgroundColour;
}