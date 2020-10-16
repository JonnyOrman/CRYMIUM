#pragma once
#include "Cry/Core/ICryInitialiser.h"
#include "Inputs/Core/IInputInitialiser.h"
#include "Rendering/Core/ICrymiumRendererInitialiser.h"

namespace Crymium::CryEngine
{
	class CryInitialiser
		: public ICryInitialiser
	{
	public:
		__declspec(dllexport) CryInitialiser(
			ICrymiumRendererInitialiser* crymiumRendererInitialiser,
			IInputInitialiser* inputInitialiser
		);

		__declspec(dllexport) void Initialise() override;

	private:
		ICrymiumRendererInitialiser* _crymiumRendererInitialiser;
		IInputInitialiser* _inputInitialiser;
	};
}

using namespace Crymium::CryEngine;