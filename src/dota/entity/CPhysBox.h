#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CPhysBox : public CBaseEntity
{
};

DeclareNetworkClass(CPhysBox);

}
