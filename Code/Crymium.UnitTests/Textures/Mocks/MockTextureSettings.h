#pragma once
#include "gmock/gmock.h"
#include "Textures/Core/ITextureSettings.h"

namespace Crymium::UnitTests::Textures::Mocks
{
	class MockTextureSettings : public ITextureSettings
	{
	public:
		MOCK_METHOD(const char*, GetName, (), (override));

		MOCK_METHOD(int, GetNumberOfMips, (), (override));

		MOCK_METHOD(int, GetFlags, (), (override));

		MOCK_METHOD(ETEX_Format, GetEtexFormat, (), (override));

		MOCK_METHOD(int, GetWidth, (), (override));

		MOCK_METHOD(int, GetHeight, (), (override));
	};
}

using namespace Crymium::UnitTests::Textures::Mocks;