#include "UiDirectoryProvider.h"

UiDirectoryProvider::UiDirectoryProvider(
	std::string uiDirectory
)
:
_uiDirectory(uiDirectory)
{
}

std::string UiDirectoryProvider::Get()
{
	return _uiDirectory;
}
