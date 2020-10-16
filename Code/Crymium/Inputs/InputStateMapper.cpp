#include "InputStateMapper.h"

cef_key_event_type_t InputStateMapper::Map(EInputState inputState)
{
    switch (inputState)
	{
    case EInputState::eIS_Pressed:
        return KEYEVENT_KEYDOWN;
    case EInputState::eIS_Released:
        return KEYEVENT_KEYUP;
    default:
        throw;
    }
}
