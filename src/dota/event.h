#pragma once
#include <string>
#include <vector>
#include "clientevent.h"

namespace dota
{

using EventID = size_t;

struct EventProperty
{
   EventPropertyType type;
   std::string name;
   std::ptrdiff_t offset;
};

struct EventDescriptor
{
   std::size_t id;
   std::string name;
   std::vector<EventProperty> properties;
   ClientEventID clientEventID;
   const ClientEventBase *clientEventClass;
};

struct Event
{
   const EventDescriptor *classInfo;
   ClientEvent *clientEvent;
};

template<typename EventType>
bool is_a(const Event *event)
{
   assert(event && event->classInfo);
   return event->classInfo->clientEventID == dota::ClientEventClass<EventType>::ClassID;
}

template<typename EventType>
bool is_a(const Event &event)
{
   return is_a<EventType>(&event);
}

template<typename EventType>
class event_ptr
{
public:
   event_ptr() :
      mEvent(nullptr)
   {
   }

   event_ptr(const Event *event)
   {
      *this = event;
   }

   event_ptr &operator=(const Event *event)
   {
      assert(event && event->classInfo);
      assert(is_a<EventType>(event));
      mEvent = event;
      return *this;
   }

   operator bool() const
   {
      return mEvent != nullptr;
   }

   const EventType *operator->() const
   {
      return reinterpret_cast<EventType*>(mEvent->clientEvent);
   }

private:
   const Event *mEvent;
};

template<typename EventType>
event_ptr<EventType> make_event_ptr(const Event *event)
{
   return { event };
}

template<typename EventType>
event_ptr<EventType> make_event_ptr(const Event &event)
{
   return make_event_ptr<EventType>(&event);
}

}
