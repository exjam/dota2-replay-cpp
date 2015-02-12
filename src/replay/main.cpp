#include <iostream>
#include <fstream>
#include <chrono>

#include "entity/CDOTA_PlayerResource.h"
#include "entity/CDOTAGamerulesProxy.h"
#include "event/dota_courier_lost.h"

#include "byteview.h"
#include "demoparser.h"
#include "clientclass.h"

class ReplayAnalyser
{
public:
   ReplayAnalyser()
   {
      mDemo.setOnTickEventListener(std::bind(&ReplayAnalyser::onDemoTick, this, std::placeholders::_1, std::placeholders::_2));
   }

   void analyse(std::string filename)
   {
      auto file = std::ifstream { filename, std::ifstream::binary };
      file.seekg(0, file.end);

      auto size = static_cast<std::size_t>(file.tellg());
      file.seekg(0, file.beg);
      
      auto data = std::vector<char> {};
      data.resize(size);
      file.read(data.data(), size);

      mInGameTime = std::chrono::seconds(0);
      mTick = 0;

      auto in = ByteView { data.data(), size };
      mDemo.parse(in, dota::ParseProfile::FullReplay);
   }

   void onDemoTick(dota::Tick tick, const dota::TickData &data)
   {
      for (auto &&enterEntity : data.enterEntity) {
         onEntityEnter(enterEntity);
      }

      for (auto &&deleteEntity : data.deleteEntity) {
         onEntityDelete(deleteEntity);
      }

      for (auto &&event : data.events) {
         onGameEvent(&event);
      }

      if (mPlayerResource && mGameRules && mGameRules->dota_gamerules_data.m_flGameStartTime > 0.0f) {
         auto dt = mGameRules->dota_gamerules_data.m_fGameTime - mGameRules->dota_gamerules_data.m_flGameStartTime;
         auto time = std::chrono::seconds(static_cast<long long>(dt));

         if (time != mInGameTime) {
            if ((time.count() % 5) == 0) {
               for (auto i = 0u; i < mPlayerSamples.size(); ++i) {
                  SampleData &sample = mPlayerSamples[i];
                  sample.lastHits.push_back(mPlayerResource->m_iLastHitCount[i]);
                  sample.denies.push_back(mPlayerResource->m_iDenyCount[i]);
               }
            }

            mInGameTime = time;
         }
      }

      mTick = tick;
   }

   void onGameEvent(const dota::Event *event)
   {
      if (dota::is_a<dota::event::dota_courier_lost>(event)) {
         auto courierLost = dota::make_event_ptr<dota::event::dota_courier_lost>(event);
         std::cout << "Courier Lost: " << courierLost->teamnumber << std::endl;
      }
   }

   void onEntityEnter(const dota::Entity *entity)
   {
      if (dota::is_a<dota::CDOTA_PlayerResource>(entity)) {
         mPlayerResource = dota::make_entity_ptr<dota::CDOTA_PlayerResource>(entity);
      }

      if (dota::is_a<dota::CDOTAGamerulesProxy>(entity)) {
         mGameRules = dota::make_entity_ptr<dota::CDOTAGamerulesProxy>(entity);
      }
   }

   void onEntityDelete(const dota::EntityHandle &handle)
   {
      if (mPlayerResource == handle) {
         mPlayerResource = nullptr;
      }

      if (mGameRules == handle) {
         mGameRules = nullptr;
      }
   }

private:
   struct SampleData {
      std::vector<std::size_t> lastHits;
      std::vector<std::size_t> denies;
   };

   std::array<SampleData, 10> mPlayerSamples;

   std::chrono::seconds mInGameTime;
   dota::Tick mTick;
   dota::DemoParser mDemo;
   dota::entity_ptr<dota::CDOTA_PlayerResource> mPlayerResource;
   dota::entity_ptr<dota::CDOTAGamerulesProxy> mGameRules;
};

int main()
{
   std::chrono::time_point<std::chrono::system_clock> start, end, destruct;
   start = std::chrono::system_clock::now();
   {
      ReplayAnalyser analyser;
      analyser.analyse("1151921935.dem");
      end = std::chrono::system_clock::now();
   }
   destruct = std::chrono::system_clock::now();

   std::chrono::duration<double> elapsed1 = end - start;
   std::chrono::duration<double> elapsed2 = destruct - end;
   std::cout << "Finished analysis! Time1: " << elapsed1.count() << " Time2: " << elapsed2.count() << std::endl;
   return 0;
}
