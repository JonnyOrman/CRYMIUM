#pragma once
#include <string>

namespace Crymium::Uis::Core
{
	struct IUiSettings
	{
		virtual ~IUiSettings() = default;

		virtual std::string GetDefaultFileName() = 0;

		virtual std::string GetDefaultFileType() = 0;
	};
}

using namespace Crymium::Uis::Core;