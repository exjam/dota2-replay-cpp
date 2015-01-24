#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct account_all_hero_challenge_changed
{
   uint64_t account_id;
};

}

DeclareGameEvent(account_all_hero_challenge_changed);

}
