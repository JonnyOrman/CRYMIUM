#pragma once

namespace Crymium::Cef::Core
{
	struct ICrymiumSandboxInfoCreator
	{
		virtual ~ICrymiumSandboxInfoCreator() = default;

		virtual void* Create() = 0;
	};
}

using namespace Crymium::Cef::Core;