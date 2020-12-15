#pragma once
#include "Core/IUiDirectoryProvider.h"

namespace Crymium::Uis
{
	class UiDirectoryProvider
		: public IUiDirectoryProvider
	{
	public:
		UiDirectoryProvider(
			std::string uiDirectory
		);

		std::string Get() override;

	private:
		std::string _uiDirectory;
	};
}

