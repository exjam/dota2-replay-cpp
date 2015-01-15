#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector2f.h"
#include "vector3f.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CDOTA_DeathProphet_Exorcism_Spirit : public CBaseAnimating
{
   Vector2f m_vecOrigin;
   Vector2f m_angRotation;
};

DeclareNetworkClass(CDOTA_DeathProphet_Exorcism_Spirit);

}
