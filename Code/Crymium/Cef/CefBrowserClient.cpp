#include "CefBrowserClient.h"
#include <include/wrapper/cef_helpers.h>
#include "MessageHandler.h"

CefBrowserClient::CefBrowserClient(
    BufferRenderHandler* renderHandler,
    CefRefPtr<CefMessageRouterBrowserSide> messageRouter,
    MessageHandler* messageHandler
)
	:
_renderHandler(renderHandler),
_messageRouter(messageRouter),
_messageHandler(messageHandler)
{
	
}

CefRefPtr<CefRenderHandler> CefBrowserClient::GetRenderHandler()
{
	return _renderHandler;
}

CefRefPtr<CefLifeSpanHandler> CefBrowserClient::GetLifeSpanHandler()
{
    return this;
}

bool CefBrowserClient::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefProcessId source_process,
    CefRefPtr<CefProcessMessage> message
)
{
    return _messageRouter->OnProcessMessageReceived(
        browser, 
        frame,
        source_process, 
        message
    );
}

void CefBrowserClient::OnAfterCreated(CefRefPtr<CefBrowser> browser)
{
    _messageRouterBrowserSideHandler.reset(_messageHandler);
    _messageRouter->AddHandler(_messageRouterBrowserSideHandler.get(), false);
}