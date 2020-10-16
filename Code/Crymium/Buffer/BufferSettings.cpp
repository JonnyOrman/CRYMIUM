#include "BufferSettings.h"

BufferSettings::BufferSettings(
	int sizeMultiplier
)
:
_sizeMultiplier(sizeMultiplier)
{
}

int BufferSettings::GetSizeMultiplier()
{
	return _sizeMultiplier;
}
