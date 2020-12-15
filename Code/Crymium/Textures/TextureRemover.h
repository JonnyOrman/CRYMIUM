#pragma once
#include "Crymium/Textures/Core/ITextureProvider.h"
#include "Crymium/Textures/Core/ITextureRemover.h"
#include "Crymium/Rendering/Core/ICrymiumRenderer.h"

namespace Crymium::Textures
{
	class TextureRemover
		:
		public ITextureRemover
	{
	public:
		TextureRemover(
			ITextureProvider* textureProvider,
			ICrymiumRenderer* crymiumRenderer
		);

		void Remove() override;

	private:
		ITextureProvider* _textureProvider;
		ICrymiumRenderer* _crymiumRenderer;
	};
}

using namespace Crymium::Textures;