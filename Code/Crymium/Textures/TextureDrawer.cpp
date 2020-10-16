#include "TextureDrawer.h"
#include <CryRenderer/IRenderAuxGeom.h>

TextureDrawer::TextureDrawer(
    ITextureProvider* textureProvider
)
:
_textureProvider(textureProvider)
{
}

void TextureDrawer::Draw()
{
    IRenderAuxImage::Draw2dImage(
        0,
        0,
        static_cast<float>(_textureProvider->GetTextureWidth()),
        static_cast<float>(_textureProvider->GetTextureHeight()),
        _textureProvider->GetTextureId(),
        0.0f,
        1.0f,
        1.0f,
        0.0f,
        0.0f,
        1,
        1,
        1,
        1.0f,
        1
    );
}
