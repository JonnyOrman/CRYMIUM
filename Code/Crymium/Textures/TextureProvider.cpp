#include "TextureProvider.h"

void TextureProvider::Set(ITexture* texture)
{
	_texture = texture;
}

int TextureProvider::GetTextureId()
{
	return _texture->GetTextureID();
}

int TextureProvider::GetTextureWidth()
{
	return _texture->GetWidth();
}

int TextureProvider::GetTextureHeight()
{
	return _texture->GetHeight();
}

bool TextureProvider::TextureExists()
{
	return _texture;
}
