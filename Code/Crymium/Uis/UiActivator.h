#pragma once
#include "Uis/Core/IUiPathResolver.h"
#include "Browsers/Core/IBrowser.h"
#include "Uis/Core/IUiActivator.h"

namespace Crymium::Uis
{
	class UiActivator
		: public IUiActivator
	{
	public:
		__declspec(dllexport) UiActivator(
			IUiPathResolver* uiPathResolver,
			IBrowser* browser
		);

		__declspec(dllexport) void Activate(const char* uiName) override;

	private:
		IUiPathResolver* _uiPathResolver;
		IBrowser* _browser;
	};
}

using namespace Crymium::Uis;