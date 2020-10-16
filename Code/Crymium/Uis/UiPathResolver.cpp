#include "UiPathResolver.h"

UiPathResolver::UiPathResolver(
	IUiSettings* uiSettings,
	IUiDirectoryProvider* uiDirectoryProvider
)
:
_uiSettings(uiSettings),
_uiDirectoryProvider(uiDirectoryProvider)
{
}

std::string UiPathResolver::Resolve(std::string uiName)
{
	auto path = _uiDirectoryProvider->Get()
	+ "/"
	+ uiName
	+ "/"
	+ _uiSettings->GetDefaultFileName()
	+ "."
	+ _uiSettings->GetDefaultFileType();

	return path;
}
