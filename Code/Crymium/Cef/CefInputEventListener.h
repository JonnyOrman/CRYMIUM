#pragma once
#include <CryInput/IInput.h>
#include "Crymium/Core/ICrymiumContainer.h"

namespace Crymium::Cef
{
	class CefInputEventListener
		:
		public IInputEventListener
	{
	public:
		__declspec(dllexport) CefInputEventListener(
			ICrymiumContainer* crymiumContainer
		);

		__declspec(dllexport) bool OnInputEvent(const SInputEvent& event) override;

	private:
		ICrymiumContainer* _crymiumContainer;
	};
}

using namespace Crymium::Cef;