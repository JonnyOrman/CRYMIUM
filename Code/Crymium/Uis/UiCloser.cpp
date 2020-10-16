#include "UiCloser.h"

UiCloser::UiCloser(
	IBrowser* browser

)
:
_browser(browser)
{
}

void UiCloser::Close()
{
	_browser->GoTo("None");
}