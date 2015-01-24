#include "clientclass.h"

namespace dota
{

ClientClassID ClientClassList::GetUniqueID()
{
   static ClientClassID classID = 0;
   return ++classID;
}

};
