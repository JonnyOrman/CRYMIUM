#pragma once
#include <string>

namespace Crymium::Cef::Core
{
	struct ICefMessageHandler
	{
		virtual ~ICefMessageHandler() = default;

		virtual void Handle(std::string request) = 0;
	};
}

using namespace Crymium::Cef::Core;
