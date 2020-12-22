#pragma once
#include "Crymium/Buffer/Core/IBufferSizeProvider.h"
#include "Crymium/Buffer/Core/IBufferProvider.h"

namespace Crymium::Buffer
{
	class BufferProvider
		:
		public IBufferProvider
	{
	public:
		__declspec(dllexport) BufferProvider(
			IBufferSizeProvider* bufferSizeProvider
		);

		__declspec(dllexport) void Set(const void* buffer) override;

		__declspec(dllexport) unsigned char* Get() override;

	private:
		IBufferSizeProvider* _bufferSizeProvider;
		void* _bufferCopy;
		unsigned char* _buffer;
	};
}

using namespace Crymium::Buffer;