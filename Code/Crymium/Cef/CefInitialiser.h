#pragma once
#include "Crymium/Cef/Core/ICrymiumSandboxInfoCreator.h"
#include "Crymium/Cef/Core/ICrymiumCefMainArgsCreator.h"
#include "Crymium/Cef/Core/ICrymiumCefSettingsCreator.h"
#include "Crymium/Cef/Core/ICefInitialiser.h"

namespace Crymium::Cef
{
	class CrymiumCefAppInitialiser
		: public ICrymiumCefAppInitialiser
	{
	public:
		CrymiumCefAppInitialiser(
			ICrymiumCefSettingsCreator* crymiumCefSettingsCreator,
			ICrymiumCefMainArgsCreator* crymiumCefMainArgsCreator,
			ICrymiumSandboxInfoCreator* crymiumSandboxInfoCreator
		);

		void Initialise() override;

	private:
		ICrymiumCefSettingsCreator* _crymiumCefSettingsCreator;
		ICrymiumCefMainArgsCreator* _cymiumCefMainArgsCreator;
		ICrymiumSandboxInfoCreator* _crymiumSandboxInfoCreator;
	};
}

using namespace Crymium::Cef;