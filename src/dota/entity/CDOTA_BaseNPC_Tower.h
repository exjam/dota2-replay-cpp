#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Building.h"

namespace dota
{

struct CDOTA_BaseNPC_Tower : public CDOTA_BaseNPC_Building
{
};

DeclareNetworkClass(CDOTA_BaseNPC_Tower);

}
