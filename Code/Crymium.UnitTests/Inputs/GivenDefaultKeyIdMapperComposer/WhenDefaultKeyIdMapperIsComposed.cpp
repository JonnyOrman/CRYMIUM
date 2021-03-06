#include <gtest/gtest.h>
#include "Crymium/Inputs/DefaultKeyIdMapperComposer.h"

namespace Crymium::UnitTests::Inputs::GivenDefaultKeyIdMapperComposer
{
	TEST(WhenDefaultKeyIdMapperIsComposed, ShouldComposeKeyIdMapperWithDefaultMappings)
	{
		auto defaultKeyIdMapper = DefaultKeyIdMapperComposer::Compose();

		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Backspace), Backspace);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Tab), Tab);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Enter), Enter);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_LShift), Shift);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_LCtrl), Ctrl);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_LAlt), Alt);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Pause), Pause);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_CapsLock), CapsLock);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Escape), KeyCode::Escape);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Space), Spacebar);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_PgUp), PageUp);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_PgDn), PageDown);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_End), End);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Left), Left);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Up), Up);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Right), Right);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Down), Down);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Print), Print);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Insert), Insert);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Delete), Delete);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_0), Zero);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_1), One);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_2), Two);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_3), Three);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_4), Four);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_5), Five);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_6), Six);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_7), Seven);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_8), Eight);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_9), Nine);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_A), A);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_B), B);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_C), C);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_D), D);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_E), E);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_F), F);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_G), G);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_H), H);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_I), I);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_J), J);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_K), K);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_L), L);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_M), M);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_N), N);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_O), O);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_P), P);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Q), Q);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_R), R);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_S), S);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_T), T);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_U), U);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_V), V);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_W), W);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_X), X);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Y), Y);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Z), Z);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_NP_0), NumPad0);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_NP_1), NumPad1);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_NP_2), NumPad2);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_NP_3), NumPad3);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_NP_4), NumPad4);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_NP_5), NumPad5);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_NP_6), NumPad6);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_NP_7), NumPad7);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_NP_8), NumPad8);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_NP_9), NumPad9);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_NP_Multiply), NumPadMultiply);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_NP_Add), NumPadAdd);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_NP_Substract), NumPadSubtract);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_NP_Period), NumPadDecimalPoint);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_NP_Divide), NumPadDivide);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_F1), F1);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_F2), F2);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_F3), F3);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_F4), F4);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_F5), F5);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_F6), F6);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_F7), F7);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_F8), F8);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_F9), F9);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_F10), F10);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_F11), F11);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_F12), F12);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_F13), F13);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_F14), F14);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_F15), F15);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_NumLock), NumLock);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_ScrollLock), ScrollLock);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Semicolon), SemiColon);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Equals), EqualSign);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Comma), Comma);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Minus), Hyphen);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Period), FullStop);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Slash), ForwardSlash);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_Apostrophe), Apostrophe);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_LBracket), OpenBracket);
		ASSERT_EQ(defaultKeyIdMapper->Map(eKI_RBracket), CloseBracket);
	}
}