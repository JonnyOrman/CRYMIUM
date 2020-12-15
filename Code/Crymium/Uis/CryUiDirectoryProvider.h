#pragma once
#include "Core/IUiDirectoryProvider.h"

namespace Crymium::Uis
{
	class CryUiDirectoryProvider
		: public IUiDirectoryProvider
	{
	public:
		CryUiDirectoryProvider() = default;

		std::string Get() override;
	};
}

