#include "CefMessageHandler.h"

CefMessageHandler::CefMessageHandler(
	std::vector<ICefQueryHandler*> cefQueryHandlers
)
:
	_cefQueryHandlers(std::move(cefQueryHandlers))
{
}

void CefMessageHandler::Handle(const std::string& request)
{
	for(auto cefQueryHandler : _cefQueryHandlers)
	{
		if(cefQueryHandler->CanHandle(request))
		{
			cefQueryHandler->Handle(request);
		}
	}
}

void CefMessageHandler::AddCefQueryHandler(ICefQueryHandler* cefQueryHandler)
{
	_cefQueryHandlers.push_back(cefQueryHandler);
}