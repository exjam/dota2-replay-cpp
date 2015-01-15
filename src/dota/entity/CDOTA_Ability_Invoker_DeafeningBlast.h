#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_Ability_Invoker_InvokedBase.h"

namespace dota
{

struct CDOTA_Ability_Invoker_DeafeningBlast : public CDOTA_Ability_Invoker_InvokedBase
{
};

DeclareNetworkClass(CDOTA_Ability_Invoker_DeafeningBlast);

}
