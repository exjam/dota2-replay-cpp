#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CSprite.h"

namespace dota
{

struct CSpriteOriented : public CSprite
{
};

DeclareNetworkClass(CSpriteOriented);

}
