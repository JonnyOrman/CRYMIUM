#pragma once

namespace Crymium::CryEngine::Core
{
	struct ICryInitialiser
	{
		virtual ~ICryInitialiser() = default;

		virtual void Initialise() = 0;
	};
}

using namespace Crymium::CryEngine::Core;