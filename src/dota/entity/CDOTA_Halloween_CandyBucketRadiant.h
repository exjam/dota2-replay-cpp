#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_Halloween_CandyBucket.h"

namespace dota
{

struct CDOTA_Halloween_CandyBucketRadiant : public CDOTA_Halloween_CandyBucket
{
};

DeclareNetworkClass(CDOTA_Halloween_CandyBucketRadiant);

}
