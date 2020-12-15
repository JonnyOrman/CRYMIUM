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
		CrymiumRendererInitialiser(
			ICrymiumRenderer* crymiumRenderer,
			ICaptureFrameListener* captureFrameListener
		);

		void Initialise() override;

	private:
		ICrymiumRenderer* _crymiumRenderer;
		ICaptureFrameListener* _captureFrameListener;
	};
}

using namespace Crymium::Rendering;