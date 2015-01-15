#pragma once
#include <cstdint>
#include "networkclass.h"
#include <string>

namespace dota
{

struct CColorCorrectionVolume
{
   float m_Weight;
   std::string m_lookupFilename;
};

DeclareNetworkClass(CColorCorrectionVolume);

}
