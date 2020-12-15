#pragma once
#include "Crymium/Cef/Core/ICrymiumCefMainArgsCreator.h"

namespace Crymium::Cef
{
    class CrymiumCefMainArgsCreator
        : public ICrymiumCefMainArgsCreator
    {
    public:
        CrymiumCefMainArgsCreator() = default;

        std::unique_ptr<CefMainArgs> Create() override;
    };
}

using namespace Crymium::Cef;