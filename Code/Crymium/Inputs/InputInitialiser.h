#pragma once
#include "Inputs/Core/IInputInitialiser.h"
#include <CryInput/IInput.h>

namespace Crymium::Inputs::Core
{
	class InputInitialiser
		: public IInputInitialiser
	{
	public:
		__declspec(dllexport) InputInitialiser(
			IInputEventListener* inputEventListener
		);

		__declspec(dllexport) void Initialise() override;

	private:
		IInputEventListener* _inputEventListener;
	};
}

using namespace Crymium::Inputs::Core;