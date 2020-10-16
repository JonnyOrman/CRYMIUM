#pragma once
#include <include/cef_render_handler.h>
#include "include/cef_app.h"
#include "Rendering/Core/IRendererSettings.h"
#include "Cef/Core/ICefRectSettings.h"
#include "Buffer/Core/IBufferProvider.h"

namespace Crymium::Buffer
{
    class BufferRenderHandler : public CefRenderHandler
    {
    public:
        __declspec(dllexport) BufferRenderHandler(
            ICrymiumCefRectSettings* cefRectSettings,
            IRendererSettings* rendererSettings,
            IBufferProvider* bufferProvider
        );

        __declspec(dllexport) void GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect) override;

        __declspec(dllexport) void OnPaint(
            CefRefPtr<CefBrowser> browser, 
            PaintElementType type, 
            const RectList& dirtyRects,
            const void* buffer,
            int width,
            int height
        ) override;

    private:
        ICrymiumCefRectSettings* _cefRectSettings;
        IRendererSettings* _rendererSettings;
        IBufferProvider* _bufferProvider;

    public:
        IMPLEMENT_REFCOUNTING(BufferRenderHandler);
    };
}

using namespace Crymium::Buffer;