#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTA_NPC_Observer_Ward.h"

namespace dota
{

struct CDOTA_NPC_Observer_Ward_TrueSight : public CDOTA_NPC_Observer_Ward
{
};

DeclareClientClass(CDOTA_NPC_Observer_Ward_TrueSight);

}
