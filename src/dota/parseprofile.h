#pragma once
#include <array>
#include <map>
#include <vector>

namespace dota
{

struct ParseProfile
{
   static const int MaxMsg = 15;
   static const int MaxSub = 34;
   static const int MaxUsr = 139;

   ParseProfile();
   ParseProfile(std::vector<const ParseProfile *> bases);
   ParseProfile(std::vector<int> allowMsg,
                std::vector<int> allowSub,
                std::vector<int> allowUsr,
                std::vector<const ParseProfile *> bases = { });

   std::array<bool, MaxMsg> msg;
   std::array<bool, MaxSub> sub;
   std::array<bool, MaxUsr> usr;

   static const ParseProfile *SendTables;
   static const ParseProfile *StringTables;
   static const ParseProfile *Entities;
   static const ParseProfile *TempEntities;
   static const ParseProfile *Events;
   static const ParseProfile *EventDescriptors;
   static const ParseProfile *UserMessages;
   static const ParseProfile *FullReplay;
};

}
