#pragma once

namespace Crymium::Cef
{
    class CrymiumCefApp
		:
		public CefApp,
		public CefRenderProcessHandler,
		public CefBrowserProcessHandler
    {
    public:
        __declspec(dllexport) CrymiumCefApp() = default;

        __declspec(dllexport) void OnContextCreated(CefRefPtr<CefBrowser> browser,
            CefRefPtr<CefFrame> frame,
            CefRefPtr<CefV8Context> context) override;

        __declspec(dllexport) CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override;

        __declspec(dllexport) bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
            CefRefPtr<CefFrame> frame,
            CefProcessId source_process,
            CefRefPtr<CefProcessMessage> message) override;

        __declspec(dllexport) CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override;

        __declspec(dllexport) void OnRenderProcessThreadCreated(
            CefRefPtr<CefListValue> extra_info) override;

        __declspec(dllexport) void OnRenderThreadCreated(CefRefPtr<CefListValue> extra_info) override;

    private:
        IMPLEMENT_REFCOUNTING(CrymiumCefApp);
    };
}

using namespace Crymium::Cef;