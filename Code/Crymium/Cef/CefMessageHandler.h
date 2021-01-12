#pragma once
#include "Core/ICefQueryHandler.h"
#include "Crymium/Cef/Core/ICefMessageHandler.h"

namespace Crymium::Cef
{
	class CefMessageHandler
		:
		public ICefMessageHandler
	{
	public:
		__declspec(dllexport) CefMessageHandler(
			std::vector<ICefQueryHandler*> cefQueryHandlers
		);
		
		__declspec(dllexport) void Handle(const std::string& request) override;

		__declspec(dllexport) void AddCefQueryHandler(ICefQueryHandler* cefQueryHandler) override;
	
	private:
		std::vector<ICefQueryHandler*> _cefQueryHandlers;
	};
}

using namespace Crymium::Cef;