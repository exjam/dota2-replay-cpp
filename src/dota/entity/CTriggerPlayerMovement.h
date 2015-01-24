#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseTrigger.h"

namespace dota
{

struct CTriggerPlayerMovement : public CBaseTrigger
{
};

DeclareClientClass(CTriggerPlayerMovement);

}
