#pragma once
#include "Crymium/Buffer/Core/IBufferSettings.h"

namespace Crymium::Buffer
{
	class BufferSettings
		:
		public IBufferSettings
	{
	public:
		BufferSettings(
			int sizeMultiplier
		);

		int GetSizeMultiplier() override;

	private:
		int _sizeMultiplier;
	};
}

using namespace Crymium::Buffer;