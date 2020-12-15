#pragma once
#include "Crymium/Core/IInitialiser.h"
#include "Crymium/Cef/Core/ICrymiumCefInitialiser.h"
#include "Crymium/Cry/Core/ICryInitialiser.h"

namespace Crymium
{
	class CrymiumInitialiser
		:
		public Crymium::Core::ICrymiumInitialiser
	{
	public:
		CrymiumInitialiser(
			ICrymiumCefInitialiser* crymiumCefInitialiser,
			ICryInitialiser* cryInitialiser
		);

		void Initialise() override;

	private:
		ICrymiumCefInitialiser* _crymiumCefInitialiser;
		ICryInitialiser* _cryInitialiser;
	};
}

using namespace Crymium;