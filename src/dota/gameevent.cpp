#include <iostream>

#include "proto/dota_gcmessages_common.pbsl.h"
#include "proto/netmessages.pbsl.h"
#include "proto/networkbasetypes.pbsl.h"

#include "event/dota_combatlog.h"

#include "demoparser.h"
#include "byteview.h"

namespace dota
{

#if 0
bool parseGameEventKey(ProtoBufView &in, GameEvent *gameEvent, GameEventDescriptor::Property *property)
{
   auto valuePtr = std::ptrdiff_t { 0 };
   auto type = GameEventType::Invalid;
   auto length = in.readVarint32();
   auto end = in.tell() + length;

   for (; in.tell() < end;) {
      auto tag = in.readTag();

      switch (in.getField(tag)) {
      case CSVCMsg_GameEvent_key_t::kTypeFieldNumber:
         assert(in.getType(tag) == ProtoBufView::WireType::VarInt);
         type = static_cast<GameEventType>(in.readVarint32());
         assert(property->type == type);
         assert(property->offset != -1);
         valuePtr = property->offset + reinterpret_cast<std::ptrdiff_t>(gameEvent);
         break;
      case CSVCMsg_GameEvent_key_t::kValStringFieldNumber:
         assert(in.getType(tag) == ProtoBufView::WireType::LengthDelimited);
         assert(property->type == GameEventType::String);
         *reinterpret_cast<std::string*>(valuePtr) = in.readStringView().toStdString();
         break;
      case CSVCMsg_GameEvent_key_t::kValFloatFieldNumber:
         assert(in.getType(tag) == ProtoBufView::WireType::Fixed32);
         assert(property->type == GameEventType::Float);
         *reinterpret_cast<float*>(valuePtr) = in.readFloat();
         break;
      case CSVCMsg_GameEvent_key_t::kValLongFieldNumber:
         assert(in.getType(tag) == ProtoBufView::WireType::VarInt);
         assert(property->type == GameEventType::Long);
         *reinterpret_cast<int32_t*>(valuePtr) = in.readVarint32();
         break;
      case CSVCMsg_GameEvent_key_t::kValShortFieldNumber:
         assert(in.getType(tag) == ProtoBufView::WireType::VarInt);
         assert(property->type == GameEventType::Short);
         *reinterpret_cast<int16_t*>(valuePtr) = in.readVarint32();
         break;
      case CSVCMsg_GameEvent_key_t::kValByteFieldNumber:
         assert(in.getType(tag) == ProtoBufView::WireType::VarInt);
         assert(property->type == GameEventType::Byte);
         *reinterpret_cast<uint8_t*>(valuePtr) = in.readVarint32();
         break;
      case CSVCMsg_GameEvent_key_t::kValBoolFieldNumber:
         assert(in.getType(tag) == ProtoBufView::WireType::VarInt);
         assert(property->type == GameEventType::Bool);
         *reinterpret_cast<bool*>(valuePtr) = !!in.readVarint32();
         break;
      case CSVCMsg_GameEvent_key_t::kValUint64FieldNumber:
         assert(in.getType(tag) == ProtoBufView::WireType::VarInt);
         assert(property->type == GameEventType::Uint64);
         *reinterpret_cast<uint64_t*>(valuePtr) = !!in.readVarint64();
         break;
      }
   }

   return true;
}
#endif

bool DemoParser::handleGameEvent(const CSVCMsg_GameEvent &msg)
{
   // TODO: Handle game event using pbsl
#if 0
   GameEventDescriptor *descriptor = nullptr;
   GameEvent *event = nullptr;
   auto stream = ByteView { reinterpret_cast<const char*>(msg.data()), msg.size() };
   auto in = ProtoBufView { stream };
   auto id = 0u;
   auto propID = 0u;

   while (!in.eof()) {
      auto tag = in.readTag();

      switch (in.getField(tag)) {
      case CSVCMsg_GameEvent::kEventNameFieldNumber:
         assert(in.getType(tag) == ProtoBufView::WireType::LengthDelimited);
         in.readStringView(); // skip
         break;
      case CSVCMsg_GameEvent::kEventidFieldNumber:
         assert(in.getType(tag) == ProtoBufView::WireType::VarInt);
         id = in.readVarint32();
         descriptor = &mGameEventDescriptors[id];
         assert(descriptor->gameEventClass);
         event = descriptor->gameEventClass->create();
         break;
      case CSVCMsg_GameEvent::kKeysFieldNumber:
      {
         parseGameEventKey(in, event, &descriptor->properties[propID++]);
         break;
      }
      default:
         assert(0 && "Invalid GameEvent field number");
      }
   }

   if (event) {
      mTickData.gameEvents.push_back(std::make_pair(descriptor, event));
   }
#endif
   return true;
}

bool DemoParser::handleGameEventList(const CSVCMsg_GameEventList &msg)
{
   for (auto i = 0u; i < msg.descriptors.size(); ++i) {
      auto &desc = msg.descriptors[i];

      if (mGameEventDescriptors.size() <= static_cast<unsigned>(desc.eventid)) {
         mGameEventDescriptors.resize(desc.eventid + 1);
      }

      auto &event = mGameEventDescriptors[desc.eventid];
      event.id = desc.eventid;
      event.name = desc.name.to_string();
      event.gameEventClass = GameEventList::get(event.name);

      for (auto j = 0u; j < desc.keys.size(); ++j) {
         auto &key = desc.keys[j];
         auto offset = static_cast<std::ptrdiff_t>(-1);

         if (event.gameEventClass) {
            auto prop = event.gameEventClass->findProperty(key.name.to_string());

            if (prop) {
               offset = prop->offset;
            }
         }

         event.properties.push_back({ static_cast<GameEventType>(key.type), key.name, offset });
      }
   }

   return true;
}

}
