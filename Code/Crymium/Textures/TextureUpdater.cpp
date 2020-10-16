#include "TextureUpdater.h"

TextureUpdater::TextureUpdater(
    ITextureRemover* textureRemover,
    ITextureRenderer* textureRenderer
)
:
_textureRemover(textureRemover),
_textureRenderer(textureRenderer)
{
}

void TextureUpdater::UpdateTexture()
{
    _textureRemover->Remove();

    _textureRenderer->Render();
}