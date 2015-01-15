#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_NPC_Observer_Ward.h"

namespace dota
{

struct CDOTA_NPC_Observer_Ward_TrueSight : public CDOTA_NPC_Observer_Ward
{
};

DeclareNetworkClass(CDOTA_NPC_Observer_Ward_TrueSight);

}
