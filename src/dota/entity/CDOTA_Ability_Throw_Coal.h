#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTABaseAbility.h"

namespace dota
{

struct CDOTA_Ability_Throw_Coal : public CDOTABaseAbility
{
};

DeclareNetworkClass(CDOTA_Ability_Throw_Coal);

}
