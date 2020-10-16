#include "CefCaptureFrameListener.h"
#include "include/cef_app.h"

CrymiumCefCaptureFrameListener::CrymiumCefCaptureFrameListener(
    ITextureUpdater* textureUpdater
)
:
	_textureUpdater(textureUpdater)
{
}

bool CrymiumCefCaptureFrameListener::OnNeedFrameData(unsigned char*& pConvertedTextureBuf)
{
	return true;
}

void CrymiumCefCaptureFrameListener::OnFrameCaptured()
{
    _textureUpdater->UpdateTexture();
}

int CrymiumCefCaptureFrameListener::OnGetFrameWidth()
{
	return 0;
}

int CrymiumCefCaptureFrameListener::OnGetFrameHeight()
{
	return 0;
}

int CrymiumCefCaptureFrameListener::OnCaptureFrameBegin(int* pTexHandle)
{
    CefDoMessageLoopWork();
	
	return 1;
}
