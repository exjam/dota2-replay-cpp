#pragma once
#include <cstdint>
#include <cassert>
#include <string>
#include <vector>
#include "vector2f.h"
#include "vector3f.h"

class BitStream;

namespace dota
{

enum class PropertyType
{
   Int,
   Float,
   Vector,
   VectorXY,
   String,
   Array,
   DataTable,
   Int64,
   Invalid
};

enum class PropertyFlag
{
   None                    = 0,
   Unsigned                = 1 <<  0,
   Coord                   = 1 <<  1,
   NoScale                 = 1 <<  2,
   RoundDown               = 1 <<  3,
   RoundUp                 = 1 <<  4,
   Normal                  = 1 <<  5,
   Exclude                 = 1 <<  6,
   Xyze                    = 1 <<  7,
   InsideArray             = 1 <<  8,
   ProxyAlways             = 1 <<  9,
   VectorElem              = 1 << 10,
   Collapsible             = 1 << 11,
   CoordMp                 = 1 << 12,
   CoordMpLowPrecision     = 1 << 13,
   CoordMpIntegral         = 1 << 14,
   CellCoord               = 1 << 15,
   CellCoordLowPrecision   = 1 << 16,
   CellCoordIntegral       = 1 << 17,
   ChangesOften            = 1 << 18,
   EncodedAgainstTickCount = 1 << 19
};

struct Property;
struct ElementGetter;

using PropertyInt = int32_t;
using PropertyInt64 = int64_t;
using PropertyFloat = float;
using PropertyVector = Vector3f;
using PropertyVectorXY = Vector2f;
using PropertyString = std::string;

static inline std::size_t operator&(const PropertyFlag &lhs, const PropertyFlag &rhs)
{
   return static_cast<std::size_t>(lhs) & static_cast<std::size_t>(rhs);
}

struct Property
{
   PropertyType type;
   std::string varName;
   std::string dtName;
   std::size_t numElements;
   std::size_t numBits;
   PropertyFlag flags;
   unsigned priority;
   float lowValue;
   float highValue;
   Property *arrayElementType;

   bool isExcluded() const
   {
      return flags & PropertyFlag::Exclude;
   }

   bool isCollapsible() const
   {
      return flags & PropertyFlag::Collapsible;
   }

   bool isChangedOften() const
   {
      return flags & PropertyFlag::ChangesOften;
   }

   bool isEncodedAgainstTickCount() const
   {
      return flags & PropertyFlag::EncodedAgainstTickCount;
   }

   bool isUnsigned() const
   {
      return flags & PropertyFlag::Unsigned;
   }

   bool isNormal() const
   {
      return flags & PropertyFlag::Normal;
   }

   bool isInsideArray() const
   {
      return flags & PropertyFlag::InsideArray;
   }

   bool isVectorElement() const
   {
      return flags & PropertyFlag::VectorElem;
   }

   bool isArray() const
   {
      return type == PropertyType::Array;
   }

   bool isDataTable() const
   {
      return type == PropertyType::DataTable;
   }
};

}
