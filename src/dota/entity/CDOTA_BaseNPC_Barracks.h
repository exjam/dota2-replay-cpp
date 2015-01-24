#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTA_BaseNPC_Building.h"

namespace dota
{

struct CDOTA_BaseNPC_Barracks : public CDOTA_BaseNPC_Building
{
};

DeclareClientClass(CDOTA_BaseNPC_Barracks);

}
