#include "dota_modifiers.pbsl.h"
#include <pbsl/parser.h>

bool CDOTAModifierBuffTableEntry::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         entry_type = static_cast<DOTA_MODIFIER_ENTRY_TYPE>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         parent = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         index = parser__.readInt32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         serial_num = parser__.readInt32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         modifier_class = parser__.readInt32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         ability_level = parser__.readInt32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         stack_count = parser__.readInt32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         creation_time = parser__.readFloat();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         duration = parser__.readFloat();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         caster = parser__.readInt32();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         ability = parser__.readInt32();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         armor = parser__.readInt32();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         fade_time = parser__.readFloat();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         subtle = parser__.readBool();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         channel_time = parser__.readFloat();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         v_start.parse(parser__.readString());
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         v_end.parse(parser__.readString());
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         portal_loop_appear = parser__.readString();
         break;
      case 19:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         portal_loop_disappear = parser__.readString();
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         hero_loop_appear = parser__.readString();
         break;
      case 21:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         hero_loop_disappear = parser__.readString();
         break;
      case 22:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         movement_speed = parser__.readInt32();
         break;
      case 23:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         aura = parser__.readBool();
         break;
      case 24:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         activity = parser__.readInt32();
         break;
      case 25:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         damage = parser__.readInt32();
         break;
      case 26:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         range = parser__.readInt32();
         break;
      case 27:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         dd_modifier_index = parser__.readInt32();
         break;
      case 28:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         dd_ability_index = parser__.readInt32();
         break;
      case 29:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         illusion_label = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

