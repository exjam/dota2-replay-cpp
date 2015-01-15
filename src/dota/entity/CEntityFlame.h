#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CEntityFlame : public CBaseEntity
{
   uint32_t m_hEntAttached;
   uint32_t m_bCheapEffect;
};

DeclareNetworkClass(CEntityFlame);

}
