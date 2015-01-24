#pragma once
#include <cstdint>
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_link_clicked
{
   std::string link;
   bool nav;
   bool nav_back;
   int16_t recipe;
   int16_t shop;
};

}

DeclareGameEvent(dota_link_clicked);

}
