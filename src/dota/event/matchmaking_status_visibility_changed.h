#pragma once
#include "event.h"

namespace dota
{

namespace event
{

struct matchmaking_status_visibility_changed
{
};

}

DeclareGameEvent(matchmaking_status_visibility_changed);

}
