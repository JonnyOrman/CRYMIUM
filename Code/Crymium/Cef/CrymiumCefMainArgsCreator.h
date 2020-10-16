#pragma once
#include "Cef/Core/ICrymiumCefMainArgsCreator.h"

namespace Crymium::Cef
{
    class CrymiumCefMainArgsCreator
        : public ICrymiumCefMainArgsCreator
    {
    public:
        __declspec(dllexport) CrymiumCefMainArgsCreator() = default;

        __declspec(dllexport) std::unique_ptr<CefMainArgs> Create() override;
    };
}

using namespace Crymium::Cef;