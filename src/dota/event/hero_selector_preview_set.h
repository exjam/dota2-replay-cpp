#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct hero_selector_preview_set
{
   int16_t setindex;
};

}

DeclareGameEvent(hero_selector_preview_set);

}
