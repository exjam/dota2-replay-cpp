#pragma once
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct highlight_hud_element
{
   std::string elementname;
   float duration;
};

}

DeclareGameEvent(highlight_hud_element);

}
