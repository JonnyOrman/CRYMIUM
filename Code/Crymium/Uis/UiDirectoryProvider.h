#pragma once
#include "Crymium/Uis/Core/IUiDirectoryProvider.h"

namespace Crymium::Uis
{
	class UiDirectoryProvider
		: public IUiDirectoryProvider
	{
	public:
		__declspec(dllexport) UiDirectoryProvider(
			std::string uiDirectory
		);

		__declspec(dllexport) std::string Get() override;

	private:
		std::string _uiDirectory;
	};
}

