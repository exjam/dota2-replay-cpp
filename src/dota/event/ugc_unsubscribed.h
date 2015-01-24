#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct ugc_unsubscribed
{
   uint64_t published_file_id;
};

}

DeclareGameEvent(ugc_unsubscribed);

}
