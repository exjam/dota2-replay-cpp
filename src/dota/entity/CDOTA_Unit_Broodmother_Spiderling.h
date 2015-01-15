#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Creep_Talking.h"

namespace dota
{

struct CDOTA_Unit_Broodmother_Spiderling : public CDOTA_BaseNPC_Creep_Talking
{
};

DeclareNetworkClass(CDOTA_Unit_Broodmother_Spiderling);

}
