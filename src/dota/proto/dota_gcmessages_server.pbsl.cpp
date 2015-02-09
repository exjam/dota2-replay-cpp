#include "dota_gcmessages_server.pbsl.h"
#include <pbsl/parser.h>

bool CMsgSpawnLootGreevil::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         rare = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDismissLootGreevil::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         killed = parser__.readBool();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         rare = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDismissLootGreevilResponse::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgPoorNetworkConditions::Player::parse(const std::string_view &data__)
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
         disconnect_reason = static_cast<ENetworkDisconnectionReason>(parser__.readUint32());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_bad_intervals = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         peak_loss_pct = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgPoorNetworkConditions::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         detection_type = static_cast<EPoorNetworkConditionsType>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         players.emplace_back();
         players.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgConnectedPlayers::Player::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         leaver_state.parse(parser__.readString());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         disconnect_reason = static_cast<ENetworkDisconnectionReason>(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgConnectedPlayers::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         connected_players.emplace_back();
         connected_players.back().parse(parser__.readString());
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         disconnected_players.emplace_back();
         disconnected_players.back().parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_state = static_cast<DOTA_GameState>(parser__.readUint32());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tower_state = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         first_blood_happened = parser__.readBool();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         legacy_mass_disconnect = parser__.readBool();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         poor_network_conditions.parse(parser__.readString());
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         send_reason = static_cast<SendReason>(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGameServerInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         server_public_ip_addr = parser__.readFixed32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         server_private_ip_addr = parser__.readFixed32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_port = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_tv_port = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         server_key = parser__.readString();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_hibernation = parser__.readBool();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_type = static_cast<ServerType>(parser__.readUint32());
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_region = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         server_loadavg = parser__.readFloat();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         server_tv_broadcast_time = parser__.readFloat();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         server_game_time = parser__.readFloat();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         server_relay_connected_steam_id = parser__.readFixed64();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         relay_slots_max = parser__.readUint32();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         relays_connected = parser__.readInt32();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         relay_clients_connected = parser__.readInt32();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         relayed_game_server_steam_id = parser__.readFixed64();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         parent_relay_count = parser__.readUint32();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         tv_secret_code = parser__.readFixed64();
         break;
      case 19:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_version = parser__.readUint32();
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_cluster = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgLeaverDetected::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leaver_status = static_cast<DOTALeaverStatus_t>(parser__.readUint32());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         leaver_state.parse(parser__.readString());
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_cluster = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         disconnect_reason = static_cast<ENetworkDisconnectionReason>(parser__.readUint32());
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         poor_network_conditions.parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgLeaverDetectedResponse::parse(const std::string_view &data__)
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

bool CMsgDOTAFantasyPlayerStats::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_id = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_completed = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         level = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         kills = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         deaths = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         assists = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         last_hits = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         denies = parser__.readUint32();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         gpm = parser__.readFloat();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         xppm = parser__.readFloat();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         stuns = parser__.readFloat();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         healing = parser__.readFloat();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tower_kills = parser__.readUint32();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         roshan_kills = parser__.readUint32();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         delay = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFantasyMatch::parse(const std::string_view &data__)
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
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         series_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         start_time = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         series_type = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_1 = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_2 = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGameMatchSignOut::CTeam::CPlayer::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         account_id = parser__.readFixed64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         items.push_back(parser__.readUint32());
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gold = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         kills = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         deaths = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         assists = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leaver_status = parser__.readUint32();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         last_hits = parser__.readUint32();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         denies = parser__.readUint32();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gold_per_min = parser__.readUint32();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         xp_per_minute = parser__.readUint32();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gold_spent = parser__.readUint32();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         level = parser__.readUint32();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_damage = parser__.readUint32();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tower_damage = parser__.readUint32();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_healing = parser__.readUint32();
         break;
      case 19:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_last_seen = parser__.readUint32();
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         support_ability_value = parser__.readUint32();
         break;
      case 21:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         party_id = parser__.readUint64();
         break;
      case 24:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         scaled_kills = parser__.readFloat();
         break;
      case 25:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         scaled_deaths = parser__.readFloat();
         break;
      case 26:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         scaled_assists = parser__.readFloat();
         break;
      case 27:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         claimed_farm_gold = parser__.readUint32();
         break;
      case 28:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         support_gold = parser__.readUint32();
         break;
      case 29:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         claimed_denies = parser__.readUint32();
         break;
      case 30:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         claimed_misses = parser__.readUint32();
         break;
      case 31:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         misses = parser__.readUint32();
         break;
      case 32:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         ability_upgrades.emplace_back();
         ability_upgrades.back().parse(parser__.readString());
         break;
      case 33:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         additional_units_inventory.emplace_back();
         additional_units_inventory.back().parse(parser__.readString());
         break;
      case 34:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         net_worth = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGameMatchSignOut::CTeam::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         players.emplace_back();
         players.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGameMatchSignOut::CAdditionalSignoutMsg::parse(const std::string_view &data__)
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

bool CMsgGameMatchSignOut::parse(const std::string_view &data__)
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
         duration = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         good_guys_win = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         date = parser__.readFixed32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_players.push_back(parser__.readUint32());
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         teams.emplace_back();
         teams.back().parse(parser__.readString());
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
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         server_addr = parser__.readString();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         first_blood_time = parser__.readUint32();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         game_balance = parser__.readFloat();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         event_score = parser__.readUint32();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         picks_bans.emplace_back();
         picks_bans.back().parse(parser__.readString());
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         fantasy_stats.emplace_back();
         fantasy_stats.back().parse(parser__.readString());
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         player_strange_count_adjustments.emplace_back();
         player_strange_count_adjustments.back().parse(parser__.readString());
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         automatic_surrender = parser__.readBool();
         break;
      case 19:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_version = parser__.readUint32();
         break;
      case 21:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         legacy_mass_disconnect = parser__.readBool();
         break;
      case 35:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         poor_network_conditions.parse(parser__.readString());
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         additional_msgs.emplace_back();
         additional_msgs.back().parse(parser__.readString());
         break;
      case 22:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         average_networth_delta = parser__.readSint32();
         break;
      case 23:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         networth_delta_min10 = parser__.readSint32();
         break;
      case 24:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         networth_delta_min20 = parser__.readSint32();
         break;
      case 25:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         maximum_losing_networth_lead = parser__.readSint32();
         break;
      case 26:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         average_experience_delta = parser__.readSint32();
         break;
      case 27:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         experience_delta_min10 = parser__.readSint32();
         break;
      case 28:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         experience_delta_min20 = parser__.readSint32();
         break;
      case 29:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bonus_gold_winner_min10 = parser__.readSint32();
         break;
      case 30:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bonus_gold_winner_min20 = parser__.readSint32();
         break;
      case 31:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bonus_gold_winner_total = parser__.readUint32();
         break;
      case 32:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bonus_gold_loser_min10 = parser__.readSint32();
         break;
      case 33:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bonus_gold_loser_min20 = parser__.readSint32();
         break;
      case 34:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bonus_gold_loser_total = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgSignOutDraftInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         radiant_captain_account_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         dire_captain_account_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         picks_bans.emplace_back();
         picks_bans.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgSignOutBotInfo::CMsgBotSlotDifficulty::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot = parser__.readUint32();
         break;
      case 2:
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

bool CMsgSignOutBotInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         allow_cheats = parser__.readBool();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bot_difficulty = static_cast<DOTABotDifficulty>(parser__.readUint32());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         created_lobby = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         bot_slot_difficulties.emplace_back();
         bot_slot_difficulties.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgSignOutCommunicationSummary::PlayerCommunication::parse(const std::string_view &data__)
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
         pings = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         max_pings_per_interval = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         teammate_pings = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         max_teammate_pings_per_interval = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_chat_messages = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         all_chat_messages = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         chat_wheel_messages = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         pauses = parser__.readUint32();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         unpauses = parser__.readUint32();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         lines_drawn = parser__.readUint32();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         voice_chat_seconds = parser__.readUint32();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         chat_mutes = parser__.readUint32();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         voice_mutes = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgSignOutCommunicationSummary::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         players.emplace_back();
         players.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGameMatchSignoutResponse::CAdditionalSignoutMsg::parse(const std::string_view &data__)
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

bool CMsgGameMatchSignoutResponse::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         replay_salt = parser__.readFixed32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         timed_reward_details.emplace_back();
         timed_reward_details.back().parse(parser__.readString());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         xp_reward_details.emplace_back();
         xp_reward_details.back().parse(parser__.readString());
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         leagueid = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         additional_msgs.emplace_back();
         additional_msgs.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGameMatchSignOutPermissionRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_version = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         local_attempt = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         total_attempt = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         seconds_waited = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGameMatchSignOutPermissionResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         permission_granted = parser__.readBool();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         abandon_signout = parser__.readBool();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         retry_delay_seconds = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGameChatLog::CChatLine::parse(const std::string_view &data__)
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
         team_only = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         text = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_time = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGameChatLog::parse(const std::string_view &data__)
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
         lines.emplace_back();
         lines.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTALiveScoreboardUpdate::Team::Player::HeroAbility::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         ability_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         ability_level = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTALiveScoreboardUpdate::Team::Player::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_slot = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         player_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         hero_name = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_id = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         kills = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         deaths = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         assists = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         last_hits = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         denies = parser__.readUint32();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gold = parser__.readUint32();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         level = parser__.readUint32();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         gold_per_min = parser__.readFloat();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         xp_per_min = parser__.readFloat();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         ultimate_state = static_cast<DOTAUltimateState>(parser__.readUint32());
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         ultimate_cooldown = parser__.readFloat();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item0 = parser__.readUint32();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item1 = parser__.readUint32();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item2 = parser__.readUint32();
         break;
      case 19:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item3 = parser__.readUint32();
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item4 = parser__.readUint32();
         break;
      case 21:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item5 = parser__.readUint32();
         break;
      case 22:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         respawn_timer = parser__.readUint32();
         break;
      case 23:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_id = parser__.readUint32();
         break;
      case 24:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         position_x = parser__.readFloat();
         break;
      case 25:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         position_y = parser__.readFloat();
         break;
      case 26:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         net_worth = parser__.readUint32();
         break;
      case 27:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         abilities.emplace_back();
         abilities.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTALiveScoreboardUpdate::Team::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         players.emplace_back();
         players.back().parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         score = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tower_state = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         barracks_state = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_picks.push_back(parser__.readUint32());
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hero_bans.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTALiveScoreboardUpdate::parse(const std::string_view &data__)
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
         tournament_game_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         duration = parser__.readFloat();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         hltv_delay = parser__.readInt32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_good.parse(parser__.readString());
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         team_bad.parse(parser__.readString());
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         roshan_respawn_timer = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
         break;
      case 9:
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

bool CMsgDOTARequestPlayerResources::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_id = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTARequestPlayerResourcesResponse::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         rank = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         prevent_text_chat = parser__.readBool();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         prevent_voice_chat = parser__.readBool();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         low_priority = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTARequestBatchPlayerResources::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         account_ids.push_back(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         legacy_rank_use_competitive = parser__.readBool();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         legacy_rank_use_solo.push_back(parser__.readBool());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         rank_types.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTARequestBatchPlayerResourcesResponse::Result::parse(const std::string_view &data__)
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
         prevent_text_chat = parser__.readBool();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         prevent_voice_chat = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         rank = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         rank_calibrated = parser__.readBool();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         low_priority = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTARequestBatchPlayerResourcesResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 6:
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

bool CMsgDOTAPlayerFailedToConnect::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         failed_loaders.push_back(parser__.readFixed64());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         abandoned_loaders.push_back(parser__.readFixed64());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToRelayConnect::parse(const std::string_view &data__)
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
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_server_steam_id = parser__.readUint64();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         parent_count = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         tv_unique_secret_code = parser__.readFixed64();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         source_tv_steamid = parser__.readFixed64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCGCToLANServerRelayConnect::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         relay_steamid = parser__.readFixed64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToRelayConnectResponse::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgGCBanStatusRequest::parse(const std::string_view &data__)
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

bool CMsgGCBanStatusResponse::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         low_priority = parser__.readBool();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         text_chat_banned = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         voice_chat_banned = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgTournamentItemEvent::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         killer_account_id = parser__.readFixed32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         victim_account_id = parser__.readFixed32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         event_type = static_cast<DOTA_TournamentEvents>(parser__.readUint32());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tv_delay = parser__.readInt32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         dota_time = parser__.readInt32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         replay_time = parser__.readFloat();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         loot_list = parser__.readString();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         event_team = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         multi_kill_count = parser__.readUint32();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         winner_score = parser__.readUint32();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         loser_score = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgTournamentItemEventResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         event_type = static_cast<DOTA_TournamentEvents>(parser__.readUint32());
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         viewers_granted = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgTeamFanfare::parse(const std::string_view &data__)
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

bool CMsgResponseTeamFanfare::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fanfare_goodguys = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         fanfare_badguys = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGameServerUploadSaveGame::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         save_game_data = parser__.readBytes();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         lobby_id = parser__.readUint64();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_steam_ids.push_back(parser__.readUint64());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGameServerSaveGameResult::parse(const std::string_view &data__)
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

bool CMsgGameServerGetLoadGame::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         save_id = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGameServerGetLoadGameResult::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         save_game_data = parser__.readBytes();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAGenerateDiretidePrizeList::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         prize_list = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         highest_roshan_level = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAGenerateDiretidePrizeListResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_defs.push_back(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         steam_ids.push_back(parser__.readFixed64());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         prize_list = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTARewardDiretidePrizes::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         prize_list = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTADiretidePrizesRewardedResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         prize_list = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAAwardEventPoints::AwardPoints::parse(const std::string_view &data__)
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
         points = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         premium_points = parser__.readInt32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         trade_ban_time = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAAwardEventPoints::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         award_points.emplace_back();
         award_points.back().parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         match_id = parser__.readUint64();
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

bool CMsgServerToGCSignoutAwardAdditionalDrops::AdditionalDrops::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         loot_list = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_account_ids.push_back(parser__.readUint32());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         no_trade = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         randomize_reward = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgServerToGCSignoutAwardAdditionalDrops::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         drops.emplace_back();
         drops.back().parse(parser__.readString());
         break;
      case 2:
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

bool CMsgDOTAUpdateTI4HeroQuest::Player::parse(const std::string_view &data__)
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

bool CMsgDOTAUpdateTI4HeroQuest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         players.emplace_back();
         players.back().parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         match_start_time = parser__.readFixed32();
         break;
      case 3:
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

bool CMsgDOTAFrostivusTimeElapsed::User::parse(const std::string_view &data__)
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
         time_elapsed_s = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDOTAFrostivusTimeElapsed::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         seconds = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         users.emplace_back();
         users.back().parse(parser__.readString());
         break;
      case 3:
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

bool CMsgGCToServerPingRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         request_id = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         request_time = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToServerPingResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         request_id = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         request_time = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         cluster = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToServerConsoleCommand::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         console_command = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgServerGetEventPoints::parse(const std::string_view &data__)
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
         account_id.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgServerGetEventPointsResponse::Points::parse(const std::string_view &data__)
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
         points_total = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         premium_total = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgServerGetEventPointsResponse::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         points.emplace_back();
         points.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgServerGrantSurveyPermission::Survey::parse(const std::string_view &data__)
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
         question_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         expire_time = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         survey_key = parser__.readUint64();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         extra_data = parser__.readUint64();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         extra_data_32 = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgServerGrantSurveyPermission::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         surveys.emplace_back();
         surveys.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgServerGrantSurveyPermissionResponse::parse(const std::string_view &data__)
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

bool CMsgServerToGCMatchConnectionStats::Player::parse(const std::string_view &data__)
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
         ip = parser__.readFixed32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         avg_ping_ms = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         packet_loss = parser__.readFloat();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         ping_deviation = parser__.readFloat();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         full_resends = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgServerToGCMatchConnectionStats::parse(const std::string_view &data__)
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
         region_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         league_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         players.emplace_back();
         players.back().parse(parser__.readString());
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         cluster_id = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgServerGCUpdateSpectatorCount::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         spectator_count = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSerializedCombatLog::Dictionary::DictString::parse(const std::string_view &data__)
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

bool CSerializedCombatLog::Dictionary::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         strings.emplace_back();
         strings.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSerializedCombatLog::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         version = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         dictionary.parse(parser__.readString());
         break;
      case 3:
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

bool CMsgServerToGCGetAdditionalEquips::parse(const std::string_view &data__)
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

bool CMsgServerToGCGetAdditionalEquipsResponse::CUserEquips::parse(const std::string_view &data__)
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

bool CMsgServerToGCGetAdditionalEquipsResponse::parse(const std::string_view &data__)
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

bool CMsgServerToGCGetProfileCard::parse(const std::string_view &data__)
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

bool CMsgServerToGCGetProfileCardResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         cards.emplace_back();
         cards.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgServerToGCVictoryPredictions::Record::parse(const std::string_view &data__)
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
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_ids.push_back(parser__.readUint64());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgServerToGCVictoryPredictions::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         records.emplace_back();
         records.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgSuspiciousActivity::parse(const std::string_view &data__)
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
         activity = static_cast<ESuspiciousActivity>(parser__.readUint32());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         intdata1 = parser__.readSint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         intdata2 = parser__.readSint32();
         break;
      case 5:
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

bool CMsgServerToGCRequestStatus::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgServerToGCRequestStatus_Response::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         response = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgSignOutAssassinMiniGameInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         winning_players.push_back(parser__.readFixed64());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         losing_players.push_back(parser__.readFixed64());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         arcana_owners.push_back(parser__.readFixed64());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         assassin_won = parser__.readBool();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         target_hero_id = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         contract_completed = parser__.readBool();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         contract_complete_time = parser__.readFloat();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         pa_is_radiant = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgServerToGCGetIngameEventData::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         event = static_cast<EIngameEvent>(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToServerIngameEventDataOraclePA::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         target_hero_ids.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgServerToGCKillSummaries::KillSummary::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         killer_hero_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         victim_hero_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         kill_count = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgServerToGCKillSummaries::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         ingameevent_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         summaries.emplace_back();
         summaries.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToServerPredictionResult::Prediction::parse(const std::string_view &data__)
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
         num_correct = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_fails = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<EResult>(parser__.readUint32());
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         granted_item_def = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToServerPredictionResult::parse(const std::string_view &data__)
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
         match_id = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         correct = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         predictions.emplace_back();
         predictions.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

