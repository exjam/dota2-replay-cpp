#include "demo.pbsl.h"
#include <pbsl/parser.h>

bool CDemoFileHeader::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         demo_file_stamp = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         network_protocol = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         server_name = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         client_name = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         map_name = parser__.readString();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         game_directory = parser__.readString();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fullpackets_version = parser__.readInt32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         allow_clientside_entities = parser__.readBool();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         allow_clientside_particles = parser__.readBool();
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

bool CGameInfo::CDotaGameInfo::CPlayerInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         hero_name = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         player_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_fake_client = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         steamid = parser__.readUint64();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_team = parser__.readInt32();
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

bool CGameInfo::CDotaGameInfo::CHeroSelectEvent::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_pick = parser__.readBool();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
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

bool CGameInfo::CDotaGameInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_mode = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_winner = parser__.readInt32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         player_info.emplace_back();
         player_info.back().parse(parser__.readString());
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leagueid = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         picks_bans.emplace_back();
         picks_bans.back().parse(parser__.readString());
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         radiant_team_id = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         dire_team_id = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         radiant_team_tag = parser__.readString();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         dire_team_tag = parser__.readString();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         end_time = parser__.readUint32();
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

bool CGameInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         dota.parse(parser__.readString());
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

bool CDemoFileInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         playback_time = parser__.readFloat();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         playback_ticks = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         playback_frames = parser__.readInt32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         game_info.parse(parser__.readString());
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

bool CDemoPacket::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         sequence_in = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         sequence_out_ack = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         data = parser__.readBytes();
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

bool CDemoStringTables::items_t::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         str = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         data = parser__.readBytes();
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

bool CDemoStringTables::table_t::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         table_name = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         items.emplace_back();
         items.back().parse(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         items_clientside.emplace_back();
         items_clientside.back().parse(parser__.readString());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         table_flags = parser__.readInt32();
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

bool CDemoStringTables::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         tables.emplace_back();
         tables.back().parse(parser__.readString());
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

bool CDemoSaveGame::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         data = parser__.readBytes();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         steam_id = parser__.readFixed64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         signature = parser__.readFixed64();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         version = parser__.readInt32();
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

bool CDemoSyncTick::parse(const std::string_view &data__)
{
   return true;
};

bool CDemoConsoleCmd::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         cmdstring = parser__.readString();
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

bool CDemoSendTables::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         data = parser__.readBytes();
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

bool CDemoClassInfo::class_t::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         class_id = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         network_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         table_name = parser__.readString();
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

bool CDemoClassInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         classes.emplace_back();
         classes.back().parse(parser__.readString());
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

bool CDemoCustomData::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         callback_index = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         data = parser__.readBytes();
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

bool CDemoCustomDataCallbacks::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         save_id.push_back(parser__.readString());
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

bool CDemoFullPacket::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         string_table.parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         packet.parse(parser__.readString());
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

bool CDemoStop::parse(const std::string_view &data__)
{
   return true;
};

bool CDemoUserCmd::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         cmd_number = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         data = parser__.readBytes();
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

