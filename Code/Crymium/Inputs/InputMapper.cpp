#include "InputMapper.h"

InputMapper::InputMapper(
    IKeyIdMapper* keyIdMapper,
    IInputStateMapper* inputStateMapper
)
:
_keyIdMapper(keyIdMapper),
_inputStateMapper(inputStateMapper)
{	
}

CefKeyEvent InputMapper::Map(const SInputEvent& inputEvent)
{
    CefKeyEvent keyEvent;

    auto keyCode = _keyIdMapper->Map(inputEvent.keyId);

    keyEvent.native_key_code = keyCode;
    keyEvent.windows_key_code = keyCode;

    keyEvent.type = _inputStateMapper->Map(inputEvent.state);
	
    keyEvent.character = keyEvent.unmodified_character;

    return keyEvent;
}
