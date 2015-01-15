#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Creep.h"

namespace dota
{

struct CDOTA_BaseNPC_Creep_Neutral : public CDOTA_BaseNPC_Creep
{
};

DeclareNetworkClass(CDOTA_BaseNPC_Creep_Neutral);

}
