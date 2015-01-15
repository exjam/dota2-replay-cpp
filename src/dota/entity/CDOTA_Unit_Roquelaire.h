#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Creep_Talking.h"

namespace dota
{

struct CDOTA_Unit_Roquelaire : public CDOTA_BaseNPC_Creep_Talking
{
   float m_flFlyHeight;
};

DeclareNetworkClass(CDOTA_Unit_Roquelaire);

}
