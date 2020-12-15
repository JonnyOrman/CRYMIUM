#pragma once
#include "Crymium/Inputs/Core/IInputStateMapper.h"

namespace Crymium::Inputs::Core
{
	class InputStateMapper
		: public IInputStateMapper
	{
	public:
		InputStateMapper() = default;

		cef_key_event_type_t Map(EInputState inputState) override;
	};
}

using namespace Crymium::Inputs::Core;