#pragma once
#include "Crymium/Browsers/Core/IBrowser.h"
#include "Crymium/Uis/Core/IUiCloser.h"

namespace Crymium::Uis
{
	class UiCloser
		: public IUiCloser
	{
	public:
		UiCloser(
			IBrowser* browser
		);

		void Close() override;
		
	private:
		IBrowser* _browser;
	};
}

using namespace Crymium::Uis;