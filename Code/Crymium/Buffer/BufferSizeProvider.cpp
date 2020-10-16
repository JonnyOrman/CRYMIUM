#include "BufferSizeProvider.h"

BufferSizeProvider::BufferSizeProvider(
	IRendererSettings* rendererSettings,
	IBufferSettings* bufferSettings
)
:
_rendererSettings(rendererSettings),
_bufferSettings(bufferSettings)
{
}

int BufferSizeProvider::Get()
{
	return _rendererSettings->GetWidth() * _rendererSettings->GetHeight() * _bufferSettings->GetSizeMultiplier();
}
