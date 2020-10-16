#pragma once
#include "include/internal/cef_types.h"

namespace Crymium::Cef::Core
{
	struct ICrymiumCefSettings
	{
		virtual ~ICrymiumCefSettings() = default;

		virtual const char* GetBrowserSubprocessPath() = 0;

		virtual bool GetCommandLineArgsDisabled() = 0;

		virtual cef_log_severity_t GetLogSeverity() = 0;

		virtual int GetRemoteDebuggingPort() = 0;

		virtual cef_color_t GetBackgroundColour() = 0;
	};
}

using namespace Crymium::Cef::Core;