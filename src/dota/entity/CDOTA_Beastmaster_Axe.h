#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector2f.h"
#include "vector3f.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CDOTA_Beastmaster_Axe : public CBaseAnimating
{
   Vector3f m_vecOrigin;
};

DeclareClientClass(CDOTA_Beastmaster_Axe);

}
