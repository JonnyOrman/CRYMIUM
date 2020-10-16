#include "TextureCreator.h"

TextureCreator::TextureCreator(
    ITextureSettings* textureSettings,
    IBufferProvider* bufferProvider,
    ITextureProvider* textureProvider,
    ICrymiumRenderer* crymiumRenderer
)
:
_textureSettings(textureSettings),
_bufferProvider(bufferProvider),
_textureProvider(textureProvider),
_crymiumRenderer(crymiumRenderer)
{
}

void TextureCreator::Create()
{
	auto texture = _crymiumRenderer->CreateTexture(
        _textureSettings->GetName(),
        _textureSettings->GetWidth(),
        _textureSettings->GetHeight(),
        _textureSettings->GetNumberOfMips(),
        _bufferProvider->Get(),
        _textureSettings->GetEtexFormat(),
        _textureSettings->GetFlags()
    );

    _textureProvider->Set(texture);
}
