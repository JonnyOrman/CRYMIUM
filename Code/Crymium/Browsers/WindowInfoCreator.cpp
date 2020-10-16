#include "WindowInfoCreator.h"

WindowInfoCreator::WindowInfoCreator(
	ICrymiumRenderer* crymiumRenderer
)
:
_crymiumRenderer(crymiumRenderer)
{
}

std::unique_ptr<CefWindowInfo> WindowInfoCreator::Create()
{
	auto info = std::make_unique<CefWindowInfo>();

	info->SetAsWindowless(HWND(_crymiumRenderer->GetHWND()));

	return info;
}
