#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct nommed_tree
{
   int16_t PlayerID;
};

}

DeclareGameEvent(nommed_tree);

}
