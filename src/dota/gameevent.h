#pragma once
#include <map>
#include <string>
#include <vector>
#include <cstdint>

#include "stringtable.h"

class CSVCMsg_GameEvent;

namespace dota
{

using GameEventID = std::size_t;
class GameEventBase;

enum class GameEventType
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
   struct Property
   {
      std::size_t type;
      std::string name;
      std::ptrdiff_t offset;
   };

   std::size_t id;
   std::string name;
   std::vector<Property> properties;
   const GameEventBase *gameEventClass;
};

struct GameEvent
{
   GameEvent() = delete;
   GameEvent(const GameEvent&) = delete;
   GameEvent& operator=(const GameEvent&) = delete;
   ~GameEvent() = delete;
};

struct GameEventProperty
{
   std::size_t id;
   GameEventType type;
   std::ptrdiff_t offset;
};

class GameEventBase
{
public:
   virtual GameEvent *create() const = 0;
   virtual void destroy(GameEvent *event) const = 0;

   const GameEventProperty *findProperty(const std::string &name) const
   {
      auto itr = properties.find(name);

      if (itr != properties.end()) {
         return &itr->second;
      } else {
         return nullptr;
      }
   }

   std::string name;
   std::map<std::string, GameEventProperty> properties;
};

class GameEventList
{
public:
   static const GameEventBase* get(const std::string &name)
   {
      auto itr = mGameEventMap.find(name);

      if (itr != mGameEventMap.end()) {
         return itr->second;
      } else {
         return nullptr;
      }
   }

   static std::map<std::string, const GameEventBase*> mGameEventMap;
};

template<typename Type>
struct GameEventClass
{
};

template<typename Type>
struct get_game_event_property_type
{
   static const auto value = GameEventType::Invalid;
   static_assert(get_game_event_property_type<Type>::value != GameEventType::Invalid,
                 "Invalid game event property type.");
};

template<>
struct get_game_event_property_type<std::string>
{
   static const auto value = GameEventType::String;
};

template<>
struct get_game_event_property_type<float>
{
   static const auto value = GameEventType::Float;
};

template<>
struct get_game_event_property_type<int32_t>
{
   static const auto value = GameEventType::Long;
};

template<>
struct get_game_event_property_type<int16_t>
{
   static const auto value = GameEventType::Short;
};

template<>
struct get_game_event_property_type<uint8_t>
{
   static const auto value = GameEventType::Byte;
};

template<>
struct get_game_event_property_type<bool>
{
   static const auto value = GameEventType::Bool;
};

template<>
struct get_game_event_property_type<uint64_t>
{
   static const auto value = GameEventType::Uint64;
};

#define DeclareGameEvent(ClassName) \
   template<> \
   struct GameEventClass<event::ClassName> : public GameEventBase { \
      static GameEventClass<event::ClassName> Instance; \
      static const GameEventBase *InstancePtr; \
      using WrappedClass = event::ClassName; \
      GameEventClass(); \
      virtual GameEvent *create() const override; \
      virtual void destroy(GameEvent *event) const override; \
   };

#define BeginGameEvent(ClassName) \
   GameEventClass<event::ClassName> GameEventClass<event::ClassName>::Instance; \
   const GameEventBase *GameEventClass<event::ClassName>::InstancePtr = reinterpret_cast<GameEventBase*>(&GameEventClass<event::ClassName>::Instance); \
   GameEvent *GameEventClass<event::ClassName>::create() const { \
      return reinterpret_cast<GameEvent*>(new event::ClassName());\
   } \
   void GameEventClass<event::ClassName>::destroy(GameEvent *event) const { \
      delete reinterpret_cast<event::ClassName*>(event); \
   } \
   GameEventClass<event::ClassName>::GameEventClass() \
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
