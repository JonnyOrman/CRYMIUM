#pragma once
#include "Crymium/Browsers/Core/IWindowInfoCreator.h"
#include "Crymium/Rendering/Core/ICrymiumRenderer.h"

namespace Crymium::Browsers
{
	class WindowInfoCreator
		: public IWindowInfoCreator
	{
	public:
		WindowInfoCreator(
			ICrymiumRenderer* crymiumRenderer
		);

		std::unique_ptr<CefWindowInfo> Create() override;

	private:
		ICrymiumRenderer* _crymiumRenderer;
	};
}

using namespace Crymium::Browsers;