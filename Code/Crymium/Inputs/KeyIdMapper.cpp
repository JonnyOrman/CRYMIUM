#include "KeyIdMapper.h"

int KeyIdMapper::Map(EKeyId keyId)
{
    if (keyId == EKeyId::eKI_Down
       || keyId == EKeyId::eKI_XI_DPadDown)
   {
       return 40;
   }
   if (keyId == EKeyId::eKI_Up
       || keyId == EKeyId::eKI_XI_DPadUp)
   {
       return 38;
   }
   if (keyId == EKeyId::eKI_Enter
       || keyId == EKeyId::eKI_XI_A)
   {
       return 13;
   }
   if (keyId == EKeyId::eKI_Escape
       || keyId == EKeyId::eKI_XI_B)
   {
       return 27;
   }

   return 0;
}
