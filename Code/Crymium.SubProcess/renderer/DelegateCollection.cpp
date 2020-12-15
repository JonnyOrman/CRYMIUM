#include "DelegateCollection.h"

DelegateCollection::DelegateCollection()
:
_delegatesRaw(std::vector<IDelegate*>()),
_delegates(std::vector<std::unique_ptr<IDelegate>>())
{
	
}

std::vector<IDelegate*> DelegateCollection::GetAll()
{
	return _delegatesRaw;
}

void DelegateCollection::Add(IDelegate* delegate)
{
	_delegatesRaw.push_back(delegate);
}