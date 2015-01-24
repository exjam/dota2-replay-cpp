#pragma once
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct joined_chat_channel
{
   std::string channelName;
};

}

DeclareGameEvent(joined_chat_channel);

}
