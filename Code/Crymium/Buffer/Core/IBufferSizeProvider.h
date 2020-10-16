#pragma once

namespace Crymium::Buffer::Core
{
	struct IBufferSizeProvider
	{
		virtual ~IBufferSizeProvider() = default;

		virtual int Get() = 0;
	};
}

using namespace Crymium::Buffer::Core;