#pragma once

namespace Crymium::Cef::Core
{
	struct ICrymiumCefAppInitialiser
	{
		virtual ~ICrymiumCefAppInitialiser() = default;

		virtual void Initialise() = 0;
	};
}

using namespace Crymium::Cef::Core;