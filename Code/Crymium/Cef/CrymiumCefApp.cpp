#include "CrymiumCefApp.h"

void CrymiumCefApp::OnContextCreated(
	CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	CefRefPtr<CefV8Context> context
)
{
}

CefRefPtr<CefRenderProcessHandler> CrymiumCefApp::GetRenderProcessHandler()
{
	return this;
}

bool CrymiumCefApp::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
	CefProcessId source_process, CefRefPtr<CefProcessMessage> message)
{
	return false;
}

CefRefPtr<CefBrowserProcessHandler> CrymiumCefApp::GetBrowserProcessHandler()
{
	return this;
}

void CrymiumCefApp::OnRenderProcessThreadCreated(CefRefPtr<CefListValue> extra_info)
{
}

void CrymiumCefApp::OnRenderThreadCreated(CefRefPtr<CefListValue> extra_info)
{
	
}
