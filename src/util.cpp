#include <cmath>
#include "util.h"

std::size_t getRequiredBits(std::size_t number)
{
   return static_cast<std::size_t>(std::ceil(std::log2(number)));
}
