#include "account_all_hero_challenge_changed.h"
#include "account_trophies_changed.h"
#include "achievement_earned.h"
#include "achievement_event.h"
#include "achievement_write_failed.h"
#include "antiaddiction_toast.h"
#include "antiaddiction_update.h"
#include "bindpanel_close.h"
#include "bindpanel_open.h"
#include "bonus_updated.h"
#include "booster_state_updated.h"
#include "break_breakable.h"
#include "break_prop.h"
#include "cart_updated.h"
#include "chat_members_changed.h"
#include "chat_new_message.h"
#include "community_cached_names_updated.h"
#include "compendium_event_actions_loaded.h"
#include "compendium_selections_loaded.h"
#include "compendium_set_selection_failed.h"
#include "custom_game_difficulty.h"
#include "dashboard_caches_cleared.h"
#include "dashboard_switched_section.h"
#include "defeated.h"
#include "demo_stop.h"
#include "difficulty_changed.h"
#include "dota_ability_changed.h"
#include "dota_ability_channel_finished.h"
#include "dota_action_item.h"
#include "dota_action_success.h"
#include "dota_barracks_kill.h"
#include "dota_chase_hero.h"
#include "dota_chat_assassin_announce.h"
#include "dota_chat_assassin_denied.h"
#include "dota_chat_assassin_success.h"
#include "dota_chat_ban_notification.h"
#include "dota_chat_event.h"
#include "dota_chat_first_blood.h"
#include "dota_chat_informational.h"
#include "dota_chat_kill_streak.h"
#include "dota_chat_timed_reward.h"
#include "dota_combatlog.h"
#include "dota_courier_lost.h"
#include "dota_courier_respawned.h"
#include "dota_courier_transfer_item.h"
#include "dota_effigy_kill.h"
#include "dota_enemy_money_changed.h"
#include "dota_favorite_heroes_updated.h"
#include "dota_force_portrait_update.h"
#include "dota_game_state_change.h"
#include "dota_glyph_used.h"
#include "dota_hero_random.h"
#include "dota_hero_swap.h"
#include "dota_holdout_revive_complete.h"
#include "dota_hud_error_message.h"
#include "dota_hud_skin_changed.h"
#include "dota_inventory_changed.h"
#include "dota_inventory_changed_query_unit.h"
#include "dota_inventory_item_added.h"
#include "dota_inventory_item_changed.h"
#include "dota_inventory_player_got_item.h"
#include "dota_item_auto_purchase.h"
#include "dota_item_drag_begin.h"
#include "dota_item_drag_end.h"
#include "dota_item_gifted.h"
#include "dota_item_picked_up.h"
#include "dota_item_purchase.h"
#include "dota_item_purchased.h"
#include "dota_item_spotted.h"
#include "dota_item_used.h"
#include "dota_link_clicked.h"
#include "dota_local_quickbuy_changed.h"
#include "dota_match_done.h"
#include "dota_match_done_client.h"
#include "dota_match_signout.h"
#include "dota_money_changed.h"
#include "dota_no_battle_points.h"
#include "dota_non_player_used_ability.h"
#include "dota_pause_event.h"
#include "dota_player_deny.h"
#include "dota_player_gained_level.h"
#include "dota_player_kill.h"
#include "dota_player_killed.h"
#include "dota_player_learned_ability.h"
#include "dota_player_pick_hero.h"
#include "dota_player_shop_changed.h"
#include "dota_player_show_killcam.h"
#include "dota_player_show_minikillcam.h"
#include "dota_player_take_tower_damage.h"
#include "dota_player_update_hero_selection.h"
#include "dota_player_update_killcam_unit.h"
#include "dota_player_update_query_unit.h"
#include "dota_player_update_selected_unit.h"
#include "dota_player_used_ability.h"
#include "dota_portrait_ability_layout_changed.h"
#include "dota_portrait_unit_modifiers_changed.h"
#include "dota_portrait_unit_stats_changed.h"
#include "dota_quest_completed.h"
#include "dota_quest_started.h"
#include "dota_quick_buy_changed.h"
#include "dota_rd_chat_turn.h"
#include "dota_reset_suggested_items.h"
#include "dota_roshan_kill.h"
#include "dota_rubick_ability_steal.h"
#include "dota_rune_activated_server.h"
#include "dota_rune_pickup.h"
#include "dota_rune_spotted.h"
#include "dota_set_quick_buy.h"
#include "dota_shop_item_drag_begin.h"
#include "dota_shop_item_drag_end.h"
#include "dota_spectate_hero.h"
#include "dota_starting_position_changed.h"
#include "dota_super_creeps.h"
#include "dota_tournament_item_event.h"
#include "dota_tower_kill.h"
#include "dota_tutorial_lesson_start.h"
#include "dota_unit_event.h"
#include "dota_workshop_filecanceled.h"
#include "dota_workshop_fileselected.h"
#include "drop_rate_modified.h"
#include "entity_hurt.h"
#include "entity_killed.h"
#include "event_points_updated.h"
#include "event_ticket_modified.h"
#include "fantasy_league_changed.h"
#include "fantasy_score_info_changed.h"
#include "fantasy_updated.h"
#include "file_downloaded.h"
#include "finale_start.h"
#include "flare_ignite_npc.h"
#include "frosty_points_updated.h"
#include "full_ui_unlocked.h"
#include "game_end.h"
#include "game_end_visible.h"
#include "game_init.h"
#include "game_message.h"
#include "game_newmap.h"
#include "game_rules_state_change.h"
#include "game_start.h"
#include "gameinstructor_draw.h"
#include "gameinstructor_nodraw.h"
#include "gameui_activated.h"
#include "gameui_hidden.h"
#include "gc_chat_channel_list_updated.h"
#include "gc_connected.h"
#include "gc_mismatched_version.h"
#include "gc_user_session_created.h"
#include "guild_data_updated.h"
#include "guild_open_parties_updated.h"
#include "halloween_high_score_received.h"
#include "halloween_high_score_request_failed.h"
#include "halloween_phase_end.h"
#include "helicopter_grenade_punt_miss.h"
#include "hero_picker_hidden.h"
#include "hero_picker_shown.h"
#include "hero_selector_preview_set.h"
#include "hide_highlight_hud_element.h"
#include "highlight_hud_element.h"
#include "hltv_cameraman.h"
#include "hltv_chase.h"
#include "hltv_chat.h"
#include "hltv_fixed.h"
#include "hltv_message.h"
#include "hltv_rank_camera.h"
#include "hltv_rank_entity.h"
#include "hltv_status.h"
#include "hltv_title.h"
#include "hltv_versioninfo.h"
#include "hostname_changed.h"
#include "hud_flip_changed.h"
#include "ingame_events_changed.h"
#include "instructor_server_hint_create.h"
#include "instructor_server_hint_stop.h"
#include "intro_video_finished.h"
#include "inventory_updated.h"
#include "item_preview_closed.h"
#include "item_purchased.h"
#include "item_schema_initialized.h"
#include "joined_chat_channel.h"
#include "keybind_changed.h"
#include "last_hit.h"
#include "left_chat_channel.h"
#include "live_games_updated.h"
#include "lobby_updated.h"
#include "local_player_event_points.h"
#include "map_location_updated.h"
#include "map_shutdown.h"
#include "map_transition.h"
#include "match_details_updated.h"
#include "match_history_updated.h"
#include "matchmaking_status_visibility_changed.h"
#include "microtransaction_success.h"
#include "modifier_event.h"
#include "news_updated.h"
#include "nommed_tree.h"
#include "npc_replaced.h"
#include "npc_spawned.h"
#include "party_updated.h"
#include "persona_updated.h"
#include "physgun_pickup.h"
#include "player_activate.h"
#include "player_changename.h"
#include "player_chat.h"
#include "player_class.h"
#include "player_completed_game.h"
#include "player_connect.h"
#include "player_connect_full.h"
#include "player_death.h"
#include "player_disconnect.h"
#include "player_full_update.h"
#include "player_fullyjoined.h"
#include "player_hintmessage.h"
#include "player_hurt.h"
#include "player_info.h"
#include "player_info_updated.h"
#include "player_is_experienced.h"
#include "player_is_notexperienced.h"
#include "player_reconnected.h"
#include "player_report_counts_updated.h"
#include "player_say.h"
#include "player_score.h"
#include "player_shoot.h"
#include "player_spawn.h"
#include "player_stats_updated.h"
#include "player_team.h"
#include "player_use.h"
#include "practice_lobby_visibility_changed.h"
#include "prizepool_received.h"
#include "profile_closed.h"
#include "profile_opened.h"
#include "ragdoll_dissolved.h"
#include "recent_matches_updated.h"
#include "reset_defeated.h"
#include "rich_presence_updated.h"
#include "richpresence_custom_updated.h"
#include "round_end.h"
#include "round_start.h"
#include "round_start_pre_entity.h"
#include "scaleform_file_download_complete.h"
#include "server_addban.h"
#include "server_cvar.h"
#include "server_message.h"
#include "server_pre_shutdown.h"
#include "server_removeban.h"
#include "server_shutdown.h"
#include "server_spawn.h"
#include "set_instructor_group_enabled.h"
#include "show_center_message.h"
#include "spec_aegis_reclaim_time.h"
#include "spec_item_pickup.h"
#include "store_pricesheet_updated.h"
#include "team_data_updated.h"
#include "team_info.h"
#include "team_score.h"
#include "team_showcase_ui_update.h"
#include "teamplay_broadcast_audio.h"
#include "teamplay_round_start.h"
#include "today_messages_updated.h"
#include "tournament_state_updated.h"
#include "tree_cut.h"
#include "ugc_details_arrived.h"
#include "ugc_subscribed.h"
#include "ugc_unsubscribed.h"
#include "user_data_downloaded.h"

namespace dota
{

BeginGameEvent(account_all_hero_challenge_changed);
   GameEventProperty(account_id);
EndGameEvent();

BeginGameEvent(account_trophies_changed);
   GameEventProperty(account_id);
EndGameEvent();

BeginGameEvent(achievement_earned);
   GameEventProperty(player);
   GameEventProperty(achievement);
EndGameEvent();

BeginGameEvent(achievement_event);
   GameEventProperty(achievement_name);
   GameEventProperty(cur_val);
   GameEventProperty(max_val);
EndGameEvent();

BeginGameEvent(achievement_write_failed);
EndGameEvent();

BeginGameEvent(antiaddiction_toast);
   GameEventProperty(message);
   GameEventProperty(duration);
EndGameEvent();

BeginGameEvent(antiaddiction_update);
EndGameEvent();

BeginGameEvent(bindpanel_close);
EndGameEvent();

BeginGameEvent(bindpanel_open);
EndGameEvent();

BeginGameEvent(bonus_updated);
   GameEventProperty(numadvanced);
   GameEventProperty(numbronze);
   GameEventProperty(numsilver);
   GameEventProperty(numgold);
EndGameEvent();

BeginGameEvent(booster_state_updated);
EndGameEvent();

BeginGameEvent(break_breakable);
   GameEventProperty(entindex);
   GameEventProperty(userid);
   GameEventProperty(material);
EndGameEvent();

BeginGameEvent(break_prop);
   GameEventProperty(entindex);
   GameEventProperty(userid);
EndGameEvent();

BeginGameEvent(cart_updated);
EndGameEvent();

BeginGameEvent(chat_members_changed);
   GameEventProperty(channel);
EndGameEvent();

BeginGameEvent(chat_new_message);
   GameEventProperty(channel);
EndGameEvent();

BeginGameEvent(community_cached_names_updated);
EndGameEvent();

BeginGameEvent(compendium_event_actions_loaded);
   GameEventProperty(account_id);
   GameEventProperty(league_id);
   GameEventProperty(local_test);
   GameEventProperty(original_points);
EndGameEvent();

BeginGameEvent(compendium_selections_loaded);
   GameEventProperty(account_id);
   GameEventProperty(league_id);
   GameEventProperty(local_test);
EndGameEvent();

BeginGameEvent(compendium_set_selection_failed);
   GameEventProperty(account_id);
   GameEventProperty(league_id);
   GameEventProperty(local_test);
EndGameEvent();

BeginGameEvent(custom_game_difficulty);
   GameEventProperty(difficulty);
EndGameEvent();

BeginGameEvent(dashboard_caches_cleared);
EndGameEvent();

BeginGameEvent(dashboard_switched_section);
   GameEventProperty(section);
EndGameEvent();

BeginGameEvent(defeated);
   GameEventProperty(entindex);
EndGameEvent();

BeginGameEvent(demo_stop);
EndGameEvent();

BeginGameEvent(difficulty_changed);
   GameEventProperty(newDifficulty);
   GameEventProperty(oldDifficulty);
   GameEventProperty(strDifficulty);
EndGameEvent();

BeginGameEvent(dota_ability_changed);
EndGameEvent();

BeginGameEvent(dota_ability_channel_finished);
   GameEventProperty(abilityname);
   GameEventProperty(interrupted);
EndGameEvent();

BeginGameEvent(dota_action_item);
   GameEventProperty(reason);
   GameEventProperty(itemdef);
   GameEventProperty(message);
EndGameEvent();

BeginGameEvent(dota_action_success);
EndGameEvent();

BeginGameEvent(dota_barracks_kill);
   GameEventProperty(barracks_id);
EndGameEvent();

BeginGameEvent(dota_chase_hero);
   GameEventProperty(target1);
   GameEventProperty(target2);
   GameEventProperty(type);
   GameEventProperty(priority);
   GameEventProperty(gametime);
   GameEventProperty(highlight);
   GameEventProperty(target1playerid);
   GameEventProperty(target2playerid);
   GameEventProperty(eventtype);
EndGameEvent();

BeginGameEvent(dota_chat_assassin_announce);
   GameEventProperty(assassin_id);
   GameEventProperty(target_id);
   GameEventProperty(message);
EndGameEvent();

BeginGameEvent(dota_chat_assassin_denied);
   GameEventProperty(assassin_id);
   GameEventProperty(target_id);
   GameEventProperty(message);
EndGameEvent();

BeginGameEvent(dota_chat_assassin_success);
   GameEventProperty(assassin_id);
   GameEventProperty(target_id);
   GameEventProperty(message);
EndGameEvent();

BeginGameEvent(dota_chat_ban_notification);
   GameEventProperty(userid);
EndGameEvent();

BeginGameEvent(dota_chat_event);
   GameEventProperty(userid);
   GameEventProperty(gold);
   GameEventProperty(message);
EndGameEvent();

BeginGameEvent(dota_chat_first_blood);
   GameEventProperty(gold);
   GameEventProperty(killer_id);
   GameEventProperty(victim_id);
EndGameEvent();

BeginGameEvent(dota_chat_informational);
   GameEventProperty(userid);
   GameEventProperty(type);
EndGameEvent();

BeginGameEvent(dota_chat_kill_streak);
   GameEventProperty(gold);
   GameEventProperty(killer_id);
   GameEventProperty(killer_streak);
   GameEventProperty(killer_multikill);
   GameEventProperty(victim_id);
   GameEventProperty(victim_streak);
EndGameEvent();

BeginGameEvent(dota_chat_timed_reward);
   GameEventProperty(userid);
   GameEventProperty(itmedef);
   GameEventProperty(message);
EndGameEvent();

BeginGameEvent(dota_combatlog);
   GameEventProperty(type);
   GameEventProperty(sourcename);
   GameEventProperty(targetname);
   GameEventProperty(attackername);
   GameEventProperty(inflictorname);
   GameEventProperty(attackerillusion);
   GameEventProperty(targetillusion);
   GameEventProperty(value);
   GameEventProperty(health);
   GameEventProperty(timestamp);
   GameEventProperty(targetsourcename);
   GameEventProperty(timestampraw);
   GameEventProperty(attackerhero);
   GameEventProperty(targethero);
   GameEventProperty(ability_toggle_on);
   GameEventProperty(ability_toggle_off);
   GameEventProperty(ability_level);
   GameEventProperty(gold_reason);
   GameEventProperty(xp_reason);
EndGameEvent();

BeginGameEvent(dota_courier_lost);
   GameEventProperty(teamnumber);
EndGameEvent();

BeginGameEvent(dota_courier_respawned);
   GameEventProperty(teamnumber);
EndGameEvent();

BeginGameEvent(dota_courier_transfer_item);
EndGameEvent();

BeginGameEvent(dota_effigy_kill);
   GameEventProperty(owner_userid);
EndGameEvent();

BeginGameEvent(dota_enemy_money_changed);
EndGameEvent();

BeginGameEvent(dota_favorite_heroes_updated);
EndGameEvent();

BeginGameEvent(dota_force_portrait_update);
EndGameEvent();

BeginGameEvent(dota_game_state_change);
   GameEventProperty(old_state);
   GameEventProperty(new_state);
EndGameEvent();

BeginGameEvent(dota_glyph_used);
   GameEventProperty(teamnumber);
EndGameEvent();

BeginGameEvent(dota_hero_random);
   GameEventProperty(userid);
   GameEventProperty(heroid);
EndGameEvent();

BeginGameEvent(dota_hero_swap);
   GameEventProperty(playerid1);
   GameEventProperty(playerid2);
EndGameEvent();

BeginGameEvent(dota_holdout_revive_complete);
   GameEventProperty(caster);
   GameEventProperty(target);
EndGameEvent();

BeginGameEvent(dota_hud_error_message);
   GameEventProperty(reason);
   GameEventProperty(message);
EndGameEvent();

BeginGameEvent(dota_hud_skin_changed);
   GameEventProperty(skin);
   GameEventProperty(style);
EndGameEvent();

BeginGameEvent(dota_inventory_changed);
EndGameEvent();

BeginGameEvent(dota_inventory_changed_query_unit);
EndGameEvent();

BeginGameEvent(dota_inventory_item_added);
   GameEventProperty(itemname);
EndGameEvent();

BeginGameEvent(dota_inventory_item_changed);
   GameEventProperty(entityIndex);
EndGameEvent();

BeginGameEvent(dota_inventory_player_got_item);
   GameEventProperty(itemname);
EndGameEvent();

BeginGameEvent(dota_item_auto_purchase);
   GameEventProperty(item_id);
EndGameEvent();

BeginGameEvent(dota_item_drag_begin);
EndGameEvent();

BeginGameEvent(dota_item_drag_end);
EndGameEvent();

BeginGameEvent(dota_item_gifted);
   GameEventProperty(userid);
   GameEventProperty(itemid);
   GameEventProperty(sourceid);
EndGameEvent();

BeginGameEvent(dota_item_picked_up);
   GameEventProperty(itemname);
   GameEventProperty(PlayerID);
   GameEventProperty(ItemEntityIndex);
   GameEventProperty(HeroEntityIndex);
EndGameEvent();

BeginGameEvent(dota_item_purchase);
   GameEventProperty(userid);
   GameEventProperty(itemid);
EndGameEvent();

BeginGameEvent(dota_item_purchased);
   GameEventProperty(PlayerID);
   GameEventProperty(itemname);
   GameEventProperty(itemcost);
EndGameEvent();

BeginGameEvent(dota_item_spotted);
   GameEventProperty(userid);
   GameEventProperty(itemid);
EndGameEvent();

BeginGameEvent(dota_item_used);
   GameEventProperty(PlayerID);
   GameEventProperty(itemname);
EndGameEvent();

BeginGameEvent(dota_link_clicked);
   GameEventProperty(link);
   GameEventProperty(nav);
   GameEventProperty(nav_back);
   GameEventProperty(recipe);
   GameEventProperty(shop);
EndGameEvent();

BeginGameEvent(dota_local_quickbuy_changed);
EndGameEvent();

BeginGameEvent(dota_match_done);
   GameEventProperty(winningteam);
EndGameEvent();

BeginGameEvent(dota_match_done_client);
EndGameEvent();

BeginGameEvent(dota_match_signout);
EndGameEvent();

BeginGameEvent(dota_money_changed);
EndGameEvent();

BeginGameEvent(dota_no_battle_points);
   GameEventProperty(userid);
   GameEventProperty(reason);
EndGameEvent();

BeginGameEvent(dota_non_player_used_ability);
   GameEventProperty(abilityname);
EndGameEvent();

BeginGameEvent(dota_pause_event);
   GameEventProperty(userid);
   GameEventProperty(value);
   GameEventProperty(message);
EndGameEvent();

BeginGameEvent(dota_player_deny);
   GameEventProperty(killer_userid);
   GameEventProperty(victim_userid);
EndGameEvent();

BeginGameEvent(dota_player_gained_level);
   GameEventProperty(PlayerID);
   GameEventProperty(level);
EndGameEvent();

BeginGameEvent(dota_player_kill);
   GameEventProperty(victim_userid);
   GameEventProperty(killer1_userid);
   GameEventProperty(killer2_userid);
   GameEventProperty(killer3_userid);
   GameEventProperty(killer4_userid);
   GameEventProperty(killer5_userid);
   GameEventProperty(bounty);
   GameEventProperty(neutral);
   GameEventProperty(greevil);
EndGameEvent();

BeginGameEvent(dota_player_killed);
   GameEventProperty(PlayerID);
   GameEventProperty(HeroKill);
   GameEventProperty(TowerKill);
EndGameEvent();

BeginGameEvent(dota_player_learned_ability);
   GameEventProperty(PlayerID);
   GameEventProperty(abilityname);
EndGameEvent();

BeginGameEvent(dota_player_pick_hero);
   GameEventProperty(player);
   GameEventProperty(heroindex);
   GameEventProperty(hero);
EndGameEvent();

BeginGameEvent(dota_player_shop_changed);
   GameEventProperty(prevshopmask);
   GameEventProperty(shopmask);
EndGameEvent();

BeginGameEvent(dota_player_show_killcam);
   GameEventProperty(nodes);
   GameEventProperty(player);
EndGameEvent();

BeginGameEvent(dota_player_show_minikillcam);
   GameEventProperty(nodes);
   GameEventProperty(player);
EndGameEvent();

BeginGameEvent(dota_player_take_tower_damage);
   GameEventProperty(PlayerID);
   GameEventProperty(damage);
EndGameEvent();

BeginGameEvent(dota_player_update_hero_selection);
   GameEventProperty(tabcycle);
EndGameEvent();

BeginGameEvent(dota_player_update_killcam_unit);
EndGameEvent();

BeginGameEvent(dota_player_update_query_unit);
EndGameEvent();

BeginGameEvent(dota_player_update_selected_unit);
EndGameEvent();

BeginGameEvent(dota_player_used_ability);
   GameEventProperty(PlayerID);
   GameEventProperty(abilityname);
EndGameEvent();

BeginGameEvent(dota_portrait_ability_layout_changed);
EndGameEvent();

BeginGameEvent(dota_portrait_unit_modifiers_changed);
EndGameEvent();

BeginGameEvent(dota_portrait_unit_stats_changed);
EndGameEvent();

BeginGameEvent(dota_quest_completed);
   GameEventProperty(questIndex);
EndGameEvent();

BeginGameEvent(dota_quest_started);
   GameEventProperty(questIndex);
EndGameEvent();

BeginGameEvent(dota_quick_buy_changed);
   GameEventProperty(item);
   GameEventProperty(recipe);
EndGameEvent();

BeginGameEvent(dota_rd_chat_turn);
   GameEventProperty(userid);
EndGameEvent();

BeginGameEvent(dota_reset_suggested_items);
EndGameEvent();

BeginGameEvent(dota_roshan_kill);
   GameEventProperty(teamnumber);
   GameEventProperty(gold);
EndGameEvent();

BeginGameEvent(dota_rubick_ability_steal);
   GameEventProperty(abilityIndex);
   GameEventProperty(abilityLevel);
EndGameEvent();

BeginGameEvent(dota_rune_activated_server);
   GameEventProperty(PlayerID);
   GameEventProperty(rune);
EndGameEvent();

BeginGameEvent(dota_rune_pickup);
   GameEventProperty(userid);
   GameEventProperty(type);
   GameEventProperty(rune);
EndGameEvent();

BeginGameEvent(dota_rune_spotted);
   GameEventProperty(userid);
   GameEventProperty(rune);
EndGameEvent();

BeginGameEvent(dota_set_quick_buy);
   GameEventProperty(item);
   GameEventProperty(recipe);
   GameEventProperty(toggle);
EndGameEvent();

BeginGameEvent(dota_shop_item_drag_begin);
EndGameEvent();

BeginGameEvent(dota_shop_item_drag_end);
EndGameEvent();

BeginGameEvent(dota_spectate_hero);
   GameEventProperty(entindex);
EndGameEvent();

BeginGameEvent(dota_starting_position_changed);
EndGameEvent();

BeginGameEvent(dota_super_creeps);
   GameEventProperty(teamnumber);
EndGameEvent();

BeginGameEvent(dota_tournament_item_event);
   GameEventProperty(winner_count);
   GameEventProperty(event_type);
EndGameEvent();

BeginGameEvent(dota_tower_kill);
   GameEventProperty(killer_userid);
   GameEventProperty(teamnumber);
   GameEventProperty(gold);
EndGameEvent();

BeginGameEvent(dota_tutorial_lesson_start);
EndGameEvent();

BeginGameEvent(dota_unit_event);
   GameEventProperty(victim);
   GameEventProperty(attacker);
   GameEventProperty(basepriority);
   GameEventProperty(priority);
   GameEventProperty(eventtype);
EndGameEvent();

BeginGameEvent(dota_workshop_filecanceled);
EndGameEvent();

BeginGameEvent(dota_workshop_fileselected);
   GameEventProperty(filename);
EndGameEvent();

BeginGameEvent(drop_rate_modified);
EndGameEvent();

BeginGameEvent(entity_hurt);
   GameEventProperty(entindex_killed);
   GameEventProperty(entindex_attacker);
   GameEventProperty(entindex_inflictor);
   GameEventProperty(damagebits);
EndGameEvent();

BeginGameEvent(entity_killed);
   GameEventProperty(entindex_killed);
   GameEventProperty(entindex_attacker);
   GameEventProperty(entindex_inflictor);
   GameEventProperty(damagebits);
EndGameEvent();

BeginGameEvent(event_points_updated);
   GameEventProperty(event_id);
   GameEventProperty(points);
   GameEventProperty(premium_points);
EndGameEvent();

BeginGameEvent(event_ticket_modified);
EndGameEvent();

BeginGameEvent(fantasy_league_changed);
EndGameEvent();

BeginGameEvent(fantasy_score_info_changed);
EndGameEvent();

BeginGameEvent(fantasy_updated);
EndGameEvent();

BeginGameEvent(file_downloaded);
   GameEventProperty(success);
   GameEventProperty(local_filename);
   GameEventProperty(remote_url);
EndGameEvent();

BeginGameEvent(finale_start);
   GameEventProperty(rushes);
EndGameEvent();

BeginGameEvent(flare_ignite_npc);
   GameEventProperty(entindex);
EndGameEvent();

BeginGameEvent(frosty_points_updated);
EndGameEvent();

BeginGameEvent(full_ui_unlocked);
EndGameEvent();

BeginGameEvent(game_end);
   GameEventProperty(winner);
EndGameEvent();

BeginGameEvent(game_end_visible);
EndGameEvent();

BeginGameEvent(game_init);
EndGameEvent();

BeginGameEvent(game_message);
   GameEventProperty(target);
   GameEventProperty(text);
EndGameEvent();

BeginGameEvent(game_newmap);
   GameEventProperty(mapname);
EndGameEvent();

BeginGameEvent(game_rules_state_change);
EndGameEvent();

BeginGameEvent(game_start);
   GameEventProperty(roundslimit);
   GameEventProperty(timelimit);
   GameEventProperty(fraglimit);
   GameEventProperty(objective);
EndGameEvent();

BeginGameEvent(gameinstructor_draw);
EndGameEvent();

BeginGameEvent(gameinstructor_nodraw);
EndGameEvent();

BeginGameEvent(gameui_activated);
EndGameEvent();

BeginGameEvent(gameui_hidden);
EndGameEvent();

BeginGameEvent(gc_chat_channel_list_updated);
EndGameEvent();

BeginGameEvent(gc_connected);
EndGameEvent();

BeginGameEvent(gc_mismatched_version);
EndGameEvent();

BeginGameEvent(gc_user_session_created);
EndGameEvent();

BeginGameEvent(guild_data_updated);
EndGameEvent();

BeginGameEvent(guild_open_parties_updated);
EndGameEvent();

BeginGameEvent(halloween_high_score_received);
   GameEventProperty(round);
EndGameEvent();

BeginGameEvent(halloween_high_score_request_failed);
   GameEventProperty(round);
EndGameEvent();

BeginGameEvent(halloween_phase_end);
   GameEventProperty(phase);
   GameEventProperty(team);
EndGameEvent();

BeginGameEvent(helicopter_grenade_punt_miss);
EndGameEvent();

BeginGameEvent(hero_picker_hidden);
EndGameEvent();

BeginGameEvent(hero_picker_shown);
EndGameEvent();

BeginGameEvent(hero_selector_preview_set);
   GameEventProperty(setindex);
EndGameEvent();

BeginGameEvent(hide_highlight_hud_element);
EndGameEvent();

BeginGameEvent(highlight_hud_element);
   GameEventProperty(elementname);
   GameEventProperty(duration);
EndGameEvent();

BeginGameEvent(hltv_cameraman);
   GameEventProperty(index);
EndGameEvent();

BeginGameEvent(hltv_chase);
   GameEventProperty(target1);
   GameEventProperty(target2);
   GameEventProperty(distance);
   GameEventProperty(theta);
   GameEventProperty(phi);
   GameEventProperty(inertia);
   GameEventProperty(ineye);
EndGameEvent();

BeginGameEvent(hltv_chat);
   GameEventProperty(name);
   GameEventProperty(text);
   GameEventProperty(steamID);
EndGameEvent();

BeginGameEvent(hltv_fixed);
   GameEventProperty(posx);
   GameEventProperty(posy);
   GameEventProperty(posz);
   GameEventProperty(theta);
   GameEventProperty(phi);
   GameEventProperty(offset);
   GameEventProperty(fov);
   GameEventProperty(target);
EndGameEvent();

BeginGameEvent(hltv_message);
   GameEventProperty(text);
EndGameEvent();

BeginGameEvent(hltv_rank_camera);
   GameEventProperty(index);
   GameEventProperty(rank);
   GameEventProperty(target);
EndGameEvent();

BeginGameEvent(hltv_rank_entity);
   GameEventProperty(index);
   GameEventProperty(rank);
   GameEventProperty(target);
EndGameEvent();

BeginGameEvent(hltv_status);
   GameEventProperty(clients);
   GameEventProperty(slots);
   GameEventProperty(proxies);
   GameEventProperty(master);
EndGameEvent();

BeginGameEvent(hltv_title);
   GameEventProperty(text);
EndGameEvent();

BeginGameEvent(hltv_versioninfo);
   GameEventProperty(version);
EndGameEvent();

BeginGameEvent(hostname_changed);
   GameEventProperty(hostname);
EndGameEvent();

BeginGameEvent(hud_flip_changed);
   GameEventProperty(flipped);
EndGameEvent();

BeginGameEvent(ingame_events_changed);
EndGameEvent();

BeginGameEvent(instructor_server_hint_create);
   GameEventProperty(hint_name);
   GameEventProperty(hint_replace_key);
   GameEventProperty(hint_target);
   GameEventProperty(hint_activator_userid);
   GameEventProperty(hint_timeout);
   GameEventProperty(hint_icon_onscreen);
   GameEventProperty(hint_icon_offscreen);
   GameEventProperty(hint_caption);
   GameEventProperty(hint_activator_caption);
   GameEventProperty(hint_color);
   GameEventProperty(hint_icon_offset);
   GameEventProperty(hint_range);
   GameEventProperty(hint_flags);
   GameEventProperty(hint_binding);
   GameEventProperty(hint_allow_nodraw_target);
   GameEventProperty(hint_nooffscreen);
   GameEventProperty(hint_forcecaption);
   GameEventProperty(hint_local_player_only);
EndGameEvent();

BeginGameEvent(instructor_server_hint_stop);
   GameEventProperty(hint_name);
EndGameEvent();

BeginGameEvent(intro_video_finished);
EndGameEvent();

BeginGameEvent(inventory_updated);
   GameEventProperty(itemdef);
   GameEventProperty(itemid);
EndGameEvent();

BeginGameEvent(item_preview_closed);
EndGameEvent();

BeginGameEvent(item_purchased);
   GameEventProperty(itemid);
EndGameEvent();

BeginGameEvent(item_schema_initialized);
EndGameEvent();

BeginGameEvent(joined_chat_channel);
   GameEventProperty(channelName);
EndGameEvent();

BeginGameEvent(keybind_changed);
EndGameEvent();

BeginGameEvent(last_hit);
   GameEventProperty(PlayerID);
   GameEventProperty(EntKilled);
   GameEventProperty(FirstBlood);
   GameEventProperty(HeroKill);
   GameEventProperty(TowerKill);
EndGameEvent();

BeginGameEvent(left_chat_channel);
   GameEventProperty(channelName);
EndGameEvent();

BeginGameEvent(live_games_updated);
EndGameEvent();

BeginGameEvent(lobby_updated);
EndGameEvent();

BeginGameEvent(local_player_event_points);
   GameEventProperty(points);
   GameEventProperty(conversion_rate);
EndGameEvent();

BeginGameEvent(map_location_updated);
EndGameEvent();

BeginGameEvent(map_shutdown);
EndGameEvent();

BeginGameEvent(map_transition);
EndGameEvent();

BeginGameEvent(match_details_updated);
   GameEventProperty(matchID);
   GameEventProperty(result);
EndGameEvent();

BeginGameEvent(match_history_updated);
   GameEventProperty(SteamID);
EndGameEvent();

BeginGameEvent(matchmaking_status_visibility_changed);
EndGameEvent();

BeginGameEvent(microtransaction_success);
   GameEventProperty(txnid);
EndGameEvent();

BeginGameEvent(modifier_event);
   GameEventProperty(eventname);
   GameEventProperty(caster);
   GameEventProperty(ability);
EndGameEvent();

BeginGameEvent(news_updated);
EndGameEvent();

BeginGameEvent(nommed_tree);
   GameEventProperty(PlayerID);
EndGameEvent();

BeginGameEvent(npc_replaced);
   GameEventProperty(old_entindex);
   GameEventProperty(new_entindex);
EndGameEvent();

BeginGameEvent(npc_spawned);
   GameEventProperty(entindex);
EndGameEvent();

BeginGameEvent(party_updated);
EndGameEvent();

BeginGameEvent(persona_updated);
   GameEventProperty(SteamID);
EndGameEvent();

BeginGameEvent(physgun_pickup);
   GameEventProperty(entindex);
EndGameEvent();

BeginGameEvent(player_activate);
   GameEventProperty(userid);
EndGameEvent();

BeginGameEvent(player_changename);
   GameEventProperty(userid);
   GameEventProperty(oldname);
   GameEventProperty(newname);
EndGameEvent();

BeginGameEvent(player_chat);
   GameEventProperty(teamonly);
   GameEventProperty(userid);
   GameEventProperty(text);
EndGameEvent();

BeginGameEvent(player_class);
   GameEventProperty(userid);
   GameEventProperty(class_);
EndGameEvent();

BeginGameEvent(player_completed_game);
   GameEventProperty(PlayerID);
   GameEventProperty(Winner);
EndGameEvent();

BeginGameEvent(player_connect);
   GameEventProperty(name);
   GameEventProperty(index);
   GameEventProperty(userid);
   GameEventProperty(networkid);
   GameEventProperty(address);
EndGameEvent();

BeginGameEvent(player_connect_full);
   GameEventProperty(userid);
   GameEventProperty(index);
EndGameEvent();

BeginGameEvent(player_death);
   GameEventProperty(userid);
   GameEventProperty(attacker);
EndGameEvent();

BeginGameEvent(player_disconnect);
   GameEventProperty(userid);
   GameEventProperty(reason);
   GameEventProperty(name);
   GameEventProperty(networkid);
EndGameEvent();

BeginGameEvent(player_full_update);
   GameEventProperty(userid);
   GameEventProperty(count);
EndGameEvent();

BeginGameEvent(player_fullyjoined);
   GameEventProperty(userid);
   GameEventProperty(name);
EndGameEvent();

BeginGameEvent(player_hintmessage);
   GameEventProperty(hintmessage);
EndGameEvent();

BeginGameEvent(player_hurt);
   GameEventProperty(userid);
   GameEventProperty(attacker);
   GameEventProperty(health);
EndGameEvent();

BeginGameEvent(player_info);
   GameEventProperty(name);
   GameEventProperty(index);
   GameEventProperty(userid);
   GameEventProperty(networkid);
   GameEventProperty(bot);
EndGameEvent();

BeginGameEvent(player_info_updated);
EndGameEvent();

BeginGameEvent(player_is_experienced);
EndGameEvent();

BeginGameEvent(player_is_notexperienced);
EndGameEvent();

BeginGameEvent(player_reconnected);
   GameEventProperty(PlayerID);
EndGameEvent();

BeginGameEvent(player_report_counts_updated);
   GameEventProperty(positive_remaining);
   GameEventProperty(negative_remaining);
   GameEventProperty(positive_total);
   GameEventProperty(negative_total);
EndGameEvent();

BeginGameEvent(player_say);
   GameEventProperty(userid);
   GameEventProperty(text);
EndGameEvent();

BeginGameEvent(player_score);
   GameEventProperty(userid);
   GameEventProperty(kills);
   GameEventProperty(deaths);
   GameEventProperty(score);
EndGameEvent();

BeginGameEvent(player_shoot);
   GameEventProperty(userid);
   GameEventProperty(weapon);
   GameEventProperty(mode);
EndGameEvent();

BeginGameEvent(player_spawn);
   GameEventProperty(userid);
EndGameEvent();

BeginGameEvent(player_stats_updated);
   GameEventProperty(forceupload);
EndGameEvent();

BeginGameEvent(player_team);
   GameEventProperty(userid);
   GameEventProperty(team);
   GameEventProperty(oldteam);
   GameEventProperty(disconnect);
   GameEventProperty(autoteam);
   GameEventProperty(silent);
EndGameEvent();

BeginGameEvent(player_use);
   GameEventProperty(userid);
   GameEventProperty(entity);
EndGameEvent();

BeginGameEvent(practice_lobby_visibility_changed);
EndGameEvent();

BeginGameEvent(prizepool_received);
   GameEventProperty(success);
   GameEventProperty(prizepool);
   GameEventProperty(leagueid);
EndGameEvent();

BeginGameEvent(profile_closed);
EndGameEvent();

BeginGameEvent(profile_opened);
EndGameEvent();

BeginGameEvent(ragdoll_dissolved);
   GameEventProperty(entindex);
EndGameEvent();

BeginGameEvent(recent_matches_updated);
   GameEventProperty(Page);
EndGameEvent();

BeginGameEvent(reset_defeated);
EndGameEvent();

BeginGameEvent(rich_presence_updated);
EndGameEvent();

BeginGameEvent(richpresence_custom_updated);
EndGameEvent();

BeginGameEvent(round_end);
   GameEventProperty(winner);
   GameEventProperty(reason);
   GameEventProperty(message);
EndGameEvent();

BeginGameEvent(round_start);
   GameEventProperty(timelimit);
   GameEventProperty(fraglimit);
   GameEventProperty(objective);
EndGameEvent();

BeginGameEvent(round_start_pre_entity);
EndGameEvent();

BeginGameEvent(scaleform_file_download_complete);
   GameEventProperty(success);
   GameEventProperty(local_filename);
   GameEventProperty(remote_url);
EndGameEvent();

BeginGameEvent(server_addban);
   GameEventProperty(name);
   GameEventProperty(userid);
   GameEventProperty(networkid);
   GameEventProperty(ip);
   GameEventProperty(duration);
   GameEventProperty(by);
   GameEventProperty(kicked);
EndGameEvent();

BeginGameEvent(server_cvar);
   GameEventProperty(cvarname);
   GameEventProperty(cvarvalue);
EndGameEvent();

BeginGameEvent(server_message);
   GameEventProperty(text);
EndGameEvent();

BeginGameEvent(server_pre_shutdown);
   GameEventProperty(reason);
EndGameEvent();

BeginGameEvent(server_removeban);
   GameEventProperty(networkid);
   GameEventProperty(ip);
   GameEventProperty(by);
EndGameEvent();

BeginGameEvent(server_shutdown);
   GameEventProperty(reason);
EndGameEvent();

BeginGameEvent(server_spawn);
   GameEventProperty(hostname);
   GameEventProperty(address);
   GameEventProperty(port);
   GameEventProperty(game);
   GameEventProperty(mapname);
   GameEventProperty(addonname);
   GameEventProperty(maxplayers);
   GameEventProperty(os);
   GameEventProperty(dedicated);
   GameEventProperty(password);
EndGameEvent();

BeginGameEvent(set_instructor_group_enabled);
   GameEventProperty(group);
   GameEventProperty(enabled);
EndGameEvent();

BeginGameEvent(show_center_message);
   GameEventProperty(message);
   GameEventProperty(duration);
   GameEventProperty(clear_message_queue);
EndGameEvent();

BeginGameEvent(spec_aegis_reclaim_time);
   GameEventProperty(reclaim_time);
EndGameEvent();

BeginGameEvent(spec_item_pickup);
   GameEventProperty(player_id);
   GameEventProperty(item_name);
   GameEventProperty(purchase);
EndGameEvent();

BeginGameEvent(store_pricesheet_updated);
EndGameEvent();

BeginGameEvent(team_data_updated);
EndGameEvent();

BeginGameEvent(team_info);
   GameEventProperty(teamid);
   GameEventProperty(teamname);
EndGameEvent();

BeginGameEvent(team_score);
   GameEventProperty(teamid);
   GameEventProperty(score);
EndGameEvent();

BeginGameEvent(team_showcase_ui_update);
   GameEventProperty(show);
   GameEventProperty(account_id);
   GameEventProperty(hero_entindex);
   GameEventProperty(display_ui_on_left);
EndGameEvent();

BeginGameEvent(teamplay_broadcast_audio);
   GameEventProperty(team);
   GameEventProperty(sound);
EndGameEvent();

BeginGameEvent(teamplay_round_start);
   GameEventProperty(full_reset);
EndGameEvent();

BeginGameEvent(today_messages_updated);
   GameEventProperty(num_messages);
EndGameEvent();

BeginGameEvent(tournament_state_updated);
EndGameEvent();

BeginGameEvent(tree_cut);
   GameEventProperty(tree_x);
   GameEventProperty(tree_y);
EndGameEvent();

BeginGameEvent(ugc_details_arrived);
   GameEventProperty(published_file_id);
EndGameEvent();

BeginGameEvent(ugc_subscribed);
   GameEventProperty(published_file_id);
EndGameEvent();

BeginGameEvent(ugc_unsubscribed);
   GameEventProperty(published_file_id);
EndGameEvent();

BeginGameEvent(user_data_downloaded);
EndGameEvent();

std::map<std::string, const GameEventBase*> GameEventList::mGameEventMap = {
   { "account_all_hero_challenge_changed", GameEventClass<event::account_all_hero_challenge_changed>::InstancePtr },
   { "account_trophies_changed", GameEventClass<event::account_trophies_changed>::InstancePtr },
   { "achievement_earned", GameEventClass<event::achievement_earned>::InstancePtr },
   { "achievement_event", GameEventClass<event::achievement_event>::InstancePtr },
   { "achievement_write_failed", GameEventClass<event::achievement_write_failed>::InstancePtr },
   { "antiaddiction_toast", GameEventClass<event::antiaddiction_toast>::InstancePtr },
   { "antiaddiction_update", GameEventClass<event::antiaddiction_update>::InstancePtr },
   { "bindpanel_close", GameEventClass<event::bindpanel_close>::InstancePtr },
   { "bindpanel_open", GameEventClass<event::bindpanel_open>::InstancePtr },
   { "bonus_updated", GameEventClass<event::bonus_updated>::InstancePtr },
   { "booster_state_updated", GameEventClass<event::booster_state_updated>::InstancePtr },
   { "break_breakable", GameEventClass<event::break_breakable>::InstancePtr },
   { "break_prop", GameEventClass<event::break_prop>::InstancePtr },
   { "cart_updated", GameEventClass<event::cart_updated>::InstancePtr },
   { "chat_members_changed", GameEventClass<event::chat_members_changed>::InstancePtr },
   { "chat_new_message", GameEventClass<event::chat_new_message>::InstancePtr },
   { "community_cached_names_updated", GameEventClass<event::community_cached_names_updated>::InstancePtr },
   { "compendium_event_actions_loaded", GameEventClass<event::compendium_event_actions_loaded>::InstancePtr },
   { "compendium_selections_loaded", GameEventClass<event::compendium_selections_loaded>::InstancePtr },
   { "compendium_set_selection_failed", GameEventClass<event::compendium_set_selection_failed>::InstancePtr },
   { "custom_game_difficulty", GameEventClass<event::custom_game_difficulty>::InstancePtr },
   { "dashboard_caches_cleared", GameEventClass<event::dashboard_caches_cleared>::InstancePtr },
   { "dashboard_switched_section", GameEventClass<event::dashboard_switched_section>::InstancePtr },
   { "defeated", GameEventClass<event::defeated>::InstancePtr },
   { "demo_stop", GameEventClass<event::demo_stop>::InstancePtr },
   { "difficulty_changed", GameEventClass<event::difficulty_changed>::InstancePtr },
   { "dota_ability_changed", GameEventClass<event::dota_ability_changed>::InstancePtr },
   { "dota_ability_channel_finished", GameEventClass<event::dota_ability_channel_finished>::InstancePtr },
   { "dota_action_item", GameEventClass<event::dota_action_item>::InstancePtr },
   { "dota_action_success", GameEventClass<event::dota_action_success>::InstancePtr },
   { "dota_barracks_kill", GameEventClass<event::dota_barracks_kill>::InstancePtr },
   { "dota_chase_hero", GameEventClass<event::dota_chase_hero>::InstancePtr },
   { "dota_chat_assassin_announce", GameEventClass<event::dota_chat_assassin_announce>::InstancePtr },
   { "dota_chat_assassin_denied", GameEventClass<event::dota_chat_assassin_denied>::InstancePtr },
   { "dota_chat_assassin_success", GameEventClass<event::dota_chat_assassin_success>::InstancePtr },
   { "dota_chat_ban_notification", GameEventClass<event::dota_chat_ban_notification>::InstancePtr },
   { "dota_chat_event", GameEventClass<event::dota_chat_event>::InstancePtr },
   { "dota_chat_first_blood", GameEventClass<event::dota_chat_first_blood>::InstancePtr },
   { "dota_chat_informational", GameEventClass<event::dota_chat_informational>::InstancePtr },
   { "dota_chat_kill_streak", GameEventClass<event::dota_chat_kill_streak>::InstancePtr },
   { "dota_chat_timed_reward", GameEventClass<event::dota_chat_timed_reward>::InstancePtr },
   { "dota_combatlog", GameEventClass<event::dota_combatlog>::InstancePtr },
   { "dota_courier_lost", GameEventClass<event::dota_courier_lost>::InstancePtr },
   { "dota_courier_respawned", GameEventClass<event::dota_courier_respawned>::InstancePtr },
   { "dota_courier_transfer_item", GameEventClass<event::dota_courier_transfer_item>::InstancePtr },
   { "dota_effigy_kill", GameEventClass<event::dota_effigy_kill>::InstancePtr },
   { "dota_enemy_money_changed", GameEventClass<event::dota_enemy_money_changed>::InstancePtr },
   { "dota_favorite_heroes_updated", GameEventClass<event::dota_favorite_heroes_updated>::InstancePtr },
   { "dota_force_portrait_update", GameEventClass<event::dota_force_portrait_update>::InstancePtr },
   { "dota_game_state_change", GameEventClass<event::dota_game_state_change>::InstancePtr },
   { "dota_glyph_used", GameEventClass<event::dota_glyph_used>::InstancePtr },
   { "dota_hero_random", GameEventClass<event::dota_hero_random>::InstancePtr },
   { "dota_hero_swap", GameEventClass<event::dota_hero_swap>::InstancePtr },
   { "dota_holdout_revive_complete", GameEventClass<event::dota_holdout_revive_complete>::InstancePtr },
   { "dota_hud_error_message", GameEventClass<event::dota_hud_error_message>::InstancePtr },
   { "dota_hud_skin_changed", GameEventClass<event::dota_hud_skin_changed>::InstancePtr },
   { "dota_inventory_changed", GameEventClass<event::dota_inventory_changed>::InstancePtr },
   { "dota_inventory_changed_query_unit", GameEventClass<event::dota_inventory_changed_query_unit>::InstancePtr },
   { "dota_inventory_item_added", GameEventClass<event::dota_inventory_item_added>::InstancePtr },
   { "dota_inventory_item_changed", GameEventClass<event::dota_inventory_item_changed>::InstancePtr },
   { "dota_inventory_player_got_item", GameEventClass<event::dota_inventory_player_got_item>::InstancePtr },
   { "dota_item_auto_purchase", GameEventClass<event::dota_item_auto_purchase>::InstancePtr },
   { "dota_item_drag_begin", GameEventClass<event::dota_item_drag_begin>::InstancePtr },
   { "dota_item_drag_end", GameEventClass<event::dota_item_drag_end>::InstancePtr },
   { "dota_item_gifted", GameEventClass<event::dota_item_gifted>::InstancePtr },
   { "dota_item_picked_up", GameEventClass<event::dota_item_picked_up>::InstancePtr },
   { "dota_item_purchase", GameEventClass<event::dota_item_purchase>::InstancePtr },
   { "dota_item_purchased", GameEventClass<event::dota_item_purchased>::InstancePtr },
   { "dota_item_spotted", GameEventClass<event::dota_item_spotted>::InstancePtr },
   { "dota_item_used", GameEventClass<event::dota_item_used>::InstancePtr },
   { "dota_link_clicked", GameEventClass<event::dota_link_clicked>::InstancePtr },
   { "dota_local_quickbuy_changed", GameEventClass<event::dota_local_quickbuy_changed>::InstancePtr },
   { "dota_match_done", GameEventClass<event::dota_match_done>::InstancePtr },
   { "dota_match_done_client", GameEventClass<event::dota_match_done_client>::InstancePtr },
   { "dota_match_signout", GameEventClass<event::dota_match_signout>::InstancePtr },
   { "dota_money_changed", GameEventClass<event::dota_money_changed>::InstancePtr },
   { "dota_no_battle_points", GameEventClass<event::dota_no_battle_points>::InstancePtr },
   { "dota_non_player_used_ability", GameEventClass<event::dota_non_player_used_ability>::InstancePtr },
   { "dota_pause_event", GameEventClass<event::dota_pause_event>::InstancePtr },
   { "dota_player_deny", GameEventClass<event::dota_player_deny>::InstancePtr },
   { "dota_player_gained_level", GameEventClass<event::dota_player_gained_level>::InstancePtr },
   { "dota_player_kill", GameEventClass<event::dota_player_kill>::InstancePtr },
   { "dota_player_killed", GameEventClass<event::dota_player_killed>::InstancePtr },
   { "dota_player_learned_ability", GameEventClass<event::dota_player_learned_ability>::InstancePtr },
   { "dota_player_pick_hero", GameEventClass<event::dota_player_pick_hero>::InstancePtr },
   { "dota_player_shop_changed", GameEventClass<event::dota_player_shop_changed>::InstancePtr },
   { "dota_player_show_killcam", GameEventClass<event::dota_player_show_killcam>::InstancePtr },
   { "dota_player_show_minikillcam", GameEventClass<event::dota_player_show_minikillcam>::InstancePtr },
   { "dota_player_take_tower_damage", GameEventClass<event::dota_player_take_tower_damage>::InstancePtr },
   { "dota_player_update_hero_selection", GameEventClass<event::dota_player_update_hero_selection>::InstancePtr },
   { "dota_player_update_killcam_unit", GameEventClass<event::dota_player_update_killcam_unit>::InstancePtr },
   { "dota_player_update_query_unit", GameEventClass<event::dota_player_update_query_unit>::InstancePtr },
   { "dota_player_update_selected_unit", GameEventClass<event::dota_player_update_selected_unit>::InstancePtr },
   { "dota_player_used_ability", GameEventClass<event::dota_player_used_ability>::InstancePtr },
   { "dota_portrait_ability_layout_changed", GameEventClass<event::dota_portrait_ability_layout_changed>::InstancePtr },
   { "dota_portrait_unit_modifiers_changed", GameEventClass<event::dota_portrait_unit_modifiers_changed>::InstancePtr },
   { "dota_portrait_unit_stats_changed", GameEventClass<event::dota_portrait_unit_stats_changed>::InstancePtr },
   { "dota_quest_completed", GameEventClass<event::dota_quest_completed>::InstancePtr },
   { "dota_quest_started", GameEventClass<event::dota_quest_started>::InstancePtr },
   { "dota_quick_buy_changed", GameEventClass<event::dota_quick_buy_changed>::InstancePtr },
   { "dota_rd_chat_turn", GameEventClass<event::dota_rd_chat_turn>::InstancePtr },
   { "dota_reset_suggested_items", GameEventClass<event::dota_reset_suggested_items>::InstancePtr },
   { "dota_roshan_kill", GameEventClass<event::dota_roshan_kill>::InstancePtr },
   { "dota_rubick_ability_steal", GameEventClass<event::dota_rubick_ability_steal>::InstancePtr },
   { "dota_rune_activated_server", GameEventClass<event::dota_rune_activated_server>::InstancePtr },
   { "dota_rune_pickup", GameEventClass<event::dota_rune_pickup>::InstancePtr },
   { "dota_rune_spotted", GameEventClass<event::dota_rune_spotted>::InstancePtr },
   { "dota_set_quick_buy", GameEventClass<event::dota_set_quick_buy>::InstancePtr },
   { "dota_shop_item_drag_begin", GameEventClass<event::dota_shop_item_drag_begin>::InstancePtr },
   { "dota_shop_item_drag_end", GameEventClass<event::dota_shop_item_drag_end>::InstancePtr },
   { "dota_spectate_hero", GameEventClass<event::dota_spectate_hero>::InstancePtr },
   { "dota_starting_position_changed", GameEventClass<event::dota_starting_position_changed>::InstancePtr },
   { "dota_super_creeps", GameEventClass<event::dota_super_creeps>::InstancePtr },
   { "dota_tournament_item_event", GameEventClass<event::dota_tournament_item_event>::InstancePtr },
   { "dota_tower_kill", GameEventClass<event::dota_tower_kill>::InstancePtr },
   { "dota_tutorial_lesson_start", GameEventClass<event::dota_tutorial_lesson_start>::InstancePtr },
   { "dota_unit_event", GameEventClass<event::dota_unit_event>::InstancePtr },
   { "dota_workshop_filecanceled", GameEventClass<event::dota_workshop_filecanceled>::InstancePtr },
   { "dota_workshop_fileselected", GameEventClass<event::dota_workshop_fileselected>::InstancePtr },
   { "drop_rate_modified", GameEventClass<event::drop_rate_modified>::InstancePtr },
   { "entity_hurt", GameEventClass<event::entity_hurt>::InstancePtr },
   { "entity_killed", GameEventClass<event::entity_killed>::InstancePtr },
   { "event_points_updated", GameEventClass<event::event_points_updated>::InstancePtr },
   { "event_ticket_modified", GameEventClass<event::event_ticket_modified>::InstancePtr },
   { "fantasy_league_changed", GameEventClass<event::fantasy_league_changed>::InstancePtr },
   { "fantasy_score_info_changed", GameEventClass<event::fantasy_score_info_changed>::InstancePtr },
   { "fantasy_updated", GameEventClass<event::fantasy_updated>::InstancePtr },
   { "file_downloaded", GameEventClass<event::file_downloaded>::InstancePtr },
   { "finale_start", GameEventClass<event::finale_start>::InstancePtr },
   { "flare_ignite_npc", GameEventClass<event::flare_ignite_npc>::InstancePtr },
   { "frosty_points_updated", GameEventClass<event::frosty_points_updated>::InstancePtr },
   { "full_ui_unlocked", GameEventClass<event::full_ui_unlocked>::InstancePtr },
   { "game_end", GameEventClass<event::game_end>::InstancePtr },
   { "game_end_visible", GameEventClass<event::game_end_visible>::InstancePtr },
   { "game_init", GameEventClass<event::game_init>::InstancePtr },
   { "game_message", GameEventClass<event::game_message>::InstancePtr },
   { "game_newmap", GameEventClass<event::game_newmap>::InstancePtr },
   { "game_rules_state_change", GameEventClass<event::game_rules_state_change>::InstancePtr },
   { "game_start", GameEventClass<event::game_start>::InstancePtr },
   { "gameinstructor_draw", GameEventClass<event::gameinstructor_draw>::InstancePtr },
   { "gameinstructor_nodraw", GameEventClass<event::gameinstructor_nodraw>::InstancePtr },
   { "gameui_activated", GameEventClass<event::gameui_activated>::InstancePtr },
   { "gameui_hidden", GameEventClass<event::gameui_hidden>::InstancePtr },
   { "gc_chat_channel_list_updated", GameEventClass<event::gc_chat_channel_list_updated>::InstancePtr },
   { "gc_connected", GameEventClass<event::gc_connected>::InstancePtr },
   { "gc_mismatched_version", GameEventClass<event::gc_mismatched_version>::InstancePtr },
   { "gc_user_session_created", GameEventClass<event::gc_user_session_created>::InstancePtr },
   { "guild_data_updated", GameEventClass<event::guild_data_updated>::InstancePtr },
   { "guild_open_parties_updated", GameEventClass<event::guild_open_parties_updated>::InstancePtr },
   { "halloween_high_score_received", GameEventClass<event::halloween_high_score_received>::InstancePtr },
   { "halloween_high_score_request_failed", GameEventClass<event::halloween_high_score_request_failed>::InstancePtr },
   { "halloween_phase_end", GameEventClass<event::halloween_phase_end>::InstancePtr },
   { "helicopter_grenade_punt_miss", GameEventClass<event::helicopter_grenade_punt_miss>::InstancePtr },
   { "hero_picker_hidden", GameEventClass<event::hero_picker_hidden>::InstancePtr },
   { "hero_picker_shown", GameEventClass<event::hero_picker_shown>::InstancePtr },
   { "hero_selector_preview_set", GameEventClass<event::hero_selector_preview_set>::InstancePtr },
   { "hide_highlight_hud_element", GameEventClass<event::hide_highlight_hud_element>::InstancePtr },
   { "highlight_hud_element", GameEventClass<event::highlight_hud_element>::InstancePtr },
   { "hltv_cameraman", GameEventClass<event::hltv_cameraman>::InstancePtr },
   { "hltv_chase", GameEventClass<event::hltv_chase>::InstancePtr },
   { "hltv_chat", GameEventClass<event::hltv_chat>::InstancePtr },
   { "hltv_fixed", GameEventClass<event::hltv_fixed>::InstancePtr },
   { "hltv_message", GameEventClass<event::hltv_message>::InstancePtr },
   { "hltv_rank_camera", GameEventClass<event::hltv_rank_camera>::InstancePtr },
   { "hltv_rank_entity", GameEventClass<event::hltv_rank_entity>::InstancePtr },
   { "hltv_status", GameEventClass<event::hltv_status>::InstancePtr },
   { "hltv_title", GameEventClass<event::hltv_title>::InstancePtr },
   { "hltv_versioninfo", GameEventClass<event::hltv_versioninfo>::InstancePtr },
   { "hostname_changed", GameEventClass<event::hostname_changed>::InstancePtr },
   { "hud_flip_changed", GameEventClass<event::hud_flip_changed>::InstancePtr },
   { "ingame_events_changed", GameEventClass<event::ingame_events_changed>::InstancePtr },
   { "instructor_server_hint_create", GameEventClass<event::instructor_server_hint_create>::InstancePtr },
   { "instructor_server_hint_stop", GameEventClass<event::instructor_server_hint_stop>::InstancePtr },
   { "intro_video_finished", GameEventClass<event::intro_video_finished>::InstancePtr },
   { "inventory_updated", GameEventClass<event::inventory_updated>::InstancePtr },
   { "item_preview_closed", GameEventClass<event::item_preview_closed>::InstancePtr },
   { "item_purchased", GameEventClass<event::item_purchased>::InstancePtr },
   { "item_schema_initialized", GameEventClass<event::item_schema_initialized>::InstancePtr },
   { "joined_chat_channel", GameEventClass<event::joined_chat_channel>::InstancePtr },
   { "keybind_changed", GameEventClass<event::keybind_changed>::InstancePtr },
   { "last_hit", GameEventClass<event::last_hit>::InstancePtr },
   { "left_chat_channel", GameEventClass<event::left_chat_channel>::InstancePtr },
   { "live_games_updated", GameEventClass<event::live_games_updated>::InstancePtr },
   { "lobby_updated", GameEventClass<event::lobby_updated>::InstancePtr },
   { "local_player_event_points", GameEventClass<event::local_player_event_points>::InstancePtr },
   { "map_location_updated", GameEventClass<event::map_location_updated>::InstancePtr },
   { "map_shutdown", GameEventClass<event::map_shutdown>::InstancePtr },
   { "map_transition", GameEventClass<event::map_transition>::InstancePtr },
   { "match_details_updated", GameEventClass<event::match_details_updated>::InstancePtr },
   { "match_history_updated", GameEventClass<event::match_history_updated>::InstancePtr },
   { "matchmaking_status_visibility_changed", GameEventClass<event::matchmaking_status_visibility_changed>::InstancePtr },
   { "microtransaction_success", GameEventClass<event::microtransaction_success>::InstancePtr },
   { "modifier_event", GameEventClass<event::modifier_event>::InstancePtr },
   { "news_updated", GameEventClass<event::news_updated>::InstancePtr },
   { "nommed_tree", GameEventClass<event::nommed_tree>::InstancePtr },
   { "npc_replaced", GameEventClass<event::npc_replaced>::InstancePtr },
   { "npc_spawned", GameEventClass<event::npc_spawned>::InstancePtr },
   { "party_updated", GameEventClass<event::party_updated>::InstancePtr },
   { "persona_updated", GameEventClass<event::persona_updated>::InstancePtr },
   { "physgun_pickup", GameEventClass<event::physgun_pickup>::InstancePtr },
   { "player_activate", GameEventClass<event::player_activate>::InstancePtr },
   { "player_changename", GameEventClass<event::player_changename>::InstancePtr },
   { "player_chat", GameEventClass<event::player_chat>::InstancePtr },
   { "player_class", GameEventClass<event::player_class>::InstancePtr },
   { "player_completed_game", GameEventClass<event::player_completed_game>::InstancePtr },
   { "player_connect", GameEventClass<event::player_connect>::InstancePtr },
   { "player_connect_full", GameEventClass<event::player_connect_full>::InstancePtr },
   { "player_death", GameEventClass<event::player_death>::InstancePtr },
   { "player_disconnect", GameEventClass<event::player_disconnect>::InstancePtr },
   { "player_full_update", GameEventClass<event::player_full_update>::InstancePtr },
   { "player_fullyjoined", GameEventClass<event::player_fullyjoined>::InstancePtr },
   { "player_hintmessage", GameEventClass<event::player_hintmessage>::InstancePtr },
   { "player_hurt", GameEventClass<event::player_hurt>::InstancePtr },
   { "player_info", GameEventClass<event::player_info>::InstancePtr },
   { "player_info_updated", GameEventClass<event::player_info_updated>::InstancePtr },
   { "player_is_experienced", GameEventClass<event::player_is_experienced>::InstancePtr },
   { "player_is_notexperienced", GameEventClass<event::player_is_notexperienced>::InstancePtr },
   { "player_reconnected", GameEventClass<event::player_reconnected>::InstancePtr },
   { "player_report_counts_updated", GameEventClass<event::player_report_counts_updated>::InstancePtr },
   { "player_say", GameEventClass<event::player_say>::InstancePtr },
   { "player_score", GameEventClass<event::player_score>::InstancePtr },
   { "player_shoot", GameEventClass<event::player_shoot>::InstancePtr },
   { "player_spawn", GameEventClass<event::player_spawn>::InstancePtr },
   { "player_stats_updated", GameEventClass<event::player_stats_updated>::InstancePtr },
   { "player_team", GameEventClass<event::player_team>::InstancePtr },
   { "player_use", GameEventClass<event::player_use>::InstancePtr },
   { "practice_lobby_visibility_changed", GameEventClass<event::practice_lobby_visibility_changed>::InstancePtr },
   { "prizepool_received", GameEventClass<event::prizepool_received>::InstancePtr },
   { "profile_closed", GameEventClass<event::profile_closed>::InstancePtr },
   { "profile_opened", GameEventClass<event::profile_opened>::InstancePtr },
   { "ragdoll_dissolved", GameEventClass<event::ragdoll_dissolved>::InstancePtr },
   { "recent_matches_updated", GameEventClass<event::recent_matches_updated>::InstancePtr },
   { "reset_defeated", GameEventClass<event::reset_defeated>::InstancePtr },
   { "rich_presence_updated", GameEventClass<event::rich_presence_updated>::InstancePtr },
   { "richpresence_custom_updated", GameEventClass<event::richpresence_custom_updated>::InstancePtr },
   { "round_end", GameEventClass<event::round_end>::InstancePtr },
   { "round_start", GameEventClass<event::round_start>::InstancePtr },
   { "round_start_pre_entity", GameEventClass<event::round_start_pre_entity>::InstancePtr },
   { "scaleform_file_download_complete", GameEventClass<event::scaleform_file_download_complete>::InstancePtr },
   { "server_addban", GameEventClass<event::server_addban>::InstancePtr },
   { "server_cvar", GameEventClass<event::server_cvar>::InstancePtr },
   { "server_message", GameEventClass<event::server_message>::InstancePtr },
   { "server_pre_shutdown", GameEventClass<event::server_pre_shutdown>::InstancePtr },
   { "server_removeban", GameEventClass<event::server_removeban>::InstancePtr },
   { "server_shutdown", GameEventClass<event::server_shutdown>::InstancePtr },
   { "server_spawn", GameEventClass<event::server_spawn>::InstancePtr },
   { "set_instructor_group_enabled", GameEventClass<event::set_instructor_group_enabled>::InstancePtr },
   { "show_center_message", GameEventClass<event::show_center_message>::InstancePtr },
   { "spec_aegis_reclaim_time", GameEventClass<event::spec_aegis_reclaim_time>::InstancePtr },
   { "spec_item_pickup", GameEventClass<event::spec_item_pickup>::InstancePtr },
   { "store_pricesheet_updated", GameEventClass<event::store_pricesheet_updated>::InstancePtr },
   { "team_data_updated", GameEventClass<event::team_data_updated>::InstancePtr },
   { "team_info", GameEventClass<event::team_info>::InstancePtr },
   { "team_score", GameEventClass<event::team_score>::InstancePtr },
   { "team_showcase_ui_update", GameEventClass<event::team_showcase_ui_update>::InstancePtr },
   { "teamplay_broadcast_audio", GameEventClass<event::teamplay_broadcast_audio>::InstancePtr },
   { "teamplay_round_start", GameEventClass<event::teamplay_round_start>::InstancePtr },
   { "today_messages_updated", GameEventClass<event::today_messages_updated>::InstancePtr },
   { "tournament_state_updated", GameEventClass<event::tournament_state_updated>::InstancePtr },
   { "tree_cut", GameEventClass<event::tree_cut>::InstancePtr },
   { "ugc_details_arrived", GameEventClass<event::ugc_details_arrived>::InstancePtr },
   { "ugc_subscribed", GameEventClass<event::ugc_subscribed>::InstancePtr },
   { "ugc_unsubscribed", GameEventClass<event::ugc_unsubscribed>::InstancePtr },
   { "user_data_downloaded", GameEventClass<event::user_data_downloaded>::InstancePtr },
};

}
