#pragma once
#include <include/wrapper/cef_message_router.h>
#include "Crymium/Cef/Core/ICefMessageHandler.h"

namespace Crymium::Cef
{
    class MessageHandler
        : public CefMessageRouterBrowserSide::Handler
    {
    public:
        __declspec(dllexport) MessageHandler(
            ICefMessageHandler* cefMessageHandler
        );

        __declspec(dllexport) bool OnQuery(
            CefRefPtr<CefBrowser> browser,
            CefRefPtr<CefFrame> frame,
            int64 query_id,
            const CefString& request,
            bool persistent,
            CefRefPtr<Callback> callback
        ) OVERRIDE;

    private:
        ICefMessageHandler* _cefMessageHandler;

        DISALLOW_COPY_AND_ASSIGN(MessageHandler);
    };
}

using namespace Crymium::Cef;