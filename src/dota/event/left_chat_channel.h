#pragma once
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct left_chat_channel
{
   std::string channelName;
};

}

DeclareGameEvent(left_chat_channel);

}
