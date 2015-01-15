#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Building.h"

namespace dota
{

struct CDOTA_BaseNPC_Shop : public CDOTA_BaseNPC_Building
{
   uint32_t m_ShopType;
};

DeclareNetworkClass(CDOTA_BaseNPC_Shop);

}
