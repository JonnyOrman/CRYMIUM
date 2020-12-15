#pragma once
#include "Crymium/Textures/Core/ITextureProvider.h"
#include "Crymium/Textures/Core/ITextureCreator.h"
#include "Crymium/Buffer/Core/IBufferProvider.h"
#include "Crymium/Textures/Core/ITextureSettings.h"
#include "Crymium/Rendering/Core/ICrymiumRenderer.h"

namespace Crymium::Textures
{
	class TextureCreator
		:
		public ITextureCreator
	{
	public:
		TextureCreator(
			ITextureSettings* textureSettings,
			IBufferProvider* bufferProvider,
			ITextureProvider* textureProvider,
			ICrymiumRenderer* crymiumRenderer
		);

		void Create() override;

	private:
		ITextureSettings* _textureSettings;
		IBufferProvider* _bufferProvider;
		ITextureProvider* _textureProvider;
		ICrymiumRenderer* _crymiumRenderer;
	};
}

using namespace Crymium::Textures;