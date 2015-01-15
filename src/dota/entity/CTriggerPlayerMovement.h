#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseTrigger.h"

namespace dota
{

struct CTriggerPlayerMovement : public CBaseTrigger
{
};

DeclareNetworkClass(CTriggerPlayerMovement);

}
