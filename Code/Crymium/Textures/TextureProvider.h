#pragma once
#include "Crymium/Textures/Core/ITextureProvider.h"

namespace Crymium::Textures
{
	class TextureProvider
		:
		public ITextureProvider
	{
	public:
		__declspec(dllexport) TextureProvider();

		__declspec(dllexport) void Set(ITexture* texture) override;

		__declspec(dllexport) int GetTextureId() override;

		__declspec(dllexport) int GetTextureWidth() override;

		__declspec(dllexport) int GetTextureHeight() override;

		__declspec(dllexport) bool TextureExists() override;

	private:
		ITexture* _texture;
		int _defaultValue;
	};
}

using namespace Crymium::Textures;