#pragma once
#include "gmock/gmock.h"
#include "Rendering/Core/ICrymiumRenderer.h"

namespace Crymium::UnitTests::Rendering::Mocks
{
	class MockCrymiumRenderer : public ICrymiumRenderer
	{
	public:
		MOCK_METHOD(ITexture*, CreateTexture, (
			const char* getName,
			int getWidth,
			int getHeight,
			int getNumberOfMips,
			unsigned char* get,
			ETEX_Format etexFormat,
			int getFlags
			), (override));

		MOCK_METHOD(CRY_HWND, GetHWND, (), (override));

		MOCK_METHOD(void, RegisterCaptureFrame, (ICaptureFrameListener* captureFrameListener), (override));

		MOCK_METHOD(void, RemoveTexture, (int textureId), (override));
	};
}

using namespace Crymium::UnitTests::Rendering::Mocks;