#pragma once
#include <string>
#include "event.h"

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
