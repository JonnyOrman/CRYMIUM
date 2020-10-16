#include "BrowserSettingsCreator.h"

CefBrowserSettings BrowserSettingsCreator::Create()
{
	CefBrowserSettings browserSettings;
	
	browserSettings.web_security = STATE_DISABLED;

	return browserSettings;
}