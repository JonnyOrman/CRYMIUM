#include "MessageHandler.h"

Crymium::Cef::MessageHandler::MessageHandler(
    ICefMessageHandler* cefMessageHandler
)
    :
    _cefMessageHandler(cefMessageHandler)
{

}

bool Crymium::Cef::MessageHandler::OnQuery(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    int64 query_id,
    const CefString& request,
    bool persistent,
    CefRefPtr<Callback> callback
)
{
    _cefMessageHandler->Handle(request);

    return false;
}