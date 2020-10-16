#include "CefInitialiser.h"
#include "CrymiumCefApp.h"

CrymiumCefAppInitialiser::CrymiumCefAppInitialiser(
    ICrymiumCefSettingsCreator* crymiumCefSettingsCreator,
    ICrymiumCefMainArgsCreator* crymiumCefMainArgsCreator,
    ICrymiumSandboxInfoCreator* crymiumSandboxInfoCreator
)
:
    _crymiumCefSettingsCreator(crymiumCefSettingsCreator),
	_cymiumCefMainArgsCreator(crymiumCefMainArgsCreator),
    _crymiumSandboxInfoCreator(crymiumSandboxInfoCreator)
{
}

void CrymiumCefAppInitialiser::Initialise()
{
    CefEnableHighDPISupport();
	
    auto settings = _crymiumCefSettingsCreator->Create();

    auto mainArgs = _cymiumCefMainArgsCreator->Create();

    auto sandboxInfo = _crymiumSandboxInfoCreator->Create();
	
    CefRefPtr<CefApp> app = new CrymiumCefApp();

    CefExecuteProcess(
        *mainArgs, 
        app, 
        sandboxInfo
    );
	
    CefInitialize(
        *mainArgs,
        settings, 
        app,
        sandboxInfo
    );
}