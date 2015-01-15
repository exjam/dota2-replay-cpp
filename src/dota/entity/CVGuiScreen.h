#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CVGuiScreen : public CBaseEntity
{
   float m_flWidth;
   float m_flHeight;
   uint32_t m_nAttachmentIndex;
   uint32_t m_nPanelName;
   uint32_t m_fScreenFlags;
   uint32_t m_nOverlayMaterial;
   uint32_t m_hPlayerOwner;
};

DeclareNetworkClass(CVGuiScreen);

}
