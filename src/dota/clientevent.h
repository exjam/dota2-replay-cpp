#pragma once
#include <map>
#include <string>
#include <vector>
#include <cstdint>

namespace dota
{

enum class EventPropertyType
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

class ClientEventBase;
using ClientEventID = std::size_t;

// ClientEvent must be destroyed through ClientEventBase->destroy(event)
struct ClientEvent
{
   ClientEvent() = delete;
   ClientEvent(const ClientEvent&) = delete;
   ClientEvent& operator=(const ClientEvent&) = delete;
   ~ClientEvent() = delete;
};

// A property within an event class
struct ClientEventProperty
{
   std::size_t id;
   EventPropertyType type;
   std::ptrdiff_t offset;
};

// Reflection for our C++ client events!
class ClientEventBase
{
public:
   virtual ClientEvent *create() const = 0;
   virtual void destroy(ClientEvent *event) const = 0;
   virtual ClientEventID eventID() const = 0;

   const ClientEventProperty *findProperty(const std::string &name) const
   {
      auto itr = properties.find(name);

      if (itr != properties.end()) {
         return &itr->second;
      } else {
         return nullptr;
      }
   }

   std::string name;
   std::map<std::string, ClientEventProperty> properties;
};

// List of all reflected event classes
class ClientEventList
{
public:
   static ClientEventID GetUniqueID();

   static const ClientEventBase* get(const std::string &name)
   {
      auto itr = mEventMap.find(name);

      if (itr != mEventMap.end()) {
         return itr->second;
      } else {
         return nullptr;
      }
   }

   static std::map<std::string, const ClientEventBase*> mEventMap;
};

template<typename Type>
struct ClientEventClass
{
};

template<typename Type>
struct get_game_event_property_type
{
   static const auto value = EventPropertyType::Invalid;
   static_assert(get_game_event_property_type<Type>::value != EventPropertyType::Invalid,
                 "Invalid game event property type.");
};

template<>
struct get_game_event_property_type<std::string>
{
   static const auto value = EventPropertyType::String;
};

template<>
struct get_game_event_property_type<float>
{
   static const auto value = EventPropertyType::Float;
};

template<>
struct get_game_event_property_type<int32_t>
{
   static const auto value = EventPropertyType::Long;
};

template<>
struct get_game_event_property_type<int16_t>
{
   static const auto value = EventPropertyType::Short;
};

template<>
struct get_game_event_property_type<uint8_t>
{
   static const auto value = EventPropertyType::Byte;
};

template<>
struct get_game_event_property_type<bool>
{
   static const auto value = EventPropertyType::Bool;
};

template<>
struct get_game_event_property_type<uint64_t>
{
   static const auto value = EventPropertyType::Uint64;
};

#define DeclareGameEvent(ClassName) \
   template<> \
   struct ClientEventClass<event::ClassName> : public ClientEventBase { \
      static ClientEventClass<event::ClassName> Instance; \
      static const ClientEventBase *InstancePtr; \
      static ClientEventID ClassID; \
      using WrappedClass = event::ClassName; \
      ClientEventClass(); \
      virtual ClientEvent *create() const override; \
      virtual void destroy(ClientEvent *event) const override; \
      virtual ClientEventID eventID() const override; \
   };

#define BeginGameEvent(ClassName) \
   ClientEventClass<event::ClassName> ClientEventClass<event::ClassName>::Instance; \
   ClientEventID ClientEventClass<event::ClassName>::ClassID = ClientEventList::GetUniqueID(); \
   const ClientEventBase *ClientEventClass<event::ClassName>::InstancePtr = reinterpret_cast<ClientEventBase*>(&ClientEventClass<event::ClassName>::Instance); \
   ClientEvent *ClientEventClass<event::ClassName>::create() const { \
      return reinterpret_cast<ClientEvent*>(new event::ClassName());\
   } \
   void ClientEventClass<event::ClassName>::destroy(ClientEvent *event) const { \
      delete reinterpret_cast<event::ClassName*>(event); \
   } \
   ClientEventID ClientEventClass<event::ClassName>::eventID() const { \
      return ClientEventClass<event::ClassName>::ClassID; \
   } \
   ClientEventClass<event::ClassName>::ClientEventClass() \
   { \
      name = #ClassName;

#define GameEventProperty(ValueName) \
   { \
      using value_type = decltype(((WrappedClass*)0)->ValueName); \
      auto &prop = properties[#ValueName]; \
      prop.id = properties.size() - 1; \
      prop.offset = offsetof(WrappedClass, ValueName); \
      prop.type = get_game_event_property_type<value_type>::value; \
   }

#define EndGameEvent() \
   }

}
