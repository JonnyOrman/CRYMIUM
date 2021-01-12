#pragma once
#include <CrySystem/ICryPlugin.h>
#include "ICrymiumContainer.h"

namespace Crymium::Core
{
	class ICrymiumPlugin
		: public Cry::IEnginePlugin
		, public ISystemEventListener
	{
	public:
		CRYINTERFACE_DECLARE_GUID(ICrymiumPlugin, "{D1CE115F-F1E8-42A1-8C31-B17EE387DE14}"_cry_guid);

		virtual ~ICrymiumPlugin() { };

		virtual ICrymiumContainer* GetCrymiumContainer() = 0;
	};
}

using namespace Crymium::Core;