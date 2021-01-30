#pragma once
#include <CryInput/IInput.h>
#include "Crymium/Inputs/KeyCode.h"

namespace Crymium::Inputs::Core
{
	struct IKeyIdMapper
	{
		virtual ~IKeyIdMapper() = default;

		virtual int Map(EKeyId keyId) = 0;

		virtual void SetMapping(EKeyId keyId, KeyCode keyCode) = 0;
	};
}

using namespace Crymium::Inputs::Core;