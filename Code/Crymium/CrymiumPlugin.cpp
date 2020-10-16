#include "StdAfx.h"
#include "CrymiumPlugin.h"
#include <CryCore/Platform/platform_impl.inl>

CrymiumPlugin::~CrymiumPlugin()
{
}

bool CrymiumPlugin::Initialize(SSystemGlobalEnvironment& env, const SSystemInitParams& initParams)
{
	return true;
}

CRYREGISTER_SINGLETON_CLASS(CrymiumPlugin)