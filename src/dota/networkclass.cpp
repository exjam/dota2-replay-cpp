#include "networkclass.h"

namespace dota
{

NetworkClassList &NetworkClassList::Instance()
{
   static NetworkClassList self;
   return self;
}

};
