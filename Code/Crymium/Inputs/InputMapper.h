#pragma once
#include "Inputs/Core/IInputStateMapper.h"
#include "Inputs/Core/IKeyIdMapper.h"
#include "Inputs/Core/IInputMapper.h"

namespace Crymium::Inputs::Core
{
	class InputMapper
		: public IInputMapper
	{
	public:
		__declspec(dllexport) InputMapper(
			IKeyIdMapper* keyIdMapper,
			IInputStateMapper* inputStateMapper
		);

		__declspec(dllexport) CefKeyEvent Map(const SInputEvent& inputEvent) override;

	private:
		IKeyIdMapper* _keyIdMapper;
		IInputStateMapper* _inputStateMapper;
	};
}

using namespace Crymium::Inputs::Core;