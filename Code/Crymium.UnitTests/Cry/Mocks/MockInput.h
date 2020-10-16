#pragma once
#include <CryInput/IInput.h>
#include "gmock/gmock.h"

namespace Crymium::UnitTests::Cry::Mocks
{
	class MockInput : public IInput
	{
	public:
		MOCK_METHOD(void, AddEventListener, (IInputEventListener* pListener), (override));

		MOCK_METHOD(void, RemoveEventListener, (IInputEventListener* pListener), (override));

		MOCK_METHOD(void, AddConsoleEventListener, (IInputEventListener* pListener), (override));

		MOCK_METHOD(void, RemoveConsoleEventListener, (IInputEventListener* pListener), (override));

		MOCK_METHOD(bool, AddTouchEventListener, (ITouchEventListener* pListener, const char* name), (override));

		MOCK_METHOD(void, RemoveTouchEventListener, (ITouchEventListener* pListener), (override));

		MOCK_METHOD(void, SetExclusiveListener, (IInputEventListener* pListener), (override));

		MOCK_METHOD(IInputEventListener*, GetExclusiveListener, (), (override));

		MOCK_METHOD(bool, AddInputDevice, (IInputDevice* pDevice), (override));

		MOCK_METHOD(bool, RemoveInputDevice, (IInputDevice* pDevice), (override));

		MOCK_METHOD(void, EnableEventPosting, (bool bEnable), (override));

		MOCK_METHOD(bool, IsEventPostingEnabled, (), (const override));

		MOCK_METHOD(void, PostInputEvent, (const SInputEvent& event, bool bForce), (override));

		MOCK_METHOD(void, PostTouchEvent, (const STouchEvent& event, bool bForce), (override));

		MOCK_METHOD(void, PostUnicodeEvent, (const SUnicodeEvent& event, bool bForce), (override));

		MOCK_METHOD(void, ProcessKey, (uint32 key, bool pressed, wchar_t unicode, bool repeat), (override));

		MOCK_METHOD(void, ForceFeedbackEvent, (const SFFOutputEvent& event), (override));

		MOCK_METHOD(void, ForceFeedbackSetDeviceIndex, (int index), (override));

		MOCK_METHOD(bool, Init, (), (override));

		MOCK_METHOD(void, PostInit, (), (override));

		MOCK_METHOD(void, Update, (bool bFocus), (override));

		MOCK_METHOD(void, ShutDown, (), (override));

		MOCK_METHOD(void, SetExclusiveMode, (EInputDeviceType deviceType, bool exclusive, void* hwnd), (override));

		MOCK_METHOD(bool, InputState, (const TKeyName& key, EInputState state), (override));

		MOCK_METHOD(const char*, GetKeyName, (const SInputEvent& event), (const override));

		MOCK_METHOD(const char*, GetKeyName, (EKeyId keyId), (const override));

		MOCK_METHOD(uint32, GetInputCharUnicode, (const SInputEvent& event), (override));

		MOCK_METHOD(SInputSymbol*, LookupSymbol, (EInputDeviceType deviceType, int deviceIndex, EKeyId keyId), (override));

		MOCK_METHOD(SInputSymbol*, GetSymbolByName, (const char* name), (const override));

		MOCK_METHOD(const char*, GetOSKeyName, (const SInputEvent& event), (override));

		MOCK_METHOD(void, ClearKeyState, (), (override));

		MOCK_METHOD(void, ClearAnalogKeyState, (), (override));

		MOCK_METHOD(void, RetriggerKeyState, (), (override));

		MOCK_METHOD(bool, Retriggering, (), (override));

		MOCK_METHOD(bool, HasInputDeviceOfType, (EInputDeviceType type), (override));

		MOCK_METHOD(int, GetModifiers, (), (const override));

		MOCK_METHOD(void, EnableDevice, (EInputDeviceType deviceType, bool enable), (override));

		MOCK_METHOD(void, SetDeadZone, (float fThreshold), (override));

		MOCK_METHOD(void, RestoreDefaultDeadZone, (), (override));

		MOCK_METHOD(IInputDevice*, GetDevice, (uint16 id, EInputDeviceType deviceType), (override));

		MOCK_METHOD(uint32, GetPlatformFlags, (), (const override));

		MOCK_METHOD(bool, SetBlockingInput, (const SInputBlockData& inputBlockData), (override));

		MOCK_METHOD(bool, RemoveBlockingInput, (const SInputBlockData& inputBlockData), (override));

		MOCK_METHOD(bool, HasBlockingInput, (const SInputBlockData& inputBlockData), (const override));

		MOCK_METHOD(int, GetNumBlockingInputs, (), (const override));

		MOCK_METHOD(void, ClearBlockingInputs, (), (override));

		MOCK_METHOD(bool, ShouldBlockInputEventPosting, (const EKeyId keyId, const EInputDeviceType deviceType, const uint8 deviceIndex), (const override));

		MOCK_METHOD(int, ShowCursor, (const bool bShow), (override));

		MOCK_METHOD(IKinectInput*, GetKinectInput, (), (override));

		MOCK_METHOD(INaturalPointInput*, GetNaturalPointInput, (), (override));

		MOCK_METHOD(bool, GrabInput, (bool bGrab), (override));
	};
}

using namespace Crymium::UnitTests::Cry::Mocks;