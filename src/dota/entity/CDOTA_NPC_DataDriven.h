#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Additive.h"

namespace dota
{

struct CDOTA_NPC_DataDriven : public CDOTA_BaseNPC_Additive
{
};

DeclareNetworkClass(CDOTA_NPC_DataDriven);

}