#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Hero.h"

namespace dota
{

struct CDOTA_Unit_Hero_Necrolyte : public CDOTA_BaseNPC_Hero
{
};

DeclareNetworkClass(CDOTA_Unit_Hero_Necrolyte);

}
