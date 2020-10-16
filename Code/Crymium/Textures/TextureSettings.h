#pragma once
#include "Textures/Core/ITextureSettings.h"
#include "Rendering/Core/IRendererSettings.h"

namespace Crymium::Textures
{
	class TextureSettings
		:
		public ITextureSettings
	{
	public:
		__declspec(dllexport) TextureSettings(
			const char* name,
			int numberOfMips,
			int flags,
			ETEX_Format etexFormat,
			IRendererSettings* renderSettings
		);

		__declspec(dllexport) const char* GetName() override;

		__declspec(dllexport) int GetNumberOfMips() override;

		__declspec(dllexport) int GetFlags() override;

		__declspec(dllexport) ETEX_Format GetEtexFormat() override;

		__declspec(dllexport) int GetWidth() override;

		__declspec(dllexport) int GetHeight() override;
		
	private:
		const char* _name;
		int _numberOfMips;
		int _flags;
		ETEX_Format _etexFormat;
		IRendererSettings* _renderSettings;
	};
}

using namespace Crymium::Textures;