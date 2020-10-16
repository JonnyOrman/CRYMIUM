#include "RendererProvider.h"

IRenderer* RendererProvider::Get()
{
	return gEnv->pRenderer;
}

int RendererProvider::GetRendererWidth()
{
	return Get()->GetWidth();
}

int RendererProvider::GetRendererHeight()
{
	return Get()->GetHeight();
}
