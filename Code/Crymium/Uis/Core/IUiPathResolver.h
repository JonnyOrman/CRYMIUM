#pragma once
#include <string>

namespace Crymium::Uis::Core
{
	struct IUiPathResolver
	{
		virtual ~IUiPathResolver() = default;

		virtual std::string Resolve(std::string uiName) = 0;
	};
}

using namespace Crymium::Uis::Core;