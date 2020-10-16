#pragma once
#include <CryRenderer/ITexture.h>
#include "gmock/gmock.h"

namespace Crymium::UnitTests::Cry::Mocks
{
	class MockTexture : public ITexture
	{
	public:
		MOCK_METHOD(int, AddRef, (), (override));

		MOCK_METHOD(int, Release, (), (override));

		MOCK_METHOD(int, ReleaseForce, (), (override));

		MOCK_METHOD(const char*, GetName, (), (const override));

		MOCK_METHOD(const int, GetWidth, (), (const override));

		MOCK_METHOD(const int, GetHeight, (), (const override));

		MOCK_METHOD(const int, GetDepth, (), (const override));

		MOCK_METHOD(const int, GetTextureID, (), (const override));

		MOCK_METHOD(const uint32, GetFlags, (), (const override));

		MOCK_METHOD(const int8, GetNumMips, (), (const override));

		MOCK_METHOD(const int8, GetRequiredMip, (), (const override));

		MOCK_METHOD(const uint32, GetDeviceDataSize, (), (const override));

		MOCK_METHOD(const uint32, GetDataSize, (), (const override));

		MOCK_METHOD(const ETEX_Type, GetTextureType, (), (const override));

		MOCK_METHOD(const bool, IsTextureLoaded, (), (const override));

		MOCK_METHOD(uint8*, GetData32, (int nSide, int nLevel, uint8* pDst, ETEX_Format eDstFormat), (override));

		MOCK_METHOD(bool, SetFilter, (int nFilter), (override));

		MOCK_METHOD(void, SetClamp, (bool bEnable), (override));

		MOCK_METHOD(float, GetAvgBrightness, (), (const override));

		MOCK_METHOD(bool, Clear, (), (override));

		MOCK_METHOD(bool, Clear, (const ColorF& color), (override));

		MOCK_METHOD(int8, StreamCalculateMipsSigned, (float fMipFactor), (const override));

		MOCK_METHOD(int8, StreamCalculateMips, (float fMipFactor), (const override));

		MOCK_METHOD(int8, GetStreamableMipNumber, (), (const override));

		MOCK_METHOD(uint32, GetStreamableMemoryUsage, (int8 nStartMip), (const override));

		MOCK_METHOD(int8, GetMinLoadedMip, (), (const override));

		MOCK_METHOD(const char*, GetFormatName, (), (const override));

		MOCK_METHOD(const char*, GetTypeName, (), (const override));

		MOCK_METHOD(const bool, IsStreamedVirtual, (), (const override));

		MOCK_METHOD(const bool, IsShared, (), (const override));

		MOCK_METHOD(const bool, IsStreamable, (), (const override));

		MOCK_METHOD(bool, IsStreamedIn, (const int nMinPrecacheRoundIds[2]), (const override));

		MOCK_METHOD(const int, GetAccessFrameId, (), (const override));

		MOCK_METHOD(const int, GetCustomID, (), (const override));

		MOCK_METHOD(void, SetCustomID, (int nID), (override));

		MOCK_METHOD(const ETEX_Format, GetTextureDstFormat, (), (const override));

		MOCK_METHOD(const ETEX_Format, GetTextureSrcFormat, (), (const override));

		MOCK_METHOD(bool, IsPostponed, (), (const override));

		MOCK_METHOD(const bool, IsParticularMipStreamed, (float fMipFactor), (const override));

		MOCK_METHOD(const ColorB*, GetLowResSystemCopy, (uint16& width, uint16& height, int** ppUserData, const int maxTexSize), (override));

		MOCK_METHOD(void, UpdateData, (STexDataPtr&& td, int flags), (override));

		MOCK_METHOD(void, GetMemoryUsage, (ICrySizer* pSizer), (const override));

		MOCK_METHOD(void, SetKeepSystemCopy, (const bool bKeepSystemCopy), (override));
	};
}

using namespace Crymium::UnitTests::Cry::Mocks;