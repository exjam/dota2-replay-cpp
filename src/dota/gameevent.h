#pragma once
#include <map>
#include <string>
#include <vector>

#include "stringtable.h"

class CSVCMsg_GameEvent;

namespace dota
{

enum class GameEventKeyType
{
   Invalid,
   String,
   Float,
   Long,
   Short,
   Byte,
   Bool,
   Uint64
};

struct GameEventDescriptor
{
   struct Key
   {
      int type;
      std::string name;
   };

   int id;
   std::string name;
   std::vector<Key> keys;
   std::map<std::string, int> keyIndexMap;
};

struct CombatLogEventDescriptor
{
   struct {
      int type;
      int sourceName;
      int targetName;
      int attackerName;
      int inflictorName;
      int attackerIllusion;
      int targetIllusion;
      int value;
      int health;
      int timestamp;
      int targetSourceName;
      int timestampRaw;
      int attackerHero;
      int targetHero;
      int abilityToggleOn;
      int abilityToggleOff;
      int abilityLevel;
      int goldReason;
      int xpReason;
   } mIndex;

   int mID;
   StringTable *combatLogNames;

   void setCombatLogNames(StringTable *stringTable);
   void setDescription(GameEventDescriptor &desc);

   int type(const CSVCMsg_GameEvent &event) const;
   int sourceNameID(const CSVCMsg_GameEvent &event) const;
   std::string sourceName(const CSVCMsg_GameEvent &event) const;
   int targetNameID(const CSVCMsg_GameEvent &event) const;
   std::string targetName(const CSVCMsg_GameEvent &event) const;
   int attackerNameID(const CSVCMsg_GameEvent &event) const;
   std::string attackerName(const CSVCMsg_GameEvent &event) const;
   int inflictorNameID(const CSVCMsg_GameEvent &event) const;
   std::string inflictorName(const CSVCMsg_GameEvent &event) const;
   bool isAttackerIllusion(const CSVCMsg_GameEvent &event) const;
   bool isTargetIllusion(const CSVCMsg_GameEvent &event) const;
   int value(const CSVCMsg_GameEvent &event) const;
   int health(const CSVCMsg_GameEvent &event) const;
   float timestamp(const CSVCMsg_GameEvent &event) const;
   int targetSourceNameID(const CSVCMsg_GameEvent &event) const;
   std::string targetSourceName(const CSVCMsg_GameEvent &event) const;
   float timestampRaw(const CSVCMsg_GameEvent &event) const;
   bool isAttackerHero(const CSVCMsg_GameEvent &event) const;
   bool isTargetHero(const CSVCMsg_GameEvent &event) const;
   bool isAbilityToggleOn(const CSVCMsg_GameEvent &event) const;
   bool isAbilityToggleOff(const CSVCMsg_GameEvent &event) const;
   int abilityLevel(const CSVCMsg_GameEvent &event) const;
   int goldReason(const CSVCMsg_GameEvent &event) const;
   int xpReason(const CSVCMsg_GameEvent &event) const;
};

}
