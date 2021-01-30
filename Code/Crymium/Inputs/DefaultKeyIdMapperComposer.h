#pragma once
#include "Crymium/Inputs/Core/IKeyIdMapper.h"

namespace Crymium::Inputs
{
	class DefaultKeyIdMapperComposer
	{
	public:
		DefaultKeyIdMapperComposer() = default;

		__declspec(dllexport) static std::unique_ptr<IKeyIdMapper> Compose();
	};
}

using namespace Crymium::Inputs;