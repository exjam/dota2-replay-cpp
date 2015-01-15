#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseCombatCharacter.h"

namespace dota
{

struct NextBotCombatCharacter : public CBaseCombatCharacter
{
};

DeclareNetworkClass(NextBotCombatCharacter);

}
