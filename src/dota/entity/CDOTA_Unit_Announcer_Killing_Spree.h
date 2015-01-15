#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC.h"

namespace dota
{

struct CDOTA_Unit_Announcer_Killing_Spree : public CDOTA_BaseNPC
{
};

DeclareNetworkClass(CDOTA_Unit_Announcer_Killing_Spree);

}
