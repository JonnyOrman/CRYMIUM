#pragma once
#include <CryInput/IInput.h>
#include <include/internal/cef_types_wrappers.h>

namespace Crymium::Inputs::Core
{
	struct IInputMapper
	{
		virtual ~IInputMapper() = default;

		virtual CefKeyEvent Map(const SInputEvent& inputEvent) = 0;
	};
}

using namespace Crymium::Inputs::Core;