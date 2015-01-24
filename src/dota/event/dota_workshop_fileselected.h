#pragma once
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_workshop_fileselected
{
   std::string filename;
};

}

DeclareGameEvent(dota_workshop_fileselected);

}
