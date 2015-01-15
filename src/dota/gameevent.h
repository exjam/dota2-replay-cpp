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
   int type(const CSVCMsg_GameEvent &event);
   int sourceNameID(const CSVCMsg_GameEvent &event);
   std::string sourceName(const CSVCMsg_GameEvent &event);
   int targetNameID(const CSVCMsg_GameEvent &event);
   std::string targetName(const CSVCMsg_GameEvent &event);
   int attackerNameID(const CSVCMsg_GameEvent &event);
   std::string attackerName(const CSVCMsg_GameEvent &event);
   int inflictorNameID(const CSVCMsg_GameEvent &event);
   std::string inflictorName(const CSVCMsg_GameEvent &event);
   bool isAttackerIllusion(const CSVCMsg_GameEvent &event);
   bool isTargetIllusion(const CSVCMsg_GameEvent &event);
   int value(const CSVCMsg_GameEvent &event);
   int health(const CSVCMsg_GameEvent &event);
   float timestamp(const CSVCMsg_GameEvent &event);
   int targetSourceNameID(const CSVCMsg_GameEvent &event);
   std::string targetSourceName(const CSVCMsg_GameEvent &event);
   float timestampRaw(const CSVCMsg_GameEvent &event);
   bool isAttackerHero(const CSVCMsg_GameEvent &event);
   bool isTargetHero(const CSVCMsg_GameEvent &event);
   bool isAbilityToggleOn(const CSVCMsg_GameEvent &event);
   bool isAbilityToggleOff(const CSVCMsg_GameEvent &event);
   int abilityLevel(const CSVCMsg_GameEvent &event);
   int goldReason(const CSVCMsg_GameEvent &event);
   int xpReason(const CSVCMsg_GameEvent &event);
};

}
