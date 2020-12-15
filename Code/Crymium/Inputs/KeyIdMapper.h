#pragma once
#include "Crymium/Inputs/Core/IKeyIdMapper.h"

namespace Crymium::Inputs::Core
{
	class KeyIdMapper
		: public IKeyIdMapper
	{
	public:
		KeyIdMapper() = default;

		int Map(EKeyId keyId) override;
	};
}

using namespace Crymium::Inputs::Core;