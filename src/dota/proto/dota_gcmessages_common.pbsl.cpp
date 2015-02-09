#include "dota_gcmessages_common.pbsl.h"
#include <pbsl/parser.h>

bool CSODOTAGameAccountClient::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         wins = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         losses = parser__.readUint32();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         xp = parser__.readUint32();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         level = parser__.readUint32();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         initial_skill = parser__.readUint32();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leaver_count = parser__.readUint32();
         break;
      case 58:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         secondary_leaver_count = parser__.readUint32();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         low_priority_until_date = parser__.readUint32();
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         prevent_text_chat_until_date = parser__.readUint32();
         break;
      case 21:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         prevent_voice_until_date = parser__.readUint32();
         break;
      case 22:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         last_abandoned_game_date = parser__.readUint32();
         break;
      case 59:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         last_secondary_abandoned_game_date = parser__.readUint32();
         break;
      case 23:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leaver_penalty_count = parser__.readUint32();
         break;
      case 24:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         completed_game_streak = parser__.readUint32();
         break;
      case 28:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         teaching = parser__.readUint32();
         break;
      case 29:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leadership = parser__.readUint32();
         break;
      case 30:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         friendly = parser__.readUint32();
         break;
      case 31:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         forgiving = parser__.readUint32();
         break;
      case 38:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_disabled_until_date = parser__.readUint32();
         break;
      case 39:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_disabled_count = parser__.readUint32();
         break;
      case 40:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         showcase_hero_id = parser__.readUint32();
         break;
      case 41:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_disabled_until_date = parser__.readUint32();
         break;
      case 42:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_disabled_count = parser__.readUint32();
         break;
      case 44:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         partner_account_type = static_cast<PartnerAccountType>(parser__.readUint32());
         break;
      case 45:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         partner_account_state = parser__.readUint32();
         break;
      case 47:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         shutdownlawterminatetimestamp = parser__.readUint32();
         break;
      case 48:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         low_priority_games_remaining = parser__.readUint32();
         break;
      case 49:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         competitive_rank = parser__.readUint32();
         break;
      case 51:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         calibration_games_remaining = parser__.readUint32();
         break;
      case 52:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         solo_competitive_rank = parser__.readUint32();
         break;
      case 54:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         solo_calibration_games_remaining = parser__.readUint32();
         break;
      case 63:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         competitive_1v1_rank = parser__.readUint32();
         break;
      case 64:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         competitive_1v1_calibration_games_remaining = parser__.readUint32();
         break;
      case 55:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         recruitment_level = parser__.readUint32();
         break;
      case 56:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         has_new_notifications = parser__.readBool();
         break;
      case 57:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_league_admin = parser__.readBool();
         break;
      case 60:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         casual_games_played = parser__.readUint32();
         break;
      case 61:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         solo_competitive_games_played = parser__.readUint32();
         break;
      case 62:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         party_competitive_games_played = parser__.readUint32();
         break;
      case 65:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         casual_1v1_games_played = parser__.readUint32();
         break;
      case 66:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         competitive_team_games_played = parser__.readUint32();
         break;
      case 67:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         curr_all_hero_challenge_id = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSODOTAPartyMember::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         partner_type = static_cast<PartnerAccountType>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_coach = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSODOTAParty::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         leader_id = parser__.readFixed64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         member_ids.push_back(parser__.readFixed64());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_modes = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         pending_invites.push_back(parser__.readFixed64());
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         state = static_cast<State>(parser__.readUint32());
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         effective_started_matchmaking_time = parser__.readUint32();
         break;
      case 32:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         raw_started_matchmaking_time = parser__.readUint32();
         break;
      case 33:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         attempt_start_time = parser__.readUint32();
         break;
      case 34:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         attempt_num = parser__.readUint32();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         matchgroups = parser__.readUint32();
         break;
      case 19:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         low_priority_account_id = parser__.readUint32();
         break;
      case 21:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_type = static_cast<MatchType>(parser__.readUint32());
         break;
      case 22:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bot_difficulty = static_cast<DOTABotDifficulty>(parser__.readUint32());
         break;
      case 23:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
         break;
      case 24:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_disabled_until_date = parser__.readUint32();
         break;
      case 25:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_disabled_account_id = parser__.readUint32();
         break;
      case 26:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         matchmaking_max_range_minutes = parser__.readUint32();
         break;
      case 27:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         matchlanguages = parser__.readUint32();
         break;
      case 38:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         map_preference = parser__.readUint32();
         break;
      case 29:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         members.emplace_back();
         members.back().parse(parser__.readString());
         break;
      case 30:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         open_guild_id = parser__.readUint32();
         break;
      case 31:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         common_guilds.push_back(parser__.readUint32());
         break;
      case 35:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         low_priority_games_remaining = parser__.readUint32();
         break;
      case 36:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         min_level = parser__.readUint32();
         break;
      case 37:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         max_level = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSODOTAPartyInvite::PartyMember::parse(const std::string_view &data__)
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

bool CSODOTAPartyInvite::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         group_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         sender_id = parser__.readFixed64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         sender_name = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         members.emplace_back();
         members.back().parse(parser__.readString());
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         low_priority_status = parser__.readBool();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         as_coach = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAPartyMemberSetCoach::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         wants_coach = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CDOTASaveGame::Player::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         hero = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CDOTASaveGame::SaveInstance::PlayerPositions::parse(const std::string_view &data__)
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

bool CDOTASaveGame::SaveInstance::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_time = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team1_score = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team2_score = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         player_positions.emplace_back();
         player_positions.back().parse(parser__.readString());
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         save_id = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         save_time = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CDOTASaveGame::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         save_time = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         players.emplace_back();
         players.back().parse(parser__.readString());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         save_instances.emplace_back();
         save_instances.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgLeaverState::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         lobby_state = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_state = static_cast<DOTA_GameState>(parser__.readUint32());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leaver_detected = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         first_blood_happened = parser__.readBool();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         discard_match_results = parser__.readBool();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         mass_disconnect = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CDOTALobbyMember::CDOTALobbyMemberXPBonus::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         xp_bonus = parser__.readFloat();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         source_key = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CDOTALobbyMember::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         id = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team = static_cast<DOTA_GC_TEAM>(parser__.readUint32());
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         name = parser__.readString();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot = parser__.readUint32();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         party_id = parser__.readUint64();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         meta_level = parser__.readUint32();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         meta_xp = parser__.readUint32();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         meta_xp_awarded = parser__.readUint32();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leaver_status = static_cast<DOTALeaverStatus_t>(parser__.readUint32());
         break;
      case 28:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leaver_actions = parser__.readUint32();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         channel = parser__.readUint32();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         prize_def_index = parser__.readUint32();
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         disabled_hero_id.push_back(parser__.readUint32());
         break;
      case 21:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         partner_account_type = static_cast<PartnerAccountType>(parser__.readUint32());
         break;
      case 22:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         enabled_hero_id.push_back(parser__.readUint32());
         break;
      case 23:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         coach_team = static_cast<DOTA_GC_TEAM>(parser__.readUint32());
         break;
      case 24:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         nexon_pc_bang_no = parser__.readUint32();
         break;
      case 25:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         nexon_pc_bang_name = parser__.readString();
         break;
      case 27:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         xp_bonuses.emplace_back();
         xp_bonuses.back().parse(parser__.readString());
         break;
      case 29:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         rank_change = parser__.readSint32();
         break;
      case 30:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         cameraman = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CLobbyTeamDetails::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_tag = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_logo = parser__.readUint64();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_base_logo = parser__.readUint64();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_banner_logo = parser__.readUint64();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_complete = parser__.readBool();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         guild_name = parser__.readString();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         guild_tag = parser__.readString();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_id = parser__.readUint32();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_logo = parser__.readUint64();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_base_logo = parser__.readUint64();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         guild_banner_logo = parser__.readUint64();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         rank = parser__.readUint32();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         rank_change = parser__.readSint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CLobbyTimedRewardDetails::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_def_index = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_supply_crate = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_timed_drop = parser__.readBool();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         origin = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CLobbyBroadcastChannelInfo::parse(const std::string_view &data__)
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

bool CSODOTALobby::CExtraMsg::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         contents = parser__.readBytes();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSODOTALobby::parse(const std::string_view &data__)
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
         members.emplace_back();
         members.back().parse(parser__.readString());
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         left_members.emplace_back();
         left_members.back().parse(parser__.readString());
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         leader_id = parser__.readFixed64();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         server_id = parser__.readFixed64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_mode = parser__.readUint32();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         pending_invites.push_back(parser__.readFixed64());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         state = static_cast<State>(parser__.readUint32());
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         connect = parser__.readString();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         lobby_type = static_cast<LobbyType>(parser__.readUint32());
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         allow_cheats = parser__.readBool();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fill_with_bots = parser__.readBool();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         intro_mode = parser__.readBool();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         game_name = parser__.readString();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_details.emplace_back();
         team_details.back().parse(parser__.readString());
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tutorial_lesson = parser__.readUint32();
         break;
      case 19:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_id = parser__.readUint32();
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tournament_game_id = parser__.readUint32();
         break;
      case 21:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_region = parser__.readUint32();
         break;
      case 22:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_state = static_cast<DOTA_GameState>(parser__.readUint32());
         break;
      case 23:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_spectators = parser__.readUint32();
         break;
      case 25:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         matchgroup = parser__.readUint32();
         break;
      case 28:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         cm_pick = static_cast<DOTA_CM_PICK>(parser__.readUint32());
         break;
      case 30:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_id = parser__.readUint64();
         break;
      case 31:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         allow_spectating = parser__.readBool();
         break;
      case 36:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bot_difficulty = static_cast<DOTABotDifficulty>(parser__.readUint32());
         break;
      case 37:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_version = static_cast<DOTAGameVersion>(parser__.readUint32());
         break;
      case 38:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         timed_reward_details.emplace_back();
         timed_reward_details.back().parse(parser__.readString());
         break;
      case 39:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         pass_key = parser__.readString();
         break;
      case 41:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bot_slot_difficulty.push_back(static_cast<DOTABotDifficulty>(parser__.readUint32()));
         break;
      case 42:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leagueid = parser__.readUint32();
         break;
      case 43:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         penalty_level_radiant = parser__.readUint32();
         break;
      case 44:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         penalty_level_dire = parser__.readUint32();
         break;
      case 45:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         load_game_id = parser__.readUint32();
         break;
      case 46:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         series_type = parser__.readUint32();
         break;
      case 47:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         radiant_series_wins = parser__.readUint32();
         break;
      case 48:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         dire_series_wins = parser__.readUint32();
         break;
      case 49:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         loot_generated = parser__.readUint32();
         break;
      case 50:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         loot_awarded = parser__.readUint32();
         break;
      case 51:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         allchat = parser__.readBool();
         break;
      case 53:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         dota_tv_delay = static_cast<LobbyDotaTVDelay>(parser__.readUint32());
         break;
      case 54:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         custom_game_mode = parser__.readString();
         break;
      case 55:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         custom_map_name = parser__.readString();
         break;
      case 56:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         custom_difficulty = parser__.readUint32();
         break;
      case 57:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         lan = parser__.readBool();
         break;
      case 58:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         broadcast_channel_info.emplace_back();
         broadcast_channel_info.back().parse(parser__.readString());
         break;
      case 59:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         first_leaver_accountid = parser__.readUint32();
         break;
      case 60:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         series_id = parser__.readUint32();
         break;
      case 61:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         low_priority = parser__.readBool();
         break;
      case 62:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         extra_messages.emplace_back();
         extra_messages.back().parse(parser__.readString());
         break;
      case 63:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         save_game.parse(parser__.readString());
         break;
      case 65:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         first_blood_happened = parser__.readBool();
         break;
      case 66:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         legacy_discard_match_results = parser__.readBool();
         break;
      case 70:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_outcome = static_cast<EMatchOutcome>(parser__.readUint32());
         break;
      case 67:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         mass_disconnect = parser__.readBool();
         break;
      case 68:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         custom_game_id = parser__.readUint64();
         break;
      case 69:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         active_ingame_events.push_back(static_cast<EIngameEvent>(parser__.readUint32()));
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAGenericResult::parse(const std::string_view &data__)
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

bool CMsgDOTABroadcastNotification::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         message = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAPCBangTimedReward::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         persona = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         itemdef = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         pcbangname = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CAttribute_String::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CAttribute_ItemDynamicRecipeComponent::parse(const std::string_view &data__)
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
         item_quality = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_flags = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         attributes_string = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_count = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         items_fulfilled = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_rarity = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         lootlist = parser__.readString();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fulfilled_item_id = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CProtoItemHeroStatue::parse(const std::string_view &data__)
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
         status_effect_index = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         sequence_name = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         cycle = parser__.readFloat();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         wearable.push_back(parser__.readUint32());
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         inscription = parser__.readString();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         style.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CProtoItemTeamShowcase::parse(const std::string_view &data__)
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
         status_effect_index = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         sequence_name = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         cycle = parser__.readFloat();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         wearable.push_back(parser__.readUint32());
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         inscription = parser__.readString();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         style.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CProtoItemSocket::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         attr_def_index = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         required_type = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         required_hero = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gem_def_index = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         not_tradable = parser__.readBool();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         required_item_slot = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CProtoItemSocket_Empty::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         socket.parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CProtoItemSocket_Effect::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         socket.parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         effect = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CProtoItemSocket_Color::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         socket.parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         red = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         green = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         blue = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CProtoItemSocket_Strange::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         socket.parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         strange_type = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         strange_value = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CProtoItemSocket_Spectator::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         socket.parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         games_viewed = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         corporation_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
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

bool CProtoItemSocket_AssetModifier::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         socket.parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         asset_modifier = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CProtoItemSocket_Autograph::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         socket.parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         autograph = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         autograph_id = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CProtoItemSocket_AbilityEffect::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         socket.parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         ability_effect = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CProtoItemSocket_StaticVisuals::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         socket.parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMatchPlayerAbilityUpgrade::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         ability = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMatchAdditionalUnitInventory::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         unit_name = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         items.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMatchHeroSelectEvent::parse(const std::string_view &data__)
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

bool CMsgDOTAProcessFantasyScheduledEvent::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         event = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         timestamp = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         season = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         reference_data = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAHasItemQuery::parse(const std::string_view &data__)
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
         item_id = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAHasItemResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         has_item = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAHasItemDefsQuery::parse(const std::string_view &data__)
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
         itemdef_ids.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAHasItemDefsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         has_items = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAConsumeFantasyTicket::parse(const std::string_view &data__)
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
         item_id = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAConsumeFantasyTicketFailure::parse(const std::string_view &data__)
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
         item_id = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCFantasySetMatchLeague::parse(const std::string_view &data__)
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

bool CSODOTAMapLocationState::parse(const std::string_view &data__)
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
         location_id = parser__.readInt32();
         break;
      case 3:
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

bool CMsgNexonPartnerUpdate::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         messagetype = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         timeremaining = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         terminate = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgMakeOffering::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_id = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgRequestOfferings::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgRequestOfferingsResponse::NewYearsOffering::parse(const std::string_view &data__)
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
         item_id = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgRequestOfferingsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         offerings.emplace_back();
         offerings.back().parse(parser__.readString());
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

bool CMsgLeagueAdminList::parse(const std::string_view &data__)
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

bool CMsgPerfectWorldUserLookupRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         user_name = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgPerfectWorldUserLookupResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result_code = static_cast<EResultCode>(parser__.readUint32());
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

bool CCompendiumTimestampedData::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_time = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gpm = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         xpm = parser__.readUint32();
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
         item_purchases.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CCompendiumGameTimeline::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         data.emplace_back();
         data.back().parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         tags.push_back(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CCompendiumGameList::parse(const std::string_view &data__)
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
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CAdditionalEquipSlot::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         class_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         def_index = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTARedeemItem::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         currency_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         purchase_def = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTARedeemItemResponse::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgDOTACombatLogEntry::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         type = static_cast<DOTA_COMBATLOG_TYPES>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         target_name = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         target_source_name = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         attacker_name = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         damage_source_name = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         inflictor_name = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_attacker_illusion = parser__.readBool();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_attacker_hero = parser__.readBool();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_target_illusion = parser__.readBool();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_target_hero = parser__.readBool();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_visible_radiant = parser__.readBool();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_visible_dire = parser__.readBool();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         value = parser__.readUint32();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         health = parser__.readInt32();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         timestamp = parser__.readFloat();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         stun_duration = parser__.readFloat();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         slow_duration = parser__.readFloat();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_ability_toggle_on = parser__.readBool();
         break;
      case 19:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_ability_toggle_off = parser__.readBool();
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         ability_level = parser__.readUint32();
         break;
      case 21:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         location_x = parser__.readFloat();
         break;
      case 22:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         location_y = parser__.readFloat();
         break;
      case 23:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gold_reason = parser__.readUint32();
         break;
      case 24:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         timestamp_raw = parser__.readFloat();
         break;
      case 25:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         modifier_duration = parser__.readFloat();
         break;
      case 26:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         xp_reason = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAProfileCard::Slot::Trophy::parse(const std::string_view &data__)
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

bool CMsgDOTAProfileCard::Slot::Stat::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         stat_id = static_cast<CMsgDOTAProfileCard::EStatID>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         stat_score = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAProfileCard::Slot::Item::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         serialized_item = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAProfileCard::Slot::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         trophy.parse(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         stat.parse(parser__.readString());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         item.parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAProfileCard::parse(const std::string_view &data__)
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
         background_def_index = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         slots.emplace_back();
         slots.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

