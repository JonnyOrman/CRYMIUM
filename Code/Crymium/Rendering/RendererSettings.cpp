#include "RendererSettings.h"

RendererSettings::RendererSettings(
	IRendererProvider* rendererProvider
)
:
_rendererProvider(rendererProvider)
{
}

int RendererSettings::GetWidth()
{
	return _rendererProvider->GetRendererWidth();
}

int RendererSettings::GetHeight()
{
	return _rendererProvider->GetRendererHeight();
}
