#pragma once
#include "gmock/gmock.h"
#include "Crymium/Rendering/Core/IRendererSettings.h"

namespace Crymium::UnitTests::Rendering::Mocks
{
	class MockRendererSettings : public IRendererSettings
	{
	public:
		MOCK_METHOD(int, GetWidth, (), (override));

		MOCK_METHOD(int, GetHeight, (), (override));
	};
}

using namespace Crymium::UnitTests::Rendering::Mocks;