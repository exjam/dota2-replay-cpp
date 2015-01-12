#pragma once
#include <string>
#include <vector>
#include <map>

#include "stringtable.h"
#include "proto/networkbasetypes.pb.h"

enum class GameEventKeyType {
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

struct CombatLogEventDescriptor {
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

   void setCombatLogNames(StringTable *stringTable)
   {
      combatLogNames = stringTable;
   }

   void setDescription(GameEventDescriptor &desc)
   {
      mID = desc.id;

      mIndex.type = desc.keyIndexMap["type"];
      mIndex.sourceName = desc.keyIndexMap["sourcename"];
      mIndex.targetName = desc.keyIndexMap["targetname"];
      mIndex.attackerName = desc.keyIndexMap["attackername"];
      mIndex.inflictorName = desc.keyIndexMap["inflictorname"];
      mIndex.attackerIllusion = desc.keyIndexMap["attackerillusion"];
      mIndex.targetIllusion = desc.keyIndexMap["targetillusion"];
      mIndex.value = desc.keyIndexMap["value"];
      mIndex.health = desc.keyIndexMap["health"];
      mIndex.timestamp = desc.keyIndexMap["timestamp"];
      mIndex.targetSourceName = desc.keyIndexMap["targetsourcename"];
      mIndex.timestampRaw = desc.keyIndexMap["timestampraw"];
      mIndex.attackerHero = desc.keyIndexMap["attackerhero"];
      mIndex.targetHero = desc.keyIndexMap["targethero"];
      mIndex.abilityToggleOn = desc.keyIndexMap["ability_toggle_on"];
      mIndex.abilityToggleOff = desc.keyIndexMap["ability_toggle_off"];
      mIndex.abilityLevel = desc.keyIndexMap["ability_level"];
      mIndex.goldReason = desc.keyIndexMap["gold_reason"];
      mIndex.xpReason = desc.keyIndexMap["xp_reason"];
   }

   int type(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.type).val_byte();
   }

   int sourceNameID(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.sourceName).val_short();
   }

   std::string sourceName(const CSVCMsg_GameEvent &event) {
      return combatLogNames->entries[sourceNameID(event)].strData;
   }

   int targetNameID(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.targetName).val_short();
   }

   std::string targetName(const CSVCMsg_GameEvent &event) {
      return combatLogNames->entries[targetNameID(event)].strData;
   }

   int attackerNameID(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.attackerName).val_short();
   }

   std::string attackerName(const CSVCMsg_GameEvent &event) {
      return combatLogNames->entries[attackerNameID(event)].strData;
   }

   int inflictorNameID(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.inflictorName).val_short();
   }

   std::string inflictorName(const CSVCMsg_GameEvent &event) {
      return combatLogNames->entries[inflictorNameID(event)].strData;
   }

   bool isAttackerIllusion(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.attackerIllusion).val_bool();
   }

   bool isTargetIllusion(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.targetIllusion).val_bool();
   }

   int value(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.value).val_short();
   }

   int health(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.health).val_short();
   }

   float timestamp(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.timestamp).val_float();
   }

   int targetSourceNameID(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.targetSourceName).val_short();
   }

   std::string targetSourceName(const CSVCMsg_GameEvent &event) {
      return combatLogNames->entries[targetSourceNameID(event)].strData;
   }

   float timestampRaw(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.timestampRaw).val_float();
   }

   bool isAttackerHero(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.attackerHero).val_bool();
   }

   bool isTargetHero(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.targetHero).val_bool();
   }

   bool isAbilityToggleOn(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.abilityToggleOn).val_bool();
   }

   bool isAbilityToggleOff(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.abilityToggleOff).val_bool();
   }

   int abilityLevel(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.abilityLevel).val_short();
   }

   int goldReason(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.goldReason).val_short();
   }

   int xpReason(const CSVCMsg_GameEvent &event) {
      return event.keys(mIndex.xpReason).val_short();
   }
};
