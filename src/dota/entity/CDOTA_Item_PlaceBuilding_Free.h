#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTA_Item_PlaceBuilding.h"

namespace dota
{

struct CDOTA_Item_PlaceBuilding_Free : public CDOTA_Item_PlaceBuilding
{
};

DeclareClientClass(CDOTA_Item_PlaceBuilding_Free);

}
