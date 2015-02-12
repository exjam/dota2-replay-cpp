#pragma once
#include <string>
#include "event.h"

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
