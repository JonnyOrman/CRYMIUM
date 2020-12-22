#pragma once
#include "Crymium/Cef/Core/ICefRectSettings.h"

namespace Crymium::Cef
{
	class CrymiumCefRectSettings
		:
		public ICrymiumCefRectSettings
	{
	public:
		__declspec(dllexport) CrymiumCefRectSettings(
			int x,
			int y
		);

		__declspec(dllexport) int GetX() override;

		__declspec(dllexport) int GetY() override;

	private:
		int x_;
		int y_;
	};
}

using namespace Crymium::Cef;