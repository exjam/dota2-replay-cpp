#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTA_BaseNPC_Creep.h"

namespace dota
{

struct CDOTA_BaseNPC_Creature : public CDOTA_BaseNPC_Creep
{
};

DeclareClientClass(CDOTA_BaseNPC_Creature);

}
