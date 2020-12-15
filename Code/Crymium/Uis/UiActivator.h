#pragma once
#include "Crymium/Uis/Core/IUiPathResolver.h"
#include "Crymium/Browsers/Core/IBrowser.h"
#include "Crymium/Uis/Core/IUiActivator.h"

namespace Crymium::Uis
{
	class UiActivator
		: public IUiActivator
	{
	public:
		UiActivator(
			IUiPathResolver* uiPathResolver,
			IBrowser* browser
		);

		void Activate(const char* uiName) override;

	private:
		IUiPathResolver* _uiPathResolver;
		IBrowser* _browser;
	};
}

using namespace Crymium::Uis;