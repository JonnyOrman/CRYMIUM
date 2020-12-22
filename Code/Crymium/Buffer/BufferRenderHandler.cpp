#include "BufferRenderHandler.h"

BufferRenderHandler::BufferRenderHandler(
    ICrymiumCefRectSettings* cefRectSettings,
    IRendererSettings* rendererSettings,
    IBufferProvider* bufferProvider
)
    :
    _cefRectSettings(cefRectSettings),
	_rendererSettings(rendererSettings),
	_bufferProvider(bufferProvider)
{
}

void BufferRenderHandler::GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect)
{
    rect = CefRect(
        _cefRectSettings->GetX(),
        _cefRectSettings->GetY(),
        _rendererSettings->GetWidth(),
        _rendererSettings->GetHeight()
    );
}

void BufferRenderHandler::OnPaint(
    CefRefPtr<CefBrowser> browser,
    PaintElementType type,
    const RectList& dirtyRects, 
    const void* buffer,
    int width, 
    int height
)
{
    _bufferProvider->Set(buffer);
}