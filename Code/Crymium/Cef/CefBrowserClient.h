#pragma once
#include "include/cef_client.h"
#include "Crymium/Buffer/BufferRenderHandler.h"
#include "include/wrapper/cef_message_router.h"
#include "MessageHandler.h"

namespace Crymium::Cef
{
    class CefBrowserClient
		:
		public CefClient,
        public CefLifeSpanHandler
    {
    public:
        explicit CefBrowserClient(
            BufferRenderHandler* renderHandler,
            CefRefPtr<CefMessageRouterBrowserSide> messageRouter,
            MessageHandler* messageHandler
        );

        CefRefPtr<CefRenderHandler> GetRenderHandler() OVERRIDE;
    	
        CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE;
    	
        bool OnProcessMessageReceived(
            CefRefPtr<CefBrowser> browser,
            CefRefPtr<CefFrame> frame,
            CefProcessId source_process,
            CefRefPtr<CefProcessMessage> message
        ) OVERRIDE;

        void OnAfterCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;
    	
    private:
        CefRefPtr<CefMessageRouterBrowserSide> _messageRouter;
        scoped_ptr<CefMessageRouterBrowserSide::Handler> _messageRouterBrowserSideHandler;
        CefRefPtr<CefRenderHandler> _renderHandler;
        MessageHandler* _messageHandler;

        IMPLEMENT_REFCOUNTING(CefBrowserClient);
    };
}

using namespace Crymium::Cef;