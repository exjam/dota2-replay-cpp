#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct team_showcase_ui_update
{
   bool show;
   uint64_t account_id;
   int16_t hero_entindex;
   bool display_ui_on_left;
};

}

DeclareGameEvent(team_showcase_ui_update);

}
