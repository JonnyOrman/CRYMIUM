#pragma once
#include "Core/IContainer.h"
#include <string>
#include <memory>

namespace Crymium
{
	class ContainerComposer
	{
	public:
		__declspec(dllexport) static std::unique_ptr<ICrymiumContainer> Compose(std::string uiDirectory = "");
	};
}

using namespace Crymium;