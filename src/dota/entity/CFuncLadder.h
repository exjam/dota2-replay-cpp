#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CBaseEntity.h"

namespace dota
{

struct CFuncLadder : public CBaseEntity
{
   Vector3f m_vecPlayerMountPositionTop;
   Vector3f m_vecPlayerMountPositionBottom;
   Vector3f m_vecLadderDir;
   uint32_t m_bFakeLadder;
};

DeclareClientClass(CFuncLadder);

}
