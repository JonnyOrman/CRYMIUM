#pragma once
#include "include/cef_frame.h"
#include "include/cef_v8.h"
#include "include/wrapper/cef_message_router.h"

namespace Crymium::SubProcess::Renderer
{
    struct IDelegate
    {
        virtual ~IDelegate() = default;

        virtual void OnWebKitInitialized() = 0;

        virtual void OnContextCreated(
            const scoped_refptr<CefBrowser>& browser,
            const scoped_refptr<CefFrame>& frame,
            const scoped_refptr<CefV8Context>& context) = 0;

        virtual void OnContextReleased(
            const scoped_refptr<CefBrowser>& browser,
            const scoped_refptr<CefFrame>& frame,
            const scoped_refptr<CefV8Context>& context) = 0;

        virtual bool OnProcessMessageReceived(
            const scoped_refptr<CefBrowser>& browser,
            const scoped_refptr<CefFrame>& frame,
            CefProcessId sourceProcess,
            const scoped_refptr<CefProcessMessage>& message) = 0;
    };
}

using namespace Crymium::SubProcess::Renderer;