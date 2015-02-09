#include "econ_gcmessages.pbsl.h"
#include <pbsl/parser.h>

bool CMsgApplyAutograph::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         autograph_item_id = parser__.readUint64();
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

bool CMsgEconPlayerStrangeCountAdjustment::CStrangeCountAdjustment::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         event_type = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_id = parser__.readUint64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         adjustment = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgEconPlayerStrangeCountAdjustment::parse(const std::string_view &data__)
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
         strange_count_adjustments.emplace_back();
         strange_count_adjustments.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgRequestItemPurgatory_FinalizePurchase::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CMsgRequestItemPurgatory_FinalizePurchaseResponse::parse(const std::string_view &data__)
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

bool CMsgRequestItemPurgatory_RefundPurchase::parse(const std::string_view &data__)
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

bool CMsgRequestItemPurgatory_RefundPurchaseResponse::parse(const std::string_view &data__)
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

bool CMsgCraftingResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CMsgGCRequestStoreSalesData::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         currency = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCRequestStoreSalesDataResponse::Price::parse(const std::string_view &data__)
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
         price = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCRequestStoreSalesDataResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         sale_price.emplace_back();
         sale_price.back().parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         version = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         expiration_time = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCRequestStoreSalesDataUpToDateResponse::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         expiration_time = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCPingRequest::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgGCToGCPingResponse::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgGCToGCGetUserSessionServer::parse(const std::string_view &data__)
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

bool CMsgGCToGCGetUserSessionServerResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         server_steam_id = parser__.readFixed64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCGetUserServerMembers::parse(const std::string_view &data__)
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
         max_spectators = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCGetUserServerMembersResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         member_account_id.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgLookupMultipleAccountNames::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         accountids.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgLookupMultipleAccountNamesResponse::Account::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         persona = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgLookupMultipleAccountNamesResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         accounts.emplace_back();
         accounts.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCGetUserPCBangNo::parse(const std::string_view &data__)
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

bool CMsgGCToGCGetUserPCBangNoResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         pc_bang_no = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgRequestCrateItems::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         crate_item_def = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgRequestCrateItemsResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         crate_item_def = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         item_defs.push_back(parser__.readUint32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCCanUseDropRateBonus::parse(const std::string_view &data__)
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
         drop_rate_bonus = parser__.readFloat();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         booster_type = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         exclusive_item_def = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         allow_equal_rate = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgSQLAddDropRateBonus::parse(const std::string_view &data__)
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
         item_def = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         drop_rate_bonus = parser__.readFloat();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         booster_type = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         seconds_duration = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         end_time_stamp = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgSQLUpgradeBattleBooster::parse(const std::string_view &data__)
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
         item_def = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         bonus_to_add = parser__.readFloat();
         break;
      case 4:
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

bool CMsgGCToGCRefreshSOCache::parse(const std::string_view &data__)
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
         reload = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCCheckAccountTradeStatus::parse(const std::string_view &data__)
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
         initiator = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCCheckAccountTradeStatusResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         can_trade = parser__.readBool();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         error_code = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCGrantAccountRolledItems::Item::DynamicAttribute::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         value_uint32 = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         value_float = parser__.readFloat();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCGrantAccountRolledItems::Item::AdditionalAuditEntry::parse(const std::string_view &data__)
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
         audit_action = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         audit_data = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCGrantAccountRolledItems::Item::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         loot_lists.push_back(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         ignore_limit = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         origin = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         dynamic_attributes.emplace_back();
         dynamic_attributes.back().parse(parser__.readString());
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         additional_audit_entries.emplace_back();
         additional_audit_entries.back().parse(parser__.readString());
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         inventory_token = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCGrantAccountRolledItems::parse(const std::string_view &data__)
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
         items.emplace_back();
         items.back().parse(parser__.readString());
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         audit_action = parser__.readUint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         audit_data = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCToGCGrantSelfMadeItemToAccount::parse(const std::string_view &data__)
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
         accountid = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgUseItem::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         target_steam_id = parser__.readFixed64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         gift__potential_targets.push_back(parser__.readUint32());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         duel__class_lock = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         initiator_steam_id = parser__.readUint64();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         itempack__ack_immediately = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgServerUseItem::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         initiator_account_id = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         use_item_msg.parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCPartnerBalanceRequest::parse(const std::string_view &data__)
{
   return true;
};

bool CMsgGCPartnerBalanceResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<EGCPartnerRequestResponse>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         balance = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgGCPartnerRechargeRedirectURLRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CMsgGCPartnerRechargeRedirectURLResponse::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         result = static_cast<EGCPartnerRequestResponse>(parser__.readUint32());
         break;
      case 2:
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

bool CMsgGCEconSQLWorkItemEmbeddedRollbackData::parse(const std::string_view &data__)
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
         deleted_item_id = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgCraftStatue::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         heroid = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         sequencename = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         cycle = parser__.readFloat();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         description = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         pedestal_itemdef = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         toolid = parser__.readUint64();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgRedeemCode::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
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

bool CMsgRedeemCodeResponse::parse(const std::string_view &data__)
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

bool CMsgDevNewItemRequest::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         item_def_name = parser__.readString();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         loot_list_name = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         attr_def_name.push_back(parser__.readString());
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         attr_value.push_back(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CMsgDevNewItemRequestResponse::parse(const std::string_view &data__)
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

bool CMsgGCAddGiftItem::parse(const std::string_view &data__)
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

