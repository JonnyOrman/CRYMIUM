#include "StdAfx.h"
#include "CrymiumPlugin.h"
#include <CryCore/Platform/platform_impl.inl>
#include "CrymiumContainerComposer.h"

CrymiumPlugin::~CrymiumPlugin()
{
	gEnv->pSystem->GetISystemEventDispatcher()->RemoveListener(this);
}

bool CrymiumPlugin::Initialize(SSystemGlobalEnvironment& env, const SSystemInitParams& initParams)
{
	gEnv->pSystem->GetISystemEventDispatcher()->RegisterListener(this, "Crymium");

	_crymiumContainer = CrymiumContainerComposer::Compose();
	
	return true;
}

void CrymiumPlugin::OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam)
{
	switch (event)
	{
	case ESYSTEM_EVENT_GAME_POST_INIT:
	{
		_crymiumContainer->GetCrymiumInitialiser()->Initialise();
	}
	break;
	}
}

ICrymiumContainer* CrymiumPlugin::GetCrymiumContainer()
{
	return _crymiumContainer.get();
}

CRYREGISTER_SINGLETON_CLASS(CrymiumPlugin)