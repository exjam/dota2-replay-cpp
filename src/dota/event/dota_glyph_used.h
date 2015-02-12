#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_glyph_used
{
   int16_t teamnumber;
};

}

DeclareGameEvent(dota_glyph_used);

}
