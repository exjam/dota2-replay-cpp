#pragma once
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_match_done_client
{
};

}

DeclareGameEvent(dota_match_done_client);

}
