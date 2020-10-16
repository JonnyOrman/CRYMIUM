#pragma once

namespace Crymium::Inputs::Core
{
	struct IInputInitialiser
	{
		virtual ~IInputInitialiser() = default;

		virtual void Initialise() = 0;
	};
}

using namespace Crymium::Inputs::Core;