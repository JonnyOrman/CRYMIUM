#include "UiSettings.h"

UiSettings::UiSettings(
	std::string defaultFileName,
	std::string defaultFileType
)
:
_defaultFileName(std::move(defaultFileName)),
_defaultFileType(std::move(defaultFileType))
{
}

std::string UiSettings::GetDefaultFileName()
{
	return _defaultFileName;
}

std::string UiSettings::GetDefaultFileType()
{
	return _defaultFileType;
}