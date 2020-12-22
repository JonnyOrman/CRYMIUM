#pragma once
#include "Crymium/Rendering/Core/IRendererSettings.h"
#include "Crymium/Rendering/Core/IRendererProvider.h"

namespace Crymium
{
	class RendererSettings
		:
		public IRendererSettings
	{
	public:
		__declspec(dllexport) RendererSettings(
			IRendererProvider* rendererProvider
		);

		__declspec(dllexport) int GetWidth() override;

		__declspec(dllexport) int GetHeight() override;

	private:
		IRendererProvider* _rendererProvider;
	};
}

using namespace Crymium;