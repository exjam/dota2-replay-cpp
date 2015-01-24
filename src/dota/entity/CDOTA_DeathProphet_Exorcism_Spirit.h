#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector2f.h"
#include "vector3f.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CDOTA_DeathProphet_Exorcism_Spirit : public CBaseAnimating
{
   Vector3f m_vecOrigin;
   Vector2f m_angRotation;
};

DeclareClientClass(CDOTA_DeathProphet_Exorcism_Spirit);

}
