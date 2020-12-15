#pragma once
#include "Crymium/Cef/Core/ICrymiumSandboxInfoCreator.h"

namespace Crymium::Cef
{
    class CrymiumSandboxInfoCreator
        : public ICrymiumSandboxInfoCreator
    {
    public:
        CrymiumSandboxInfoCreator() = default;

    	void* Create() override;
    };
}

using namespace Crymium::Cef;