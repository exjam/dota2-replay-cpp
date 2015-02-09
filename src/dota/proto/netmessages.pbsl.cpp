#include "netmessages.pbsl.h"
#include <pbsl/parser.h>

bool CCLCMsg_ClientInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         send_table_crc = parser__.readFixed32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_count = parser__.readUint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_hltv = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_replay = parser__.readBool();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         friends_id = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         friends_name = parser__.readString();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         custom_files.push_back(parser__.readFixed32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CCLCMsg_Move::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_backup_commands = parser__.readUint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_new_commands = parser__.readUint32();
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

bool CCLCMsg_VoiceData::parse(const std::string_view &data__)
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
         xuid = parser__.readFixed64();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         format = static_cast<VoiceDataFormat_t>(parser__.readUint32());
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         sequence_bytes = parser__.readInt32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         section_number = parser__.readUint32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         uncompressed_sample_offset = parser__.readUint32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tick = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CCLCMsg_BaselineAck::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         baseline_tick = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         baseline_nr = parser__.readInt32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CCLCMsg_ListenEvents::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         event_mask.push_back(parser__.readFixed32());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CCLCMsg_RespondCvarValue::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         cookie = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         status_code = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         name = parser__.readString();
         break;
      case 4:
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

bool CCLCMsg_FileCRCCheck::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         code_path = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         path = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         code_filename = parser__.readInt32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         filename = parser__.readString();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         crc = parser__.readFixed32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CCLCMsg_LoadingProgress::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         progress = parser__.readInt32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CCLCMsg_SplitPlayerConnect::parse(const std::string_view &data__)
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

bool CCLCMsg_ClientMessage::parse(const std::string_view &data__)
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

bool CSVCMsg_ServerInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         protocol = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         server_count = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_dedicated = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_hltv = parser__.readBool();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_replay = parser__.readBool();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         c_os = parser__.readInt32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         map_crc = parser__.readFixed32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         client_crc = parser__.readFixed32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         string_table_crc = parser__.readFixed32();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         max_clients = parser__.readInt32();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         max_classes = parser__.readInt32();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_slot = parser__.readInt32();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         tick_interval = parser__.readFloat();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         game_dir = parser__.readString();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         map_name = parser__.readString();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         sky_name = parser__.readString();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         host_name = parser__.readString();
         break;
      case 18:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         addon_name = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_ClassInfo::class_t::parse(const std::string_view &data__)
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
         data_table_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         class_name = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_ClassInfo::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         create_on_client = parser__.readBool();
         break;
      case 2:
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

bool CSVCMsg_SetPause::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         paused = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_VoiceInit::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         quality = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         codec = parser__.readString();
         break;
      case 3:
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

bool CSVCMsg_Print::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         text = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_Sounds::sounddata_t::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         origin_x = parser__.readSint32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         origin_y = parser__.readSint32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         origin_z = parser__.readSint32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         volume = parser__.readUint32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         delay_value = parser__.readFloat();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         sequence_number = parser__.readInt32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         entity_index = parser__.readInt32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         channel = parser__.readInt32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         pitch = parser__.readInt32();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         flags = parser__.readInt32();
         break;
      case 11:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         sound_num = parser__.readUint32();
         break;
      case 12:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         sound_num_handle = parser__.readFixed32();
         break;
      case 13:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         speaker_entity = parser__.readInt32();
         break;
      case 14:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         random_seed = parser__.readInt32();
         break;
      case 15:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         sound_level = parser__.readInt32();
         break;
      case 16:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_sentence = parser__.readBool();
         break;
      case 17:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_ambient = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_Sounds::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         reliable_sound = parser__.readBool();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         sounds.emplace_back();
         sounds.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_Prefetch::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         sound_index = parser__.readInt32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_SetView::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         entity_index = parser__.readInt32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_FixAngle::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         relative = parser__.readBool();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         angle.parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_CrosshairAngle::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         angle.parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_BSPDecal::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         pos.parse(parser__.readString());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         decal_texture_index = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         entity_index = parser__.readInt32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         model_index = parser__.readInt32();
         break;
      case 5:
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

bool CSVCMsg_SplitScreen::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         type = static_cast<ESplitScreenMessageType>(parser__.readUint32());
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         slot = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         player_index = parser__.readInt32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_GetCvarValue::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         cookie = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         cvar_name = parser__.readString();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_Menu::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         dialog_type = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         menu_key_values = parser__.readBytes();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_SendTable::sendprop_t::parse(const std::string_view &data__)
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
         var_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         flags = parser__.readInt32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         priority = parser__.readInt32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         dt_name = parser__.readString();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_elements = parser__.readInt32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         low_value = parser__.readFloat();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::Fixed32);
         high_value = parser__.readFloat();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_bits = parser__.readInt32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_SendTable::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_end = parser__.readBool();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         net_table_name = parser__.readString();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         needs_decoder = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         props.emplace_back();
         props.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_GameEventList::key_t::parse(const std::string_view &data__)
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

bool CSVCMsg_GameEventList::descriptor_t::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         eventid = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         name = parser__.readString();
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

bool CSVCMsg_GameEventList::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         descriptors.emplace_back();
         descriptors.back().parse(parser__.readString());
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_PacketEntities::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         max_entries = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         updated_entries = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         is_delta = parser__.readBool();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         update_baseline = parser__.readBool();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         baseline = parser__.readInt32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         delta_from = parser__.readInt32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         entity_data = parser__.readBytes();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         pending_full_frame = parser__.readBool();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_TempEntities::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         reliable = parser__.readBool();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_entries = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         entity_data = parser__.readBytes();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_CreateStringTable::parse(const std::string_view &data__)
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
         max_entries = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_entries = parser__.readInt32();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         user_data_fixed_size = parser__.readBool();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         user_data_size = parser__.readInt32();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         user_data_size_bits = parser__.readInt32();
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         flags = parser__.readInt32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         string_data = parser__.readBytes();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_UpdateStringTable::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         table_id = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         num_changed_entries = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         string_data = parser__.readBytes();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_VoiceData::parse(const std::string_view &data__)
{
   auto parser__ = pbsl::Parser { data__ };

   while(!parser__.eof()) {
      auto tag__ = parser__.readTag();

      switch(tag__.field) {
      case 1:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         client = parser__.readInt32();
         break;
      case 2:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         proximity = parser__.readBool();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::Fixed64);
         xuid = parser__.readFixed64();
         break;
      case 4:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         audible_mask = parser__.readInt32();
         break;
      case 5:
         assert(tag__.type == pbsl::Parser::WireType::LengthDelimited);
         voice_data = parser__.readBytes();
         break;
      case 6:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         format = static_cast<VoiceDataFormat_t>(parser__.readUint32());
         break;
      case 7:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         sequence_bytes = parser__.readInt32();
         break;
      case 8:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         section_number = parser__.readUint32();
         break;
      case 9:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         uncompressed_sample_offset = parser__.readUint32();
         break;
      case 10:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         tick = parser__.readUint32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_PacketReliable::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         messagessize = parser__.readInt32();
         break;
      default:
         if (!parser__.eof()) {
            assert(0 && "Invalid field number!");
         }
         return false;
      }
   }

   return true;
};

bool CSVCMsg_FullFrameSplit::parse(const std::string_view &data__)
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
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         section = parser__.readInt32();
         break;
      case 3:
         assert(tag__.type == pbsl::Parser::WireType::VarInt);
         total = parser__.readInt32();
         break;
      case 4:
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

