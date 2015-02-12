#pragma once
#include <cstdint>
#include "event.h"

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
