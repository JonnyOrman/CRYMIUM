#include "BufferProvider.h"

BufferProvider::BufferProvider(
    IBufferSizeProvider* bufferSizeProvider
)
:
_bufferSizeProvider(bufferSizeProvider),
_buffer(nullptr)
{
}

void BufferProvider::Set(const void* buffer)
{
    auto bufferSize = _bufferSizeProvider->Get();

    _bufferCopy = malloc(bufferSize);

    memcpy(_bufferCopy, buffer, bufferSize);

    _buffer = (unsigned char*)_bufferCopy;
}

unsigned char* BufferProvider::Get()
{
    return _buffer;
}
