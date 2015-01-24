#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseCombatCharacter.h"

namespace dota
{

struct NextBotCombatCharacter : public CBaseCombatCharacter
{
};

DeclareClientClass(NextBotCombatCharacter);

}
