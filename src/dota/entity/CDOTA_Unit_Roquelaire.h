#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTA_BaseNPC_Creep_Talking.h"

namespace dota
{

struct CDOTA_Unit_Roquelaire : public CDOTA_BaseNPC_Creep_Talking
{
   float m_flFlyHeight;
};

DeclareClientClass(CDOTA_Unit_Roquelaire);

}
