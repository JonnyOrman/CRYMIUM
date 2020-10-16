#pragma once

namespace Crymium::Rendering::Core
{
	struct ICrymiumRendererInitialiser
	{
		virtual ~ICrymiumRendererInitialiser() = default;

		virtual void Initialise() = 0;
	};
}

using namespace Crymium::Rendering::Core;