#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Additive.h"

namespace dota
{

struct CDOTA_NPC_Observer_Ward : public CDOTA_BaseNPC_Additive
{
};

DeclareNetworkClass(CDOTA_NPC_Observer_Ward);

}
