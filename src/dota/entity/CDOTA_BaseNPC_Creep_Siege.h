#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Creep_Lane.h"

namespace dota
{

struct CDOTA_BaseNPC_Creep_Siege : public CDOTA_BaseNPC_Creep_Lane
{
};

DeclareNetworkClass(CDOTA_BaseNPC_Creep_Siege);

}
