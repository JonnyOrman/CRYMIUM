#include <string>
#include "include/base/cef_logging.h"
#include "include/cef_v8.h"
#include "include/wrapper/cef_stream_resource_handler.h"
#include "ClientAppRenderer.h"

namespace Crymium::SubProcess::Renderer
{
    class V8Handler
        : public CefV8Handler
    {
    public:
        V8Handler() = default;

        bool Execute(
            const CefString& name,
            CefRefPtr<CefV8Value> object,
            const CefV8ValueList& arguments,
            CefRefPtr<CefV8Value>& retval,
            CefString& exception
        ) OVERRIDE;

    private:
        IMPLEMENT_REFCOUNTING(V8Handler);
    };
}

using namespace Crymium::SubProcess::Renderer;