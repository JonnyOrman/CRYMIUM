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
        CrymiumCefApp() = default;

        void OnContextCreated(CefRefPtr<CefBrowser> browser,
            CefRefPtr<CefFrame> frame,
            CefRefPtr<CefV8Context> context) override;

        CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override;

        bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
            CefRefPtr<CefFrame> frame,
            CefProcessId source_process,
            CefRefPtr<CefProcessMessage> message) override;

        CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override;

        void OnRenderProcessThreadCreated(
            CefRefPtr<CefListValue> extra_info) override;

        void OnRenderThreadCreated(CefRefPtr<CefListValue> extra_info) override;

    private:
        IMPLEMENT_REFCOUNTING(CrymiumCefApp);
    };
}

using namespace Crymium::Cef;