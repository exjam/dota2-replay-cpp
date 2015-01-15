#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTABaseAbility.h"

namespace dota
{

struct CDOTA_Ability_Invoker_InvokedBase : public CDOTABaseAbility
{
   int32_t m_nQuasLevel;
   int32_t m_nWexLevel;
   int32_t m_nExortLevel;
};

DeclareNetworkClass(CDOTA_Ability_Invoker_InvokedBase);

}
