#include "base_gcmessages.pbsl.h"
#include <pbsl/parser.h>

bool CGCStorePurchaseInit_LineItem::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_def_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         quantity = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         cost_in_local_currency = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         purchase_type = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         source_reference_id = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCStorePurchaseInit::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         country = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         language = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         currency = parser__.readInt32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         line_items.emplace_back();
         line_items.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCStorePurchaseInitResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         txn_id = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSOPartyInvite::parse(const std::string_view &data__)
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
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSOLobbyInvite::parse(const std::string_view &data__)
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
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgSystemBroadcast::parse(const std::string_view &data__)
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

bool CMsgInviteToParty::parse(const std::string_view &data__)
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
         client_version = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
         break;
      case 4:
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

bool CMsgInvitationCreated::parse(const std::string_view &data__)
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

bool CMsgPartyInviteResponse::parse(const std::string_view &data__)
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
         accept = parser__.readBool();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         client_version = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         team_id = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         as_coach = parser__.readBool();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         game_language_enum = parser__.readUint32();
         break;
      case 7:
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

bool CMsgKickFromParty::parse(const std::string_view &data__)
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

bool CMsgLeaveParty::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgServerAvailable::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgLANServerAvailable::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         lobby_id = parser__.readFixed64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSOEconGameAccountClient::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         additional_backpack_slots = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         trial_account = parser__.readBool();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eligible_for_online_play = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         need_to_choose_most_helpful_friend = parser__.readBool();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         in_coaches_list = parser__.readBool();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         trade_ban_expiration = parser__.readFixed32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         duel_ban_expiration = parser__.readFixed32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         preview_item_def = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         made_first_purchase = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSOItemCriteriaCondition::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         op = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         field = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         required = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         float_value = parser__.readFloat();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         string_value = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSOItemCriteria::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_level = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_quality = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_level_set = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_quality_set = parser__.readBool();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         initial_inventory = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         initial_quantity = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         ignore_enabled_flag = parser__.readBool();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         conditions.emplace_back();
         conditions.back().parse(parser__.readString());
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         recent_only = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSOItemRecipe::parse(const std::string_view &data__)
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
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         n_a = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         desc_inputs = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         desc_outputs = parser__.readString();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         di_a = parser__.readString();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         di_b = parser__.readString();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         di_c = parser__.readString();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         do_a = parser__.readString();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         do_b = parser__.readString();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         do_c = parser__.readString();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         requires_all_same_class = parser__.readBool();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         requires_all_same_slot = parser__.readBool();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         class_usage_for_output = parser__.readInt32();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot_usage_for_output = parser__.readInt32();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         set_for_output = parser__.readInt32();
         break;
      case 20:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         input_items_criteria.emplace_back();
         input_items_criteria.back().parse(parser__.readString());
         break;
      case 21:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         output_items_criteria.emplace_back();
         output_items_criteria.back().parse(parser__.readString());
         break;
      case 22:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         input_item_dupe_counts.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgApplyStrangePart::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         strange_part_item_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_item_id = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgApplyPennantUpgrade::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         upgrade_item_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         pennant_item_id = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgApplyEggEssence::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         essence_item_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         egg_item_id = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSOEconItemAttribute::parse(const std::string_view &data__)
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
         value = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         value_bytes = parser__.readBytes();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSOEconItemEquipped::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         new_class = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         new_slot = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSOEconItem::parse(const std::string_view &data__)
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
         account_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         inventory = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         def_index = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         quantity = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         level = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         quality = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         flags = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         origin = parser__.readUint32();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         attribute.emplace_back();
         attribute.back().parse(parser__.readString());
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         interior_item = std::make_unique<CSOEconItem>();
         interior_item->parse(parser__.readString());
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         in_use = parser__.readBool();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         style = parser__.readUint32();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         original_id = parser__.readUint64();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         equipped_state.emplace_back();
         equipped_state.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgAdjustItemEquippedState::parse(const std::string_view &data__)
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
         new_class = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         new_slot = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgSortItems::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         sort_type = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSOEconClaimCode::parse(const std::string_view &data__)
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
         code_type = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         time_acquired = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         code = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgStoreGetUserData::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         price_sheet_version = parser__.readFixed32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgStoreGetUserDataResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         currency = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         country = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         price_sheet_version = parser__.readFixed32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         experiment_data = parser__.readUint64();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         featured_item_idx = parser__.readInt32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         show_hat_descriptions = parser__.readBool();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         price_sheet = parser__.readBytes();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         default_item_sort = parser__.readInt32();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         popular_items.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgUpdateItemSchema::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         items_game = parser__.readBytes();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         item_schema_version = parser__.readFixed32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         items_game_url = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCError::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         error_text = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgRequestInventoryRefresh::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgConVarValue::parse(const std::string_view &data__)
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

bool CMsgReplicateConVars::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         convars.emplace_back();
         convars.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgReplayUploadedToYouTube::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         youtube_url = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         youtube_account_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         session_id = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgConsumableExhausted::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_def_id = parser__.readInt32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgItemAcknowledged::parse(const std::string_view &data__)
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
         inventory = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         def_index = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         quality = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         rarity = parser__.readUint32();
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

bool CMsgSetPresetItemPosition::parse(const std::string_view &data__)
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
         preset_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot_id = parser__.readUint32();
         break;
      case 4:
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

bool CMsgSetItemPositions::ItemPosition::parse(const std::string_view &data__)
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
         position = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgSetItemPositions::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         item_positions.emplace_back();
         item_positions.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSOEconItemPresetInstance::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         class_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         preset_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot_id = parser__.readUint32();
         break;
      case 5:
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

bool CMsgSelectItemPresetForClass::parse(const std::string_view &data__)
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
         preset_id = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgSelectItemPresetForClassReply::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         success = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSOSelectedItemPreset::parse(const std::string_view &data__)
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
         class_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         preset_id = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCReportAbuse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         target_steam_id = parser__.readFixed64();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         description = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gid = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         abuse_type = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         content_type = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         target_game_server_ip = parser__.readFixed32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         target_game_server_port = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCReportAbuseResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         target_steam_id = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         error_message = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCNameItemNotification::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         player_steamid = parser__.readFixed64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_def_index = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         item_name_custom = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCClientDisplayNotification::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         notification_title_localization_key = parser__.readString();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         notification_body_localization_key = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         body_substring_keys.push_back(parser__.readString());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         body_substring_values.push_back(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCShowItemsPickedUp::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         player_steamid = parser__.readFixed64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCIncrementKillCountResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         killer_account_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_kills = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_def = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         level_type = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSOEconItemDropRateBonus::parse(const std::string_view &data__)
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
         expiration_date = parser__.readFixed32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         bonus = parser__.readFloat();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         bonus_count = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_id = parser__.readUint64();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         def_index = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         seconds_left = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         booster_type = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSOEconItemLeagueViewPass::parse(const std::string_view &data__)
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
         league_id = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         itemindex = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         grant_reason = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSOEconItemEventTicket::parse(const std::string_view &data__)
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
         event_id = parser__.readUint32();
         break;
      case 3:
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

bool CSOEconItemTournamentPassport::parse(const std::string_view &data__)
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
         league_id = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_id = parser__.readUint64();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         original_purchaser_id = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         passports_bought = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         version = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         def_index = parser__.readUint32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         reward_flags = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCItemPreviewItemBoughtNotification::parse(const std::string_view &data__)
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

bool CMsgGCStorePurchaseCancel::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         txn_id = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCStorePurchaseCancelResponse::parse(const std::string_view &data__)
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

bool CMsgGCStorePurchaseFinalize::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         txn_id = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCStorePurchaseFinalizeResponse::parse(const std::string_view &data__)
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

bool CMsgGCBannedWordListRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         ban_list_group_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         word_id = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCBannedWord::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         word_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         word_type = static_cast<GC_BannedWordType>(parser__.readUint32());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         word = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCBannedWordListResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         ban_list_group_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         word_list.emplace_back();
         word_list.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCBannedWordListBroadcast::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         broadcast.parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCBannedWordListUpdated::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         group_id = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCDirtySDOCache::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         sdo_type = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         key_uint64 = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCDirtyMultipleSDOCache::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         sdo_type = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         key_uint64.push_back(parser__.readUint64());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCApplyLocalizationDiff::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         language = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         packed_diff = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCApplyLocalizationDiffResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         success = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCCollectItem::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         collection_item_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         subject_item_id = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgSDONoMemcached::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgGCToGCUpdateSQLKeyValue::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         key_name = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCBroadcastConsoleCommand::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         con_command = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCServerVersionUpdated::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_version = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCClientVersionUpdated::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CMsgGCToGCWebAPIAccountChanged::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgRecipeComponent::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         subject_item_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         attribute_index = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgFulfillDynamicRecipeComponent::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tool_item_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         consumption_components.emplace_back();
         consumption_components.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCClientMarketDataRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         user_currency = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCClientMarketDataEntry::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_def_index = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_quality = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_sell_listings = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         price_in_local_currency = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCClientMarketData::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CMsgExtractGems::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tool_item_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_item_id = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgAddSocket::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tool_item_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_item_id = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         unusual = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgAddSocketResponse::parse(const std::string_view &data__)
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
         updated_socket_index.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgAddItemToSocketData::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gem_item_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         socket_index = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgAddItemToSocket::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_item_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         gems_to_socket.emplace_back();
         gems_to_socket.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgAddItemToSocketResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_item_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         updated_socket_index.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgResetStrangeGemCount::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_item_id = parser__.readUint64();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         socket_index = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

