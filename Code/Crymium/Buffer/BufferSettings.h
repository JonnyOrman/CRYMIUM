#pragma once
#include "Buffer/Core/IBufferSettings.h"

namespace Crymium::Buffer
{
	class BufferSettings
		:
		public IBufferSettings
	{
	public:
		__declspec(dllexport) BufferSettings(
			int sizeMultiplier
		);

		__declspec(dllexport) int GetSizeMultiplier() override;

	private:
		int _sizeMultiplier;
	};
}

using namespace Crymium::Buffer;