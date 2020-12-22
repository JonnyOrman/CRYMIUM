#pragma once
#include "Crymium/Uis/Core/IUiDirectoryProvider.h"

namespace Crymium::Uis
{
	class CryUiDirectoryProvider
		: public IUiDirectoryProvider
	{
	public:
		__declspec(dllexport) CryUiDirectoryProvider() = default;

		__declspec(dllexport) std::string Get() override;
	};
}

