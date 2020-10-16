#include "TextureProvider.h"

TextureProvider::TextureProvider()
	:
_texture(nullptr),
_defaultValue(-1)
{
}

void TextureProvider::Set(ITexture* texture)
{
	_texture = texture;
}

int TextureProvider::GetTextureId()
{
	if (TextureExists())
	{
		return _texture->GetTextureID();
	}

	return _defaultValue;
}

int TextureProvider::GetTextureWidth()
{
	if (TextureExists())
	{
		return _texture->GetWidth();
	}

	return _defaultValue;
}

int TextureProvider::GetTextureHeight()
{
	if (TextureExists())
	{
		return _texture->GetHeight();
	}

	return _defaultValue;
}

bool TextureProvider::TextureExists()
{
	return _texture;
}
