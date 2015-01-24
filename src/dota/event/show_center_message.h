#pragma once
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct show_center_message
{
   std::string message;
   float duration;
   bool clear_message_queue;
};

}

DeclareGameEvent(show_center_message);

}
