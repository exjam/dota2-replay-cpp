#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEKillPlayerAttachments : public CBaseTempEntity
{
   uint32_t m_nPlayer;
};

DeclareNetworkClass(CTEKillPlayerAttachments);

}
