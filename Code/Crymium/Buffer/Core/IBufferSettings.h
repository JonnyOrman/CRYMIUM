#pragma once

namespace Crymium::Buffer::Core
{
	struct IBufferSettings
	{
		virtual ~IBufferSettings() = default;

		virtual int GetSizeMultiplier() = 0;
	};
}

using namespace Crymium::Buffer::Core;