#include "dota_gcmessages_client_fantasy.pbsl.h"
#include <pbsl/parser.h>

bool CMsgGCPlayerInfo::PlayerInfo::parse(const std::string_view &data__)
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
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         country_code = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_role = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
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
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         sponsor = parser__.readString();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_locked = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCPlayerInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         player_infos.emplace_back();
         player_infos.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTACreateFantasyLeagueRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         league_name = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_logo = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         selection_mode = static_cast<Fantasy_Selection_Mode>(parser__.readUint32());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_count = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTACreateFantasyLeagueResponse::parse(const std::string_view &data__)
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

bool CMsgFantasyLeagueScoring::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         level = parser__.readFloat();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         kills = parser__.readFloat();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         deaths = parser__.readFloat();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         assists = parser__.readFloat();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         last_hits = parser__.readFloat();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         denies = parser__.readFloat();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         gpm = parser__.readFloat();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         xppm = parser__.readFloat();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         stuns = parser__.readFloat();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         healing = parser__.readFloat();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         tower_kills = parser__.readFloat();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         roshan_kills = parser__.readFloat();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         multiplier_premium = parser__.readFloat();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         multiplier_professional = parser__.readFloat();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyLeagueInfo::OwnerInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         owner_account_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         left_league = parser__.readBool();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_account_id.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyLeagueInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         commissioner_account_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         fantasy_league_name = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         selection_mode = static_cast<Fantasy_Selection_Mode>(parser__.readUint32());
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_count = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         logo = parser__.readUint64();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         scoring.parse(parser__.readString());
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         draft_time = parser__.readUint32();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         draft_pick_time = parser__.readUint32();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         season_start = parser__.readUint32();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         season_length = parser__.readUint32();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         veto_votes = parser__.readUint32();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         acquisitions = parser__.readUint32();
         break;
      case 19:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot_1 = parser__.readUint32();
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot_2 = parser__.readUint32();
         break;
      case 21:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot_3 = parser__.readUint32();
         break;
      case 22:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot_4 = parser__.readUint32();
         break;
      case 23:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot_5 = parser__.readUint32();
         break;
      case 24:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bench_slots = parser__.readUint32();
         break;
      case 25:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         owner_info.emplace_back();
         owner_info.back().parse(parser__.readString());
         break;
      case 26:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         players.push_back(parser__.readUint32());
         break;
      case 27:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_zone = parser__.readUint32();
         break;
      case 28:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         season = parser__.readUint32();
         break;
      case 29:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         password = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyLeagueEditInfoRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         edit_info.parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyLeagueEditInfoResponse::parse(const std::string_view &data__)
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

bool CMsgDOTAFantasyLeagueFindRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         password = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyLeagueFindResponse::parse(const std::string_view &data__)
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
         fantasy_league_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         commissioner_name = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyLeagueInfoRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CMsgDOTAFantasyLeagueInfoResponse::parse(const std::string_view &data__)
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

bool CMsgDOTAFantasyLeagueMatchupsRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CMsgDOTAFantasyLeagueMatchupsResponse::Matchup::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         owner_account_id_1 = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         owner_account_id_2 = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         score_1 = parser__.readFloat();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         score_2 = parser__.readFloat();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyLeagueMatchupsResponse::WeeklyMatchups::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         matchup.emplace_back();
         matchup.back().parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         start_time = parser__.readUint32();
         break;
      case 3:
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

bool CMsgDOTAFantasyLeagueMatchupsResponse::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         weekly_matchups.emplace_back();
         weekly_matchups.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAEditFantasyTeamRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_index = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_name = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_logo = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAEditFantasyTeamResponse::parse(const std::string_view &data__)
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

bool CMsgDOTAFantasyTeamInfoRequestByFantasyLeagueID::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CMsgDOTAFantasyTeamInfoRequestByOwnerAccountID::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         owner_account_id = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyTeamInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         owner_account_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_team_index = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_name = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_logo = parser__.readUint64();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         wins = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         losses = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         current_roster.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyTeamInfoResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         results.emplace_back();
         results.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyTeamScoreRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         owner_account_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_team_index = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         filter_match_id = parser__.readUint64();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         filter_start_time = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         filter_end_time = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         include_bench = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyTeamScoreResponse::CMsgPlayerScore::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         score = parser__.readFloat();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyTeamScoreResponse::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         fantasy_team_score = parser__.readFloat();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         fantasy_player_score.emplace_back();
         fantasy_player_score.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyTeamStandingsRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         count = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         filter_start_time = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         filter_end_time = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         filter_match_id = parser__.readUint64();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         filter_last_match = parser__.readBool();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         filter_in_hall = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyTeamStandingsResponse::CMsgTeamScore::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         owner_account_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_team_index = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_team_logo = parser__.readUint64();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         owner_name = parser__.readString();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         fantasy_team_name = parser__.readString();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         score = parser__.readFloat();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         score_against = parser__.readFloat();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         wins = parser__.readUint32();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         losses = parser__.readUint32();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         streak = parser__.readInt32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyTeamStandingsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<EResult>(parser__.readUint32());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_scores.emplace_back();
         team_scores.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyPlayerScoreRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_account_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         filter_start_time = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         filter_end_time = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         filter_match_id = parser__.readUint64();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         filter_last_match = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyPlayerScoreResponse::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_account_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         player_name = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         score = parser__.readFloat();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyPlayerStandingsRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         count = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         role = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         filter_start_time = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         filter_end_time = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         filter_match_id = parser__.readUint64();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         filter_last_match = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyPlayerStandingsResponse::CMsgPlayerScore::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_account_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         player_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         score = parser__.readFloat();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyPlayerStandingsResponse::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         role = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         player_scores.emplace_back();
         player_scores.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyPlayerInfoRequest::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgDOTAFantasyPlayerInfoResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CMsgDOTAFantasyLeagueCreateRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         season_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         fantasy_league_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         password = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_name = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         logo = parser__.readUint64();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         ticket_item_id = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyLeagueCreateResponse::parse(const std::string_view &data__)
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

bool CMsgDOTAFantasyTeamCreateRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         password = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_name = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         logo = parser__.readUint64();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         ticket_item_id = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyTeamCreateResponse::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_team_index = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyLeagueEditInvitesRequest::InviteChange::parse(const std::string_view &data__)
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
         invited = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyLeagueEditInvitesRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         password = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         invite_change.emplace_back();
         invite_change.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyLeagueEditInvitesResponse::parse(const std::string_view &data__)
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

bool CMsgDOTAFantasyLeagueDraftStatusRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CMsgDOTAFantasyLeagueDraftStatus::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         draft_order.push_back(parser__.readUint32());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         current_pick = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_remaining = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         pending_resume = parser__.readBool();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         completed = parser__.readBool();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         available_players.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyLeagueDraftPlayerRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_index = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_account_id = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyLeagueDraftPlayerResponse::parse(const std::string_view &data__)
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

bool CMsgDOTAFantasyTeamRosterSwapRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_index = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         timestamp = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot_1 = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot_2 = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyTeamRosterSwapResponse::parse(const std::string_view &data__)
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

bool CMsgDOTAFantasyTeamRosterAddDropRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_index = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         add_account_id = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         drop_account_id = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyTeamRosterAddDropResponse::parse(const std::string_view &data__)
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

bool CMsgDOTAFantasyTeamTradesRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CMsgDOTAFantasyTeamTradesResponse::Trade::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         timestamp = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         owner_account_id_1 = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         owner_account_id_2 = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_account_id_1 = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_account_id_2 = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         status = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyTeamTradesResponse::parse(const std::string_view &data__)
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
         trades.emplace_back();
         trades.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyTeamTradeCancelRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_index_1 = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         owner_account_id_2 = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_index_2 = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyTeamTradeCancelResponse::parse(const std::string_view &data__)
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

bool CMsgDOTAFantasyTeamRosterRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_index = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         owner_account_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         timestamp = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyTeamRosterResponse::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_account_ids.push_back(parser__.readUint32());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_locked.push_back(parser__.readBool());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyPlayerHisoricalStatsRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CMsgDOTAFantasyPlayerHisoricalStatsResponse::PlayerScoreAccumulator::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         matches = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         levels = parser__.readFloat();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         kills = parser__.readFloat();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         deaths = parser__.readFloat();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         assists = parser__.readFloat();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         last_hits = parser__.readFloat();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         denies = parser__.readFloat();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         gpm = parser__.readFloat();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         xppm = parser__.readFloat();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         stuns = parser__.readFloat();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         healing = parser__.readFloat();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         tower_kills = parser__.readFloat();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         roshan_kills = parser__.readFloat();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         score = parser__.readFloat();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyPlayerHisoricalStatsResponse::PlayerStats::parse(const std::string_view &data__)
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
         weeks = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         stats_premium.parse(parser__.readString());
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         stats_professional.parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyPlayerHisoricalStatsResponse::parse(const std::string_view &data__)
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
         stats.emplace_back();
         stats.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyMessageAdd::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
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

bool CMsgDOTAFantasyMessagesRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         start_message = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         end_message = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyMessagesResponse::Message::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         message_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         message = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         author_account_id = parser__.readUint32();
         break;
      case 4:
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

bool CMsgDOTAFantasyMessagesResponse::parse(const std::string_view &data__)
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
         messages.emplace_back();
         messages.back().parse(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_total_messages = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyRemoveOwner::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         owner_account_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_index = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyRemoveOwnerResponse::parse(const std::string_view &data__)
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

bool CMsgDOTAFantasyScheduledMatchesRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CMsgDOTAFantasyScheduledMatchesResponse::ScheduledMatchDays::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         timestamp = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_ids.push_back(parser__.readUint32());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_ids.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyScheduledMatchesResponse::parse(const std::string_view &data__)
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
         scheduled_match_days.emplace_back();
         scheduled_match_days.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyLeaveLeagueRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_team_index = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyLeaveLeagueResponse::parse(const std::string_view &data__)
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

bool CMsgDOTAFantasyPlayerScoreDetailsRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fantasy_league_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_account_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         start_time = parser__.readUint32();
         break;
      case 4:
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

bool CMsgDOTAFantasyPlayerScoreDetailsResponse::PlayerMatchData::parse(const std::string_view &data__)
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
         series_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         series_num = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         series_type = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_tier = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         opposing_team_id = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         opposing_team_logo = parser__.readUint64();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         opposing_team_name = parser__.readString();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         stats.parse(parser__.readString());
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         owned_by = parser__.readUint32();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         benched = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyPlayerScoreDetailsResponse::parse(const std::string_view &data__)
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

