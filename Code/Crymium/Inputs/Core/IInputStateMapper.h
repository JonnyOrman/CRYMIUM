#pragma once
#include <CryInput/IInput.h>
#include <include/internal/cef_types_wrappers.h>

namespace Crymium::Inputs::Core
{
	struct IInputStateMapper
	{
		virtual ~IInputStateMapper() = default;

		virtual cef_key_event_type_t Map(EInputState inputState) = 0;
	};
}

using namespace Crymium::Inputs::Core;