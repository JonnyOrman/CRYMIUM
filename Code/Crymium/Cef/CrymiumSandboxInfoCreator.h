#pragma once
#include "Cef/Core/ICrymiumSandboxInfoCreator.h"

namespace Crymium::Cef
{
    class CrymiumSandboxInfoCreator
        : public ICrymiumSandboxInfoCreator
    {
    public:
        __declspec(dllexport) CrymiumSandboxInfoCreator() = default;

        __declspec(dllexport) void* Create() override;
    };
}

using namespace Crymium::Cef;