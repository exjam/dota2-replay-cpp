#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct hltv_chat
{
   std::string name;
   std::string text;
   uint64_t steamID;
};

}

DeclareGameEvent(hltv_chat);

}
