#include "TextureRemover.h"

TextureRemover::TextureRemover(
	ITextureProvider* textureProvider,
    ICrymiumRenderer* crymiumRenderer
)
:
_textureProvider(textureProvider),
_crymiumRenderer(crymiumRenderer)
{
}

void TextureRemover::Remove()
{
    if (_textureProvider->TextureExists())
    {
        _crymiumRenderer->RemoveTexture(_textureProvider->GetTextureId());
    }
}
