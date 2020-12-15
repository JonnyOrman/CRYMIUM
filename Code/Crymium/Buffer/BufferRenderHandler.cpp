#include "BufferRenderHandler.h"

BufferRenderHandler::BufferRenderHandler(
    IRendererSettings* rendererSettings,
    ICrymiumCefRectSettings* cefRectSettings,
    IBufferProvider* bufferProvider
)
    : 
	_rendererSettings(rendererSettings),
	_cefRectSettings(cefRectSettings),
	_bufferProvider(std::move(bufferProvider))
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

void BufferRenderHandler::OnPaint(CefRefPtr<CefBrowser> browser, PaintElementType type,
    const RectList& dirtyRects, const void* buffer, int width, int height)
{
    _bufferProvider->Set(buffer);
}