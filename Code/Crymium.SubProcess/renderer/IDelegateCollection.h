#pragma once
#include <vector>
#include "IDelegate.h"

namespace Crymium::SubProcess::Renderer
{
	struct IDelegateCollection
	{
		virtual ~IDelegateCollection() = default;

		virtual std::vector<IDelegate*> GetAll() = 0;

		virtual void Add(IDelegate* delegate) = 0;
	};
}

using namespace Crymium::SubProcess::Renderer;