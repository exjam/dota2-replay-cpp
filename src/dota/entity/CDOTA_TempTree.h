#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CDOTA_TempTree : public CBaseAnimating
{
};

DeclareNetworkClass(CDOTA_TempTree);

}
