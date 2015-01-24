#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTA_BaseNPC.h"

namespace dota
{

struct CDOTA_BaseNPC_Additive : public CDOTA_BaseNPC
{
};

DeclareClientClass(CDOTA_BaseNPC_Additive);

}
