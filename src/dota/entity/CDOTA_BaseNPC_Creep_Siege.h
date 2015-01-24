#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTA_BaseNPC_Creep_Lane.h"

namespace dota
{

struct CDOTA_BaseNPC_Creep_Siege : public CDOTA_BaseNPC_Creep_Lane
{
};

DeclareClientClass(CDOTA_BaseNPC_Creep_Siege);

}
