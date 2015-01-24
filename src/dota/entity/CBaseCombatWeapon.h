#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseAnimating.h"

namespace dota
{

struct DT_LocalWeaponData
{
   uint32_t m_iClip1;
   uint32_t m_iClip2;
   int32_t m_iPrimaryAmmoType;
   int32_t m_iSecondaryAmmoType;
   uint32_t m_nViewModelIndex;
};

struct DT_LocalActiveWeaponData
{
   float m_flNextPrimaryAttack;
   float m_flNextSecondaryAttack;
   int32_t m_nNextThinkTick;
   float m_flTimeWeaponIdle;
};

struct CBaseCombatWeapon : public CBaseAnimating
{
   DT_LocalWeaponData LocalWeaponData;
   DT_LocalActiveWeaponData LocalActiveWeaponData;
   int32_t m_iViewModelIndex;
   int32_t m_iWorldModelIndex;
   uint32_t m_iState;
   uint32_t m_hOwner;
};

DeclareClientStruct(DT_LocalWeaponData);
DeclareClientStruct(DT_LocalActiveWeaponData);
DeclareClientClass(CBaseCombatWeapon);

}
