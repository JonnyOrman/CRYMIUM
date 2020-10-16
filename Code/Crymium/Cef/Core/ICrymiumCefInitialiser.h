#pragma once

namespace Crymium::Cef::Core
{
	struct ICrymiumCefInitialiser
	{
		virtual ~ICrymiumCefInitialiser() = default;

		virtual void Initialise() = 0;
	};
}

using namespace Crymium::Cef::Core;