#include <iostream>

#include "proto/dota_gcmessages_common.pb.h"
#include "proto/netmessages.pb.h"
#include "proto/networkbasetypes.pb.h"

#include "demoparser.h"

namespace dota
{

void CombatLogEventDescriptor::setCombatLogNames(StringTable *stringTable)
{
   combatLogNames = stringTable;
}

void CombatLogEventDescriptor::setDescription(GameEventDescriptor &desc)
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

int CombatLogEventDescriptor::type(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.type).val_byte();
}

int CombatLogEventDescriptor::sourceNameID(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.sourceName).val_short();
}

std::string CombatLogEventDescriptor::sourceName(const CSVCMsg_GameEvent &event)
{
   return combatLogNames->entries[sourceNameID(event)].strData;
}

int CombatLogEventDescriptor::targetNameID(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.targetName).val_short();
}

std::string CombatLogEventDescriptor::targetName(const CSVCMsg_GameEvent &event)
{
   return combatLogNames->entries[targetNameID(event)].strData;
}

int CombatLogEventDescriptor::attackerNameID(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.attackerName).val_short();
}

std::string CombatLogEventDescriptor::attackerName(const CSVCMsg_GameEvent &event)
{
   return combatLogNames->entries[attackerNameID(event)].strData;
}

int CombatLogEventDescriptor::inflictorNameID(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.inflictorName).val_short();
}

std::string CombatLogEventDescriptor::inflictorName(const CSVCMsg_GameEvent &event)
{
   return combatLogNames->entries[inflictorNameID(event)].strData;
}

bool CombatLogEventDescriptor::isAttackerIllusion(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.attackerIllusion).val_bool();
}

bool CombatLogEventDescriptor::isTargetIllusion(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.targetIllusion).val_bool();
}

int CombatLogEventDescriptor::value(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.value).val_short();
}

int CombatLogEventDescriptor::health(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.health).val_short();
}

float CombatLogEventDescriptor::timestamp(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.timestamp).val_float();
}

int CombatLogEventDescriptor::targetSourceNameID(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.targetSourceName).val_short();
}

std::string CombatLogEventDescriptor::targetSourceName(const CSVCMsg_GameEvent &event)
{
   return combatLogNames->entries[targetSourceNameID(event)].strData;
}

float CombatLogEventDescriptor::timestampRaw(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.timestampRaw).val_float();
}

bool CombatLogEventDescriptor::isAttackerHero(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.attackerHero).val_bool();
}

bool CombatLogEventDescriptor::isTargetHero(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.targetHero).val_bool();
}

bool CombatLogEventDescriptor::isAbilityToggleOn(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.abilityToggleOn).val_bool();
}

bool CombatLogEventDescriptor::isAbilityToggleOff(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.abilityToggleOff).val_bool();
}

int CombatLogEventDescriptor::abilityLevel(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.abilityLevel).val_short();
}

int CombatLogEventDescriptor::goldReason(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.goldReason).val_short();
}

int CombatLogEventDescriptor::xpReason(const CSVCMsg_GameEvent &event)
{
   return event.keys(mIndex.xpReason).val_short();
}

struct CombatLogEvent
{
   CombatLogEvent(const CSVCMsg_GameEvent &event) :
      gameEvent(event)
   {
   }

   const CSVCMsg_GameEvent &gameEvent;
};

bool DemoParser::handleCombatLog(const CSVCMsg_GameEvent &event)
{
   auto type = mCombatLogEventDescriptor.type(event);

   switch (type) {
   case DOTA_COMBATLOG_DAMAGE:
      std::cout << "Damage" << std::endl;
      break;
   case DOTA_COMBATLOG_HEAL:
      std::cout << "Heal" << std::endl;
      break;
   case DOTA_COMBATLOG_MODIFIER_ADD:
      std::cout << "Modifier Add" << std::endl;
      break;
   case DOTA_COMBATLOG_MODIFIER_REMOVE:
      std::cout << "Modifier Remove" << std::endl;
      break;
   case DOTA_COMBATLOG_DEATH:
      std::cout << "Death" << std::endl;
      break;
   case DOTA_COMBATLOG_ABILITY:
      std::cout << "Ability" << std::endl;
      break;
   case DOTA_COMBATLOG_ITEM:
      std::cout << "Item" << std::endl;
      break;
   case DOTA_COMBATLOG_LOCATION:
      std::cout << "Location" << std::endl;
      break;
   case DOTA_COMBATLOG_GOLD:
      std::cout << mCombatLogEventDescriptor.value(event) << " gold"
                << " given to " << mCombatLogEventDescriptor.targetName(event)
                << std::endl;
      break;
   case DOTA_COMBATLOG_GAME_STATE:
   {
      DOTA_GameState state = static_cast<DOTA_GameState>(mCombatLogEventDescriptor.value(event));
      std::cout << "Game State: " << state << std::endl;
      break;
   }
   case DOTA_COMBATLOG_XP:
      std::cout << "XP" << std::endl;
      break;
   case DOTA_COMBATLOG_PURCHASE:
      std::cout << mCombatLogEventDescriptor.targetName(event)
                << " purchase item " << mCombatLogEventDescriptor.value(event)
                << std::endl;
      break;
   case DOTA_COMBATLOG_BUYBACK:
      std::cout << "Buyback" << std::endl;
      break;
   case DOTA_COMBATLOG_ABILITY_TRIGGER:
      std::cout << "Ability Trigger" << std::endl;
      break;
   default:
      std::cout << "Unhandled combat log type: " << type << std::endl;
   }

   return true;
}

bool DemoParser::handleGameEvent(const CSVCMsg_GameEvent &event)
{
   return true;

   auto &desc = mGameEventDescriptors[event.eventid()];
   std::cout << "Game Event: " << desc.name << std::endl;

   for (auto i = 0; i < event.keys_size(); ++i) {
      auto &key = event.keys(i);
      assert(key.has_type());

      auto type = key.type();
      std::cout << desc.keys[i].name << " type: " << type << " ";

      switch (type) {
      case GameEventKeyType::Bool:
         assert(key.has_val_bool());
         std::cout << "bool: " << key.val_bool() << std::endl;
         break;
      case GameEventKeyType::Byte:
         assert(key.has_val_byte());
         std::cout << "byte: " << key.val_byte() << std::endl;
         break;
      case GameEventKeyType::Float:
         assert(key.has_val_float());
         std::cout << "float: " << key.val_float() << std::endl;
         break;
      case GameEventKeyType::Long:
         assert(key.has_val_long());
         std::cout << "float: " << key.val_long() << std::endl;
         break;
      case GameEventKeyType::Short:
         assert(key.has_val_short());
         std::cout << "short: " << key.val_short() << std::endl;
         break;
      case GameEventKeyType::String:
         assert(key.has_val_string());
         std::cout << "string: " << key.val_string() << std::endl;
         break;
      case GameEventKeyType::Uint64:
         assert(key.has_val_uint64());
         std::cout << "uint64: " << key.val_uint64() << std::endl;
         break;
      default:
         assert(false);
         std::cout << "UNKNOWN" << std::endl;
      }
   }

   if (desc.name.compare("dota_combatlog") == 0) {
      handleCombatLog(event);
   }

   return true;
}

bool DemoParser::handleGameEventList(const CSVCMsg_GameEventList &list)
{
   for (auto i = 0; i < list.descriptors_size(); ++i) {
      auto &desc = list.descriptors(i);
      auto &event = mGameEventDescriptors[desc.eventid()];

      event.id = i;
      event.name = desc.name();

      for (auto j = 0; j < desc.keys_size(); ++j) {
         auto &key = desc.keys(j);
         event.keyIndexMap[key.name()] = j;
         event.keys.push_back({ key.type(), key.name() });
      }

      if (event.name.compare("dota_combatlog") == 0) {
         mCombatLogEventDescriptor.setDescription(event);
         mCombatLogEventDescriptor.setCombatLogNames(&mStringTables["CombatLogNames"]);
      }
   }

   return true;
}

}
