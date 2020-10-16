#pragma once

namespace Crymium::Uis::Core
{
	struct IUiActivator
	{
		virtual ~IUiActivator() = default;

		virtual void Activate(const char* uiName) = 0;
	};
}

using namespace Crymium::Uis::Core;