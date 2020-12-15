#pragma once
#include "Crymium/Inputs/Core/IInputInitialiser.h"
#include <CryInput/IInput.h>

namespace Crymium::Inputs::Core
{
	class InputInitialiser
		: public IInputInitialiser
	{
	public:
		InputInitialiser(
			IInputEventListener* inputEventListener
		);

		void Initialise() override;

	private:
		IInputEventListener* _inputEventListener;
	};
}

using namespace Crymium::Inputs::Core;