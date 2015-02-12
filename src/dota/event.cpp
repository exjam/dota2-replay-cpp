#include <iostream>

#include "proto/dota_gcmessages_common.pbsl.h"
#include "proto/netmessages.pbsl.h"
#include "proto/networkbasetypes.pbsl.h"

#include "demoparser.h"
#include "byteview.h"

namespace dota
{

ClientEventID ClientEventList::GetUniqueID()
{
   static ClientEventID eventID = 0;
   return ++eventID;
}

bool DemoParser::handleGameEvent(const CSVCMsg_GameEvent &msg)
{
   auto &descriptor = mEventDescriptors[msg.eventid];
   auto event = descriptor.clientEventClass->create();

   for (auto i = 0u; i < msg.keys.size(); ++i) {
      auto &property = descriptor.properties[i];
      auto &key = msg.keys[i];
      auto valuePtr = reinterpret_cast<ptrdiff_t>(event) + property.offset;

      switch (static_cast<EventPropertyType>(key.type))
      {
      case EventPropertyType::String:
         *reinterpret_cast<std::string*>(valuePtr) = key.val_string.to_string();
         break;
      case EventPropertyType::Float:
         *reinterpret_cast<float*>(valuePtr) = key.val_float;
         break;
      case EventPropertyType::Long:
         *reinterpret_cast<int32_t*>(valuePtr) = key.val_long;
         break;
      case EventPropertyType::Short:
         *reinterpret_cast<int16_t*>(valuePtr) = static_cast<int16_t>(key.val_short);
         break;
      case EventPropertyType::Byte:
         *reinterpret_cast<uint8_t*>(valuePtr) = static_cast<uint8_t>(key.val_byte);
         break;
      case EventPropertyType::Bool:
         *reinterpret_cast<bool*>(valuePtr) = !!key.val_bool;
         break;
      case EventPropertyType::Uint64:
         *reinterpret_cast<uint64_t*>(valuePtr) = !!key.val_uint64;
         break;
      }
   }

   if (event) {
      mTickData.events.push_back({ &descriptor, event });
   }

   return true;
}

bool DemoParser::handleGameEventList(const CSVCMsg_GameEventList &msg)
{
   for (auto i = 0u; i < msg.descriptors.size(); ++i) {
      auto &desc = msg.descriptors[i];

      if (mEventDescriptors.size() <= static_cast<unsigned>(desc.eventid)) {
         mEventDescriptors.resize(desc.eventid + 1);
      }

      auto &event = mEventDescriptors[desc.eventid];
      event.id = desc.eventid;
      event.name = desc.name.to_string();
      event.clientEventClass = ClientEventList::get(event.name);
      event.clientEventID = event.clientEventClass ? event.clientEventClass->eventID() : 0;

      for (auto j = 0u; j < desc.keys.size(); ++j) {
         auto &key = desc.keys[j];
         auto offset = static_cast<std::ptrdiff_t>(-1);

         if (event.clientEventClass) {
            auto prop = event.clientEventClass->findProperty(key.name.to_string());

            if (prop) {
               offset = prop->offset;
            }
         }

         event.properties.push_back({ static_cast<EventPropertyType>(key.type), key.name, offset });
      }
   }

   return true;
}

}
