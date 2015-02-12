#pragma once
#include <string>
#include "event.h"

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
