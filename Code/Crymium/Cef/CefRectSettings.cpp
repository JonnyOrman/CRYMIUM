#include "CefRectSettings.h"

CrymiumCefRectSettings::CrymiumCefRectSettings(
	int x,
	int y
)
:
x_(x),
y_(y)
{
}

int CrymiumCefRectSettings::GetX()
{
	return x_;
}

int CrymiumCefRectSettings::GetY()
{
	return y_;
}
