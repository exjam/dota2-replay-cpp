#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseFlex.h"

namespace dota
{

struct DT_BCCLocalPlayerExclusive
{
   float m_flNextAttack;
   uint32_t m_hMyWeapons[48];
};

struct CBaseCombatCharacter : public CBaseFlex
{
   DT_BCCLocalPlayerExclusive bcc_localdata;
   uint32_t m_hActiveWeapon;
};

DeclareNetworkStruct(DT_BCCLocalPlayerExclusive);
DeclareNetworkClass(CBaseCombatCharacter);

}
