#pragma once
#include "Crymium/Rendering/Core/ICrymiumRendererInitialiser.h"
#include "Crymium/Rendering/Core/ICrymiumRenderer.h"

namespace Crymium::Rendering
{
	class CrymiumRendererInitialiser
		:
		public ICrymiumRendererInitialiser
	{
	public:
		__declspec(dllexport) CrymiumRendererInitialiser(
			ICrymiumRenderer* crymiumRenderer,
			ICaptureFrameListener* captureFrameListener
		);

		__declspec(dllexport) void Initialise() override;

	private:
		ICrymiumRenderer* _crymiumRenderer;
		ICaptureFrameListener* _captureFrameListener;
	};
}

using namespace Crymium::Rendering;