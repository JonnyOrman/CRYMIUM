#pragma once
#include <string>
#include "ICefQueryHandler.h"

namespace Crymium::Cef::Core
{
	struct ICefMessageHandler
	{
		virtual ~ICefMessageHandler() = default;

		virtual void Handle(const std::string& request) = 0;

		virtual void AddCefQueryHandler(ICefQueryHandler* cefQueryHandler) = 0;
	};
}

using namespace Crymium::Cef::Core;
