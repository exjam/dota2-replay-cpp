#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_Item.h"

namespace dota
{

struct CDOTA_Item_PlaceBuilding : public CDOTA_Item
{
};

DeclareNetworkClass(CDOTA_Item_PlaceBuilding);

}