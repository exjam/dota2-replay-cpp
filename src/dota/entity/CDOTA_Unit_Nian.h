#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Creature.h"

namespace dota
{

struct CDOTA_Unit_Nian : public CDOTA_BaseNPC_Creature
{
};

DeclareNetworkClass(CDOTA_Unit_Nian);

}
