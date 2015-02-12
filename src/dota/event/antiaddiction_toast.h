#pragma once
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct antiaddiction_toast
{
   std::string message;
   float duration;
};

}

DeclareGameEvent(antiaddiction_toast);

}
