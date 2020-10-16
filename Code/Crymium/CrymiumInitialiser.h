#pragma once
#include "Core/IInitialiser.h"
#include "Cef/Core/ICrymiumCefInitialiser.h"
#include "Cry/Core/ICryInitialiser.h"

namespace Crymium
{
	class CrymiumInitialiser
		:
		public Crymium::Core::ICrymiumInitialiser
	{
	public:
		__declspec(dllexport) CrymiumInitialiser(
			ICrymiumCefInitialiser* crymiumCefInitialiser,
			ICryInitialiser* cryInitialiser
		);

		__declspec(dllexport) void Initialise() override;

	private:
		ICrymiumCefInitialiser* _crymiumCefInitialiser;
		ICryInitialiser* _cryInitialiser;
	};
}

using namespace Crymium;