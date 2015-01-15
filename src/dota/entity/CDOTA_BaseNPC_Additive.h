#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC.h"

namespace dota
{

struct CDOTA_BaseNPC_Additive : public CDOTA_BaseNPC
{
};

DeclareNetworkClass(CDOTA_BaseNPC_Additive);

}
