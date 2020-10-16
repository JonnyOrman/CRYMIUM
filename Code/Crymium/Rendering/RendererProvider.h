#pragma once
#include "Rendering/Core/IRendererProvider.h"

namespace Crymium::Rendering
{
	class RendererProvider
		:
		public IRendererProvider
	{
	public:
		__declspec(dllexport) RendererProvider() = default;

		__declspec(dllexport) IRenderer* Get() override;

		__declspec(dllexport) int GetRendererWidth() override;

		__declspec(dllexport) int GetRendererHeight() override;
	};
}

using namespace Crymium::Rendering;