#pragma once

namespace Crymium::Buffer::Core
{
	struct IBufferProvider
	{
		virtual ~IBufferProvider() = default;

		virtual void Set(const void* buffer) = 0;

		virtual unsigned char* Get() = 0;
	};
}

using namespace Crymium::Buffer::Core;