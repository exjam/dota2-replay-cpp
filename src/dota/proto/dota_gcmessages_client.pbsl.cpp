#include "dota_gcmessages_client.pbsl.h"
#include <pbsl/parser.h>

bool CMsgStartFindingMatch::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         key = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         matchgroups = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         client_version = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_modes = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bot_difficulty = static_cast<DOTABotDifficulty>(parser__.readUint32());
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_type = static_cast<MatchType>(parser__.readUint32());
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         matchlanguages = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         map_preference = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_language_enum = static_cast<MatchLanguages>(parser__.readUint32());
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         game_language_name = parser__.readString();
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

bool CMsgStopFindingMatch::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgReadyUp::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         state = static_cast<DOTALobbyReadyState>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         ready_up_key = parser__.readFixed64();
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

bool CMsgReadyUpStatus::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         lobby_id = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         accepted_ids.push_back(parser__.readUint32());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         declined_ids.push_back(parser__.readUint32());
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

bool CSourceTVGame::Player::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         steam_id = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         name = parser__.readString();
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

bool CSourceTVGame::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         source_tv_public_addr = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         source_tv_private_addr = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         source_tv_port = parser__.readUint32();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         good_players.emplace_back();
         good_players.back().parse(parser__.readString());
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         bad_players.emplace_back();
         bad_players.back().parse(parser__.readString());
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         other_players.emplace_back();
         other_players.back().parse(parser__.readString());
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         game_name = parser__.readString();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_details.emplace_back();
         team_details.back().parse(parser__.readString());
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_spectators = parser__.readUint32();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_id = parser__.readUint32();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_game_id = parser__.readUint32();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tower_state = parser__.readUint32();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         tv_broadcast_time = parser__.readFloat();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         game_time = parser__.readFloat();
         break;
      case 19:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         server_steamid = parser__.readFixed64();
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leagueid = parser__.readUint32();
         break;
      case 21:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_mode = static_cast<DOTA_GameMode>(parser__.readUint32());
         break;
      case 22:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         lobby_type = parser__.readUint32();
         break;
      case 24:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         custom_game_id = parser__.readUint64();
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

bool CMsgSourceTVGamesResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         games.emplace_back();
         games.back().parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_total_games = parser__.readUint32();
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

bool CMsgFindSourceTVGames::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         search_key = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         start = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_games = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leagueid = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         heroid = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_game = parser__.readBool();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         custom_game_id = parser__.readUint64();
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

bool CMsgSpectateFriendGame::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         steam_id = parser__.readFixed64();
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

bool CMsgSpectateFriendGameResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         server_steamid = parser__.readFixed64();
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

bool CMsgAbandonCurrentGame::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgClientSuspended::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_end = parser__.readUint32();
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

bool CMsgPracticeLobbySetDetails::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         lobby_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         game_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_details.emplace_back();
         team_details.back().parse(parser__.readString());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_region = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_mode = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         cm_pick = static_cast<DOTA_CM_PICK>(parser__.readUint32());
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bot_difficulty = static_cast<DOTABotDifficulty>(parser__.readUint32());
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         allow_cheats = parser__.readBool();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fill_with_bots = parser__.readBool();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         intro_mode = parser__.readBool();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         allow_spectating = parser__.readBool();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_version = static_cast<DOTAGameVersion>(parser__.readUint32());
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         pass_key = parser__.readString();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leagueid = parser__.readUint32();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         penalty_level_radiant = parser__.readUint32();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         penalty_level_dire = parser__.readUint32();
         break;
      case 19:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         load_game_id = parser__.readUint32();
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         series_type = parser__.readUint32();
         break;
      case 21:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         radiant_series_wins = parser__.readUint32();
         break;
      case 22:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         dire_series_wins = parser__.readUint32();
         break;
      case 23:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         allchat = parser__.readBool();
         break;
      case 24:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         dota_tv_delay = static_cast<LobbyDotaTVDelay>(parser__.readUint32());
         break;
      case 25:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         lan = parser__.readBool();
         break;
      case 26:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         custom_game_mode = parser__.readString();
         break;
      case 27:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         custom_map_name = parser__.readString();
         break;
      case 28:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         custom_difficulty = parser__.readUint32();
         break;
      case 29:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         custom_game_id = parser__.readUint64();
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

bool CMsgPracticeLobbyCreate::SaveGame::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         version = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         steam_id = parser__.readFixed64();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         signature = parser__.readFixed64();
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

bool CMsgPracticeLobbyCreate::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         search_key = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_game = parser__.readBool();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_game_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_id = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         pass_key = parser__.readString();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         client_version = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         lobby_details.parse(parser__.readString());
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         save_game.parse(parser__.readString());
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

bool CMsgPracticeLobbySetTeamSlot::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team = static_cast<DOTA_GC_TEAM>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bot_difficulty = static_cast<DOTABotDifficulty>(parser__.readUint32());
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

bool CMsgPracticeLobbySetCoach::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team = static_cast<DOTA_GC_TEAM>(parser__.readUint32());
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

bool CMsgPracticeLobbyJoinBroadcastChannel::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         channel = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         preferred_description = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         preferred_country_code = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         preferred_language_code = parser__.readString();
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

bool CMsgPracticeLobbyToggleBroadcastChannelCameramanStatus::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgPracticeLobbyKick::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id = parser__.readUint32();
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

bool CMsgPracticeLobbyLeave::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgPracticeLobbyLaunch::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         client_version = parser__.readUint32();
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

bool CMsgApplyTeamToPracticeLobby::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
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

bool CMsgPracticeLobbyList::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_games = parser__.readBool();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         pass_key = parser__.readString();
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

bool CMsgPracticeLobbyListResponseEntry::CLobbyMember::parse(const std::string_view &data__)
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

bool CMsgPracticeLobbyListResponseEntry::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         id = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_game_id = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         members.emplace_back();
         members.back().parse(parser__.readString());
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         requires_pass_key = parser__.readBool();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leader_account_id = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_logo = parser__.readUint64();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         name = parser__.readString();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         custom_game_mode = parser__.readString();
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

bool CMsgPracticeLobbyListResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_games = parser__.readBool();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         lobbies.emplace_back();
         lobbies.back().parse(parser__.readString());
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

bool CMsgPracticeLobbyJoin::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         lobby_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         client_version = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         pass_key = parser__.readString();
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

bool CMsgPracticeLobbyJoinResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<DOTAJoinLobbyResult>(parser__.readUint32());
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

bool CMsgFriendPracticeLobbyListRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         friends.push_back(parser__.readUint32());
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

bool CMsgFriendPracticeLobbyListResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         lobbies.emplace_back();
         lobbies.back().parse(parser__.readString());
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

bool CMsgGuildmatePracticeLobbyListRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guilds.push_back(parser__.readUint32());
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

bool CMsgGuildmatePracticeLobbyListResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         lobbies.emplace_back();
         lobbies.back().parse(parser__.readString());
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

bool CMsgJoinableCustomGameModesRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_region = parser__.readUint32();
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

bool CMsgJoinableCustomGameModesResponseEntry::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         custom_game_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         lobby_count = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_count = parser__.readUint32();
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

bool CMsgJoinableCustomGameModesResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         game_modes.emplace_back();
         game_modes.back().parse(parser__.readString());
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

bool CMsgJoinableCustomLobbiesRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_region = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         custom_game_id = parser__.readUint64();
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

bool CMsgJoinableCustomLobbiesResponseEntry::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         lobby_id = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         custom_game_id = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         lobby_name = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         member_count = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leader_account_id = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         leader_name = parser__.readString();
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

bool CMsgJoinableCustomLobbiesResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         lobbies.emplace_back();
         lobbies.back().parse(parser__.readString());
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

bool CMsgQuickJoinCustomLobby::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_region = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         custom_game_id = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         client_version = parser__.readUint32();
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

bool CMsgQuickJoinCustomLobbyResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<DOTAJoinLobbyResult>(parser__.readUint32());
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

bool CMsgBotGameCreate::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         search_key = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         client_version = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         difficulty = static_cast<DOTABotDifficulty>(parser__.readUint32());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team = static_cast<DOTA_GC_TEAM>(parser__.readUint32());
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_mode = parser__.readUint32();
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

bool CMsgCustomGameCreate::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         search_key = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         client_version = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         difficulty = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         game_mode = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         map = parser__.readString();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         custom_game_id = parser__.readUint64();
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

bool CMsgEventGameCreate::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         search_key = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         client_version = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         difficulty = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         game_mode = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         map = parser__.readString();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         custom_game_id = parser__.readUint64();
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

bool CMsgRequestInternationalTicket::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgBalancedShuffleLobby::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgInitialQuestionnaireResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         initial_skill = parser__.readUint32();
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

bool CMsgDOTATournament::Team::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_abbrev = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         players.push_back(parser__.readUint32());
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         seed = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_logo = parser__.readUint64();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         country_code = parser__.readString();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         node_or_state = parser__.readUint32();
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

bool CMsgDOTATournament::Game::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         good_team_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bad_team_id = parser__.readUint32();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         good_team_seed = parser__.readUint32();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bad_team_seed = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         lobby_id = parser__.readFixed64();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_id = parser__.readUint64();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         game_name = parser__.readString();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         live_stream = parser__.readBool();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         message = parser__.readString();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         results_final = parser__.readBool();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         state = static_cast<ETournamentGameState>(parser__.readUint32());
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         node_id = parser__.readUint32();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         start_time = parser__.readUint32();
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

bool CMsgDOTATournament::Node::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         node_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_seed_a = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_seed_b = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         winner_node = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         loser_node = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         series_type = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         node_state = static_cast<ETournamentNodeState>(parser__.readUint32());
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         series_id = parser__.readUint32();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         start_time = parser__.readUint32();
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

bool CMsgDOTATournament::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         teams.emplace_back();
         teams.back().parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         games.emplace_back();
         games.back().parse(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gid = parser__.readUint64();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_id = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_type = static_cast<ETournamentType>(parser__.readUint32());
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_template = static_cast<ETournamentTemplate>(parser__.readUint32());
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         start_time = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         state = static_cast<ETournamentState>(parser__.readUint32());
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         nodes.emplace_back();
         nodes.back().parse(parser__.readString());
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

bool CMsgDOTATournamentRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         client_tournament_gid = parser__.readUint64();
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

bool CMsgDOTATournamentResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         tournament.parse(parser__.readString());
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

bool CMsgDOTAClearTournamentGame::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_id = parser__.readUint32();
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

bool CMsgDOTAMatch::Player::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_slot = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_0 = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_1 = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_2 = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_3 = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_4 = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_5 = parser__.readUint32();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         expected_team_contribution = parser__.readFloat();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         scaled_metric = parser__.readFloat();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         previous_rank = parser__.readUint32();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         rank_change = parser__.readUint32();
         break;
      case 49:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         solo_rank = parser__.readBool();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         kills = parser__.readUint32();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         deaths = parser__.readUint32();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         assists = parser__.readUint32();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leaver_status = parser__.readUint32();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gold = parser__.readUint32();
         break;
      case 19:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         last_hits = parser__.readUint32();
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         denies = parser__.readUint32();
         break;
      case 21:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gold_per_min = parser__.readUint32();
         break;
      case 22:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         XP_per_min = parser__.readUint32();
         break;
      case 23:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gold_spent = parser__.readUint32();
         break;
      case 24:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_damage = parser__.readUint32();
         break;
      case 25:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tower_damage = parser__.readUint32();
         break;
      case 26:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_healing = parser__.readUint32();
         break;
      case 27:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         level = parser__.readUint32();
         break;
      case 28:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_last_seen = parser__.readUint32();
         break;
      case 29:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         player_name = parser__.readString();
         break;
      case 30:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         support_ability_value = parser__.readUint32();
         break;
      case 32:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         feeding_detected = parser__.readBool();
         break;
      case 34:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         search_rank = parser__.readUint32();
         break;
      case 35:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         search_rank_uncertainty = parser__.readUint32();
         break;
      case 36:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         rank_uncertainty_change = parser__.readInt32();
         break;
      case 37:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_play_count = parser__.readUint32();
         break;
      case 38:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         party_id = parser__.readFixed64();
         break;
      case 39:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         scaled_kills = parser__.readFloat();
         break;
      case 40:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         scaled_deaths = parser__.readFloat();
         break;
      case 41:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         scaled_assists = parser__.readFloat();
         break;
      case 42:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         claimed_farm_gold = parser__.readUint32();
         break;
      case 43:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         support_gold = parser__.readUint32();
         break;
      case 44:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         claimed_denies = parser__.readUint32();
         break;
      case 45:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         claimed_misses = parser__.readUint32();
         break;
      case 46:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         misses = parser__.readUint32();
         break;
      case 47:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         ability_upgrades.emplace_back();
         ability_upgrades.back().parse(parser__.readString());
         break;
      case 48:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         additional_units_inventory.emplace_back();
         additional_units_inventory.back().parse(parser__.readString());
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

bool CMsgDOTAMatch::BroadcasterInfo::parse(const std::string_view &data__)
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
         name = parser__.readString();
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

bool CMsgDOTAMatch::BroadcasterChannel::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         country_code = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         description = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         broadcaster_infos.emplace_back();
         broadcaster_infos.back().parse(parser__.readString());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         language_code = parser__.readString();
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

bool CMsgDOTAMatch::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         good_guys_win = parser__.readBool();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         duration = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         startTime = parser__.readFixed32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         players.emplace_back();
         players.back().parse(parser__.readString());
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_id = parser__.readUint64();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tower_status.push_back(parser__.readUint32());
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         barracks_status.push_back(parser__.readUint32());
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         cluster = parser__.readUint32();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         first_blood_time = parser__.readUint32();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         replay_salt = parser__.readFixed32();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         server_ip = parser__.readFixed32();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_port = parser__.readUint32();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         lobby_type = parser__.readUint32();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         human_players = parser__.readUint32();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         average_skill = parser__.readUint32();
         break;
      case 19:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         game_balance = parser__.readFloat();
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         radiant_team_id = parser__.readUint32();
         break;
      case 21:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         dire_team_id = parser__.readUint32();
         break;
      case 22:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leagueid = parser__.readUint32();
         break;
      case 23:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         radiant_team_name = parser__.readString();
         break;
      case 24:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         dire_team_name = parser__.readString();
         break;
      case 25:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         radiant_team_logo = parser__.readUint64();
         break;
      case 26:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         dire_team_logo = parser__.readUint64();
         break;
      case 27:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         radiant_team_complete = parser__.readUint32();
         break;
      case 28:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         dire_team_complete = parser__.readUint32();
         break;
      case 29:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         positive_votes = parser__.readUint32();
         break;
      case 30:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         negative_votes = parser__.readUint32();
         break;
      case 31:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_mode = static_cast<DOTA_GameMode>(parser__.readUint32());
         break;
      case 32:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         picks_bans.emplace_back();
         picks_bans.back().parse(parser__.readString());
         break;
      case 33:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_seq_num = parser__.readUint64();
         break;
      case 34:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         replay_state = static_cast<ReplayState>(parser__.readUint32());
         break;
      case 35:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         radiant_guild_id = parser__.readUint32();
         break;
      case 36:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         dire_guild_id = parser__.readUint32();
         break;
      case 37:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         radiant_team_tag = parser__.readString();
         break;
      case 38:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         dire_team_tag = parser__.readString();
         break;
      case 39:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         series_id = parser__.readUint32();
         break;
      case 40:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         series_type = parser__.readUint32();
         break;
      case 42:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         custom_game_id = parser__.readUint64();
         break;
      case 43:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         broadcaster_channels.emplace_back();
         broadcaster_channels.back().parse(parser__.readString());
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

bool CMsgDOTAPlayerMatchHistory::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_ids.push_back(parser__.readUint64());
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

bool CMsgDOTAMatchHistoryFilter::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_ids.push_back(parser__.readUint64());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         newest_match_id_at_last_query = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_last_query = parser__.readUint32();
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

bool CMsgDOTARequestMatches::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_mode = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         date_min = parser__.readFixed32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         date_max = parser__.readFixed32();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         matches_requested = parser__.readUint32();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         start_at_match_id = parser__.readUint64();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         min_players = parser__.readFixed32();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         request_id = parser__.readUint32();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_games_only = parser__.readBool();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id = parser__.readUint32();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         skill = static_cast<SkillLevel>(parser__.readUint32());
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         custom_game_id = parser__.readUint64();
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

bool CMsgDOTARequestMatchesResponse::Series::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         matches.emplace_back();
         matches.back().parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         series_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         series_type = parser__.readUint32();
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

bool CMsgDOTARequestMatchesResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         matches.emplace_back();
         matches.back().parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         series.emplace_back();
         series.back().parse(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         request_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         total_results = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         results_remaining = parser__.readUint32();
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

bool CMsgDOTAPopup::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         id = static_cast<PopupID>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         custom_text = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         int_data = parser__.readSint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         popup_data = parser__.readBytes();
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

bool CMsgDOTATeamMemberSDO::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_ids.push_back(parser__.readUint32());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         profile_team_id = parser__.readUint32();
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

bool CMsgDOTATeamAdminSDO::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_ids.push_back(parser__.readUint32());
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

bool CMsgDOTATeamMember::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_joined = parser__.readUint32();
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

bool CMsgDOTATeam::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         members.emplace_back();
         members.back().parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         name = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         tag = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         admin_id = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_created = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         disbanded = parser__.readBool();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         wins = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         losses = parser__.readUint32();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         rank = parser__.readUint32();
         break;
      case 24:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         calibration_games_remaining = parser__.readUint32();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         logo = parser__.readUint64();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         base_logo = parser__.readUint64();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         banner_logo = parser__.readUint64();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         sponsor_logo = parser__.readUint64();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         country_code = parser__.readString();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         url = parser__.readString();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fullgamesplayed = parser__.readUint32();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leagues.push_back(parser__.readUint32());
         break;
      case 19:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gamesplayed = parser__.readUint32();
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gamesplayedwithcurrentroster = parser__.readUint32();
         break;
      case 21:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         teammatchmakinggamesplayed = parser__.readUint32();
         break;
      case 22:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         lastplayedgametime = parser__.readUint32();
         break;
      case 23:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         lastrenametime = parser__.readUint32();
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

bool CMsgDOTACreateTeam::parse(const std::string_view &data__)
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
         tag = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         logo = parser__.readUint64();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         base_logo = parser__.readUint64();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         banner_logo = parser__.readUint64();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         sponsor_logo = parser__.readUint64();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         country_code = parser__.readString();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         url = parser__.readString();
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

bool CMsgDOTACreateTeamResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         results.push_back(static_cast<Result>(parser__.readUint32()));
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         seconds_remaining = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         required_level = parser__.readUint32();
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

bool CMsgDOTAEditTeam::parse(const std::string_view &data__)
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
         tag = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         logo = parser__.readUint64();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         base_logo = parser__.readUint64();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         banner_logo = parser__.readUint64();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         sponsor_logo = parser__.readUint64();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         country_code = parser__.readString();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         url = parser__.readString();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
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

bool CMsgDOTAEditTeamLogo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         logo = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         base_logo = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         banner_logo = parser__.readUint64();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         sponsor_logo = parser__.readUint64();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
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

bool CMsgDOTAEditTeamLogoResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         results.push_back(static_cast<Result>(parser__.readUint32()));
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

bool CMsgDOTAEditTeamDetails::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         country_code = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         url = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
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

bool CMsgDOTAEditTeamDetailsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         results.push_back(static_cast<Result>(parser__.readUint32()));
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

bool CMsgDOTADisbandTeam::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
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

bool CMsgDOTADisbandTeamResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<Result>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_name = parser__.readString();
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

bool CMsgDOTARequestTeamData::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgDOTATeamData::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         on_team = parser__.readBool();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         profile_team = parser__.readBool();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team.parse(parser__.readString());
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

bool CMsgDOTARequestTeamDataResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<Result>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         data.emplace_back();
         data.back().parse(parser__.readString());
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

bool CMsgDOTATeamProfileRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
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

bool CMsgDOTATeamMemberProfileRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         steam_id = parser__.readFixed64();
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

bool CMsgDOTATeamIDByNameRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         name = parser__.readString();
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

bool CMsgDOTATeamIDByNameResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eresult = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
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

bool CMsgDOTATeamProfileResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eresult = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team.parse(parser__.readString());
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

bool CMsgDOTAProTeamListRequest::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgDOTAProTeamListResponse::TeamEntry::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         tag = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_created = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         logo = parser__.readUint64();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         country_code = parser__.readString();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         member_count = parser__.readUint32();
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

bool CMsgDOTAProTeamListResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         teams.emplace_back();
         teams.back().parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eresult = parser__.readUint32();
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

bool CMsgDOTATeamInvite_InviterToGC::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
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

bool CMsgDOTATeamInvite_GCImmediateResponseToInviter::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<Result>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         invitee_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         required_level = parser__.readUint32();
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

bool CMsgDOTATeamInvite_GCRequestToInvitee::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         inviter_account_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_tag = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         logo = parser__.readUint64();
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

bool CMsgDOTATeamInvite_InviteeResponseToGC::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<Result>(parser__.readUint32());
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

bool CMsgDOTATeamInvite_GCResponseToInviter::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<Result>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         invitee_name = parser__.readString();
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

bool CMsgDOTATeamInvite_GCResponseToInvitee::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<Result>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_name = parser__.readString();
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

bool CMsgDOTATeamOnProfile::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         enabled = parser__.readBool();
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

bool CMsgDOTAKickTeamMember::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
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

bool CMsgDOTAKickTeamMemberResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<Result>(parser__.readUint32());
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

bool CMsgDOTATransferTeamAdmin::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         new_admin_account_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
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

bool CMsgDOTATransferTeamAdminResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<Result>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         invitee_name = parser__.readString();
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

bool CMsgDOTALeaveTeam::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
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

bool CMsgDOTALeaveTeamResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<Result>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_name = parser__.readString();
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

bool CMsgDOTABetaParticipation::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         access_rights = parser__.readUint32();
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

bool CMsgDOTAJoinChatChannel::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         channel_name = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         channel_type = static_cast<DOTAChatChannelType_t>(parser__.readUint32());
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

bool CMsgDOTALeaveChatChannel::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         channel_id = parser__.readUint64();
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

bool CMsgDOTAClientIgnoredUser::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         ignored_account_id = parser__.readUint32();
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

bool CMsgDOTAChatMessage::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         channel_id = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         persona_name = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         text = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         timestamp = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         suggest_invite_account_id = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         suggest_invite_name = parser__.readString();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_draft_owner_account_id = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_draft_player_account_id = parser__.readUint32();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         compendium_league_id = parser__.readUint32();
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

bool CMsgDOTAChatMember::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         steam_id = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         persona_name = parser__.readString();
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

bool CMsgDOTAJoinChatChannelResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         response = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         channel_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         channel_id = parser__.readFixed64();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         max_members = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         members.emplace_back();
         members.back().parse(parser__.readString());
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

bool CMsgDOTAChatChannelFullUpdate::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         channel_id = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         members.emplace_back();
         members.back().parse(parser__.readString());
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

bool CMsgDOTAOtherJoinedChatChannel::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         channel_id = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         persona_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         steam_id = parser__.readFixed64();
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

bool CMsgDOTAOtherLeftChatChannel::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         channel_id = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         steam_id = parser__.readFixed64();
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

bool CMsgDOTAChatChannelMemberUpdate::JoinedMember::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         steam_id = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         persona_name = parser__.readString();
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

bool CMsgDOTAChatChannelMemberUpdate::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         channel_id = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         left_steam_ids.push_back(parser__.readFixed64());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         joined_members.emplace_back();
         joined_members.back().parse(parser__.readString());
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

bool CMsgDOTARequestChatChannelList::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgDOTARequestChatChannelListResponse::ChatChannel::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         channel_name = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_members = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         channel_type = static_cast<DOTAChatChannelType_t>(parser__.readUint32());
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

bool CMsgDOTARequestChatChannelListResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         channels.emplace_back();
         channels.back().parse(parser__.readString());
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

bool CMsgDOTAChatGetUserList::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         channel_id = parser__.readFixed64();
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

bool CMsgDOTAChatGetUserListResponse::Member::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         steam_id = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         persona_name = parser__.readString();
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

bool CMsgDOTAChatGetUserListResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         channel_id = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         members.emplace_back();
         members.back().parse(parser__.readString());
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

bool CMsgDOTAGuildSDO::Member::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_joined = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         role = parser__.readUint32();
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

bool CMsgDOTAGuildSDO::Invitation::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_sent = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id_sender = parser__.readUint32();
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

bool CMsgDOTAGuildSDO::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         tag = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_created = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_disbanded = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         logo = parser__.readUint64();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         base_logo = parser__.readUint64();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         banner_logo = parser__.readUint64();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         members.emplace_back();
         members.back().parse(parser__.readString());
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         invitations.emplace_back();
         invitations.back().parse(parser__.readString());
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         message = parser__.readString();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         incremental = parser__.readBool();
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

bool CMsgDOTAGuildAuditSDO::Entry::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         event_index = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         timestamp = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         action = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id_requestor = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id_target = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         reference_data_a = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         reference_data_b = parser__.readUint32();
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

bool CMsgDOTAGuildAuditSDO::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         entries.emplace_back();
         entries.back().parse(parser__.readString());
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

bool CMsgDOTAAccountGuildMembershipsSDO::Membership::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         role = parser__.readUint32();
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

bool CMsgDOTAAccountGuildMembershipsSDO::Invitation::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_sent = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id_sender = parser__.readUint32();
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

bool CMsgDOTAAccountGuildMembershipsSDO::parse(const std::string_view &data__)
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
         memberships.emplace_back();
         memberships.back().parse(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         invitations.emplace_back();
         invitations.back().parse(parser__.readString());
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

bool CMsgDOTAGuildCreateRequest::parse(const std::string_view &data__)
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
         tag = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         logo = parser__.readUint64();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         base_logo = parser__.readUint64();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         banner_logo = parser__.readUint64();
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

bool CMsgDOTAGuildCreateResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         errors.push_back(static_cast<EError>(parser__.readUint32()));
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

bool CMsgDOTAGuildSetAccountRoleRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         target_account_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         target_role = parser__.readUint32();
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

bool CMsgDOTAGuildSetAccountRoleResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<EResult>(parser__.readUint32());
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

bool CMsgDOTAGuildInviteAccountRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         target_account_id = parser__.readUint32();
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

bool CMsgDOTAGuildInviteAccountResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<EResult>(parser__.readUint32());
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

bool CMsgDOTAGuildCancelInviteRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         target_account_id = parser__.readUint32();
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

bool CMsgDOTAGuildCancelInviteResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<EResult>(parser__.readUint32());
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

bool CMsgDOTAGuildUpdateDetailsRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         logo = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         base_logo = parser__.readUint64();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         banner_logo = parser__.readUint64();
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

bool CMsgDOTAGuildUpdateDetailsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<EResult>(parser__.readUint32());
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

bool CMsgDOTAGCToGCUpdateOpenGuildPartyRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         party_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         member_account_ids.push_back(parser__.readUint32());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         description = parser__.readString();
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

bool CMsgDOTAGCToGCUpdateOpenGuildPartyResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         maintain_association = parser__.readBool();
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

bool CMsgDOTAGCToGCDestroyOpenGuildPartyRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         party_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
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

bool CMsgDOTAGCToGCDestroyOpenGuildPartyResponse::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgDOTAPartySetOpenGuildRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         description = parser__.readString();
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

bool CMsgDOTAPartySetOpenGuildResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<EResult>(parser__.readUint32());
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

bool CMsgDOTAJoinOpenGuildPartyRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         party_id = parser__.readUint64();
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

bool CMsgDOTAJoinOpenGuildPartyResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<EResult>(parser__.readUint32());
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

bool CMsgDOTAGuildOpenPartyRefresh::OpenParty::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         party_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         member_account_ids.push_back(parser__.readUint32());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_created = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         description = parser__.readString();
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

bool CMsgDOTAGuildOpenPartyRefresh::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         open_parties.emplace_back();
         open_parties.back().parse(parser__.readString());
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

bool CMsgDOTARequestGuildData::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgDOTAGuildInviteData::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         invited_to_guild = parser__.readBool();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         guild_name = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         guild_tag = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         logo = parser__.readUint64();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         inviter = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         inviter_name = parser__.readString();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         member_count = parser__.readUint32();
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

bool CMsgDOTAGuildUpdateMessage::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         message = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
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

bool CMsgDOTAGuildEditLogoRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         logo = parser__.readUint64();
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

bool CMsgDOTAGuildEditLogoResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<EResult>(parser__.readUint32());
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

bool CMsgDOTAReportsRemainingRequest::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgDOTAReportsRemainingResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_positive_reports_remaining = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_negative_reports_remaining = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_positive_reports_total = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_negative_reports_total = parser__.readUint32();
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

bool CMsgDOTASubmitPlayerReport::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         target_account_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         report_flags = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         comment = parser__.readString();
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

bool CMsgDOTASubmitPlayerReportResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         target_account_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         report_flags = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = parser__.readUint32();
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

bool CMsgDOTAReportCountsRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         target_account_id = parser__.readUint32();
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

bool CMsgDOTAReportCountsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         target_account_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leadership_count = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         teaching_count = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         friendly_count = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         forgiving_count = parser__.readUint32();
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

bool CMsgDOTAKickedFromMatchmakingQueue::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_type = static_cast<MatchType>(parser__.readUint32());
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

bool CMsgDOTARequestSaveGames::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_region = parser__.readUint32();
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

bool CMsgDOTARequestSaveGamesResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         steam_id = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         save_games.emplace_back();
         save_games.back().parse(parser__.readString());
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

bool CMsgWatchGame::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         server_steamid = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         client_version = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         watch_server_steamid = parser__.readFixed64();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         lobby_id = parser__.readUint64();
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

bool CMsgCancelWatchGame::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgWatchGameResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         watch_game_result = static_cast<WatchGameResult>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         source_tv_public_addr = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         source_tv_private_addr = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         source_tv_port = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         game_server_steamid = parser__.readFixed64();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         watch_server_steamid = parser__.readFixed64();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         watch_tv_unique_secret_code = parser__.readFixed64();
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

bool CMsgPartyLeaderWatchGamePrompt::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         game_server_steamid = parser__.readFixed64();
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

bool CMsgGCMatchDetailsRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_id = parser__.readUint64();
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

bool CMsgGCMatchDetailsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         match.parse(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         vote = static_cast<DOTAMatchVote>(parser__.readUint32());
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

bool CMsgDOTAProfileRequest::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         request_name = parser__.readBool();
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

bool CMsgDOTAProfileResponse::PlayedHero::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         wins = parser__.readUint32();
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

bool CMsgDOTAProfileResponse::ShowcaseHero::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         object_data.push_back(parser__.readBytes());
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

bool CMsgDOTAProfileResponse::LeaguePass::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_def = parser__.readUint32();
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

bool CMsgDOTAProfileResponse::EventTicket::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         event_id = parser__.readUint32();
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

bool CMsgDOTAProfileResponse::FeaturedItem::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         object_data = parser__.readBytes();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot_index = parser__.readUint32();
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

bool CMsgDOTAProfileResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         game_account_client.parse(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         latest_matches.emplace_back();
         latest_matches.back().parse(parser__.readString());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         heroes.emplace_back();
         heroes.back().parse(parser__.readString());
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         player_name = parser__.readString();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_name = parser__.readString();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_tag = parser__.readString();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_logo = parser__.readUint64();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         showcase_hero.parse(parser__.readString());
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         league_passes.emplace_back();
         league_passes.back().parse(parser__.readString());
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         event_tickets.emplace_back();
         event_tickets.back().parse(parser__.readString());
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         has_passport = parser__.readBool();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         featured_items.emplace_back();
         featured_items.back().parse(parser__.readString());
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         abandon_percent = parser__.readUint32();
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

bool CMsgGCSteamProfileRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id = parser__.readUint32();
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

bool CMsgGCSteamProfileRequestResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = parser__.readUint32();
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

bool CMsgDOTAClearNotifySuccessfulReport::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgDOTAWelcome::LocalizationDigest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         context = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         english_language_file_sha1.parse(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         client_language_file_sha1.parse(parser__.readString());
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

bool CMsgDOTAWelcome::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_admin = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_broadcaster = parser__.readBool();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         store_item_hash = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         timeplayedconsecutively = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         allow_3rd_party_match_history = parser__.readBool();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         partner_account_type = static_cast<PartnerAccountType>(parser__.readUint32());
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         banned_word_list_word_id = parser__.readUint32();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         partner_account_state = parser__.readUint32();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         last_time_played = parser__.readUint32();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         last_ip_address = parser__.readUint32();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         shutdownlawterminateminutes = parser__.readUint32();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         banned_word_list_version = parser__.readUint32();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         profile_private = parser__.readBool();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         currency = parser__.readUint32();
         break;
      case 19:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bang_no = parser__.readUint32();
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         should_request_player_origin = parser__.readBool();
         break;
      case 21:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         compendium_unlocks = parser__.readUint64();
         break;
      case 22:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gc_socache_file_version = parser__.readUint32();
         break;
      case 23:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         localization_digests.emplace_back();
         localization_digests.back().parse(parser__.readString());
         break;
      case 24:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_perfect_world_test_account = parser__.readBool();
         break;
      case 25:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         active_events.push_back(static_cast<EIngameEvent>(parser__.readUint32()));
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

bool CSODOTAGameHeroFavorites::parse(const std::string_view &data__)
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

bool CMsgDOTAHeroFavoritesAdd::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CMsgDOTAHeroFavoritesRemove::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CMsgSetShowcaseHero::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         showcase_hero_id = parser__.readUint32();
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

bool CMsgSetFeaturedItems::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         featured_item_id.push_back(parser__.readUint64());
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

bool CMsgDOTAFeaturedItems::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         featured_item_id.push_back(parser__.readUint64());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         object_data.push_back(parser__.readBytes());
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

bool CMsgRequestLeagueInfo::parse(const std::string_view &data__)
{
   return true;
};

bool CLeague::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leagueid = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         live = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         lastgametime = parser__.readFixed32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         prize_pool_usd = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         version = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         compendium_is_public = parser__.readBool();
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

bool CMsgResponseLeagueInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         leagues.emplace_back();
         leagues.back().parse(parser__.readString());
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

bool CMsgDOTAMatchVotes::PlayerVote::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         vote = parser__.readUint32();
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

bool CMsgDOTAMatchVotes::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         votes.emplace_back();
         votes.back().parse(parser__.readString());
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

bool CMsgCastMatchVote::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         vote = static_cast<DOTAMatchVote>(parser__.readUint32());
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

bool CMsgRetrieveMatchVote::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         incremental = parser__.readUint32();
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

bool CMsgMatchVoteResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eresult = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         vote = static_cast<DOTAMatchVote>(parser__.readUint32());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         positive_votes = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         negative_votes = parser__.readUint32();
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

bool CMsgDOTAHallOfFame::FeaturedPlayer::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         average_scaled_metric = parser__.readFloat();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_games = parser__.readUint32();
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

bool CMsgDOTAHallOfFame::FeaturedFarmer::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gold_per_min = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_id = parser__.readUint64();
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

bool CMsgDOTAHallOfFame::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         week = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         featured_players.emplace_back();
         featured_players.back().parse(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         featured_farmer.parse(parser__.readString());
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

bool CMsgDOTAHallOfFameRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         week = parser__.readUint32();
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

bool CMsgDOTAHallOfFameResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         hall_of_fame.parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eresult = parser__.readUint32();
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

bool CMsgDOTAHalloweenHighScoreRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         round = parser__.readInt32();
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

bool CMsgDOTAHalloweenHighScoreResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         score = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         match.parse(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eresult = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         round = parser__.readInt32();
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

bool CMsgDOTAStorePromoPagesRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         version_seen = parser__.readUint32();
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

bool CMsgDOTAStorePromoPagesResponse::PromoPage::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         promo_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         title = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         url = parser__.readString();
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

bool CMsgDOTAStorePromoPagesResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         pages.emplace_back();
         pages.back().parse(parser__.readString());
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

bool CMsgLeagueScheduleBlockTeamInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         name = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         logo = parser__.readUint64();
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

bool CMsgLeagueScheduleBlock::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         block_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         start_time = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         finals = parser__.readBool();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         comment = parser__.readString();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         teams.emplace_back();
         teams.back().parse(parser__.readString());
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

bool CMsgDOTALeague::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         schedule.emplace_back();
         schedule.back().parse(parser__.readString());
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

bool CMsgDOTALeagueScheduleRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
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

bool CMsgDOTALeagueScheduleResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         league.parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eresult = parser__.readUint32();
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

bool CMsgDOTALeagueScheduleEdit::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         schedule.parse(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         delete_block = parser__.readBool();
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

bool CMsgDOTALeagueScheduleEditResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         league.parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eresult = parser__.readUint32();
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

bool CMsgDOTALeaguesInMonthRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         month = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         year = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tier = parser__.readUint32();
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

bool CMsgDOTALeaguesInMonthResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eresult = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         month = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         year = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         leagues.emplace_back();
         leagues.back().parse(parser__.readString());
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

bool CMsgSockAddrList::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         ip.push_back(parser__.readFixed32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         port.push_back(parser__.readUint32());
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

bool CMsgMatchmakingGroupServerSample::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         servers_by_group.emplace_back();
         servers_by_group.back().parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         servers_to_ping = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         reply_odds = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         reply_detailed_odds = parser__.readUint32();
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

bool CMsgClientGameserverPings::PingDetail::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         ip = parser__.readFixed32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         port = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         ping = parser__.readUint32();
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

bool CMsgClientGameserverPings::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         average_ping_by_group.push_back(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         ping_details.emplace_back();
         ping_details.back().parse(parser__.readString());
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

bool CMsgDOTAMatchmakingStatsRequest::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgDOTAMatchmakingStatsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         searching_players_by_group.push_back(parser__.readUint32());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         disabled_groups = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         gameserver_sample.parse(parser__.readString());
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         gameserver_sample_source2.parse(parser__.readString());
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         maintenance_alerts = parser__.readBool();
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

bool CMsgDOTASetMatchHistoryAccess::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         allow_3rd_party_match_history = parser__.readBool();
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

bool CMsgDOTASetMatchHistoryAccessResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eresult = parser__.readUint32();
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

bool CMsgDOTANotifyAccountFlagsChange::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         accountid = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_flags = parser__.readUint32();
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

bool CMsgDOTASetProfilePrivacy::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         profile_private = parser__.readBool();
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

bool CMsgDOTASetProfilePrivacyResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eresult = parser__.readUint32();
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

bool CMsgUpgradeLeagueItem::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
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

bool CMsgUpgradeLeagueItemResponse::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgGCWatchDownloadedReplay::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         watch_type = static_cast<DOTA_WatchReplayType>(parser__.readUint32());
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

bool CMsgSetMapLocationState::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         location_id = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         completed = parser__.readBool();
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

bool CMsgSetMapLocationStateResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eresult = parser__.readUint32();
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

bool CMsgResetMapLocations::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgResetMapLocationsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eresult = parser__.readUint32();
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

bool CMsgRefreshPartnerAccountLink::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         partner_type = parser__.readInt32();
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

bool CMsgClientsRejoinChatChannels::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgDOTASendFriendRecruits::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         recruits.push_back(parser__.readUint32());
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

bool CMsgDOTAFriendRecruitsRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_ids.push_back(parser__.readUint32());
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

bool CMsgDOTAFriendRecruitsResponse::FriendRecruitStatus::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         status = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         levels_earned = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bonus = parser__.readBool();
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

bool CMsgDOTAFriendRecruitsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<EResult>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         recruits.emplace_back();
         recruits.back().parse(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         recruiters.emplace_back();
         recruiters.back().parse(parser__.readString());
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

bool CMsgDOTAFriendRecruitInviteAcceptDecline::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         accepted = parser__.readBool();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id = parser__.readUint32();
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

bool CMsgDOTAPassportVoteTeamGuess::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         winner_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         runnerup_id = parser__.readUint32();
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

bool CMsgDOTAPassportVoteGenericSelection::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         selection_index = static_cast<DOTA_2013PassportSelectionIndices>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         selection = parser__.readUint32();
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

bool CMsgDOTAPassportStampedPlayer::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         steam_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         stamp_level = parser__.readUint32();
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

bool CMsgDOTAPassportPlayerCardChallenge::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         challenge_id = parser__.readUint32();
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

bool CMsgDOTAPassportVote::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_votes.emplace_back();
         team_votes.back().parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         generic_selections.emplace_back();
         generic_selections.back().parse(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         stamped_players.emplace_back();
         stamped_players.back().parse(parser__.readString());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         player_card_challenges.emplace_back();
         player_card_challenges.back().parse(parser__.readString());
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

bool CMsgPassportDataRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id = parser__.readUint32();
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

bool CMsgPassportDataResponse::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         international.parse(parser__.readString());
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         east_qualifiers_predict_end_time = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         west_qualifiers_predict_end_time = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         allstar_match_end_time = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         league_guesses.parse(parser__.readString());
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         east_qualifiers_winner_team_id = parser__.readUint32();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         east_qualifiers_runner_up_team_id = parser__.readUint32();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         west_qualifiers_winner_team_id = parser__.readUint32();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         west_qualifiers_runner_up_team_id = parser__.readUint32();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         passports_bought = parser__.readUint32();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         original_purchaser_id = parser__.readUint32();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_team_count = parser__.readUint32();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_teamexpiration = parser__.readUint32();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_teams_will_lock_at = parser__.readUint32();
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

bool CMsgHeroPickStatsRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         matches_since_time = parser__.readUint32();
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

bool CMsgHeroPickStatPlayer::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         win = parser__.readBool();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gpm = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         kills = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         deaths = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         assists = parser__.readUint32();
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

bool CMsgHeroPickStatsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         total_picks = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         total_wins = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_picks = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_wins = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         player_pick.emplace_back();
         player_pick.back().parse(parser__.readString());
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

bool CMsgRequestLeaguePrizePool::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
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

bool CMsgRequestLeaguePrizePoolResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         prize_pool = parser__.readUint32();
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

bool CMsgGCGetHeroStandings::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgGCGetHeroStandingsResponse::Hero::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         wins = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         losses = parser__.readUint32();
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

bool CMsgGCGetHeroStandingsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         standings.emplace_back();
         standings.back().parse(parser__.readString());
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

bool CMsgGCItemEditorReservationsRequest::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgGCItemEditorReservation::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         def_index = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         name = parser__.readString();
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

bool CMsgGCItemEditorReservationsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         reservations.emplace_back();
         reservations.back().parse(parser__.readString());
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

bool CMsgGCItemEditorReserveItemDef::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         def_index = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         username = parser__.readString();
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

bool CMsgGCItemEditorReserveItemDefResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         def_index = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         username = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = parser__.readUint32();
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

bool CMsgGCItemEditorReleaseReservation::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         def_index = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         username = parser__.readString();
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

bool CMsgGCItemEditorReleaseReservationResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         def_index = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         released = parser__.readBool();
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

bool CMsgGCItemEditorRequestLeagueInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
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

bool CMsgGCItemEditorLeagueInfoResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         league_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         league_desc = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         league_url = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         revenue_url = parser__.readString();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tier = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         location = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = parser__.readUint32();
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

bool CMsgDOTARewardTutorialPrizes::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         location_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tracking_only = parser__.readBool();
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

bool CMsgDOTALastHitChallengeHighScorePost::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         high_score = parser__.readUint32();
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

bool CMsgDOTALastHitChallengeHighScoreRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CMsgDOTALastHitChallengeHighScoreResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         score = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eresult = parser__.readUint32();
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

bool CMsgFlipLobbyTeams::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgPresentedClientTerminateDlg::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgGCLobbyUpdateBroadcastChannelInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         channel_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         country_code = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         description = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         language_code = parser__.readString();
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

bool CMsgDOTARedeemEventPrize::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_def_index = parser__.readUint32();
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

bool CMsgDOTARedeemEventPrizeResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<ResultCode>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         remaining_points = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         remaining_premium_points = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         event_id = parser__.readUint32();
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

bool CMsgDOTAGetEventPoints::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         event_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id = parser__.readUint32();
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

bool CMsgDOTAGetEventPointsResponse::Action::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         action_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         times_completed = parser__.readUint32();
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

bool CMsgDOTAGetEventPointsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         total_points = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         total_premium_points = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         event_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         points = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         premium_points = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         completed_actions.emplace_back();
         completed_actions.back().parse(parser__.readString());
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id = parser__.readUint32();
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

bool CMsgDOTAExchangeEventPoints::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         event_id = parser__.readUint32();
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

bool CMsgDOTAExchangeEventPointsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         success = parser__.readBool();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         total_points = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         total_premium_points = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         event_id = parser__.readUint32();
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

bool CMsgDOTALiveLeagueGameUpdate::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         live_league_games = parser__.readUint32();
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

bool CMsgDOTACompendiumSelection::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         selection_index = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         selection = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leagueid = parser__.readUint32();
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

bool CMsgDOTACompendiumSelectionResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eresult = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         extra_selections.emplace_back();
         extra_selections.back().parse(parser__.readString());
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

bool CMsgDOTACompendiumData::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         selections.emplace_back();
         selections.back().parse(parser__.readString());
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

bool CMsgDOTACompendiumDataRequest::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leagueid = parser__.readUint32();
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

bool CMsgDOTACompendiumDataResponse::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leagueid = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         compendium_data.parse(parser__.readString());
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

bool CMsgDOTAGetPlayerMatchHistory::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         start_at_match_id = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         matches_requested = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         request_id = parser__.readUint32();
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

bool CMsgDOTAGetPlayerMatchHistoryResponse::Match::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         start_time = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         winner = parser__.readBool();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_mode = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         rank_change = parser__.readInt32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         previous_rank = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         lobby_type = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         solo_rank = parser__.readBool();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         abandon = parser__.readBool();
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

bool CMsgDOTAGetPlayerMatchHistoryResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         matches.emplace_back();
         matches.back().parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         request_id = parser__.readUint32();
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

bool CMsgDOTAStartDailyHeroChallenge::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgGCNewBloomModeState::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgGCNewBloomModeStateResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         active = parser__.readBool();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         switch_time = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         round = parser__.readUint32();
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

bool CMsgGCNotificationsRequest::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgGCNotificationsResponse::Notification::parse(const std::string_view &data__)
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
         type = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         timestamp = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         reference_a = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         reference_b = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         reference_c = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         message = parser__.readString();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         unread = parser__.readBool();
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

bool CMsgGCNotificationsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<EResult>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         notifications.emplace_back();
         notifications.back().parse(parser__.readString());
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

bool CMsgGCNotificationsMarkReadRequest::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgClientToGCMarkNotificationListRead::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         notification_ids.push_back(parser__.readUint64());
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

bool CMsgGCLeagueAdminState::PrivateLeagueKeys::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leagueid = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         privatekey = parser__.readUint32();
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

bool CMsgGCLeagueAdminState::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leagues.push_back(parser__.readUint32());
         break;
      case 2:
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

bool CMsgGCPlayerInfoRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_ids.push_back(parser__.readUint32());
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

bool CMsgGCPlayerInfoSubmit::parse(const std::string_view &data__)
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
         country_code = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_role = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         sponsor = parser__.readString();
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

bool CMsgGCPlayerInfoSubmitResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<EResult>(parser__.readUint32());
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

bool CMsgSerializedSOCache::TypeCache::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         type = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         objects.push_back(parser__.readBytes());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         service_id = parser__.readUint32();
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

bool CMsgSerializedSOCache::Cache::Version::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         service = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         version = parser__.readUint64();
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

bool CMsgSerializedSOCache::Cache::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         type = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         id = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         versions.emplace_back();
         versions.back().parse(parser__.readString());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         type_caches.emplace_back();
         type_caches.back().parse(parser__.readString());
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

bool CMsgSerializedSOCache::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         file_version = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         caches.emplace_back();
         caches.back().parse(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gc_socache_file_version = parser__.readUint32();
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

bool CMsgRequestWeekendTourneySchedule::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgWeekendTourneySchedule::Division::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         division_code = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_window_open = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_window_close = parser__.readUint32();
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

bool CMsgWeekendTourneySchedule::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         divisions.emplace_back();
         divisions.back().parse(parser__.readString());
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

bool CMsgClientProvideSurveyResult::Response::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         question_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         survey_value = parser__.readUint32();
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

bool CMsgClientProvideSurveyResult::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         responses.emplace_back();
         responses.back().parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         survey_key = parser__.readUint64();
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

bool CMsgDOTAEmoticonAccessSDO::parse(const std::string_view &data__)
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
         unlocked_emoticons = parser__.readBytes();
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

bool CMsgClientToGCEmoticonDataRequest::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgGCToClientEmoticonData::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         emoticon_access.parse(parser__.readString());
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

bool CMsgClientToGCTrackDialogResult::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         dialog_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         value = parser__.readUint32();
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

bool CMsgGCToClientTournamentItemDrop::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_def = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         event_type = parser__.readUint32();
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

bool CMsgClientToGCSetAdditionalEquips::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         equips.emplace_back();
         equips.back().parse(parser__.readString());
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

bool CMsgClientToGCGetAdditionalEquips::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgClientToGCGetAdditionalEquipsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         equips.emplace_back();
         equips.back().parse(parser__.readString());
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

bool CMsgClientToGCGetAllHeroProgress::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id = parser__.readUint32();
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

bool CMsgClientToGCGetAllHeroProgressResponse::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         curr_hero_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         laps_completed = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         curr_hero_games = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         curr_lap_time_started = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         curr_lap_games = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         best_lap_games = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         best_lap_time = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         lap_heroes_completed = parser__.readUint32();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         lap_heroes_remaining = parser__.readUint32();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         next_hero_id = parser__.readUint32();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         prev_hero_id = parser__.readUint32();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         prev_hero_games = parser__.readUint32();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         prev_avg_tries = parser__.readFloat();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         curr_avg_tries = parser__.readFloat();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         next_avg_tries = parser__.readFloat();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         full_lap_avg_tries = parser__.readFloat();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         curr_lap_avg_tries = parser__.readFloat();
         break;
      case 19:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         profile_name = parser__.readString();
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

bool CMsgClientToGCGetTrophyList::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id = parser__.readUint32();
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

bool CMsgClientToGCGetTrophyListResponse::Trophy::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         trophy_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         trophy_score = parser__.readUint32();
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

bool CMsgClientToGCGetTrophyListResponse::parse(const std::string_view &data__)
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
         trophies.emplace_back();
         trophies.back().parse(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         profile_name = parser__.readString();
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

bool CMsgGCToClientTrophyAwarded::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         trophy_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         trophy_score = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         trophy_old_score = parser__.readUint32();
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

bool CMsgClientToGCGetProfileCard::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id = parser__.readUint32();
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

bool CMsgClientToGCSetProfileCardSlot::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot_type = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot_value = parser__.readUint64();
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

bool CMsgClientToGCCreateHeroStatue::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         source_item = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         sequence_name = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         cycle = parser__.readFloat();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         wearables.push_back(parser__.readUint32());
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         inscription = parser__.readString();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         styles.push_back(parser__.readUint32());
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

bool CMsgClientToGCCreateTeamShowcase::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         source_item = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         sequence_name = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         cycle = parser__.readFloat();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         wearables.push_back(parser__.readUint32());
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         inscription = parser__.readString();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         styles.push_back(parser__.readUint32());
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

bool CMsgGCToClientHeroStatueCreateResult::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         resulting_item = parser__.readUint64();
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

bool CMsgGCToClientTeamShowcaseCreateResult::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         resulting_item = parser__.readUint64();
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

bool CMsgClientToGCRecordCompendiumStats::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         view_duration_s = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         videos_viewed = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         page_turns = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         links_followed = parser__.readUint32();
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

bool CMsgClientToGCRecordStatueStats::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         view_duration_s = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         created_statue = parser__.readBool();
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

bool CMsgGCToClientEventStatusChanged::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         active_events.push_back(static_cast<EIngameEvent>(parser__.readUint32()));
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

