#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CWaterBullet : public CBaseAnimating
{
};

DeclareNetworkClass(CWaterBullet);

}
