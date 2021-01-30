#pragma once
#include "Crymium/Inputs/Core/IKeyIdMapper.h"

namespace Crymium::Inputs
{
	class KeyIdMapper
		: public IKeyIdMapper
	{
	public:
		__declspec(dllexport) KeyIdMapper() = default;

		__declspec(dllexport) int Map(EKeyId keyId) override;

		__declspec(dllexport) void SetMapping(EKeyId keyId, KeyCode keyCode) override;

	private:
		std::map<EKeyId, KeyCode> _map;
	};
}

using namespace Crymium::Inputs;