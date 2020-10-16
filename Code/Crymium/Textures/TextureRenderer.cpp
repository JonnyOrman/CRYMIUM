#include "TextureRenderer.h"

TextureRenderer::TextureRenderer(
	ITextureCreator* textureCreator,
	ITextureDrawer* textureDrawer
)
:
_textureCreator(textureCreator),
_textureDrawer(textureDrawer)
{
}

void TextureRenderer::Render()
{
	_textureCreator->Create();

	_textureDrawer->Draw();
}
