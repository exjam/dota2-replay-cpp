#include <iostream>
#include <fstream>
#include <set>

#include "binarystream.h"
#include "demoparser.h"
#include "gameevent.h"

std::string getSafeVarName(std::string name)
{
   // player_class.class
   if (name.compare("class") == 0) {
      return "class_";
   }

   return name;
}

void dumpDeclaration(std::ostream &out, const dota::GameEventDescriptor *event)
{
   out << "struct " << event->name << std::endl;
   out << "{" << std::endl;

   for (auto &&prop : event->properties) {
      out << "   ";

      switch (prop.type) {
      case dota::GameEventType::String:
         out << "std::string ";
         break;
      case dota::GameEventType::Float:
         out << "float ";
         break;
      case dota::GameEventType::Long:
         out << "int32_t ";
         break;
      case dota::GameEventType::Short:
         out << "int16_t ";
         break;
      case dota::GameEventType::Byte:
         out << "uint8_t ";
         break;
      case dota::GameEventType::Bool:
         out << "bool ";
         break;
      case dota::GameEventType::Uint64:
         out << "uint64_t ";
         break;
      }

      out << getSafeVarName(prop.name) << ";" << std::endl;
   }

   out << "};" << std::endl;
   out << std::endl;
}

void dumpDefinition(std::ostream &out, const dota::GameEventDescriptor *event)
{
   out << "BeginGameEvent(" << event->name << ");" << std::endl;

   for (auto &&prop : event->properties) {
      out << "   ";
      out << "GameEventProperty(" << getSafeVarName(prop.name) << ");" << std::endl;
   }

   out << "EndGameEvent();" << std::endl;
}

void getRequiredIncludes(const dota::GameEventDescriptor *event, std::set<std::string> &headers)
{
   for (auto &&prop : event->properties) {
      switch (prop.type) {
      case dota::GameEventType::String:
         headers.insert("<string>");
         break;
      case dota::GameEventType::Long:
      case dota::GameEventType::Short:
      case dota::GameEventType::Byte:
      case dota::GameEventType::Uint64:
         headers.insert("<cstdint>");
         break;
      }
   }
}


int main()
{
   auto file = std::ifstream { "1151921935.dem", std::ifstream::binary };
   auto in = BinaryStream { file };
   auto demo = dota::DemoParser { };
   demo.parse(in, dota::ParseProfile::GameEventDescriptors);

   auto &eventList = demo.gameEventDescriptors();
   std::map<std::string, const dota::GameEventDescriptor*> events;

   for (auto &&event : eventList) {
      if (!event.name.size()) {
         continue;
      }

      events[event.name] = &event;
   }

   for (auto &&evpair : events) {
      std::set<std::string> includes;
      getRequiredIncludes(evpair.second, includes);

      std::ofstream header;
      header.open("src/dota/event/" + evpair.first + ".h");
      header << "#pragma once" << std::endl;

      for (auto &&include : includes) {
         header << "#include " << include << std::endl;
      }

      header << "#include \"gameevent.h\"" << std::endl;

      header << std::endl;
      header << "namespace dota" << std::endl;
      header << "{" << std::endl;
      header << std::endl;
      header << "namespace event" << std::endl;
      header << "{" << std::endl;
      header << std::endl;
      dumpDeclaration(header, evpair.second);
      header << "}" << std::endl;
      header << std::endl;
      header << "DeclareGameEvent(" << evpair.first << ");" << std::endl;
      header << std::endl;
      header << "}" << std::endl;
      header.close();
   }

   std::ofstream source;
   source.open("src/dota/event/definitions.cpp");

   for (auto &&evpair : events) {
      source << "#include \"" << evpair.first << ".h\"" << std::endl;
   }

   source << std::endl;
   source << "namespace dota" << std::endl;
   source << "{" << std::endl;
   source << std::endl;

   for (auto &&evpair : events) {
      dumpDefinition(source, evpair.second);
      source << std::endl;
   }

   source << "std::map<std::string, const GameEventBase*> GameEventList::mGameEventMap = {" << std::endl;

   for (auto &&evpair : events) {
      source << "   { "
             << "\"" << evpair.first << "\", "
             << "GameEventClass<event::" << evpair.first << ">::InstancePtr"
             << " },"
             << std::endl;
   }

   source << "};" << std::endl;

   source << std::endl;
   source << "}" << std::endl;

   source.close();
   return 0;
}
