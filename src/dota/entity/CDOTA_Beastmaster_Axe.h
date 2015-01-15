#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector2f.h"
#include "vector3f.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CDOTA_Beastmaster_Axe : public CBaseAnimating
{
   Vector2f m_vecOrigin;
};

DeclareNetworkClass(CDOTA_Beastmaster_Axe);

}
