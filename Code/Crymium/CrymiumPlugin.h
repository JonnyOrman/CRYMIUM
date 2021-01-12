#pragma once
#include <CrySystem/ICryPlugin.h>
#include <CryNetwork/INetwork.h>
#include "Core/ICrymiumContainer.h"
#include "Core/ICrymiumPlugin.h"

namespace Crymium
{
	class CrymiumPlugin final
		: public ICrymiumPlugin
	{
		CRYINTERFACE_BEGIN()
		CRYINTERFACE_ADD(CrymiumPlugin)
		CRYINTERFACE_ADD(Cry::IEnginePlugin)
		CRYINTERFACE_END()
		
		CRYGENERATE_SINGLETONCLASS_GUID(Crymium::CrymiumPlugin, "Crymium", "{E2899FF1-A355-4379-8C6E-37474C7EA35C}"_cry_guid)
	
		virtual ~CrymiumPlugin();
		
		bool Initialize(SSystemGlobalEnvironment& env, const SSystemInitParams& initParams) override;

		void OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam) override;
		
		__declspec(dllexport) ICrymiumContainer* GetCrymiumContainer() override;
		
	private:
		std::unique_ptr<ICrymiumContainer> _crymiumContainer;
	};
}

using namespace Crymium;