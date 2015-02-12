#pragma once
#include "event.h"

namespace dota
{

namespace event
{

struct tree_cut
{
   float tree_x;
   float tree_y;
};

}

DeclareGameEvent(tree_cut);

}
