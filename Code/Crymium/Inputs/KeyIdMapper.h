#pragma once
#include "Inputs/Core/IKeyIdMapper.h"

namespace Crymium::Inputs::Core
{
	class KeyIdMapper
		: public IKeyIdMapper
	{
	public:
		__declspec(dllexport) KeyIdMapper() = default;

		__declspec(dllexport) int Map(EKeyId keyId) override;
	};
}

using namespace Crymium::Inputs::Core;