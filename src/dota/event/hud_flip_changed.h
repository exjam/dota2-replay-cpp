#pragma once
#include "gameevent.h"

namespace dota
{

namespace event
{

struct hud_flip_changed
{
   bool flipped;
};

}

DeclareGameEvent(hud_flip_changed);

}
