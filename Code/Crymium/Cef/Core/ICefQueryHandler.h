#pragma once

namespace Crymium::Cef::Core
{
	struct ICefQueryHandler
	{
		virtual ~ICefQueryHandler() = default;

		virtual bool CanHandle(const std::string& request) = 0;
		
		virtual void Handle(const std::string& request) = 0;
	};
}

using namespace Crymium::Cef::Core;
