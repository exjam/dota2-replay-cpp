#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_chat_ban_notification
{
   int16_t userid;
};

}

DeclareGameEvent(dota_chat_ban_notification);

}
