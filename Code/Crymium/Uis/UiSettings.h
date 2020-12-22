#pragma once
#include "Crymium/Uis/Core/IUiSettings.h"

namespace Crymium::Uis
{
	class UiSettings
		: public IUiSettings
	{
	public:
		__declspec(dllexport) UiSettings(
			std::string defaultFileName,
			std::string defaultFileType
		);

		__declspec(dllexport) std::string GetDefaultFileName() override;

		__declspec(dllexport) std::string GetDefaultFileType() override;
		
	private:
		std::string _defaultFileName;
		std::string _defaultFileType;
	};
}

using namespace Crymium::Uis;