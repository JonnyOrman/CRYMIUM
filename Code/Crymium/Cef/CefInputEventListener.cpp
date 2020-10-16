#include "CefInputEventListener.h"

CefInputEventListener::CefInputEventListener(
	ICrymiumContainer* crymiumContainer
)
:
_crymiumContainer(crymiumContainer)
{
}

bool CefInputEventListener::OnInputEvent(const SInputEvent& event)
{
	if (event.state != eIS_Changed && event.state != eIS_Down)
	{
		_crymiumContainer->GetBrowser()->SendInputEvent(event);
	}
	
	return false;
}
