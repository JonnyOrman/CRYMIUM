#pragma once
#include <include/cef_render_handler.h>
#include "include/cef_app.h"
#include "Crymium/Rendering/Core/IRendererSettings.h"
#include "Crymium/Cef/Core/ICefRectSettings.h"
#include "Crymium/Buffer/Core/IBufferProvider.h"

namespace Crymium::Buffer
{
    class BufferRenderHandler : public CefRenderHandler
    {
    public:
        BufferRenderHandler(
            IRendererSettings* rendererSettings,
            ICrymiumCefRectSettings* cefRectSettings,
            IBufferProvider* bufferProvider
        );

        void GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect) override;

        void OnPaint(CefRefPtr<CefBrowser> browser, PaintElementType type, const RectList& dirtyRects,
            const void* buffer, int width, int height) override;

    private:
        IRendererSettings* _rendererSettings;
        ICrymiumCefRectSettings* _cefRectSettings;
        IBufferProvider* _bufferProvider;

    public:
        IMPLEMENT_REFCOUNTING(BufferRenderHandler);
    };
}

using namespace Crymium::Buffer;