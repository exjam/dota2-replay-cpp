#include <string>
#include <vector>
#include <Windows.h>
#include <psapi.h>
#include <iostream>
#include <vector>
#pragma comment( lib, "psapi.lib" )
struct TestA
{
   std::string a;
   std::string b;
};

struct TestB
{
   char a[sizeof(std::string)];
   char b[sizeof(std::string)];
};

int main(int argc, char **argv)
{
   {
      std::vector < TestA >
         ActiveModifiers,
         CombatLogNames,
         CooldownNames,
         EconItems,
         EffectDispatch,
         ExtraParticleFilesTable,
         GameRulesCreation,
         InfoPanel,
         Materials,
         ModifierNames,
         ParticleEffectNames,
         ResponseKeys,
         Scenes,
         VguiScreen,
         decalprecache,
         downloadables,
         dynamicmodel,
         genericprecache,
         instancebaseline,
         lightstyles,
         modelprecache,
         server_query_info,
         soundprecache,
         userinfo;

      PROCESS_MEMORY_COUNTERS pmc;
      GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
      std::cout << "WorkingSetSize: " << pmc.WorkingSetSize << std::endl;

      ActiveModifiers.resize(4096);
      CombatLogNames.resize(1024);
      CooldownNames.resize(1024);
      EconItems.resize(1024);
      EffectDispatch.resize(1024);
      ExtraParticleFilesTable.resize(1024);
      GameRulesCreation.resize(1);
      InfoPanel.resize(128);
      Materials.resize(1024);
      ModifierNames.resize(2048);
      ParticleEffectNames.resize(16384);
      ResponseKeys.resize(32768);
      Scenes.resize(8192);
      VguiScreen.resize(256);
      decalprecache.resize(512);
      downloadables.resize(8192);
      dynamicmodel.resize(1024);
      genericprecache.resize(512);
      instancebaseline.resize(1024);
      lightstyles.resize(64);
      modelprecache.resize(1024);
      server_query_info.resize(4);
      soundprecache.resize(32768);
      userinfo.resize(64);

      GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
      std::cout << "WorkingSetSize: " << pmc.WorkingSetSize << std::endl;
   }

   {
      std::vector < TestB >
         ActiveModifiers,
         CombatLogNames,
         CooldownNames,
         EconItems,
         EffectDispatch,
         ExtraParticleFilesTable,
         GameRulesCreation,
         InfoPanel,
         Materials,
         ModifierNames,
         ParticleEffectNames,
         ResponseKeys,
         Scenes,
         VguiScreen,
         decalprecache,
         downloadables,
         dynamicmodel,
         genericprecache,
         instancebaseline,
         lightstyles,
         modelprecache,
         server_query_info,
         soundprecache,
         userinfo;

      PROCESS_MEMORY_COUNTERS pmc;
      GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
      std::cout << "WorkingSetSize: " << pmc.WorkingSetSize << std::endl;

      ActiveModifiers.resize(4096);
      CombatLogNames.resize(1024);
      CooldownNames.resize(1024);
      EconItems.resize(1024);
      EffectDispatch.resize(1024);
      ExtraParticleFilesTable.resize(1024);
      GameRulesCreation.resize(1);
      InfoPanel.resize(128);
      Materials.resize(1024);
      ModifierNames.resize(2048);
      ParticleEffectNames.resize(16384);
      ResponseKeys.resize(32768);
      Scenes.resize(8192);
      VguiScreen.resize(256);
      decalprecache.resize(512);
      downloadables.resize(8192);
      dynamicmodel.resize(1024);
      genericprecache.resize(512);
      instancebaseline.resize(1024);
      lightstyles.resize(64);
      modelprecache.resize(1024);
      server_query_info.resize(4);
      soundprecache.resize(32768);
      userinfo.resize(64);

      GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
      std::cout << "WorkingSetSize: " << pmc.WorkingSetSize << std::endl;
   }

   return 0;
}

#if 0
#define WIN32
#define HAVE_REMOTE
#include <pcap.h>

#include <iostream>
#include <string>
#include <vector>
#include <functional>

namespace ncap
{

enum class DeviceFlags
{
   None,
   LoopBack,
};

enum class AddressFamily
{
   Unknown,
   IPv4,
   IPv6
};

struct Address
{
   AddressFamily family;
   std::string ip;
   std::string netmask;
   std::string broadcast;
   std::string destination;
};

struct Device
{
   ~Device()
   {
      close();
   }

   std::string name;
   std::string description;
   DeviceFlags flags;
   std::vector<Address> addresses;
   pcap_t *devicePtr = 0;

   bool open()
   {
      char err[PCAP_ERRBUF_SIZE];
      devicePtr = pcap_open(name.c_str(), 65536, 0, 20, nullptr, err);

      if (!devicePtr) {
         std::cerr << "Error: pcap_open = %s" << err << std::endl;
         return false;
      }

      return true;
   }

   bool close()
   {
      if (devicePtr) {
         pcap_close(devicePtr);
         devicePtr = nullptr;
      }

      return true;
   }
};

std::string getSockAddrIP(const sockaddr *addr)
{
   char buffer[PCAP_ERRBUF_SIZE];
   std::size_t size;

   if (addr) {
      if (addr->sa_family == AF_INET) {
         size = sizeof(sockaddr_in);
      } else {
         size = sizeof(sockaddr_in6);
      }

      getnameinfo(addr, sizeof(sockaddr_in), buffer, PCAP_ERRBUF_SIZE, nullptr, 0, NI_NUMERICHOST);
   }

   return buffer;
}

std::vector<Device> findAllDevices()
{
   char buffer[PCAP_ERRBUF_SIZE];
   std::vector<Device> devices;
   pcap_if_t *pcapDevices;

   if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, nullptr, &pcapDevices, buffer) == -1) {
      std::cerr << "Error: pcap_findalldevs_ex = %s" << buffer << std::endl;
   } else {
      for(auto pcapDevice = pcapDevices; pcapDevice; pcapDevice = pcapDevice->next) {
         Device device;
         device.name = pcapDevice->name;
         device.description = pcapDevice->description;
         device.flags = static_cast<DeviceFlags>(pcapDevice->flags);

         for (auto pcapAddress = pcapDevice->addresses; pcapAddress; pcapAddress = pcapAddress->next) {
            Address address;

            switch (pcapAddress->addr->sa_family) {
            case AF_INET:
               address.ip = getSockAddrIP(pcapAddress->addr);
               address.netmask = getSockAddrIP(pcapAddress->netmask);
               address.broadcast = getSockAddrIP(pcapAddress->broadaddr);
               address.destination = getSockAddrIP(pcapAddress->dstaddr);
               break;
            case AF_INET6:
               address.ip = getSockAddrIP(pcapAddress->addr);
               break;
            }

            device.addresses.push_back(address);
         }

         devices.push_back(device);
      }

      pcap_freealldevs(pcapDevices);
   }

   return devices;
}

}

int main(int argc, char **argv)
{
   auto devices = ncap::findAllDevices();
   for (auto &device : devices) {
      std::cout << device.name << " " << device.description << std::endl;
      if (device.open()) {

      }
   }

   return 0;
}
#endif
