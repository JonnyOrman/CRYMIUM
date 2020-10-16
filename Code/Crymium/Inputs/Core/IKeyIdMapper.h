#pragma once
#include <CryInput/IInput.h>

namespace Crymium::Inputs::Core
{
	struct IKeyIdMapper
	{
		virtual ~IKeyIdMapper() = default;

		virtual int Map(EKeyId keyId) = 0;
	};
}

using namespace Crymium::Inputs::Core;