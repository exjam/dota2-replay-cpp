#include <iostream>

#include "proto/dota_gcmessages_common.pb.h"
#include "proto/netmessages.pb.h"
#include "proto/networkbasetypes.pb.h"

#include "event/dota_combatlog.h"

#include "demoparser.h"

namespace dota
{
// DOTA_COMBATLOG_TYPES

bool DemoParser::parseGameEvent(const CSVCMsg_GameEvent &event)
{
   GameEventDescriptor &descriptor = mGameEventDescriptors[event.eventid()];
   GameEvent *gameEvent = nullptr;

   if (descriptor.gameEventClass) {
      gameEvent = descriptor.gameEventClass->create();

      for (auto i = 0; i < event.keys_size(); ++i) {
         auto &prop = descriptor.properties[i];
         auto &key = event.keys(i);
         auto valuePtr = reinterpret_cast<std::ptrdiff_t>(gameEvent) + prop.offset;

         if (prop.offset == -1) {
            continue;
         }

         switch (prop.type) {
         case GameEventType::String:
            *reinterpret_cast<std::string*>(valuePtr) = key.val_string();
            break;
         case GameEventType::Float:
            *reinterpret_cast<float*>(valuePtr) = key.val_float();
            break;
         case GameEventType::Long:
            *reinterpret_cast<int32_t*>(valuePtr) = key.val_long();
            break;
         case GameEventType::Short:
            *reinterpret_cast<int16_t*>(valuePtr) = key.val_short();
            break;
         case GameEventType::Byte:
            *reinterpret_cast<uint8_t*>(valuePtr) = key.val_byte();
            break;
         case GameEventType::Bool:
            *reinterpret_cast<bool*>(valuePtr) = key.val_bool();
            break;
         case GameEventType::Uint64:
            *reinterpret_cast<uint64_t*>(valuePtr) = key.val_uint64();
            break;
         }
      }

      mTickData.gameEvents.push_back(std::make_pair(&descriptor, gameEvent));
   } else {
      // TODO: Fall back to slow dynamic game event!
   }

   return true;
}

bool DemoParser::handleGameEventList(const CSVCMsg_GameEventList &list)
{
   for (auto i = 0; i < list.descriptors_size(); ++i) {
      auto &desc = list.descriptors(i);
      auto id = desc.eventid();

      if (mGameEventDescriptors.size() <= id) {
         mGameEventDescriptors.resize(id + 1);
      }

      auto &event = mGameEventDescriptors[id];
      event.id = id;
      event.name = desc.name();
      event.gameEventClass = GameEventList::get(event.name);

      for (auto j = 0; j < desc.keys_size(); ++j) {
         auto &key = desc.keys(j);
         auto offset = static_cast<std::ptrdiff_t>(-1);

         if (event.gameEventClass) {
            auto prop = event.gameEventClass->findProperty(key.name());

            if (prop) {
               offset = prop->offset;
            }
         }

         event.properties.push_back({ key.type(), key.name(), offset });
      }
   }

   return true;
}

}
