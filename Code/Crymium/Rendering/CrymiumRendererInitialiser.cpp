#include "CrymiumRendererInitialiser.h"

CrymiumRendererInitialiser::CrymiumRendererInitialiser(
	ICrymiumRenderer* crymiumRenderer,
	ICaptureFrameListener* captureFrameListener
)
:
_crymiumRenderer(crymiumRenderer),
_captureFrameListener(captureFrameListener)
{
}

void CrymiumRendererInitialiser::Initialise()
{
	_crymiumRenderer->RegisterCaptureFrame(_captureFrameListener);
}
