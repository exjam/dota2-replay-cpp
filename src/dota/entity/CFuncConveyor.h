#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CFuncConveyor : public CBaseEntity
{
   float m_flConveyorSpeed;
};

DeclareNetworkClass(CFuncConveyor);

}
