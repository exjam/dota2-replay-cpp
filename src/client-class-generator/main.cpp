#include <algorithm>
#include <cctype>
#include <iostream>
#include <fstream>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "byteview.h"
#include "demoparser.h"

// We build without libdotaevent and libdotaentity, so define empty maps
namespace dota
{
   std::map<std::string, const GameEventBase*> GameEventList::mGameEventMap = {};
   std::map<std::string, const ClientClassBase*> ClientClassList::mClassMap = {};
};

// I am lazy
dota::DemoParser demo;
std::map<std::string, std::string> dtDefinition;

// Remove " because 1 variable has it. volvo pls
std::string makeSafeVarName(std::string varName)
{
   varName.erase(std::remove(varName.begin(), varName.end(), '"'), varName.end());
   return varName;
}

// Split string s by delim into elems
void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

// Find a class by its table name
std::string getClassName(std::string dtName)
{
   auto entityClass = demo.findClassByTableName(dtName);

   if (entityClass) {
      return entityClass->name;
   } else {
      return "";
   }
}

// Get the C++ typename of a PropertyType
std::string getPropertyValueTypename(dota::Property &prop)
{
   switch (prop.type) {
   case dota::PropertyType::Int:
      if (prop.isUnsigned()) {
         return "uint32_t";
      } else {
         return "int32_t";
      }
   case dota::PropertyType::Int64:
      if (prop.isUnsigned()) {
         return "uint64_t";
      } else {
         return "int64_t";
      }
   case dota::PropertyType::Float:
      return "float";
   case dota::PropertyType::Vector:
      return "Vector3f";
   case dota::PropertyType::VectorXY:
      return "Vector2f";
   case dota::PropertyType::String:
      return "std::string";
   case dota::PropertyType::Array:
      return "std::vector";
   case dota::PropertyType::DataTable:
   {
      auto className = getClassName(prop.dtName);

      if (className.size()) {
         return className;
      } else {
         return prop.dtName;
      }
   }
   default:
      return {};
   }
}

/* Check if property is an array encoded as a DT_ of 0000...nnnn members
 * Or if property is encoded as those weird lengthproxy arrays.
 */
int isPropertyFixedArray(dota::Property &prop)
{
   if (!prop.isDataTable()) {
      return 0;
   }

   if (prop.dtName.find("_ST_" + prop.varName) == 0) {
      // It's a lengthproxy based array
      auto sendTable = demo.findSendTableByName(prop.dtName);
      assert(sendTable->properties.size() > 1);
      assert(sendTable->properties[0].varName.compare("lengthproxy") == 0);
      assert(sendTable->properties[1].varName.compare("0000") == 0);
      return sendTable->properties.size() - 1;
   }

   if (prop.varName.compare(prop.dtName) == 0) {
      // It's a static array
      auto sendTable = demo.findSendTableByName(prop.dtName);
      assert(sendTable->properties.size());
      assert(sendTable->properties[0].varName.compare("0000") == 0);
      return sendTable->properties.size();
   }

   return 0;
}

// Find out if we need to write a struct DT_x or add a #include <classname.h>
void findDependencies(dota::SendTable *table, std::set<std::string> &structDeps, std::set<std::string> &classDeps, std::set<std::string> &headers)
{
   for (dota::Property &prop : table->properties) {
      if (prop.varName.compare("baseclass") == 0) {
         classDeps.insert(getClassName(prop.dtName));
         continue;
      }

      if (prop.isExcluded()) {
         continue;
      }

      if (prop.type == dota::PropertyType::String) {
         headers.insert("<string>");
      }

      if (prop.type == dota::PropertyType::Array) {
         headers.insert("<vector>");
      }

      if (prop.type == dota::PropertyType::Vector) {
         headers.insert("\"vector3f.h\"");
      }

      if (prop.type == dota::PropertyType::VectorXY) {
         headers.insert("\"vector2f.h\"");
      }

      // Lets be lazy & safe
      if (prop.isVectorElement()) {
         headers.insert("\"vector3f.h\"");
         headers.insert("\"vector2f.h\"");
      }

      if (isPropertyFixedArray(prop)) {
         auto sendTable = demo.findSendTableByName(prop.dtName);
         auto &arrayType = sendTable->properties.back();

         if (arrayType.isDataTable()) {
            auto className = getClassName(arrayType.dtName);

            if (className.size()) {
               classDeps.insert(className);
            } else {
               structDeps.insert(arrayType.dtName);
               findDependencies(demo.findSendTableByName(arrayType.dtName), structDeps, classDeps, headers);
            }
         }

         continue;
      }

      if (prop.isDataTable()) {
         auto className = getClassName(prop.dtName);
         if (className.size()) {
            classDeps.insert(className);
         } else {
            structDeps.insert(prop.dtName);
            findDependencies(demo.findSendTableByName(prop.dtName), structDeps, classDeps, headers);
         }
      }
   }
}

/* Group vector properties that have been encoded as:
 *    varName[0]; Flags: VectorElem
 *    ...
 *    varName[N]; Flags: VectorElem
 */
void findVectorElems(dota::SendTable *table, std::map<std::string, int> &vectors)
{
   for (dota::Property &prop : table->properties) {
      if (prop.isInsideArray() || prop.isExcluded()) {
         continue;
      }

      if (!prop.isVectorElement()) {
         continue;
      }

      std::smatch match;
      std::regex_match(prop.varName, match, std::regex("([^[]*)\\[([0-9])\\]"));

      if (match.size() != 3) {
         continue;
      }

      assert(prop.type == dota::PropertyType::Float);

      auto name = match.str(1);
      auto index = std::atoi(match.str(2).c_str());
      auto itr = vectors.find(name);

      if (itr != vectors.end()) {
         index = std::max(itr->second, index);
      }

      vectors[name] = index;
   }
}

/* Group array properties that have been encoded as:
 *    varName[0];
 *    ...
 *    varName[N];
 */
void findFunkyArrays(dota::SendTable *table, std::map<std::string, int> &funkyArrays)
{
   for (dota::Property &prop : table->properties) {
      if (prop.isInsideArray() || prop.isExcluded() || prop.isVectorElement()) {
         continue;
      }

      std::smatch match;
      std::regex_match(prop.varName, match, std::regex("([^[]*)\\[([0-9])\\]"));

      if (match.size() != 3) {
         continue;
      }

      auto name = match.str(1);
      auto index = std::atoi(match.str(2).c_str());
      auto itr = funkyArrays.find(name);

      if (itr != funkyArrays.end()) {
         index = std::max(itr->second, index);
      }

      funkyArrays[name] = index;
   }
}

// Dump a SendTable members as C++ variables
void dumpStructure(std::ostream &out, dota::SendTable *table)
{
   dota::Property *arrayType = nullptr;
   std::map<std::string, int> funkyArrays;
   std::map<std::string, int> vectors;
   std::vector<std::string> activePath;
   std::string indent = "   ";
   std::string activeIndent = indent;
   findVectorElems(table, vectors);
   findFunkyArrays(table, funkyArrays);

   for (dota::Property &prop : table->properties) {
      if (prop.isInsideArray()) {
         arrayType = &prop;
         continue;
      }

      if (prop.varName.compare("baseclass") == 0) {
         continue;
      }

      if (prop.isExcluded()) {
         continue;
      }

      auto vecItr = vectors.find(prop.varName);
      if (prop.isVectorElement() || vecItr != vectors.end()) {
         std::smatch match;
         std::regex_match(prop.varName, match, std::regex("([^[]*)\\[([0-9])\\]"));
         auto index = 0;
         auto name = prop.varName;

         if (match.size() == 3) {
            name = match.str(1);
            index = std::atoi(match.str(2).c_str());

            if (vecItr == vectors.end()) {
               vecItr = vectors.find(name);
            }
         }

         if (index != 0) {
            // Only print on the first element
            continue;
         }

         // Print the correct size
         assert (vecItr != vectors.end());
         index = vecItr->second;

         if (index == 1) {
            out << activeIndent << "Vector2f " << name;
         } else if (index == 2) {
            out << activeIndent << "Vector3f " << name;
         } else {
            assert(false);//BAD
         }
      } else if (int arrayLength = isPropertyFixedArray(prop)) {
         auto sendTable = demo.findSendTableByName(prop.dtName);
         out << activeIndent << getPropertyValueTypename(sendTable->properties.back());
         out << " " << makeSafeVarName(prop.varName);
         out << "[" << arrayLength << "]";
      } else {
         if (prop.varName.find_first_of('.') != std::string::npos) {
            std::vector<std::string> path;

            // Figure out our anonymous struct path
            split(prop.varName, '.', path);
            path.erase(path.end() - 1);

            // Find where it matches the current patch
            auto samePath = 0u;

            for (samePath = 0; samePath < activePath.size() && samePath < path.size(); ++samePath) {
               if (activePath[samePath].compare(path[samePath]) != 0) {
                  break;
               }
            }

            // Pop out of activePath until we reach the common path
            for (auto i = activePath.size() - 1; i >= samePath; --i) {
               activeIndent.erase(activeIndent.begin(), activeIndent.begin() + indent.size());
               out << activeIndent << "} " << activePath[i] << ";" << std::endl;
            }

            // Open new structs from common path until we reach the new path
            for (auto i = samePath; i < path.size(); ++i) {
               out << activeIndent << "struct {" << std::endl;
               activeIndent += indent;
            }

            activePath = path;
         } else {
            if (activePath.size()) {
               // Close all anonymous structs
               for (auto &name : activePath) {
                  activeIndent.erase(activeIndent.begin(), activeIndent.begin() + indent.size());
                  out << activeIndent << "} " << name << ";" << std::endl;
               }

               activePath.clear();
            }
         }

         std::string varName = prop.varName;

         // Fixup funkyArrays
         if (varName.find_first_of('[') != std::string::npos) {
            std::smatch match;
            std::regex_match(prop.varName, match, std::regex("([^[]*)\\[([0-9])\\]"));

            if (match.size() == 3) {
               auto name = match.str(1);
               auto index = std::atoi(match.str(2).c_str());
               auto itr = funkyArrays.find(name);

               if (itr != funkyArrays.end()) {
                  if (index != itr->second) {
                     continue;
                  } else {
                     varName = name + "[" + std::to_string(index + 1) + "]";
                  }
               }
            }
         }

         out << activeIndent << getPropertyValueTypename(prop);

         // Do a vector template type std::vector<ArrayType>
         if (prop.isArray()) {
            assert(!!arrayType);
            // We do not support std::vector<DT_Type>
            assert(arrayType->type != dota::PropertyType::DataTable);
            out << "<" << getPropertyValueTypename(*arrayType) << ">";
            arrayType = nullptr;
         }

         out << " ";

         // Trim off annonymous struct path name
         if (activePath.size()) {
            int skipSize = 0;
            for (auto &name : activePath) {
               skipSize += name.size() + 1;
            }

            varName = varName.substr(skipSize);
         }

         out << makeSafeVarName(varName);
      }

      out << ";" << std::endl;
   }

   // Close any remaining open structs
   if (activePath.size()) {
      for (auto &name : activePath) {
         activeIndent.erase(activeIndent.begin(), activeIndent.begin() + indent.size());
         out << activeIndent << "} " << name << ";" << std::endl;
      }

      activePath.clear();
   }
}

bool doesDependOnStruct(dota::SendTable *sendTable, std::string name)
{
   for (dota::Property &prop : sendTable->properties) {
      if (prop.isDataTable()) {
         if (prop.dtName.compare(name) == 0) {
            return true;
         }
      }

      if (isPropertyFixedArray(prop)) {
         auto arrayTable = demo.findSendTableByName(prop.dtName);
         auto &arrayType = arrayTable->properties.back();

         if (arrayType.isDataTable()) {
            if (arrayType.dtName.compare(name) == 0) {
               return true;
            }
         }
      }
   }

   return false;
}

void orderStructDependencies(std::set<std::string> &structDeps, std::vector<std::string> &ordered)
{
   for (auto &dep : structDeps) {
      auto sendTable = demo.findSendTableByName(dep);
      int earliestPos = 0;

      for (auto i = 0u; i < ordered.size(); ++i) {
         if (doesDependOnStruct(sendTable, ordered[i])) {
            earliestPos = i + 1;
         }
      }

      ordered.insert(ordered.begin() + earliestPos, dep);
   }
}

// Write the class.h file
void writeEntityDeclaration(const dota::EntityClass &entityClass, std::ofstream &out)
{
   auto sendTable = entityClass.sendTable;

   // Find all dependencies
   std::set<std::string> structDeps, classDeps, headers;
   headers.insert("\"clientclass.h\"");
   findDependencies(sendTable, structDeps, classDeps, headers);

   // Filter out any DT_ structs which have been declared in other files
   for (auto itr = structDeps.begin(); itr != structDeps.end(); ) {
      auto find = dtDefinition.find(*itr);

      if (find == dtDefinition.end()) {
         dtDefinition[*itr] = entityClass.name;
      } else if (find->second.compare(entityClass.name) != 0){
         classDeps.insert(find->second);
         structDeps.erase(itr++);
         continue;
      }

      ++itr;
   }

   // Write file header
   out << "#pragma once" << std::endl;
   out << "#include <cstdint>" << std::endl;

   for (auto h : headers) {
      out << "#include " << h << std::endl;
   }

   // Include class dependenices
   for (auto dep : classDeps) {
      out << "#include \"" << dep << ".h\"" << std::endl;
   }

   out << std::endl;
   out << "namespace dota" << std::endl;
   out << "{" << std::endl;
   out << std::endl;

   // Named DT_ depedencies
   std::vector<std::string> orderedStructDeps;
   orderStructDependencies(structDeps, orderedStructDeps);

   for (auto &dep : orderedStructDeps) {
      out << "struct " << dep << std::endl;
      out << "{" << std::endl;
      dumpStructure(out, demo.findSendTableByName(dep));
      out << "};" << std::endl;
      out << std::endl;
   }

   // Write our struct!
   std::string baseClass;
   out << "struct " << entityClass.name;

   auto itr = std::find_if(std::begin(sendTable->properties),
                           std::end(sendTable->properties),
                           [](dota::Property &property){
                              return property.varName.compare("baseclass") == 0;
                           });

   if (itr != std::end(sendTable->properties)) {
      baseClass = getClassName(itr->dtName);
   }

   if (baseClass.size()) {
      out << " : public " << baseClass;
   }

   out << std::endl;
   out << "{" << std::endl;
   dumpStructure(out, sendTable);
   out << "};" << std::endl;

   out << std::endl;
   for (auto &dep : orderedStructDeps) {
      out << "DeclareClientStruct(" << dep << ");" << std::endl;
   }
   out << "DeclareClientClass(" << entityClass.name << ");" << std::endl;

   out << std::endl;
   out << "}" << std::endl;
}

void dumpNetworkStructure(dota::SendTable *sendTable, std::ofstream &out)
{
   for (dota::Property &prop : sendTable->properties) {
      if (prop.isExcluded()) {
         continue;
      }

      if (prop.isInsideArray()) {
         continue;
      }

      std::string varName = prop.varName;

      if (varName.compare("baseclass") == 0) {
         continue;
      }

      std::smatch match;
      std::regex_match(varName, match, std::regex("([^[]*)\\[([0-9])\\]"));

      if (match.size() == 3) {
         auto size = std::atoi(match.str(2).c_str());

         if (size != 0) {
            continue;
         }

         varName = match.str(1);
      }

      out << "   " << "AddClientProperty(" << makeSafeVarName(varName) << ");" << std::endl;
   }
}

// Write the class.cpp file
void writeEntityDefinition(const dota::EntityClass &entityClass, std::ofstream &out)
{
   std::set<std::string> structDeps;
   findDependencies(entityClass.sendTable, structDeps, std::set<std::string> {}, std::set<std::string> {});

   // Filter out any DT_ structs which have been declared in other files
   for (auto itr = structDeps.begin(); itr != structDeps.end(); ) {
      auto find = dtDefinition.find(*itr);

      if (find == dtDefinition.end()) {
         dtDefinition[*itr] = entityClass.name;
      } else if (find->second.compare(entityClass.name) != 0){
         structDeps.erase(itr++);
         continue;
      }

      ++itr;
   }

   // Define our DT_ structs
   for (auto &dep : structDeps) {
      out << "BeginClientStruct(" << dep << ");" << std::endl;
      dumpNetworkStructure(demo.findSendTableByName(dep), out);
      out << "EndClientStruct();" << std::endl;
      out << std::endl;
   }

   // Dump our class!
   out << "BeginClientClass(" << entityClass.name << ", " << entityClass.tableName << ");" << std::endl;

   auto baseClass = entityClass.getBaseClass();

   if (baseClass.size()) {
      auto className = getClassName(baseClass);
      if (className.size()) {
         baseClass = className;
      }

      out << "   " << "ClientBaseClass(" << baseClass << ");" << std::endl;
   }

   dumpNetworkStructure(entityClass.sendTable, out);
   out << "EndClientClass();" << std::endl;
   out << std::endl;
}

int main()
{
   auto file = std::ifstream { "1151921935.dem", std::ifstream::binary };
   file.seekg(0, file.end);

   auto size = static_cast<std::size_t>(file.tellg());
   file.seekg(0, file.beg);

   auto data = std::vector<char> {};
   data.resize(size);
   file.read(data.data(), size);

   auto in = ByteView { data.data(), data.size() };
   demo.parse(in, dota::ParseProfile::SendTables);

   for (auto &&entityClass : demo.classList()) {
      if (!entityClass.sendTable) {
         continue;
      }

      std::ofstream header;
      header.open("src/dota/entity/" + entityClass.name + ".h");
      std::cout << entityClass.name << ".h" << std::endl;
      writeEntityDeclaration(entityClass, header);
      header.close();
   }

   std::ofstream source;
   source.open("src/dota/entity/definitions.cpp");
   std::cout << "definitions.cpp" << std::endl;

   for (auto &&entityClass : demo.classList()) {
      source << "#include \"" << entityClass.name << ".h\"" << std::endl;
   }

   source << std::endl;
   source << "namespace dota" << std::endl;
   source << "{" << std::endl;
   source << std::endl;

   for (auto &&entityClass : demo.classList()) {
      if (!entityClass.sendTable) {
         continue;
      }

      writeEntityDefinition(entityClass, source);
   }

   source << "std::map<std::string, const ClientClassBase*> ClientClassList::mClassMap = {" << std::endl;

   for (auto &&entityClass : demo.classList()) {
      if (!entityClass.sendTable) {
         continue;
      }

      source << "   { "
             << "\"" << entityClass.tableName << "\", "
             << "ClientClass<" << entityClass.name << ">::InstancePtr"
             << " },"
             << std::endl;
   }

   source << "};" << std::endl;
   source << std::endl;

   source << "}" << std::endl;
   source.close();
   return 0;
}
