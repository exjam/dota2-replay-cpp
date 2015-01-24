#pragma once
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct hltv_title
{
   std::string text;
};

}

DeclareGameEvent(hltv_title);

}
