#pragma once
#include <cstdint>
#include "clientclass.h"
#include <string>

namespace dota
{

struct CColorCorrectionVolume
{
   float m_Weight;
   std::string m_lookupFilename;
};

DeclareClientClass(CColorCorrectionVolume);

}
