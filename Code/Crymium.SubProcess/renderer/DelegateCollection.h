#pragma once
#include "IDelegateCollection.h"
#include <memory>

namespace Crymium::SubProcess::Renderer
{
    class DelegateCollection
		: public IDelegateCollection
    {
    public:
        DelegateCollection();

        std::vector<IDelegate*> GetAll() override;

        void Add(IDelegate* delegate) override;

    private:
        std::vector<IDelegate*> _delegatesRaw;
        std::vector<std::unique_ptr<IDelegate>> _delegates;
    };
}

using namespace Crymium::SubProcess::Renderer;