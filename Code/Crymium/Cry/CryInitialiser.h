#pragma once
#include "Crymium/Cry/Core/ICryInitialiser.h"
#include "Crymium/Inputs/Core/IInputInitialiser.h"
#include "Crymium/Rendering/Core/ICrymiumRendererInitialiser.h"

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