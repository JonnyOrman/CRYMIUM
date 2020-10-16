#pragma once
#include "Textures/Core/ITextureProvider.h"
#include "Textures/Core/ITextureCreator.h"
#include "Buffer/Core/IBufferProvider.h"
#include "Textures/Core/ITextureSettings.h"
#include "Rendering/Core/ICrymiumRenderer.h"

namespace Crymium::Textures
{
	class TextureCreator
		:
		public ITextureCreator
	{
	public:
		__declspec(dllexport) TextureCreator(
			ITextureSettings* textureSettings,
			IBufferProvider* bufferProvider,
			ITextureProvider* textureProvider,
			ICrymiumRenderer* crymiumRenderer
		);

		__declspec(dllexport) void Create() override;

	private:
		ITextureSettings* _textureSettings;
		IBufferProvider* _bufferProvider;
		ITextureProvider* _textureProvider;
		ICrymiumRenderer* _crymiumRenderer;
	};
}

using namespace Crymium::Textures;