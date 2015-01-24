#pragma once
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct hltv_message
{
   std::string text;
};

}

DeclareGameEvent(hltv_message);

}
