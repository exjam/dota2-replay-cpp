#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTA_BaseNPC.h"

namespace dota
{

struct CDOTA_Unit_Announcer : public CDOTA_BaseNPC
{
};

DeclareClientClass(CDOTA_Unit_Announcer);

}
