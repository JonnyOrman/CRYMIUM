#pragma once
#include "Crymium/Cef/Core/ICefRectSettings.h"

namespace Crymium::Cef
{
	class CrymiumCefRectSettings
		:
		public ICrymiumCefRectSettings
	{
	public:
		CrymiumCefRectSettings(
			int x,
			int y
		);

		int GetX() override;

		int GetY() override;

	private:
		int x_;
		int y_;
	};
}

using namespace Crymium::Cef;