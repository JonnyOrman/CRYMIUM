#pragma once
#include "Crymium/Textures/Core/ITextureSettings.h"
#include "Crymium/Rendering/Core/IRendererSettings.h"

namespace Crymium::Textures
{
	class TextureSettings
		:
		public ITextureSettings
	{
	public:
		TextureSettings(
			const char* name,
			int numberOfMips,
			int flags,
			ETEX_Format etexFormat,
			IRendererSettings* renderSettings
		);

		const char* GetName() override;

		int GetNumberOfMips() override;

		int GetFlags() override;

		ETEX_Format GetEtexFormat() override;

		int GetWidth() override;

		int GetHeight() override;
		
	private:
		const char* _name;
		int _numberOfMips;
		int _flags;
		ETEX_Format _etexFormat;
		IRendererSettings* _renderSettings;
	};
}

using namespace Crymium::Textures;