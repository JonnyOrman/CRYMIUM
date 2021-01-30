#include "KeyIdMapper.h"

int KeyIdMapper::Map(EKeyId keyId)
{
    return _map[keyId];
}

void KeyIdMapper::SetMapping(EKeyId keyId, KeyCode keyCode)
{
    _map[keyId] = keyCode;
}
