#include "networkbasetypes.pbsl.h"
#include <pbsl/parser.h>

bool CMsgVector::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         x = parser__.readFloat();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         y = parser__.readFloat();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         z = parser__.readFloat();
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

bool CMsgVector2D::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         x = parser__.readFloat();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         y = parser__.readFloat();
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

bool CMsgQAngle::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         x = parser__.readFloat();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         y = parser__.readFloat();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         z = parser__.readFloat();
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

bool CMsg_CVars::CVar::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         name = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         value = parser__.readString();
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

bool CMsg_CVars::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         cvars.emplace_back();
         cvars.back().parse(parser__.readString());
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

bool CNETMsg_NOP::parse(const std::string_view &data__)
{
   return true;
};

bool CNETMsg_SplitScreenUser::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot = parser__.readInt32();
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

bool CNETMsg_Disconnect::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         reason = static_cast<ENetworkDisconnectionReason>(parser__.readUint32());
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

bool CNETMsg_File::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         transfer_id = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         file_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_replay_demo_file = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         deny = parser__.readBool();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_file_requested = parser__.readBool();
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

bool CNETMsg_Tick::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tick = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         host_computationtime = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         host_computationtime_std_deviation = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         host_framestarttime_std_deviation = parser__.readUint32();
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

bool CNETMsg_StringCmd::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         command = parser__.readString();
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

bool CNETMsg_SetConVar::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         convars.parse(parser__.readString());
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

bool CNETMsg_SignonState::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         signon_state = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         spawn_count = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_server_players = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         players_networkids.push_back(parser__.readString());
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         map_name = parser__.readString();
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

bool CSVCMsg_GameEvent::key_t::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         type = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         val_string = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         val_float = parser__.readFloat();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         val_long = parser__.readInt32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         val_short = parser__.readInt32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         val_byte = parser__.readInt32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         val_bool = parser__.readBool();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         val_uint64 = parser__.readUint64();
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

bool CSVCMsg_GameEvent::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         event_name = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eventid = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         keys.emplace_back();
         keys.back().parse(parser__.readString());
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

bool CSVCMsgList_GameEvents::event_t::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tick = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         event.parse(parser__.readString());
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

bool CSVCMsgList_GameEvents::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         events.emplace_back();
         events.back().parse(parser__.readString());
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

bool CSVCMsg_UserMessage::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         msg_type = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         msg_data = parser__.readBytes();
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

bool CSVCMsgList_UserMessages::usermsg_t::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tick = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         msg.parse(parser__.readString());
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

bool CSVCMsgList_UserMessages::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         usermsgs.emplace_back();
         usermsgs.back().parse(parser__.readString());
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

