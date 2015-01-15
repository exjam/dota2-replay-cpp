#pragma once
#include <cstdint>
#include "networkclass.h"
#include <string>
#include "CBaseEntity.h"

namespace dota
{

struct CMovieDisplay : public CBaseEntity
{
   uint32_t m_bEnabled;
   uint32_t m_bLooping;
   std::string m_szMovieFilename;
   std::string m_szGroupName;
};

DeclareNetworkClass(CMovieDisplay);

}
