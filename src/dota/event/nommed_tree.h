#pragma once
#include <cstdint>
#include "event.h"

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
