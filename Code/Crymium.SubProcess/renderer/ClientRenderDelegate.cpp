#include "ClientRenderDelegate.h"
#include "include/wrapper/cef_message_router.h"

void ClientRenderDelegate::OnWebKitInitialized()
{
    CefMessageRouterConfig config;
    _messageRouter = CefMessageRouterRendererSide::Create(config);
}

void ClientRenderDelegate::OnContextCreated(
    const scoped_refptr<CefBrowser>& browser,
    const scoped_refptr<CefFrame>& frame,
    const scoped_refptr<CefV8Context>& context)
{
    _messageRouter->OnContextCreated(
        browser, 
        frame, 
        context
    );
}

void ClientRenderDelegate::OnContextReleased(
    const scoped_refptr<CefBrowser>& browser,
    const scoped_refptr<CefFrame>& frame,
    const scoped_refptr<CefV8Context>& context
)
{
    _messageRouter->OnContextReleased(
        browser, 
        frame, 
        context
    );
}

bool ClientRenderDelegate::OnProcessMessageReceived(
    const scoped_refptr<CefBrowser>& browser,
    const scoped_refptr<CefFrame>& frame,
    CefProcessId sourceProcess,
    const scoped_refptr<CefProcessMessage>& message
)
{
    return _messageRouter->OnProcessMessageReceived(
        browser, 
        frame,
        sourceProcess, 
        message
    );
}