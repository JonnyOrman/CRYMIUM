#include "CrymiumCefMainArgsCreator.h"

std::unique_ptr<CefMainArgs> CrymiumCefMainArgsCreator::Create()
{
	auto cefMainArgs = std::make_unique<CefMainArgs>();

	return cefMainArgs;
}
