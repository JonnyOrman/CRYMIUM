#pragma once
#include "Crymium/Rendering/Core/IRendererProvider.h"

namespace Crymium::Rendering
{
	class RendererProvider
		:
		public IRendererProvider
	{
	public:
		RendererProvider() = default;

		IRenderer* Get() override;

		int GetRendererWidth() override;

		int GetRendererHeight() override;
	};
}

using namespace Crymium::Rendering;