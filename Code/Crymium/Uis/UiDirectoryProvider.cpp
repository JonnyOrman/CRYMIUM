#include "UiDirectoryProvider.h"

UiDirectoryProvider::UiDirectoryProvider(
	std::string uiDirectory
)
:
_uiDirectory(std::move(uiDirectory))
{
}

std::string UiDirectoryProvider::Get()
{
	return _uiDirectory;
}
