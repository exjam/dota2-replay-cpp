#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CFuncConveyor : public CBaseEntity
{
   float m_flConveyorSpeed;
};

DeclareClientClass(CFuncConveyor);

}
