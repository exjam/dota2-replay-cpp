#pragma once
#include <cstdint>
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct instructor_server_hint_create
{
   std::string hint_name;
   std::string hint_replace_key;
   int32_t hint_target;
   int16_t hint_activator_userid;
   int16_t hint_timeout;
   std::string hint_icon_onscreen;
   std::string hint_icon_offscreen;
   std::string hint_caption;
   std::string hint_activator_caption;
   std::string hint_color;
   float hint_icon_offset;
   float hint_range;
   int32_t hint_flags;
   std::string hint_binding;
   bool hint_allow_nodraw_target;
   bool hint_nooffscreen;
   bool hint_forcecaption;
   bool hint_local_player_only;
};

}

DeclareGameEvent(instructor_server_hint_create);

}
