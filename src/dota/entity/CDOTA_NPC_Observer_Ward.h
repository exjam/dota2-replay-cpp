#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTA_BaseNPC_Additive.h"

namespace dota
{

struct CDOTA_NPC_Observer_Ward : public CDOTA_BaseNPC_Additive
{
};

DeclareClientClass(CDOTA_NPC_Observer_Ward);

}
