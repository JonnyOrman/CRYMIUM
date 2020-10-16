#pragma once
#include "Inputs/Core/IInputStateMapper.h"

namespace Crymium::Inputs::Core
{
	class InputStateMapper
		: public IInputStateMapper
	{
	public:
		__declspec(dllexport) InputStateMapper() = default;

		__declspec(dllexport) cef_key_event_type_t Map(EInputState inputState) override;
	};
}

using namespace Crymium::Inputs::Core;