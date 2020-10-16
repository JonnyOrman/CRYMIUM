#pragma once

namespace Crymium::Core
{
	struct ICrymiumInitialiser
	{
		virtual ~ICrymiumInitialiser() = default;

		virtual void Initialise() = 0;
	};
}

using namespace Crymium::Core;