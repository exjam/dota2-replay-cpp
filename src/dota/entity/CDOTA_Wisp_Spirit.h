#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector2f.h"
#include "vector3f.h"
#include "CDOTA_BaseNPC.h"

namespace dota
{

struct CDOTA_Wisp_Spirit : public CDOTA_BaseNPC
{
   Vector3f m_vecOrigin;
};

DeclareClientClass(CDOTA_Wisp_Spirit);

}
