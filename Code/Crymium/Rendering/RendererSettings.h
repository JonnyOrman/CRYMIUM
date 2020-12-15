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
		RendererSettings(
			IRendererProvider* rendererProvider
		);

		int GetWidth() override;

		int GetHeight() override;

	private:
		IRendererProvider* _rendererProvider;
	};
}

using namespace Crymium;