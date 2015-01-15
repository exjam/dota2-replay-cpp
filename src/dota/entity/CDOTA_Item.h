#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTABaseAbility.h"

namespace dota
{

struct CDOTA_Item : public CDOTABaseAbility
{
   uint32_t m_bCombinable;
   uint32_t m_bPermanent;
   uint32_t m_bStackable;
   uint32_t m_bRecipe;
   int32_t m_iSharability;
   uint32_t m_bDroppable;
   uint32_t m_bPurchasable;
   uint32_t m_bSellable;
   uint32_t m_bRequiresCharges;
   uint32_t m_bKillable;
   uint32_t m_bDisassemblable;
   uint32_t m_bAlertable;
   uint32_t m_iCurrentCharges;
   float m_flPurchaseTime;
   uint32_t m_iInitialCharges;
   uint32_t m_hPurchaser;
   float m_flAssembledTime;
   uint32_t m_bPurchasedWhileDead;
};

DeclareNetworkClass(CDOTA_Item);

}
