#pragma once
#include "Crymium/Cry/Core/ICryInitialiser.h"
#include "Inputs/Core/IInputInitialiser.h"
#include "Rendering/Core/ICrymiumRendererInitialiser.h"

namespace Crymium::CryEngine
{
	class CryInitialiser
		: public ICryInitialiser
	{
	public:
		CryInitialiser(
			ICrymiumRendererInitialiser* crymiumRendererInitialiser,
			IInputInitialiser* crymiumInputInitialiser
		);

		void Initialise() override;

	private:
		ICrymiumRendererInitialiser* _crymiumRendererInitialiser;
		IInputInitialiser* _crymiumInputInitialiser;
	};
}

using namespace Crymium::CryEngine;