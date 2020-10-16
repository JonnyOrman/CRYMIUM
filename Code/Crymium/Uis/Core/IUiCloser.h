#pragma once

namespace Crymium::Uis::Core
{
	struct IUiCloser
	{
		virtual ~IUiCloser() = default;

		virtual void Close() = 0;
	};
}

using namespace Crymium::Uis::Core;