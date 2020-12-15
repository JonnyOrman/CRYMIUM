#pragma once
#include "Crymium/Inputs/Core/IInputStateMapper.h"
#include "Crymium/Inputs/Core/IKeyIdMapper.h"
#include "Crymium/Inputs/Core/IInputMapper.h"

namespace Crymium::Inputs::Core
{
	class InputMapper
		: public IInputMapper
	{
	public:
		InputMapper(
			IKeyIdMapper* keyIdMapper,
			IInputStateMapper* inputStateMapper
		);

		CefKeyEvent Map(const SInputEvent& inputEvent) override;

	private:
		IKeyIdMapper* _keyIdMapper;
		IInputStateMapper* _inputStateMapper;
	};
}

using namespace Crymium::Inputs::Core;