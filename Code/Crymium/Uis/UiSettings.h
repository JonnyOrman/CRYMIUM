#pragma once
#include "Crymium/Uis/Core/IUiSettings.h"

namespace Crymium::Uis
{
	class UiSettings
		: public IUiSettings
	{
	public:
		UiSettings(
			std::string defaultFileName,
			std::string defaultFileType
		);

		std::string GetDefaultFileName() override;

		std::string GetDefaultFileType() override;
		
	private:
		std::string _defaultFileName;
		std::string _defaultFileType;
	};
}

using namespace Crymium::Uis;