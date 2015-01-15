#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector2f.h"
#include "vector3f.h"
#include "CDOTA_BaseNPC.h"

namespace dota
{

struct CDOTA_Wisp_Spirit : public CDOTA_BaseNPC
{
   Vector2f m_vecOrigin;
};

DeclareNetworkClass(CDOTA_Wisp_Spirit);

}
