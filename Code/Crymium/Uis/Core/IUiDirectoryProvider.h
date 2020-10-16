#pragma once
#include <string>

namespace Crymium::Uis::Core
{
	struct IUiDirectoryProvider
	{
		virtual ~IUiDirectoryProvider() = default;

		virtual std::string Get() = 0;
	};
}

using namespace Crymium::Uis::Core;