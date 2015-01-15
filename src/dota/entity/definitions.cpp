#include "CAI_BaseNPC.h"
#include "CBaseAnimating.h"
#include "CBaseAnimatingOverlay.h"
#include "CBaseAttributableItem.h"
#include "CBaseButton.h"
#include "CBaseCombatCharacter.h"
#include "CBaseCombatWeapon.h"
#include "CBaseDoor.h"
#include "CBaseEntity.h"
#include "CBaseFlex.h"
#include "CBaseGrenade.h"
#include "CBaseParticleEntity.h"
#include "CBasePlayer.h"
#include "CBasePropDoor.h"
#include "CBaseTempEntity.h"
#include "CBaseToggle.h"
#include "CBaseTrigger.h"
#include "CBaseViewModel.h"
#include "CBeam.h"
#include "CBeamSpotlight.h"
#include "CBoneFollower.h"
#include "CBreakableProp.h"
#include "CBreakableSurface.h"
#include "CColorCorrection.h"
#include "CColorCorrectionVolume.h"
#include "CDOTA_Ability_AbyssalUnderlord_DarkRift.h"
#include "CDOTA_Ability_AbyssalUnderlord_Firestorm.h"
#include "CDOTA_Ability_AbyssalUnderlord_PitOfMalice.h"
#include "CDOTA_Ability_Alchemist_AcidSpray.h"
#include "CDOTA_Ability_AncientApparition_ChillingTouch.h"
#include "CDOTA_Ability_AncientApparition_ColdFeet.h"
#include "CDOTA_Ability_AncientApparition_IceBlast.h"
#include "CDOTA_Ability_AncientApparition_IceVortex.h"
#include "CDOTA_Ability_AntiMage_Blink.h"
#include "CDOTA_Ability_AntiMage_ManaVoid.h"
#include "CDOTA_Ability_AttributeBonus.h"
#include "CDOTA_Ability_Axe_BerserkersCall.h"
#include "CDOTA_Ability_Axe_CounterHelix.h"
#include "CDOTA_Ability_Axe_CullingBlade.h"
#include "CDOTA_Ability_Bane_FiendsGrip.h"
#include "CDOTA_Ability_Batrider_Flamebreak.h"
#include "CDOTA_Ability_Batrider_StickyNapalm.h"
#include "CDOTA_Ability_Beastmaster_PrimalRoar.h"
#include "CDOTA_Ability_Bloodseeker_Bloodbath.h"
#include "CDOTA_Ability_BountyHunter_ShurikenToss.h"
#include "CDOTA_Ability_Brewmaster_DispelMagic.h"
#include "CDOTA_Ability_Brewmaster_DrunkenBrawler.h"
#include "CDOTA_Ability_Brewmaster_DrunkenHaze.h"
#include "CDOTA_Ability_Brewmaster_PrimalSplit.h"
#include "CDOTA_Ability_Bristleback_QuillSpray.h"
#include "CDOTA_Ability_Broodmother_SpinWeb.h"
#include "CDOTA_Ability_Centaur_Stampede.h"
#include "CDOTA_Ability_ChaosKnight_Phantasm.h"
#include "CDOTA_Ability_Chen_HandOfGod.h"
#include "CDOTA_Ability_Chen_HolyPersuasion.h"
#include "CDOTA_Ability_Chen_TestOfFaithTeleport.h"
#include "CDOTA_Ability_Courier_TakeStashItems.h"
#include "CDOTA_Ability_Courier_TransferItems.h"
#include "CDOTA_Ability_CrystalMaiden_CrystalNova.h"
#include "CDOTA_Ability_CrystalMaiden_FreezingField.h"
#include "CDOTA_Ability_DarkSeer_Vacuum.h"
#include "CDOTA_Ability_DataDriven.h"
#include "CDOTA_Ability_Dazzle_Weave.h"
#include "CDOTA_Ability_DeathProphet_CarrionSwarm.h"
#include "CDOTA_Ability_DeathProphet_Silence.h"
#include "CDOTA_Ability_Disruptor_KineticField.h"
#include "CDOTA_Ability_Disruptor_StaticStorm.h"
#include "CDOTA_Ability_DoomBringer_Devour.h"
#include "CDOTA_Ability_DragonKnight_BreatheFire.h"
#include "CDOTA_Ability_DrowRanger_Silence.h"
#include "CDOTA_Ability_DrowRanger_WaveOfSilence.h"
#include "CDOTA_Ability_EarthSpirit_BoulderSmash.h"
#include "CDOTA_Ability_EarthSpirit_GeomagneticGrip.h"
#include "CDOTA_Ability_EarthSpirit_Petrify.h"
#include "CDOTA_Ability_EarthSpirit_RollingBoulder.h"
#include "CDOTA_Ability_EarthSpirit_StoneCaller.h"
#include "CDOTA_Ability_Elder_Titan_EarthSplitter.h"
#include "CDOTA_Ability_EmberSpirit_Activate_FireRemnant.h"
#include "CDOTA_Ability_EmberSpirit_FireRemnant.h"
#include "CDOTA_Ability_EmberSpirit_SearingChains.h"
#include "CDOTA_Ability_EmberSpirit_SleightOfFist.h"
#include "CDOTA_Ability_Enchantress_Impetus.h"
#include "CDOTA_Ability_Enchantress_NaturesAttendants.h"
#include "CDOTA_Ability_Enchantress_Untouchable.h"
#include "CDOTA_Ability_Enigma_BlackHole.h"
#include "CDOTA_Ability_Enigma_DemonicConversion.h"
#include "CDOTA_Ability_Enigma_MidnightPulse.h"
#include "CDOTA_Ability_FacelessVoid_Chronosphere.h"
#include "CDOTA_Ability_FacelessVoid_TimeWalk.h"
#include "CDOTA_Ability_Furion_ForceOfNature.h"
#include "CDOTA_Ability_Furion_Teleportation.h"
#include "CDOTA_Ability_Greevil_BlackHole.h"
#include "CDOTA_Ability_Greevil_BladeFury.h"
#include "CDOTA_Ability_Greevil_Bloodlust.h"
#include "CDOTA_Ability_Greevil_ColdSnap.h"
#include "CDOTA_Ability_Greevil_Decrepify.h"
#include "CDOTA_Ability_Greevil_Diabolic_Edict.h"
#include "CDOTA_Ability_Greevil_EchoSlam.h"
#include "CDOTA_Ability_Greevil_Fatal_Bonds.h"
#include "CDOTA_Ability_Greevil_FleshGolem.h"
#include "CDOTA_Ability_Greevil_IceWall.h"
#include "CDOTA_Ability_Greevil_LagunaBlade.h"
#include "CDOTA_Ability_Greevil_LeechSeed.h"
#include "CDOTA_Ability_Greevil_Magic_Missile.h"
#include "CDOTA_Ability_Greevil_Maledict.h"
#include "CDOTA_Ability_Greevil_MeatHook.h"
#include "CDOTA_Ability_Greevil_Miniboss_Black_BrainSap.h"
#include "CDOTA_Ability_Greevil_Miniboss_Black_Nightmare.h"
#include "CDOTA_Ability_Greevil_Miniboss_Blue_ColdFeet.h"
#include "CDOTA_Ability_Greevil_Miniboss_Blue_IceVortex.h"
#include "CDOTA_Ability_Greevil_Miniboss_Green_LivingArmor.h"
#include "CDOTA_Ability_Greevil_Miniboss_Green_Overgrowth.h"
#include "CDOTA_Ability_Greevil_Miniboss_Orange_DragonSlave.h"
#include "CDOTA_Ability_Greevil_Miniboss_Orange_LightStrikeArray.h"
#include "CDOTA_Ability_Greevil_Miniboss_Purple_PlagueWard.h"
#include "CDOTA_Ability_Greevil_Miniboss_Purple_VenomousGale.h"
#include "CDOTA_Ability_Greevil_Miniboss_Red_Earthshock.h"
#include "CDOTA_Ability_Greevil_Miniboss_Red_Overpower.h"
#include "CDOTA_Ability_Greevil_Miniboss_Sight.h"
#include "CDOTA_Ability_Greevil_Miniboss_White_Degen_Aura.h"
#include "CDOTA_Ability_Greevil_Miniboss_White_Purification.h"
#include "CDOTA_Ability_Greevil_Miniboss_Yellow_IonShell.h"
#include "CDOTA_Ability_Greevil_Miniboss_Yellow_Surge.h"
#include "CDOTA_Ability_Greevil_NaturesAttendants.h"
#include "CDOTA_Ability_Greevil_PhantomStrike.h"
#include "CDOTA_Ability_Greevil_PoisonNova.h"
#include "CDOTA_Ability_Greevil_Purification.h"
#include "CDOTA_Ability_Greevil_Rot.h"
#include "CDOTA_Ability_Greevil_ShadowStrike.h"
#include "CDOTA_Ability_Greevil_ShadowWave.h"
#include "CDOTA_Ability_Greevil_TimeLock.h"
#include "CDOTA_Ability_Gyrocopter_Call_Down.h"
#include "CDOTA_Ability_Healing_Campfire.h"
#include "CDOTA_Ability_Holdout_CullingBlade.h"
#include "CDOTA_Ability_Holdout_GladiatorsUnite.h"
#include "CDOTA_Ability_Holdout_Multishot.h"
#include "CDOTA_Ability_Holdout_Omnislash.h"
#include "CDOTA_Ability_Huskar_Life_Break.h"
#include "CDOTA_Ability_Invoker_DeafeningBlast.h"
#include "CDOTA_Ability_Invoker_EMP.h"
#include "CDOTA_Ability_Invoker_Invoke.h"
#include "CDOTA_Ability_Invoker_InvokedBase.h"
#include "CDOTA_Ability_Invoker_SunStrike.h"
#include "CDOTA_Ability_Invoker_Tornado.h"
#include "CDOTA_Ability_Jakiro_DualBreath.h"
#include "CDOTA_Ability_Jakiro_IcePath.h"
#include "CDOTA_Ability_Jakiro_Macropyre.h"
#include "CDOTA_Ability_Juggernaut_HealingWard.h"
#include "CDOTA_Ability_Juggernaut_Omnislash.h"
#include "CDOTA_Ability_KeeperOfTheLight_BlindingLight.h"
#include "CDOTA_Ability_KeeperOfTheLight_Illuminate.h"
#include "CDOTA_Ability_KeeperOfTheLight_Recall.h"
#include "CDOTA_Ability_Kunkka_GhostShip.h"
#include "CDOTA_Ability_Kunkka_Tidebringer.h"
#include "CDOTA_Ability_Kunkka_Torrent.h"
#include "CDOTA_Ability_Legion_Commander_MomentOfCourage.h"
#include "CDOTA_Ability_Legion_Commander_OverwhelmingOdds.h"
#include "CDOTA_Ability_Leshrac_Diabolic_Edict.h"
#include "CDOTA_Ability_Leshrac_Pulse_Nova.h"
#include "CDOTA_Ability_Leshrac_Split_Earth.h"
#include "CDOTA_Ability_Lich_ChainFrost.h"
#include "CDOTA_Ability_Lich_FrostNova.h"
#include "CDOTA_Ability_Life_Stealer_Infest.h"
#include "CDOTA_Ability_Lina_DragonSlave.h"
#include "CDOTA_Ability_Lina_LagunaBlade.h"
#include "CDOTA_Ability_Lina_LightStrikeArray.h"
#include "CDOTA_Ability_Lion_FingerOfDeath.h"
#include "CDOTA_Ability_Lion_Impale.h"
#include "CDOTA_Ability_Lion_ManaDrain.h"
#include "CDOTA_Ability_LoneDruid_Rabid.h"
#include "CDOTA_Ability_LoneDruid_SpiritBear.h"
#include "CDOTA_Ability_LoneDruid_SpiritBear_Return.h"
#include "CDOTA_Ability_LoneDruid_TrueForm_BattleCry.h"
#include "CDOTA_Ability_LoneDruid_TrueForm_Druid.h"
#include "CDOTA_Ability_Luna_Eclipse.h"
#include "CDOTA_Ability_Luna_LunarBlessing.h"
#include "CDOTA_Ability_Lycan_Howl.h"
#include "CDOTA_Ability_Lycan_SummonWolves.h"
#include "CDOTA_Ability_Magnataur_ReversePolarity.h"
#include "CDOTA_Ability_Magnataur_Shockwave.h"
#include "CDOTA_Ability_Meepo_DividedWeStand.h"
#include "CDOTA_Ability_Meepo_Earthbind.h"
#include "CDOTA_Ability_Meepo_Poof.h"
#include "CDOTA_Ability_Morphling_Replicate.h"
#include "CDOTA_Ability_Morphling_Waveform.h"
#include "CDOTA_Ability_NagaSiren_MirrorImage.h"
#include "CDOTA_Ability_NagaSiren_RipTide.h"
#include "CDOTA_Ability_Necrolyte_Death_Pulse.h"
#include "CDOTA_Ability_Necrolyte_ReapersScythe.h"
#include "CDOTA_Ability_Nevermore_Requiem.h"
#include "CDOTA_Ability_Nian_Apocalypse.h"
#include "CDOTA_Ability_Nian_Eruption.h"
#include "CDOTA_Ability_Nian_Frenzy.h"
#include "CDOTA_Ability_Nian_Hurricane.h"
#include "CDOTA_Ability_Nian_Roar.h"
#include "CDOTA_Ability_Nian_Sigils.h"
#include "CDOTA_Ability_Nian_Tail_Swipe.h"
#include "CDOTA_Ability_Nian_Waterball.h"
#include "CDOTA_Ability_Nian_Whirlpool.h"
#include "CDOTA_Ability_Nyx_Assassin_Impale.h"
#include "CDOTA_Ability_Obsidian_Destroyer_ArcaneOrb.h"
#include "CDOTA_Ability_Obsidian_Destroyer_AstralImprisonment.h"
#include "CDOTA_Ability_Obsidian_Destroyer_SanityEclipse.h"
#include "CDOTA_Ability_Ogre_Magi_Bloodlust.h"
#include "CDOTA_Ability_Ogre_Magi_Fireblast.h"
#include "CDOTA_Ability_Ogre_Magi_Multicast.h"
#include "CDOTA_Ability_Ogre_Magi_Unrefined_Fireblast.h"
#include "CDOTA_Ability_Oracle_FortunesEnd.h"
#include "CDOTA_Ability_PhantomAssassin_PhantomStrike.h"
#include "CDOTA_Ability_PhantomLancer_Doppelwalk.h"
#include "CDOTA_Ability_Phoenix_LaunchFireSpirit.h"
#include "CDOTA_Ability_Phoenix_Supernova.h"
#include "CDOTA_Ability_Puck_DreamCoil.h"
#include "CDOTA_Ability_Puck_IllusoryOrb.h"
#include "CDOTA_Ability_Puck_WaningRift.h"
#include "CDOTA_Ability_Pudge_Dismember.h"
#include "CDOTA_Ability_Pudge_MeatHook.h"
#include "CDOTA_Ability_Pugna_Decrepify.h"
#include "CDOTA_Ability_Pugna_LifeDrain.h"
#include "CDOTA_Ability_Pugna_NetherBlast.h"
#include "CDOTA_Ability_QueenOfPain_Blink.h"
#include "CDOTA_Ability_QueenOfPain_SonicWave.h"
#include "CDOTA_Ability_Rattletrap_BatteryAssault.h"
#include "CDOTA_Ability_Rattletrap_Hookshot.h"
#include "CDOTA_Ability_Rattletrap_RocketFlare.h"
#include "CDOTA_Ability_Razor_PlasmaField.h"
#include "CDOTA_Ability_Riki_BlinkStrike.h"
#include "CDOTA_Ability_Riki_SmokeScreen.h"
#include "CDOTA_Ability_Roshan_Halloween_Apocalypse.h"
#include "CDOTA_Ability_Roshan_Halloween_Burn.h"
#include "CDOTA_Ability_Roshan_Halloween_Fireball.h"
#include "CDOTA_Ability_Roshan_Toss.h"
#include "CDOTA_Ability_Roshan_WaveOfForce.h"
#include "CDOTA_Ability_Rubick_SpellSteal.h"
#include "CDOTA_Ability_Rubick_TelekinesisLand.h"
#include "CDOTA_Ability_SandKing_BurrowStrike.h"
#include "CDOTA_Ability_SandKing_Epicenter.h"
#include "CDOTA_Ability_SatyrTrickster_Purge.h"
#include "CDOTA_Ability_Shadow_Demon_Disruption.h"
#include "CDOTA_Ability_Shadow_Demon_Shadow_Poison.h"
#include "CDOTA_Ability_Shadow_Demon_Soul_Catcher.h"
#include "CDOTA_Ability_Shredder_Chakram.h"
#include "CDOTA_Ability_Shredder_TimberChain.h"
#include "CDOTA_Ability_Silencer_CurseOfTheSilent.h"
#include "CDOTA_Ability_Silencer_GlaivesOfWisdom.h"
#include "CDOTA_Ability_Skywrath_Mage_Mystic_Flare.h"
#include "CDOTA_Ability_Slardar_Slithereen_Crush.h"
#include "CDOTA_Ability_Slark_EssenceShift.h"
#include "CDOTA_Ability_Sniper_Shrapnel.h"
#include "CDOTA_Ability_SpiritBreaker_NetherStrike.h"
#include "CDOTA_Ability_StormSpirit_BallLightning.h"
#include "CDOTA_Ability_Sven_StormBolt.h"
#include "CDOTA_Ability_Techies_FocusedDetonate.h"
#include "CDOTA_Ability_Techies_LandMines.h"
#include "CDOTA_Ability_Techies_Minefield_Sign.h"
#include "CDOTA_Ability_Techies_RemoteMines.h"
#include "CDOTA_Ability_Techies_RemoteMines_SelfDetonate.h"
#include "CDOTA_Ability_Techies_StasisTrap.h"
#include "CDOTA_Ability_Terrorblade_Sunder.h"
#include "CDOTA_Ability_Throw_Coal.h"
#include "CDOTA_Ability_Throw_Snowball.h"
#include "CDOTA_Ability_Tidehunter_AnchorSmash.h"
#include "CDOTA_Ability_Tidehunter_Ravage.h"
#include "CDOTA_Ability_Tiny_Avalanche.h"
#include "CDOTA_Ability_Tiny_CraggyExterior.h"
#include "CDOTA_Ability_Tiny_Toss.h"
#include "CDOTA_Ability_Treant_EyesInTheForest.h"
#include "CDOTA_Ability_Treant_Overgrowth.h"
#include "CDOTA_Ability_TrollWarlord_BerserkersRage.h"
#include "CDOTA_Ability_TrollWarlord_WhirlingAxes_Ranged.h"
#include "CDOTA_Ability_Tusk_FrozenSigil.h"
#include "CDOTA_Ability_Undying_Decay.h"
#include "CDOTA_Ability_Undying_SoulRip.h"
#include "CDOTA_Ability_VengefulSpirit_Nether_Swap.h"
#include "CDOTA_Ability_VengefulSpirit_WaveOfTerror.h"
#include "CDOTA_Ability_Venomancer_PoisonNova.h"
#include "CDOTA_Ability_Venomancer_VenomousGale.h"
#include "CDOTA_Ability_Viper_ViperStrike.h"
#include "CDOTA_Ability_Visage_SummonFamiliars.h"
#include "CDOTA_Ability_Visage_SummonFamiliars_StoneForm.h"
#include "CDOTA_Ability_Warlock_RainOfChaos.h"
#include "CDOTA_Ability_Warlock_Shadow_Word.h"
#include "CDOTA_Ability_Warlock_Upheaval.h"
#include "CDOTA_Ability_Weaver_TheSwarm.h"
#include "CDOTA_Ability_Windrunner_FocusFire.h"
#include "CDOTA_Ability_Windrunner_Powershot.h"
#include "CDOTA_Ability_Winter_Wyvern_Arctic_Burn.h"
#include "CDOTA_Ability_Winter_Wyvern_Cold_Embrace.h"
#include "CDOTA_Ability_Winter_Wyvern_Winters_Curse.h"
#include "CDOTA_Ability_Wisp_Overcharge.h"
#include "CDOTA_Ability_Wisp_Relocate.h"
#include "CDOTA_Ability_Wisp_Spirits.h"
#include "CDOTA_Ability_Wisp_Tether.h"
#include "CDOTA_Ability_WitchDoctor_Maledict.h"
#include "CDOTA_Ability_WitchDoctor_ParalyzingCask.h"
#include "CDOTA_Ability_WitchDoctor_VoodooRestoration.h"
#include "CDOTA_BaseNPC.h"
#include "CDOTA_BaseNPC_Additive.h"
#include "CDOTA_BaseNPC_Barracks.h"
#include "CDOTA_BaseNPC_Building.h"
#include "CDOTA_BaseNPC_Creature.h"
#include "CDOTA_BaseNPC_Creep.h"
#include "CDOTA_BaseNPC_Creep_Diretide.h"
#include "CDOTA_BaseNPC_Creep_Lane.h"
#include "CDOTA_BaseNPC_Creep_LootGreevil.h"
#include "CDOTA_BaseNPC_Creep_Neutral.h"
#include "CDOTA_BaseNPC_Creep_Siege.h"
#include "CDOTA_BaseNPC_Creep_Talking.h"
#include "CDOTA_BaseNPC_Fort.h"
#include "CDOTA_BaseNPC_HallofFame.h"
#include "CDOTA_BaseNPC_Hero.h"
#include "CDOTA_BaseNPC_HoldoutTower.h"
#include "CDOTA_BaseNPC_HoldoutTower_HeavySlow.h"
#include "CDOTA_BaseNPC_HoldoutTower_LightFast.h"
#include "CDOTA_BaseNPC_HoldoutTower_ReduceSpeed.h"
#include "CDOTA_BaseNPC_Invoker_Forged_Spirit.h"
#include "CDOTA_BaseNPC_ShadowShaman_SerpentWard.h"
#include "CDOTA_BaseNPC_Shop.h"
#include "CDOTA_BaseNPC_Tower.h"
#include "CDOTA_BaseNPC_Tusk_Sigil.h"
#include "CDOTA_BaseNPC_Venomancer_PlagueWard.h"
#include "CDOTA_BaseNPC_Warlock_Golem.h"
#include "CDOTA_Beastmaster_Axe.h"
#include "CDOTA_DataDire.h"
#include "CDOTA_DataNonSpectator.h"
#include "CDOTA_DataRadiant.h"
#include "CDOTA_DataSpectator.h"
#include "CDOTA_DeathProphet_Exorcism_Spirit.h"
#include "CDOTA_DisplacementVisibility.h"
#include "CDOTA_Halloween_CandyBucket.h"
#include "CDOTA_Halloween_CandyBucketDire.h"
#include "CDOTA_Halloween_CandyBucketRadiant.h"
#include "CDOTA_Hero_Recorder.h"
#include "CDOTA_Item.h"
#include "CDOTA_Item_Ancient_Janggo.h"
#include "CDOTA_Item_Armlet.h"
#include "CDOTA_Item_Battlefury.h"
#include "CDOTA_Item_BlinkDagger.h"
#include "CDOTA_Item_Bloodstone.h"
#include "CDOTA_Item_BootsOfTravel.h"
#include "CDOTA_Item_Cyclone.h"
#include "CDOTA_Item_Cyclone_2.h"
#include "CDOTA_Item_DataDriven.h"
#include "CDOTA_Item_Diffusal_Blade.h"
#include "CDOTA_Item_Diffusal_Blade_Level2.h"
#include "CDOTA_Item_EmptyBottle.h"
#include "CDOTA_Item_Ethereal_Blade.h"
#include "CDOTA_Item_ForceStaff.h"
#include "CDOTA_Item_Greevil_Blink.h"
#include "CDOTA_Item_Greevil_Whistle.h"
#include "CDOTA_Item_Greevil_WhistleToggle.h"
#include "CDOTA_Item_MantaStyle.h"
#include "CDOTA_Item_Medallion_Of_Courage.h"
#include "CDOTA_Item_Mystery_Toss.h"
#include "CDOTA_Item_Mystery_Vacuum.h"
#include "CDOTA_Item_Necronomicon.h"
#include "CDOTA_Item_Necronomicon_Level2.h"
#include "CDOTA_Item_Necronomicon_Level3.h"
#include "CDOTA_Item_Nian_Flag_Trap.h"
#include "CDOTA_Item_ObserverWard.h"
#include "CDOTA_Item_Physical.h"
#include "CDOTA_Item_PlaceBuilding.h"
#include "CDOTA_Item_PlaceBuilding_Free.h"
#include "CDOTA_Item_PlaceBuilding_Grid.h"
#include "CDOTA_Item_PowerTreads.h"
#include "CDOTA_Item_QuellingBlade.h"
#include "CDOTA_Item_Radiance.h"
#include "CDOTA_Item_Recipe_Veil_Of_Discord.h"
#include "CDOTA_Item_Ring_Of_Basilius.h"
#include "CDOTA_Item_RingOfAquila.h"
#include "CDOTA_Item_Rune.h"
#include "CDOTA_Item_SentryWard.h"
#include "CDOTA_Item_Tango.h"
#include "CDOTA_Item_TeleportScroll.h"
#include "CDOTA_Item_TranquilBoots.h"
#include "CDOTA_Item_Urn_Of_Shadows.h"
#include "CDOTA_Item_Veil_Of_Discord.h"
#include "CDOTA_NeutralSpawner.h"
#include "CDOTA_NPC_DataDriven.h"
#include "CDOTA_NPC_Observer_Ward.h"
#include "CDOTA_NPC_Observer_Ward_TrueSight.h"
#include "CDOTA_NPC_Techies_Minefield_Sign.h"
#include "CDOTA_NPC_TechiesMines.h"
#include "CDOTA_NPC_Treant_EyesInTheForest.h"
#include "CDOTA_NPC_WitchDoctor_Ward.h"
#include "CDOTA_PhantomAssassin_Gravestone.h"
#include "CDOTA_PlayerResource.h"
#include "CDOTA_RoshanSpawner.h"
#include "CDOTA_TempTree.h"
#include "CDOTA_Tiny_ScepterTree.h"
#include "CDOTA_Unit_Announcer.h"
#include "CDOTA_Unit_Announcer_Killing_Spree.h"
#include "CDOTA_Unit_Brewmaster_PrimalEarth.h"
#include "CDOTA_Unit_Brewmaster_PrimalFire.h"
#include "CDOTA_Unit_Brewmaster_PrimalStorm.h"
#include "CDOTA_Unit_Broodmother_Spiderling.h"
#include "CDOTA_Unit_Broodmother_Web.h"
#include "CDOTA_Unit_Courier.h"
#include "CDOTA_Unit_Earth_Spirit_Stone.h"
#include "CDOTA_Unit_Elder_Titan_AncestralSpirit.h"
#include "CDOTA_Unit_Fountain.h"
#include "CDOTA_Unit_Greevil.h"
#include "CDOTA_Unit_Hero_Abaddon.h"
#include "CDOTA_Unit_Hero_AbyssalUnderlord.h"
#include "CDOTA_Unit_Hero_Alchemist.h"
#include "CDOTA_Unit_Hero_AncientApparition.h"
#include "CDOTA_Unit_Hero_AntiMage.h"
#include "CDOTA_Unit_Hero_Axe.h"
#include "CDOTA_Unit_Hero_Bane.h"
#include "CDOTA_Unit_Hero_Batrider.h"
#include "CDOTA_Unit_Hero_Beastmaster.h"
#include "CDOTA_Unit_Hero_Beastmaster_Beasts.h"
#include "CDOTA_Unit_Hero_Beastmaster_Boar.h"
#include "CDOTA_Unit_Hero_Beastmaster_Hawk.h"
#include "CDOTA_Unit_Hero_Bloodseeker.h"
#include "CDOTA_Unit_Hero_BountyHunter.h"
#include "CDOTA_Unit_Hero_Brewmaster.h"
#include "CDOTA_Unit_Hero_Bristleback.h"
#include "CDOTA_Unit_Hero_Broodmother.h"
#include "CDOTA_Unit_Hero_Centaur.h"
#include "CDOTA_Unit_Hero_ChaosKnight.h"
#include "CDOTA_Unit_Hero_Chen.h"
#include "CDOTA_Unit_Hero_Clinkz.h"
#include "CDOTA_Unit_Hero_CrystalMaiden.h"
#include "CDOTA_Unit_Hero_DarkSeer.h"
#include "CDOTA_Unit_Hero_Dazzle.h"
#include "CDOTA_Unit_Hero_DeathProphet.h"
#include "CDOTA_Unit_Hero_Disruptor.h"
#include "CDOTA_Unit_Hero_DoomBringer.h"
#include "CDOTA_Unit_Hero_DragonKnight.h"
#include "CDOTA_Unit_Hero_DrowRanger.h"
#include "CDOTA_Unit_Hero_Earthshaker.h"
#include "CDOTA_Unit_Hero_EarthSpirit.h"
#include "CDOTA_Unit_Hero_Elder_Titan.h"
#include "CDOTA_Unit_Hero_EmberSpirit.h"
#include "CDOTA_Unit_Hero_Enchantress.h"
#include "CDOTA_Unit_Hero_Enigma.h"
#include "CDOTA_Unit_Hero_FacelessVoid.h"
#include "CDOTA_Unit_Hero_Furion.h"
#include "CDOTA_Unit_Hero_Gyrocopter.h"
#include "CDOTA_Unit_Hero_Huskar.h"
#include "CDOTA_Unit_Hero_Invoker.h"
#include "CDOTA_Unit_Hero_Jakiro.h"
#include "CDOTA_Unit_Hero_Juggernaut.h"
#include "CDOTA_Unit_Hero_KeeperOfTheLight.h"
#include "CDOTA_Unit_Hero_Kunkka.h"
#include "CDOTA_Unit_Hero_Legion_Commander.h"
#include "CDOTA_Unit_Hero_Leshrac.h"
#include "CDOTA_Unit_Hero_Lich.h"
#include "CDOTA_Unit_Hero_Life_Stealer.h"
#include "CDOTA_Unit_Hero_Lina.h"
#include "CDOTA_Unit_Hero_Lion.h"
#include "CDOTA_Unit_Hero_LoneDruid.h"
#include "CDOTA_Unit_Hero_Luna.h"
#include "CDOTA_Unit_Hero_Lycan.h"
#include "CDOTA_Unit_Hero_Magnataur.h"
#include "CDOTA_Unit_Hero_Medusa.h"
#include "CDOTA_Unit_Hero_Meepo.h"
#include "CDOTA_Unit_Hero_Mirana.h"
#include "CDOTA_Unit_Hero_Morphling.h"
#include "CDOTA_Unit_Hero_Naga_Siren.h"
#include "CDOTA_Unit_Hero_Necrolyte.h"
#include "CDOTA_Unit_Hero_Nevermore.h"
#include "CDOTA_Unit_Hero_NightStalker.h"
#include "CDOTA_Unit_Hero_Nyx_Assassin.h"
#include "CDOTA_Unit_Hero_Obsidian_Destroyer.h"
#include "CDOTA_Unit_Hero_Ogre_Magi.h"
#include "CDOTA_Unit_Hero_Omniknight.h"
#include "CDOTA_Unit_Hero_Oracle.h"
#include "CDOTA_Unit_Hero_PhantomAssassin.h"
#include "CDOTA_Unit_Hero_PhantomLancer.h"
#include "CDOTA_Unit_Hero_Phoenix.h"
#include "CDOTA_Unit_Hero_Puck.h"
#include "CDOTA_Unit_Hero_Pudge.h"
#include "CDOTA_Unit_Hero_Pugna.h"
#include "CDOTA_Unit_Hero_QueenOfPain.h"
#include "CDOTA_Unit_Hero_Rattletrap.h"
#include "CDOTA_Unit_Hero_Razor.h"
#include "CDOTA_Unit_Hero_Riki.h"
#include "CDOTA_Unit_Hero_Rubick.h"
#include "CDOTA_Unit_Hero_SandKing.h"
#include "CDOTA_Unit_Hero_Shadow_Demon.h"
#include "CDOTA_Unit_Hero_ShadowShaman.h"
#include "CDOTA_Unit_Hero_Shredder.h"
#include "CDOTA_Unit_Hero_Silencer.h"
#include "CDOTA_Unit_Hero_SkeletonKing.h"
#include "CDOTA_Unit_Hero_Skywrath_Mage.h"
#include "CDOTA_Unit_Hero_Slardar.h"
#include "CDOTA_Unit_Hero_Slark.h"
#include "CDOTA_Unit_Hero_Sniper.h"
#include "CDOTA_Unit_Hero_Spectre.h"
#include "CDOTA_Unit_Hero_SpiritBreaker.h"
#include "CDOTA_Unit_Hero_StormSpirit.h"
#include "CDOTA_Unit_Hero_Sven.h"
#include "CDOTA_Unit_Hero_Techies.h"
#include "CDOTA_Unit_Hero_TemplarAssassin.h"
#include "CDOTA_Unit_Hero_Terrorblade.h"
#include "CDOTA_Unit_Hero_Tidehunter.h"
#include "CDOTA_Unit_Hero_Tinker.h"
#include "CDOTA_Unit_Hero_Tiny.h"
#include "CDOTA_Unit_Hero_Treant.h"
#include "CDOTA_Unit_Hero_TrollWarlord.h"
#include "CDOTA_Unit_Hero_Tusk.h"
#include "CDOTA_Unit_Hero_Undying.h"
#include "CDOTA_Unit_Hero_Ursa.h"
#include "CDOTA_Unit_Hero_VengefulSpirit.h"
#include "CDOTA_Unit_Hero_Venomancer.h"
#include "CDOTA_Unit_Hero_Viper.h"
#include "CDOTA_Unit_Hero_Visage.h"
#include "CDOTA_Unit_Hero_Warlock.h"
#include "CDOTA_Unit_Hero_Weaver.h"
#include "CDOTA_Unit_Hero_Windrunner.h"
#include "CDOTA_Unit_Hero_Winter_Wyvern.h"
#include "CDOTA_Unit_Hero_Wisp.h"
#include "CDOTA_Unit_Hero_WitchDoctor.h"
#include "CDOTA_Unit_Hero_Zuus.h"
#include "CDOTA_Unit_LoopingSound.h"
#include "CDOTA_Unit_Nian.h"
#include "CDOTA_Unit_Roquelaire.h"
#include "CDOTA_Unit_Roshan.h"
#include "CDOTA_Unit_Roshan_Halloween.h"
#include "CDOTA_Unit_SpiritBear.h"
#include "CDOTA_Unit_TargetDummy.h"
#include "CDOTA_Unit_Undying_Tombstone.h"
#include "CDOTA_Unit_Undying_Zombie.h"
#include "CDOTA_Unit_VisageFamiliar.h"
#include "CDOTA_Wisp_Spirit.h"
#include "CDOTABaseAbility.h"
#include "CDOTABaseGameMode.h"
#include "CDOTACameraBounds.h"
#include "CDOTAFogOfWarTempViewers.h"
#include "CDOTAFogOfWarWasVisible.h"
#include "CDOTAGameManagerProxy.h"
#include "CDOTAGamerulesProxy.h"
#include "CDOTAHoldoutNetworker.h"
#include "CDOTAMinimapBoundary.h"
#include "CDOTAPlayer.h"
#include "CDOTAPropCustomTexture.h"
#include "CDotaQuest.h"
#include "CDotaQuestBase.h"
#include "CDOTASpecGraphPlayerData.h"
#include "CDOTASpectatorGraphManagerProxy.h"
#include "CDotaSubquestBase.h"
#include "CDOTATeam.h"
#include "CDotaTutorialNetworker.h"
#include "CDOTAWearableItem.h"
#include "CDynamicLight.h"
#include "CDynamicProp.h"
#include "CEconEntity.h"
#include "CEconWearable.h"
#include "CEntityDissolve.h"
#include "CEntityFlame.h"
#include "CEntityFreezing.h"
#include "CEntityParticleTrail.h"
#include "CEnvAmbientLight.h"
#include "CEnvDeferredLight.h"
#include "CEnvDetailController.h"
#include "CEnvDOFController.h"
#include "CEnvParticleScript.h"
#include "CEnvProjectedTexture.h"
#include "CEnvQuadraticBeam.h"
#include "CEnvScreenEffect.h"
#include "CEnvScreenOverlay.h"
#include "CEnvTonemapController.h"
#include "CEnvWind.h"
#include "CFireSmoke.h"
#include "CFireTrail.h"
#include "CFish.h"
#include "CFogController.h"
#include "CFunc_Dust.h"
#include "CFunc_LOD.h"
#include "CFuncAreaPortalWindow.h"
#include "CFuncBrush.h"
#include "CFuncConveyor.h"
#include "CFuncLadder.h"
#include "CFuncMoveLinear.h"
#include "CFuncOccluder.h"
#include "CFuncReflectiveGlass.h"
#include "CFuncRotating.h"
#include "CFuncSmokeVolume.h"
#include "CFuncTrackTrain.h"
#include "CGameRulesProxy.h"
#include "CHandleTest.h"
#include "CInfoLadderDismount.h"
#include "CInfoOverlayAccessor.h"
#include "CLightGlow.h"
#include "CMaterialModifyControl.h"
#include "CMovieDisplay.h"
#include "CParticleFire.h"
#include "CParticlePerformanceMonitor.h"
#include "CParticleSystem.h"
#include "CPhysBox.h"
#include "CPhysBoxMultiplayer.h"
#include "CPhysicsProp.h"
#include "CPhysicsPropMultiplayer.h"
#include "CPhysMagnet.h"
#include "CPlasma.h"
#include "CPointCamera.h"
#include "CPointCommentaryNode.h"
#include "CPoseController.h"
#include "CPostProcessController.h"
#include "CPrecipitation.h"
#include "CPrecipitationBlocker.h"
#include "CProp_Hallucination.h"
#include "CPropDoorRotating.h"
#include "CPropVehicleDriveable.h"
#include "CRagdollManager.h"
#include "CRagdollProp.h"
#include "CRagdollPropAttached.h"
#include "CRopeKeyframe.h"
#include "CSceneEntity.h"
#include "CShadowControl.h"
#include "CSlideshowDisplay.h"
#include "CSmokeStack.h"
#include "CSpatialEntity.h"
#include "CSpotlightEnd.h"
#include "CSprite.h"
#include "CSpriteOriented.h"
#include "CSpriteTrail.h"
#include "CStatueProp.h"
#include "CSteamJet.h"
#include "CSun.h"
#include "CSunlightShadowControl.h"
#include "CTeam.h"
#include "CTeamShowcaseEditorManager.h"
#include "CTeamShowcasePlayer.h"
#include "CTEArmorRicochet.h"
#include "CTEBaseBeam.h"
#include "CTEBeamEntPoint.h"
#include "CTEBeamEnts.h"
#include "CTEBeamFollow.h"
#include "CTEBeamLaser.h"
#include "CTEBeamPoints.h"
#include "CTEBeamRing.h"
#include "CTEBeamRingPoint.h"
#include "CTEBeamSpline.h"
#include "CTEBloodSprite.h"
#include "CTEBloodStream.h"
#include "CTEBreakModel.h"
#include "CTEBSPDecal.h"
#include "CTEBubbles.h"
#include "CTEBubbleTrail.h"
#include "CTEClientProjectile.h"
#include "CTEDecal.h"
#include "CTEDotaBloodImpact.h"
#include "CTEDOTAProjectile.h"
#include "CTEDOTAProjectileLoc.h"
#include "CTEDust.h"
#include "CTEDynamicLight.h"
#include "CTEEffectDispatch.h"
#include "CTEEnergySplash.h"
#include "CTEExplosion.h"
#include "CTEFizz.h"
#include "CTEFootprintDecal.h"
#include "CTEFoundryHelpers.h"
#include "CTEGaussExplosion.h"
#include "CTEGlowSprite.h"
#include "CTEImpact.h"
#include "CTEKillPlayerAttachments.h"
#include "CTELargeFunnel.h"
#include "CTEMetalSparks.h"
#include "CTEMuzzleFlash.h"
#include "CTEParticleSystem.h"
#include "CTEPhysicsProp.h"
#include "CTEPlayerDecal.h"
#include "CTEProjectedDecal.h"
#include "CTEShatterSurface.h"
#include "CTEShowLine.h"
#include "CTesla.h"
#include "CTESmoke.h"
#include "CTESparks.h"
#include "CTESprite.h"
#include "CTESpriteSpray.h"
#include "CTest_ProxyToggle_Networkable.h"
#include "CTestTraceline.h"
#include "CTEUnitAnimation.h"
#include "CTEUnitAnimationEnd.h"
#include "CTEWorldDecal.h"
#include "CTFWearableItem.h"
#include "CTriggerCamera.h"
#include "CTriggerPlayerMovement.h"
#include "CVGuiScreen.h"
#include "CWaterBullet.h"
#include "CWaterLODControl.h"
#include "CWorld.h"
#include "DustTrail.h"
#include "MovieExplosion.h"
#include "NextBotCombatCharacter.h"
#include "ParticleSmokeGrenade.h"
#include "RocketTrail.h"
#include "SmokeTrail.h"
#include "SporeExplosion.h"
#include "SporeTrail.h"

namespace dota
{

BeginNetworkClass(CAI_BaseNPC, DT_AI_BaseNPC);
   NetworkBaseClass(CBaseCombatCharacter);
   NetworkProperty(m_lifeState);
   NetworkProperty(m_bPerformAvoidance);
   NetworkProperty(m_bIsMoving);
   NetworkProperty(m_bFadeCorpse);
   NetworkProperty(m_iDeathPose);
   NetworkProperty(m_iDeathFrame);
   NetworkProperty(m_bSpeedModActive);
   NetworkProperty(m_iSpeedModRadius);
   NetworkProperty(m_iSpeedModSpeed);
   NetworkProperty(m_bImportanRagdoll);
   NetworkProperty(m_flTimePingEffect);
EndNetworkClass();

BeginNetworkStruct(DT_ServerAnimationData);
   NetworkProperty(m_flCycle);
EndNetworkStruct();

BeginNetworkClass(CBaseAnimating, DT_BaseAnimating);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_nForceBone);
   NetworkProperty(m_vecForce);
   NetworkProperty(m_nSkin);
   NetworkProperty(m_nBody);
   NetworkProperty(m_nHitboxSet);
   NetworkProperty(m_flModelScale);
   NetworkProperty(m_flPoseParameter);
   NetworkProperty(m_nSequence);
   NetworkProperty(m_flPlaybackRate);
   NetworkProperty(m_flEncodedController);
   NetworkProperty(m_bClientSideAnimation);
   NetworkProperty(m_bClientSideFrameReset);
   NetworkProperty(m_bClientSideRagdoll);
   NetworkProperty(m_nNewSequenceParity);
   NetworkProperty(m_nResetEventsParity);
   NetworkProperty(m_nMuzzleFlashParity);
   NetworkProperty(m_hLightingOrigin);
   NetworkProperty(serveranimdata);
   NetworkProperty(m_flFrozen);
EndNetworkClass();

BeginNetworkStruct(DT_Animationlayer);
   NetworkProperty(m_nSequence);
   NetworkProperty(m_flCycle);
   NetworkProperty(m_flPrevCycle);
   NetworkProperty(m_flWeight);
   NetworkProperty(m_nOrder);
EndNetworkStruct();

BeginNetworkStruct(DT_OverlayVars);
   NetworkProperty(m_AnimOverlay);
EndNetworkStruct();

BeginNetworkClass(CBaseAnimatingOverlay, DT_BaseAnimatingOverlay);
   NetworkBaseClass(CBaseAnimating);
   NetworkProperty(overlay_vars);
EndNetworkClass();

BeginNetworkStruct(DT_AttributeContainer);
   NetworkProperty(m_hOuter);
   NetworkProperty(m_ProviderType);
   NetworkProperty(m_iReapplyProvisionParity);
   NetworkProperty(m_Item);
EndNetworkStruct();

BeginNetworkStruct(DT_AttributeList);
   NetworkProperty(m_Attributes);
EndNetworkStruct();

BeginNetworkStruct(DT_ScriptCreatedAttribute);
   NetworkProperty(m_iAttributeDefinitionIndex);
   NetworkProperty(m_iRawValue32);
EndNetworkStruct();

BeginNetworkStruct(DT_ScriptCreatedItem);
   NetworkProperty(m_iItemDefinitionIndex);
   NetworkProperty(m_iEntityLevel);
   NetworkProperty(m_iItemIDHigh);
   NetworkProperty(m_iItemIDLow);
   NetworkProperty(m_iAccountID);
   NetworkProperty(m_iEntityQuality);
   NetworkProperty(m_bInitialized);
   NetworkProperty(m_AttributeList);
EndNetworkStruct();

BeginNetworkClass(CBaseAttributableItem, DT_BaseAttributableItem);
   NetworkBaseClass(CBaseAnimating);
   NetworkProperty(m_AttributeManager);
EndNetworkClass();

BeginNetworkClass(CBaseButton, DT_BaseButton);
   NetworkBaseClass(CBaseToggle);
EndNetworkClass();

BeginNetworkStruct(DT_BCCLocalPlayerExclusive);
   NetworkProperty(m_flNextAttack);
   NetworkProperty(m_hMyWeapons);
EndNetworkStruct();

BeginNetworkClass(CBaseCombatCharacter, DT_BaseCombatCharacter);
   NetworkBaseClass(CBaseFlex);
   NetworkProperty(bcc_localdata);
   NetworkProperty(m_hActiveWeapon);
EndNetworkClass();

BeginNetworkStruct(DT_LocalActiveWeaponData);
   NetworkProperty(m_flNextPrimaryAttack);
   NetworkProperty(m_flNextSecondaryAttack);
   NetworkProperty(m_nNextThinkTick);
   NetworkProperty(m_flTimeWeaponIdle);
EndNetworkStruct();

BeginNetworkStruct(DT_LocalWeaponData);
   NetworkProperty(m_iClip1);
   NetworkProperty(m_iClip2);
   NetworkProperty(m_iPrimaryAmmoType);
   NetworkProperty(m_iSecondaryAmmoType);
   NetworkProperty(m_nViewModelIndex);
EndNetworkStruct();

BeginNetworkClass(CBaseCombatWeapon, DT_BaseCombatWeapon);
   NetworkBaseClass(CBaseAnimating);
   NetworkProperty(LocalWeaponData);
   NetworkProperty(LocalActiveWeaponData);
   NetworkProperty(m_iViewModelIndex);
   NetworkProperty(m_iWorldModelIndex);
   NetworkProperty(m_iState);
   NetworkProperty(m_hOwner);
EndNetworkClass();

BeginNetworkClass(CBaseDoor, DT_BaseDoor);
   NetworkBaseClass(CBaseToggle);
   NetworkProperty(m_flWaveHeight);
EndNetworkClass();

BeginNetworkStruct(DT_AnimTimeMustBeFirst);
   NetworkProperty(m_flAnimTime);
EndNetworkStruct();

BeginNetworkStruct(DT_CollisionProperty);
   NetworkProperty(m_vecMins);
   NetworkProperty(m_vecMaxs);
   NetworkProperty(m_nSolidType);
   NetworkProperty(m_usSolidFlags);
   NetworkProperty(m_nSurroundType);
   NetworkProperty(m_triggerBloat);
   NetworkProperty(m_vecSpecifiedSurroundingMins);
   NetworkProperty(m_vecSpecifiedSurroundingMaxs);
EndNetworkStruct();

BeginNetworkClass(CBaseEntity, DT_BaseEntity);
   NetworkProperty(AnimTimeMustBeFirst);
   NetworkProperty(m_flSimulationTime);
   NetworkProperty(m_flCreateTime);
   NetworkProperty(m_ubInterpolationFrame);
   NetworkProperty(m_cellbits);
   NetworkProperty(m_cellX);
   NetworkProperty(m_cellY);
   NetworkProperty(m_cellZ);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_Collision);
   NetworkProperty(m_nRenderFX);
   NetworkProperty(m_nRenderMode);
   NetworkProperty(m_fEffects);
   NetworkProperty(m_clrRender);
   NetworkProperty(m_iTeamNum);
   NetworkProperty(m_CollisionGroup);
   NetworkProperty(m_flElasticity);
   NetworkProperty(m_flShadowCastDistance);
   NetworkProperty(m_hOwnerEntity);
   NetworkProperty(m_hEffectEntity);
   NetworkProperty(moveparent);
   NetworkProperty(m_iParentAttachment);
   NetworkProperty(m_iName);
   NetworkProperty(movetype);
   NetworkProperty(movecollide);
   NetworkProperty(m_angRotation);
   NetworkProperty(m_iTextureFrameIndex);
   NetworkProperty(m_bSimulatedEveryTick);
   NetworkProperty(m_bAnimatedEveryTick);
   NetworkProperty(m_bAlternateSorting);
   NetworkProperty(m_fadeMinDist);
   NetworkProperty(m_fadeMaxDist);
   NetworkProperty(m_flFadeScale);
   NetworkProperty(m_nMinCPULevel);
   NetworkProperty(m_nMaxCPULevel);
   NetworkProperty(m_nMinGPULevel);
   NetworkProperty(m_nMaxGPULevel);
EndNetworkClass();

BeginNetworkClass(CBaseFlex, DT_BaseFlex);
   NetworkBaseClass(CBaseAnimatingOverlay);
   NetworkProperty(m_flexWeight);
   NetworkProperty(m_blinktoggle);
   NetworkProperty(m_viewtarget);
EndNetworkClass();

BeginNetworkClass(CBaseGrenade, DT_BaseGrenade);
   NetworkBaseClass(CBaseCombatCharacter);
   NetworkProperty(m_flDamage);
   NetworkProperty(m_DmgRadius);
   NetworkProperty(m_bIsLive);
   NetworkProperty(m_hThrower);
   NetworkProperty(m_vecVelocity);
   NetworkProperty(m_fFlags);
EndNetworkClass();

BeginNetworkClass(CBaseParticleEntity, DT_BaseParticleEntity);
   NetworkBaseClass(CBaseEntity);
EndNetworkClass();

BeginNetworkStruct(DT_Local);
   NetworkProperty(m_chAreaBits);
   NetworkProperty(m_chAreaPortalBits);
   NetworkProperty(m_iHideHUD);
   NetworkProperty(m_flFOVRate);
   NetworkProperty(m_bDucked);
   NetworkProperty(m_bDucking);
   NetworkProperty(m_bInDuckJump);
   NetworkProperty(m_nDuckTimeMsecs);
   NetworkProperty(m_nDuckJumpTimeMsecs);
   NetworkProperty(m_nJumpTimeMsecs);
   NetworkProperty(m_flFallVelocity);
   NetworkProperty(m_vecPunchAngle);
   NetworkProperty(m_vecPunchAngleVel);
   NetworkProperty(m_bDrawViewmodel);
   NetworkProperty(m_bWearingSuit);
   NetworkProperty(m_bPoisoned);
   NetworkProperty(m_flStepSize);
   NetworkProperty(m_bAllowAutoMovement);
   NetworkProperty(m_skybox3d.scale);
   NetworkProperty(m_skybox3d.origin);
   NetworkProperty(m_skybox3d.area);
   NetworkProperty(m_skybox3d.fog.enable);
   NetworkProperty(m_skybox3d.fog.blend);
   NetworkProperty(m_skybox3d.fog.dirPrimary);
   NetworkProperty(m_skybox3d.fog.colorPrimary);
   NetworkProperty(m_skybox3d.fog.colorSecondary);
   NetworkProperty(m_skybox3d.fog.start);
   NetworkProperty(m_skybox3d.fog.end);
   NetworkProperty(m_skybox3d.fog.maxdensity);
   NetworkProperty(m_skybox3d.fog.HDRColorScale);
   NetworkProperty(m_audio.localSound);
   NetworkProperty(m_audio.soundscapeIndex);
   NetworkProperty(m_audio.localBits);
   NetworkProperty(m_audio.entIndex);
EndNetworkStruct();

BeginNetworkStruct(DT_LocalPlayerExclusive);
   NetworkProperty(m_Local);
   NetworkProperty(m_vecViewOffset);
   NetworkProperty(m_flFriction);
   NetworkProperty(m_iAmmo);
   NetworkProperty(m_fOnTarget);
   NetworkProperty(m_nTickBase);
   NetworkProperty(m_nNextThinkTick);
   NetworkProperty(m_hLastWeapon);
   NetworkProperty(m_vecVelocity);
   NetworkProperty(m_vecBaseVelocity);
   NetworkProperty(m_hConstraintEntity);
   NetworkProperty(m_vecConstraintCenter);
   NetworkProperty(m_flConstraintRadius);
   NetworkProperty(m_flConstraintWidth);
   NetworkProperty(m_flConstraintSpeedFactor);
   NetworkProperty(m_bConstraintPastRadius);
   NetworkProperty(m_flDeathTime);
   NetworkProperty(m_nWaterLevel);
   NetworkProperty(m_flLaggedMovementValue);
   NetworkProperty(m_hTonemapController);
EndNetworkStruct();

BeginNetworkStruct(DT_PlayerState);
   NetworkProperty(deadflag);
EndNetworkStruct();

BeginNetworkClass(CBasePlayer, DT_BasePlayer);
   NetworkBaseClass(CBaseCombatCharacter);
   NetworkProperty(pl);
   NetworkProperty(m_hVehicle);
   NetworkProperty(m_hUseEntity);
   NetworkProperty(m_hGroundEntity);
   NetworkProperty(m_iHealth);
   NetworkProperty(m_lifeState);
   NetworkProperty(m_iBonusProgress);
   NetworkProperty(m_iBonusChallenge);
   NetworkProperty(m_flMaxspeed);
   NetworkProperty(m_fFlags);
   NetworkProperty(m_iObserverMode);
   NetworkProperty(m_hObserverTarget);
   NetworkProperty(m_iFOV);
   NetworkProperty(m_iFOVStart);
   NetworkProperty(m_flFOVTime);
   NetworkProperty(m_iDefaultFOV);
   NetworkProperty(m_hZoomOwner);
   NetworkProperty(m_hViewModel);
   NetworkProperty(m_szLastPlaceName);
   NetworkProperty(m_vecLadderNormal);
   NetworkProperty(m_ladderSurfaceProps);
   NetworkProperty(m_hPostProcessCtrl);
   NetworkProperty(m_hColorCorrectionCtrl);
   NetworkProperty(m_PlayerFog.m_hCtrl);
   NetworkProperty(m_currentSCLPacked);
   NetworkProperty(m_hViewEntity);
   NetworkProperty(localdata);
EndNetworkClass();

BeginNetworkClass(CBasePropDoor, DT_BasePropDoor);
   NetworkBaseClass(CDynamicProp);
EndNetworkClass();

BeginNetworkClass(CBaseTempEntity, DT_BaseTempEntity);
EndNetworkClass();

BeginNetworkClass(CBaseToggle, DT_BaseToggle);
   NetworkBaseClass(CBaseEntity);
EndNetworkClass();

BeginNetworkClass(CBaseTrigger, DT_BaseTrigger);
   NetworkBaseClass(CBaseToggle);
   NetworkProperty(m_bClientSidePredicted);
   NetworkProperty(m_spawnflags);
EndNetworkClass();

BeginNetworkClass(CBaseViewModel, DT_BaseViewModel);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_hWeapon);
   NetworkProperty(m_nBody);
   NetworkProperty(m_nSkin);
   NetworkProperty(m_nSequence);
   NetworkProperty(m_nViewModelIndex);
   NetworkProperty(m_flPlaybackRate);
   NetworkProperty(m_fEffects);
   NetworkProperty(m_nAnimationParity);
   NetworkProperty(m_hOwner);
   NetworkProperty(m_nNewSequenceParity);
   NetworkProperty(m_nResetEventsParity);
   NetworkProperty(m_nMuzzleFlashParity);
EndNetworkClass();

BeginNetworkClass(CBeam, DT_Beam);
   NetworkProperty(m_nBeamType);
   NetworkProperty(m_nBeamFlags);
   NetworkProperty(m_nNumBeamEnts);
   NetworkProperty(m_hAttachEntity);
   NetworkProperty(m_nAttachIndex);
   NetworkProperty(m_nHaloIndex);
   NetworkProperty(m_fHaloScale);
   NetworkProperty(m_fWidth);
   NetworkProperty(m_fEndWidth);
   NetworkProperty(m_fFadeLength);
   NetworkProperty(m_fAmplitude);
   NetworkProperty(m_fStartFrame);
   NetworkProperty(m_fSpeed);
   NetworkProperty(m_nRenderFX);
   NetworkProperty(m_nRenderMode);
   NetworkProperty(m_flFrameRate);
   NetworkProperty(m_flHDRColorScale);
   NetworkProperty(m_flFrame);
   NetworkProperty(m_clrRender);
   NetworkProperty(m_nClipStyle);
   NetworkProperty(m_vecEndPos);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(moveparent);
EndNetworkClass();

BeginNetworkClass(CBeamSpotlight, DT_BeamSpotlight);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_nHaloIndex);
   NetworkProperty(m_bSpotlightOn);
   NetworkProperty(m_bHasDynamicLight);
   NetworkProperty(m_flSpotlightMaxLength);
   NetworkProperty(m_flSpotlightGoalWidth);
   NetworkProperty(m_flHDRColorScale);
   NetworkProperty(m_flRotationSpeed);
   NetworkProperty(m_nRotationAxis);
EndNetworkClass();

BeginNetworkClass(CBoneFollower, DT_BoneFollower);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_modelIndex);
   NetworkProperty(m_solidIndex);
EndNetworkClass();

BeginNetworkClass(CBreakableProp, DT_BreakableProp);
   NetworkBaseClass(CBaseAnimating);
   NetworkProperty(m_bClientPhysics);
EndNetworkClass();

BeginNetworkClass(CBreakableSurface, DT_BreakableSurface);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_nNumWide);
   NetworkProperty(m_nNumHigh);
   NetworkProperty(m_flPanelWidth);
   NetworkProperty(m_flPanelHeight);
   NetworkProperty(m_vNormal);
   NetworkProperty(m_vCorner);
   NetworkProperty(m_bIsBroken);
   NetworkProperty(m_nSurfaceType);
   NetworkProperty(m_RawPanelBitVec);
EndNetworkClass();

BeginNetworkClass(CColorCorrection, DT_ColorCorrection);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_MinFalloff);
   NetworkProperty(m_MaxFalloff);
   NetworkProperty(m_flCurWeight);
   NetworkProperty(m_flMaxWeight);
   NetworkProperty(m_flFadeInDuration);
   NetworkProperty(m_flFadeOutDuration);
   NetworkProperty(m_netlookupFilename);
   NetworkProperty(m_bEnabled);
   NetworkProperty(m_bMaster);
   NetworkProperty(m_bClientSide);
   NetworkProperty(m_bExclusive);
EndNetworkClass();

BeginNetworkClass(CColorCorrectionVolume, DT_ColorCorrectionVolume);
   NetworkProperty(m_Weight);
   NetworkProperty(m_lookupFilename);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_AbyssalUnderlord_DarkRift, DT_DOTA_Ability_AbyssalUnderlord_DarkRift);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_AbyssalUnderlord_Firestorm, DT_DOTA_Ability_AbyssalUnderlord_Firestorm);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_AbyssalUnderlord_PitOfMalice, DT_DOTA_Ability_AbyssalUnderlord_PitOfMalice);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Alchemist_AcidSpray, DT_DOTA_Ability_Alchemist_AcidSpray);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_AncientApparition_ChillingTouch, DT_DOTA_Ability_AncientApparition_ChillingTouch);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_AncientApparition_ColdFeet, DT_DOTA_Ability_AncientApparition_ColdFeet);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_AncientApparition_IceBlast, DT_DOTA_Ability_AncientApparition_RocketFlare);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_AncientApparition_IceVortex, DT_DOTA_Ability_AncientApparition_IceVortex);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_AntiMage_Blink, DT_DOTA_Ability_AntiMage_Blink);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_AntiMage_ManaVoid, DT_DOTA_Ability_AntiMage_ManaVoid);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_AttributeBonus, DT_DOTA_Ability_AttributeBonus);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Axe_BerserkersCall, DT_DOTA_Ability_Axe_BerserkersCall);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Axe_CounterHelix, DT_DOTA_Ability_Axe_CounterHelix);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Axe_CullingBlade, DT_DOTA_Ability_Axe_CullingBlade);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Bane_FiendsGrip, DT_DOTA_Ability_Bane_FiendsGrip);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Batrider_Flamebreak, DT_DOTA_Ability_Batrider_Flamebreak);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Batrider_StickyNapalm, DT_DOTA_Ability_Batrider_StickyNapalm);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Beastmaster_PrimalRoar, DT_DOTA_Ability_Beastmaster_PrimalRoar);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Bloodseeker_Bloodbath, DT_DOTA_Ability_Bloodseeker_Bloodbath);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_BountyHunter_ShurikenToss, DT_DOTA_Ability_BountyHunter_ShurikenToss);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Brewmaster_DispelMagic, DT_DOTA_Ability_Brewmaster_DispelMagic);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Brewmaster_DrunkenBrawler, DT_DOTA_Ability_Brewmaster_DrunkenBrawler);
   NetworkBaseClass(CDOTABaseAbility);
   NetworkProperty(m_iBrawlActive);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Brewmaster_DrunkenHaze, DT_DOTA_Ability_Brewmaster_DrunkenHaze);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Brewmaster_PrimalSplit, DT_DOTA_Ability_Brewmaster_PrimalSplit);
   NetworkBaseClass(CDOTABaseAbility);
   NetworkProperty(m_hPrimary);
   NetworkProperty(m_hSecondary);
   NetworkProperty(m_hTertiary);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Bristleback_QuillSpray, DT_DOTA_Ability_Bristleback_QuillSpray);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Broodmother_SpinWeb, DT_DOTA_Ability_Broodmother_SpinWeb);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Centaur_Stampede, DT_DOTA_Ability_Centaur_Stampede);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_ChaosKnight_Phantasm, DT_DOTA_Ability_ChaosKnight_Phantasm);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Chen_HandOfGod, DT_DOTA_Ability_Chen_HandOfGod);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Chen_HolyPersuasion, DT_DOTA_Ability_Chen_HolyPersuasion);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Chen_TestOfFaithTeleport, DT_DOTA_Ability_Chen_TestOfFaithTeleport);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Courier_TakeStashItems, DT_DOTA_Ability_Courier_TakeStashItems);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Courier_TransferItems, DT_DOTA_Ability_Courier_TransferItems);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_CrystalMaiden_CrystalNova, DT_DOTA_Ability_CrystalMaiden_CrystalNova);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_CrystalMaiden_FreezingField, DT_DOTA_Ability_CrystalMaiden_FreezingField);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_DarkSeer_Vacuum, DT_DOTA_Ability_DarkSeer_Vacuum);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_DataDriven, DT_DOTA_Ability_DataDriven);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Dazzle_Weave, DT_DOTA_Ability_Dazzle_Weave);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_DeathProphet_CarrionSwarm, DT_DOTA_Ability_DeathProphet_CarrionSwarm);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_DeathProphet_Silence, DT_DOTA_Ability_DeathProphet_Silence);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Disruptor_KineticField, DT_DOTA_Ability_Disruptor_KineticField);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Disruptor_StaticStorm, DT_DOTA_Ability_Disruptor_StaticStorm);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_DoomBringer_Devour, DT_DOTA_Ability_DoomBringer_Devour);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_DragonKnight_BreatheFire, DT_DOTA_Unit_Ability_DragonKnight_BreatheFire);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_DrowRanger_Silence, DT_DOTA_Ability_DrowRanger_Silence);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_DrowRanger_WaveOfSilence, DT_DOTA_Unit_Ability_DrowRanger_WaveOfSilence);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_EarthSpirit_BoulderSmash, DT_DOTA_Ability_EarthSpirit_BoulderSmash);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_EarthSpirit_GeomagneticGrip, DT_DOTA_Ability_EarthSpirit_GeomagneticGrip);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_EarthSpirit_Petrify, DT_DOTA_Ability_EarthSpirit_Petrify);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_EarthSpirit_RollingBoulder, DT_DOTA_Ability_EarthSpirit_RollingBoulder);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_EarthSpirit_StoneCaller, DT_DOTA_Ability_EarthSpirit_StoneCaller);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Elder_Titan_EarthSplitter, DT_DOTA_Unit_Ability_Elder_Titan_EarthSplitter);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_EmberSpirit_Activate_FireRemnant, DT_DOTA_Ability_EmberSpirit_Activate_FireRemnant);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_EmberSpirit_FireRemnant, DT_DOTA_Ability_EmberSpirit_FireRemnant);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_EmberSpirit_SearingChains, DT_DOTA_Ability_EmberSpirit_SearingChains);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_EmberSpirit_SleightOfFist, DT_DOTA_Ability_EmberSpirit_SleightOfFist);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Enchantress_Impetus, DT_DOTA_Ability_Enchantress_Impetus);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Enchantress_NaturesAttendants, DT_DOTA_Ability_Enchantress_NaturesAttendants);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Enchantress_Untouchable, DT_DOTA_Ability_Enchantress_Untouchable);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Enigma_BlackHole, DT_DOTA_Ability_Enigma_BlackHole);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Enigma_DemonicConversion, DT_DOTA_Ability_Enigma_DemonicConversion);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Enigma_MidnightPulse, DT_DOTA_Ability_Enigma_MidnightPulse);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_FacelessVoid_Chronosphere, DT_DOTA_Ability_FacelessVoid_Chronosphere);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_FacelessVoid_TimeWalk, DT_DOTA_Unit_Ability_FacelessVoid_TimeWalk);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Furion_ForceOfNature, DT_DOTA_Ability_Furion_ForceOfNature);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Furion_Teleportation, DT_DOTA_Ability_Furion_Teleportation);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_BlackHole, DT_DOTA_Ability_Greevil_BlackHole);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_BladeFury, DT_DOTA_Ability_Greevil_BladeFury);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Bloodlust, DT_DOTA_Ability_Greevil_Bloodlust);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_ColdSnap, DT_DOTA_Ability_Greevil_ColdSnap);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Decrepify, DT_DOTA_Ability_Greevil_Decrepify);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Diabolic_Edict, DT_DOTA_Ability_Greevil_Diabolic_Edict);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_EchoSlam, DT_DOTA_Ability_Greevil_EchoSlam);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Fatal_Bonds, DT_DOTA_Ability_Greevil_Fatal_Bonds);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_FleshGolem, DT_DOTA_Ability_Greevil_FleshGolem);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_IceWall, DT_DOTA_Ability_Greevil_IceWall);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_LagunaBlade, DT_DOTA_Ability_Greevil_LagunaBlade);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_LeechSeed, DT_DOTA_Ability_Greevil_LeechSeed);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Magic_Missile, DT_DOTA_Ability_Greevil_Magic_Missile);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Maledict, DT_DOTA_Ability_Greevil_Maledict);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_MeatHook, DT_DOTA_Ability_Greevil_MeatHook);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Miniboss_Black_BrainSap, DT_DOTA_Ability_Greevil_Miniboss_Black_BrainSap);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Miniboss_Black_Nightmare, DT_DOTA_Ability_Greevil_Miniboss_Black_Nightmare);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Miniboss_Blue_ColdFeet, DT_DOTA_Ability_Greevil_Miniboss_White_ColdFeet);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Miniboss_Blue_IceVortex, DT_DOTA_Ability_Greevil_Miniboss_White_IceVortex);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Miniboss_Green_LivingArmor, DT_DOTA_Ability_Greevil_Miniboss_Green_LivingArmor);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Miniboss_Green_Overgrowth, DT_DOTA_Ability_Greevil_Miniboss_Green_Overgrowth);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Miniboss_Orange_DragonSlave, DT_DOTA_Ability_Greevil_Miniboss_Orange_DragonSlave);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Miniboss_Orange_LightStrikeArray, DT_DOTA_Ability_Greevil_Miniboss_Orange_LightStrikeArray);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Miniboss_Purple_PlagueWard, DT_DOTA_Ability_Greevil_Miniboss_Purple_PlagueWard);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Miniboss_Purple_VenomousGale, DT_DOTA_Ability_Greevil_Miniboss_Purple_VenomousGale);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Miniboss_Red_Earthshock, DT_DOTA_Ability_Greevil_Miniboss_Red_Earthshock);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Miniboss_Red_Overpower, DT_DOTA_Ability_Greevil_Miniboss_Red_Overpower);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Miniboss_Sight, DT_DOTA_Ability_Greevil_Miniboss_Sight);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Miniboss_White_Degen_Aura, DT_DOTA_Ability_Greevil_Miniboss_White_Degen_Aura);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Miniboss_White_Purification, DT_DOTA_Ability_Greevil_Miniboss_White_Purification);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Miniboss_Yellow_IonShell, DT_DOTA_Ability_Greevil_Miniboss_Yellow_IonShell);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Miniboss_Yellow_Surge, DT_DOTA_Ability_Greevil_Miniboss_Yellow_Surge);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_NaturesAttendants, DT_DOTA_Ability_Greevil_NaturesAttendants);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_PhantomStrike, DT_DOTA_Ability_Greevil_PhantomStrike);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_PoisonNova, DT_DOTA_Ability_Greevil_PoisonNova);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Purification, DT_DOTA_Ability_Greevil_Purification);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_Rot, DT_DOTA_Ability_Greevil_Rot);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_ShadowStrike, DT_DOTA_Ability_Greevil_ShadowStrike);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_ShadowWave, DT_DOTA_Ability_Greevil_ShadowWave);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Greevil_TimeLock, DT_DOTA_Ability_Greevil_TimeLock);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Gyrocopter_Call_Down, DT_DOTA_Ability_Gyrocopter_Call_Down);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Healing_Campfire, DT_DOTA_Ability_Healing_Campfire);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Holdout_CullingBlade, DT_DOTA_Ability_Holdout_CullingBlade);
   NetworkBaseClass(CDOTA_Ability_Axe_CullingBlade);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Holdout_GladiatorsUnite, DT_DOTA_Ability_Holdout_GladiatorsUnite);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Holdout_Multishot, DT_DOTA_Ability_Holdout_Multishot);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Holdout_Omnislash, DT_DOTA_Ability_Holdout_Omnislash);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Huskar_Life_Break, DT_DOTA_Ability_Huskar_Life_Break);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Invoker_DeafeningBlast, DT_DOTA_Unit_Ability_Invoker_DeafeningBlast);
   NetworkBaseClass(CDOTA_Ability_Invoker_InvokedBase);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Invoker_EMP, DT_DOTA_Ability_Invoker_EMP);
   NetworkBaseClass(CDOTA_Ability_Invoker_InvokedBase);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Invoker_Invoke, DT_DOTA_Ability_Invoker_Invoke);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Invoker_InvokedBase, DT_DOTA_Ability_Invoker_InvokedBase);
   NetworkBaseClass(CDOTABaseAbility);
   NetworkProperty(m_nQuasLevel);
   NetworkProperty(m_nWexLevel);
   NetworkProperty(m_nExortLevel);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Invoker_SunStrike, DT_DOTA_Ability_Invoker_SunStrike);
   NetworkBaseClass(CDOTA_Ability_Invoker_InvokedBase);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Invoker_Tornado, DT_DOTA_Unit_Ability_Invoker_Tornado);
   NetworkBaseClass(CDOTA_Ability_Invoker_InvokedBase);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Jakiro_DualBreath, DT_DOTA_Unit_Ability_Jakiro_DualBreath);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Jakiro_IcePath, DT_DOTA_Unit_Ability_Jakiro_IcePath);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Jakiro_Macropyre, DT_DOTA_Unit_Ability_Jakiro_Macropyre);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Juggernaut_HealingWard, DT_DOTA_Ability_Juggernaut_HealingWard);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Juggernaut_Omnislash, DT_DOTA_Ability_Juggernaut_Omnislash);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_KeeperOfTheLight_BlindingLight, DT_DOTA_Ability_KeeperOfTheLight_BlindingLight);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_KeeperOfTheLight_Illuminate, DT_DOTA_Unit_Ability_KeeperOfTheLight_Illuminate);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_KeeperOfTheLight_Recall, DT_DOTA_Ability_KeeperOfTheLight_Recall);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Kunkka_GhostShip, DT_DOTA_Unit_Ability_Kunkka_GhostShip);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Kunkka_Tidebringer, DT_DOTA_Ability_Kunkka_Tidebringer);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Kunkka_Torrent, DT_DOTA_Ability_Kunkka_Torrent);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Legion_Commander_MomentOfCourage, DT_DOTA_Ability_Legion_Commander_MomentOfCourage);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Legion_Commander_OverwhelmingOdds, DT_DOTA_Ability_Legion_Commander_OverwhelmingOdds);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Leshrac_Diabolic_Edict, DT_DOTA_Ability_Leshrac_Diabolic_Edict);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Leshrac_Pulse_Nova, DT_DOTA_Ability_Leshrac_Pulse_Nova);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Leshrac_Split_Earth, DT_DOTA_Ability_Leshrac_Split_Earth);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Lich_ChainFrost, DT_DOTA_Ability_Lich_ChainFrost);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Lich_FrostNova, DT_DOTA_Ability_Lich_FrostNova);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Life_Stealer_Infest, DT_DOTA_Ability_Life_Stealer_Infest);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Lina_DragonSlave, DT_DOTA_Unit_Ability_Lina_DragonSlave);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Lina_LagunaBlade, DT_DOTA_Ability_Lina_LagunaBlade);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Lina_LightStrikeArray, DT_DOTA_Ability_Lina_LightStrikeArray);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Lion_FingerOfDeath, DT_DOTA_Ability_Lion_FingerOfDeath);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Lion_Impale, DT_DOTA_Unit_Ability_Lion_Impale);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Lion_ManaDrain, DT_DOTA_Ability_Lion_ManaDrain);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_LoneDruid_Rabid, DT_DOTA_Ability_LoneDruid_Rabid);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_LoneDruid_SpiritBear, DT_DOTA_Ability_LoneDruid_SpiritBear);
   NetworkBaseClass(CDOTABaseAbility);
   NetworkProperty(m_hBear);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_LoneDruid_SpiritBear_Return, DT_DOTA_Ability_LoneDruid_SpiritBear_Return);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_LoneDruid_TrueForm_BattleCry, DT_DOTA_Ability_LoneDruid_TrueForm_BattleCry);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_LoneDruid_TrueForm_Druid, DT_DOTA_Ability_LoneDruid_TrueForm_Druid);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Luna_Eclipse, DT_DOTA_Ability_Luna_Eclipse);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Luna_LunarBlessing, DT_DOTA_Ability_Luna_LunarBlessing);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Lycan_Howl, DT_DOTA_Ability_Lycan_Howl);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Lycan_SummonWolves, DT_DOTA_Ability_Lycan_SummonWolves);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Magnataur_ReversePolarity, DT_DOTA_Ability_Magnataur_ReversePolarity);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Magnataur_Shockwave, DT_DOTA_Unit_Ability_Magnataur_Shockwave);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Meepo_DividedWeStand, DT_DOTA_Ability_Meepo_DividedWeStand);
   NetworkBaseClass(CDOTABaseAbility);
   NetworkProperty(m_entPrimeDividedWeStand);
   NetworkProperty(m_entNextDividedWeStand);
   NetworkProperty(m_nWhichDividedWeStand);
   NetworkProperty(m_nNumDividedWeStand);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Meepo_Earthbind, DT_DOTA_Ability_Meepo_Earthbind);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Meepo_Poof, DT_DOTA_Ability_Meepo_Poof);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Morphling_Replicate, DT_DOTA_Ability_Morphling_Replicate);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Morphling_Waveform, DT_DOTA_Unit_Ability_Morphling_Waveform);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_NagaSiren_MirrorImage, DT_DOTA_Ability_NagaSiren_MirrorImage);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_NagaSiren_RipTide, DT_DOTA_Ability_NagaSiren_RipTide);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Necrolyte_Death_Pulse, DT_DOTA_Ability_Necrolyte_Death_Pulse);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Necrolyte_ReapersScythe, DT_DOTA_Ability_Necrolyte_ReapersScythe);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Nevermore_Requiem, DT_Ability_Nevermore_Requiem);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Nian_Apocalypse, DT_DOTA_Ability_Nian_Apocalypse);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Nian_Eruption, DT_DOTA_Ability_Nian_Eruption);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Nian_Frenzy, DT_DOTA_Ability_Nian_Frenzy);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Nian_Hurricane, DT_DOTA_Ability_Nian_Hurricane);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Nian_Roar, DT_DOTA_Ability_Nian_Roar);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Nian_Sigils, DT_DOTA_Ability_Nian_Sigils);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Nian_Tail_Swipe, DT_DOTA_Ability_Nian_Tail_Swipe);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Nian_Waterball, DT_DOTA_Ability_Nian_Waterball);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Nian_Whirlpool, DT_DOTA_Ability_Nian_Whirlpool);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Nyx_Assassin_Impale, DT_DOTA_Unit_Ability_Nyx_Assassin_Impale);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Obsidian_Destroyer_ArcaneOrb, DT_DOTA_Ability_Obsidian_Destroyer_ArcaneOrb);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Obsidian_Destroyer_AstralImprisonment, DT_DOTA_Ability_Obsidian_Destroyer_AstralImprisonment);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Obsidian_Destroyer_SanityEclipse, DT_Ability_Obsidian_Destroyer_SanityEclipse);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Ogre_Magi_Bloodlust, DT_DOTA_Ability_Ogre_Magi_Bloodlust);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Ogre_Magi_Fireblast, DT_DOTA_Ability_Ogre_Magi_Fireblast);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Ogre_Magi_Multicast, DT_DOTA_Ability_Ogre_Magi_Multicast);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Ogre_Magi_Unrefined_Fireblast, DT_DOTA_Ability_Ogre_Magi_Unrefined_Fireblast);
   NetworkBaseClass(CDOTA_Ability_Ogre_Magi_Fireblast);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Oracle_FortunesEnd, DT_DOTA_Ability_Oracle_FortunesEnd);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_PhantomAssassin_PhantomStrike, DT_DOTA_Ability_PhantomAssassin_PhantomStrike);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_PhantomLancer_Doppelwalk, DT_DOTA_Ability_PhantomLancer_Doppelwalk);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Phoenix_LaunchFireSpirit, DT_DOTA_Unit_Ability_Phoenix_LaunchFireSpirit);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Phoenix_Supernova, DT_DOTA_Ability_Phoenix_Supernova);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Puck_DreamCoil, DT_DOTA_Ability_Puck_DreamCoil);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Puck_IllusoryOrb, DT_DOTA_Unit_Ability_Puck_IllusoryOrb);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Puck_WaningRift, DT_DOTA_Ability_Puck_WaningRift);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Pudge_Dismember, DT_DOTA_Ability_Pudge_Dismember);
   NetworkBaseClass(CDOTABaseAbility);
   NetworkProperty(m_hVictim);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Pudge_MeatHook, DT_DOTA_Unit_Ability_Pudge_MeatHook);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Pugna_Decrepify, DT_DOTA_Ability_Pugna_Decrepify);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Pugna_LifeDrain, DT_DOTA_Ability_Pugna_LifeDrain);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Pugna_NetherBlast, DT_DOTA_Ability_Pugna_NetherBlast);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_QueenOfPain_Blink, DT_DOTA_Ability_QueenOfPain_Blink);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_QueenOfPain_SonicWave, DT_DOTA_Unit_Ability_QueenOfPain_SonicWave);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Rattletrap_BatteryAssault, DT_DOTA_Ability_Rattletrap_BatteryAssault);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Rattletrap_Hookshot, DT_DOTA_Ability_Rattletrap_Hookshot);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Rattletrap_RocketFlare, DT_DOTA_Ability_Rattletrap_RocketFlare);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Razor_PlasmaField, DT_DOTA_Ability_Razor_PlasmaField);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Riki_BlinkStrike, DT_DOTA_Ability_Riki_BlinkStrike);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Riki_SmokeScreen, DT_DOTA_Ability_Riki_SmokeScreen);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Roshan_Halloween_Apocalypse, DT_DOTA_Ability_Roshan_Halloween_Apocalypse);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Roshan_Halloween_Burn, DT_DOTA_Ability_Roshan_Halloween_Burn);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Roshan_Halloween_Fireball, DT_DOTA_Ability_Roshan_Halloween_Fireball);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Roshan_Toss, DT_DOTA_Ability_Roshan_Toss);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Roshan_WaveOfForce, DT_DOTA_Ability_Roshan_WaveOfForce);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Rubick_SpellSteal, DT_DOTA_Ability_Rubick_SpellSteal);
   NetworkBaseClass(CDOTABaseAbility);
   NetworkProperty(m_ActivityModifier);
   NetworkProperty(m_fStolenCastPoint);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Rubick_TelekinesisLand, DT_DOTA_Ability_Rubick_TelekinesisLand);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_SandKing_BurrowStrike, DT_DOTA_Unit_Ability_SandKing_BurrowStrike);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_SandKing_Epicenter, DT_DOTA_Ability_SandKing_Epicenter);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_SatyrTrickster_Purge, DT_DOTA_Ability_SatyrTrickster_Purge);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Shadow_Demon_Disruption, DT_DOTA_Ability_Shadow_Demon_Disruption);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Shadow_Demon_Shadow_Poison, DT_DOTA_Unit_Ability_Shadow_Demon_Shadow_Poison);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Shadow_Demon_Soul_Catcher, DT_DOTA_Ability_Shadow_Demon_Soul_Catcher);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Shredder_Chakram, DT_DOTA_Ability_Shredder_Chakram);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Shredder_TimberChain, DT_DOTA_Ability_Shredder_TimberChain);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Silencer_CurseOfTheSilent, DT_DOTA_Ability_Silencer_CurseOfTheSilent);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Silencer_GlaivesOfWisdom, DT_DOTA_Ability_Silencer_GlaivesOfWisdom);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Skywrath_Mage_Mystic_Flare, DT_DOTA_Ability_Skywrath_Mage_Mystic_Flare);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Slardar_Slithereen_Crush, DT_DOTA_Ability_Slardar_Slithereen_Crush);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Slark_EssenceShift, DT_DOTA_Ability_Slark_EssenceShift);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Sniper_Shrapnel, DT_DOTA_Ability_Sniper_Shrapnel);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_SpiritBreaker_NetherStrike, DT_DOTA_Ability_SpiritBreaker_NetherStrike);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_StormSpirit_BallLightning, DT_DOTA_Ability_StormSpirit_BallLightning);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Sven_StormBolt, DT_DOTA_Ability_Sven_StormBolt);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Techies_FocusedDetonate, DT_DOTA_Ability_Techies_FocusedDetonate);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Techies_LandMines, DT_DOTA_Ability_Techies_LandMines);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Techies_Minefield_Sign, DT_DOTA_Ability_Techies_Minefield_Sign);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Techies_RemoteMines, DT_DOTA_Ability_Techies_RemoteMines);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Techies_RemoteMines_SelfDetonate, DT_DOTA_Ability_Techies_RemoteMines_SelfDetonate);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Techies_StasisTrap, DT_DOTA_Ability_Techies_StasisTrap);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Terrorblade_Sunder, DT_DOTA_Ability_Terrorblade_Sunder);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Throw_Coal, DT_DOTA_Ability_Throw_Coal);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Throw_Snowball, DT_DOTA_Ability_Throw_Snowball);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Tidehunter_AnchorSmash, DT_DOTA_Ability_Tidehunter_AnchorSmash);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Tidehunter_Ravage, DT_DOTA_Ability_Tidehunter_Ravage);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Tiny_Avalanche, DT_DOTA_Ability_Tiny_Avalanche);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Tiny_CraggyExterior, DT_DOTA_Ability_Tiny_CraggyExterior);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Tiny_Toss, DT_DOTA_Ability_Tiny_Toss);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Treant_EyesInTheForest, DT_DOTA_Ability_Treant_EyesInTheForest);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Treant_Overgrowth, DT_DOTA_Ability_Treant_Overgrowth);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_TrollWarlord_BerserkersRage, DT_DOTA_Ability_TrollWarlord_BerserkersRage);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_TrollWarlord_WhirlingAxes_Ranged, DT_DOTA_Unit_Ability_TrollWarlord_WhirlingAxes_Ranged);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Tusk_FrozenSigil, DT_DOTA_Ability_Tusk_FrozenSigil);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Undying_Decay, DT_DOTA_Ability_Undying_Decay);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Undying_SoulRip, DT_DOTA_Ability_Undying_SoulRip);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_VengefulSpirit_Nether_Swap, DT_DOTA_Ability_VengefulSpirit_Nether_Swap);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_VengefulSpirit_WaveOfTerror, DT_DOTA_Unit_Ability_VengefulSpirit_WaveOfTerror);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Venomancer_PoisonNova, DT_DOTA_Ability_Venomancer_PoisonNova);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Venomancer_VenomousGale, DT_DOTA_Unit_Ability_Venomancer_VenomousGale);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Viper_ViperStrike, DT_DOTA_Ability_Viper_ViperStrike);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Visage_SummonFamiliars, DT_DOTA_Ability_Visage_SummonFamiliars);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Visage_SummonFamiliars_StoneForm, DT_DOTA_Ability_Visage_SummonFamiliars_StoneForm);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Warlock_RainOfChaos, DT_DOTA_Ability_Warlock_RainOfChaos);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Warlock_Shadow_Word, DT_DOTA_Ability_Warlock_Shadow_Word);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Warlock_Upheaval, DT_DOTA_Ability_Warlock_Upheaval);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Weaver_TheSwarm, DT_DOTA_Unit_Ability_Weaver_TheSwarm);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Windrunner_FocusFire, DT_DOTA_Ability_Windrunner_FocusFire);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Windrunner_Powershot, DT_DOTA_Unit_Ability_Windrunner_Powershot);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Winter_Wyvern_Arctic_Burn, DT_DOTA_Unit_Ability_Winter_Wyvern_Arctic_Burn);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Winter_Wyvern_Cold_Embrace, DT_DOTA_Unit_Ability_Winter_Wyvern_Cold_Embrace);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Winter_Wyvern_Winters_Curse, DT_DOTA_Unit_Ability_Winter_Wyvern_Winters_Curse);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Wisp_Overcharge, DT_DOTA_Ability_Wisp_Overcharge);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Wisp_Relocate, DT_DOTA_Ability_Wisp_Relocate);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Wisp_Spirits, DT_DOTA_Ability_Wisp_Spirits);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_Wisp_Tether, DT_DOTA_Ability_Wisp_Tether);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_WitchDoctor_Maledict, DT_DOTA_Ability_WitchDoctor_Maledict);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_WitchDoctor_ParalyzingCask, DT_DOTA_Ability_WitchDoctor_ParalyzingCask);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkClass(CDOTA_Ability_WitchDoctor_VoodooRestoration, DT_DOTA_Ability_WitchDoctor_VoodooRestoration);
   NetworkBaseClass(CDOTABaseAbility);
EndNetworkClass();

BeginNetworkStruct(DT_DOTA_ModifierManager);
   NetworkProperty(m_hModifierParent);
EndNetworkStruct();

BeginNetworkStruct(DT_DOTA_UnitInventory);
   NetworkProperty(m_hItems);
   NetworkProperty(m_iParity);
   NetworkProperty(m_hInventoryParent);
   NetworkProperty(m_bStashEnabled);
   NetworkProperty(m_hTransientCastItem);
EndNetworkStruct();

BeginNetworkClass(CDOTA_BaseNPC, DT_DOTA_BaseNPC);
   NetworkBaseClass(NextBotCombatCharacter);
   NetworkProperty(m_iCurrentLevel);
   NetworkProperty(m_iCustomXPValue);
   NetworkProperty(m_iIsControllableByPlayer);
   NetworkProperty(m_bIsPhantom);
   NetworkProperty(m_bIsAncient);
   NetworkProperty(m_bStolenScepter);
   NetworkProperty(m_bIsNeutralUnitType);
   NetworkProperty(m_bIsSummoned);
   NetworkProperty(m_bCanBeDominated);
   NetworkProperty(m_bHasUpgradeableAbilities);
   NetworkProperty(m_iBKBChargesUsed);
   NetworkProperty(m_iHealth);
   NetworkProperty(m_flHealthThinkRegen);
   NetworkProperty(m_iMaxHealth);
   NetworkProperty(m_iAttackCapabilities);
   NetworkProperty(m_iDayTimeVisionRange);
   NetworkProperty(m_iNightTimeVisionRange);
   NetworkProperty(m_flMana);
   NetworkProperty(m_flMaxMana);
   NetworkProperty(m_flManaThinkRegen);
   NetworkProperty(m_hAbilities);
   NetworkProperty(m_iUnitNameIndex);
   NetworkProperty(m_iDamageMin);
   NetworkProperty(m_iDamageMax);
   NetworkProperty(m_iDamageBonus);
   NetworkProperty(m_lifeState);
   NetworkProperty(m_ModifierManager);
   NetworkProperty(m_Inventory);
   NetworkProperty(m_nUnitState);
   NetworkProperty(m_iTaggedAsVisibleByTeam);
   NetworkProperty(m_iCurShop);
   NetworkProperty(m_anglediff);
   NetworkProperty(m_fFlags);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_cellX);
   NetworkProperty(m_cellY);
   NetworkProperty(m_cellZ);
   NetworkProperty(m_angRotation);
   NetworkProperty(m_NetworkActivity);
   NetworkProperty(m_NetworkSequenceIndex);
   NetworkProperty(m_iBotDebugData);
   NetworkProperty(m_hMyWearables);
   NetworkProperty(m_bShouldDoFlyHeightVisual);
   NetworkProperty(m_nTotalDamageTaken);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Additive, DT_DOTA_BaseNPC_Additive);
   NetworkBaseClass(CDOTA_BaseNPC);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Barracks, DT_DOTA_BaseNPC_Barracks);
   NetworkBaseClass(CDOTA_BaseNPC_Building);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Building, DT_DOTA_BaseNPC_Building);
   NetworkBaseClass(CDOTA_BaseNPC);
   NetworkProperty(m_nFXIndex);
   NetworkProperty(m_nFXIndexDestruction);
   NetworkProperty(m_angInitialAngles);
   NetworkProperty(m_hHeroStatueSequence);
   NetworkProperty(m_fHeroStatueCycle);
   NetworkProperty(m_iHeroStatueStatusEffectIndex);
   NetworkProperty(m_bHeroStatue);
   NetworkProperty(m_HeroStatueInscription);
   NetworkProperty(m_iHeroStatueOwnerPlayerID);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Creature, DT_DOTA_BaseNPC_Creature);
   NetworkBaseClass(CDOTA_BaseNPC_Creep);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Creep, DT_DOTA_BaseNPC_Creep);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
   NetworkProperty(m_bIsWaitingToSpawn);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Creep_Diretide, DT_DOTA_BaseNPC_Creep_Diretide);
   NetworkBaseClass(CDOTA_BaseNPC_Creep_Lane);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Creep_Lane, DT_DOTA_BaseNPC_Creep_Lane);
   NetworkBaseClass(CDOTA_BaseNPC_Creep);
   NetworkProperty(m_iHealthPercentage);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Creep_LootGreevil, DT_DOTA_BaseNPC_Creep_LootGreevil);
   NetworkBaseClass(CDOTA_BaseNPC_Creep);
   NetworkProperty(m_bIsRareLootGreevil);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Creep_Neutral, DT_DOTA_BaseNPC_Creep_Neutral);
   NetworkBaseClass(CDOTA_BaseNPC_Creep);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Creep_Siege, DT_DOTA_BaseNPC_Creep_Siege);
   NetworkBaseClass(CDOTA_BaseNPC_Creep_Lane);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Creep_Talking, DT_DOTA_BaseNPC_Creep_Talking);
   NetworkBaseClass(CDOTA_BaseNPC_Creep);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Fort, DT_DOTA_BaseNPC_Fort);
   NetworkBaseClass(CDOTA_BaseNPC_Building);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_HallofFame, DT_DOTA_BaseNPC_HallofFame);
   NetworkBaseClass(CDOTA_BaseNPC_Building);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Hero, DT_DOTA_BaseNPC_Hero);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
   NetworkProperty(m_iCurrentXP);
   NetworkProperty(m_flRespawnTime);
   NetworkProperty(m_flRespawnTimePenalty);
   NetworkProperty(m_iAbilityPoints);
   NetworkProperty(m_flStrength);
   NetworkProperty(m_flAgility);
   NetworkProperty(m_flIntellect);
   NetworkProperty(m_flStrengthTotal);
   NetworkProperty(m_flAgilityTotal);
   NetworkProperty(m_flIntellectTotal);
   NetworkProperty(m_iRecentDamage);
   NetworkProperty(m_iPlayerID);
   NetworkProperty(m_bReincarnating);
   NetworkProperty(m_flSpawnedAt);
   NetworkProperty(m_hReplicatingOtherHeroModel);
   NetworkProperty(m_hEconConsumableAbility);
   NetworkProperty(m_bCustomKillEffect);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_HoldoutTower, DT_DOTA_BaseNPC_HoldoutTower);
   NetworkBaseClass(CDOTA_BaseNPC_Tower);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_HoldoutTower_HeavySlow, DT_DOTA_BaseNPC_HoldoutTower_HeavySlow);
   NetworkBaseClass(CDOTA_BaseNPC_HoldoutTower);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_HoldoutTower_LightFast, DT_DOTA_BaseNPC_HoldoutTower_LightFast);
   NetworkBaseClass(CDOTA_BaseNPC_HoldoutTower);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_HoldoutTower_ReduceSpeed, DT_DOTA_BaseNPC_HoldoutTower_ReduceSpeed);
   NetworkBaseClass(CDOTA_BaseNPC_HoldoutTower);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Invoker_Forged_Spirit, DT_DOTA_BaseNPC_Invoker_Forged_Spirit);
   NetworkBaseClass(CDOTA_BaseNPC_Creep);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_ShadowShaman_SerpentWard, DT_DOTA_BaseNPC_ShadowShaman_SerpentWard);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Shop, DT_DOTA_BaseNPC_Shop);
   NetworkBaseClass(CDOTA_BaseNPC_Building);
   NetworkProperty(m_ShopType);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Tower, DT_DOTA_BaseNPC_Tower);
   NetworkBaseClass(CDOTA_BaseNPC_Building);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Tusk_Sigil, DT_DOTA_BaseNPC_Tusk_Sigil);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Venomancer_PlagueWard, DT_DOTA_BaseNPC_Venomancer_PlagueWard);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
EndNetworkClass();

BeginNetworkClass(CDOTA_BaseNPC_Warlock_Golem, DT_DOTA_BaseNPC_Warlock_Golem);
   NetworkBaseClass(CDOTA_BaseNPC_Creep);
EndNetworkClass();

BeginNetworkClass(CDOTA_Beastmaster_Axe, DT_DOTA_Beastmaster_Axe);
   NetworkBaseClass(CBaseAnimating);
   NetworkProperty(m_vecOrigin);
EndNetworkClass();

BeginNetworkClass(CDOTA_DataDire, DT_DOTA_DataDire);
   NetworkBaseClass(CDOTA_DataNonSpectator);
EndNetworkClass();

BeginNetworkClass(CDOTA_DataNonSpectator, DT_DOTA_DataNonSpectator);
   NetworkProperty(m_iReliableGold);
   NetworkProperty(m_iUnreliableGold);
   NetworkProperty(m_iStartingPositions);
EndNetworkClass();

BeginNetworkClass(CDOTA_DataRadiant, DT_DOTA_DataRadiant);
   NetworkBaseClass(CDOTA_DataNonSpectator);
EndNetworkClass();

BeginNetworkClass(CDOTA_DataSpectator, DT_DOTA_DataSpectator);
   NetworkProperty(m_hPrimaryRune);
   NetworkProperty(m_hSecondaryRune);
   NetworkProperty(m_iNetWorth);
EndNetworkClass();

BeginNetworkClass(CDOTA_DeathProphet_Exorcism_Spirit, DT_DOTA_DeathProphet_Exorcism_Spirit);
   NetworkBaseClass(CBaseAnimating);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_angRotation);
EndNetworkClass();

BeginNetworkClass(CDOTA_DisplacementVisibility, DT_DOTA_DisplacementVisibility);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_HiddenDisplacement);
EndNetworkClass();

BeginNetworkClass(CDOTA_Halloween_CandyBucket, DT_DOTA_Halloween_CandyBucket);
   NetworkBaseClass(CDOTA_BaseNPC);
EndNetworkClass();

BeginNetworkClass(CDOTA_Halloween_CandyBucketDire, DT_DOTA_Halloween_CandyBucketDire);
   NetworkBaseClass(CDOTA_Halloween_CandyBucket);
EndNetworkClass();

BeginNetworkClass(CDOTA_Halloween_CandyBucketRadiant, DT_DOTA_Halloween_CandyBucketRadiant);
   NetworkBaseClass(CDOTA_Halloween_CandyBucket);
EndNetworkClass();

BeginNetworkClass(CDOTA_Hero_Recorder, DT_DOTA_Hero_Recorder);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_bStartRecording);
   NetworkProperty(m_hHero);
   NetworkProperty(m_hPlayer);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item, DT_DOTA_Item);
   NetworkBaseClass(CDOTABaseAbility);
   NetworkProperty(m_bCombinable);
   NetworkProperty(m_bPermanent);
   NetworkProperty(m_bStackable);
   NetworkProperty(m_bRecipe);
   NetworkProperty(m_iSharability);
   NetworkProperty(m_bDroppable);
   NetworkProperty(m_bPurchasable);
   NetworkProperty(m_bSellable);
   NetworkProperty(m_bRequiresCharges);
   NetworkProperty(m_bKillable);
   NetworkProperty(m_bDisassemblable);
   NetworkProperty(m_bAlertable);
   NetworkProperty(m_iCurrentCharges);
   NetworkProperty(m_flPurchaseTime);
   NetworkProperty(m_iInitialCharges);
   NetworkProperty(m_hPurchaser);
   NetworkProperty(m_flAssembledTime);
   NetworkProperty(m_bPurchasedWhileDead);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Ancient_Janggo, DT_DOTA_Item_Ancient_Janggo);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Armlet, DT_DOTA_Item_Armlet);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Battlefury, DT_DOTA_Item_Battlefury);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_BlinkDagger, DT_DOTA_Item_BlinkDagger);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Bloodstone, DT_DOTA_Item_Bloodstone);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_BootsOfTravel, DT_DOTA_Item_BootsOfTravel);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Cyclone, DT_DOTA_Item_Cyclone);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Cyclone_2, DT_DOTA_Item_Cyclone_2);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_DataDriven, DT_DOTA_Item_DataDriven);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Diffusal_Blade, DT_DOTA_Item_Diffusal_Blade);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Diffusal_Blade_Level2, DT_DOTA_Item_Diffusal_Blade_Level2);
   NetworkBaseClass(CDOTA_Item_Diffusal_Blade);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_EmptyBottle, DT_DOTA_Item_EmptyBottle);
   NetworkBaseClass(CDOTA_Item);
   NetworkProperty(m_iStoredRuneType);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Ethereal_Blade, DT_DOTA_Item_Ethereal_Blade);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_ForceStaff, DT_DOTA_Item_ForceStaff);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Greevil_Blink, DT_DOTA_Item_Greevil_Blink);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Greevil_Whistle, DT_DOTA_Item_Greevil_Whistle);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Greevil_WhistleToggle, DT_DOTA_Item_Greevil_WhistleToggle);
   NetworkBaseClass(CDOTA_Item);
   NetworkProperty(m_hGreevil);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_MantaStyle, DT_DOTA_Item_MantaStyle);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Medallion_Of_Courage, DT_DOTA_Item_Medallion_Of_Courage);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Mystery_Toss, DT_DOTA_Item_Mystery_Toss);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Mystery_Vacuum, DT_DOTA_Item_Mystery_Vacuum);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Necronomicon, DT_DOTA_Item_Necronomicon);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Necronomicon_Level2, DT_DOTA_Item_Necronomicon_Level2);
   NetworkBaseClass(CDOTA_Item_Necronomicon);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Necronomicon_Level3, DT_DOTA_Item_Necronomicon_Level3);
   NetworkBaseClass(CDOTA_Item_Necronomicon);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Nian_Flag_Trap, DT_DOTA_Item_Nian_Flag_Trap);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_ObserverWard, DT_DOTA_Item_ObserverWard);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Physical, DT_DOTA_Item_Physical);
   NetworkBaseClass(CBaseAnimating);
   NetworkProperty(m_hItem);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_PlaceBuilding, DT_DOTA_Item_PlaceBuilding);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_PlaceBuilding_Free, DT_DOTA_Item_PlaceBuilding_Free);
   NetworkBaseClass(CDOTA_Item_PlaceBuilding);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_PlaceBuilding_Grid, DT_DOTA_Item_PlaceBuilding_Grid);
   NetworkBaseClass(CDOTA_Item_PlaceBuilding);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_PowerTreads, DT_DOTA_Item_PowerTreads);
   NetworkBaseClass(CDOTA_Item);
   NetworkProperty(m_iStat);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_QuellingBlade, DT_DOTA_Item_QuellingBlade);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Radiance, DT_DOTA_Item_Radiance);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Recipe_Veil_Of_Discord, DT_DOTA_Item_Recipe_Veil_Of_Discord);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Ring_Of_Basilius, DT_DOTA_Item_Ring_Of_Basilius);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_RingOfAquila, DT_DOTA_Item_RingOfAquila);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Rune, DT_DOTA_Item_Rune);
   NetworkBaseClass(CBaseAnimating);
   NetworkProperty(m_iRuneType);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_SentryWard, DT_DOTA_Item_SentryWard);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Tango, DT_DOTA_Item_Tango);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_TeleportScroll, DT_DOTA_Item_TeleportScroll);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_TranquilBoots, DT_DOTA_Item_TranquilBoots);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Urn_Of_Shadows, DT_DOTA_Item_Urn_Of_Shadows);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_Item_Veil_Of_Discord, DT_DOTA_Item_Veil_Of_Discord);
   NetworkBaseClass(CDOTA_Item);
EndNetworkClass();

BeginNetworkClass(CDOTA_NeutralSpawner, DT_DOTA_NeutralSpawner);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_Type);
EndNetworkClass();

BeginNetworkClass(CDOTA_NPC_DataDriven, DT_DOTA_NPC_DataDriven);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
EndNetworkClass();

BeginNetworkClass(CDOTA_NPC_Observer_Ward, DT_DOTA_NPC_Observer_Ward);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
EndNetworkClass();

BeginNetworkClass(CDOTA_NPC_Observer_Ward_TrueSight, DT_DOTA_NPC_Observer_Ward_TrueSight);
   NetworkBaseClass(CDOTA_NPC_Observer_Ward);
EndNetworkClass();

BeginNetworkClass(CDOTA_NPC_Techies_Minefield_Sign, DT_DOTA_NPC_Techies_Minefield_Sign);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
EndNetworkClass();

BeginNetworkClass(CDOTA_NPC_TechiesMines, DT_DOTA_NPC_TechiesMines);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
EndNetworkClass();

BeginNetworkClass(CDOTA_NPC_Treant_EyesInTheForest, DT_DOTA_NPC_Treant_EyesInTheForest);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
EndNetworkClass();

BeginNetworkClass(CDOTA_NPC_WitchDoctor_Ward, DT_DOTA_NPC_WitchDoctor_Ward);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
   NetworkProperty(m_nTargetType);
EndNetworkClass();

BeginNetworkClass(CDOTA_PhantomAssassin_Gravestone, DT_DOTA_PhantomAssassin_Gravestone);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
EndNetworkClass();

BeginNetworkStruct(DT_DireData);
   NetworkProperty(m_iReliableGoldDire);
   NetworkProperty(m_iUnreliableGoldDire);
   NetworkProperty(m_bWorldTreeStateDire);
EndNetworkStruct();

BeginNetworkStruct(DT_EndScoreAndSpectatorStats);
   NetworkProperty(m_iTotalEarnedGold);
   NetworkProperty(m_iTotalEarnedXP);
   NetworkProperty(m_bWorldTreeStateSpectator);
EndNetworkStruct();

BeginNetworkStruct(DT_RadiantData);
   NetworkProperty(m_iReliableGoldRadiant);
   NetworkProperty(m_iUnreliableGoldRadiant);
   NetworkProperty(m_bWorldTreeStateRadiant);
EndNetworkStruct();

BeginNetworkClass(CDOTA_PlayerResource, DT_DOTA_PlayerResource);
   NetworkProperty(m_iszPlayerNames);
   NetworkProperty(m_iszSelectedHero);
   NetworkProperty(m_nSelectedHeroID);
   NetworkProperty(m_iPlayerTeams);
   NetworkProperty(m_iKills);
   NetworkProperty(m_iAssists);
   NetworkProperty(m_iDeaths);
   NetworkProperty(m_iStreak);
   NetworkProperty(m_iRespawnSeconds);
   NetworkProperty(m_iLastBuybackTime);
   NetworkProperty(m_iLevel);
   NetworkProperty(m_iDenyCount);
   NetworkProperty(m_iLastHitCount);
   NetworkProperty(m_iLastHitStreak);
   NetworkProperty(m_iLastHitMultikill);
   NetworkProperty(m_iNearbyCreepDeathCount);
   NetworkProperty(m_hSelectedHero);
   NetworkProperty(m_bFullyJoinedServer);
   NetworkProperty(m_bFakeClient);
   NetworkProperty(m_iPlayerSteamIDs);
   NetworkProperty(m_bIsBroadcaster);
   NetworkProperty(m_iBroadcasterChannel);
   NetworkProperty(m_iBroadcasterChannelSlot);
   NetworkProperty(m_iszBroadcasterChannelDescription);
   NetworkProperty(m_iszBroadcasterChannelCountryCode);
   NetworkProperty(m_iszBroadcasterChannelLanguageCode);
   NetworkProperty(m_iConnectionState);
   NetworkProperty(m_bAFK);
   NetworkProperty(m_bVoiceChatBanned);
   NetworkProperty(m_iTimedRewardDrops);
   NetworkProperty(m_iTimedRewardCrates);
   NetworkProperty(m_nPossibleHeroSelection);
   NetworkProperty(m_nSuggestedHeroes);
   NetworkProperty(m_iMetaLevel);
   NetworkProperty(m_iMetaExperience);
   NetworkProperty(m_iMetaExperienceAwarded);
   NetworkProperty(m_bHasRepicked);
   NetworkProperty(m_bHasRandomed);
   NetworkProperty(m_UnitShareMasks);
   NetworkProperty(m_bBattleBonusActive);
   NetworkProperty(m_iBattleBonusRate);
   NetworkProperty(m_flBuybackCooldownTime);
   NetworkProperty(m_flBuybackGoldLimitTime);
   NetworkProperty(m_flBuybackCostTime);
   NetworkProperty(m_iCustomBuybackCost);
   NetworkProperty(m_flCustomBuybackCooldown);
   NetworkProperty(m_iGoldBagsCollected);
   NetworkProperty(m_fStuns);
   NetworkProperty(m_fHealing);
   NetworkProperty(m_iTowerKills);
   NetworkProperty(m_iRoshanKills);
   NetworkProperty(m_iEventPoints);
   NetworkProperty(m_iEventPremiumPoints);
   NetworkProperty(m_hCameraTarget);
   NetworkProperty(m_iEventRanks);
   NetworkProperty(m_unCompendiumLevel);
   NetworkProperty(m_bIsBroadcasterChannelCameraman);
   NetworkProperty(m_bHasPredictedVictory);
   NetworkProperty(m_bReservedHeroOnly);
   NetworkProperty(m_bQualifiesForPAContractReward);
   NetworkProperty(m_iTimedRewardEvents);
   NetworkProperty(EndScoreAndSpectatorStats);
   NetworkProperty(RadiantOnlyData);
   NetworkProperty(DireOnlyData);
EndNetworkClass();

BeginNetworkClass(CDOTA_RoshanSpawner, DT_DOTA_RoshanSpawner);
   NetworkBaseClass(CBaseEntity);
EndNetworkClass();

BeginNetworkClass(CDOTA_TempTree, DT_DOTA_TempTree);
   NetworkBaseClass(CBaseAnimating);
EndNetworkClass();

BeginNetworkClass(CDOTA_Tiny_ScepterTree, DT_DOTA_Tiny_ScepterTree);
   NetworkBaseClass(CDOTAWearableItem);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Announcer, DT_DOTA_Unit_Announcer);
   NetworkBaseClass(CDOTA_BaseNPC);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Announcer_Killing_Spree, DT_DOTA_Unit_Announcer_Killing_Spree);
   NetworkBaseClass(CDOTA_BaseNPC);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Brewmaster_PrimalEarth, DT_DOTA_Unit_Brewmaster_PrimalEarth);
   NetworkBaseClass(CDOTA_BaseNPC_Creep);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Brewmaster_PrimalFire, DT_DOTA_Unit_Brewmaster_PrimalFire);
   NetworkBaseClass(CDOTA_BaseNPC_Creep);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Brewmaster_PrimalStorm, DT_DOTA_Unit_Brewmaster_PrimalStorm);
   NetworkBaseClass(CDOTA_BaseNPC_Creep);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Broodmother_Spiderling, DT_DOTA_Unit_Broodmother_Spiderling);
   NetworkBaseClass(CDOTA_BaseNPC_Creep_Talking);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Broodmother_Web, DT_DOTA_Unit_Broodmother_Web);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Courier, DT_DOTA_Unit_Courier);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
   NetworkProperty(m_flRespawnTime);
   NetworkProperty(m_nCourierState);
   NetworkProperty(m_hCourierStateEntity);
   NetworkProperty(m_bFlyingCourier);
   NetworkProperty(m_iUnusualColor);
   NetworkProperty(m_iUnusualParticleSystem);
   NetworkProperty(m_hCourierWearable);
   NetworkProperty(m_bMorphEnabled);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Earth_Spirit_Stone, DT_DOTA_Unit_Earth_Spirit_Stone);
   NetworkBaseClass(CDOTA_BaseNPC);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Elder_Titan_AncestralSpirit, DT_DOTA_Unit_Elder_Titan_AncestralSpirit);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Fountain, DT_DOTA_Unit_Fountain);
   NetworkBaseClass(CDOTA_BaseNPC_Building);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Greevil, DT_DOTA_Unit_Greevil);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
   NetworkProperty(m_flRespawnTime);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Abaddon, DT_DOTA_Unit_Hero_Abaddon);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_AbyssalUnderlord, DT_DOTA_Unit_Hero_AbyssalUnderlord);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Alchemist, DT_DOTA_Unit_Hero_Alchemist);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_AncientApparition, DT_DOTA_Unit_Hero_AncientApparition);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_AntiMage, DT_DOTA_Unit_Hero_AntiMage);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Axe, DT_DOTA_Unit_Hero_Axe);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Bane, DT_DOTA_Unit_Hero_Bane);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Batrider, DT_DOTA_Unit_Hero_Batrider);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Beastmaster, DT_DOTA_Unit_Hero_Beastmaster);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Beastmaster_Beasts, DT_DOTA_Unit_Hero_Beastmaster_Beasts);
   NetworkBaseClass(CDOTA_BaseNPC_Creep);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Beastmaster_Boar, DT_DOTA_Unit_Hero_Beastmaster_Boar);
   NetworkBaseClass(CDOTA_Unit_Hero_Beastmaster_Beasts);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Beastmaster_Hawk, DT_DOTA_Unit_Hero_Beastmaster_Hawk);
   NetworkBaseClass(CDOTA_Unit_Hero_Beastmaster_Beasts);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Bloodseeker, DT_DOTA_Unit_Hero_Bloodseeker);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_BountyHunter, DT_DOTA_Unit_Hero_BountyHunter);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Brewmaster, DT_DOTA_Unit_Hero_Brewmaster);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Bristleback, DT_DOTA_Unit_Hero_Bristleback);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Broodmother, DT_DOTA_Unit_Hero_Broodmother);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Centaur, DT_DOTA_Unit_Hero_Centaur);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_ChaosKnight, DT_DOTA_Unit_Hero_ChaosKnight);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Chen, DT_DOTA_Unit_Hero_Chen);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Clinkz, DT_DOTA_Unit_Hero_Clinkz);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_CrystalMaiden, DT_DOTA_Unit_Hero_CrystalMaiden);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_DarkSeer, DT_DOTA_Unit_Hero_DarkSeer);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Dazzle, DT_DOTA_Unit_Hero_Dazzle);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_DeathProphet, DT_DOTA_Unit_Hero_DeathProphet);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Disruptor, DT_DOTA_Unit_Hero_Disruptor);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_DoomBringer, DT_DOTA_Unit_Hero_DoomBringer);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_DragonKnight, DT_DOTA_Unit_Hero_DragonKnight);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_DrowRanger, DT_DOTA_Unit_Hero_DrowRanger);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Earthshaker, DT_DOTA_Unit_Hero_Earthshaker);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_EarthSpirit, DT_DOTA_Unit_Hero_EarthSpirit);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Elder_Titan, DT_DOTA_Unit_Hero_Elder_Titan);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_EmberSpirit, DT_DOTA_Unit_Hero_EmberSpirit);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Enchantress, DT_DOTA_Unit_Hero_Enchantress);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Enigma, DT_DOTA_Unit_Hero_Enigma);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_FacelessVoid, DT_DOTA_Unit_Hero_FacelessVoid);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Furion, DT_DOTA_Unit_Hero_Furion);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Gyrocopter, DT_DOTA_Unit_Hero_Gyrocopter);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Huskar, DT_DOTA_Unit_Hero_Huskar);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Invoker, DT_DOTA_Unit_Hero_Invoker);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Jakiro, DT_DOTA_Unit_Hero_Jakiro);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Juggernaut, DT_DOTA_Unit_Hero_Juggernaut);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_KeeperOfTheLight, DT_DOTA_Unit_Hero_KeeperOfTheLight);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Kunkka, DT_DOTA_Unit_Hero_Kunkka);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Legion_Commander, DT_DOTA_Unit_Hero_Legion_Commander);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Leshrac, DT_DOTA_Unit_Hero_Leshrac);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Lich, DT_DOTA_Unit_Hero_Lich);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Life_Stealer, DT_DOTA_Unit_Hero_Life_Stealer);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Lina, DT_DOTA_Unit_Hero_Lina);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Lion, DT_DOTA_Unit_Hero_Lion);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_LoneDruid, DT_DOTA_Unit_Hero_LoneDruid);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Luna, DT_DOTA_Unit_Hero_Luna);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Lycan, DT_DOTA_Unit_Hero_Lycan);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Magnataur, DT_DOTA_Unit_Hero_Magnataur);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Medusa, DT_DOTA_Unit_Hero_Medusa);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Meepo, DT_DOTA_Unit_Hero_Meepo);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
   NetworkProperty(m_nWhichMeepo);
   NetworkProperty(m_bIsIllusion);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Mirana, DT_DOTA_Unit_Hero_Mirana);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Morphling, DT_DOTA_Unit_Hero_Morphling);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Naga_Siren, DT_DOTA_Unit_Hero_Naga_Siren);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Necrolyte, DT_DOTA_Unit_Hero_Necrolyte);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Nevermore, DT_DOTA_Unit_Hero_Nevermore);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_NightStalker, DT_DOTA_Unit_Hero_NightStalker);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Nyx_Assassin, DT_DOTA_Unit_Hero_Nyx_Assassin);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Obsidian_Destroyer, DT_DOTA_Unit_Hero_Obsidian_Destroyer);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Ogre_Magi, DT_DOTA_Unit_Hero_Ogre_Magi);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Omniknight, DT_DOTA_Unit_Hero_Omniknight);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Oracle, DT_DOTA_Unit_Hero_Oracle);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_PhantomAssassin, DT_DOTA_Unit_Hero_PhantomAssassin);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
   NetworkProperty(m_nArcanaLevel);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_PhantomLancer, DT_DOTA_Unit_Hero_PhantomLancer);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Phoenix, DT_DOTA_Unit_Hero_Phoenix);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Puck, DT_DOTA_Unit_Hero_Puck);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Pudge, DT_DOTA_Unit_Hero_Pudge);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Pugna, DT_DOTA_Unit_Hero_Pugna);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_QueenOfPain, DT_DOTA_Unit_Hero_QueenOfPain);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Rattletrap, DT_DOTA_Unit_Hero_Rattletrap);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Razor, DT_DOTA_Unit_Hero_Razor);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Riki, DT_DOTA_Unit_Hero_Riki);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Rubick, DT_DOTA_Unit_Hero_Rubick);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_SandKing, DT_DOTA_Unit_Hero_SandKing);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Shadow_Demon, DT_DOTA_Unit_Hero_Shadow_Demon);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_ShadowShaman, DT_DOTA_Unit_Hero_ShadowShaman);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Shredder, DT_DOTA_Unit_Hero_Shredder);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Silencer, DT_DOTA_Unit_Hero_Silencer);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_SkeletonKing, DT_DOTA_Unit_Hero_SkeletonKing);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Skywrath_Mage, DT_DOTA_Unit_Hero_Skywrath_Mage);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Slardar, DT_DOTA_Unit_Hero_Slardar);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Slark, DT_DOTA_Unit_Hero_Slark);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Sniper, DT_DOTA_Unit_Hero_Sniper);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Spectre, DT_DOTA_Unit_Hero_Spectre);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_SpiritBreaker, DT_DOTA_Unit_Hero_SpiritBreaker);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_StormSpirit, DT_DOTA_Unit_Hero_StormSpirit);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Sven, DT_DOTA_Unit_Hero_Sven);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Techies, DT_DOTA_Unit_Hero_Techies);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
   NetworkProperty(m_bHasArcana);
   NetworkProperty(m_nArcanaColor);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_TemplarAssassin, DT_DOTA_Unit_Hero_TemplarAssassin);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Terrorblade, DT_DOTA_Unit_Hero_Terrorblade);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
   NetworkProperty(m_nArcanaColor);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Tidehunter, DT_DOTA_Unit_Hero_Tidehunter);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Tinker, DT_DOTA_Unit_Hero_Tinker);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Tiny, DT_DOTA_Unit_Hero_Tiny);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Treant, DT_DOTA_Unit_Hero_Treant);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_TrollWarlord, DT_DOTA_Unit_Hero_TrollWarlord);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Tusk, DT_DOTA_Unit_Hero_Tusk);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Undying, DT_DOTA_Unit_Hero_Undying);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Ursa, DT_DOTA_Unit_Hero_Ursa);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_VengefulSpirit, DT_DOTA_Unit_Hero_VengefulSpirit);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Venomancer, DT_DOTA_Unit_Hero_Venomancer);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Viper, DT_DOTA_Unit_Hero_Viper);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Visage, DT_DOTA_Unit_Hero_Visage);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Warlock, DT_DOTA_Unit_Hero_Warlock);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Weaver, DT_DOTA_Unit_Hero_Weaver);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Windrunner, DT_DOTA_Unit_Hero_Windrunner);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Winter_Wyvern, DT_DOTA_Unit_Hero_Winter_Wyvern);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Wisp, DT_DOTA_Unit_Hero_Wisp);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_WitchDoctor, DT_DOTA_Unit_Hero_WitchDoctor);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Hero_Zuus, DT_DOTA_Unit_Hero_Zuus);
   NetworkBaseClass(CDOTA_BaseNPC_Hero);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_LoopingSound, DT_DOTA_Unit_LoopingSound);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
   NetworkProperty(m_pszNetworkedSoundLoop);
   NetworkProperty(m_nLoopingSoundParity);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Nian, DT_DOTA_Unit_Nian);
   NetworkBaseClass(CDOTA_BaseNPC_Creature);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Roquelaire, DT_DOTA_Unit_Roquelaire);
   NetworkBaseClass(CDOTA_BaseNPC_Creep_Talking);
   NetworkProperty(m_flFlyHeight);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Roshan, DT_DOTA_Unit_Roshan);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Roshan_Halloween, DT_DOTA_Unit_Roshan_Halloween);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
   NetworkProperty(m_hChosenTarget);
   NetworkProperty(m_iHealth);
   NetworkProperty(m_iMaxHealth);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_SpiritBear, DT_DOTA_Unit_SpiritBear);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_TargetDummy, DT_DOTA_Unit_TargetDummy);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
   NetworkProperty(m_flDamageTaken);
   NetworkProperty(m_flStartDamageTime);
   NetworkProperty(m_flLastDamageTime);
   NetworkProperty(m_flLastHit);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Undying_Tombstone, DT_DOTA_Unit_Undying_Tombstone);
   NetworkBaseClass(CDOTA_BaseNPC_Additive);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_Undying_Zombie, DT_DOTA_Unit_Undying_Zombie);
   NetworkBaseClass(CDOTA_BaseNPC_Creep);
EndNetworkClass();

BeginNetworkClass(CDOTA_Unit_VisageFamiliar, DT_DOTA_Unit_VisageFamiliar);
   NetworkBaseClass(CDOTA_BaseNPC_Creep);
EndNetworkClass();

BeginNetworkClass(CDOTA_Wisp_Spirit, DT_DOTA_Wisp_Spirit);
   NetworkBaseClass(CDOTA_BaseNPC);
   NetworkProperty(m_vecOrigin);
EndNetworkClass();

BeginNetworkClass(CDOTABaseAbility, DT_DOTABaseAbility);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_bHidden);
   NetworkProperty(m_bActivated);
   NetworkProperty(m_iDirtyButtons);
   NetworkProperty(m_iLevel);
   NetworkProperty(m_bToggleState);
   NetworkProperty(m_bInAbilityPhase);
   NetworkProperty(m_fCooldown);
   NetworkProperty(m_iCastRange);
   NetworkProperty(m_flCooldownLength);
   NetworkProperty(m_iManaCost);
   NetworkProperty(m_bAutoCastState);
   NetworkProperty(m_flChannelStartTime);
   NetworkProperty(m_flOverrideCastPoint);
   NetworkProperty(m_bInIndefiniteCooldown);
EndNetworkClass();

BeginNetworkClass(CDOTABaseGameMode, DT_DOTABaseGameMode);
   NetworkProperty(m_bAlwaysShowPlayerInventory);
   NetworkProperty(m_bGoldSoundDisabled);
   NetworkProperty(m_bRecommendedItemsDisabled);
   NetworkProperty(m_bFogOfWarDisabled);
   NetworkProperty(m_bUseCustomBuybackCost);
   NetworkProperty(m_bUseCustomBuybackCooldown);
   NetworkProperty(m_bBuybackEnabled);
   NetworkProperty(m_flCameraDistanceOverride);
   NetworkProperty(m_hOverrideSelectionEntity);
   NetworkProperty(m_bTopBarTeamValuesOverride);
   NetworkProperty(m_bTopBarTeamValuesVisible);
   NetworkProperty(m_nTeamGoodGuysTopBarValue);
   NetworkProperty(m_nTeamBadGuysTopBarValue);
   NetworkProperty(m_bUseCustomHeroLevels);
   NetworkProperty(m_nCustomHeroMaxLevel);
   NetworkProperty(m_nCustomXPRequiredToReachNextLevel);
EndNetworkClass();

BeginNetworkClass(CDOTACameraBounds, DT_DOTACameraBounds);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_vecBoundsMin);
   NetworkProperty(m_vecBoundsMax);
EndNetworkClass();

BeginNetworkClass(CDOTAFogOfWarTempViewers, DT_DOTAFogOfWarTempViewers);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_bTempViewers);
EndNetworkClass();

BeginNetworkClass(CDOTAFogOfWarWasVisible, DT_DOTAFogOfWarWasVisible);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_bWasVisible);
EndNetworkClass();

BeginNetworkStruct(DT_DOTA_GameManager);
   NetworkProperty(m_StableHeroAvailable);
   NetworkProperty(m_CurrentHeroAvailable);
   NetworkProperty(m_CulledHeroes);
EndNetworkStruct();

BeginNetworkClass(CDOTAGameManagerProxy, DT_DOTAGameManagerProxy);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(dota_gamemanager_data);
EndNetworkClass();

BeginNetworkStruct(DT_DOTAGamerules);
   NetworkProperty(m_iNetTimeOfDay);
   NetworkProperty(m_fGameTime);
   NetworkProperty(m_bGamePaused);
   NetworkProperty(m_ItemStockInfoGood);
   NetworkProperty(m_ItemStockInfoBad);
   NetworkProperty(m_AssassinMiniGameNetData);
   NetworkProperty(m_hGoodGuyFountain);
   NetworkProperty(m_hBadGuyFountain);
   NetworkProperty(m_hGoodGuyShop);
   NetworkProperty(m_hBadGuyShop);
   NetworkProperty(m_hSideShop1);
   NetworkProperty(m_hSideShop2);
   NetworkProperty(m_hSecretShop1);
   NetworkProperty(m_hSecretShop2);
   NetworkProperty(m_hGoodGuyFort);
   NetworkProperty(m_hBadGuyFort);
   NetworkProperty(m_hAnnouncerGood);
   NetworkProperty(m_hAnnouncerBad);
   NetworkProperty(m_hAnnouncerSpectator);
   NetworkProperty(m_hAnnouncerGood_KillingSpree);
   NetworkProperty(m_hAnnouncerBad_KillingSpree);
   NetworkProperty(m_hAnnouncerSpectator_KillingSpree);
   NetworkProperty(m_nGameState);
   NetworkProperty(m_flStateTransitionTime);
   NetworkProperty(m_iGameMode);
   NetworkProperty(m_nHeroPickState);
   NetworkProperty(m_iCMModePickBanOrder);
   NetworkProperty(m_iCDModePickBanOrder);
   NetworkProperty(m_flHeroPickStateTransitionTime);
   NetworkProperty(m_fExtraTimeRemaining);
   NetworkProperty(m_iPlayerIDsInControl);
   NetworkProperty(m_bSuggestedGoodHeroes);
   NetworkProperty(m_bSuggestedBadHeroes);
   NetworkProperty(m_iCaptainPlayerIDs);
   NetworkProperty(m_BannedHeroes);
   NetworkProperty(m_SelectedHeroes);
   NetworkProperty(m_AvailableHerosPerPlayer);
   NetworkProperty(m_UnlockedHeroesPerPlayer);
   NetworkProperty(m_LockedHeroesPerPlayer);
   NetworkProperty(m_iActiveTeam);
   NetworkProperty(m_iStartingTeam);
   NetworkProperty(m_iMiscHeroPickCounter);
   NetworkProperty(m_flPreGameStartTime);
   NetworkProperty(m_flGameStartTime);
   NetworkProperty(m_flGameEndTime);
   NetworkProperty(m_flGameLoadTime);
   NetworkProperty(m_fGoodGlyphCooldown);
   NetworkProperty(m_fBadGlyphCooldown);
   NetworkProperty(m_bIsNightstalkerNight);
   NetworkProperty(m_bIsTemporaryNight);
   NetworkProperty(m_nGameWinner);
   NetworkProperty(m_nLoadedPlayers);
   NetworkProperty(m_nExpectedPlayers);
   NetworkProperty(m_iMinimapDebugGridState);
   NetworkProperty(m_iFoWFrameNumber);
   NetworkProperty(m_bIsInItemTestingMode);
   NetworkProperty(m_bIsInCinematicMode);
   NetworkProperty(m_bItemWhiteList);
   NetworkProperty(m_hEndGameCinematicEntity);
   NetworkProperty(m_bIsStableMode);
   NetworkProperty(m_unMatchID64);
   NetworkProperty(m_BotDebugPushLane);
   NetworkProperty(m_BotDebugDefendLane);
   NetworkProperty(m_BotDebugFarmLane);
   NetworkProperty(m_BotDebugRoam);
   NetworkProperty(m_hBotDebugRoamTarget);
   NetworkProperty(m_BotDebugRoshan);
   NetworkProperty(m_lobbyLeagueID);
   NetworkProperty(m_lobbyGameName);
   NetworkProperty(m_bMatchSignoutComplete);
   NetworkProperty(m_bWhiteListEnabled);
   NetworkProperty(m_bHeroRespawnEnabled);
   NetworkProperty(m_nLastHitUIMode);
   NetworkProperty(m_bHUDTimerTutorialMode);
   NetworkProperty(m_unFanfareGoodGuys);
   NetworkProperty(m_unFanfareBadGuys);
   NetworkProperty(m_nSeriesType);
   NetworkProperty(m_nRadiantSeriesWins);
   NetworkProperty(m_nDireSeriesWins);
   NetworkProperty(m_nHalloweenTransitionState);
   NetworkProperty(m_flHalloweenRoshanLifetime);
   NetworkProperty(m_bTier3TowerDestroyed);
   NetworkProperty(m_iCustomGameScore);
   NetworkProperty(m_iPauseTeam);
   NetworkProperty(m_nGGTeam);
   NetworkProperty(m_flGGEndsAtTime);
   NetworkProperty(m_hGameModeEntity);
   NetworkProperty(m_nHalloweenRoshanLevel);
   NetworkProperty(m_flHalloweenRoshanRoundStartTime);
   NetworkProperty(m_nHalloweenRoshanRemainingHealth);
   NetworkProperty(m_nCustomGameDifficulty);
   NetworkProperty(m_hOverlayHealthBarUnit);
   NetworkProperty(m_nOverlayHealthBarType);
   NetworkProperty(m_bUseUniversalShopMode);
   NetworkProperty(m_bUseCustomHeroXPValue);
   NetworkProperty(m_bUseBaseGoldBountyOnHeroes);
   NetworkProperty(m_bSameHeroSelectionEnabled);
   NetworkProperty(m_nHeroMinimapIconSize);
   NetworkProperty(m_flCreepMinimapIconScale);
   NetworkProperty(m_flRuneMinimapIconScale);
   NetworkProperty(m_AbilityDraftAbilities);
   NetworkProperty(m_nAbilityDraftPlayerTracker);
   NetworkProperty(m_nAbilityDraftRoundNumber);
   NetworkProperty(m_nAbilityDraftAdvanceSteps);
   NetworkProperty(m_nAbilityDraftPhase);
   NetworkProperty(m_nAbilityDraftHeroesChosen);
   NetworkProperty(m_nARDMHeroesRemaining);
   NetworkProperty(m_nARDMHeroesPrecachedPercent);
   NetworkProperty(m_nAllDraftPhase);
   NetworkProperty(m_bAllDraftRadiantFirst);
   NetworkProperty(m_bHasHeroStatueLiked);
EndNetworkStruct();

BeginNetworkStruct(DT_DOTA_AbilityDraftAbilityState);
   NetworkProperty(m_unAbilityIndex);
   NetworkProperty(m_unPlayerID);
   NetworkProperty(m_unAbilityPlayerSlot);
EndNetworkStruct();

BeginNetworkStruct(DT_DOTA_AssassinMinigameNetworkState);
   NetworkProperty(nAssassinState);
   NetworkProperty(nVictimHeroID);
EndNetworkStruct();

BeginNetworkStruct(DT_DOTA_ItemStockInfo);
   NetworkProperty(usItemIndex);
   NetworkProperty(fStockDuration);
   NetworkProperty(fStockTime);
   NetworkProperty(iStockCount);
   NetworkProperty(iMaxCount);
EndNetworkStruct();

BeginNetworkClass(CDOTAGamerulesProxy, DT_DOTAGamerulesProxy);
   NetworkBaseClass(CGameRulesProxy);
   NetworkProperty(dota_gamerules_data);
EndNetworkClass();

BeginNetworkClass(CDOTAHoldoutNetworker, DT_DOTA_HoldoutNetworker);
   NetworkProperty(m_flPrepTimeLeft);
   NetworkProperty(m_nWaveEnemyCount);
   NetworkProperty(m_nCurrentEnemyCount);
   NetworkProperty(m_nNumberOfRounds);
   NetworkProperty(m_nRoundNumber);
   NetworkProperty(m_bIsHeroRespawnEnabled);
   NetworkProperty(m_nGoldBagsExpired);
EndNetworkClass();

BeginNetworkClass(CDOTAMinimapBoundary, DT_DOTAMinimapBoundary);
   NetworkBaseClass(CBaseEntity);
EndNetworkClass();

BeginNetworkStruct(DT_ClientQuickBuyItemState);
   NetworkProperty(nItemType);
   NetworkProperty(bPurchasable);
EndNetworkStruct();

BeginNetworkStruct(DT_DOTACommentatorTable);
   NetworkProperty(m_cellbits);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_cellX);
   NetworkProperty(m_cellY);
   NetworkProperty(m_cellZ);
   NetworkProperty(m_iSpectatorClickBehavior);
   NetworkProperty(m_iCursor);
   NetworkProperty(m_flAspectRatio);
   NetworkProperty(m_hSpectatorQueryUnit);
   NetworkProperty(m_iStatsPanel);
   NetworkProperty(m_iShopPanel);
   NetworkProperty(m_iShopViewMode);
   NetworkProperty(m_iStatsDropdownCategory);
   NetworkProperty(m_iStatsDropdownSort);
   NetworkProperty(m_szShopString);
   NetworkProperty(m_vecClientQuickBuyState);
   NetworkProperty(m_iQuickBuyParity);
   NetworkProperty(m_bInShowCaseMode);
   NetworkProperty(m_flCameraZoomAmount);
   NetworkProperty(m_iHighPriorityScore);
EndNetworkStruct();

BeginNetworkStruct(DT_DOTACompendiumData);
   NetworkProperty(m_iTotalEarnedGold);
   NetworkProperty(m_iTotalEarnedXP);
EndNetworkStruct();

BeginNetworkClass(CDOTAPlayer, DT_DOTAPlayer);
   NetworkBaseClass(CBasePlayer);
   NetworkProperty(m_nTickBase);
   NetworkProperty(m_iPlayerID);
   NetworkProperty(m_nCachedCoachedTeam);
   NetworkProperty(m_vecStartingPosition);
   NetworkProperty(m_hAssignedHero);
   NetworkProperty(m_iMusicStatus);
   NetworkProperty(m_flMusicOperatorVals);
   NetworkProperty(m_iMusicOperatorVals);
   NetworkProperty(m_hKillCamUnit);
   NetworkProperty(dota_commentator_table);
   NetworkProperty(dota_compendium_data);
   NetworkProperty(m_bUsingCameraMan);
   NetworkProperty(m_bUsingAssistedCameraOperator);
EndNetworkClass();

BeginNetworkClass(CDOTAPropCustomTexture, DT_DOTAPropCustomTexture);
   NetworkBaseClass(CDynamicProp);
EndNetworkClass();

BeginNetworkClass(CDotaQuest, DT_DotaQuest);
   NetworkProperty(m_pszQuestTitle);
   NetworkProperty(m_pszQuestText);
   NetworkProperty(m_nQuestType);
   NetworkProperty(m_hSubquests);
   NetworkProperty(m_bHidden);
   NetworkProperty(m_bCompleted);
   NetworkProperty(m_bWinIfCompleted);
   NetworkProperty(m_bLoseIfCompleted);
   NetworkProperty(m_pszGameEndText);
   NetworkProperty(m_pnTextReplaceValuesCDotaQuest);
   NetworkProperty(m_pszTextReplaceString);
   NetworkProperty(m_nTextReplaceValueVersion);
EndNetworkClass();

BeginNetworkClass(CDotaQuestBase, DT_DotaQuestBase);
EndNetworkClass();

BeginNetworkClass(CDOTASpecGraphPlayerData, DT_DotaSpecGraphPlayerData);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_rgGoldPerMinute);
   NetworkProperty(m_rgXPPerMinute);
   NetworkProperty(m_nCreatedByPlayerID);
EndNetworkClass();

BeginNetworkStruct(DT_DOTASpectatorGraphManager);
   NetworkProperty(m_rgPlayerGraphData);
   NetworkProperty(m_rgRadiantTotalEarnedGold);
   NetworkProperty(m_rgDireTotalEarnedGold);
   NetworkProperty(m_rgRadiantTotalEarnedXP);
   NetworkProperty(m_rgDireTotalEarnedXP);
   NetworkProperty(m_rgRadiantNetWorth);
   NetworkProperty(m_rgDireNetWorth);
   NetworkProperty(m_flTotalEarnedGoldStartTime);
   NetworkProperty(m_flTotalEarnedGoldEndTime);
   NetworkProperty(m_nGoldGraphVersion);
EndNetworkStruct();

BeginNetworkClass(CDOTASpectatorGraphManagerProxy, DT_DOTASpectatorGraphManagerProxy);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(dota_spectator_graph_manager_data);
EndNetworkClass();

BeginNetworkClass(CDotaSubquestBase, DT_DotaSubquestBase);
   NetworkProperty(m_pszSubquestText);
   NetworkProperty(m_bHidden);
   NetworkProperty(m_bCompleted);
   NetworkProperty(m_bShowProgressBar);
   NetworkProperty(m_nProgressBarHueShift);
   NetworkProperty(m_pnTextReplaceValuesCDotaSubquestBase);
   NetworkProperty(m_pszTextReplaceString);
   NetworkProperty(m_nTextReplaceValueVersion);
EndNetworkClass();

BeginNetworkClass(CDOTATeam, DT_DOTATeam);
   NetworkBaseClass(CTeam);
   NetworkProperty(m_iHeroKills);
   NetworkProperty(m_iTowerKills);
   NetworkProperty(m_iBarracksKills);
   NetworkProperty(m_unTournamentTeamID);
   NetworkProperty(m_ulTeamLogo);
   NetworkProperty(m_ulTeamBaseLogo);
   NetworkProperty(m_ulTeamBannerLogo);
   NetworkProperty(m_szTag);
   NetworkProperty(m_bTeamComplete);
EndNetworkClass();

BeginNetworkStruct(DT_SpeechBubbleInfo);
   NetworkProperty(m_LocalizationStr);
   NetworkProperty(m_hNPC);
   NetworkProperty(m_flLifetime);
EndNetworkStruct();

BeginNetworkClass(CDotaTutorialNetworker, DT_DotaTutorialNetworker);
   NetworkProperty(m_nTutorialState);
   NetworkProperty(m_nTaskProgress);
   NetworkProperty(m_nTaskSteps);
   NetworkProperty(m_nTaskSecondsRemianing);
   NetworkProperty(m_nUIState);
   NetworkProperty(m_TargetLocation);
   NetworkProperty(m_SpeechBubbles);
   NetworkProperty(m_nLocationID);
EndNetworkClass();

BeginNetworkClass(CDOTAWearableItem, DT_DOTAWearableItem);
   NetworkBaseClass(CEconWearable);
   NetworkProperty(m_bOwnerModelChanged);
EndNetworkClass();

BeginNetworkClass(CDynamicLight, DT_DynamicLight);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_Flags);
   NetworkProperty(m_LightStyle);
   NetworkProperty(m_Radius);
   NetworkProperty(m_Exponent);
   NetworkProperty(m_InnerAngle);
   NetworkProperty(m_OuterAngle);
   NetworkProperty(m_SpotRadius);
EndNetworkClass();

BeginNetworkClass(CDynamicProp, DT_DynamicProp);
   NetworkBaseClass(CBreakableProp);
   NetworkProperty(m_bUseHitboxesForRenderBox);
EndNetworkClass();

BeginNetworkClass(CEconEntity, DT_EconEntity);
   NetworkBaseClass(CBaseFlex);
   NetworkProperty(m_AttributeManager);
EndNetworkClass();

BeginNetworkClass(CEconWearable, DT_WearableItem);
   NetworkBaseClass(CEconEntity);
EndNetworkClass();

BeginNetworkClass(CEntityDissolve, DT_EntityDissolve);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_flStartTime);
   NetworkProperty(m_flFadeInStart);
   NetworkProperty(m_flFadeInLength);
   NetworkProperty(m_flFadeOutModelStart);
   NetworkProperty(m_flFadeOutModelLength);
   NetworkProperty(m_flFadeOutStart);
   NetworkProperty(m_flFadeOutLength);
   NetworkProperty(m_nDissolveType);
   NetworkProperty(m_vDissolverOrigin);
   NetworkProperty(m_nMagnitude);
EndNetworkClass();

BeginNetworkClass(CEntityFlame, DT_EntityFlame);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_hEntAttached);
   NetworkProperty(m_bCheapEffect);
EndNetworkClass();

BeginNetworkClass(CEntityFreezing, DT_EntityFreezing);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_vFreezingOrigin);
   NetworkProperty(m_flFrozenPerHitbox);
   NetworkProperty(m_flFrozen);
   NetworkProperty(m_bFinishFreezing);
EndNetworkClass();

BeginNetworkStruct(DT_EntityParticleTrailInfo);
   NetworkProperty(m_flLifetime);
   NetworkProperty(m_flStartSize);
   NetworkProperty(m_flEndSize);
EndNetworkStruct();

BeginNetworkClass(CEntityParticleTrail, DT_EntityParticleTrail);
   NetworkBaseClass(CBaseParticleEntity);
   NetworkProperty(m_iMaterialName);
   NetworkProperty(m_Info);
   NetworkProperty(m_hConstraintEntity);
EndNetworkClass();

BeginNetworkClass(CEnvAmbientLight, DT_EnvAmbientLight);
   NetworkBaseClass(CSpatialEntity);
   NetworkProperty(m_vecColor);
EndNetworkClass();

BeginNetworkClass(CEnvDeferredLight, DT_EnvDeferredLight);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_LightColor);
   NetworkProperty(m_flIntensity);
   NetworkProperty(m_flLightSize);
   NetworkProperty(m_flSpotFoV);
   NetworkProperty(m_vLightDirection);
   NetworkProperty(m_flStartFalloff);
   NetworkProperty(m_flDistanceFalloff);
   NetworkProperty(m_nFlags);
   NetworkProperty(m_ProjectedTextureName);
EndNetworkClass();

BeginNetworkClass(CEnvDetailController, DT_DetailController);
   NetworkProperty(m_flFadeStartDist);
   NetworkProperty(m_flFadeEndDist);
EndNetworkClass();

BeginNetworkClass(CEnvDOFController, DT_EnvDOFController);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_bDOFEnabled);
   NetworkProperty(m_flNearBlurDepth);
   NetworkProperty(m_flNearFocusDepth);
   NetworkProperty(m_flFarFocusDepth);
   NetworkProperty(m_flFarBlurDepth);
   NetworkProperty(m_flNearBlurRadius);
   NetworkProperty(m_flFarBlurRadius);
EndNetworkClass();

BeginNetworkClass(CEnvParticleScript, DT_EnvParticleScript);
   NetworkBaseClass(CBaseAnimating);
   NetworkProperty(m_flSequenceScale);
EndNetworkClass();

BeginNetworkClass(CEnvProjectedTexture, DT_EnvProjectedTexture);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_hTargetEntity);
   NetworkProperty(m_bState);
   NetworkProperty(m_bAlwaysUpdate);
   NetworkProperty(m_flLightFOV);
   NetworkProperty(m_bEnableShadows);
   NetworkProperty(m_bSimpleProjection);
   NetworkProperty(m_bLightOnlyTarget);
   NetworkProperty(m_bLightWorld);
   NetworkProperty(m_bCameraSpace);
   NetworkProperty(m_flBrightnessScale);
   NetworkProperty(m_LightColor);
   NetworkProperty(m_flFarZ);
   NetworkProperty(m_flColorTransitionTime);
   NetworkProperty(m_flAmbient);
   NetworkProperty(m_SpotlightTextureName);
   NetworkProperty(m_nSpotlightTextureFrame);
   NetworkProperty(m_flNearZ);
   NetworkProperty(m_nShadowQuality);
   NetworkProperty(m_flProjectionSize);
   NetworkProperty(m_flRotation);
EndNetworkClass();

BeginNetworkClass(CEnvQuadraticBeam, DT_QuadraticBeam);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_targetPosition);
   NetworkProperty(m_controlPosition);
   NetworkProperty(m_scrollRate);
   NetworkProperty(m_flWidth);
EndNetworkClass();

BeginNetworkClass(CEnvScreenEffect, DT_EnvScreenEffect);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_flDuration);
   NetworkProperty(m_nType);
EndNetworkClass();

BeginNetworkClass(CEnvScreenOverlay, DT_EnvScreenOverlay);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_iszOverlayNames);
   NetworkProperty(m_flOverlayTimes);
   NetworkProperty(m_flStartTime);
   NetworkProperty(m_iDesiredOverlay);
   NetworkProperty(m_bIsActive);
EndNetworkClass();

BeginNetworkClass(CEnvTonemapController, DT_EnvTonemapController);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_bUseCustomAutoExposureMin);
   NetworkProperty(m_bUseCustomAutoExposureMax);
   NetworkProperty(m_bUseCustomBloomScale);
   NetworkProperty(m_flCustomAutoExposureMin);
   NetworkProperty(m_flCustomAutoExposureMax);
   NetworkProperty(m_flCustomBloomScale);
   NetworkProperty(m_flCustomBloomScaleMinimum);
   NetworkProperty(m_flBloomExponent);
   NetworkProperty(m_flBloomSaturation);
EndNetworkClass();

BeginNetworkStruct(DT_EnvWindShared);
   NetworkProperty(m_iMinWind);
   NetworkProperty(m_iMaxWind);
   NetworkProperty(m_iMinGust);
   NetworkProperty(m_iMaxGust);
   NetworkProperty(m_windRadius);
   NetworkProperty(m_flMinGustDelay);
   NetworkProperty(m_flMaxGustDelay);
   NetworkProperty(m_iGustDirChange);
   NetworkProperty(m_iWindSeed);
   NetworkProperty(m_iInitialWindDir);
   NetworkProperty(m_flInitialWindSpeed);
   NetworkProperty(m_flStartTime);
   NetworkProperty(m_flGustDuration);
EndNetworkStruct();

BeginNetworkClass(CEnvWind, DT_EnvWind);
   NetworkProperty(m_EnvWindShared);
EndNetworkClass();

BeginNetworkClass(CFireSmoke, DT_FireSmoke);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_flStartScale);
   NetworkProperty(m_flScale);
   NetworkProperty(m_flScaleTime);
   NetworkProperty(m_nFlags);
   NetworkProperty(m_nFlameModelIndex);
   NetworkProperty(m_nFlameFromAboveModelIndex);
EndNetworkClass();

BeginNetworkClass(CFireTrail, DT_FireTrail);
   NetworkBaseClass(CBaseParticleEntity);
   NetworkProperty(m_nAttachment);
   NetworkProperty(m_flLifetime);
EndNetworkClass();

BeginNetworkClass(CFish, DT_CFish);
   NetworkProperty(m_poolOrigin);
   NetworkProperty(m_angle);
   NetworkProperty(m_x);
   NetworkProperty(m_y);
   NetworkProperty(m_z);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_lifeState);
   NetworkProperty(m_waterLevel);
EndNetworkClass();

BeginNetworkClass(CFogController, DT_FogController);
   NetworkProperty(m_fog.enable);
   NetworkProperty(m_fog.blend);
   NetworkProperty(m_fog.dirPrimary);
   NetworkProperty(m_fog.colorPrimary);
   NetworkProperty(m_fog.colorSecondary);
   NetworkProperty(m_fog.start);
   NetworkProperty(m_fog.end);
   NetworkProperty(m_fog.maxdensity);
   NetworkProperty(m_fog.farz);
   NetworkProperty(m_fog.colorPrimaryLerpTo);
   NetworkProperty(m_fog.colorSecondaryLerpTo);
   NetworkProperty(m_fog.startLerpTo);
   NetworkProperty(m_fog.endLerpTo);
   NetworkProperty(m_fog.maxdensityLerpTo);
   NetworkProperty(m_fog.lerptime);
   NetworkProperty(m_fog.duration);
   NetworkProperty(m_fog.HDRColorScale);
   NetworkProperty(m_fog.m_bNoReflectionFog);
EndNetworkClass();

BeginNetworkClass(CFunc_Dust, DT_Func_Dust);
   NetworkProperty(m_Color);
   NetworkProperty(m_SpawnRate);
   NetworkProperty(m_SpeedMax);
   NetworkProperty(m_flSizeMin);
   NetworkProperty(m_flSizeMax);
   NetworkProperty(m_DistMax);
   NetworkProperty(m_LifetimeMin);
   NetworkProperty(m_LifetimeMax);
   NetworkProperty(m_DustFlags);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_FallSpeed);
   NetworkProperty(m_Collision);
EndNetworkClass();

BeginNetworkClass(CFunc_LOD, DT_Func_LOD);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_nDisappearMinDist);
   NetworkProperty(m_nDisappearMaxDist);
EndNetworkClass();

BeginNetworkClass(CFuncAreaPortalWindow, DT_FuncAreaPortalWindow);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_flFadeDist);
   NetworkProperty(m_flFadeStartDist);
   NetworkProperty(m_flTranslucencyLimit);
   NetworkProperty(m_iBackgroundModelIndex);
EndNetworkClass();

BeginNetworkClass(CFuncBrush, DT_FuncBrush);
   NetworkBaseClass(CBaseEntity);
EndNetworkClass();

BeginNetworkClass(CFuncConveyor, DT_FuncConveyor);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_flConveyorSpeed);
EndNetworkClass();

BeginNetworkClass(CFuncLadder, DT_FuncLadder);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_vecPlayerMountPositionTop);
   NetworkProperty(m_vecPlayerMountPositionBottom);
   NetworkProperty(m_vecLadderDir);
   NetworkProperty(m_bFakeLadder);
EndNetworkClass();

BeginNetworkClass(CFuncMoveLinear, DT_FuncMoveLinear);
   NetworkBaseClass(CBaseToggle);
   NetworkProperty(m_vecVelocity);
   NetworkProperty(m_fFlags);
EndNetworkClass();

BeginNetworkClass(CFuncOccluder, DT_FuncOccluder);
   NetworkProperty(m_bActive);
   NetworkProperty(m_nOccluderIndex);
EndNetworkClass();

BeginNetworkClass(CFuncReflectiveGlass, DT_FuncReflectiveGlass);
   NetworkBaseClass(CFuncBrush);
EndNetworkClass();

BeginNetworkClass(CFuncRotating, DT_FuncRotating);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_angRotation);
   NetworkProperty(m_flSimulationTime);
EndNetworkClass();

BeginNetworkClass(CFuncSmokeVolume, DT_FuncSmokeVolume);
   NetworkBaseClass(CBaseParticleEntity);
   NetworkProperty(m_Color1);
   NetworkProperty(m_Color2);
   NetworkProperty(m_MaterialName);
   NetworkProperty(m_ParticleDrawWidth);
   NetworkProperty(m_ParticleSpacingDistance);
   NetworkProperty(m_DensityRampSpeed);
   NetworkProperty(m_RotationSpeed);
   NetworkProperty(m_MovementSpeed);
   NetworkProperty(m_Density);
   NetworkProperty(m_maxDrawDistance);
   NetworkProperty(m_spawnflags);
EndNetworkClass();

BeginNetworkClass(CFuncTrackTrain, DT_FuncTrackTrain);
   NetworkBaseClass(CBaseEntity);
EndNetworkClass();

BeginNetworkClass(CGameRulesProxy, DT_GameRulesProxy);
EndNetworkClass();

BeginNetworkClass(CHandleTest, DT_HandleTest);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_Handle);
   NetworkProperty(m_bSendHandle);
EndNetworkClass();

BeginNetworkClass(CInfoLadderDismount, DT_InfoLadderDismount);
   NetworkBaseClass(CBaseEntity);
EndNetworkClass();

BeginNetworkClass(CInfoOverlayAccessor, DT_InfoOverlayAccessor);
   NetworkProperty(m_iTextureFrameIndex);
   NetworkProperty(m_iOverlayID);
EndNetworkClass();

BeginNetworkClass(CLightGlow, DT_LightGlow);
   NetworkProperty(m_clrRender);
   NetworkProperty(m_nHorizontalSize);
   NetworkProperty(m_nVerticalSize);
   NetworkProperty(m_nMinDist);
   NetworkProperty(m_nMaxDist);
   NetworkProperty(m_nOuterMaxDist);
   NetworkProperty(m_spawnflags);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_angRotation);
   NetworkProperty(moveparent);
   NetworkProperty(m_flGlowProxySize);
   NetworkProperty(HDRColorScale);
EndNetworkClass();

BeginNetworkClass(CMaterialModifyControl, DT_MaterialModifyControl);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_szMaterialName);
   NetworkProperty(m_szMaterialVar);
   NetworkProperty(m_szMaterialVarValue);
   NetworkProperty(m_iFrameStart);
   NetworkProperty(m_iFrameEnd);
   NetworkProperty(m_bWrap);
   NetworkProperty(m_flFramerate);
   NetworkProperty(m_bNewAnimCommandsSemaphore);
   NetworkProperty(m_flFloatLerpStartValue);
   NetworkProperty(m_flFloatLerpEndValue);
   NetworkProperty(m_flFloatLerpTransitionTime);
   NetworkProperty(m_nModifyMode);
EndNetworkClass();

BeginNetworkClass(CMovieDisplay, DT_MovieDisplay);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_bEnabled);
   NetworkProperty(m_bLooping);
   NetworkProperty(m_szMovieFilename);
   NetworkProperty(m_szGroupName);
EndNetworkClass();

BeginNetworkClass(CParticleFire, DT_ParticleFire);
   NetworkProperty(m_vOrigin);
   NetworkProperty(m_vDirection);
EndNetworkClass();

BeginNetworkClass(CParticlePerformanceMonitor, DT_ParticlePerformanceMonitor);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_bDisplayPerf);
   NetworkProperty(m_bMeasurePerf);
EndNetworkClass();

BeginNetworkClass(CParticleSystem, DT_ParticleSystem);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_flStartTime);
   NetworkProperty(m_iEffectIndex);
   NetworkProperty(m_bActive);
   NetworkProperty(m_hOwnerEntity);
   NetworkProperty(moveparent);
   NetworkProperty(m_iParentAttachment);
   NetworkProperty(m_angRotation);
   NetworkProperty(m_nStopType);
   NetworkProperty(m_szSnapshotFileName);
   NetworkProperty(m_vServerControlPoints);
   NetworkProperty(m_iServerControlPointAssignments);
   NetworkProperty(m_hControlPointEnts);
   NetworkProperty(m_iControlPointParents);
EndNetworkClass();

BeginNetworkClass(CPhysBox, DT_PhysBox);
   NetworkBaseClass(CBaseEntity);
EndNetworkClass();

BeginNetworkClass(CPhysBoxMultiplayer, DT_PhysBoxMultiplayer);
   NetworkBaseClass(CPhysBox);
   NetworkProperty(m_iPhysicsMode);
   NetworkProperty(m_fMass);
EndNetworkClass();

BeginNetworkClass(CPhysicsProp, DT_PhysicsProp);
   NetworkBaseClass(CBreakableProp);
   NetworkProperty(m_bAwake);
EndNetworkClass();

BeginNetworkClass(CPhysicsPropMultiplayer, DT_PhysicsPropMultiplayer);
   NetworkBaseClass(CPhysicsProp);
   NetworkProperty(m_iPhysicsMode);
   NetworkProperty(m_fMass);
   NetworkProperty(m_collisionMins);
   NetworkProperty(m_collisionMaxs);
EndNetworkClass();

BeginNetworkClass(CPhysMagnet, DT_PhysMagnet);
   NetworkBaseClass(CBaseAnimating);
EndNetworkClass();

BeginNetworkClass(CPlasma, DT_Plasma);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_flScale);
   NetworkProperty(m_flScaleTime);
   NetworkProperty(m_nFlags);
   NetworkProperty(m_nPlasmaModelIndex);
   NetworkProperty(m_nPlasmaModelIndex2);
   NetworkProperty(m_nGlowModelIndex);
EndNetworkClass();

BeginNetworkClass(CPointCamera, DT_PointCamera);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_FOV);
   NetworkProperty(m_Resolution);
   NetworkProperty(m_bFogEnable);
   NetworkProperty(m_FogColor);
   NetworkProperty(m_flFogStart);
   NetworkProperty(m_flFogEnd);
   NetworkProperty(m_flFogMaxDensity);
   NetworkProperty(m_bActive);
   NetworkProperty(m_bUseScreenAspectRatio);
   NetworkProperty(m_bNoSky);
   NetworkProperty(m_fBrightness);
EndNetworkClass();

BeginNetworkClass(CPointCommentaryNode, DT_PointCommentaryNode);
   NetworkBaseClass(CBaseAnimating);
   NetworkProperty(m_bActive);
   NetworkProperty(m_iszCommentaryFile);
   NetworkProperty(m_iszCommentaryFileNoHDR);
   NetworkProperty(m_flStartTime);
   NetworkProperty(m_iszSpeakers);
   NetworkProperty(m_iNodeNumber);
   NetworkProperty(m_iNodeNumberMax);
   NetworkProperty(m_hViewPosition);
EndNetworkClass();

BeginNetworkClass(CPoseController, DT_PoseController);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_hProps);
   NetworkProperty(m_chPoseIndex);
   NetworkProperty(m_bPoseValueParity);
   NetworkProperty(m_fPoseValue);
   NetworkProperty(m_fInterpolationTime);
   NetworkProperty(m_bInterpolationWrap);
   NetworkProperty(m_fCycleFrequency);
   NetworkProperty(m_nFModType);
   NetworkProperty(m_fFModTimeOffset);
   NetworkProperty(m_fFModRate);
   NetworkProperty(m_fFModAmplitude);
EndNetworkClass();

BeginNetworkClass(CPostProcessController, DT_PostProcessController);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_flPostProcessParameters);
   NetworkProperty(m_bMaster);
EndNetworkClass();

BeginNetworkClass(CPrecipitation, DT_Precipitation);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_nPrecipType);
EndNetworkClass();

BeginNetworkClass(CPrecipitationBlocker, DT_PrecipitationBlocker);
   NetworkBaseClass(CBaseEntity);
EndNetworkClass();

BeginNetworkClass(CProp_Hallucination, DT_Prop_Hallucination);
   NetworkBaseClass(CBaseAnimating);
   NetworkProperty(m_bEnabled);
   NetworkProperty(m_fVisibleTime);
   NetworkProperty(m_fRechargeTime);
EndNetworkClass();

BeginNetworkClass(CPropDoorRotating, DT_PropDoorRotating);
   NetworkBaseClass(CBasePropDoor);
EndNetworkClass();

BeginNetworkClass(CPropVehicleDriveable, DT_PropVehicleDriveable);
   NetworkBaseClass(CBaseAnimating);
   NetworkProperty(m_hPlayer);
   NetworkProperty(m_nSpeed);
   NetworkProperty(m_nRPM);
   NetworkProperty(m_flThrottle);
   NetworkProperty(m_nBoostTimeLeft);
   NetworkProperty(m_nHasBoost);
   NetworkProperty(m_nScannerDisabledWeapons);
   NetworkProperty(m_nScannerDisabledVehicle);
   NetworkProperty(m_bEnterAnimOn);
   NetworkProperty(m_bExitAnimOn);
   NetworkProperty(m_bUnableToFire);
   NetworkProperty(m_vecEyeExitEndpoint);
   NetworkProperty(m_bHasGun);
   NetworkProperty(m_vecGunCrosshair);
EndNetworkClass();

BeginNetworkClass(CRagdollManager, DT_RagdollManager);
   NetworkProperty(m_iCurrentMaxRagdollCount);
EndNetworkClass();

BeginNetworkClass(CRagdollProp, DT_Ragdoll);
   NetworkBaseClass(CBaseAnimating);
   NetworkProperty(m_ragAngles);
   NetworkProperty(m_ragPos);
   NetworkProperty(m_hUnragdoll);
   NetworkProperty(m_flBlendWeight);
   NetworkProperty(m_nOverlaySequence);
EndNetworkClass();

BeginNetworkClass(CRagdollPropAttached, DT_Ragdoll_Attached);
   NetworkBaseClass(CRagdollProp);
   NetworkProperty(m_boneIndexAttached);
   NetworkProperty(m_ragdollAttachedObjectIndex);
   NetworkProperty(m_attachmentPointBoneSpace);
   NetworkProperty(m_attachmentPointRagdollSpace);
EndNetworkClass();

BeginNetworkClass(CRopeKeyframe, DT_RopeKeyframe);
   NetworkProperty(m_hStartPoint);
   NetworkProperty(m_hEndPoint);
   NetworkProperty(m_iStartAttachment);
   NetworkProperty(m_iEndAttachment);
   NetworkProperty(m_Slack);
   NetworkProperty(m_RopeLength);
   NetworkProperty(m_fLockedPoints);
   NetworkProperty(m_nChangeCount);
   NetworkProperty(m_RopeFlags);
   NetworkProperty(m_nSegments);
   NetworkProperty(m_bConstrainBetweenEndpoints);
   NetworkProperty(m_iRopeMaterialModelIndex);
   NetworkProperty(m_Subdiv);
   NetworkProperty(m_TextureScale);
   NetworkProperty(m_Width);
   NetworkProperty(m_flScrollSpeed);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(moveparent);
   NetworkProperty(m_iParentAttachment);
   NetworkProperty(m_nMinCPULevel);
   NetworkProperty(m_nMaxCPULevel);
   NetworkProperty(m_nMinGPULevel);
   NetworkProperty(m_nMaxGPULevel);
EndNetworkClass();

BeginNetworkClass(CSceneEntity, DT_SceneEntity);
   NetworkProperty(m_nSceneStringIndex);
   NetworkProperty(m_bIsPlayingBack);
   NetworkProperty(m_bPaused);
   NetworkProperty(m_bMultiplayer);
   NetworkProperty(m_flForceClientTime);
   NetworkProperty(m_hActorList);
EndNetworkClass();

BeginNetworkClass(CShadowControl, DT_ShadowControl);
   NetworkProperty(m_shadowDirection);
   NetworkProperty(m_shadowColor);
   NetworkProperty(m_flShadowMaxDist);
   NetworkProperty(m_bDisableShadows);
   NetworkProperty(m_bEnableLocalLightShadows);
EndNetworkClass();

BeginNetworkClass(CSlideshowDisplay, DT_SlideshowDisplay);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_bEnabled);
   NetworkProperty(m_szDisplayText);
   NetworkProperty(m_szSlideshowDirectory);
   NetworkProperty(m_chCurrentSlideLists);
   NetworkProperty(m_fMinSlideTime);
   NetworkProperty(m_fMaxSlideTime);
   NetworkProperty(m_iCycleType);
   NetworkProperty(m_bNoListRepeats);
EndNetworkClass();

BeginNetworkClass(CSmokeStack, DT_SmokeStack);
   NetworkBaseClass(CBaseParticleEntity);
   NetworkProperty(m_SpreadSpeed);
   NetworkProperty(m_Speed);
   NetworkProperty(m_StartSize);
   NetworkProperty(m_EndSize);
   NetworkProperty(m_Rate);
   NetworkProperty(m_JetLength);
   NetworkProperty(m_bEmit);
   NetworkProperty(m_flBaseSpread);
   NetworkProperty(m_flRollSpeed);
   NetworkProperty(m_DirLight.m_vPos);
   NetworkProperty(m_DirLight.m_vColor);
   NetworkProperty(m_DirLight.m_flIntensity);
   NetworkProperty(m_AmbientLight.m_vPos);
   NetworkProperty(m_AmbientLight.m_vColor);
   NetworkProperty(m_AmbientLight.m_flIntensity);
   NetworkProperty(m_vWind);
   NetworkProperty(m_flTwist);
   NetworkProperty(m_iMaterialModel);
EndNetworkClass();

BeginNetworkClass(CSpatialEntity, DT_SpatialEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_MinFalloff);
   NetworkProperty(m_MaxFalloff);
   NetworkProperty(m_flCurWeight);
   NetworkProperty(m_bEnabled);
EndNetworkClass();

BeginNetworkClass(CSpotlightEnd, DT_SpotlightEnd);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_flLightScale);
   NetworkProperty(m_Radius);
EndNetworkClass();

BeginNetworkClass(CSprite, DT_Sprite);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_hAttachedToEntity);
   NetworkProperty(m_nAttachment);
   NetworkProperty(m_flScaleTime);
   NetworkProperty(m_flSpriteScale);
   NetworkProperty(m_flGlowProxySize);
   NetworkProperty(m_flHDRColorScale);
   NetworkProperty(m_flSpriteFramerate);
   NetworkProperty(m_flFrame);
   NetworkProperty(m_flBrightnessTime);
   NetworkProperty(m_nBrightness);
   NetworkProperty(m_bWorldSpaceScale);
EndNetworkClass();

BeginNetworkClass(CSpriteOriented, DT_SpriteOriented);
   NetworkBaseClass(CSprite);
EndNetworkClass();

BeginNetworkClass(CSpriteTrail, DT_SpriteTrail);
   NetworkBaseClass(CSprite);
   NetworkProperty(m_flLifeTime);
   NetworkProperty(m_flStartWidth);
   NetworkProperty(m_flEndWidth);
   NetworkProperty(m_flStartWidthVariance);
   NetworkProperty(m_flTextureRes);
   NetworkProperty(m_flMinFadeLength);
   NetworkProperty(m_vecSkyboxOrigin);
   NetworkProperty(m_flSkyboxScale);
EndNetworkClass();

BeginNetworkClass(CStatueProp, DT_StatueProp);
   NetworkBaseClass(CPhysicsProp);
   NetworkProperty(m_hInitBaseAnimating);
   NetworkProperty(m_bShatter);
   NetworkProperty(m_nShatterFlags);
   NetworkProperty(m_vShatterPosition);
   NetworkProperty(m_vShatterForce);
EndNetworkClass();

BeginNetworkClass(CSteamJet, DT_SteamJet);
   NetworkBaseClass(CBaseParticleEntity);
   NetworkProperty(m_SpreadSpeed);
   NetworkProperty(m_Speed);
   NetworkProperty(m_StartSize);
   NetworkProperty(m_EndSize);
   NetworkProperty(m_Rate);
   NetworkProperty(m_JetLength);
   NetworkProperty(m_bEmit);
   NetworkProperty(m_bFaceLeft);
   NetworkProperty(m_nType);
   NetworkProperty(m_spawnflags);
   NetworkProperty(m_flRollSpeed);
EndNetworkClass();

BeginNetworkClass(CSun, DT_Sun);
   NetworkProperty(m_clrRender);
   NetworkProperty(m_clrOverlay);
   NetworkProperty(m_vDirection);
   NetworkProperty(m_bOn);
   NetworkProperty(m_nSize);
   NetworkProperty(m_nOverlaySize);
   NetworkProperty(m_nMaterial);
   NetworkProperty(m_nOverlayMaterial);
   NetworkProperty(HDRColorScale);
EndNetworkClass();

BeginNetworkClass(CSunlightShadowControl, DT_SunlightShadowControl);
   NetworkProperty(m_shadowDirection);
   NetworkProperty(m_bEnabled);
   NetworkProperty(m_TextureName);
   NetworkProperty(m_LightColor);
   NetworkProperty(m_flColorTransitionTime);
   NetworkProperty(m_flSunDistance);
   NetworkProperty(m_flFOV);
   NetworkProperty(m_flNearZ);
   NetworkProperty(m_flNorthOffset);
   NetworkProperty(m_bEnableShadows);
EndNetworkClass();

BeginNetworkClass(CTeam, DT_Team);
   NetworkProperty(m_iTeamNum);
   NetworkProperty(m_iScore);
   NetworkProperty(m_iRoundsWon);
   NetworkProperty(m_szTeamname);
   NetworkProperty(player_array);
EndNetworkClass();

BeginNetworkStruct(DT_ShowcaseData);
   NetworkProperty(m_hRootEntity);
   NetworkProperty(m_Slots);
EndNetworkStruct();

BeginNetworkStruct(DT_ShowcaseSlot);
   NetworkProperty(nType);
   NetworkProperty(szName);
   NetworkProperty(vecLocalOrigin);
   NetworkProperty(angLocalAngles);
   NetworkProperty(hEntity);
   NetworkProperty(ulItemID);
   NetworkProperty(bIsOnlySlotOfThisType);
EndNetworkStruct();

BeginNetworkClass(CTeamShowcaseEditorManager, DT_TeamShowcaseEditorManager);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_nEditorMode);
   NetworkProperty(m_nCurEditingSlot);
   NetworkProperty(m_Data);
EndNetworkClass();

BeginNetworkClass(CTeamShowcasePlayer, DT_TeamShowcasePlayer);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_hPlayerEntity);
   NetworkProperty(m_szCameraAnim);
   NetworkProperty(m_flTransitionTime);
EndNetworkClass();

BeginNetworkClass(CTEArmorRicochet, DT_TEArmorRicochet);
   NetworkBaseClass(CTEMetalSparks);
EndNetworkClass();

BeginNetworkClass(CTEBaseBeam, DT_BaseBeam);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_nHaloIndex);
   NetworkProperty(m_nStartFrame);
   NetworkProperty(m_nFrameRate);
   NetworkProperty(m_fLife);
   NetworkProperty(m_fWidth);
   NetworkProperty(m_fEndWidth);
   NetworkProperty(m_nFadeLength);
   NetworkProperty(m_fAmplitude);
   NetworkProperty(m_nSpeed);
   NetworkProperty(r);
   NetworkProperty(g);
   NetworkProperty(b);
   NetworkProperty(a);
   NetworkProperty(m_nFlags);
EndNetworkClass();

BeginNetworkClass(CTEBeamEntPoint, DT_TEBeamEntPoint);
   NetworkBaseClass(CTEBaseBeam);
   NetworkProperty(m_nStartEntity);
   NetworkProperty(m_nEndEntity);
   NetworkProperty(m_vecStartPoint);
   NetworkProperty(m_vecEndPoint);
EndNetworkClass();

BeginNetworkClass(CTEBeamEnts, DT_TEBeamEnts);
   NetworkBaseClass(CTEBaseBeam);
   NetworkProperty(m_nStartEntity);
   NetworkProperty(m_nEndEntity);
EndNetworkClass();

BeginNetworkClass(CTEBeamFollow, DT_TEBeamFollow);
   NetworkBaseClass(CTEBaseBeam);
   NetworkProperty(m_iEntIndex);
EndNetworkClass();

BeginNetworkClass(CTEBeamLaser, DT_TEBeamLaser);
   NetworkBaseClass(CTEBaseBeam);
   NetworkProperty(m_nStartEntity);
   NetworkProperty(m_nEndEntity);
EndNetworkClass();

BeginNetworkClass(CTEBeamPoints, DT_TEBeamPoints);
   NetworkBaseClass(CTEBaseBeam);
   NetworkProperty(m_vecStartPoint);
   NetworkProperty(m_vecEndPoint);
EndNetworkClass();

BeginNetworkClass(CTEBeamRing, DT_TEBeamRing);
   NetworkBaseClass(CTEBaseBeam);
   NetworkProperty(m_nStartEntity);
   NetworkProperty(m_nEndEntity);
EndNetworkClass();

BeginNetworkClass(CTEBeamRingPoint, DT_TEBeamRingPoint);
   NetworkBaseClass(CTEBaseBeam);
   NetworkProperty(m_vecCenter);
   NetworkProperty(m_flStartRadius);
   NetworkProperty(m_flEndRadius);
EndNetworkClass();

BeginNetworkClass(CTEBeamSpline, DT_TEBeamSpline);
   NetworkProperty(m_nPoints);
   NetworkProperty(m_vecPoints);
EndNetworkClass();

BeginNetworkClass(CTEBloodSprite, DT_TEBloodSprite);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_vecDirection);
   NetworkProperty(r);
   NetworkProperty(g);
   NetworkProperty(b);
   NetworkProperty(a);
   NetworkProperty(m_nSprayModel);
   NetworkProperty(m_nDropModel);
   NetworkProperty(m_nSize);
EndNetworkClass();

BeginNetworkClass(CTEBloodStream, DT_TEBloodStream);
   NetworkBaseClass(CTEParticleSystem);
   NetworkProperty(m_vecDirection);
   NetworkProperty(r);
   NetworkProperty(g);
   NetworkProperty(b);
   NetworkProperty(a);
   NetworkProperty(m_nAmount);
EndNetworkClass();

BeginNetworkClass(CTEBreakModel, DT_TEBreakModel);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_angRotation);
   NetworkProperty(m_vecSize);
   NetworkProperty(m_vecVelocity);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_nRandomization);
   NetworkProperty(m_nCount);
   NetworkProperty(m_fTime);
   NetworkProperty(m_nFlags);
EndNetworkClass();

BeginNetworkClass(CTEBSPDecal, DT_TEBSPDecal);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_nEntity);
   NetworkProperty(m_nIndex);
EndNetworkClass();

BeginNetworkClass(CTEBubbles, DT_TEBubbles);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecMins);
   NetworkProperty(m_vecMaxs);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_fHeight);
   NetworkProperty(m_nCount);
   NetworkProperty(m_fSpeed);
EndNetworkClass();

BeginNetworkClass(CTEBubbleTrail, DT_TEBubbleTrail);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecMins);
   NetworkProperty(m_vecMaxs);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_flWaterZ);
   NetworkProperty(m_nCount);
   NetworkProperty(m_fSpeed);
EndNetworkClass();

BeginNetworkClass(CTEClientProjectile, DT_TEClientProjectile);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_vecVelocity);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_nLifeTime);
   NetworkProperty(m_hOwner);
EndNetworkClass();

BeginNetworkClass(CTEDecal, DT_TEDecal);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_vecStart);
   NetworkProperty(m_nEntity);
   NetworkProperty(m_nHitbox);
   NetworkProperty(m_nIndex);
EndNetworkClass();

BeginNetworkClass(CTEDotaBloodImpact, DT_TEDotaBloodImpact);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_hEntity);
   NetworkProperty(m_flScale);
   NetworkProperty(m_flXNormal);
   NetworkProperty(m_flYNormal);
EndNetworkClass();

BeginNetworkClass(CTEDOTAProjectile, DT_TEDOTAProjectile);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_iMoveSpeed);
   NetworkProperty(m_hSource);
   NetworkProperty(m_hTarget);
   NetworkProperty(m_iSourceAttachment);
   NetworkProperty(m_iParticleSystem);
   NetworkProperty(m_bDodgeable);
   NetworkProperty(m_bIsAttack);
   NetworkProperty(m_bIsEvaded);
   NetworkProperty(m_flExpireTime);
EndNetworkClass();

BeginNetworkClass(CTEDOTAProjectileLoc, DT_TEDOTAProjectileLoc);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_iMoveSpeed);
   NetworkProperty(m_vSourceLoc);
   NetworkProperty(m_vTargetLoc);
   NetworkProperty(m_hTarget);
   NetworkProperty(m_iParticleSystem);
   NetworkProperty(m_bDodgeable);
   NetworkProperty(m_bIsAttack);
   NetworkProperty(m_bIsEvaded);
   NetworkProperty(m_flExpireTime);
EndNetworkClass();

BeginNetworkClass(CTEDust, DT_TEDust);
   NetworkBaseClass(CTEParticleSystem);
   NetworkProperty(m_flSize);
   NetworkProperty(m_flSpeed);
   NetworkProperty(m_vecDirection);
EndNetworkClass();

BeginNetworkClass(CTEDynamicLight, DT_TEDynamicLight);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(r);
   NetworkProperty(g);
   NetworkProperty(b);
   NetworkProperty(exponent);
   NetworkProperty(m_fRadius);
   NetworkProperty(m_fTime);
   NetworkProperty(m_fDecay);
EndNetworkClass();

BeginNetworkStruct(DT_EffectData);
   NetworkProperty(m_vOrigin.x);
   NetworkProperty(m_vOrigin.y);
   NetworkProperty(m_vOrigin.z);
   NetworkProperty(m_vStart.x);
   NetworkProperty(m_vStart.y);
   NetworkProperty(m_vStart.z);
   NetworkProperty(m_vAngles);
   NetworkProperty(m_vNormal);
   NetworkProperty(m_fFlags);
   NetworkProperty(m_flMagnitude);
   NetworkProperty(m_flScale);
   NetworkProperty(m_nAttachmentIndex);
   NetworkProperty(m_nSurfaceProp);
   NetworkProperty(m_iEffectName);
   NetworkProperty(m_nMaterial);
   NetworkProperty(m_nDamageType);
   NetworkProperty(m_nHitBox);
   NetworkProperty(entindex);
   NetworkProperty(m_nOtherEntIndex);
   NetworkProperty(m_nColor);
   NetworkProperty(m_flRadius);
EndNetworkStruct();

BeginNetworkClass(CTEEffectDispatch, DT_TEEffectDispatch);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_EffectData);
EndNetworkClass();

BeginNetworkClass(CTEEnergySplash, DT_TEEnergySplash);
   NetworkProperty(m_vecPos);
   NetworkProperty(m_vecDir);
   NetworkProperty(m_bExplosive);
EndNetworkClass();

BeginNetworkClass(CTEExplosion, DT_TEExplosion);
   NetworkBaseClass(CTEParticleSystem);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_fScale);
   NetworkProperty(m_nFrameRate);
   NetworkProperty(m_nFlags);
   NetworkProperty(m_vecNormal);
   NetworkProperty(m_chMaterialType);
   NetworkProperty(m_nRadius);
   NetworkProperty(m_nMagnitude);
EndNetworkClass();

BeginNetworkClass(CTEFizz, DT_TEFizz);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_nEntity);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_nDensity);
   NetworkProperty(m_nCurrent);
EndNetworkClass();

BeginNetworkClass(CTEFootprintDecal, DT_TEFootprintDecal);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_vecDirection);
   NetworkProperty(m_nEntity);
   NetworkProperty(m_nIndex);
   NetworkProperty(m_chMaterialType);
EndNetworkClass();

BeginNetworkClass(CTEFoundryHelpers, DT_TEFoundryHelpers);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_iEntity);
EndNetworkClass();

BeginNetworkClass(CTEGaussExplosion, DT_TEGaussExplosion);
   NetworkBaseClass(CTEParticleSystem);
   NetworkProperty(m_nType);
   NetworkProperty(m_vecDirection);
EndNetworkClass();

BeginNetworkClass(CTEGlowSprite, DT_TEGlowSprite);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_fScale);
   NetworkProperty(m_fLife);
   NetworkProperty(m_nBrightness);
EndNetworkClass();

BeginNetworkClass(CTEImpact, DT_TEImpact);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_vecNormal);
   NetworkProperty(m_iType);
EndNetworkClass();

BeginNetworkClass(CTEKillPlayerAttachments, DT_TEKillPlayerAttachments);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_nPlayer);
EndNetworkClass();

BeginNetworkClass(CTELargeFunnel, DT_TELargeFunnel);
   NetworkBaseClass(CTEParticleSystem);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_nReversed);
EndNetworkClass();

BeginNetworkClass(CTEMetalSparks, DT_TEMetalSparks);
   NetworkProperty(m_vecPos);
   NetworkProperty(m_vecDir);
EndNetworkClass();

BeginNetworkClass(CTEMuzzleFlash, DT_TEMuzzleFlash);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_vecAngles);
   NetworkProperty(m_flScale);
   NetworkProperty(m_nType);
EndNetworkClass();

BeginNetworkClass(CTEParticleSystem, DT_TEParticleSystem);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
EndNetworkClass();

BeginNetworkClass(CTEPhysicsProp, DT_TEPhysicsProp);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_angRotation);
   NetworkProperty(m_vecVelocity);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_nSkin);
   NetworkProperty(m_nFlags);
   NetworkProperty(m_nEffects);
EndNetworkClass();

BeginNetworkClass(CTEPlayerDecal, DT_TEPlayerDecal);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_nEntity);
   NetworkProperty(m_nPlayer);
EndNetworkClass();

BeginNetworkClass(CTEProjectedDecal, DT_TEProjectedDecal);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_angRotation);
   NetworkProperty(m_flDistance);
   NetworkProperty(m_nIndex);
EndNetworkClass();

BeginNetworkClass(CTEShatterSurface, DT_TEShatterSurface);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_vecAngles);
   NetworkProperty(m_vecForce);
   NetworkProperty(m_vecForcePos);
   NetworkProperty(m_flWidth);
   NetworkProperty(m_flHeight);
   NetworkProperty(m_flShardSize);
   NetworkProperty(m_nSurfaceType);
   NetworkProperty(m_uchFrontColor);
   NetworkProperty(m_uchBackColor);
EndNetworkClass();

BeginNetworkClass(CTEShowLine, DT_TEShowLine);
   NetworkBaseClass(CTEParticleSystem);
   NetworkProperty(m_vecEnd);
EndNetworkClass();

BeginNetworkClass(CTesla, DT_Tesla);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_SoundName);
   NetworkProperty(m_iszSpriteName);
EndNetworkClass();

BeginNetworkClass(CTESmoke, DT_TESmoke);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_fScale);
   NetworkProperty(m_nFrameRate);
EndNetworkClass();

BeginNetworkClass(CTESparks, DT_TESparks);
   NetworkBaseClass(CTEParticleSystem);
   NetworkProperty(m_nMagnitude);
   NetworkProperty(m_nTrailLength);
   NetworkProperty(m_vecDir);
EndNetworkClass();

BeginNetworkClass(CTESprite, DT_TESprite);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_fScale);
   NetworkProperty(m_nBrightness);
EndNetworkClass();

BeginNetworkClass(CTESpriteSpray, DT_TESpriteSpray);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_vecDirection);
   NetworkProperty(m_nModelIndex);
   NetworkProperty(m_fNoise);
   NetworkProperty(m_nSpeed);
   NetworkProperty(m_nCount);
EndNetworkClass();

BeginNetworkStruct(DT_ProxyToggle_ProxiedData);
   NetworkProperty(m_WithProxy);
EndNetworkStruct();

BeginNetworkClass(CTest_ProxyToggle_Networkable, DT_ProxyToggle);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(blah);
EndNetworkClass();

BeginNetworkClass(CTestTraceline, DT_TestTraceline);
   NetworkProperty(m_clrRender);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_angRotation);
   NetworkProperty(moveparent);
EndNetworkClass();

BeginNetworkClass(CTEUnitAnimation, DT_TEUnitAnimation);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_flCastPoint);
   NetworkProperty(m_hEntity);
   NetworkProperty(m_flPlaybackRate);
   NetworkProperty(m_iSequenceIndex);
   NetworkProperty(m_iType);
   NetworkProperty(m_Activity);
EndNetworkClass();

BeginNetworkClass(CTEUnitAnimationEnd, DT_TEUnitAnimationEnd);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_hEntity);
   NetworkProperty(m_bSnap);
EndNetworkClass();

BeginNetworkClass(CTEWorldDecal, DT_TEWorldDecal);
   NetworkBaseClass(CBaseTempEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_nIndex);
EndNetworkClass();

BeginNetworkClass(CTFWearableItem, DT_TFWearableItem);
   NetworkBaseClass(CEconWearable);
EndNetworkClass();

BeginNetworkClass(CTriggerCamera, DT_TriggerCamera);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_vecOrigin);
   NetworkProperty(m_angRotation);
EndNetworkClass();

BeginNetworkClass(CTriggerPlayerMovement, DT_TriggerPlayerMovement);
   NetworkBaseClass(CBaseTrigger);
EndNetworkClass();

BeginNetworkClass(CVGuiScreen, DT_VGuiScreen);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_flWidth);
   NetworkProperty(m_flHeight);
   NetworkProperty(m_nAttachmentIndex);
   NetworkProperty(m_nPanelName);
   NetworkProperty(m_fScreenFlags);
   NetworkProperty(m_nOverlayMaterial);
   NetworkProperty(m_hPlayerOwner);
EndNetworkClass();

BeginNetworkClass(CWaterBullet, DT_WaterBullet);
   NetworkBaseClass(CBaseAnimating);
EndNetworkClass();

BeginNetworkClass(CWaterLODControl, DT_WaterLODControl);
   NetworkProperty(m_flCheapWaterStartDistance);
   NetworkProperty(m_flCheapWaterEndDistance);
EndNetworkClass();

BeginNetworkClass(CWorld, DT_WORLD);
   NetworkBaseClass(CBaseEntity);
   NetworkProperty(m_flWaveHeight);
   NetworkProperty(m_WorldMins);
   NetworkProperty(m_WorldMaxs);
   NetworkProperty(m_bStartDark);
   NetworkProperty(m_flMaxOccludeeArea);
   NetworkProperty(m_flMinOccluderArea);
   NetworkProperty(m_flMaxPropScreenSpaceWidth);
   NetworkProperty(m_flMinPropScreenSpaceWidth);
   NetworkProperty(m_iszDetailSpriteMaterial);
   NetworkProperty(m_bColdWorld);
EndNetworkClass();

BeginNetworkClass(DustTrail, DT_DustTrail);
   NetworkBaseClass(CBaseParticleEntity);
   NetworkProperty(m_SpawnRate);
   NetworkProperty(m_Color);
   NetworkProperty(m_ParticleLifetime);
   NetworkProperty(m_StopEmitTime);
   NetworkProperty(m_MinSpeed);
   NetworkProperty(m_MaxSpeed);
   NetworkProperty(m_MinDirectedSpeed);
   NetworkProperty(m_MaxDirectedSpeed);
   NetworkProperty(m_StartSize);
   NetworkProperty(m_EndSize);
   NetworkProperty(m_SpawnRadius);
   NetworkProperty(m_bEmit);
   NetworkProperty(m_Opacity);
EndNetworkClass();

BeginNetworkClass(MovieExplosion, DT_MovieExplosion);
   NetworkBaseClass(CBaseParticleEntity);
EndNetworkClass();

BeginNetworkClass(NextBotCombatCharacter, DT_NextBot);
   NetworkBaseClass(CBaseCombatCharacter);
EndNetworkClass();

BeginNetworkClass(ParticleSmokeGrenade, DT_ParticleSmokeGrenade);
   NetworkBaseClass(CBaseParticleEntity);
   NetworkProperty(m_flSpawnTime);
   NetworkProperty(m_FadeStartTime);
   NetworkProperty(m_FadeEndTime);
   NetworkProperty(m_CurrentStage);
EndNetworkClass();

BeginNetworkClass(RocketTrail, DT_RocketTrail);
   NetworkBaseClass(CBaseParticleEntity);
   NetworkProperty(m_SpawnRate);
   NetworkProperty(m_StartColor);
   NetworkProperty(m_EndColor);
   NetworkProperty(m_ParticleLifetime);
   NetworkProperty(m_StopEmitTime);
   NetworkProperty(m_MinSpeed);
   NetworkProperty(m_MaxSpeed);
   NetworkProperty(m_StartSize);
   NetworkProperty(m_EndSize);
   NetworkProperty(m_SpawnRadius);
   NetworkProperty(m_bEmit);
   NetworkProperty(m_nAttachment);
   NetworkProperty(m_Opacity);
   NetworkProperty(m_bDamaged);
   NetworkProperty(m_flFlareScale);
EndNetworkClass();

BeginNetworkClass(SmokeTrail, DT_SmokeTrail);
   NetworkBaseClass(CBaseParticleEntity);
   NetworkProperty(m_SpawnRate);
   NetworkProperty(m_StartColor);
   NetworkProperty(m_EndColor);
   NetworkProperty(m_ParticleLifetime);
   NetworkProperty(m_StopEmitTime);
   NetworkProperty(m_MinSpeed);
   NetworkProperty(m_MaxSpeed);
   NetworkProperty(m_MinDirectedSpeed);
   NetworkProperty(m_MaxDirectedSpeed);
   NetworkProperty(m_StartSize);
   NetworkProperty(m_EndSize);
   NetworkProperty(m_SpawnRadius);
   NetworkProperty(m_bEmit);
   NetworkProperty(m_nAttachment);
   NetworkProperty(m_Opacity);
EndNetworkClass();

BeginNetworkClass(SporeExplosion, DT_SporeExplosion);
   NetworkBaseClass(CBaseParticleEntity);
   NetworkProperty(m_flSpawnRate);
   NetworkProperty(m_flParticleLifetime);
   NetworkProperty(m_flStartSize);
   NetworkProperty(m_flEndSize);
   NetworkProperty(m_flSpawnRadius);
   NetworkProperty(m_bEmit);
   NetworkProperty(m_bDontRemove);
EndNetworkClass();

BeginNetworkClass(SporeTrail, DT_SporeTrail);
   NetworkBaseClass(CBaseParticleEntity);
   NetworkProperty(m_flSpawnRate);
   NetworkProperty(m_vecEndColor);
   NetworkProperty(m_flParticleLifetime);
   NetworkProperty(m_flStartSize);
   NetworkProperty(m_flEndSize);
   NetworkProperty(m_flSpawnRadius);
   NetworkProperty(m_bEmit);
EndNetworkClass();

}
