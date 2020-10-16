#pragma once
#include <CrySystem/ICryPlugin.h>
#include <CryNetwork/INetwork.h>

namespace Crymium
{
	class CrymiumPlugin
		:
		public Cry::IEnginePlugin
	{
	public:
		CRYINTERFACE_SIMPLE(Cry::IEnginePlugin)
			CRYGENERATE_SINGLETONCLASS_GUID(CrymiumPlugin, "Crymium", "{E2899FF1-A355-4379-8C6E-37474C7EA35C}"_cry_guid)

			virtual ~CrymiumPlugin();

		bool Initialize(SSystemGlobalEnvironment& env, const SSystemInitParams& initParams) override;
	};
}

using namespace Crymium;