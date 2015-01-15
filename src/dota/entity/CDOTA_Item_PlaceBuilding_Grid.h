#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_Item_PlaceBuilding.h"

namespace dota
{

struct CDOTA_Item_PlaceBuilding_Grid : public CDOTA_Item_PlaceBuilding
{
};

DeclareNetworkClass(CDOTA_Item_PlaceBuilding_Grid);

}
