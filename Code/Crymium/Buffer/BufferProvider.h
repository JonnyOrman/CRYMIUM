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
		BufferProvider(
			IBufferSizeProvider* bufferSizeProvider
		);

		void Set(const void* buffer) override;

		unsigned char* Get() override;

	private:
		IBufferSizeProvider* _bufferSizeProvider;
		void* _bufferCopy;
		unsigned char* _buffer;
	};
}

using namespace Crymium::Buffer;