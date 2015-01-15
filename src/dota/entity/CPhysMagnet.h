#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CPhysMagnet : public CBaseAnimating
{
};

DeclareNetworkClass(CPhysMagnet);

}
