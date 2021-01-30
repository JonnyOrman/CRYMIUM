#include "DefaultKeyIdMapperComposer.h"
#include "Crymium/Inputs/KeyIdMapper.h"

std::unique_ptr<IKeyIdMapper> DefaultKeyIdMapperComposer::Compose()
{
	auto keyIdMapper = std::make_unique<KeyIdMapper>();

	keyIdMapper->SetMapping(eKI_Enter, Enter);
	keyIdMapper->SetMapping(eKI_Escape, Escape);
	keyIdMapper->SetMapping(eKI_Left, Left);
	keyIdMapper->SetMapping(eKI_Up, Up);
	keyIdMapper->SetMapping(eKI_Right, Right);
	keyIdMapper->SetMapping(eKI_Down, Down);
	
	return keyIdMapper;
}
