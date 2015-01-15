#include "bitstream.h"
#include "demoparser.h"
#include "propertyvariant.h"
#include "util.h"

std::ostream& operator<<(std::ostream& os, const dota::PropertyVariant& var)
{
   switch (var.type()) {
   case dota::PropertyType::Int:
      os << var.get<dota::PropertyInt>();
      break;
   case dota::PropertyType::Float:
      os << var.get<dota::PropertyFloat>();
      break;
   case dota::PropertyType::Vector:
   {
      auto &value = var.get<dota::PropertyVector>();
      os << "{ x: " << value.x << ", y: " << value.y << ", z:" << value.z << " }";
      break;
   }
   case dota::PropertyType::VectorXY:
   {
      auto &value = var.get<dota::PropertyVectorXY>();
      os << "{ x: " << value.x << ", y: " << value.y << " }";
      break;
   }
   case dota::PropertyType::String:
      os << var.get<dota::PropertyString>();
      break;
   case dota::PropertyType::Array:
   {
      auto &value = var.get<dota::PropertyArray>();
      os << "[";
      for (auto &&elem : value) {
         os << elem << ", ";
      }
      os << "]";
      break;
   }
   case dota::PropertyType::Int64:
      os << var.get<dota::PropertyInt64>();
      break;
   default:
      os << "{InvalidPropertyVariant}";
   }

   return os;
}

namespace dota
{

static const auto COORD_INTEGER_BITS = 14;
static const auto COORD_FRACTIONAL_BITS = 5;
static const auto COORD_DENOMINATOR = (1 << COORD_FRACTIONAL_BITS);
static const auto COORD_RESOLUTION = (1.0f / COORD_DENOMINATOR);

static const auto COORD_INTEGER_BITS_MP = 11;
static const auto COORD_FRACTIONAL_BITS_MP_LOWPRECISION = 3;
static const auto COORD_DENOMINATOR_LOWPRECISION = (1 << COORD_FRACTIONAL_BITS_MP_LOWPRECISION);
static const auto COORD_RESOLUTION_LOWPRECISION = (1.0f / COORD_DENOMINATOR_LOWPRECISION);

static const auto NORMAL_FRACTIONAL_BITS = 11;
static const auto NORMAL_DENOMINATOR = ((1 << NORMAL_FRACTIONAL_BITS) - 1);
static const auto NORMAL_RESOLUTION = (1.0f / NORMAL_DENOMINATOR);

static const auto DT_MAX_STRING_BITS = 9;
static const auto DT_MAX_STRING_BUFFERSIZE = 1 << DT_MAX_STRING_BITS;

static bool parsePropertyVariant(BitStream &in, Property &prop, PropertyVariant &variant);
static PropertyInt parsePropertyInt(BitStream &in, Property &prop);
static PropertyInt64 parsePropertyInt64(BitStream &in, Property &prop);
static PropertyArray parsePropertyArray(BitStream &in, Property &prop);
static PropertyString parsePropertyString(BitStream &in, Property &prop);
static PropertyVector parsePropertyVector(BitStream &in, Property &prop);
static PropertyVectorXY parsePropertyVectorXY(BitStream &in, Property &prop);
static PropertyFloat parsePropertyFloat(BitStream &in, Property &prop);
static PropertyFloat parsePropertyFloatDefault(BitStream &in, Property &prop);
static PropertyFloat parsePropertyFloatCellCoordIntegral(BitStream &in, Property &prop);
static PropertyFloat parsePropertyFloatCellCoord(BitStream &in, Property &prop);
static PropertyFloat parsePropertyFloatNormal(BitStream &in, Property &prop);
static PropertyFloat parsePropertyFloatNoScale(BitStream &in, Property &prop);
static PropertyFloat parsePropertyFloatCoordMpLowPrecision(BitStream &in, Property &prop);
static PropertyFloat parsePropertyFloatCoordMpIntegral(BitStream &in, Property &prop);
static PropertyFloat parsePropertyFloatCoordMp(BitStream &in, Property &prop);
static PropertyFloat parsePropertyFloatCoord(BitStream &in, Property &prop);

bool DemoParser::parsePropertyVariant(BitStream &in, Property &prop, PropertyVariant &variant)
{
   return dota::parsePropertyVariant(in, prop, variant);
}

static PropertyInt parsePropertyInt(BitStream &in, Property &prop)
{
   auto value = PropertyInt { 0 };

   if (prop.isEncodedAgainstTickCount()) {
      value = in.readVarInt();
   } else if (prop.isUnsigned()) {
      value = in.read<uint32_t>(prop.numBits);
   } else {
      value = in.read<int32_t>(prop.numBits);
   }

   return value;
}

static PropertyInt64 parsePropertyInt64(BitStream &in, Property &prop)
{
   auto value = PropertyInt64 { 0 };

   if (prop.isEncodedAgainstTickCount()) {
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

static PropertyFloat parsePropertyFloatCoord(BitStream &in, Property &prop)
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

static PropertyFloat parsePropertyFloatCoordMp(BitStream &in, Property &prop)
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

static PropertyFloat parsePropertyFloatCoordMpIntegral(BitStream &in, Property &prop)
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

static PropertyFloat parsePropertyFloatCoordMpLowPrecision(BitStream &in, Property &prop)
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

static PropertyFloat parsePropertyFloatNoScale(BitStream &in, Property &prop)
{
   auto value = PropertyFloat { 0 };
   value = in.read<float>(32);
   return value;
}

static PropertyFloat parsePropertyFloatNormal(BitStream &in, Property &prop)
{
   auto value = PropertyFloat { 0 };
   auto sign = in.readBit();
   value = static_cast<PropertyFloat>(in.read<uint32_t>(NORMAL_FRACTIONAL_BITS));
   value *= NORMAL_RESOLUTION;
   return sign ? -value : value;
}

static PropertyFloat parsePropertyFloatCellCoord(BitStream &in, Property &prop)
{
   auto value = PropertyFloat { 0 };
   value = static_cast<PropertyFloat>(in.read<uint32_t>(prop.numBits));
   value += COORD_RESOLUTION * static_cast<PropertyFloat>(in.read<uint32_t>(COORD_FRACTIONAL_BITS));
   return value;
}

static PropertyFloat parsePropertyFloatCellCoordIntegral(BitStream &in, Property &prop)
{
   auto value = PropertyFloat { 0 };
   value = static_cast<PropertyFloat>(in.read<uint32_t>(prop.numBits));
   return value;
}

static PropertyFloat parsePropertyFloatDefault(BitStream &in, Property &prop)
{
   auto value = PropertyFloat { 0 };
   value = static_cast<PropertyFloat>(in.read<uint32_t>(prop.numBits));
   value /= (1 << prop.numBits) - 1;
   return value * (prop.highValue - prop.lowValue) + prop.lowValue;
}

static PropertyFloat parsePropertyFloat(BitStream &in, Property &prop)
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

static PropertyVector parsePropertyVector(BitStream &in, Property &prop)
{
   auto value = PropertyVector { };
   value.x = parsePropertyFloat(in, prop);
   value.y = parsePropertyFloat(in, prop);

   if (prop.isNormal()) {
      auto d = value.x * value.x + value.y * value.y;
      value.z = (d >= 1.0) ? 0.0 : std::sqrt(1.0 - d);

      if (in.readBit()) {
         value.z *= -1;
      }
   } else {
      value.z = parsePropertyFloat(in, prop);
   }

   return value;
}

static PropertyVectorXY parsePropertyVectorXY(BitStream &in, Property &prop)
{
   auto value = PropertyVectorXY { };
   value.x = parsePropertyFloat(in, prop);
   value.y = parsePropertyFloat(in, prop);
   return value;
}

static PropertyString parsePropertyString(BitStream &in, Property &prop)
{
   auto value = PropertyString { };
   auto length = in.read<std::size_t>(DT_MAX_STRING_BITS);

   if (length >= DT_MAX_STRING_BUFFERSIZE) {
      length = DT_MAX_STRING_BUFFERSIZE - 1;
   }

   value = in.readStringLength(length);
   return value;
}

static PropertyArray parsePropertyArray(BitStream &in, Property &prop)
{
   auto value = PropertyArray { };
   auto numBits = getRequiredBits(prop.numElements);
   auto count = in.read<std::size_t>(numBits);
   auto type = prop.arrayElementType;
   assert(type);

   value.resize(count);

   for (std::size_t i = 0; i < count; ++i) {
      auto &variant = value[i];
      parsePropertyVariant(in, *type, variant);
   }

   return value;
}

static bool parsePropertyVariant(BitStream &in, Property &prop, PropertyVariant &variant)
{
   switch (prop.type) {
   case PropertyType::Int:
      variant.set(parsePropertyInt(in, prop));
      break;
   case PropertyType::Int64:
      variant.set(parsePropertyInt64(in, prop));
      break;
   case PropertyType::Float:
      variant.set(parsePropertyFloat(in, prop));
      break;
   case PropertyType::Vector:
      variant.set(parsePropertyVector(in, prop));
      break;
   case PropertyType::VectorXY:
      variant.set(parsePropertyVectorXY(in, prop));
      break;
   case PropertyType::String:
      variant.set(parsePropertyString(in, prop));
      break;
   case PropertyType::Array:
      variant.set(parsePropertyArray(in, prop));
      break;
   default:
      return false;
   }

   return true;
}

}
