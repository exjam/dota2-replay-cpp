#include "dota_broadcastmessages.pbsl.h"
#include <pbsl/parser.h>

bool CDOTABroadcastMsg::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         type = static_cast<EDotaBroadcastMessages>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         msg = parser__.readBytes();
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

bool CDOTABroadcastMsg_LANLobbyRequest::parse(const std::string_view &data__)
{
   return true;
};

bool CDOTABroadcastMsg_LANLobbyReply::CLobbyMember::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         player_name = parser__.readString();
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

bool CDOTABroadcastMsg_LANLobbyReply::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_game_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         members.emplace_back();
         members.back().parse(parser__.readString());
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         requires_pass_key = parser__.readBool();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leader_account_id = parser__.readUint32();
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

