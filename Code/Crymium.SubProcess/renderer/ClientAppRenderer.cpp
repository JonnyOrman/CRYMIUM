#include "ClientAppRenderer.h"
#include "include/base/cef_logging.h"

void ClientAppRenderer::OnWebKitInitialized()
{
    for (auto delegate : _delegates->GetAll())
    {
        delegate->OnWebKitInitialized();
    }
}

CefRefPtr<CefLoadHandler> ClientAppRenderer::GetLoadHandler()
{
    CefRefPtr<CefLoadHandler> load_handler;

    return load_handler;
}

void ClientAppRenderer::OnContextCreated(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefV8Context> context
)
{
    for (auto delegate : _delegates->GetAll())
    {
        delegate->OnContextCreated(
            browser, 
            frame, 
            context
        );
    }
}

void ClientAppRenderer::OnContextReleased(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefV8Context> context
)
{
    for (auto delegate : _delegates->GetAll())
    {
        delegate->OnContextReleased(
            browser,
            frame, 
            context
        );
    }
}

bool ClientAppRenderer::OnProcessMessageReceived(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefProcessId source_process,
    CefRefPtr<CefProcessMessage> message)
{
    DCHECK_EQ(source_process, PID_BROWSER);

    bool handled = false;

    for (auto delegate : _delegates->GetAll())
    {
        delegate->OnProcessMessageReceived(
            browser, 
            frame, 
            source_process,
            message
        );
    }

    return handled;
}