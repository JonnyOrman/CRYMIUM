#pragma once
#include "Crymium/Uis/Core/IUiSettings.h"
#include "Crymium/Uis/Core/IUiPathResolver.h"
#include "Crymium/Uis/Core/IUiDirectoryProvider.h"

namespace Crymium::Uis
{
	class UiPathResolver
		: public IUiPathResolver
	{
	public:
		UiPathResolver(
			IUiSettings* uiSettings,
			IUiDirectoryProvider* uiDirectoryProvider
		);

		std::string Resolve(std::string uiName) override;

	private:
		IUiSettings* _uiSettings;
		IUiDirectoryProvider* _uiDirectoryProvider;
	};
}

using namespace Crymium::Uis;