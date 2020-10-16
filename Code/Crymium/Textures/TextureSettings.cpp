#include "TextureSettings.h"

TextureSettings::TextureSettings(
	const char* name,
	int numberOfMips,
	int flags,
	ETEX_Format etexFormat,
	IRendererSettings* renderSettings
)
:
_name(name),
_numberOfMips(numberOfMips),
_flags(flags),
_etexFormat(etexFormat),
_renderSettings(renderSettings)
{
}

const char* TextureSettings::GetName()
{
	return _name;
}

int TextureSettings::GetNumberOfMips()
{
	return _numberOfMips;
}

int TextureSettings::GetFlags()
{
	return _flags;
}

ETEX_Format TextureSettings::GetEtexFormat()
{
	return _etexFormat;
}

int TextureSettings::GetWidth()
{
	return _renderSettings->GetWidth();
}

int TextureSettings::GetHeight()
{
	return _renderSettings->GetHeight();
}
