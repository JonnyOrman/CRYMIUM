#include "CryUiDirectoryProvider.h"
#include <CrySystem/IProjectManager.h>

std::string Crymium::Uis::CryUiDirectoryProvider::Get()
{
	return std::string(gEnv->pSystem->GetIProjectManager()->GetCurrentAssetDirectoryAbsolute()) + "/UIs";
}
