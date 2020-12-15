#include "CrymiumRenderer.h"

ITexture* CrymiumRenderer::CreateTexture(
	const char* name,
	int width, 
	int height,
	int numberOfMips,
	unsigned char* data,
	ETEX_Format etexFormat, 
	int flags
)
{
	return gEnv->pRenderer->CreateTexture(
		name,
		width,
		height,
		numberOfMips,
		data,
		etexFormat,
		flags
	);
}

CRY_HWND CrymiumRenderer::GetHWND()
{
	return gEnv->pRenderer->GetHWND();
}

void CrymiumRenderer::RegisterCaptureFrame(ICaptureFrameListener* captureFrameListener)
{
	gEnv->pRenderer->RegisterCaptureFrame(captureFrameListener);
}

void CrymiumRenderer::RemoveTexture(int textureId)
{
	//have to do this twice or memory spikes for some reason (texture not removed?)
	//TODO - find out why this happens
	gEnv->pRenderer->RemoveTexture(textureId);
	gEnv->pRenderer->RemoveTexture(textureId);
}
