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
		__declspec(dllexport) BufferSizeProvider(
			IRendererSettings* rendererSettings,
			IBufferSettings* bufferSettings
		);

		__declspec(dllexport) int Get() override;

	private:
		IRendererSettings* _rendererSettings;
		IBufferSettings* _bufferSettings;
	};
}

using namespace Crymium::Buffer;