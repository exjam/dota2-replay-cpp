#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEKillPlayerAttachments : public CBaseTempEntity
{
   uint32_t m_nPlayer;
};

DeclareClientClass(CTEKillPlayerAttachments);

}
