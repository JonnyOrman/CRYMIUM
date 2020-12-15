#pragma once
#include "Crymium/Buffer/Core/IBufferSizeProvider.h"
#include "Crymium/Rendering/Core/IRendererSettings.h"
#include "Crymium/Buffer/Core/IBufferSettings.h"

namespace Crymium::Buffer
{
	class BufferSizeProvider
		:
		public IBufferSizeProvider
	{
	public:
		BufferSizeProvider(
			IRendererSettings* rendererSettings,
			IBufferSettings* bufferSettings
		);

		int Get() override;

	private:
		IRendererSettings* _rendererSettings;
		IBufferSettings* _bufferSettings;
	};
}

using namespace Crymium::Buffer;