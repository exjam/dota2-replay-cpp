#include "bitstream.h"
#include "demoparser.h"
#include "property.h"
#include "clientclass.h"
#include "util.h"

namespace dota
{

const auto COORD_INTEGER_BITS = 14;
const auto COORD_FRACTIONAL_BITS = 5;
const auto COORD_DENOMINATOR = (1 << COORD_FRACTIONAL_BITS);
const auto COORD_RESOLUTION = (1.0f / COORD_DENOMINATOR);

const auto COORD_INTEGER_BITS_MP = 11;
const auto COORD_FRACTIONAL_BITS_MP_LOWPRECISION = 3;
const auto COORD_DENOMINATOR_LOWPRECISION = (1 << COORD_FRACTIONAL_BITS_MP_LOWPRECISION);
const auto COORD_RESOLUTION_LOWPRECISION = (1.0f / COORD_DENOMINATOR_LOWPRECISION);

const auto NORMAL_FRACTIONAL_BITS = 11;
const auto NORMAL_DENOMINATOR = ((1 << NORMAL_FRACTIONAL_BITS) - 1);
const auto NORMAL_RESOLUTION = (1.0f / NORMAL_DENOMINATOR);

const auto DT_MAX_STRING_BITS = 9;
const auto DT_MAX_STRING_BUFFERSIZE = 1 << DT_MAX_STRING_BITS;

bool parsePropertyValue(BitStream &in, const Property &sendProp, std::ptrdiff_t valuePtr, ElementGetter *elemGetter);
void parsePropertyArray(BitStream &in, const Property &prop, std::ptrdiff_t containerPtr, ElementGetter *elemGetter);
PropertyInt parsePropertyInt(BitStream &in, const Property &prop);
PropertyInt64 parsePropertyInt64(BitStream &in, const Property &prop);
PropertyString parsePropertyString(BitStream &in, const Property &prop);
PropertyVector parsePropertyVector(BitStream &in, const Property &prop);
PropertyVectorXY parsePropertyVectorXY(BitStream &in, const Property &prop);
PropertyFloat parsePropertyFloat(BitStream &in, const Property &prop);
PropertyFloat parsePropertyFloatDefault(BitStream &in, const Property &prop);
PropertyFloat parsePropertyFloatCellCoordIntegral(BitStream &in, const Property &prop);
PropertyFloat parsePropertyFloatCellCoord(BitStream &in, const Property &prop);
PropertyFloat parsePropertyFloatNormal(BitStream &in, const Property &prop);
PropertyFloat parsePropertyFloatNoScale(BitStream &in, const Property &prop);
PropertyFloat parsePropertyFloatCoordMpLowPrecision(BitStream &in, const Property &prop);
PropertyFloat parsePropertyFloatCoordMpIntegral(BitStream &in, const Property &prop);
PropertyFloat parsePropertyFloatCoordMp(BitStream &in, const Property &prop);
PropertyFloat parsePropertyFloatCoord(BitStream &in, const Property &prop);

bool DemoParser::parseEntityProperties(BitStream &in, EntityClass &entityClass, ClientEntity *entity, EntityPropList &propList)
{
   auto baseOffset = reinterpret_cast<std::ptrdiff_t>(entity);

   for (auto &&propID : propList) {
      auto &prop = entityClass.properties[propID];
      auto *getter = prop.clientProp ? prop.clientProp->elemGetter : nullptr;
      auto offset = static_cast<std::ptrdiff_t>(-1);

      if (baseOffset && prop.offset != -1) {
         offset = baseOffset + prop.offset;
      }

      parsePropertyValue(in, *prop.sendProp, offset, getter);
   }

   return true;
}

bool parsePropertyValue(BitStream &in, const Property &sendProp, std::ptrdiff_t valuePtr, ElementGetter *elemGetter)
{
   switch (sendProp.type) {
   case PropertyType::Int:
   {
      auto value = parsePropertyInt(in, sendProp);

      if (valuePtr != -1) {
         *reinterpret_cast<int32_t*>(valuePtr) = value;
      }

      break;
   }
   case PropertyType::Int64:
   {
      auto value = parsePropertyInt64(in, sendProp);

      if (valuePtr != -1) {
         *reinterpret_cast<int64_t*>(valuePtr) = value;
      }

      break;
   }
   case PropertyType::Float:
   {
      auto value = parsePropertyFloat(in, sendProp);

      if (valuePtr != -1) {
         *reinterpret_cast<float*>(valuePtr) = value;
      }

      break;
   }
   case PropertyType::Vector:
   {
      auto value = parsePropertyVector(in, sendProp);

      if (valuePtr != -1) {
         *reinterpret_cast<Vector3f*>(valuePtr) = value;
      }

      break;
   }
   case PropertyType::VectorXY:
   {
      auto value = parsePropertyVectorXY(in, sendProp);

      if (valuePtr != -1) {
         *reinterpret_cast<Vector2f*>(valuePtr) = value;
      }

      break;
   }
   case PropertyType::String:
   {
      auto value = parsePropertyString(in, sendProp);

      if (valuePtr != -1) {
         *reinterpret_cast<std::string*>(valuePtr) = value;
      }

      break;
   }
   case PropertyType::Array:
      parsePropertyArray(in, sendProp, valuePtr, elemGetter);
      break;
   default:
   case PropertyType::DataTable:
      // Should never happen.
      assert(false);
   }

   return true;
}

void parsePropertyArray(BitStream &in, const Property &prop, std::ptrdiff_t containerPtr, ElementGetter *elemGetter)
{
   auto numBits = getRequiredBits(prop.numElements);
   auto count = in.read<std::size_t>(numBits);
   auto type = prop.arrayElementType;
   assert(prop.arrayElementType);

   for (std::size_t i = 0; i < count; ++i) {
      auto elemPtr = -1;

      if (containerPtr != -1) {
         assert(elemGetter);
         elemGetter->getElementPtr(containerPtr, i);
      }

      parsePropertyValue(in, *type, elemPtr, nullptr);
   }
}

PropertyInt parsePropertyInt(BitStream &in, const Property &prop)
{
   auto value = PropertyInt { 0 };

   if (prop.isEncodedAgainstTickCount()) {
      // TODO: Encoding against tick count
      value = in.readVarInt();
   } else if (prop.isUnsigned()) {
      value = in.read<uint32_t>(prop.numBits);
   } else {
      value = in.read<int32_t>(prop.numBits);
      value = (value << (32 - prop.numBits)) >> (32 - prop.numBits);
   }

   return value;
}

PropertyInt64 parsePropertyInt64(BitStream &in, const Property &prop)
{
   auto value = PropertyInt64 { 0 };

   if (prop.isEncodedAgainstTickCount()) {
      // TODO: Encoding against tick count
      return in.readVarInt();
   }

   auto sign = 0;
   auto bits = prop.numBits;

   if (!prop.isUnsigned()) {
      sign = in.readBit();
      bits--;
   }

   value = in.read<uint64_t>(bits);
   return sign ? -value : value;
}

PropertyFloat parsePropertyFloatCoord(BitStream &in, const Property &prop)
{
   auto value = PropertyFloat { 0 };
   auto hasIntegral = in.readBit();
   auto hasFractional = in.readBit();

   if (!hasIntegral && !hasFractional) {
      return 0.0f;
   }

   auto sign = in.readBit();
   auto integral = 0.0f;
   auto fractional = 0.0f;

   if (hasIntegral) {
      integral = static_cast<float>(in.read<uint32_t>(COORD_INTEGER_BITS) + 1);
   }

   if (hasFractional) {
      fractional = static_cast<float>(in.read<uint32_t>(COORD_FRACTIONAL_BITS));
   }

   value = integral + fractional * COORD_RESOLUTION;
   return sign ? -value : value;
}

PropertyFloat parsePropertyFloatCoordMp(BitStream &in, const Property &prop)
{
   auto value = PropertyFloat { 0 };
   auto inBounds = !!in.readBit();
   auto hasInt = in.readBit();
   auto sign = in.readBit();
   auto integral = 0.0f;

   if (hasInt) {
     if (inBounds) {
       integral = static_cast<PropertyFloat>(in.read<uint32_t>(COORD_INTEGER_BITS_MP) + 1);
     } else {
       integral = static_cast<PropertyFloat>(in.read<uint32_t>(COORD_INTEGER_BITS) + 1);
     }
   }

   auto fractional = static_cast<PropertyFloat>(in.read<uint32_t>(COORD_FRACTIONAL_BITS));
   value = integral + (fractional * COORD_RESOLUTION);
   return sign ? -value : value;
}

PropertyFloat parsePropertyFloatCoordMpIntegral(BitStream &in, const Property &prop)
{
   auto value = PropertyFloat { 0 };
   auto sign = 0;
   auto inBounds = !!in.readBit();

   if (in.readBit()) {
     sign = in.readBit();

     if (inBounds) {
       value = static_cast<PropertyFloat>(in.read<uint32_t>(COORD_INTEGER_BITS_MP) + 1);
     } else {
       value = static_cast<PropertyFloat>(in.read<uint32_t>(COORD_INTEGER_BITS) + 1);
     }
   }

   return sign ? -value : value;
}

PropertyFloat parsePropertyFloatCoordMpLowPrecision(BitStream &in, const Property &prop)
{
   auto value = PropertyFloat { 0 };
   auto inBounds = !!in.readBit();
   auto hasInt = in.readBit();
   auto sign = in.readBit();
   auto integral = 0.0f;

   if (hasInt) {
     if (inBounds) {
       integral = static_cast<float>(in.read<uint32_t>(COORD_INTEGER_BITS_MP) + 1);
     } else {
       integral = static_cast<float>(in.read<uint32_t>(COORD_INTEGER_BITS) + 1);
     }
   }

   auto fractional = static_cast<float>(in.read<uint32_t>(COORD_FRACTIONAL_BITS_MP_LOWPRECISION));
   value = integral + (fractional * COORD_RESOLUTION_LOWPRECISION);
   return sign ? -value : value;
}

PropertyFloat parsePropertyFloatNoScale(BitStream &in, const Property &prop)
{
   auto value = PropertyFloat { 0 };
   value = in.read<float>(32);
   return value;
}

PropertyFloat parsePropertyFloatNormal(BitStream &in, const Property &prop)
{
   auto value = PropertyFloat { 0 };
   auto sign = in.readBit();
   value = static_cast<PropertyFloat>(in.read<uint32_t>(NORMAL_FRACTIONAL_BITS));
   value *= NORMAL_RESOLUTION;
   return sign ? -value : value;
}

PropertyFloat parsePropertyFloatCellCoord(BitStream &in, const Property &prop)
{
   auto value = PropertyFloat { 0 };
   value = static_cast<PropertyFloat>(in.read<uint32_t>(prop.numBits));
   value += COORD_RESOLUTION * static_cast<PropertyFloat>(in.read<uint32_t>(COORD_FRACTIONAL_BITS));
   return value;
}

PropertyFloat parsePropertyFloatCellCoordIntegral(BitStream &in, const Property &prop)
{
   auto value = PropertyFloat { 0 };
   value = static_cast<PropertyFloat>(in.read<uint32_t>(prop.numBits));
   return value;
}

PropertyFloat parsePropertyFloatDefault(BitStream &in, const Property &prop)
{
   auto value = PropertyFloat { 0 };
   value = static_cast<PropertyFloat>(in.read<uint32_t>(prop.numBits));
   value /= (1 << prop.numBits) - 1;
   return value * (prop.highValue - prop.lowValue) + prop.lowValue;
}

PropertyFloat parsePropertyFloat(BitStream &in, const Property &prop)
{
   auto value = PropertyFloat { 0 };

   if (prop.flags & PropertyFlag::Coord) {
      value = parsePropertyFloatCoord(in, prop);
   } else if (prop.flags & PropertyFlag::CoordMp) {
      value = parsePropertyFloatCoordMp(in, prop);
   } else if (prop.flags & PropertyFlag::CoordMpIntegral) {
      value = parsePropertyFloatCoordMpIntegral(in, prop);
   } else if (prop.flags & PropertyFlag::CoordMpLowPrecision) {
      value = parsePropertyFloatCoordMpLowPrecision(in, prop);
   } else if (prop.flags & PropertyFlag::NoScale) {
      value = parsePropertyFloatNoScale(in, prop);
   } else if (prop.flags & PropertyFlag::Normal) {
      value = parsePropertyFloatNormal(in, prop);
   } else if (prop.flags & PropertyFlag::CellCoord) {
      value = parsePropertyFloatCellCoord(in, prop);
   } else if (prop.flags & PropertyFlag::CellCoordIntegral) {
      value = parsePropertyFloatCellCoordIntegral(in, prop);
   } else {
      value = parsePropertyFloatDefault(in, prop);
   }

   return value;
}

PropertyVector parsePropertyVector(BitStream &in, const Property &prop)
{
   auto value = PropertyVector { };
   value.x = parsePropertyFloat(in, prop);
   value.y = parsePropertyFloat(in, prop);

   if (prop.isNormal()) {
      auto d = value.x * value.x + value.y * value.y;
      value.z = (d >= 1.0) ? 0.0 : std::sqrt(1.0 - d);

      if (in.readBit()) {
         value.z = -value.z;
      }
   } else {
      value.z = parsePropertyFloat(in, prop);
   }

   return value;
}

PropertyVectorXY parsePropertyVectorXY(BitStream &in, const Property &prop)
{
   auto value = PropertyVectorXY { };
   value.x = parsePropertyFloat(in, prop);
   value.y = parsePropertyFloat(in, prop);
   return value;
}

PropertyString parsePropertyString(BitStream &in, const Property &prop)
{
   auto value = PropertyString { };
   auto length = in.read<std::size_t>(DT_MAX_STRING_BITS);

   if (length >= DT_MAX_STRING_BUFFERSIZE) {
      length = DT_MAX_STRING_BUFFERSIZE - 1;
   }

   value = in.readStringLength(length);
   return value;
}

}
