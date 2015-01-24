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

BeginClientClass(CAI_BaseNPC, DT_AI_BaseNPC);
   ClientBaseClass(CBaseCombatCharacter);
   AddClientProperty(m_lifeState);
   AddClientProperty(m_bPerformAvoidance);
   AddClientProperty(m_bIsMoving);
   AddClientProperty(m_bFadeCorpse);
   AddClientProperty(m_iDeathPose);
   AddClientProperty(m_iDeathFrame);
   AddClientProperty(m_bSpeedModActive);
   AddClientProperty(m_iSpeedModRadius);
   AddClientProperty(m_iSpeedModSpeed);
   AddClientProperty(m_bImportanRagdoll);
   AddClientProperty(m_flTimePingEffect);
EndClientClass();

BeginClientStruct(DT_ServerAnimationData);
   AddClientProperty(m_flCycle);
EndClientStruct();

BeginClientClass(CBaseAnimating, DT_BaseAnimating);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_nForceBone);
   AddClientProperty(m_vecForce);
   AddClientProperty(m_nSkin);
   AddClientProperty(m_nBody);
   AddClientProperty(m_nHitboxSet);
   AddClientProperty(m_flModelScale);
   AddClientProperty(m_flPoseParameter);
   AddClientProperty(m_nSequence);
   AddClientProperty(m_flPlaybackRate);
   AddClientProperty(m_flEncodedController);
   AddClientProperty(m_bClientSideAnimation);
   AddClientProperty(m_bClientSideFrameReset);
   AddClientProperty(m_bClientSideRagdoll);
   AddClientProperty(m_nNewSequenceParity);
   AddClientProperty(m_nResetEventsParity);
   AddClientProperty(m_nMuzzleFlashParity);
   AddClientProperty(m_hLightingOrigin);
   AddClientProperty(serveranimdata);
   AddClientProperty(m_flFrozen);
EndClientClass();

BeginClientStruct(DT_Animationlayer);
   AddClientProperty(m_nSequence);
   AddClientProperty(m_flCycle);
   AddClientProperty(m_flPrevCycle);
   AddClientProperty(m_flWeight);
   AddClientProperty(m_nOrder);
EndClientStruct();

BeginClientStruct(DT_OverlayVars);
   AddClientProperty(m_AnimOverlay);
EndClientStruct();

BeginClientClass(CBaseAnimatingOverlay, DT_BaseAnimatingOverlay);
   ClientBaseClass(CBaseAnimating);
   AddClientProperty(overlay_vars);
EndClientClass();

BeginClientStruct(DT_AttributeContainer);
   AddClientProperty(m_hOuter);
   AddClientProperty(m_ProviderType);
   AddClientProperty(m_iReapplyProvisionParity);
   AddClientProperty(m_Item);
EndClientStruct();

BeginClientStruct(DT_AttributeList);
   AddClientProperty(m_Attributes);
EndClientStruct();

BeginClientStruct(DT_ScriptCreatedAttribute);
   AddClientProperty(m_iAttributeDefinitionIndex);
   AddClientProperty(m_iRawValue32);
EndClientStruct();

BeginClientStruct(DT_ScriptCreatedItem);
   AddClientProperty(m_iItemDefinitionIndex);
   AddClientProperty(m_iEntityLevel);
   AddClientProperty(m_iItemIDHigh);
   AddClientProperty(m_iItemIDLow);
   AddClientProperty(m_iAccountID);
   AddClientProperty(m_iEntityQuality);
   AddClientProperty(m_bInitialized);
   AddClientProperty(m_AttributeList);
EndClientStruct();

BeginClientClass(CBaseAttributableItem, DT_BaseAttributableItem);
   ClientBaseClass(CBaseAnimating);
   AddClientProperty(m_AttributeManager);
EndClientClass();

BeginClientClass(CBaseButton, DT_BaseButton);
   ClientBaseClass(CBaseToggle);
EndClientClass();

BeginClientStruct(DT_BCCLocalPlayerExclusive);
   AddClientProperty(m_flNextAttack);
   AddClientProperty(m_hMyWeapons);
EndClientStruct();

BeginClientClass(CBaseCombatCharacter, DT_BaseCombatCharacter);
   ClientBaseClass(CBaseFlex);
   AddClientProperty(bcc_localdata);
   AddClientProperty(m_hActiveWeapon);
EndClientClass();

BeginClientStruct(DT_LocalActiveWeaponData);
   AddClientProperty(m_flNextPrimaryAttack);
   AddClientProperty(m_flNextSecondaryAttack);
   AddClientProperty(m_nNextThinkTick);
   AddClientProperty(m_flTimeWeaponIdle);
EndClientStruct();

BeginClientStruct(DT_LocalWeaponData);
   AddClientProperty(m_iClip1);
   AddClientProperty(m_iClip2);
   AddClientProperty(m_iPrimaryAmmoType);
   AddClientProperty(m_iSecondaryAmmoType);
   AddClientProperty(m_nViewModelIndex);
EndClientStruct();

BeginClientClass(CBaseCombatWeapon, DT_BaseCombatWeapon);
   ClientBaseClass(CBaseAnimating);
   AddClientProperty(LocalWeaponData);
   AddClientProperty(LocalActiveWeaponData);
   AddClientProperty(m_iViewModelIndex);
   AddClientProperty(m_iWorldModelIndex);
   AddClientProperty(m_iState);
   AddClientProperty(m_hOwner);
EndClientClass();

BeginClientClass(CBaseDoor, DT_BaseDoor);
   ClientBaseClass(CBaseToggle);
   AddClientProperty(m_flWaveHeight);
EndClientClass();

BeginClientStruct(DT_AnimTimeMustBeFirst);
   AddClientProperty(m_flAnimTime);
EndClientStruct();

BeginClientStruct(DT_CollisionProperty);
   AddClientProperty(m_vecMins);
   AddClientProperty(m_vecMaxs);
   AddClientProperty(m_nSolidType);
   AddClientProperty(m_usSolidFlags);
   AddClientProperty(m_nSurroundType);
   AddClientProperty(m_triggerBloat);
   AddClientProperty(m_vecSpecifiedSurroundingMins);
   AddClientProperty(m_vecSpecifiedSurroundingMaxs);
EndClientStruct();

BeginClientClass(CBaseEntity, DT_BaseEntity);
   AddClientProperty(AnimTimeMustBeFirst);
   AddClientProperty(m_flSimulationTime);
   AddClientProperty(m_flCreateTime);
   AddClientProperty(m_ubInterpolationFrame);
   AddClientProperty(m_cellbits);
   AddClientProperty(m_cellX);
   AddClientProperty(m_cellY);
   AddClientProperty(m_cellZ);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_Collision);
   AddClientProperty(m_nRenderFX);
   AddClientProperty(m_nRenderMode);
   AddClientProperty(m_fEffects);
   AddClientProperty(m_clrRender);
   AddClientProperty(m_iTeamNum);
   AddClientProperty(m_CollisionGroup);
   AddClientProperty(m_flElasticity);
   AddClientProperty(m_flShadowCastDistance);
   AddClientProperty(m_hOwnerEntity);
   AddClientProperty(m_hEffectEntity);
   AddClientProperty(moveparent);
   AddClientProperty(m_iParentAttachment);
   AddClientProperty(m_iName);
   AddClientProperty(movetype);
   AddClientProperty(movecollide);
   AddClientProperty(m_angRotation);
   AddClientProperty(m_iTextureFrameIndex);
   AddClientProperty(m_bSimulatedEveryTick);
   AddClientProperty(m_bAnimatedEveryTick);
   AddClientProperty(m_bAlternateSorting);
   AddClientProperty(m_fadeMinDist);
   AddClientProperty(m_fadeMaxDist);
   AddClientProperty(m_flFadeScale);
   AddClientProperty(m_nMinCPULevel);
   AddClientProperty(m_nMaxCPULevel);
   AddClientProperty(m_nMinGPULevel);
   AddClientProperty(m_nMaxGPULevel);
EndClientClass();

BeginClientClass(CBaseFlex, DT_BaseFlex);
   ClientBaseClass(CBaseAnimatingOverlay);
   AddClientProperty(m_flexWeight);
   AddClientProperty(m_blinktoggle);
   AddClientProperty(m_viewtarget);
EndClientClass();

BeginClientClass(CBaseGrenade, DT_BaseGrenade);
   ClientBaseClass(CBaseCombatCharacter);
   AddClientProperty(m_flDamage);
   AddClientProperty(m_DmgRadius);
   AddClientProperty(m_bIsLive);
   AddClientProperty(m_hThrower);
   AddClientProperty(m_vecVelocity);
   AddClientProperty(m_fFlags);
EndClientClass();

BeginClientClass(CBaseParticleEntity, DT_BaseParticleEntity);
   ClientBaseClass(CBaseEntity);
EndClientClass();

BeginClientStruct(DT_Local);
   AddClientProperty(m_chAreaBits);
   AddClientProperty(m_chAreaPortalBits);
   AddClientProperty(m_iHideHUD);
   AddClientProperty(m_flFOVRate);
   AddClientProperty(m_bDucked);
   AddClientProperty(m_bDucking);
   AddClientProperty(m_bInDuckJump);
   AddClientProperty(m_nDuckTimeMsecs);
   AddClientProperty(m_nDuckJumpTimeMsecs);
   AddClientProperty(m_nJumpTimeMsecs);
   AddClientProperty(m_flFallVelocity);
   AddClientProperty(m_vecPunchAngle);
   AddClientProperty(m_vecPunchAngleVel);
   AddClientProperty(m_bDrawViewmodel);
   AddClientProperty(m_bWearingSuit);
   AddClientProperty(m_bPoisoned);
   AddClientProperty(m_flStepSize);
   AddClientProperty(m_bAllowAutoMovement);
   AddClientProperty(m_skybox3d.scale);
   AddClientProperty(m_skybox3d.origin);
   AddClientProperty(m_skybox3d.area);
   AddClientProperty(m_skybox3d.fog.enable);
   AddClientProperty(m_skybox3d.fog.blend);
   AddClientProperty(m_skybox3d.fog.dirPrimary);
   AddClientProperty(m_skybox3d.fog.colorPrimary);
   AddClientProperty(m_skybox3d.fog.colorSecondary);
   AddClientProperty(m_skybox3d.fog.start);
   AddClientProperty(m_skybox3d.fog.end);
   AddClientProperty(m_skybox3d.fog.maxdensity);
   AddClientProperty(m_skybox3d.fog.HDRColorScale);
   AddClientProperty(m_audio.localSound);
   AddClientProperty(m_audio.soundscapeIndex);
   AddClientProperty(m_audio.localBits);
   AddClientProperty(m_audio.entIndex);
EndClientStruct();

BeginClientStruct(DT_LocalPlayerExclusive);
   AddClientProperty(m_Local);
   AddClientProperty(m_vecViewOffset);
   AddClientProperty(m_flFriction);
   AddClientProperty(m_iAmmo);
   AddClientProperty(m_fOnTarget);
   AddClientProperty(m_nTickBase);
   AddClientProperty(m_nNextThinkTick);
   AddClientProperty(m_hLastWeapon);
   AddClientProperty(m_vecVelocity);
   AddClientProperty(m_vecBaseVelocity);
   AddClientProperty(m_hConstraintEntity);
   AddClientProperty(m_vecConstraintCenter);
   AddClientProperty(m_flConstraintRadius);
   AddClientProperty(m_flConstraintWidth);
   AddClientProperty(m_flConstraintSpeedFactor);
   AddClientProperty(m_bConstraintPastRadius);
   AddClientProperty(m_flDeathTime);
   AddClientProperty(m_nWaterLevel);
   AddClientProperty(m_flLaggedMovementValue);
   AddClientProperty(m_hTonemapController);
EndClientStruct();

BeginClientStruct(DT_PlayerState);
   AddClientProperty(deadflag);
EndClientStruct();

BeginClientClass(CBasePlayer, DT_BasePlayer);
   ClientBaseClass(CBaseCombatCharacter);
   AddClientProperty(pl);
   AddClientProperty(m_hVehicle);
   AddClientProperty(m_hUseEntity);
   AddClientProperty(m_hGroundEntity);
   AddClientProperty(m_iHealth);
   AddClientProperty(m_lifeState);
   AddClientProperty(m_iBonusProgress);
   AddClientProperty(m_iBonusChallenge);
   AddClientProperty(m_flMaxspeed);
   AddClientProperty(m_fFlags);
   AddClientProperty(m_iObserverMode);
   AddClientProperty(m_hObserverTarget);
   AddClientProperty(m_iFOV);
   AddClientProperty(m_iFOVStart);
   AddClientProperty(m_flFOVTime);
   AddClientProperty(m_iDefaultFOV);
   AddClientProperty(m_hZoomOwner);
   AddClientProperty(m_hViewModel);
   AddClientProperty(m_szLastPlaceName);
   AddClientProperty(m_vecLadderNormal);
   AddClientProperty(m_ladderSurfaceProps);
   AddClientProperty(m_hPostProcessCtrl);
   AddClientProperty(m_hColorCorrectionCtrl);
   AddClientProperty(m_PlayerFog.m_hCtrl);
   AddClientProperty(m_currentSCLPacked);
   AddClientProperty(m_hViewEntity);
   AddClientProperty(localdata);
EndClientClass();

BeginClientClass(CBasePropDoor, DT_BasePropDoor);
   ClientBaseClass(CDynamicProp);
EndClientClass();

BeginClientClass(CBaseTempEntity, DT_BaseTempEntity);
EndClientClass();

BeginClientClass(CBaseToggle, DT_BaseToggle);
   ClientBaseClass(CBaseEntity);
EndClientClass();

BeginClientClass(CBaseTrigger, DT_BaseTrigger);
   ClientBaseClass(CBaseToggle);
   AddClientProperty(m_bClientSidePredicted);
   AddClientProperty(m_spawnflags);
EndClientClass();

BeginClientClass(CBaseViewModel, DT_BaseViewModel);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_hWeapon);
   AddClientProperty(m_nBody);
   AddClientProperty(m_nSkin);
   AddClientProperty(m_nSequence);
   AddClientProperty(m_nViewModelIndex);
   AddClientProperty(m_flPlaybackRate);
   AddClientProperty(m_fEffects);
   AddClientProperty(m_nAnimationParity);
   AddClientProperty(m_hOwner);
   AddClientProperty(m_nNewSequenceParity);
   AddClientProperty(m_nResetEventsParity);
   AddClientProperty(m_nMuzzleFlashParity);
EndClientClass();

BeginClientClass(CBeam, DT_Beam);
   AddClientProperty(m_nBeamType);
   AddClientProperty(m_nBeamFlags);
   AddClientProperty(m_nNumBeamEnts);
   AddClientProperty(m_hAttachEntity);
   AddClientProperty(m_nAttachIndex);
   AddClientProperty(m_nHaloIndex);
   AddClientProperty(m_fHaloScale);
   AddClientProperty(m_fWidth);
   AddClientProperty(m_fEndWidth);
   AddClientProperty(m_fFadeLength);
   AddClientProperty(m_fAmplitude);
   AddClientProperty(m_fStartFrame);
   AddClientProperty(m_fSpeed);
   AddClientProperty(m_nRenderFX);
   AddClientProperty(m_nRenderMode);
   AddClientProperty(m_flFrameRate);
   AddClientProperty(m_flHDRColorScale);
   AddClientProperty(m_flFrame);
   AddClientProperty(m_clrRender);
   AddClientProperty(m_nClipStyle);
   AddClientProperty(m_vecEndPos);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(moveparent);
EndClientClass();

BeginClientClass(CBeamSpotlight, DT_BeamSpotlight);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_nHaloIndex);
   AddClientProperty(m_bSpotlightOn);
   AddClientProperty(m_bHasDynamicLight);
   AddClientProperty(m_flSpotlightMaxLength);
   AddClientProperty(m_flSpotlightGoalWidth);
   AddClientProperty(m_flHDRColorScale);
   AddClientProperty(m_flRotationSpeed);
   AddClientProperty(m_nRotationAxis);
EndClientClass();

BeginClientClass(CBoneFollower, DT_BoneFollower);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_modelIndex);
   AddClientProperty(m_solidIndex);
EndClientClass();

BeginClientClass(CBreakableProp, DT_BreakableProp);
   ClientBaseClass(CBaseAnimating);
   AddClientProperty(m_bClientPhysics);
EndClientClass();

BeginClientClass(CBreakableSurface, DT_BreakableSurface);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_nNumWide);
   AddClientProperty(m_nNumHigh);
   AddClientProperty(m_flPanelWidth);
   AddClientProperty(m_flPanelHeight);
   AddClientProperty(m_vNormal);
   AddClientProperty(m_vCorner);
   AddClientProperty(m_bIsBroken);
   AddClientProperty(m_nSurfaceType);
   AddClientProperty(m_RawPanelBitVec);
EndClientClass();

BeginClientClass(CColorCorrection, DT_ColorCorrection);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_MinFalloff);
   AddClientProperty(m_MaxFalloff);
   AddClientProperty(m_flCurWeight);
   AddClientProperty(m_flMaxWeight);
   AddClientProperty(m_flFadeInDuration);
   AddClientProperty(m_flFadeOutDuration);
   AddClientProperty(m_netlookupFilename);
   AddClientProperty(m_bEnabled);
   AddClientProperty(m_bMaster);
   AddClientProperty(m_bClientSide);
   AddClientProperty(m_bExclusive);
EndClientClass();

BeginClientClass(CColorCorrectionVolume, DT_ColorCorrectionVolume);
   AddClientProperty(m_Weight);
   AddClientProperty(m_lookupFilename);
EndClientClass();

BeginClientClass(CDOTA_Ability_AbyssalUnderlord_DarkRift, DT_DOTA_Ability_AbyssalUnderlord_DarkRift);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_AbyssalUnderlord_Firestorm, DT_DOTA_Ability_AbyssalUnderlord_Firestorm);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_AbyssalUnderlord_PitOfMalice, DT_DOTA_Ability_AbyssalUnderlord_PitOfMalice);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Alchemist_AcidSpray, DT_DOTA_Ability_Alchemist_AcidSpray);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_AncientApparition_ChillingTouch, DT_DOTA_Ability_AncientApparition_ChillingTouch);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_AncientApparition_ColdFeet, DT_DOTA_Ability_AncientApparition_ColdFeet);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_AncientApparition_IceBlast, DT_DOTA_Ability_AncientApparition_RocketFlare);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_AncientApparition_IceVortex, DT_DOTA_Ability_AncientApparition_IceVortex);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_AntiMage_Blink, DT_DOTA_Ability_AntiMage_Blink);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_AntiMage_ManaVoid, DT_DOTA_Ability_AntiMage_ManaVoid);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_AttributeBonus, DT_DOTA_Ability_AttributeBonus);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Axe_BerserkersCall, DT_DOTA_Ability_Axe_BerserkersCall);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Axe_CounterHelix, DT_DOTA_Ability_Axe_CounterHelix);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Axe_CullingBlade, DT_DOTA_Ability_Axe_CullingBlade);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Bane_FiendsGrip, DT_DOTA_Ability_Bane_FiendsGrip);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Batrider_Flamebreak, DT_DOTA_Ability_Batrider_Flamebreak);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Batrider_StickyNapalm, DT_DOTA_Ability_Batrider_StickyNapalm);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Beastmaster_PrimalRoar, DT_DOTA_Ability_Beastmaster_PrimalRoar);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Bloodseeker_Bloodbath, DT_DOTA_Ability_Bloodseeker_Bloodbath);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_BountyHunter_ShurikenToss, DT_DOTA_Ability_BountyHunter_ShurikenToss);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Brewmaster_DispelMagic, DT_DOTA_Ability_Brewmaster_DispelMagic);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Brewmaster_DrunkenBrawler, DT_DOTA_Ability_Brewmaster_DrunkenBrawler);
   ClientBaseClass(CDOTABaseAbility);
   AddClientProperty(m_iBrawlActive);
EndClientClass();

BeginClientClass(CDOTA_Ability_Brewmaster_DrunkenHaze, DT_DOTA_Ability_Brewmaster_DrunkenHaze);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Brewmaster_PrimalSplit, DT_DOTA_Ability_Brewmaster_PrimalSplit);
   ClientBaseClass(CDOTABaseAbility);
   AddClientProperty(m_hPrimary);
   AddClientProperty(m_hSecondary);
   AddClientProperty(m_hTertiary);
EndClientClass();

BeginClientClass(CDOTA_Ability_Bristleback_QuillSpray, DT_DOTA_Ability_Bristleback_QuillSpray);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Broodmother_SpinWeb, DT_DOTA_Ability_Broodmother_SpinWeb);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Centaur_Stampede, DT_DOTA_Ability_Centaur_Stampede);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_ChaosKnight_Phantasm, DT_DOTA_Ability_ChaosKnight_Phantasm);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Chen_HandOfGod, DT_DOTA_Ability_Chen_HandOfGod);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Chen_HolyPersuasion, DT_DOTA_Ability_Chen_HolyPersuasion);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Chen_TestOfFaithTeleport, DT_DOTA_Ability_Chen_TestOfFaithTeleport);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Courier_TakeStashItems, DT_DOTA_Ability_Courier_TakeStashItems);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Courier_TransferItems, DT_DOTA_Ability_Courier_TransferItems);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_CrystalMaiden_CrystalNova, DT_DOTA_Ability_CrystalMaiden_CrystalNova);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_CrystalMaiden_FreezingField, DT_DOTA_Ability_CrystalMaiden_FreezingField);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_DarkSeer_Vacuum, DT_DOTA_Ability_DarkSeer_Vacuum);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_DataDriven, DT_DOTA_Ability_DataDriven);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Dazzle_Weave, DT_DOTA_Ability_Dazzle_Weave);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_DeathProphet_CarrionSwarm, DT_DOTA_Ability_DeathProphet_CarrionSwarm);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_DeathProphet_Silence, DT_DOTA_Ability_DeathProphet_Silence);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Disruptor_KineticField, DT_DOTA_Ability_Disruptor_KineticField);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Disruptor_StaticStorm, DT_DOTA_Ability_Disruptor_StaticStorm);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_DoomBringer_Devour, DT_DOTA_Ability_DoomBringer_Devour);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_DragonKnight_BreatheFire, DT_DOTA_Unit_Ability_DragonKnight_BreatheFire);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_DrowRanger_Silence, DT_DOTA_Ability_DrowRanger_Silence);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_DrowRanger_WaveOfSilence, DT_DOTA_Unit_Ability_DrowRanger_WaveOfSilence);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_EarthSpirit_BoulderSmash, DT_DOTA_Ability_EarthSpirit_BoulderSmash);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_EarthSpirit_GeomagneticGrip, DT_DOTA_Ability_EarthSpirit_GeomagneticGrip);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_EarthSpirit_Petrify, DT_DOTA_Ability_EarthSpirit_Petrify);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_EarthSpirit_RollingBoulder, DT_DOTA_Ability_EarthSpirit_RollingBoulder);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_EarthSpirit_StoneCaller, DT_DOTA_Ability_EarthSpirit_StoneCaller);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Elder_Titan_EarthSplitter, DT_DOTA_Unit_Ability_Elder_Titan_EarthSplitter);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_EmberSpirit_Activate_FireRemnant, DT_DOTA_Ability_EmberSpirit_Activate_FireRemnant);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_EmberSpirit_FireRemnant, DT_DOTA_Ability_EmberSpirit_FireRemnant);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_EmberSpirit_SearingChains, DT_DOTA_Ability_EmberSpirit_SearingChains);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_EmberSpirit_SleightOfFist, DT_DOTA_Ability_EmberSpirit_SleightOfFist);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Enchantress_Impetus, DT_DOTA_Ability_Enchantress_Impetus);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Enchantress_NaturesAttendants, DT_DOTA_Ability_Enchantress_NaturesAttendants);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Enchantress_Untouchable, DT_DOTA_Ability_Enchantress_Untouchable);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Enigma_BlackHole, DT_DOTA_Ability_Enigma_BlackHole);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Enigma_DemonicConversion, DT_DOTA_Ability_Enigma_DemonicConversion);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Enigma_MidnightPulse, DT_DOTA_Ability_Enigma_MidnightPulse);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_FacelessVoid_Chronosphere, DT_DOTA_Ability_FacelessVoid_Chronosphere);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_FacelessVoid_TimeWalk, DT_DOTA_Unit_Ability_FacelessVoid_TimeWalk);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Furion_ForceOfNature, DT_DOTA_Ability_Furion_ForceOfNature);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Furion_Teleportation, DT_DOTA_Ability_Furion_Teleportation);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_BlackHole, DT_DOTA_Ability_Greevil_BlackHole);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_BladeFury, DT_DOTA_Ability_Greevil_BladeFury);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Bloodlust, DT_DOTA_Ability_Greevil_Bloodlust);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_ColdSnap, DT_DOTA_Ability_Greevil_ColdSnap);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Decrepify, DT_DOTA_Ability_Greevil_Decrepify);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Diabolic_Edict, DT_DOTA_Ability_Greevil_Diabolic_Edict);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_EchoSlam, DT_DOTA_Ability_Greevil_EchoSlam);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Fatal_Bonds, DT_DOTA_Ability_Greevil_Fatal_Bonds);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_FleshGolem, DT_DOTA_Ability_Greevil_FleshGolem);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_IceWall, DT_DOTA_Ability_Greevil_IceWall);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_LagunaBlade, DT_DOTA_Ability_Greevil_LagunaBlade);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_LeechSeed, DT_DOTA_Ability_Greevil_LeechSeed);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Magic_Missile, DT_DOTA_Ability_Greevil_Magic_Missile);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Maledict, DT_DOTA_Ability_Greevil_Maledict);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_MeatHook, DT_DOTA_Ability_Greevil_MeatHook);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Miniboss_Black_BrainSap, DT_DOTA_Ability_Greevil_Miniboss_Black_BrainSap);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Miniboss_Black_Nightmare, DT_DOTA_Ability_Greevil_Miniboss_Black_Nightmare);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Miniboss_Blue_ColdFeet, DT_DOTA_Ability_Greevil_Miniboss_White_ColdFeet);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Miniboss_Blue_IceVortex, DT_DOTA_Ability_Greevil_Miniboss_White_IceVortex);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Miniboss_Green_LivingArmor, DT_DOTA_Ability_Greevil_Miniboss_Green_LivingArmor);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Miniboss_Green_Overgrowth, DT_DOTA_Ability_Greevil_Miniboss_Green_Overgrowth);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Miniboss_Orange_DragonSlave, DT_DOTA_Ability_Greevil_Miniboss_Orange_DragonSlave);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Miniboss_Orange_LightStrikeArray, DT_DOTA_Ability_Greevil_Miniboss_Orange_LightStrikeArray);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Miniboss_Purple_PlagueWard, DT_DOTA_Ability_Greevil_Miniboss_Purple_PlagueWard);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Miniboss_Purple_VenomousGale, DT_DOTA_Ability_Greevil_Miniboss_Purple_VenomousGale);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Miniboss_Red_Earthshock, DT_DOTA_Ability_Greevil_Miniboss_Red_Earthshock);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Miniboss_Red_Overpower, DT_DOTA_Ability_Greevil_Miniboss_Red_Overpower);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Miniboss_Sight, DT_DOTA_Ability_Greevil_Miniboss_Sight);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Miniboss_White_Degen_Aura, DT_DOTA_Ability_Greevil_Miniboss_White_Degen_Aura);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Miniboss_White_Purification, DT_DOTA_Ability_Greevil_Miniboss_White_Purification);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Miniboss_Yellow_IonShell, DT_DOTA_Ability_Greevil_Miniboss_Yellow_IonShell);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Miniboss_Yellow_Surge, DT_DOTA_Ability_Greevil_Miniboss_Yellow_Surge);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_NaturesAttendants, DT_DOTA_Ability_Greevil_NaturesAttendants);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_PhantomStrike, DT_DOTA_Ability_Greevil_PhantomStrike);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_PoisonNova, DT_DOTA_Ability_Greevil_PoisonNova);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Purification, DT_DOTA_Ability_Greevil_Purification);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_Rot, DT_DOTA_Ability_Greevil_Rot);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_ShadowStrike, DT_DOTA_Ability_Greevil_ShadowStrike);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_ShadowWave, DT_DOTA_Ability_Greevil_ShadowWave);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Greevil_TimeLock, DT_DOTA_Ability_Greevil_TimeLock);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Gyrocopter_Call_Down, DT_DOTA_Ability_Gyrocopter_Call_Down);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Healing_Campfire, DT_DOTA_Ability_Healing_Campfire);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Holdout_CullingBlade, DT_DOTA_Ability_Holdout_CullingBlade);
   ClientBaseClass(CDOTA_Ability_Axe_CullingBlade);
EndClientClass();

BeginClientClass(CDOTA_Ability_Holdout_GladiatorsUnite, DT_DOTA_Ability_Holdout_GladiatorsUnite);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Holdout_Multishot, DT_DOTA_Ability_Holdout_Multishot);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Holdout_Omnislash, DT_DOTA_Ability_Holdout_Omnislash);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Huskar_Life_Break, DT_DOTA_Ability_Huskar_Life_Break);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Invoker_DeafeningBlast, DT_DOTA_Unit_Ability_Invoker_DeafeningBlast);
   ClientBaseClass(CDOTA_Ability_Invoker_InvokedBase);
EndClientClass();

BeginClientClass(CDOTA_Ability_Invoker_EMP, DT_DOTA_Ability_Invoker_EMP);
   ClientBaseClass(CDOTA_Ability_Invoker_InvokedBase);
EndClientClass();

BeginClientClass(CDOTA_Ability_Invoker_Invoke, DT_DOTA_Ability_Invoker_Invoke);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Invoker_InvokedBase, DT_DOTA_Ability_Invoker_InvokedBase);
   ClientBaseClass(CDOTABaseAbility);
   AddClientProperty(m_nQuasLevel);
   AddClientProperty(m_nWexLevel);
   AddClientProperty(m_nExortLevel);
EndClientClass();

BeginClientClass(CDOTA_Ability_Invoker_SunStrike, DT_DOTA_Ability_Invoker_SunStrike);
   ClientBaseClass(CDOTA_Ability_Invoker_InvokedBase);
EndClientClass();

BeginClientClass(CDOTA_Ability_Invoker_Tornado, DT_DOTA_Unit_Ability_Invoker_Tornado);
   ClientBaseClass(CDOTA_Ability_Invoker_InvokedBase);
EndClientClass();

BeginClientClass(CDOTA_Ability_Jakiro_DualBreath, DT_DOTA_Unit_Ability_Jakiro_DualBreath);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Jakiro_IcePath, DT_DOTA_Unit_Ability_Jakiro_IcePath);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Jakiro_Macropyre, DT_DOTA_Unit_Ability_Jakiro_Macropyre);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Juggernaut_HealingWard, DT_DOTA_Ability_Juggernaut_HealingWard);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Juggernaut_Omnislash, DT_DOTA_Ability_Juggernaut_Omnislash);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_KeeperOfTheLight_BlindingLight, DT_DOTA_Ability_KeeperOfTheLight_BlindingLight);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_KeeperOfTheLight_Illuminate, DT_DOTA_Unit_Ability_KeeperOfTheLight_Illuminate);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_KeeperOfTheLight_Recall, DT_DOTA_Ability_KeeperOfTheLight_Recall);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Kunkka_GhostShip, DT_DOTA_Unit_Ability_Kunkka_GhostShip);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Kunkka_Tidebringer, DT_DOTA_Ability_Kunkka_Tidebringer);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Kunkka_Torrent, DT_DOTA_Ability_Kunkka_Torrent);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Legion_Commander_MomentOfCourage, DT_DOTA_Ability_Legion_Commander_MomentOfCourage);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Legion_Commander_OverwhelmingOdds, DT_DOTA_Ability_Legion_Commander_OverwhelmingOdds);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Leshrac_Diabolic_Edict, DT_DOTA_Ability_Leshrac_Diabolic_Edict);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Leshrac_Pulse_Nova, DT_DOTA_Ability_Leshrac_Pulse_Nova);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Leshrac_Split_Earth, DT_DOTA_Ability_Leshrac_Split_Earth);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Lich_ChainFrost, DT_DOTA_Ability_Lich_ChainFrost);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Lich_FrostNova, DT_DOTA_Ability_Lich_FrostNova);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Life_Stealer_Infest, DT_DOTA_Ability_Life_Stealer_Infest);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Lina_DragonSlave, DT_DOTA_Unit_Ability_Lina_DragonSlave);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Lina_LagunaBlade, DT_DOTA_Ability_Lina_LagunaBlade);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Lina_LightStrikeArray, DT_DOTA_Ability_Lina_LightStrikeArray);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Lion_FingerOfDeath, DT_DOTA_Ability_Lion_FingerOfDeath);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Lion_Impale, DT_DOTA_Unit_Ability_Lion_Impale);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Lion_ManaDrain, DT_DOTA_Ability_Lion_ManaDrain);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_LoneDruid_Rabid, DT_DOTA_Ability_LoneDruid_Rabid);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_LoneDruid_SpiritBear, DT_DOTA_Ability_LoneDruid_SpiritBear);
   ClientBaseClass(CDOTABaseAbility);
   AddClientProperty(m_hBear);
EndClientClass();

BeginClientClass(CDOTA_Ability_LoneDruid_SpiritBear_Return, DT_DOTA_Ability_LoneDruid_SpiritBear_Return);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_LoneDruid_TrueForm_BattleCry, DT_DOTA_Ability_LoneDruid_TrueForm_BattleCry);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_LoneDruid_TrueForm_Druid, DT_DOTA_Ability_LoneDruid_TrueForm_Druid);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Luna_Eclipse, DT_DOTA_Ability_Luna_Eclipse);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Luna_LunarBlessing, DT_DOTA_Ability_Luna_LunarBlessing);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Lycan_Howl, DT_DOTA_Ability_Lycan_Howl);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Lycan_SummonWolves, DT_DOTA_Ability_Lycan_SummonWolves);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Magnataur_ReversePolarity, DT_DOTA_Ability_Magnataur_ReversePolarity);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Magnataur_Shockwave, DT_DOTA_Unit_Ability_Magnataur_Shockwave);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Meepo_DividedWeStand, DT_DOTA_Ability_Meepo_DividedWeStand);
   ClientBaseClass(CDOTABaseAbility);
   AddClientProperty(m_entPrimeDividedWeStand);
   AddClientProperty(m_entNextDividedWeStand);
   AddClientProperty(m_nWhichDividedWeStand);
   AddClientProperty(m_nNumDividedWeStand);
EndClientClass();

BeginClientClass(CDOTA_Ability_Meepo_Earthbind, DT_DOTA_Ability_Meepo_Earthbind);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Meepo_Poof, DT_DOTA_Ability_Meepo_Poof);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Morphling_Replicate, DT_DOTA_Ability_Morphling_Replicate);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Morphling_Waveform, DT_DOTA_Unit_Ability_Morphling_Waveform);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_NagaSiren_MirrorImage, DT_DOTA_Ability_NagaSiren_MirrorImage);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_NagaSiren_RipTide, DT_DOTA_Ability_NagaSiren_RipTide);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Necrolyte_Death_Pulse, DT_DOTA_Ability_Necrolyte_Death_Pulse);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Necrolyte_ReapersScythe, DT_DOTA_Ability_Necrolyte_ReapersScythe);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Nevermore_Requiem, DT_Ability_Nevermore_Requiem);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Nian_Apocalypse, DT_DOTA_Ability_Nian_Apocalypse);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Nian_Eruption, DT_DOTA_Ability_Nian_Eruption);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Nian_Frenzy, DT_DOTA_Ability_Nian_Frenzy);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Nian_Hurricane, DT_DOTA_Ability_Nian_Hurricane);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Nian_Roar, DT_DOTA_Ability_Nian_Roar);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Nian_Sigils, DT_DOTA_Ability_Nian_Sigils);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Nian_Tail_Swipe, DT_DOTA_Ability_Nian_Tail_Swipe);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Nian_Waterball, DT_DOTA_Ability_Nian_Waterball);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Nian_Whirlpool, DT_DOTA_Ability_Nian_Whirlpool);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Nyx_Assassin_Impale, DT_DOTA_Unit_Ability_Nyx_Assassin_Impale);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Obsidian_Destroyer_ArcaneOrb, DT_DOTA_Ability_Obsidian_Destroyer_ArcaneOrb);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Obsidian_Destroyer_AstralImprisonment, DT_DOTA_Ability_Obsidian_Destroyer_AstralImprisonment);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Obsidian_Destroyer_SanityEclipse, DT_Ability_Obsidian_Destroyer_SanityEclipse);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Ogre_Magi_Bloodlust, DT_DOTA_Ability_Ogre_Magi_Bloodlust);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Ogre_Magi_Fireblast, DT_DOTA_Ability_Ogre_Magi_Fireblast);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Ogre_Magi_Multicast, DT_DOTA_Ability_Ogre_Magi_Multicast);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Ogre_Magi_Unrefined_Fireblast, DT_DOTA_Ability_Ogre_Magi_Unrefined_Fireblast);
   ClientBaseClass(CDOTA_Ability_Ogre_Magi_Fireblast);
EndClientClass();

BeginClientClass(CDOTA_Ability_Oracle_FortunesEnd, DT_DOTA_Ability_Oracle_FortunesEnd);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_PhantomAssassin_PhantomStrike, DT_DOTA_Ability_PhantomAssassin_PhantomStrike);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_PhantomLancer_Doppelwalk, DT_DOTA_Ability_PhantomLancer_Doppelwalk);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Phoenix_LaunchFireSpirit, DT_DOTA_Unit_Ability_Phoenix_LaunchFireSpirit);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Phoenix_Supernova, DT_DOTA_Ability_Phoenix_Supernova);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Puck_DreamCoil, DT_DOTA_Ability_Puck_DreamCoil);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Puck_IllusoryOrb, DT_DOTA_Unit_Ability_Puck_IllusoryOrb);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Puck_WaningRift, DT_DOTA_Ability_Puck_WaningRift);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Pudge_Dismember, DT_DOTA_Ability_Pudge_Dismember);
   ClientBaseClass(CDOTABaseAbility);
   AddClientProperty(m_hVictim);
EndClientClass();

BeginClientClass(CDOTA_Ability_Pudge_MeatHook, DT_DOTA_Unit_Ability_Pudge_MeatHook);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Pugna_Decrepify, DT_DOTA_Ability_Pugna_Decrepify);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Pugna_LifeDrain, DT_DOTA_Ability_Pugna_LifeDrain);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Pugna_NetherBlast, DT_DOTA_Ability_Pugna_NetherBlast);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_QueenOfPain_Blink, DT_DOTA_Ability_QueenOfPain_Blink);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_QueenOfPain_SonicWave, DT_DOTA_Unit_Ability_QueenOfPain_SonicWave);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Rattletrap_BatteryAssault, DT_DOTA_Ability_Rattletrap_BatteryAssault);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Rattletrap_Hookshot, DT_DOTA_Ability_Rattletrap_Hookshot);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Rattletrap_RocketFlare, DT_DOTA_Ability_Rattletrap_RocketFlare);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Razor_PlasmaField, DT_DOTA_Ability_Razor_PlasmaField);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Riki_BlinkStrike, DT_DOTA_Ability_Riki_BlinkStrike);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Riki_SmokeScreen, DT_DOTA_Ability_Riki_SmokeScreen);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Roshan_Halloween_Apocalypse, DT_DOTA_Ability_Roshan_Halloween_Apocalypse);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Roshan_Halloween_Burn, DT_DOTA_Ability_Roshan_Halloween_Burn);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Roshan_Halloween_Fireball, DT_DOTA_Ability_Roshan_Halloween_Fireball);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Roshan_Toss, DT_DOTA_Ability_Roshan_Toss);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Roshan_WaveOfForce, DT_DOTA_Ability_Roshan_WaveOfForce);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Rubick_SpellSteal, DT_DOTA_Ability_Rubick_SpellSteal);
   ClientBaseClass(CDOTABaseAbility);
   AddClientProperty(m_ActivityModifier);
   AddClientProperty(m_fStolenCastPoint);
EndClientClass();

BeginClientClass(CDOTA_Ability_Rubick_TelekinesisLand, DT_DOTA_Ability_Rubick_TelekinesisLand);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_SandKing_BurrowStrike, DT_DOTA_Unit_Ability_SandKing_BurrowStrike);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_SandKing_Epicenter, DT_DOTA_Ability_SandKing_Epicenter);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_SatyrTrickster_Purge, DT_DOTA_Ability_SatyrTrickster_Purge);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Shadow_Demon_Disruption, DT_DOTA_Ability_Shadow_Demon_Disruption);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Shadow_Demon_Shadow_Poison, DT_DOTA_Unit_Ability_Shadow_Demon_Shadow_Poison);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Shadow_Demon_Soul_Catcher, DT_DOTA_Ability_Shadow_Demon_Soul_Catcher);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Shredder_Chakram, DT_DOTA_Ability_Shredder_Chakram);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Shredder_TimberChain, DT_DOTA_Ability_Shredder_TimberChain);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Silencer_CurseOfTheSilent, DT_DOTA_Ability_Silencer_CurseOfTheSilent);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Silencer_GlaivesOfWisdom, DT_DOTA_Ability_Silencer_GlaivesOfWisdom);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Skywrath_Mage_Mystic_Flare, DT_DOTA_Ability_Skywrath_Mage_Mystic_Flare);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Slardar_Slithereen_Crush, DT_DOTA_Ability_Slardar_Slithereen_Crush);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Slark_EssenceShift, DT_DOTA_Ability_Slark_EssenceShift);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Sniper_Shrapnel, DT_DOTA_Ability_Sniper_Shrapnel);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_SpiritBreaker_NetherStrike, DT_DOTA_Ability_SpiritBreaker_NetherStrike);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_StormSpirit_BallLightning, DT_DOTA_Ability_StormSpirit_BallLightning);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Sven_StormBolt, DT_DOTA_Ability_Sven_StormBolt);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Techies_FocusedDetonate, DT_DOTA_Ability_Techies_FocusedDetonate);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Techies_LandMines, DT_DOTA_Ability_Techies_LandMines);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Techies_Minefield_Sign, DT_DOTA_Ability_Techies_Minefield_Sign);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Techies_RemoteMines, DT_DOTA_Ability_Techies_RemoteMines);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Techies_RemoteMines_SelfDetonate, DT_DOTA_Ability_Techies_RemoteMines_SelfDetonate);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Techies_StasisTrap, DT_DOTA_Ability_Techies_StasisTrap);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Terrorblade_Sunder, DT_DOTA_Ability_Terrorblade_Sunder);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Throw_Coal, DT_DOTA_Ability_Throw_Coal);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Throw_Snowball, DT_DOTA_Ability_Throw_Snowball);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Tidehunter_AnchorSmash, DT_DOTA_Ability_Tidehunter_AnchorSmash);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Tidehunter_Ravage, DT_DOTA_Ability_Tidehunter_Ravage);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Tiny_Avalanche, DT_DOTA_Ability_Tiny_Avalanche);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Tiny_CraggyExterior, DT_DOTA_Ability_Tiny_CraggyExterior);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Tiny_Toss, DT_DOTA_Ability_Tiny_Toss);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Treant_EyesInTheForest, DT_DOTA_Ability_Treant_EyesInTheForest);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Treant_Overgrowth, DT_DOTA_Ability_Treant_Overgrowth);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_TrollWarlord_BerserkersRage, DT_DOTA_Ability_TrollWarlord_BerserkersRage);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_TrollWarlord_WhirlingAxes_Ranged, DT_DOTA_Unit_Ability_TrollWarlord_WhirlingAxes_Ranged);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Tusk_FrozenSigil, DT_DOTA_Ability_Tusk_FrozenSigil);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Undying_Decay, DT_DOTA_Ability_Undying_Decay);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Undying_SoulRip, DT_DOTA_Ability_Undying_SoulRip);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_VengefulSpirit_Nether_Swap, DT_DOTA_Ability_VengefulSpirit_Nether_Swap);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_VengefulSpirit_WaveOfTerror, DT_DOTA_Unit_Ability_VengefulSpirit_WaveOfTerror);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Venomancer_PoisonNova, DT_DOTA_Ability_Venomancer_PoisonNova);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Venomancer_VenomousGale, DT_DOTA_Unit_Ability_Venomancer_VenomousGale);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Viper_ViperStrike, DT_DOTA_Ability_Viper_ViperStrike);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Visage_SummonFamiliars, DT_DOTA_Ability_Visage_SummonFamiliars);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Visage_SummonFamiliars_StoneForm, DT_DOTA_Ability_Visage_SummonFamiliars_StoneForm);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Warlock_RainOfChaos, DT_DOTA_Ability_Warlock_RainOfChaos);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Warlock_Shadow_Word, DT_DOTA_Ability_Warlock_Shadow_Word);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Warlock_Upheaval, DT_DOTA_Ability_Warlock_Upheaval);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Weaver_TheSwarm, DT_DOTA_Unit_Ability_Weaver_TheSwarm);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Windrunner_FocusFire, DT_DOTA_Ability_Windrunner_FocusFire);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Windrunner_Powershot, DT_DOTA_Unit_Ability_Windrunner_Powershot);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Winter_Wyvern_Arctic_Burn, DT_DOTA_Unit_Ability_Winter_Wyvern_Arctic_Burn);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Winter_Wyvern_Cold_Embrace, DT_DOTA_Unit_Ability_Winter_Wyvern_Cold_Embrace);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Winter_Wyvern_Winters_Curse, DT_DOTA_Unit_Ability_Winter_Wyvern_Winters_Curse);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Wisp_Overcharge, DT_DOTA_Ability_Wisp_Overcharge);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Wisp_Relocate, DT_DOTA_Ability_Wisp_Relocate);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Wisp_Spirits, DT_DOTA_Ability_Wisp_Spirits);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_Wisp_Tether, DT_DOTA_Ability_Wisp_Tether);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_WitchDoctor_Maledict, DT_DOTA_Ability_WitchDoctor_Maledict);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_WitchDoctor_ParalyzingCask, DT_DOTA_Ability_WitchDoctor_ParalyzingCask);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientClass(CDOTA_Ability_WitchDoctor_VoodooRestoration, DT_DOTA_Ability_WitchDoctor_VoodooRestoration);
   ClientBaseClass(CDOTABaseAbility);
EndClientClass();

BeginClientStruct(DT_DOTA_ModifierManager);
   AddClientProperty(m_hModifierParent);
EndClientStruct();

BeginClientStruct(DT_DOTA_UnitInventory);
   AddClientProperty(m_hItems);
   AddClientProperty(m_iParity);
   AddClientProperty(m_hInventoryParent);
   AddClientProperty(m_bStashEnabled);
   AddClientProperty(m_hTransientCastItem);
EndClientStruct();

BeginClientClass(CDOTA_BaseNPC, DT_DOTA_BaseNPC);
   ClientBaseClass(NextBotCombatCharacter);
   AddClientProperty(m_iCurrentLevel);
   AddClientProperty(m_iCustomXPValue);
   AddClientProperty(m_iIsControllableByPlayer);
   AddClientProperty(m_bIsPhantom);
   AddClientProperty(m_bIsAncient);
   AddClientProperty(m_bStolenScepter);
   AddClientProperty(m_bIsNeutralUnitType);
   AddClientProperty(m_bIsSummoned);
   AddClientProperty(m_bCanBeDominated);
   AddClientProperty(m_bHasUpgradeableAbilities);
   AddClientProperty(m_iBKBChargesUsed);
   AddClientProperty(m_iHealth);
   AddClientProperty(m_flHealthThinkRegen);
   AddClientProperty(m_iMaxHealth);
   AddClientProperty(m_iAttackCapabilities);
   AddClientProperty(m_iDayTimeVisionRange);
   AddClientProperty(m_iNightTimeVisionRange);
   AddClientProperty(m_flMana);
   AddClientProperty(m_flMaxMana);
   AddClientProperty(m_flManaThinkRegen);
   AddClientProperty(m_hAbilities);
   AddClientProperty(m_iUnitNameIndex);
   AddClientProperty(m_iDamageMin);
   AddClientProperty(m_iDamageMax);
   AddClientProperty(m_iDamageBonus);
   AddClientProperty(m_lifeState);
   AddClientProperty(m_ModifierManager);
   AddClientProperty(m_Inventory);
   AddClientProperty(m_nUnitState);
   AddClientProperty(m_iTaggedAsVisibleByTeam);
   AddClientProperty(m_iCurShop);
   AddClientProperty(m_anglediff);
   AddClientProperty(m_fFlags);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_cellX);
   AddClientProperty(m_cellY);
   AddClientProperty(m_cellZ);
   AddClientProperty(m_angRotation);
   AddClientProperty(m_NetworkActivity);
   AddClientProperty(m_NetworkSequenceIndex);
   AddClientProperty(m_iBotDebugData);
   AddClientProperty(m_hMyWearables);
   AddClientProperty(m_bShouldDoFlyHeightVisual);
   AddClientProperty(m_nTotalDamageTaken);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Additive, DT_DOTA_BaseNPC_Additive);
   ClientBaseClass(CDOTA_BaseNPC);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Barracks, DT_DOTA_BaseNPC_Barracks);
   ClientBaseClass(CDOTA_BaseNPC_Building);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Building, DT_DOTA_BaseNPC_Building);
   ClientBaseClass(CDOTA_BaseNPC);
   AddClientProperty(m_nFXIndex);
   AddClientProperty(m_nFXIndexDestruction);
   AddClientProperty(m_angInitialAngles);
   AddClientProperty(m_hHeroStatueSequence);
   AddClientProperty(m_fHeroStatueCycle);
   AddClientProperty(m_iHeroStatueStatusEffectIndex);
   AddClientProperty(m_bHeroStatue);
   AddClientProperty(m_HeroStatueInscription);
   AddClientProperty(m_iHeroStatueOwnerPlayerID);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Creature, DT_DOTA_BaseNPC_Creature);
   ClientBaseClass(CDOTA_BaseNPC_Creep);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Creep, DT_DOTA_BaseNPC_Creep);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
   AddClientProperty(m_bIsWaitingToSpawn);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Creep_Diretide, DT_DOTA_BaseNPC_Creep_Diretide);
   ClientBaseClass(CDOTA_BaseNPC_Creep_Lane);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Creep_Lane, DT_DOTA_BaseNPC_Creep_Lane);
   ClientBaseClass(CDOTA_BaseNPC_Creep);
   AddClientProperty(m_iHealthPercentage);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Creep_LootGreevil, DT_DOTA_BaseNPC_Creep_LootGreevil);
   ClientBaseClass(CDOTA_BaseNPC_Creep);
   AddClientProperty(m_bIsRareLootGreevil);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Creep_Neutral, DT_DOTA_BaseNPC_Creep_Neutral);
   ClientBaseClass(CDOTA_BaseNPC_Creep);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Creep_Siege, DT_DOTA_BaseNPC_Creep_Siege);
   ClientBaseClass(CDOTA_BaseNPC_Creep_Lane);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Creep_Talking, DT_DOTA_BaseNPC_Creep_Talking);
   ClientBaseClass(CDOTA_BaseNPC_Creep);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Fort, DT_DOTA_BaseNPC_Fort);
   ClientBaseClass(CDOTA_BaseNPC_Building);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_HallofFame, DT_DOTA_BaseNPC_HallofFame);
   ClientBaseClass(CDOTA_BaseNPC_Building);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Hero, DT_DOTA_BaseNPC_Hero);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
   AddClientProperty(m_iCurrentXP);
   AddClientProperty(m_flRespawnTime);
   AddClientProperty(m_flRespawnTimePenalty);
   AddClientProperty(m_iAbilityPoints);
   AddClientProperty(m_flStrength);
   AddClientProperty(m_flAgility);
   AddClientProperty(m_flIntellect);
   AddClientProperty(m_flStrengthTotal);
   AddClientProperty(m_flAgilityTotal);
   AddClientProperty(m_flIntellectTotal);
   AddClientProperty(m_iRecentDamage);
   AddClientProperty(m_iPlayerID);
   AddClientProperty(m_bReincarnating);
   AddClientProperty(m_flSpawnedAt);
   AddClientProperty(m_hReplicatingOtherHeroModel);
   AddClientProperty(m_hEconConsumableAbility);
   AddClientProperty(m_bCustomKillEffect);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_HoldoutTower, DT_DOTA_BaseNPC_HoldoutTower);
   ClientBaseClass(CDOTA_BaseNPC_Tower);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_HoldoutTower_HeavySlow, DT_DOTA_BaseNPC_HoldoutTower_HeavySlow);
   ClientBaseClass(CDOTA_BaseNPC_HoldoutTower);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_HoldoutTower_LightFast, DT_DOTA_BaseNPC_HoldoutTower_LightFast);
   ClientBaseClass(CDOTA_BaseNPC_HoldoutTower);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_HoldoutTower_ReduceSpeed, DT_DOTA_BaseNPC_HoldoutTower_ReduceSpeed);
   ClientBaseClass(CDOTA_BaseNPC_HoldoutTower);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Invoker_Forged_Spirit, DT_DOTA_BaseNPC_Invoker_Forged_Spirit);
   ClientBaseClass(CDOTA_BaseNPC_Creep);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_ShadowShaman_SerpentWard, DT_DOTA_BaseNPC_ShadowShaman_SerpentWard);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Shop, DT_DOTA_BaseNPC_Shop);
   ClientBaseClass(CDOTA_BaseNPC_Building);
   AddClientProperty(m_ShopType);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Tower, DT_DOTA_BaseNPC_Tower);
   ClientBaseClass(CDOTA_BaseNPC_Building);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Tusk_Sigil, DT_DOTA_BaseNPC_Tusk_Sigil);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Venomancer_PlagueWard, DT_DOTA_BaseNPC_Venomancer_PlagueWard);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
EndClientClass();

BeginClientClass(CDOTA_BaseNPC_Warlock_Golem, DT_DOTA_BaseNPC_Warlock_Golem);
   ClientBaseClass(CDOTA_BaseNPC_Creep);
EndClientClass();

BeginClientClass(CDOTA_Beastmaster_Axe, DT_DOTA_Beastmaster_Axe);
   ClientBaseClass(CBaseAnimating);
   AddClientProperty(m_vecOrigin);
EndClientClass();

BeginClientClass(CDOTA_DataDire, DT_DOTA_DataDire);
   ClientBaseClass(CDOTA_DataNonSpectator);
EndClientClass();

BeginClientClass(CDOTA_DataNonSpectator, DT_DOTA_DataNonSpectator);
   AddClientProperty(m_iReliableGold);
   AddClientProperty(m_iUnreliableGold);
   AddClientProperty(m_iStartingPositions);
EndClientClass();

BeginClientClass(CDOTA_DataRadiant, DT_DOTA_DataRadiant);
   ClientBaseClass(CDOTA_DataNonSpectator);
EndClientClass();

BeginClientClass(CDOTA_DataSpectator, DT_DOTA_DataSpectator);
   AddClientProperty(m_hPrimaryRune);
   AddClientProperty(m_hSecondaryRune);
   AddClientProperty(m_iNetWorth);
EndClientClass();

BeginClientClass(CDOTA_DeathProphet_Exorcism_Spirit, DT_DOTA_DeathProphet_Exorcism_Spirit);
   ClientBaseClass(CBaseAnimating);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_angRotation);
EndClientClass();

BeginClientClass(CDOTA_DisplacementVisibility, DT_DOTA_DisplacementVisibility);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_HiddenDisplacement);
EndClientClass();

BeginClientClass(CDOTA_Halloween_CandyBucket, DT_DOTA_Halloween_CandyBucket);
   ClientBaseClass(CDOTA_BaseNPC);
EndClientClass();

BeginClientClass(CDOTA_Halloween_CandyBucketDire, DT_DOTA_Halloween_CandyBucketDire);
   ClientBaseClass(CDOTA_Halloween_CandyBucket);
EndClientClass();

BeginClientClass(CDOTA_Halloween_CandyBucketRadiant, DT_DOTA_Halloween_CandyBucketRadiant);
   ClientBaseClass(CDOTA_Halloween_CandyBucket);
EndClientClass();

BeginClientClass(CDOTA_Hero_Recorder, DT_DOTA_Hero_Recorder);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_bStartRecording);
   AddClientProperty(m_hHero);
   AddClientProperty(m_hPlayer);
EndClientClass();

BeginClientClass(CDOTA_Item, DT_DOTA_Item);
   ClientBaseClass(CDOTABaseAbility);
   AddClientProperty(m_bCombinable);
   AddClientProperty(m_bPermanent);
   AddClientProperty(m_bStackable);
   AddClientProperty(m_bRecipe);
   AddClientProperty(m_iSharability);
   AddClientProperty(m_bDroppable);
   AddClientProperty(m_bPurchasable);
   AddClientProperty(m_bSellable);
   AddClientProperty(m_bRequiresCharges);
   AddClientProperty(m_bKillable);
   AddClientProperty(m_bDisassemblable);
   AddClientProperty(m_bAlertable);
   AddClientProperty(m_iCurrentCharges);
   AddClientProperty(m_flPurchaseTime);
   AddClientProperty(m_iInitialCharges);
   AddClientProperty(m_hPurchaser);
   AddClientProperty(m_flAssembledTime);
   AddClientProperty(m_bPurchasedWhileDead);
EndClientClass();

BeginClientClass(CDOTA_Item_Ancient_Janggo, DT_DOTA_Item_Ancient_Janggo);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Armlet, DT_DOTA_Item_Armlet);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Battlefury, DT_DOTA_Item_Battlefury);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_BlinkDagger, DT_DOTA_Item_BlinkDagger);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Bloodstone, DT_DOTA_Item_Bloodstone);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_BootsOfTravel, DT_DOTA_Item_BootsOfTravel);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Cyclone, DT_DOTA_Item_Cyclone);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Cyclone_2, DT_DOTA_Item_Cyclone_2);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_DataDriven, DT_DOTA_Item_DataDriven);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Diffusal_Blade, DT_DOTA_Item_Diffusal_Blade);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Diffusal_Blade_Level2, DT_DOTA_Item_Diffusal_Blade_Level2);
   ClientBaseClass(CDOTA_Item_Diffusal_Blade);
EndClientClass();

BeginClientClass(CDOTA_Item_EmptyBottle, DT_DOTA_Item_EmptyBottle);
   ClientBaseClass(CDOTA_Item);
   AddClientProperty(m_iStoredRuneType);
EndClientClass();

BeginClientClass(CDOTA_Item_Ethereal_Blade, DT_DOTA_Item_Ethereal_Blade);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_ForceStaff, DT_DOTA_Item_ForceStaff);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Greevil_Blink, DT_DOTA_Item_Greevil_Blink);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Greevil_Whistle, DT_DOTA_Item_Greevil_Whistle);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Greevil_WhistleToggle, DT_DOTA_Item_Greevil_WhistleToggle);
   ClientBaseClass(CDOTA_Item);
   AddClientProperty(m_hGreevil);
EndClientClass();

BeginClientClass(CDOTA_Item_MantaStyle, DT_DOTA_Item_MantaStyle);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Medallion_Of_Courage, DT_DOTA_Item_Medallion_Of_Courage);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Mystery_Toss, DT_DOTA_Item_Mystery_Toss);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Mystery_Vacuum, DT_DOTA_Item_Mystery_Vacuum);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Necronomicon, DT_DOTA_Item_Necronomicon);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Necronomicon_Level2, DT_DOTA_Item_Necronomicon_Level2);
   ClientBaseClass(CDOTA_Item_Necronomicon);
EndClientClass();

BeginClientClass(CDOTA_Item_Necronomicon_Level3, DT_DOTA_Item_Necronomicon_Level3);
   ClientBaseClass(CDOTA_Item_Necronomicon);
EndClientClass();

BeginClientClass(CDOTA_Item_Nian_Flag_Trap, DT_DOTA_Item_Nian_Flag_Trap);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_ObserverWard, DT_DOTA_Item_ObserverWard);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Physical, DT_DOTA_Item_Physical);
   ClientBaseClass(CBaseAnimating);
   AddClientProperty(m_hItem);
EndClientClass();

BeginClientClass(CDOTA_Item_PlaceBuilding, DT_DOTA_Item_PlaceBuilding);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_PlaceBuilding_Free, DT_DOTA_Item_PlaceBuilding_Free);
   ClientBaseClass(CDOTA_Item_PlaceBuilding);
EndClientClass();

BeginClientClass(CDOTA_Item_PlaceBuilding_Grid, DT_DOTA_Item_PlaceBuilding_Grid);
   ClientBaseClass(CDOTA_Item_PlaceBuilding);
EndClientClass();

BeginClientClass(CDOTA_Item_PowerTreads, DT_DOTA_Item_PowerTreads);
   ClientBaseClass(CDOTA_Item);
   AddClientProperty(m_iStat);
EndClientClass();

BeginClientClass(CDOTA_Item_QuellingBlade, DT_DOTA_Item_QuellingBlade);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Radiance, DT_DOTA_Item_Radiance);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Recipe_Veil_Of_Discord, DT_DOTA_Item_Recipe_Veil_Of_Discord);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Ring_Of_Basilius, DT_DOTA_Item_Ring_Of_Basilius);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_RingOfAquila, DT_DOTA_Item_RingOfAquila);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Rune, DT_DOTA_Item_Rune);
   ClientBaseClass(CBaseAnimating);
   AddClientProperty(m_iRuneType);
EndClientClass();

BeginClientClass(CDOTA_Item_SentryWard, DT_DOTA_Item_SentryWard);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Tango, DT_DOTA_Item_Tango);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_TeleportScroll, DT_DOTA_Item_TeleportScroll);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_TranquilBoots, DT_DOTA_Item_TranquilBoots);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Urn_Of_Shadows, DT_DOTA_Item_Urn_Of_Shadows);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_Item_Veil_Of_Discord, DT_DOTA_Item_Veil_Of_Discord);
   ClientBaseClass(CDOTA_Item);
EndClientClass();

BeginClientClass(CDOTA_NeutralSpawner, DT_DOTA_NeutralSpawner);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_Type);
EndClientClass();

BeginClientClass(CDOTA_NPC_DataDriven, DT_DOTA_NPC_DataDriven);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
EndClientClass();

BeginClientClass(CDOTA_NPC_Observer_Ward, DT_DOTA_NPC_Observer_Ward);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
EndClientClass();

BeginClientClass(CDOTA_NPC_Observer_Ward_TrueSight, DT_DOTA_NPC_Observer_Ward_TrueSight);
   ClientBaseClass(CDOTA_NPC_Observer_Ward);
EndClientClass();

BeginClientClass(CDOTA_NPC_Techies_Minefield_Sign, DT_DOTA_NPC_Techies_Minefield_Sign);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
EndClientClass();

BeginClientClass(CDOTA_NPC_TechiesMines, DT_DOTA_NPC_TechiesMines);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
EndClientClass();

BeginClientClass(CDOTA_NPC_Treant_EyesInTheForest, DT_DOTA_NPC_Treant_EyesInTheForest);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
EndClientClass();

BeginClientClass(CDOTA_NPC_WitchDoctor_Ward, DT_DOTA_NPC_WitchDoctor_Ward);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
   AddClientProperty(m_nTargetType);
EndClientClass();

BeginClientClass(CDOTA_PhantomAssassin_Gravestone, DT_DOTA_PhantomAssassin_Gravestone);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
EndClientClass();

BeginClientStruct(DT_DireData);
   AddClientProperty(m_iReliableGoldDire);
   AddClientProperty(m_iUnreliableGoldDire);
   AddClientProperty(m_bWorldTreeStateDire);
EndClientStruct();

BeginClientStruct(DT_EndScoreAndSpectatorStats);
   AddClientProperty(m_iTotalEarnedGold);
   AddClientProperty(m_iTotalEarnedXP);
   AddClientProperty(m_bWorldTreeStateSpectator);
EndClientStruct();

BeginClientStruct(DT_RadiantData);
   AddClientProperty(m_iReliableGoldRadiant);
   AddClientProperty(m_iUnreliableGoldRadiant);
   AddClientProperty(m_bWorldTreeStateRadiant);
EndClientStruct();

BeginClientClass(CDOTA_PlayerResource, DT_DOTA_PlayerResource);
   AddClientProperty(m_iszPlayerNames);
   AddClientProperty(m_iszSelectedHero);
   AddClientProperty(m_nSelectedHeroID);
   AddClientProperty(m_iPlayerTeams);
   AddClientProperty(m_iKills);
   AddClientProperty(m_iAssists);
   AddClientProperty(m_iDeaths);
   AddClientProperty(m_iStreak);
   AddClientProperty(m_iRespawnSeconds);
   AddClientProperty(m_iLastBuybackTime);
   AddClientProperty(m_iLevel);
   AddClientProperty(m_iDenyCount);
   AddClientProperty(m_iLastHitCount);
   AddClientProperty(m_iLastHitStreak);
   AddClientProperty(m_iLastHitMultikill);
   AddClientProperty(m_iNearbyCreepDeathCount);
   AddClientProperty(m_hSelectedHero);
   AddClientProperty(m_bFullyJoinedServer);
   AddClientProperty(m_bFakeClient);
   AddClientProperty(m_iPlayerSteamIDs);
   AddClientProperty(m_bIsBroadcaster);
   AddClientProperty(m_iBroadcasterChannel);
   AddClientProperty(m_iBroadcasterChannelSlot);
   AddClientProperty(m_iszBroadcasterChannelDescription);
   AddClientProperty(m_iszBroadcasterChannelCountryCode);
   AddClientProperty(m_iszBroadcasterChannelLanguageCode);
   AddClientProperty(m_iConnectionState);
   AddClientProperty(m_bAFK);
   AddClientProperty(m_bVoiceChatBanned);
   AddClientProperty(m_iTimedRewardDrops);
   AddClientProperty(m_iTimedRewardCrates);
   AddClientProperty(m_nPossibleHeroSelection);
   AddClientProperty(m_nSuggestedHeroes);
   AddClientProperty(m_iMetaLevel);
   AddClientProperty(m_iMetaExperience);
   AddClientProperty(m_iMetaExperienceAwarded);
   AddClientProperty(m_bHasRepicked);
   AddClientProperty(m_bHasRandomed);
   AddClientProperty(m_UnitShareMasks);
   AddClientProperty(m_bBattleBonusActive);
   AddClientProperty(m_iBattleBonusRate);
   AddClientProperty(m_flBuybackCooldownTime);
   AddClientProperty(m_flBuybackGoldLimitTime);
   AddClientProperty(m_flBuybackCostTime);
   AddClientProperty(m_iCustomBuybackCost);
   AddClientProperty(m_flCustomBuybackCooldown);
   AddClientProperty(m_iGoldBagsCollected);
   AddClientProperty(m_fStuns);
   AddClientProperty(m_fHealing);
   AddClientProperty(m_iTowerKills);
   AddClientProperty(m_iRoshanKills);
   AddClientProperty(m_iEventPoints);
   AddClientProperty(m_iEventPremiumPoints);
   AddClientProperty(m_hCameraTarget);
   AddClientProperty(m_iEventRanks);
   AddClientProperty(m_unCompendiumLevel);
   AddClientProperty(m_bIsBroadcasterChannelCameraman);
   AddClientProperty(m_bHasPredictedVictory);
   AddClientProperty(m_bReservedHeroOnly);
   AddClientProperty(m_bQualifiesForPAContractReward);
   AddClientProperty(m_iTimedRewardEvents);
   AddClientProperty(EndScoreAndSpectatorStats);
   AddClientProperty(RadiantOnlyData);
   AddClientProperty(DireOnlyData);
EndClientClass();

BeginClientClass(CDOTA_RoshanSpawner, DT_DOTA_RoshanSpawner);
   ClientBaseClass(CBaseEntity);
EndClientClass();

BeginClientClass(CDOTA_TempTree, DT_DOTA_TempTree);
   ClientBaseClass(CBaseAnimating);
EndClientClass();

BeginClientClass(CDOTA_Tiny_ScepterTree, DT_DOTA_Tiny_ScepterTree);
   ClientBaseClass(CDOTAWearableItem);
EndClientClass();

BeginClientClass(CDOTA_Unit_Announcer, DT_DOTA_Unit_Announcer);
   ClientBaseClass(CDOTA_BaseNPC);
EndClientClass();

BeginClientClass(CDOTA_Unit_Announcer_Killing_Spree, DT_DOTA_Unit_Announcer_Killing_Spree);
   ClientBaseClass(CDOTA_BaseNPC);
EndClientClass();

BeginClientClass(CDOTA_Unit_Brewmaster_PrimalEarth, DT_DOTA_Unit_Brewmaster_PrimalEarth);
   ClientBaseClass(CDOTA_BaseNPC_Creep);
EndClientClass();

BeginClientClass(CDOTA_Unit_Brewmaster_PrimalFire, DT_DOTA_Unit_Brewmaster_PrimalFire);
   ClientBaseClass(CDOTA_BaseNPC_Creep);
EndClientClass();

BeginClientClass(CDOTA_Unit_Brewmaster_PrimalStorm, DT_DOTA_Unit_Brewmaster_PrimalStorm);
   ClientBaseClass(CDOTA_BaseNPC_Creep);
EndClientClass();

BeginClientClass(CDOTA_Unit_Broodmother_Spiderling, DT_DOTA_Unit_Broodmother_Spiderling);
   ClientBaseClass(CDOTA_BaseNPC_Creep_Talking);
EndClientClass();

BeginClientClass(CDOTA_Unit_Broodmother_Web, DT_DOTA_Unit_Broodmother_Web);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
EndClientClass();

BeginClientClass(CDOTA_Unit_Courier, DT_DOTA_Unit_Courier);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
   AddClientProperty(m_flRespawnTime);
   AddClientProperty(m_nCourierState);
   AddClientProperty(m_hCourierStateEntity);
   AddClientProperty(m_bFlyingCourier);
   AddClientProperty(m_iUnusualColor);
   AddClientProperty(m_iUnusualParticleSystem);
   AddClientProperty(m_hCourierWearable);
   AddClientProperty(m_bMorphEnabled);
EndClientClass();

BeginClientClass(CDOTA_Unit_Earth_Spirit_Stone, DT_DOTA_Unit_Earth_Spirit_Stone);
   ClientBaseClass(CDOTA_BaseNPC);
EndClientClass();

BeginClientClass(CDOTA_Unit_Elder_Titan_AncestralSpirit, DT_DOTA_Unit_Elder_Titan_AncestralSpirit);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
EndClientClass();

BeginClientClass(CDOTA_Unit_Fountain, DT_DOTA_Unit_Fountain);
   ClientBaseClass(CDOTA_BaseNPC_Building);
EndClientClass();

BeginClientClass(CDOTA_Unit_Greevil, DT_DOTA_Unit_Greevil);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
   AddClientProperty(m_flRespawnTime);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Abaddon, DT_DOTA_Unit_Hero_Abaddon);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_AbyssalUnderlord, DT_DOTA_Unit_Hero_AbyssalUnderlord);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Alchemist, DT_DOTA_Unit_Hero_Alchemist);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_AncientApparition, DT_DOTA_Unit_Hero_AncientApparition);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_AntiMage, DT_DOTA_Unit_Hero_AntiMage);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Axe, DT_DOTA_Unit_Hero_Axe);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Bane, DT_DOTA_Unit_Hero_Bane);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Batrider, DT_DOTA_Unit_Hero_Batrider);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Beastmaster, DT_DOTA_Unit_Hero_Beastmaster);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Beastmaster_Beasts, DT_DOTA_Unit_Hero_Beastmaster_Beasts);
   ClientBaseClass(CDOTA_BaseNPC_Creep);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Beastmaster_Boar, DT_DOTA_Unit_Hero_Beastmaster_Boar);
   ClientBaseClass(CDOTA_Unit_Hero_Beastmaster_Beasts);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Beastmaster_Hawk, DT_DOTA_Unit_Hero_Beastmaster_Hawk);
   ClientBaseClass(CDOTA_Unit_Hero_Beastmaster_Beasts);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Bloodseeker, DT_DOTA_Unit_Hero_Bloodseeker);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_BountyHunter, DT_DOTA_Unit_Hero_BountyHunter);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Brewmaster, DT_DOTA_Unit_Hero_Brewmaster);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Bristleback, DT_DOTA_Unit_Hero_Bristleback);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Broodmother, DT_DOTA_Unit_Hero_Broodmother);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Centaur, DT_DOTA_Unit_Hero_Centaur);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_ChaosKnight, DT_DOTA_Unit_Hero_ChaosKnight);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Chen, DT_DOTA_Unit_Hero_Chen);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Clinkz, DT_DOTA_Unit_Hero_Clinkz);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_CrystalMaiden, DT_DOTA_Unit_Hero_CrystalMaiden);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_DarkSeer, DT_DOTA_Unit_Hero_DarkSeer);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Dazzle, DT_DOTA_Unit_Hero_Dazzle);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_DeathProphet, DT_DOTA_Unit_Hero_DeathProphet);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Disruptor, DT_DOTA_Unit_Hero_Disruptor);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_DoomBringer, DT_DOTA_Unit_Hero_DoomBringer);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_DragonKnight, DT_DOTA_Unit_Hero_DragonKnight);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_DrowRanger, DT_DOTA_Unit_Hero_DrowRanger);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Earthshaker, DT_DOTA_Unit_Hero_Earthshaker);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_EarthSpirit, DT_DOTA_Unit_Hero_EarthSpirit);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Elder_Titan, DT_DOTA_Unit_Hero_Elder_Titan);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_EmberSpirit, DT_DOTA_Unit_Hero_EmberSpirit);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Enchantress, DT_DOTA_Unit_Hero_Enchantress);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Enigma, DT_DOTA_Unit_Hero_Enigma);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_FacelessVoid, DT_DOTA_Unit_Hero_FacelessVoid);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Furion, DT_DOTA_Unit_Hero_Furion);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Gyrocopter, DT_DOTA_Unit_Hero_Gyrocopter);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Huskar, DT_DOTA_Unit_Hero_Huskar);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Invoker, DT_DOTA_Unit_Hero_Invoker);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Jakiro, DT_DOTA_Unit_Hero_Jakiro);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Juggernaut, DT_DOTA_Unit_Hero_Juggernaut);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_KeeperOfTheLight, DT_DOTA_Unit_Hero_KeeperOfTheLight);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Kunkka, DT_DOTA_Unit_Hero_Kunkka);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Legion_Commander, DT_DOTA_Unit_Hero_Legion_Commander);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Leshrac, DT_DOTA_Unit_Hero_Leshrac);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Lich, DT_DOTA_Unit_Hero_Lich);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Life_Stealer, DT_DOTA_Unit_Hero_Life_Stealer);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Lina, DT_DOTA_Unit_Hero_Lina);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Lion, DT_DOTA_Unit_Hero_Lion);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_LoneDruid, DT_DOTA_Unit_Hero_LoneDruid);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Luna, DT_DOTA_Unit_Hero_Luna);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Lycan, DT_DOTA_Unit_Hero_Lycan);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Magnataur, DT_DOTA_Unit_Hero_Magnataur);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Medusa, DT_DOTA_Unit_Hero_Medusa);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Meepo, DT_DOTA_Unit_Hero_Meepo);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
   AddClientProperty(m_nWhichMeepo);
   AddClientProperty(m_bIsIllusion);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Mirana, DT_DOTA_Unit_Hero_Mirana);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Morphling, DT_DOTA_Unit_Hero_Morphling);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Naga_Siren, DT_DOTA_Unit_Hero_Naga_Siren);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Necrolyte, DT_DOTA_Unit_Hero_Necrolyte);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Nevermore, DT_DOTA_Unit_Hero_Nevermore);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_NightStalker, DT_DOTA_Unit_Hero_NightStalker);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Nyx_Assassin, DT_DOTA_Unit_Hero_Nyx_Assassin);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Obsidian_Destroyer, DT_DOTA_Unit_Hero_Obsidian_Destroyer);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Ogre_Magi, DT_DOTA_Unit_Hero_Ogre_Magi);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Omniknight, DT_DOTA_Unit_Hero_Omniknight);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Oracle, DT_DOTA_Unit_Hero_Oracle);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_PhantomAssassin, DT_DOTA_Unit_Hero_PhantomAssassin);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
   AddClientProperty(m_nArcanaLevel);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_PhantomLancer, DT_DOTA_Unit_Hero_PhantomLancer);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Phoenix, DT_DOTA_Unit_Hero_Phoenix);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Puck, DT_DOTA_Unit_Hero_Puck);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Pudge, DT_DOTA_Unit_Hero_Pudge);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Pugna, DT_DOTA_Unit_Hero_Pugna);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_QueenOfPain, DT_DOTA_Unit_Hero_QueenOfPain);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Rattletrap, DT_DOTA_Unit_Hero_Rattletrap);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Razor, DT_DOTA_Unit_Hero_Razor);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Riki, DT_DOTA_Unit_Hero_Riki);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Rubick, DT_DOTA_Unit_Hero_Rubick);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_SandKing, DT_DOTA_Unit_Hero_SandKing);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Shadow_Demon, DT_DOTA_Unit_Hero_Shadow_Demon);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_ShadowShaman, DT_DOTA_Unit_Hero_ShadowShaman);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Shredder, DT_DOTA_Unit_Hero_Shredder);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Silencer, DT_DOTA_Unit_Hero_Silencer);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_SkeletonKing, DT_DOTA_Unit_Hero_SkeletonKing);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Skywrath_Mage, DT_DOTA_Unit_Hero_Skywrath_Mage);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Slardar, DT_DOTA_Unit_Hero_Slardar);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Slark, DT_DOTA_Unit_Hero_Slark);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Sniper, DT_DOTA_Unit_Hero_Sniper);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Spectre, DT_DOTA_Unit_Hero_Spectre);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_SpiritBreaker, DT_DOTA_Unit_Hero_SpiritBreaker);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_StormSpirit, DT_DOTA_Unit_Hero_StormSpirit);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Sven, DT_DOTA_Unit_Hero_Sven);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Techies, DT_DOTA_Unit_Hero_Techies);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
   AddClientProperty(m_bHasArcana);
   AddClientProperty(m_nArcanaColor);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_TemplarAssassin, DT_DOTA_Unit_Hero_TemplarAssassin);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Terrorblade, DT_DOTA_Unit_Hero_Terrorblade);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
   AddClientProperty(m_nArcanaColor);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Tidehunter, DT_DOTA_Unit_Hero_Tidehunter);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Tinker, DT_DOTA_Unit_Hero_Tinker);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Tiny, DT_DOTA_Unit_Hero_Tiny);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Treant, DT_DOTA_Unit_Hero_Treant);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_TrollWarlord, DT_DOTA_Unit_Hero_TrollWarlord);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Tusk, DT_DOTA_Unit_Hero_Tusk);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Undying, DT_DOTA_Unit_Hero_Undying);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Ursa, DT_DOTA_Unit_Hero_Ursa);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_VengefulSpirit, DT_DOTA_Unit_Hero_VengefulSpirit);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Venomancer, DT_DOTA_Unit_Hero_Venomancer);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Viper, DT_DOTA_Unit_Hero_Viper);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Visage, DT_DOTA_Unit_Hero_Visage);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Warlock, DT_DOTA_Unit_Hero_Warlock);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Weaver, DT_DOTA_Unit_Hero_Weaver);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Windrunner, DT_DOTA_Unit_Hero_Windrunner);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Winter_Wyvern, DT_DOTA_Unit_Hero_Winter_Wyvern);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Wisp, DT_DOTA_Unit_Hero_Wisp);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_WitchDoctor, DT_DOTA_Unit_Hero_WitchDoctor);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_Hero_Zuus, DT_DOTA_Unit_Hero_Zuus);
   ClientBaseClass(CDOTA_BaseNPC_Hero);
EndClientClass();

BeginClientClass(CDOTA_Unit_LoopingSound, DT_DOTA_Unit_LoopingSound);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
   AddClientProperty(m_pszNetworkedSoundLoop);
   AddClientProperty(m_nLoopingSoundParity);
EndClientClass();

BeginClientClass(CDOTA_Unit_Nian, DT_DOTA_Unit_Nian);
   ClientBaseClass(CDOTA_BaseNPC_Creature);
EndClientClass();

BeginClientClass(CDOTA_Unit_Roquelaire, DT_DOTA_Unit_Roquelaire);
   ClientBaseClass(CDOTA_BaseNPC_Creep_Talking);
   AddClientProperty(m_flFlyHeight);
EndClientClass();

BeginClientClass(CDOTA_Unit_Roshan, DT_DOTA_Unit_Roshan);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
EndClientClass();

BeginClientClass(CDOTA_Unit_Roshan_Halloween, DT_DOTA_Unit_Roshan_Halloween);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
   AddClientProperty(m_hChosenTarget);
   AddClientProperty(m_iHealth);
   AddClientProperty(m_iMaxHealth);
EndClientClass();

BeginClientClass(CDOTA_Unit_SpiritBear, DT_DOTA_Unit_SpiritBear);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
EndClientClass();

BeginClientClass(CDOTA_Unit_TargetDummy, DT_DOTA_Unit_TargetDummy);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
   AddClientProperty(m_flDamageTaken);
   AddClientProperty(m_flStartDamageTime);
   AddClientProperty(m_flLastDamageTime);
   AddClientProperty(m_flLastHit);
EndClientClass();

BeginClientClass(CDOTA_Unit_Undying_Tombstone, DT_DOTA_Unit_Undying_Tombstone);
   ClientBaseClass(CDOTA_BaseNPC_Additive);
EndClientClass();

BeginClientClass(CDOTA_Unit_Undying_Zombie, DT_DOTA_Unit_Undying_Zombie);
   ClientBaseClass(CDOTA_BaseNPC_Creep);
EndClientClass();

BeginClientClass(CDOTA_Unit_VisageFamiliar, DT_DOTA_Unit_VisageFamiliar);
   ClientBaseClass(CDOTA_BaseNPC_Creep);
EndClientClass();

BeginClientClass(CDOTA_Wisp_Spirit, DT_DOTA_Wisp_Spirit);
   ClientBaseClass(CDOTA_BaseNPC);
   AddClientProperty(m_vecOrigin);
EndClientClass();

BeginClientClass(CDOTABaseAbility, DT_DOTABaseAbility);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_bHidden);
   AddClientProperty(m_bActivated);
   AddClientProperty(m_iDirtyButtons);
   AddClientProperty(m_iLevel);
   AddClientProperty(m_bToggleState);
   AddClientProperty(m_bInAbilityPhase);
   AddClientProperty(m_fCooldown);
   AddClientProperty(m_iCastRange);
   AddClientProperty(m_flCooldownLength);
   AddClientProperty(m_iManaCost);
   AddClientProperty(m_bAutoCastState);
   AddClientProperty(m_flChannelStartTime);
   AddClientProperty(m_flOverrideCastPoint);
   AddClientProperty(m_bInIndefiniteCooldown);
EndClientClass();

BeginClientClass(CDOTABaseGameMode, DT_DOTABaseGameMode);
   AddClientProperty(m_bAlwaysShowPlayerInventory);
   AddClientProperty(m_bGoldSoundDisabled);
   AddClientProperty(m_bRecommendedItemsDisabled);
   AddClientProperty(m_bFogOfWarDisabled);
   AddClientProperty(m_bUseCustomBuybackCost);
   AddClientProperty(m_bUseCustomBuybackCooldown);
   AddClientProperty(m_bBuybackEnabled);
   AddClientProperty(m_flCameraDistanceOverride);
   AddClientProperty(m_hOverrideSelectionEntity);
   AddClientProperty(m_bTopBarTeamValuesOverride);
   AddClientProperty(m_bTopBarTeamValuesVisible);
   AddClientProperty(m_nTeamGoodGuysTopBarValue);
   AddClientProperty(m_nTeamBadGuysTopBarValue);
   AddClientProperty(m_bUseCustomHeroLevels);
   AddClientProperty(m_nCustomHeroMaxLevel);
   AddClientProperty(m_nCustomXPRequiredToReachNextLevel);
EndClientClass();

BeginClientClass(CDOTACameraBounds, DT_DOTACameraBounds);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_vecBoundsMin);
   AddClientProperty(m_vecBoundsMax);
EndClientClass();

BeginClientClass(CDOTAFogOfWarTempViewers, DT_DOTAFogOfWarTempViewers);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_bTempViewers);
EndClientClass();

BeginClientClass(CDOTAFogOfWarWasVisible, DT_DOTAFogOfWarWasVisible);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_bWasVisible);
EndClientClass();

BeginClientStruct(DT_DOTA_GameManager);
   AddClientProperty(m_StableHeroAvailable);
   AddClientProperty(m_CurrentHeroAvailable);
   AddClientProperty(m_CulledHeroes);
EndClientStruct();

BeginClientClass(CDOTAGameManagerProxy, DT_DOTAGameManagerProxy);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(dota_gamemanager_data);
EndClientClass();

BeginClientStruct(DT_DOTAGamerules);
   AddClientProperty(m_iNetTimeOfDay);
   AddClientProperty(m_fGameTime);
   AddClientProperty(m_bGamePaused);
   AddClientProperty(m_ItemStockInfoGood);
   AddClientProperty(m_ItemStockInfoBad);
   AddClientProperty(m_AssassinMiniGameNetData);
   AddClientProperty(m_hGoodGuyFountain);
   AddClientProperty(m_hBadGuyFountain);
   AddClientProperty(m_hGoodGuyShop);
   AddClientProperty(m_hBadGuyShop);
   AddClientProperty(m_hSideShop1);
   AddClientProperty(m_hSideShop2);
   AddClientProperty(m_hSecretShop1);
   AddClientProperty(m_hSecretShop2);
   AddClientProperty(m_hGoodGuyFort);
   AddClientProperty(m_hBadGuyFort);
   AddClientProperty(m_hAnnouncerGood);
   AddClientProperty(m_hAnnouncerBad);
   AddClientProperty(m_hAnnouncerSpectator);
   AddClientProperty(m_hAnnouncerGood_KillingSpree);
   AddClientProperty(m_hAnnouncerBad_KillingSpree);
   AddClientProperty(m_hAnnouncerSpectator_KillingSpree);
   AddClientProperty(m_nGameState);
   AddClientProperty(m_flStateTransitionTime);
   AddClientProperty(m_iGameMode);
   AddClientProperty(m_nHeroPickState);
   AddClientProperty(m_iCMModePickBanOrder);
   AddClientProperty(m_iCDModePickBanOrder);
   AddClientProperty(m_flHeroPickStateTransitionTime);
   AddClientProperty(m_fExtraTimeRemaining);
   AddClientProperty(m_iPlayerIDsInControl);
   AddClientProperty(m_bSuggestedGoodHeroes);
   AddClientProperty(m_bSuggestedBadHeroes);
   AddClientProperty(m_iCaptainPlayerIDs);
   AddClientProperty(m_BannedHeroes);
   AddClientProperty(m_SelectedHeroes);
   AddClientProperty(m_AvailableHerosPerPlayer);
   AddClientProperty(m_UnlockedHeroesPerPlayer);
   AddClientProperty(m_LockedHeroesPerPlayer);
   AddClientProperty(m_iActiveTeam);
   AddClientProperty(m_iStartingTeam);
   AddClientProperty(m_iMiscHeroPickCounter);
   AddClientProperty(m_flPreGameStartTime);
   AddClientProperty(m_flGameStartTime);
   AddClientProperty(m_flGameEndTime);
   AddClientProperty(m_flGameLoadTime);
   AddClientProperty(m_fGoodGlyphCooldown);
   AddClientProperty(m_fBadGlyphCooldown);
   AddClientProperty(m_bIsNightstalkerNight);
   AddClientProperty(m_bIsTemporaryNight);
   AddClientProperty(m_nGameWinner);
   AddClientProperty(m_nLoadedPlayers);
   AddClientProperty(m_nExpectedPlayers);
   AddClientProperty(m_iMinimapDebugGridState);
   AddClientProperty(m_iFoWFrameNumber);
   AddClientProperty(m_bIsInItemTestingMode);
   AddClientProperty(m_bIsInCinematicMode);
   AddClientProperty(m_bItemWhiteList);
   AddClientProperty(m_hEndGameCinematicEntity);
   AddClientProperty(m_bIsStableMode);
   AddClientProperty(m_unMatchID64);
   AddClientProperty(m_BotDebugPushLane);
   AddClientProperty(m_BotDebugDefendLane);
   AddClientProperty(m_BotDebugFarmLane);
   AddClientProperty(m_BotDebugRoam);
   AddClientProperty(m_hBotDebugRoamTarget);
   AddClientProperty(m_BotDebugRoshan);
   AddClientProperty(m_lobbyLeagueID);
   AddClientProperty(m_lobbyGameName);
   AddClientProperty(m_bMatchSignoutComplete);
   AddClientProperty(m_bWhiteListEnabled);
   AddClientProperty(m_bHeroRespawnEnabled);
   AddClientProperty(m_nLastHitUIMode);
   AddClientProperty(m_bHUDTimerTutorialMode);
   AddClientProperty(m_unFanfareGoodGuys);
   AddClientProperty(m_unFanfareBadGuys);
   AddClientProperty(m_nSeriesType);
   AddClientProperty(m_nRadiantSeriesWins);
   AddClientProperty(m_nDireSeriesWins);
   AddClientProperty(m_nHalloweenTransitionState);
   AddClientProperty(m_flHalloweenRoshanLifetime);
   AddClientProperty(m_bTier3TowerDestroyed);
   AddClientProperty(m_iCustomGameScore);
   AddClientProperty(m_iPauseTeam);
   AddClientProperty(m_nGGTeam);
   AddClientProperty(m_flGGEndsAtTime);
   AddClientProperty(m_hGameModeEntity);
   AddClientProperty(m_nHalloweenRoshanLevel);
   AddClientProperty(m_flHalloweenRoshanRoundStartTime);
   AddClientProperty(m_nHalloweenRoshanRemainingHealth);
   AddClientProperty(m_nCustomGameDifficulty);
   AddClientProperty(m_hOverlayHealthBarUnit);
   AddClientProperty(m_nOverlayHealthBarType);
   AddClientProperty(m_bUseUniversalShopMode);
   AddClientProperty(m_bUseCustomHeroXPValue);
   AddClientProperty(m_bUseBaseGoldBountyOnHeroes);
   AddClientProperty(m_bSameHeroSelectionEnabled);
   AddClientProperty(m_nHeroMinimapIconSize);
   AddClientProperty(m_flCreepMinimapIconScale);
   AddClientProperty(m_flRuneMinimapIconScale);
   AddClientProperty(m_AbilityDraftAbilities);
   AddClientProperty(m_nAbilityDraftPlayerTracker);
   AddClientProperty(m_nAbilityDraftRoundNumber);
   AddClientProperty(m_nAbilityDraftAdvanceSteps);
   AddClientProperty(m_nAbilityDraftPhase);
   AddClientProperty(m_nAbilityDraftHeroesChosen);
   AddClientProperty(m_nARDMHeroesRemaining);
   AddClientProperty(m_nARDMHeroesPrecachedPercent);
   AddClientProperty(m_nAllDraftPhase);
   AddClientProperty(m_bAllDraftRadiantFirst);
   AddClientProperty(m_bHasHeroStatueLiked);
EndClientStruct();

BeginClientStruct(DT_DOTA_AbilityDraftAbilityState);
   AddClientProperty(m_unAbilityIndex);
   AddClientProperty(m_unPlayerID);
   AddClientProperty(m_unAbilityPlayerSlot);
EndClientStruct();

BeginClientStruct(DT_DOTA_AssassinMinigameNetworkState);
   AddClientProperty(nAssassinState);
   AddClientProperty(nVictimHeroID);
EndClientStruct();

BeginClientStruct(DT_DOTA_ItemStockInfo);
   AddClientProperty(usItemIndex);
   AddClientProperty(fStockDuration);
   AddClientProperty(fStockTime);
   AddClientProperty(iStockCount);
   AddClientProperty(iMaxCount);
EndClientStruct();

BeginClientClass(CDOTAGamerulesProxy, DT_DOTAGamerulesProxy);
   ClientBaseClass(CGameRulesProxy);
   AddClientProperty(dota_gamerules_data);
EndClientClass();

BeginClientClass(CDOTAHoldoutNetworker, DT_DOTA_HoldoutNetworker);
   AddClientProperty(m_flPrepTimeLeft);
   AddClientProperty(m_nWaveEnemyCount);
   AddClientProperty(m_nCurrentEnemyCount);
   AddClientProperty(m_nNumberOfRounds);
   AddClientProperty(m_nRoundNumber);
   AddClientProperty(m_bIsHeroRespawnEnabled);
   AddClientProperty(m_nGoldBagsExpired);
EndClientClass();

BeginClientClass(CDOTAMinimapBoundary, DT_DOTAMinimapBoundary);
   ClientBaseClass(CBaseEntity);
EndClientClass();

BeginClientStruct(DT_ClientQuickBuyItemState);
   AddClientProperty(nItemType);
   AddClientProperty(bPurchasable);
EndClientStruct();

BeginClientStruct(DT_DOTACommentatorTable);
   AddClientProperty(m_cellbits);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_cellX);
   AddClientProperty(m_cellY);
   AddClientProperty(m_cellZ);
   AddClientProperty(m_iSpectatorClickBehavior);
   AddClientProperty(m_iCursor);
   AddClientProperty(m_flAspectRatio);
   AddClientProperty(m_hSpectatorQueryUnit);
   AddClientProperty(m_iStatsPanel);
   AddClientProperty(m_iShopPanel);
   AddClientProperty(m_iShopViewMode);
   AddClientProperty(m_iStatsDropdownCategory);
   AddClientProperty(m_iStatsDropdownSort);
   AddClientProperty(m_szShopString);
   AddClientProperty(m_vecClientQuickBuyState);
   AddClientProperty(m_iQuickBuyParity);
   AddClientProperty(m_bInShowCaseMode);
   AddClientProperty(m_flCameraZoomAmount);
   AddClientProperty(m_iHighPriorityScore);
EndClientStruct();

BeginClientStruct(DT_DOTACompendiumData);
   AddClientProperty(m_iTotalEarnedGold);
   AddClientProperty(m_iTotalEarnedXP);
EndClientStruct();

BeginClientClass(CDOTAPlayer, DT_DOTAPlayer);
   ClientBaseClass(CBasePlayer);
   AddClientProperty(m_nTickBase);
   AddClientProperty(m_iPlayerID);
   AddClientProperty(m_nCachedCoachedTeam);
   AddClientProperty(m_vecStartingPosition);
   AddClientProperty(m_hAssignedHero);
   AddClientProperty(m_iMusicStatus);
   AddClientProperty(m_flMusicOperatorVals);
   AddClientProperty(m_iMusicOperatorVals);
   AddClientProperty(m_hKillCamUnit);
   AddClientProperty(dota_commentator_table);
   AddClientProperty(dota_compendium_data);
   AddClientProperty(m_bUsingCameraMan);
   AddClientProperty(m_bUsingAssistedCameraOperator);
EndClientClass();

BeginClientClass(CDOTAPropCustomTexture, DT_DOTAPropCustomTexture);
   ClientBaseClass(CDynamicProp);
EndClientClass();

BeginClientClass(CDotaQuest, DT_DotaQuest);
   AddClientProperty(m_pszQuestTitle);
   AddClientProperty(m_pszQuestText);
   AddClientProperty(m_nQuestType);
   AddClientProperty(m_hSubquests);
   AddClientProperty(m_bHidden);
   AddClientProperty(m_bCompleted);
   AddClientProperty(m_bWinIfCompleted);
   AddClientProperty(m_bLoseIfCompleted);
   AddClientProperty(m_pszGameEndText);
   AddClientProperty(m_pnTextReplaceValuesCDotaQuest);
   AddClientProperty(m_pszTextReplaceString);
   AddClientProperty(m_nTextReplaceValueVersion);
EndClientClass();

BeginClientClass(CDotaQuestBase, DT_DotaQuestBase);
EndClientClass();

BeginClientClass(CDOTASpecGraphPlayerData, DT_DotaSpecGraphPlayerData);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_rgGoldPerMinute);
   AddClientProperty(m_rgXPPerMinute);
   AddClientProperty(m_nCreatedByPlayerID);
EndClientClass();

BeginClientStruct(DT_DOTASpectatorGraphManager);
   AddClientProperty(m_rgPlayerGraphData);
   AddClientProperty(m_rgRadiantTotalEarnedGold);
   AddClientProperty(m_rgDireTotalEarnedGold);
   AddClientProperty(m_rgRadiantTotalEarnedXP);
   AddClientProperty(m_rgDireTotalEarnedXP);
   AddClientProperty(m_rgRadiantNetWorth);
   AddClientProperty(m_rgDireNetWorth);
   AddClientProperty(m_flTotalEarnedGoldStartTime);
   AddClientProperty(m_flTotalEarnedGoldEndTime);
   AddClientProperty(m_nGoldGraphVersion);
EndClientStruct();

BeginClientClass(CDOTASpectatorGraphManagerProxy, DT_DOTASpectatorGraphManagerProxy);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(dota_spectator_graph_manager_data);
EndClientClass();

BeginClientClass(CDotaSubquestBase, DT_DotaSubquestBase);
   AddClientProperty(m_pszSubquestText);
   AddClientProperty(m_bHidden);
   AddClientProperty(m_bCompleted);
   AddClientProperty(m_bShowProgressBar);
   AddClientProperty(m_nProgressBarHueShift);
   AddClientProperty(m_pnTextReplaceValuesCDotaSubquestBase);
   AddClientProperty(m_pszTextReplaceString);
   AddClientProperty(m_nTextReplaceValueVersion);
EndClientClass();

BeginClientClass(CDOTATeam, DT_DOTATeam);
   ClientBaseClass(CTeam);
   AddClientProperty(m_iHeroKills);
   AddClientProperty(m_iTowerKills);
   AddClientProperty(m_iBarracksKills);
   AddClientProperty(m_unTournamentTeamID);
   AddClientProperty(m_ulTeamLogo);
   AddClientProperty(m_ulTeamBaseLogo);
   AddClientProperty(m_ulTeamBannerLogo);
   AddClientProperty(m_szTag);
   AddClientProperty(m_bTeamComplete);
EndClientClass();

BeginClientStruct(DT_SpeechBubbleInfo);
   AddClientProperty(m_LocalizationStr);
   AddClientProperty(m_hNPC);
   AddClientProperty(m_flLifetime);
EndClientStruct();

BeginClientClass(CDotaTutorialNetworker, DT_DotaTutorialNetworker);
   AddClientProperty(m_nTutorialState);
   AddClientProperty(m_nTaskProgress);
   AddClientProperty(m_nTaskSteps);
   AddClientProperty(m_nTaskSecondsRemianing);
   AddClientProperty(m_nUIState);
   AddClientProperty(m_TargetLocation);
   AddClientProperty(m_SpeechBubbles);
   AddClientProperty(m_nLocationID);
EndClientClass();

BeginClientClass(CDOTAWearableItem, DT_DOTAWearableItem);
   ClientBaseClass(CEconWearable);
   AddClientProperty(m_bOwnerModelChanged);
EndClientClass();

BeginClientClass(CDynamicLight, DT_DynamicLight);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_Flags);
   AddClientProperty(m_LightStyle);
   AddClientProperty(m_Radius);
   AddClientProperty(m_Exponent);
   AddClientProperty(m_InnerAngle);
   AddClientProperty(m_OuterAngle);
   AddClientProperty(m_SpotRadius);
EndClientClass();

BeginClientClass(CDynamicProp, DT_DynamicProp);
   ClientBaseClass(CBreakableProp);
   AddClientProperty(m_bUseHitboxesForRenderBox);
EndClientClass();

BeginClientClass(CEconEntity, DT_EconEntity);
   ClientBaseClass(CBaseFlex);
   AddClientProperty(m_AttributeManager);
EndClientClass();

BeginClientClass(CEconWearable, DT_WearableItem);
   ClientBaseClass(CEconEntity);
EndClientClass();

BeginClientClass(CEntityDissolve, DT_EntityDissolve);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_flStartTime);
   AddClientProperty(m_flFadeInStart);
   AddClientProperty(m_flFadeInLength);
   AddClientProperty(m_flFadeOutModelStart);
   AddClientProperty(m_flFadeOutModelLength);
   AddClientProperty(m_flFadeOutStart);
   AddClientProperty(m_flFadeOutLength);
   AddClientProperty(m_nDissolveType);
   AddClientProperty(m_vDissolverOrigin);
   AddClientProperty(m_nMagnitude);
EndClientClass();

BeginClientClass(CEntityFlame, DT_EntityFlame);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_hEntAttached);
   AddClientProperty(m_bCheapEffect);
EndClientClass();

BeginClientClass(CEntityFreezing, DT_EntityFreezing);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_vFreezingOrigin);
   AddClientProperty(m_flFrozenPerHitbox);
   AddClientProperty(m_flFrozen);
   AddClientProperty(m_bFinishFreezing);
EndClientClass();

BeginClientStruct(DT_EntityParticleTrailInfo);
   AddClientProperty(m_flLifetime);
   AddClientProperty(m_flStartSize);
   AddClientProperty(m_flEndSize);
EndClientStruct();

BeginClientClass(CEntityParticleTrail, DT_EntityParticleTrail);
   ClientBaseClass(CBaseParticleEntity);
   AddClientProperty(m_iMaterialName);
   AddClientProperty(m_Info);
   AddClientProperty(m_hConstraintEntity);
EndClientClass();

BeginClientClass(CEnvAmbientLight, DT_EnvAmbientLight);
   ClientBaseClass(CSpatialEntity);
   AddClientProperty(m_vecColor);
EndClientClass();

BeginClientClass(CEnvDeferredLight, DT_EnvDeferredLight);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_LightColor);
   AddClientProperty(m_flIntensity);
   AddClientProperty(m_flLightSize);
   AddClientProperty(m_flSpotFoV);
   AddClientProperty(m_vLightDirection);
   AddClientProperty(m_flStartFalloff);
   AddClientProperty(m_flDistanceFalloff);
   AddClientProperty(m_nFlags);
   AddClientProperty(m_ProjectedTextureName);
EndClientClass();

BeginClientClass(CEnvDetailController, DT_DetailController);
   AddClientProperty(m_flFadeStartDist);
   AddClientProperty(m_flFadeEndDist);
EndClientClass();

BeginClientClass(CEnvDOFController, DT_EnvDOFController);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_bDOFEnabled);
   AddClientProperty(m_flNearBlurDepth);
   AddClientProperty(m_flNearFocusDepth);
   AddClientProperty(m_flFarFocusDepth);
   AddClientProperty(m_flFarBlurDepth);
   AddClientProperty(m_flNearBlurRadius);
   AddClientProperty(m_flFarBlurRadius);
EndClientClass();

BeginClientClass(CEnvParticleScript, DT_EnvParticleScript);
   ClientBaseClass(CBaseAnimating);
   AddClientProperty(m_flSequenceScale);
EndClientClass();

BeginClientClass(CEnvProjectedTexture, DT_EnvProjectedTexture);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_hTargetEntity);
   AddClientProperty(m_bState);
   AddClientProperty(m_bAlwaysUpdate);
   AddClientProperty(m_flLightFOV);
   AddClientProperty(m_bEnableShadows);
   AddClientProperty(m_bSimpleProjection);
   AddClientProperty(m_bLightOnlyTarget);
   AddClientProperty(m_bLightWorld);
   AddClientProperty(m_bCameraSpace);
   AddClientProperty(m_flBrightnessScale);
   AddClientProperty(m_LightColor);
   AddClientProperty(m_flFarZ);
   AddClientProperty(m_flColorTransitionTime);
   AddClientProperty(m_flAmbient);
   AddClientProperty(m_SpotlightTextureName);
   AddClientProperty(m_nSpotlightTextureFrame);
   AddClientProperty(m_flNearZ);
   AddClientProperty(m_nShadowQuality);
   AddClientProperty(m_flProjectionSize);
   AddClientProperty(m_flRotation);
EndClientClass();

BeginClientClass(CEnvQuadraticBeam, DT_QuadraticBeam);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_targetPosition);
   AddClientProperty(m_controlPosition);
   AddClientProperty(m_scrollRate);
   AddClientProperty(m_flWidth);
EndClientClass();

BeginClientClass(CEnvScreenEffect, DT_EnvScreenEffect);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_flDuration);
   AddClientProperty(m_nType);
EndClientClass();

BeginClientClass(CEnvScreenOverlay, DT_EnvScreenOverlay);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_iszOverlayNames);
   AddClientProperty(m_flOverlayTimes);
   AddClientProperty(m_flStartTime);
   AddClientProperty(m_iDesiredOverlay);
   AddClientProperty(m_bIsActive);
EndClientClass();

BeginClientClass(CEnvTonemapController, DT_EnvTonemapController);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_bUseCustomAutoExposureMin);
   AddClientProperty(m_bUseCustomAutoExposureMax);
   AddClientProperty(m_bUseCustomBloomScale);
   AddClientProperty(m_flCustomAutoExposureMin);
   AddClientProperty(m_flCustomAutoExposureMax);
   AddClientProperty(m_flCustomBloomScale);
   AddClientProperty(m_flCustomBloomScaleMinimum);
   AddClientProperty(m_flBloomExponent);
   AddClientProperty(m_flBloomSaturation);
EndClientClass();

BeginClientStruct(DT_EnvWindShared);
   AddClientProperty(m_iMinWind);
   AddClientProperty(m_iMaxWind);
   AddClientProperty(m_iMinGust);
   AddClientProperty(m_iMaxGust);
   AddClientProperty(m_windRadius);
   AddClientProperty(m_flMinGustDelay);
   AddClientProperty(m_flMaxGustDelay);
   AddClientProperty(m_iGustDirChange);
   AddClientProperty(m_iWindSeed);
   AddClientProperty(m_iInitialWindDir);
   AddClientProperty(m_flInitialWindSpeed);
   AddClientProperty(m_flStartTime);
   AddClientProperty(m_flGustDuration);
EndClientStruct();

BeginClientClass(CEnvWind, DT_EnvWind);
   AddClientProperty(m_EnvWindShared);
EndClientClass();

BeginClientClass(CFireSmoke, DT_FireSmoke);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_flStartScale);
   AddClientProperty(m_flScale);
   AddClientProperty(m_flScaleTime);
   AddClientProperty(m_nFlags);
   AddClientProperty(m_nFlameModelIndex);
   AddClientProperty(m_nFlameFromAboveModelIndex);
EndClientClass();

BeginClientClass(CFireTrail, DT_FireTrail);
   ClientBaseClass(CBaseParticleEntity);
   AddClientProperty(m_nAttachment);
   AddClientProperty(m_flLifetime);
EndClientClass();

BeginClientClass(CFish, DT_CFish);
   AddClientProperty(m_poolOrigin);
   AddClientProperty(m_angle);
   AddClientProperty(m_x);
   AddClientProperty(m_y);
   AddClientProperty(m_z);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_lifeState);
   AddClientProperty(m_waterLevel);
EndClientClass();

BeginClientClass(CFogController, DT_FogController);
   AddClientProperty(m_fog.enable);
   AddClientProperty(m_fog.blend);
   AddClientProperty(m_fog.dirPrimary);
   AddClientProperty(m_fog.colorPrimary);
   AddClientProperty(m_fog.colorSecondary);
   AddClientProperty(m_fog.start);
   AddClientProperty(m_fog.end);
   AddClientProperty(m_fog.maxdensity);
   AddClientProperty(m_fog.farz);
   AddClientProperty(m_fog.colorPrimaryLerpTo);
   AddClientProperty(m_fog.colorSecondaryLerpTo);
   AddClientProperty(m_fog.startLerpTo);
   AddClientProperty(m_fog.endLerpTo);
   AddClientProperty(m_fog.maxdensityLerpTo);
   AddClientProperty(m_fog.lerptime);
   AddClientProperty(m_fog.duration);
   AddClientProperty(m_fog.HDRColorScale);
   AddClientProperty(m_fog.m_bNoReflectionFog);
EndClientClass();

BeginClientClass(CFunc_Dust, DT_Func_Dust);
   AddClientProperty(m_Color);
   AddClientProperty(m_SpawnRate);
   AddClientProperty(m_SpeedMax);
   AddClientProperty(m_flSizeMin);
   AddClientProperty(m_flSizeMax);
   AddClientProperty(m_DistMax);
   AddClientProperty(m_LifetimeMin);
   AddClientProperty(m_LifetimeMax);
   AddClientProperty(m_DustFlags);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_FallSpeed);
   AddClientProperty(m_Collision);
EndClientClass();

BeginClientClass(CFunc_LOD, DT_Func_LOD);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_nDisappearMinDist);
   AddClientProperty(m_nDisappearMaxDist);
EndClientClass();

BeginClientClass(CFuncAreaPortalWindow, DT_FuncAreaPortalWindow);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_flFadeDist);
   AddClientProperty(m_flFadeStartDist);
   AddClientProperty(m_flTranslucencyLimit);
   AddClientProperty(m_iBackgroundModelIndex);
EndClientClass();

BeginClientClass(CFuncBrush, DT_FuncBrush);
   ClientBaseClass(CBaseEntity);
EndClientClass();

BeginClientClass(CFuncConveyor, DT_FuncConveyor);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_flConveyorSpeed);
EndClientClass();

BeginClientClass(CFuncLadder, DT_FuncLadder);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_vecPlayerMountPositionTop);
   AddClientProperty(m_vecPlayerMountPositionBottom);
   AddClientProperty(m_vecLadderDir);
   AddClientProperty(m_bFakeLadder);
EndClientClass();

BeginClientClass(CFuncMoveLinear, DT_FuncMoveLinear);
   ClientBaseClass(CBaseToggle);
   AddClientProperty(m_vecVelocity);
   AddClientProperty(m_fFlags);
EndClientClass();

BeginClientClass(CFuncOccluder, DT_FuncOccluder);
   AddClientProperty(m_bActive);
   AddClientProperty(m_nOccluderIndex);
EndClientClass();

BeginClientClass(CFuncReflectiveGlass, DT_FuncReflectiveGlass);
   ClientBaseClass(CFuncBrush);
EndClientClass();

BeginClientClass(CFuncRotating, DT_FuncRotating);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_angRotation);
   AddClientProperty(m_flSimulationTime);
EndClientClass();

BeginClientClass(CFuncSmokeVolume, DT_FuncSmokeVolume);
   ClientBaseClass(CBaseParticleEntity);
   AddClientProperty(m_Color1);
   AddClientProperty(m_Color2);
   AddClientProperty(m_MaterialName);
   AddClientProperty(m_ParticleDrawWidth);
   AddClientProperty(m_ParticleSpacingDistance);
   AddClientProperty(m_DensityRampSpeed);
   AddClientProperty(m_RotationSpeed);
   AddClientProperty(m_MovementSpeed);
   AddClientProperty(m_Density);
   AddClientProperty(m_maxDrawDistance);
   AddClientProperty(m_spawnflags);
EndClientClass();

BeginClientClass(CFuncTrackTrain, DT_FuncTrackTrain);
   ClientBaseClass(CBaseEntity);
EndClientClass();

BeginClientClass(CGameRulesProxy, DT_GameRulesProxy);
EndClientClass();

BeginClientClass(CHandleTest, DT_HandleTest);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_Handle);
   AddClientProperty(m_bSendHandle);
EndClientClass();

BeginClientClass(CInfoLadderDismount, DT_InfoLadderDismount);
   ClientBaseClass(CBaseEntity);
EndClientClass();

BeginClientClass(CInfoOverlayAccessor, DT_InfoOverlayAccessor);
   AddClientProperty(m_iTextureFrameIndex);
   AddClientProperty(m_iOverlayID);
EndClientClass();

BeginClientClass(CLightGlow, DT_LightGlow);
   AddClientProperty(m_clrRender);
   AddClientProperty(m_nHorizontalSize);
   AddClientProperty(m_nVerticalSize);
   AddClientProperty(m_nMinDist);
   AddClientProperty(m_nMaxDist);
   AddClientProperty(m_nOuterMaxDist);
   AddClientProperty(m_spawnflags);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_angRotation);
   AddClientProperty(moveparent);
   AddClientProperty(m_flGlowProxySize);
   AddClientProperty(HDRColorScale);
EndClientClass();

BeginClientClass(CMaterialModifyControl, DT_MaterialModifyControl);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_szMaterialName);
   AddClientProperty(m_szMaterialVar);
   AddClientProperty(m_szMaterialVarValue);
   AddClientProperty(m_iFrameStart);
   AddClientProperty(m_iFrameEnd);
   AddClientProperty(m_bWrap);
   AddClientProperty(m_flFramerate);
   AddClientProperty(m_bNewAnimCommandsSemaphore);
   AddClientProperty(m_flFloatLerpStartValue);
   AddClientProperty(m_flFloatLerpEndValue);
   AddClientProperty(m_flFloatLerpTransitionTime);
   AddClientProperty(m_nModifyMode);
EndClientClass();

BeginClientClass(CMovieDisplay, DT_MovieDisplay);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_bEnabled);
   AddClientProperty(m_bLooping);
   AddClientProperty(m_szMovieFilename);
   AddClientProperty(m_szGroupName);
EndClientClass();

BeginClientClass(CParticleFire, DT_ParticleFire);
   AddClientProperty(m_vOrigin);
   AddClientProperty(m_vDirection);
EndClientClass();

BeginClientClass(CParticlePerformanceMonitor, DT_ParticlePerformanceMonitor);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_bDisplayPerf);
   AddClientProperty(m_bMeasurePerf);
EndClientClass();

BeginClientClass(CParticleSystem, DT_ParticleSystem);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_flStartTime);
   AddClientProperty(m_iEffectIndex);
   AddClientProperty(m_bActive);
   AddClientProperty(m_hOwnerEntity);
   AddClientProperty(moveparent);
   AddClientProperty(m_iParentAttachment);
   AddClientProperty(m_angRotation);
   AddClientProperty(m_nStopType);
   AddClientProperty(m_szSnapshotFileName);
   AddClientProperty(m_vServerControlPoints);
   AddClientProperty(m_iServerControlPointAssignments);
   AddClientProperty(m_hControlPointEnts);
   AddClientProperty(m_iControlPointParents);
EndClientClass();

BeginClientClass(CPhysBox, DT_PhysBox);
   ClientBaseClass(CBaseEntity);
EndClientClass();

BeginClientClass(CPhysBoxMultiplayer, DT_PhysBoxMultiplayer);
   ClientBaseClass(CPhysBox);
   AddClientProperty(m_iPhysicsMode);
   AddClientProperty(m_fMass);
EndClientClass();

BeginClientClass(CPhysicsProp, DT_PhysicsProp);
   ClientBaseClass(CBreakableProp);
   AddClientProperty(m_bAwake);
EndClientClass();

BeginClientClass(CPhysicsPropMultiplayer, DT_PhysicsPropMultiplayer);
   ClientBaseClass(CPhysicsProp);
   AddClientProperty(m_iPhysicsMode);
   AddClientProperty(m_fMass);
   AddClientProperty(m_collisionMins);
   AddClientProperty(m_collisionMaxs);
EndClientClass();

BeginClientClass(CPhysMagnet, DT_PhysMagnet);
   ClientBaseClass(CBaseAnimating);
EndClientClass();

BeginClientClass(CPlasma, DT_Plasma);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_flScale);
   AddClientProperty(m_flScaleTime);
   AddClientProperty(m_nFlags);
   AddClientProperty(m_nPlasmaModelIndex);
   AddClientProperty(m_nPlasmaModelIndex2);
   AddClientProperty(m_nGlowModelIndex);
EndClientClass();

BeginClientClass(CPointCamera, DT_PointCamera);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_FOV);
   AddClientProperty(m_Resolution);
   AddClientProperty(m_bFogEnable);
   AddClientProperty(m_FogColor);
   AddClientProperty(m_flFogStart);
   AddClientProperty(m_flFogEnd);
   AddClientProperty(m_flFogMaxDensity);
   AddClientProperty(m_bActive);
   AddClientProperty(m_bUseScreenAspectRatio);
   AddClientProperty(m_bNoSky);
   AddClientProperty(m_fBrightness);
EndClientClass();

BeginClientClass(CPointCommentaryNode, DT_PointCommentaryNode);
   ClientBaseClass(CBaseAnimating);
   AddClientProperty(m_bActive);
   AddClientProperty(m_iszCommentaryFile);
   AddClientProperty(m_iszCommentaryFileNoHDR);
   AddClientProperty(m_flStartTime);
   AddClientProperty(m_iszSpeakers);
   AddClientProperty(m_iNodeNumber);
   AddClientProperty(m_iNodeNumberMax);
   AddClientProperty(m_hViewPosition);
EndClientClass();

BeginClientClass(CPoseController, DT_PoseController);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_hProps);
   AddClientProperty(m_chPoseIndex);
   AddClientProperty(m_bPoseValueParity);
   AddClientProperty(m_fPoseValue);
   AddClientProperty(m_fInterpolationTime);
   AddClientProperty(m_bInterpolationWrap);
   AddClientProperty(m_fCycleFrequency);
   AddClientProperty(m_nFModType);
   AddClientProperty(m_fFModTimeOffset);
   AddClientProperty(m_fFModRate);
   AddClientProperty(m_fFModAmplitude);
EndClientClass();

BeginClientClass(CPostProcessController, DT_PostProcessController);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_flPostProcessParameters);
   AddClientProperty(m_bMaster);
EndClientClass();

BeginClientClass(CPrecipitation, DT_Precipitation);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_nPrecipType);
EndClientClass();

BeginClientClass(CPrecipitationBlocker, DT_PrecipitationBlocker);
   ClientBaseClass(CBaseEntity);
EndClientClass();

BeginClientClass(CProp_Hallucination, DT_Prop_Hallucination);
   ClientBaseClass(CBaseAnimating);
   AddClientProperty(m_bEnabled);
   AddClientProperty(m_fVisibleTime);
   AddClientProperty(m_fRechargeTime);
EndClientClass();

BeginClientClass(CPropDoorRotating, DT_PropDoorRotating);
   ClientBaseClass(CBasePropDoor);
EndClientClass();

BeginClientClass(CPropVehicleDriveable, DT_PropVehicleDriveable);
   ClientBaseClass(CBaseAnimating);
   AddClientProperty(m_hPlayer);
   AddClientProperty(m_nSpeed);
   AddClientProperty(m_nRPM);
   AddClientProperty(m_flThrottle);
   AddClientProperty(m_nBoostTimeLeft);
   AddClientProperty(m_nHasBoost);
   AddClientProperty(m_nScannerDisabledWeapons);
   AddClientProperty(m_nScannerDisabledVehicle);
   AddClientProperty(m_bEnterAnimOn);
   AddClientProperty(m_bExitAnimOn);
   AddClientProperty(m_bUnableToFire);
   AddClientProperty(m_vecEyeExitEndpoint);
   AddClientProperty(m_bHasGun);
   AddClientProperty(m_vecGunCrosshair);
EndClientClass();

BeginClientClass(CRagdollManager, DT_RagdollManager);
   AddClientProperty(m_iCurrentMaxRagdollCount);
EndClientClass();

BeginClientClass(CRagdollProp, DT_Ragdoll);
   ClientBaseClass(CBaseAnimating);
   AddClientProperty(m_ragAngles);
   AddClientProperty(m_ragPos);
   AddClientProperty(m_hUnragdoll);
   AddClientProperty(m_flBlendWeight);
   AddClientProperty(m_nOverlaySequence);
EndClientClass();

BeginClientClass(CRagdollPropAttached, DT_Ragdoll_Attached);
   ClientBaseClass(CRagdollProp);
   AddClientProperty(m_boneIndexAttached);
   AddClientProperty(m_ragdollAttachedObjectIndex);
   AddClientProperty(m_attachmentPointBoneSpace);
   AddClientProperty(m_attachmentPointRagdollSpace);
EndClientClass();

BeginClientClass(CRopeKeyframe, DT_RopeKeyframe);
   AddClientProperty(m_hStartPoint);
   AddClientProperty(m_hEndPoint);
   AddClientProperty(m_iStartAttachment);
   AddClientProperty(m_iEndAttachment);
   AddClientProperty(m_Slack);
   AddClientProperty(m_RopeLength);
   AddClientProperty(m_fLockedPoints);
   AddClientProperty(m_nChangeCount);
   AddClientProperty(m_RopeFlags);
   AddClientProperty(m_nSegments);
   AddClientProperty(m_bConstrainBetweenEndpoints);
   AddClientProperty(m_iRopeMaterialModelIndex);
   AddClientProperty(m_Subdiv);
   AddClientProperty(m_TextureScale);
   AddClientProperty(m_Width);
   AddClientProperty(m_flScrollSpeed);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(moveparent);
   AddClientProperty(m_iParentAttachment);
   AddClientProperty(m_nMinCPULevel);
   AddClientProperty(m_nMaxCPULevel);
   AddClientProperty(m_nMinGPULevel);
   AddClientProperty(m_nMaxGPULevel);
EndClientClass();

BeginClientClass(CSceneEntity, DT_SceneEntity);
   AddClientProperty(m_nSceneStringIndex);
   AddClientProperty(m_bIsPlayingBack);
   AddClientProperty(m_bPaused);
   AddClientProperty(m_bMultiplayer);
   AddClientProperty(m_flForceClientTime);
   AddClientProperty(m_hActorList);
EndClientClass();

BeginClientClass(CShadowControl, DT_ShadowControl);
   AddClientProperty(m_shadowDirection);
   AddClientProperty(m_shadowColor);
   AddClientProperty(m_flShadowMaxDist);
   AddClientProperty(m_bDisableShadows);
   AddClientProperty(m_bEnableLocalLightShadows);
EndClientClass();

BeginClientClass(CSlideshowDisplay, DT_SlideshowDisplay);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_bEnabled);
   AddClientProperty(m_szDisplayText);
   AddClientProperty(m_szSlideshowDirectory);
   AddClientProperty(m_chCurrentSlideLists);
   AddClientProperty(m_fMinSlideTime);
   AddClientProperty(m_fMaxSlideTime);
   AddClientProperty(m_iCycleType);
   AddClientProperty(m_bNoListRepeats);
EndClientClass();

BeginClientClass(CSmokeStack, DT_SmokeStack);
   ClientBaseClass(CBaseParticleEntity);
   AddClientProperty(m_SpreadSpeed);
   AddClientProperty(m_Speed);
   AddClientProperty(m_StartSize);
   AddClientProperty(m_EndSize);
   AddClientProperty(m_Rate);
   AddClientProperty(m_JetLength);
   AddClientProperty(m_bEmit);
   AddClientProperty(m_flBaseSpread);
   AddClientProperty(m_flRollSpeed);
   AddClientProperty(m_DirLight.m_vPos);
   AddClientProperty(m_DirLight.m_vColor);
   AddClientProperty(m_DirLight.m_flIntensity);
   AddClientProperty(m_AmbientLight.m_vPos);
   AddClientProperty(m_AmbientLight.m_vColor);
   AddClientProperty(m_AmbientLight.m_flIntensity);
   AddClientProperty(m_vWind);
   AddClientProperty(m_flTwist);
   AddClientProperty(m_iMaterialModel);
EndClientClass();

BeginClientClass(CSpatialEntity, DT_SpatialEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_MinFalloff);
   AddClientProperty(m_MaxFalloff);
   AddClientProperty(m_flCurWeight);
   AddClientProperty(m_bEnabled);
EndClientClass();

BeginClientClass(CSpotlightEnd, DT_SpotlightEnd);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_flLightScale);
   AddClientProperty(m_Radius);
EndClientClass();

BeginClientClass(CSprite, DT_Sprite);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_hAttachedToEntity);
   AddClientProperty(m_nAttachment);
   AddClientProperty(m_flScaleTime);
   AddClientProperty(m_flSpriteScale);
   AddClientProperty(m_flGlowProxySize);
   AddClientProperty(m_flHDRColorScale);
   AddClientProperty(m_flSpriteFramerate);
   AddClientProperty(m_flFrame);
   AddClientProperty(m_flBrightnessTime);
   AddClientProperty(m_nBrightness);
   AddClientProperty(m_bWorldSpaceScale);
EndClientClass();

BeginClientClass(CSpriteOriented, DT_SpriteOriented);
   ClientBaseClass(CSprite);
EndClientClass();

BeginClientClass(CSpriteTrail, DT_SpriteTrail);
   ClientBaseClass(CSprite);
   AddClientProperty(m_flLifeTime);
   AddClientProperty(m_flStartWidth);
   AddClientProperty(m_flEndWidth);
   AddClientProperty(m_flStartWidthVariance);
   AddClientProperty(m_flTextureRes);
   AddClientProperty(m_flMinFadeLength);
   AddClientProperty(m_vecSkyboxOrigin);
   AddClientProperty(m_flSkyboxScale);
EndClientClass();

BeginClientClass(CStatueProp, DT_StatueProp);
   ClientBaseClass(CPhysicsProp);
   AddClientProperty(m_hInitBaseAnimating);
   AddClientProperty(m_bShatter);
   AddClientProperty(m_nShatterFlags);
   AddClientProperty(m_vShatterPosition);
   AddClientProperty(m_vShatterForce);
EndClientClass();

BeginClientClass(CSteamJet, DT_SteamJet);
   ClientBaseClass(CBaseParticleEntity);
   AddClientProperty(m_SpreadSpeed);
   AddClientProperty(m_Speed);
   AddClientProperty(m_StartSize);
   AddClientProperty(m_EndSize);
   AddClientProperty(m_Rate);
   AddClientProperty(m_JetLength);
   AddClientProperty(m_bEmit);
   AddClientProperty(m_bFaceLeft);
   AddClientProperty(m_nType);
   AddClientProperty(m_spawnflags);
   AddClientProperty(m_flRollSpeed);
EndClientClass();

BeginClientClass(CSun, DT_Sun);
   AddClientProperty(m_clrRender);
   AddClientProperty(m_clrOverlay);
   AddClientProperty(m_vDirection);
   AddClientProperty(m_bOn);
   AddClientProperty(m_nSize);
   AddClientProperty(m_nOverlaySize);
   AddClientProperty(m_nMaterial);
   AddClientProperty(m_nOverlayMaterial);
   AddClientProperty(HDRColorScale);
EndClientClass();

BeginClientClass(CSunlightShadowControl, DT_SunlightShadowControl);
   AddClientProperty(m_shadowDirection);
   AddClientProperty(m_bEnabled);
   AddClientProperty(m_TextureName);
   AddClientProperty(m_LightColor);
   AddClientProperty(m_flColorTransitionTime);
   AddClientProperty(m_flSunDistance);
   AddClientProperty(m_flFOV);
   AddClientProperty(m_flNearZ);
   AddClientProperty(m_flNorthOffset);
   AddClientProperty(m_bEnableShadows);
EndClientClass();

BeginClientClass(CTeam, DT_Team);
   AddClientProperty(m_iTeamNum);
   AddClientProperty(m_iScore);
   AddClientProperty(m_iRoundsWon);
   AddClientProperty(m_szTeamname);
   AddClientProperty(player_array);
EndClientClass();

BeginClientStruct(DT_ShowcaseData);
   AddClientProperty(m_hRootEntity);
   AddClientProperty(m_Slots);
EndClientStruct();

BeginClientStruct(DT_ShowcaseSlot);
   AddClientProperty(nType);
   AddClientProperty(szName);
   AddClientProperty(vecLocalOrigin);
   AddClientProperty(angLocalAngles);
   AddClientProperty(hEntity);
   AddClientProperty(ulItemID);
   AddClientProperty(bIsOnlySlotOfThisType);
EndClientStruct();

BeginClientClass(CTeamShowcaseEditorManager, DT_TeamShowcaseEditorManager);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_nEditorMode);
   AddClientProperty(m_nCurEditingSlot);
   AddClientProperty(m_Data);
EndClientClass();

BeginClientClass(CTeamShowcasePlayer, DT_TeamShowcasePlayer);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_hPlayerEntity);
   AddClientProperty(m_szCameraAnim);
   AddClientProperty(m_flTransitionTime);
EndClientClass();

BeginClientClass(CTEArmorRicochet, DT_TEArmorRicochet);
   ClientBaseClass(CTEMetalSparks);
EndClientClass();

BeginClientClass(CTEBaseBeam, DT_BaseBeam);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_nHaloIndex);
   AddClientProperty(m_nStartFrame);
   AddClientProperty(m_nFrameRate);
   AddClientProperty(m_fLife);
   AddClientProperty(m_fWidth);
   AddClientProperty(m_fEndWidth);
   AddClientProperty(m_nFadeLength);
   AddClientProperty(m_fAmplitude);
   AddClientProperty(m_nSpeed);
   AddClientProperty(r);
   AddClientProperty(g);
   AddClientProperty(b);
   AddClientProperty(a);
   AddClientProperty(m_nFlags);
EndClientClass();

BeginClientClass(CTEBeamEntPoint, DT_TEBeamEntPoint);
   ClientBaseClass(CTEBaseBeam);
   AddClientProperty(m_nStartEntity);
   AddClientProperty(m_nEndEntity);
   AddClientProperty(m_vecStartPoint);
   AddClientProperty(m_vecEndPoint);
EndClientClass();

BeginClientClass(CTEBeamEnts, DT_TEBeamEnts);
   ClientBaseClass(CTEBaseBeam);
   AddClientProperty(m_nStartEntity);
   AddClientProperty(m_nEndEntity);
EndClientClass();

BeginClientClass(CTEBeamFollow, DT_TEBeamFollow);
   ClientBaseClass(CTEBaseBeam);
   AddClientProperty(m_iEntIndex);
EndClientClass();

BeginClientClass(CTEBeamLaser, DT_TEBeamLaser);
   ClientBaseClass(CTEBaseBeam);
   AddClientProperty(m_nStartEntity);
   AddClientProperty(m_nEndEntity);
EndClientClass();

BeginClientClass(CTEBeamPoints, DT_TEBeamPoints);
   ClientBaseClass(CTEBaseBeam);
   AddClientProperty(m_vecStartPoint);
   AddClientProperty(m_vecEndPoint);
EndClientClass();

BeginClientClass(CTEBeamRing, DT_TEBeamRing);
   ClientBaseClass(CTEBaseBeam);
   AddClientProperty(m_nStartEntity);
   AddClientProperty(m_nEndEntity);
EndClientClass();

BeginClientClass(CTEBeamRingPoint, DT_TEBeamRingPoint);
   ClientBaseClass(CTEBaseBeam);
   AddClientProperty(m_vecCenter);
   AddClientProperty(m_flStartRadius);
   AddClientProperty(m_flEndRadius);
EndClientClass();

BeginClientClass(CTEBeamSpline, DT_TEBeamSpline);
   AddClientProperty(m_nPoints);
   AddClientProperty(m_vecPoints);
EndClientClass();

BeginClientClass(CTEBloodSprite, DT_TEBloodSprite);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_vecDirection);
   AddClientProperty(r);
   AddClientProperty(g);
   AddClientProperty(b);
   AddClientProperty(a);
   AddClientProperty(m_nSprayModel);
   AddClientProperty(m_nDropModel);
   AddClientProperty(m_nSize);
EndClientClass();

BeginClientClass(CTEBloodStream, DT_TEBloodStream);
   ClientBaseClass(CTEParticleSystem);
   AddClientProperty(m_vecDirection);
   AddClientProperty(r);
   AddClientProperty(g);
   AddClientProperty(b);
   AddClientProperty(a);
   AddClientProperty(m_nAmount);
EndClientClass();

BeginClientClass(CTEBreakModel, DT_TEBreakModel);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_angRotation);
   AddClientProperty(m_vecSize);
   AddClientProperty(m_vecVelocity);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_nRandomization);
   AddClientProperty(m_nCount);
   AddClientProperty(m_fTime);
   AddClientProperty(m_nFlags);
EndClientClass();

BeginClientClass(CTEBSPDecal, DT_TEBSPDecal);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_nEntity);
   AddClientProperty(m_nIndex);
EndClientClass();

BeginClientClass(CTEBubbles, DT_TEBubbles);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecMins);
   AddClientProperty(m_vecMaxs);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_fHeight);
   AddClientProperty(m_nCount);
   AddClientProperty(m_fSpeed);
EndClientClass();

BeginClientClass(CTEBubbleTrail, DT_TEBubbleTrail);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecMins);
   AddClientProperty(m_vecMaxs);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_flWaterZ);
   AddClientProperty(m_nCount);
   AddClientProperty(m_fSpeed);
EndClientClass();

BeginClientClass(CTEClientProjectile, DT_TEClientProjectile);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_vecVelocity);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_nLifeTime);
   AddClientProperty(m_hOwner);
EndClientClass();

BeginClientClass(CTEDecal, DT_TEDecal);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_vecStart);
   AddClientProperty(m_nEntity);
   AddClientProperty(m_nHitbox);
   AddClientProperty(m_nIndex);
EndClientClass();

BeginClientClass(CTEDotaBloodImpact, DT_TEDotaBloodImpact);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_hEntity);
   AddClientProperty(m_flScale);
   AddClientProperty(m_flXNormal);
   AddClientProperty(m_flYNormal);
EndClientClass();

BeginClientClass(CTEDOTAProjectile, DT_TEDOTAProjectile);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_iMoveSpeed);
   AddClientProperty(m_hSource);
   AddClientProperty(m_hTarget);
   AddClientProperty(m_iSourceAttachment);
   AddClientProperty(m_iParticleSystem);
   AddClientProperty(m_bDodgeable);
   AddClientProperty(m_bIsAttack);
   AddClientProperty(m_bIsEvaded);
   AddClientProperty(m_flExpireTime);
EndClientClass();

BeginClientClass(CTEDOTAProjectileLoc, DT_TEDOTAProjectileLoc);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_iMoveSpeed);
   AddClientProperty(m_vSourceLoc);
   AddClientProperty(m_vTargetLoc);
   AddClientProperty(m_hTarget);
   AddClientProperty(m_iParticleSystem);
   AddClientProperty(m_bDodgeable);
   AddClientProperty(m_bIsAttack);
   AddClientProperty(m_bIsEvaded);
   AddClientProperty(m_flExpireTime);
EndClientClass();

BeginClientClass(CTEDust, DT_TEDust);
   ClientBaseClass(CTEParticleSystem);
   AddClientProperty(m_flSize);
   AddClientProperty(m_flSpeed);
   AddClientProperty(m_vecDirection);
EndClientClass();

BeginClientClass(CTEDynamicLight, DT_TEDynamicLight);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(r);
   AddClientProperty(g);
   AddClientProperty(b);
   AddClientProperty(exponent);
   AddClientProperty(m_fRadius);
   AddClientProperty(m_fTime);
   AddClientProperty(m_fDecay);
EndClientClass();

BeginClientStruct(DT_EffectData);
   AddClientProperty(m_vOrigin.x);
   AddClientProperty(m_vOrigin.y);
   AddClientProperty(m_vOrigin.z);
   AddClientProperty(m_vStart.x);
   AddClientProperty(m_vStart.y);
   AddClientProperty(m_vStart.z);
   AddClientProperty(m_vAngles);
   AddClientProperty(m_vNormal);
   AddClientProperty(m_fFlags);
   AddClientProperty(m_flMagnitude);
   AddClientProperty(m_flScale);
   AddClientProperty(m_nAttachmentIndex);
   AddClientProperty(m_nSurfaceProp);
   AddClientProperty(m_iEffectName);
   AddClientProperty(m_nMaterial);
   AddClientProperty(m_nDamageType);
   AddClientProperty(m_nHitBox);
   AddClientProperty(entindex);
   AddClientProperty(m_nOtherEntIndex);
   AddClientProperty(m_nColor);
   AddClientProperty(m_flRadius);
EndClientStruct();

BeginClientClass(CTEEffectDispatch, DT_TEEffectDispatch);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_EffectData);
EndClientClass();

BeginClientClass(CTEEnergySplash, DT_TEEnergySplash);
   AddClientProperty(m_vecPos);
   AddClientProperty(m_vecDir);
   AddClientProperty(m_bExplosive);
EndClientClass();

BeginClientClass(CTEExplosion, DT_TEExplosion);
   ClientBaseClass(CTEParticleSystem);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_fScale);
   AddClientProperty(m_nFrameRate);
   AddClientProperty(m_nFlags);
   AddClientProperty(m_vecNormal);
   AddClientProperty(m_chMaterialType);
   AddClientProperty(m_nRadius);
   AddClientProperty(m_nMagnitude);
EndClientClass();

BeginClientClass(CTEFizz, DT_TEFizz);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_nEntity);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_nDensity);
   AddClientProperty(m_nCurrent);
EndClientClass();

BeginClientClass(CTEFootprintDecal, DT_TEFootprintDecal);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_vecDirection);
   AddClientProperty(m_nEntity);
   AddClientProperty(m_nIndex);
   AddClientProperty(m_chMaterialType);
EndClientClass();

BeginClientClass(CTEFoundryHelpers, DT_TEFoundryHelpers);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_iEntity);
EndClientClass();

BeginClientClass(CTEGaussExplosion, DT_TEGaussExplosion);
   ClientBaseClass(CTEParticleSystem);
   AddClientProperty(m_nType);
   AddClientProperty(m_vecDirection);
EndClientClass();

BeginClientClass(CTEGlowSprite, DT_TEGlowSprite);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_fScale);
   AddClientProperty(m_fLife);
   AddClientProperty(m_nBrightness);
EndClientClass();

BeginClientClass(CTEImpact, DT_TEImpact);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_vecNormal);
   AddClientProperty(m_iType);
EndClientClass();

BeginClientClass(CTEKillPlayerAttachments, DT_TEKillPlayerAttachments);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_nPlayer);
EndClientClass();

BeginClientClass(CTELargeFunnel, DT_TELargeFunnel);
   ClientBaseClass(CTEParticleSystem);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_nReversed);
EndClientClass();

BeginClientClass(CTEMetalSparks, DT_TEMetalSparks);
   AddClientProperty(m_vecPos);
   AddClientProperty(m_vecDir);
EndClientClass();

BeginClientClass(CTEMuzzleFlash, DT_TEMuzzleFlash);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_vecAngles);
   AddClientProperty(m_flScale);
   AddClientProperty(m_nType);
EndClientClass();

BeginClientClass(CTEParticleSystem, DT_TEParticleSystem);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
EndClientClass();

BeginClientClass(CTEPhysicsProp, DT_TEPhysicsProp);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_angRotation);
   AddClientProperty(m_vecVelocity);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_nSkin);
   AddClientProperty(m_nFlags);
   AddClientProperty(m_nEffects);
EndClientClass();

BeginClientClass(CTEPlayerDecal, DT_TEPlayerDecal);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_nEntity);
   AddClientProperty(m_nPlayer);
EndClientClass();

BeginClientClass(CTEProjectedDecal, DT_TEProjectedDecal);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_angRotation);
   AddClientProperty(m_flDistance);
   AddClientProperty(m_nIndex);
EndClientClass();

BeginClientClass(CTEShatterSurface, DT_TEShatterSurface);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_vecAngles);
   AddClientProperty(m_vecForce);
   AddClientProperty(m_vecForcePos);
   AddClientProperty(m_flWidth);
   AddClientProperty(m_flHeight);
   AddClientProperty(m_flShardSize);
   AddClientProperty(m_nSurfaceType);
   AddClientProperty(m_uchFrontColor);
   AddClientProperty(m_uchBackColor);
EndClientClass();

BeginClientClass(CTEShowLine, DT_TEShowLine);
   ClientBaseClass(CTEParticleSystem);
   AddClientProperty(m_vecEnd);
EndClientClass();

BeginClientClass(CTesla, DT_Tesla);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_SoundName);
   AddClientProperty(m_iszSpriteName);
EndClientClass();

BeginClientClass(CTESmoke, DT_TESmoke);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_fScale);
   AddClientProperty(m_nFrameRate);
EndClientClass();

BeginClientClass(CTESparks, DT_TESparks);
   ClientBaseClass(CTEParticleSystem);
   AddClientProperty(m_nMagnitude);
   AddClientProperty(m_nTrailLength);
   AddClientProperty(m_vecDir);
EndClientClass();

BeginClientClass(CTESprite, DT_TESprite);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_fScale);
   AddClientProperty(m_nBrightness);
EndClientClass();

BeginClientClass(CTESpriteSpray, DT_TESpriteSpray);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_vecDirection);
   AddClientProperty(m_nModelIndex);
   AddClientProperty(m_fNoise);
   AddClientProperty(m_nSpeed);
   AddClientProperty(m_nCount);
EndClientClass();

BeginClientStruct(DT_ProxyToggle_ProxiedData);
   AddClientProperty(m_WithProxy);
EndClientStruct();

BeginClientClass(CTest_ProxyToggle_Networkable, DT_ProxyToggle);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(blah);
EndClientClass();

BeginClientClass(CTestTraceline, DT_TestTraceline);
   AddClientProperty(m_clrRender);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_angRotation);
   AddClientProperty(moveparent);
EndClientClass();

BeginClientClass(CTEUnitAnimation, DT_TEUnitAnimation);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_flCastPoint);
   AddClientProperty(m_hEntity);
   AddClientProperty(m_flPlaybackRate);
   AddClientProperty(m_iSequenceIndex);
   AddClientProperty(m_iType);
   AddClientProperty(m_Activity);
EndClientClass();

BeginClientClass(CTEUnitAnimationEnd, DT_TEUnitAnimationEnd);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_hEntity);
   AddClientProperty(m_bSnap);
EndClientClass();

BeginClientClass(CTEWorldDecal, DT_TEWorldDecal);
   ClientBaseClass(CBaseTempEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_nIndex);
EndClientClass();

BeginClientClass(CTFWearableItem, DT_TFWearableItem);
   ClientBaseClass(CEconWearable);
EndClientClass();

BeginClientClass(CTriggerCamera, DT_TriggerCamera);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_vecOrigin);
   AddClientProperty(m_angRotation);
EndClientClass();

BeginClientClass(CTriggerPlayerMovement, DT_TriggerPlayerMovement);
   ClientBaseClass(CBaseTrigger);
EndClientClass();

BeginClientClass(CVGuiScreen, DT_VGuiScreen);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_flWidth);
   AddClientProperty(m_flHeight);
   AddClientProperty(m_nAttachmentIndex);
   AddClientProperty(m_nPanelName);
   AddClientProperty(m_fScreenFlags);
   AddClientProperty(m_nOverlayMaterial);
   AddClientProperty(m_hPlayerOwner);
EndClientClass();

BeginClientClass(CWaterBullet, DT_WaterBullet);
   ClientBaseClass(CBaseAnimating);
EndClientClass();

BeginClientClass(CWaterLODControl, DT_WaterLODControl);
   AddClientProperty(m_flCheapWaterStartDistance);
   AddClientProperty(m_flCheapWaterEndDistance);
EndClientClass();

BeginClientClass(CWorld, DT_WORLD);
   ClientBaseClass(CBaseEntity);
   AddClientProperty(m_flWaveHeight);
   AddClientProperty(m_WorldMins);
   AddClientProperty(m_WorldMaxs);
   AddClientProperty(m_bStartDark);
   AddClientProperty(m_flMaxOccludeeArea);
   AddClientProperty(m_flMinOccluderArea);
   AddClientProperty(m_flMaxPropScreenSpaceWidth);
   AddClientProperty(m_flMinPropScreenSpaceWidth);
   AddClientProperty(m_iszDetailSpriteMaterial);
   AddClientProperty(m_bColdWorld);
EndClientClass();

BeginClientClass(DustTrail, DT_DustTrail);
   ClientBaseClass(CBaseParticleEntity);
   AddClientProperty(m_SpawnRate);
   AddClientProperty(m_Color);
   AddClientProperty(m_ParticleLifetime);
   AddClientProperty(m_StopEmitTime);
   AddClientProperty(m_MinSpeed);
   AddClientProperty(m_MaxSpeed);
   AddClientProperty(m_MinDirectedSpeed);
   AddClientProperty(m_MaxDirectedSpeed);
   AddClientProperty(m_StartSize);
   AddClientProperty(m_EndSize);
   AddClientProperty(m_SpawnRadius);
   AddClientProperty(m_bEmit);
   AddClientProperty(m_Opacity);
EndClientClass();

BeginClientClass(MovieExplosion, DT_MovieExplosion);
   ClientBaseClass(CBaseParticleEntity);
EndClientClass();

BeginClientClass(NextBotCombatCharacter, DT_NextBot);
   ClientBaseClass(CBaseCombatCharacter);
EndClientClass();

BeginClientClass(ParticleSmokeGrenade, DT_ParticleSmokeGrenade);
   ClientBaseClass(CBaseParticleEntity);
   AddClientProperty(m_flSpawnTime);
   AddClientProperty(m_FadeStartTime);
   AddClientProperty(m_FadeEndTime);
   AddClientProperty(m_CurrentStage);
EndClientClass();

BeginClientClass(RocketTrail, DT_RocketTrail);
   ClientBaseClass(CBaseParticleEntity);
   AddClientProperty(m_SpawnRate);
   AddClientProperty(m_StartColor);
   AddClientProperty(m_EndColor);
   AddClientProperty(m_ParticleLifetime);
   AddClientProperty(m_StopEmitTime);
   AddClientProperty(m_MinSpeed);
   AddClientProperty(m_MaxSpeed);
   AddClientProperty(m_StartSize);
   AddClientProperty(m_EndSize);
   AddClientProperty(m_SpawnRadius);
   AddClientProperty(m_bEmit);
   AddClientProperty(m_nAttachment);
   AddClientProperty(m_Opacity);
   AddClientProperty(m_bDamaged);
   AddClientProperty(m_flFlareScale);
EndClientClass();

BeginClientClass(SmokeTrail, DT_SmokeTrail);
   ClientBaseClass(CBaseParticleEntity);
   AddClientProperty(m_SpawnRate);
   AddClientProperty(m_StartColor);
   AddClientProperty(m_EndColor);
   AddClientProperty(m_ParticleLifetime);
   AddClientProperty(m_StopEmitTime);
   AddClientProperty(m_MinSpeed);
   AddClientProperty(m_MaxSpeed);
   AddClientProperty(m_MinDirectedSpeed);
   AddClientProperty(m_MaxDirectedSpeed);
   AddClientProperty(m_StartSize);
   AddClientProperty(m_EndSize);
   AddClientProperty(m_SpawnRadius);
   AddClientProperty(m_bEmit);
   AddClientProperty(m_nAttachment);
   AddClientProperty(m_Opacity);
EndClientClass();

BeginClientClass(SporeExplosion, DT_SporeExplosion);
   ClientBaseClass(CBaseParticleEntity);
   AddClientProperty(m_flSpawnRate);
   AddClientProperty(m_flParticleLifetime);
   AddClientProperty(m_flStartSize);
   AddClientProperty(m_flEndSize);
   AddClientProperty(m_flSpawnRadius);
   AddClientProperty(m_bEmit);
   AddClientProperty(m_bDontRemove);
EndClientClass();

BeginClientClass(SporeTrail, DT_SporeTrail);
   ClientBaseClass(CBaseParticleEntity);
   AddClientProperty(m_flSpawnRate);
   AddClientProperty(m_vecEndColor);
   AddClientProperty(m_flParticleLifetime);
   AddClientProperty(m_flStartSize);
   AddClientProperty(m_flEndSize);
   AddClientProperty(m_flSpawnRadius);
   AddClientProperty(m_bEmit);
EndClientClass();

std::map<std::string, const ClientClassBase*> ClientClassList::mClassMap = {
   { "DT_AI_BaseNPC", ClientClass<CAI_BaseNPC>::InstancePtr },
   { "DT_BaseAnimating", ClientClass<CBaseAnimating>::InstancePtr },
   { "DT_BaseAnimatingOverlay", ClientClass<CBaseAnimatingOverlay>::InstancePtr },
   { "DT_BaseAttributableItem", ClientClass<CBaseAttributableItem>::InstancePtr },
   { "DT_BaseButton", ClientClass<CBaseButton>::InstancePtr },
   { "DT_BaseCombatCharacter", ClientClass<CBaseCombatCharacter>::InstancePtr },
   { "DT_BaseCombatWeapon", ClientClass<CBaseCombatWeapon>::InstancePtr },
   { "DT_BaseDoor", ClientClass<CBaseDoor>::InstancePtr },
   { "DT_BaseEntity", ClientClass<CBaseEntity>::InstancePtr },
   { "DT_BaseFlex", ClientClass<CBaseFlex>::InstancePtr },
   { "DT_BaseGrenade", ClientClass<CBaseGrenade>::InstancePtr },
   { "DT_BaseParticleEntity", ClientClass<CBaseParticleEntity>::InstancePtr },
   { "DT_BasePlayer", ClientClass<CBasePlayer>::InstancePtr },
   { "DT_BasePropDoor", ClientClass<CBasePropDoor>::InstancePtr },
   { "DT_BaseTempEntity", ClientClass<CBaseTempEntity>::InstancePtr },
   { "DT_BaseToggle", ClientClass<CBaseToggle>::InstancePtr },
   { "DT_BaseTrigger", ClientClass<CBaseTrigger>::InstancePtr },
   { "DT_BaseViewModel", ClientClass<CBaseViewModel>::InstancePtr },
   { "DT_Beam", ClientClass<CBeam>::InstancePtr },
   { "DT_BeamSpotlight", ClientClass<CBeamSpotlight>::InstancePtr },
   { "DT_BoneFollower", ClientClass<CBoneFollower>::InstancePtr },
   { "DT_BreakableProp", ClientClass<CBreakableProp>::InstancePtr },
   { "DT_BreakableSurface", ClientClass<CBreakableSurface>::InstancePtr },
   { "DT_ColorCorrection", ClientClass<CColorCorrection>::InstancePtr },
   { "DT_ColorCorrectionVolume", ClientClass<CColorCorrectionVolume>::InstancePtr },
   { "DT_DOTA_Ability_AbyssalUnderlord_DarkRift", ClientClass<CDOTA_Ability_AbyssalUnderlord_DarkRift>::InstancePtr },
   { "DT_DOTA_Ability_AbyssalUnderlord_Firestorm", ClientClass<CDOTA_Ability_AbyssalUnderlord_Firestorm>::InstancePtr },
   { "DT_DOTA_Ability_AbyssalUnderlord_PitOfMalice", ClientClass<CDOTA_Ability_AbyssalUnderlord_PitOfMalice>::InstancePtr },
   { "DT_DOTA_Ability_Alchemist_AcidSpray", ClientClass<CDOTA_Ability_Alchemist_AcidSpray>::InstancePtr },
   { "DT_DOTA_Ability_AncientApparition_ChillingTouch", ClientClass<CDOTA_Ability_AncientApparition_ChillingTouch>::InstancePtr },
   { "DT_DOTA_Ability_AncientApparition_ColdFeet", ClientClass<CDOTA_Ability_AncientApparition_ColdFeet>::InstancePtr },
   { "DT_DOTA_Ability_AncientApparition_RocketFlare", ClientClass<CDOTA_Ability_AncientApparition_IceBlast>::InstancePtr },
   { "DT_DOTA_Ability_AncientApparition_IceVortex", ClientClass<CDOTA_Ability_AncientApparition_IceVortex>::InstancePtr },
   { "DT_DOTA_Ability_AntiMage_Blink", ClientClass<CDOTA_Ability_AntiMage_Blink>::InstancePtr },
   { "DT_DOTA_Ability_AntiMage_ManaVoid", ClientClass<CDOTA_Ability_AntiMage_ManaVoid>::InstancePtr },
   { "DT_DOTA_Ability_AttributeBonus", ClientClass<CDOTA_Ability_AttributeBonus>::InstancePtr },
   { "DT_DOTA_Ability_Axe_BerserkersCall", ClientClass<CDOTA_Ability_Axe_BerserkersCall>::InstancePtr },
   { "DT_DOTA_Ability_Axe_CounterHelix", ClientClass<CDOTA_Ability_Axe_CounterHelix>::InstancePtr },
   { "DT_DOTA_Ability_Axe_CullingBlade", ClientClass<CDOTA_Ability_Axe_CullingBlade>::InstancePtr },
   { "DT_DOTA_Ability_Bane_FiendsGrip", ClientClass<CDOTA_Ability_Bane_FiendsGrip>::InstancePtr },
   { "DT_DOTA_Ability_Batrider_Flamebreak", ClientClass<CDOTA_Ability_Batrider_Flamebreak>::InstancePtr },
   { "DT_DOTA_Ability_Batrider_StickyNapalm", ClientClass<CDOTA_Ability_Batrider_StickyNapalm>::InstancePtr },
   { "DT_DOTA_Ability_Beastmaster_PrimalRoar", ClientClass<CDOTA_Ability_Beastmaster_PrimalRoar>::InstancePtr },
   { "DT_DOTA_Ability_Bloodseeker_Bloodbath", ClientClass<CDOTA_Ability_Bloodseeker_Bloodbath>::InstancePtr },
   { "DT_DOTA_Ability_BountyHunter_ShurikenToss", ClientClass<CDOTA_Ability_BountyHunter_ShurikenToss>::InstancePtr },
   { "DT_DOTA_Ability_Brewmaster_DispelMagic", ClientClass<CDOTA_Ability_Brewmaster_DispelMagic>::InstancePtr },
   { "DT_DOTA_Ability_Brewmaster_DrunkenBrawler", ClientClass<CDOTA_Ability_Brewmaster_DrunkenBrawler>::InstancePtr },
   { "DT_DOTA_Ability_Brewmaster_DrunkenHaze", ClientClass<CDOTA_Ability_Brewmaster_DrunkenHaze>::InstancePtr },
   { "DT_DOTA_Ability_Brewmaster_PrimalSplit", ClientClass<CDOTA_Ability_Brewmaster_PrimalSplit>::InstancePtr },
   { "DT_DOTA_Ability_Bristleback_QuillSpray", ClientClass<CDOTA_Ability_Bristleback_QuillSpray>::InstancePtr },
   { "DT_DOTA_Ability_Broodmother_SpinWeb", ClientClass<CDOTA_Ability_Broodmother_SpinWeb>::InstancePtr },
   { "DT_DOTA_Ability_Centaur_Stampede", ClientClass<CDOTA_Ability_Centaur_Stampede>::InstancePtr },
   { "DT_DOTA_Ability_ChaosKnight_Phantasm", ClientClass<CDOTA_Ability_ChaosKnight_Phantasm>::InstancePtr },
   { "DT_DOTA_Ability_Chen_HandOfGod", ClientClass<CDOTA_Ability_Chen_HandOfGod>::InstancePtr },
   { "DT_DOTA_Ability_Chen_HolyPersuasion", ClientClass<CDOTA_Ability_Chen_HolyPersuasion>::InstancePtr },
   { "DT_DOTA_Ability_Chen_TestOfFaithTeleport", ClientClass<CDOTA_Ability_Chen_TestOfFaithTeleport>::InstancePtr },
   { "DT_DOTA_Ability_Courier_TakeStashItems", ClientClass<CDOTA_Ability_Courier_TakeStashItems>::InstancePtr },
   { "DT_DOTA_Ability_Courier_TransferItems", ClientClass<CDOTA_Ability_Courier_TransferItems>::InstancePtr },
   { "DT_DOTA_Ability_CrystalMaiden_CrystalNova", ClientClass<CDOTA_Ability_CrystalMaiden_CrystalNova>::InstancePtr },
   { "DT_DOTA_Ability_CrystalMaiden_FreezingField", ClientClass<CDOTA_Ability_CrystalMaiden_FreezingField>::InstancePtr },
   { "DT_DOTA_Ability_DarkSeer_Vacuum", ClientClass<CDOTA_Ability_DarkSeer_Vacuum>::InstancePtr },
   { "DT_DOTA_Ability_DataDriven", ClientClass<CDOTA_Ability_DataDriven>::InstancePtr },
   { "DT_DOTA_Ability_Dazzle_Weave", ClientClass<CDOTA_Ability_Dazzle_Weave>::InstancePtr },
   { "DT_DOTA_Ability_DeathProphet_CarrionSwarm", ClientClass<CDOTA_Ability_DeathProphet_CarrionSwarm>::InstancePtr },
   { "DT_DOTA_Ability_DeathProphet_Silence", ClientClass<CDOTA_Ability_DeathProphet_Silence>::InstancePtr },
   { "DT_DOTA_Ability_Disruptor_KineticField", ClientClass<CDOTA_Ability_Disruptor_KineticField>::InstancePtr },
   { "DT_DOTA_Ability_Disruptor_StaticStorm", ClientClass<CDOTA_Ability_Disruptor_StaticStorm>::InstancePtr },
   { "DT_DOTA_Ability_DoomBringer_Devour", ClientClass<CDOTA_Ability_DoomBringer_Devour>::InstancePtr },
   { "DT_DOTA_Unit_Ability_DragonKnight_BreatheFire", ClientClass<CDOTA_Ability_DragonKnight_BreatheFire>::InstancePtr },
   { "DT_DOTA_Ability_DrowRanger_Silence", ClientClass<CDOTA_Ability_DrowRanger_Silence>::InstancePtr },
   { "DT_DOTA_Unit_Ability_DrowRanger_WaveOfSilence", ClientClass<CDOTA_Ability_DrowRanger_WaveOfSilence>::InstancePtr },
   { "DT_DOTA_Ability_EarthSpirit_BoulderSmash", ClientClass<CDOTA_Ability_EarthSpirit_BoulderSmash>::InstancePtr },
   { "DT_DOTA_Ability_EarthSpirit_GeomagneticGrip", ClientClass<CDOTA_Ability_EarthSpirit_GeomagneticGrip>::InstancePtr },
   { "DT_DOTA_Ability_EarthSpirit_Petrify", ClientClass<CDOTA_Ability_EarthSpirit_Petrify>::InstancePtr },
   { "DT_DOTA_Ability_EarthSpirit_RollingBoulder", ClientClass<CDOTA_Ability_EarthSpirit_RollingBoulder>::InstancePtr },
   { "DT_DOTA_Ability_EarthSpirit_StoneCaller", ClientClass<CDOTA_Ability_EarthSpirit_StoneCaller>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Elder_Titan_EarthSplitter", ClientClass<CDOTA_Ability_Elder_Titan_EarthSplitter>::InstancePtr },
   { "DT_DOTA_Ability_EmberSpirit_Activate_FireRemnant", ClientClass<CDOTA_Ability_EmberSpirit_Activate_FireRemnant>::InstancePtr },
   { "DT_DOTA_Ability_EmberSpirit_FireRemnant", ClientClass<CDOTA_Ability_EmberSpirit_FireRemnant>::InstancePtr },
   { "DT_DOTA_Ability_EmberSpirit_SearingChains", ClientClass<CDOTA_Ability_EmberSpirit_SearingChains>::InstancePtr },
   { "DT_DOTA_Ability_EmberSpirit_SleightOfFist", ClientClass<CDOTA_Ability_EmberSpirit_SleightOfFist>::InstancePtr },
   { "DT_DOTA_Ability_Enchantress_Impetus", ClientClass<CDOTA_Ability_Enchantress_Impetus>::InstancePtr },
   { "DT_DOTA_Ability_Enchantress_NaturesAttendants", ClientClass<CDOTA_Ability_Enchantress_NaturesAttendants>::InstancePtr },
   { "DT_DOTA_Ability_Enchantress_Untouchable", ClientClass<CDOTA_Ability_Enchantress_Untouchable>::InstancePtr },
   { "DT_DOTA_Ability_Enigma_BlackHole", ClientClass<CDOTA_Ability_Enigma_BlackHole>::InstancePtr },
   { "DT_DOTA_Ability_Enigma_DemonicConversion", ClientClass<CDOTA_Ability_Enigma_DemonicConversion>::InstancePtr },
   { "DT_DOTA_Ability_Enigma_MidnightPulse", ClientClass<CDOTA_Ability_Enigma_MidnightPulse>::InstancePtr },
   { "DT_DOTA_Ability_FacelessVoid_Chronosphere", ClientClass<CDOTA_Ability_FacelessVoid_Chronosphere>::InstancePtr },
   { "DT_DOTA_Unit_Ability_FacelessVoid_TimeWalk", ClientClass<CDOTA_Ability_FacelessVoid_TimeWalk>::InstancePtr },
   { "DT_DOTA_Ability_Furion_ForceOfNature", ClientClass<CDOTA_Ability_Furion_ForceOfNature>::InstancePtr },
   { "DT_DOTA_Ability_Furion_Teleportation", ClientClass<CDOTA_Ability_Furion_Teleportation>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_BlackHole", ClientClass<CDOTA_Ability_Greevil_BlackHole>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_BladeFury", ClientClass<CDOTA_Ability_Greevil_BladeFury>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Bloodlust", ClientClass<CDOTA_Ability_Greevil_Bloodlust>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_ColdSnap", ClientClass<CDOTA_Ability_Greevil_ColdSnap>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Decrepify", ClientClass<CDOTA_Ability_Greevil_Decrepify>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Diabolic_Edict", ClientClass<CDOTA_Ability_Greevil_Diabolic_Edict>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_EchoSlam", ClientClass<CDOTA_Ability_Greevil_EchoSlam>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Fatal_Bonds", ClientClass<CDOTA_Ability_Greevil_Fatal_Bonds>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_FleshGolem", ClientClass<CDOTA_Ability_Greevil_FleshGolem>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_IceWall", ClientClass<CDOTA_Ability_Greevil_IceWall>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_LagunaBlade", ClientClass<CDOTA_Ability_Greevil_LagunaBlade>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_LeechSeed", ClientClass<CDOTA_Ability_Greevil_LeechSeed>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Magic_Missile", ClientClass<CDOTA_Ability_Greevil_Magic_Missile>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Maledict", ClientClass<CDOTA_Ability_Greevil_Maledict>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_MeatHook", ClientClass<CDOTA_Ability_Greevil_MeatHook>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Miniboss_Black_BrainSap", ClientClass<CDOTA_Ability_Greevil_Miniboss_Black_BrainSap>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Miniboss_Black_Nightmare", ClientClass<CDOTA_Ability_Greevil_Miniboss_Black_Nightmare>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Miniboss_White_ColdFeet", ClientClass<CDOTA_Ability_Greevil_Miniboss_Blue_ColdFeet>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Miniboss_White_IceVortex", ClientClass<CDOTA_Ability_Greevil_Miniboss_Blue_IceVortex>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Miniboss_Green_LivingArmor", ClientClass<CDOTA_Ability_Greevil_Miniboss_Green_LivingArmor>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Miniboss_Green_Overgrowth", ClientClass<CDOTA_Ability_Greevil_Miniboss_Green_Overgrowth>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Miniboss_Orange_DragonSlave", ClientClass<CDOTA_Ability_Greevil_Miniboss_Orange_DragonSlave>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Miniboss_Orange_LightStrikeArray", ClientClass<CDOTA_Ability_Greevil_Miniboss_Orange_LightStrikeArray>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Miniboss_Purple_PlagueWard", ClientClass<CDOTA_Ability_Greevil_Miniboss_Purple_PlagueWard>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Miniboss_Purple_VenomousGale", ClientClass<CDOTA_Ability_Greevil_Miniboss_Purple_VenomousGale>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Miniboss_Red_Earthshock", ClientClass<CDOTA_Ability_Greevil_Miniboss_Red_Earthshock>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Miniboss_Red_Overpower", ClientClass<CDOTA_Ability_Greevil_Miniboss_Red_Overpower>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Miniboss_Sight", ClientClass<CDOTA_Ability_Greevil_Miniboss_Sight>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Miniboss_White_Degen_Aura", ClientClass<CDOTA_Ability_Greevil_Miniboss_White_Degen_Aura>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Miniboss_White_Purification", ClientClass<CDOTA_Ability_Greevil_Miniboss_White_Purification>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Miniboss_Yellow_IonShell", ClientClass<CDOTA_Ability_Greevil_Miniboss_Yellow_IonShell>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Miniboss_Yellow_Surge", ClientClass<CDOTA_Ability_Greevil_Miniboss_Yellow_Surge>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_NaturesAttendants", ClientClass<CDOTA_Ability_Greevil_NaturesAttendants>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_PhantomStrike", ClientClass<CDOTA_Ability_Greevil_PhantomStrike>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_PoisonNova", ClientClass<CDOTA_Ability_Greevil_PoisonNova>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Purification", ClientClass<CDOTA_Ability_Greevil_Purification>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_Rot", ClientClass<CDOTA_Ability_Greevil_Rot>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_ShadowStrike", ClientClass<CDOTA_Ability_Greevil_ShadowStrike>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_ShadowWave", ClientClass<CDOTA_Ability_Greevil_ShadowWave>::InstancePtr },
   { "DT_DOTA_Ability_Greevil_TimeLock", ClientClass<CDOTA_Ability_Greevil_TimeLock>::InstancePtr },
   { "DT_DOTA_Ability_Gyrocopter_Call_Down", ClientClass<CDOTA_Ability_Gyrocopter_Call_Down>::InstancePtr },
   { "DT_DOTA_Ability_Healing_Campfire", ClientClass<CDOTA_Ability_Healing_Campfire>::InstancePtr },
   { "DT_DOTA_Ability_Holdout_CullingBlade", ClientClass<CDOTA_Ability_Holdout_CullingBlade>::InstancePtr },
   { "DT_DOTA_Ability_Holdout_GladiatorsUnite", ClientClass<CDOTA_Ability_Holdout_GladiatorsUnite>::InstancePtr },
   { "DT_DOTA_Ability_Holdout_Multishot", ClientClass<CDOTA_Ability_Holdout_Multishot>::InstancePtr },
   { "DT_DOTA_Ability_Holdout_Omnislash", ClientClass<CDOTA_Ability_Holdout_Omnislash>::InstancePtr },
   { "DT_DOTA_Ability_Huskar_Life_Break", ClientClass<CDOTA_Ability_Huskar_Life_Break>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Invoker_DeafeningBlast", ClientClass<CDOTA_Ability_Invoker_DeafeningBlast>::InstancePtr },
   { "DT_DOTA_Ability_Invoker_EMP", ClientClass<CDOTA_Ability_Invoker_EMP>::InstancePtr },
   { "DT_DOTA_Ability_Invoker_Invoke", ClientClass<CDOTA_Ability_Invoker_Invoke>::InstancePtr },
   { "DT_DOTA_Ability_Invoker_InvokedBase", ClientClass<CDOTA_Ability_Invoker_InvokedBase>::InstancePtr },
   { "DT_DOTA_Ability_Invoker_SunStrike", ClientClass<CDOTA_Ability_Invoker_SunStrike>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Invoker_Tornado", ClientClass<CDOTA_Ability_Invoker_Tornado>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Jakiro_DualBreath", ClientClass<CDOTA_Ability_Jakiro_DualBreath>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Jakiro_IcePath", ClientClass<CDOTA_Ability_Jakiro_IcePath>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Jakiro_Macropyre", ClientClass<CDOTA_Ability_Jakiro_Macropyre>::InstancePtr },
   { "DT_DOTA_Ability_Juggernaut_HealingWard", ClientClass<CDOTA_Ability_Juggernaut_HealingWard>::InstancePtr },
   { "DT_DOTA_Ability_Juggernaut_Omnislash", ClientClass<CDOTA_Ability_Juggernaut_Omnislash>::InstancePtr },
   { "DT_DOTA_Ability_KeeperOfTheLight_BlindingLight", ClientClass<CDOTA_Ability_KeeperOfTheLight_BlindingLight>::InstancePtr },
   { "DT_DOTA_Unit_Ability_KeeperOfTheLight_Illuminate", ClientClass<CDOTA_Ability_KeeperOfTheLight_Illuminate>::InstancePtr },
   { "DT_DOTA_Ability_KeeperOfTheLight_Recall", ClientClass<CDOTA_Ability_KeeperOfTheLight_Recall>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Kunkka_GhostShip", ClientClass<CDOTA_Ability_Kunkka_GhostShip>::InstancePtr },
   { "DT_DOTA_Ability_Kunkka_Tidebringer", ClientClass<CDOTA_Ability_Kunkka_Tidebringer>::InstancePtr },
   { "DT_DOTA_Ability_Kunkka_Torrent", ClientClass<CDOTA_Ability_Kunkka_Torrent>::InstancePtr },
   { "DT_DOTA_Ability_Legion_Commander_MomentOfCourage", ClientClass<CDOTA_Ability_Legion_Commander_MomentOfCourage>::InstancePtr },
   { "DT_DOTA_Ability_Legion_Commander_OverwhelmingOdds", ClientClass<CDOTA_Ability_Legion_Commander_OverwhelmingOdds>::InstancePtr },
   { "DT_DOTA_Ability_Leshrac_Diabolic_Edict", ClientClass<CDOTA_Ability_Leshrac_Diabolic_Edict>::InstancePtr },
   { "DT_DOTA_Ability_Leshrac_Pulse_Nova", ClientClass<CDOTA_Ability_Leshrac_Pulse_Nova>::InstancePtr },
   { "DT_DOTA_Ability_Leshrac_Split_Earth", ClientClass<CDOTA_Ability_Leshrac_Split_Earth>::InstancePtr },
   { "DT_DOTA_Ability_Lich_ChainFrost", ClientClass<CDOTA_Ability_Lich_ChainFrost>::InstancePtr },
   { "DT_DOTA_Ability_Lich_FrostNova", ClientClass<CDOTA_Ability_Lich_FrostNova>::InstancePtr },
   { "DT_DOTA_Ability_Life_Stealer_Infest", ClientClass<CDOTA_Ability_Life_Stealer_Infest>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Lina_DragonSlave", ClientClass<CDOTA_Ability_Lina_DragonSlave>::InstancePtr },
   { "DT_DOTA_Ability_Lina_LagunaBlade", ClientClass<CDOTA_Ability_Lina_LagunaBlade>::InstancePtr },
   { "DT_DOTA_Ability_Lina_LightStrikeArray", ClientClass<CDOTA_Ability_Lina_LightStrikeArray>::InstancePtr },
   { "DT_DOTA_Ability_Lion_FingerOfDeath", ClientClass<CDOTA_Ability_Lion_FingerOfDeath>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Lion_Impale", ClientClass<CDOTA_Ability_Lion_Impale>::InstancePtr },
   { "DT_DOTA_Ability_Lion_ManaDrain", ClientClass<CDOTA_Ability_Lion_ManaDrain>::InstancePtr },
   { "DT_DOTA_Ability_LoneDruid_Rabid", ClientClass<CDOTA_Ability_LoneDruid_Rabid>::InstancePtr },
   { "DT_DOTA_Ability_LoneDruid_SpiritBear", ClientClass<CDOTA_Ability_LoneDruid_SpiritBear>::InstancePtr },
   { "DT_DOTA_Ability_LoneDruid_SpiritBear_Return", ClientClass<CDOTA_Ability_LoneDruid_SpiritBear_Return>::InstancePtr },
   { "DT_DOTA_Ability_LoneDruid_TrueForm_BattleCry", ClientClass<CDOTA_Ability_LoneDruid_TrueForm_BattleCry>::InstancePtr },
   { "DT_DOTA_Ability_LoneDruid_TrueForm_Druid", ClientClass<CDOTA_Ability_LoneDruid_TrueForm_Druid>::InstancePtr },
   { "DT_DOTA_Ability_Luna_Eclipse", ClientClass<CDOTA_Ability_Luna_Eclipse>::InstancePtr },
   { "DT_DOTA_Ability_Luna_LunarBlessing", ClientClass<CDOTA_Ability_Luna_LunarBlessing>::InstancePtr },
   { "DT_DOTA_Ability_Lycan_Howl", ClientClass<CDOTA_Ability_Lycan_Howl>::InstancePtr },
   { "DT_DOTA_Ability_Lycan_SummonWolves", ClientClass<CDOTA_Ability_Lycan_SummonWolves>::InstancePtr },
   { "DT_DOTA_Ability_Magnataur_ReversePolarity", ClientClass<CDOTA_Ability_Magnataur_ReversePolarity>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Magnataur_Shockwave", ClientClass<CDOTA_Ability_Magnataur_Shockwave>::InstancePtr },
   { "DT_DOTA_Ability_Meepo_DividedWeStand", ClientClass<CDOTA_Ability_Meepo_DividedWeStand>::InstancePtr },
   { "DT_DOTA_Ability_Meepo_Earthbind", ClientClass<CDOTA_Ability_Meepo_Earthbind>::InstancePtr },
   { "DT_DOTA_Ability_Meepo_Poof", ClientClass<CDOTA_Ability_Meepo_Poof>::InstancePtr },
   { "DT_DOTA_Ability_Morphling_Replicate", ClientClass<CDOTA_Ability_Morphling_Replicate>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Morphling_Waveform", ClientClass<CDOTA_Ability_Morphling_Waveform>::InstancePtr },
   { "DT_DOTA_Ability_NagaSiren_MirrorImage", ClientClass<CDOTA_Ability_NagaSiren_MirrorImage>::InstancePtr },
   { "DT_DOTA_Ability_NagaSiren_RipTide", ClientClass<CDOTA_Ability_NagaSiren_RipTide>::InstancePtr },
   { "DT_DOTA_Ability_Necrolyte_Death_Pulse", ClientClass<CDOTA_Ability_Necrolyte_Death_Pulse>::InstancePtr },
   { "DT_DOTA_Ability_Necrolyte_ReapersScythe", ClientClass<CDOTA_Ability_Necrolyte_ReapersScythe>::InstancePtr },
   { "DT_Ability_Nevermore_Requiem", ClientClass<CDOTA_Ability_Nevermore_Requiem>::InstancePtr },
   { "DT_DOTA_Ability_Nian_Apocalypse", ClientClass<CDOTA_Ability_Nian_Apocalypse>::InstancePtr },
   { "DT_DOTA_Ability_Nian_Eruption", ClientClass<CDOTA_Ability_Nian_Eruption>::InstancePtr },
   { "DT_DOTA_Ability_Nian_Frenzy", ClientClass<CDOTA_Ability_Nian_Frenzy>::InstancePtr },
   { "DT_DOTA_Ability_Nian_Hurricane", ClientClass<CDOTA_Ability_Nian_Hurricane>::InstancePtr },
   { "DT_DOTA_Ability_Nian_Roar", ClientClass<CDOTA_Ability_Nian_Roar>::InstancePtr },
   { "DT_DOTA_Ability_Nian_Sigils", ClientClass<CDOTA_Ability_Nian_Sigils>::InstancePtr },
   { "DT_DOTA_Ability_Nian_Tail_Swipe", ClientClass<CDOTA_Ability_Nian_Tail_Swipe>::InstancePtr },
   { "DT_DOTA_Ability_Nian_Waterball", ClientClass<CDOTA_Ability_Nian_Waterball>::InstancePtr },
   { "DT_DOTA_Ability_Nian_Whirlpool", ClientClass<CDOTA_Ability_Nian_Whirlpool>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Nyx_Assassin_Impale", ClientClass<CDOTA_Ability_Nyx_Assassin_Impale>::InstancePtr },
   { "DT_DOTA_Ability_Obsidian_Destroyer_ArcaneOrb", ClientClass<CDOTA_Ability_Obsidian_Destroyer_ArcaneOrb>::InstancePtr },
   { "DT_DOTA_Ability_Obsidian_Destroyer_AstralImprisonment", ClientClass<CDOTA_Ability_Obsidian_Destroyer_AstralImprisonment>::InstancePtr },
   { "DT_Ability_Obsidian_Destroyer_SanityEclipse", ClientClass<CDOTA_Ability_Obsidian_Destroyer_SanityEclipse>::InstancePtr },
   { "DT_DOTA_Ability_Ogre_Magi_Bloodlust", ClientClass<CDOTA_Ability_Ogre_Magi_Bloodlust>::InstancePtr },
   { "DT_DOTA_Ability_Ogre_Magi_Fireblast", ClientClass<CDOTA_Ability_Ogre_Magi_Fireblast>::InstancePtr },
   { "DT_DOTA_Ability_Ogre_Magi_Multicast", ClientClass<CDOTA_Ability_Ogre_Magi_Multicast>::InstancePtr },
   { "DT_DOTA_Ability_Ogre_Magi_Unrefined_Fireblast", ClientClass<CDOTA_Ability_Ogre_Magi_Unrefined_Fireblast>::InstancePtr },
   { "DT_DOTA_Ability_Oracle_FortunesEnd", ClientClass<CDOTA_Ability_Oracle_FortunesEnd>::InstancePtr },
   { "DT_DOTA_Ability_PhantomAssassin_PhantomStrike", ClientClass<CDOTA_Ability_PhantomAssassin_PhantomStrike>::InstancePtr },
   { "DT_DOTA_Ability_PhantomLancer_Doppelwalk", ClientClass<CDOTA_Ability_PhantomLancer_Doppelwalk>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Phoenix_LaunchFireSpirit", ClientClass<CDOTA_Ability_Phoenix_LaunchFireSpirit>::InstancePtr },
   { "DT_DOTA_Ability_Phoenix_Supernova", ClientClass<CDOTA_Ability_Phoenix_Supernova>::InstancePtr },
   { "DT_DOTA_Ability_Puck_DreamCoil", ClientClass<CDOTA_Ability_Puck_DreamCoil>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Puck_IllusoryOrb", ClientClass<CDOTA_Ability_Puck_IllusoryOrb>::InstancePtr },
   { "DT_DOTA_Ability_Puck_WaningRift", ClientClass<CDOTA_Ability_Puck_WaningRift>::InstancePtr },
   { "DT_DOTA_Ability_Pudge_Dismember", ClientClass<CDOTA_Ability_Pudge_Dismember>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Pudge_MeatHook", ClientClass<CDOTA_Ability_Pudge_MeatHook>::InstancePtr },
   { "DT_DOTA_Ability_Pugna_Decrepify", ClientClass<CDOTA_Ability_Pugna_Decrepify>::InstancePtr },
   { "DT_DOTA_Ability_Pugna_LifeDrain", ClientClass<CDOTA_Ability_Pugna_LifeDrain>::InstancePtr },
   { "DT_DOTA_Ability_Pugna_NetherBlast", ClientClass<CDOTA_Ability_Pugna_NetherBlast>::InstancePtr },
   { "DT_DOTA_Ability_QueenOfPain_Blink", ClientClass<CDOTA_Ability_QueenOfPain_Blink>::InstancePtr },
   { "DT_DOTA_Unit_Ability_QueenOfPain_SonicWave", ClientClass<CDOTA_Ability_QueenOfPain_SonicWave>::InstancePtr },
   { "DT_DOTA_Ability_Rattletrap_BatteryAssault", ClientClass<CDOTA_Ability_Rattletrap_BatteryAssault>::InstancePtr },
   { "DT_DOTA_Ability_Rattletrap_Hookshot", ClientClass<CDOTA_Ability_Rattletrap_Hookshot>::InstancePtr },
   { "DT_DOTA_Ability_Rattletrap_RocketFlare", ClientClass<CDOTA_Ability_Rattletrap_RocketFlare>::InstancePtr },
   { "DT_DOTA_Ability_Razor_PlasmaField", ClientClass<CDOTA_Ability_Razor_PlasmaField>::InstancePtr },
   { "DT_DOTA_Ability_Riki_BlinkStrike", ClientClass<CDOTA_Ability_Riki_BlinkStrike>::InstancePtr },
   { "DT_DOTA_Ability_Riki_SmokeScreen", ClientClass<CDOTA_Ability_Riki_SmokeScreen>::InstancePtr },
   { "DT_DOTA_Ability_Roshan_Halloween_Apocalypse", ClientClass<CDOTA_Ability_Roshan_Halloween_Apocalypse>::InstancePtr },
   { "DT_DOTA_Ability_Roshan_Halloween_Burn", ClientClass<CDOTA_Ability_Roshan_Halloween_Burn>::InstancePtr },
   { "DT_DOTA_Ability_Roshan_Halloween_Fireball", ClientClass<CDOTA_Ability_Roshan_Halloween_Fireball>::InstancePtr },
   { "DT_DOTA_Ability_Roshan_Toss", ClientClass<CDOTA_Ability_Roshan_Toss>::InstancePtr },
   { "DT_DOTA_Ability_Roshan_WaveOfForce", ClientClass<CDOTA_Ability_Roshan_WaveOfForce>::InstancePtr },
   { "DT_DOTA_Ability_Rubick_SpellSteal", ClientClass<CDOTA_Ability_Rubick_SpellSteal>::InstancePtr },
   { "DT_DOTA_Ability_Rubick_TelekinesisLand", ClientClass<CDOTA_Ability_Rubick_TelekinesisLand>::InstancePtr },
   { "DT_DOTA_Unit_Ability_SandKing_BurrowStrike", ClientClass<CDOTA_Ability_SandKing_BurrowStrike>::InstancePtr },
   { "DT_DOTA_Ability_SandKing_Epicenter", ClientClass<CDOTA_Ability_SandKing_Epicenter>::InstancePtr },
   { "DT_DOTA_Ability_SatyrTrickster_Purge", ClientClass<CDOTA_Ability_SatyrTrickster_Purge>::InstancePtr },
   { "DT_DOTA_Ability_Shadow_Demon_Disruption", ClientClass<CDOTA_Ability_Shadow_Demon_Disruption>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Shadow_Demon_Shadow_Poison", ClientClass<CDOTA_Ability_Shadow_Demon_Shadow_Poison>::InstancePtr },
   { "DT_DOTA_Ability_Shadow_Demon_Soul_Catcher", ClientClass<CDOTA_Ability_Shadow_Demon_Soul_Catcher>::InstancePtr },
   { "DT_DOTA_Ability_Shredder_Chakram", ClientClass<CDOTA_Ability_Shredder_Chakram>::InstancePtr },
   { "DT_DOTA_Ability_Shredder_TimberChain", ClientClass<CDOTA_Ability_Shredder_TimberChain>::InstancePtr },
   { "DT_DOTA_Ability_Silencer_CurseOfTheSilent", ClientClass<CDOTA_Ability_Silencer_CurseOfTheSilent>::InstancePtr },
   { "DT_DOTA_Ability_Silencer_GlaivesOfWisdom", ClientClass<CDOTA_Ability_Silencer_GlaivesOfWisdom>::InstancePtr },
   { "DT_DOTA_Ability_Skywrath_Mage_Mystic_Flare", ClientClass<CDOTA_Ability_Skywrath_Mage_Mystic_Flare>::InstancePtr },
   { "DT_DOTA_Ability_Slardar_Slithereen_Crush", ClientClass<CDOTA_Ability_Slardar_Slithereen_Crush>::InstancePtr },
   { "DT_DOTA_Ability_Slark_EssenceShift", ClientClass<CDOTA_Ability_Slark_EssenceShift>::InstancePtr },
   { "DT_DOTA_Ability_Sniper_Shrapnel", ClientClass<CDOTA_Ability_Sniper_Shrapnel>::InstancePtr },
   { "DT_DOTA_Ability_SpiritBreaker_NetherStrike", ClientClass<CDOTA_Ability_SpiritBreaker_NetherStrike>::InstancePtr },
   { "DT_DOTA_Ability_StormSpirit_BallLightning", ClientClass<CDOTA_Ability_StormSpirit_BallLightning>::InstancePtr },
   { "DT_DOTA_Ability_Sven_StormBolt", ClientClass<CDOTA_Ability_Sven_StormBolt>::InstancePtr },
   { "DT_DOTA_Ability_Techies_FocusedDetonate", ClientClass<CDOTA_Ability_Techies_FocusedDetonate>::InstancePtr },
   { "DT_DOTA_Ability_Techies_LandMines", ClientClass<CDOTA_Ability_Techies_LandMines>::InstancePtr },
   { "DT_DOTA_Ability_Techies_Minefield_Sign", ClientClass<CDOTA_Ability_Techies_Minefield_Sign>::InstancePtr },
   { "DT_DOTA_Ability_Techies_RemoteMines", ClientClass<CDOTA_Ability_Techies_RemoteMines>::InstancePtr },
   { "DT_DOTA_Ability_Techies_RemoteMines_SelfDetonate", ClientClass<CDOTA_Ability_Techies_RemoteMines_SelfDetonate>::InstancePtr },
   { "DT_DOTA_Ability_Techies_StasisTrap", ClientClass<CDOTA_Ability_Techies_StasisTrap>::InstancePtr },
   { "DT_DOTA_Ability_Terrorblade_Sunder", ClientClass<CDOTA_Ability_Terrorblade_Sunder>::InstancePtr },
   { "DT_DOTA_Ability_Throw_Coal", ClientClass<CDOTA_Ability_Throw_Coal>::InstancePtr },
   { "DT_DOTA_Ability_Throw_Snowball", ClientClass<CDOTA_Ability_Throw_Snowball>::InstancePtr },
   { "DT_DOTA_Ability_Tidehunter_AnchorSmash", ClientClass<CDOTA_Ability_Tidehunter_AnchorSmash>::InstancePtr },
   { "DT_DOTA_Ability_Tidehunter_Ravage", ClientClass<CDOTA_Ability_Tidehunter_Ravage>::InstancePtr },
   { "DT_DOTA_Ability_Tiny_Avalanche", ClientClass<CDOTA_Ability_Tiny_Avalanche>::InstancePtr },
   { "DT_DOTA_Ability_Tiny_CraggyExterior", ClientClass<CDOTA_Ability_Tiny_CraggyExterior>::InstancePtr },
   { "DT_DOTA_Ability_Tiny_Toss", ClientClass<CDOTA_Ability_Tiny_Toss>::InstancePtr },
   { "DT_DOTA_Ability_Treant_EyesInTheForest", ClientClass<CDOTA_Ability_Treant_EyesInTheForest>::InstancePtr },
   { "DT_DOTA_Ability_Treant_Overgrowth", ClientClass<CDOTA_Ability_Treant_Overgrowth>::InstancePtr },
   { "DT_DOTA_Ability_TrollWarlord_BerserkersRage", ClientClass<CDOTA_Ability_TrollWarlord_BerserkersRage>::InstancePtr },
   { "DT_DOTA_Unit_Ability_TrollWarlord_WhirlingAxes_Ranged", ClientClass<CDOTA_Ability_TrollWarlord_WhirlingAxes_Ranged>::InstancePtr },
   { "DT_DOTA_Ability_Tusk_FrozenSigil", ClientClass<CDOTA_Ability_Tusk_FrozenSigil>::InstancePtr },
   { "DT_DOTA_Ability_Undying_Decay", ClientClass<CDOTA_Ability_Undying_Decay>::InstancePtr },
   { "DT_DOTA_Ability_Undying_SoulRip", ClientClass<CDOTA_Ability_Undying_SoulRip>::InstancePtr },
   { "DT_DOTA_Ability_VengefulSpirit_Nether_Swap", ClientClass<CDOTA_Ability_VengefulSpirit_Nether_Swap>::InstancePtr },
   { "DT_DOTA_Unit_Ability_VengefulSpirit_WaveOfTerror", ClientClass<CDOTA_Ability_VengefulSpirit_WaveOfTerror>::InstancePtr },
   { "DT_DOTA_Ability_Venomancer_PoisonNova", ClientClass<CDOTA_Ability_Venomancer_PoisonNova>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Venomancer_VenomousGale", ClientClass<CDOTA_Ability_Venomancer_VenomousGale>::InstancePtr },
   { "DT_DOTA_Ability_Viper_ViperStrike", ClientClass<CDOTA_Ability_Viper_ViperStrike>::InstancePtr },
   { "DT_DOTA_Ability_Visage_SummonFamiliars", ClientClass<CDOTA_Ability_Visage_SummonFamiliars>::InstancePtr },
   { "DT_DOTA_Ability_Visage_SummonFamiliars_StoneForm", ClientClass<CDOTA_Ability_Visage_SummonFamiliars_StoneForm>::InstancePtr },
   { "DT_DOTA_Ability_Warlock_RainOfChaos", ClientClass<CDOTA_Ability_Warlock_RainOfChaos>::InstancePtr },
   { "DT_DOTA_Ability_Warlock_Shadow_Word", ClientClass<CDOTA_Ability_Warlock_Shadow_Word>::InstancePtr },
   { "DT_DOTA_Ability_Warlock_Upheaval", ClientClass<CDOTA_Ability_Warlock_Upheaval>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Weaver_TheSwarm", ClientClass<CDOTA_Ability_Weaver_TheSwarm>::InstancePtr },
   { "DT_DOTA_Ability_Windrunner_FocusFire", ClientClass<CDOTA_Ability_Windrunner_FocusFire>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Windrunner_Powershot", ClientClass<CDOTA_Ability_Windrunner_Powershot>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Winter_Wyvern_Arctic_Burn", ClientClass<CDOTA_Ability_Winter_Wyvern_Arctic_Burn>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Winter_Wyvern_Cold_Embrace", ClientClass<CDOTA_Ability_Winter_Wyvern_Cold_Embrace>::InstancePtr },
   { "DT_DOTA_Unit_Ability_Winter_Wyvern_Winters_Curse", ClientClass<CDOTA_Ability_Winter_Wyvern_Winters_Curse>::InstancePtr },
   { "DT_DOTA_Ability_Wisp_Overcharge", ClientClass<CDOTA_Ability_Wisp_Overcharge>::InstancePtr },
   { "DT_DOTA_Ability_Wisp_Relocate", ClientClass<CDOTA_Ability_Wisp_Relocate>::InstancePtr },
   { "DT_DOTA_Ability_Wisp_Spirits", ClientClass<CDOTA_Ability_Wisp_Spirits>::InstancePtr },
   { "DT_DOTA_Ability_Wisp_Tether", ClientClass<CDOTA_Ability_Wisp_Tether>::InstancePtr },
   { "DT_DOTA_Ability_WitchDoctor_Maledict", ClientClass<CDOTA_Ability_WitchDoctor_Maledict>::InstancePtr },
   { "DT_DOTA_Ability_WitchDoctor_ParalyzingCask", ClientClass<CDOTA_Ability_WitchDoctor_ParalyzingCask>::InstancePtr },
   { "DT_DOTA_Ability_WitchDoctor_VoodooRestoration", ClientClass<CDOTA_Ability_WitchDoctor_VoodooRestoration>::InstancePtr },
   { "DT_DOTA_BaseNPC", ClientClass<CDOTA_BaseNPC>::InstancePtr },
   { "DT_DOTA_BaseNPC_Additive", ClientClass<CDOTA_BaseNPC_Additive>::InstancePtr },
   { "DT_DOTA_BaseNPC_Barracks", ClientClass<CDOTA_BaseNPC_Barracks>::InstancePtr },
   { "DT_DOTA_BaseNPC_Building", ClientClass<CDOTA_BaseNPC_Building>::InstancePtr },
   { "DT_DOTA_BaseNPC_Creature", ClientClass<CDOTA_BaseNPC_Creature>::InstancePtr },
   { "DT_DOTA_BaseNPC_Creep", ClientClass<CDOTA_BaseNPC_Creep>::InstancePtr },
   { "DT_DOTA_BaseNPC_Creep_Diretide", ClientClass<CDOTA_BaseNPC_Creep_Diretide>::InstancePtr },
   { "DT_DOTA_BaseNPC_Creep_Lane", ClientClass<CDOTA_BaseNPC_Creep_Lane>::InstancePtr },
   { "DT_DOTA_BaseNPC_Creep_LootGreevil", ClientClass<CDOTA_BaseNPC_Creep_LootGreevil>::InstancePtr },
   { "DT_DOTA_BaseNPC_Creep_Neutral", ClientClass<CDOTA_BaseNPC_Creep_Neutral>::InstancePtr },
   { "DT_DOTA_BaseNPC_Creep_Siege", ClientClass<CDOTA_BaseNPC_Creep_Siege>::InstancePtr },
   { "DT_DOTA_BaseNPC_Creep_Talking", ClientClass<CDOTA_BaseNPC_Creep_Talking>::InstancePtr },
   { "DT_DOTA_BaseNPC_Fort", ClientClass<CDOTA_BaseNPC_Fort>::InstancePtr },
   { "DT_DOTA_BaseNPC_HallofFame", ClientClass<CDOTA_BaseNPC_HallofFame>::InstancePtr },
   { "DT_DOTA_BaseNPC_Hero", ClientClass<CDOTA_BaseNPC_Hero>::InstancePtr },
   { "DT_DOTA_BaseNPC_HoldoutTower", ClientClass<CDOTA_BaseNPC_HoldoutTower>::InstancePtr },
   { "DT_DOTA_BaseNPC_HoldoutTower_HeavySlow", ClientClass<CDOTA_BaseNPC_HoldoutTower_HeavySlow>::InstancePtr },
   { "DT_DOTA_BaseNPC_HoldoutTower_LightFast", ClientClass<CDOTA_BaseNPC_HoldoutTower_LightFast>::InstancePtr },
   { "DT_DOTA_BaseNPC_HoldoutTower_ReduceSpeed", ClientClass<CDOTA_BaseNPC_HoldoutTower_ReduceSpeed>::InstancePtr },
   { "DT_DOTA_BaseNPC_Invoker_Forged_Spirit", ClientClass<CDOTA_BaseNPC_Invoker_Forged_Spirit>::InstancePtr },
   { "DT_DOTA_BaseNPC_ShadowShaman_SerpentWard", ClientClass<CDOTA_BaseNPC_ShadowShaman_SerpentWard>::InstancePtr },
   { "DT_DOTA_BaseNPC_Shop", ClientClass<CDOTA_BaseNPC_Shop>::InstancePtr },
   { "DT_DOTA_BaseNPC_Tower", ClientClass<CDOTA_BaseNPC_Tower>::InstancePtr },
   { "DT_DOTA_BaseNPC_Tusk_Sigil", ClientClass<CDOTA_BaseNPC_Tusk_Sigil>::InstancePtr },
   { "DT_DOTA_BaseNPC_Venomancer_PlagueWard", ClientClass<CDOTA_BaseNPC_Venomancer_PlagueWard>::InstancePtr },
   { "DT_DOTA_BaseNPC_Warlock_Golem", ClientClass<CDOTA_BaseNPC_Warlock_Golem>::InstancePtr },
   { "DT_DOTA_Beastmaster_Axe", ClientClass<CDOTA_Beastmaster_Axe>::InstancePtr },
   { "DT_DOTA_DataDire", ClientClass<CDOTA_DataDire>::InstancePtr },
   { "DT_DOTA_DataNonSpectator", ClientClass<CDOTA_DataNonSpectator>::InstancePtr },
   { "DT_DOTA_DataRadiant", ClientClass<CDOTA_DataRadiant>::InstancePtr },
   { "DT_DOTA_DataSpectator", ClientClass<CDOTA_DataSpectator>::InstancePtr },
   { "DT_DOTA_DeathProphet_Exorcism_Spirit", ClientClass<CDOTA_DeathProphet_Exorcism_Spirit>::InstancePtr },
   { "DT_DOTA_DisplacementVisibility", ClientClass<CDOTA_DisplacementVisibility>::InstancePtr },
   { "DT_DOTA_Halloween_CandyBucket", ClientClass<CDOTA_Halloween_CandyBucket>::InstancePtr },
   { "DT_DOTA_Halloween_CandyBucketDire", ClientClass<CDOTA_Halloween_CandyBucketDire>::InstancePtr },
   { "DT_DOTA_Halloween_CandyBucketRadiant", ClientClass<CDOTA_Halloween_CandyBucketRadiant>::InstancePtr },
   { "DT_DOTA_Hero_Recorder", ClientClass<CDOTA_Hero_Recorder>::InstancePtr },
   { "DT_DOTA_Item", ClientClass<CDOTA_Item>::InstancePtr },
   { "DT_DOTA_Item_Ancient_Janggo", ClientClass<CDOTA_Item_Ancient_Janggo>::InstancePtr },
   { "DT_DOTA_Item_Armlet", ClientClass<CDOTA_Item_Armlet>::InstancePtr },
   { "DT_DOTA_Item_Battlefury", ClientClass<CDOTA_Item_Battlefury>::InstancePtr },
   { "DT_DOTA_Item_BlinkDagger", ClientClass<CDOTA_Item_BlinkDagger>::InstancePtr },
   { "DT_DOTA_Item_Bloodstone", ClientClass<CDOTA_Item_Bloodstone>::InstancePtr },
   { "DT_DOTA_Item_BootsOfTravel", ClientClass<CDOTA_Item_BootsOfTravel>::InstancePtr },
   { "DT_DOTA_Item_Cyclone", ClientClass<CDOTA_Item_Cyclone>::InstancePtr },
   { "DT_DOTA_Item_Cyclone_2", ClientClass<CDOTA_Item_Cyclone_2>::InstancePtr },
   { "DT_DOTA_Item_DataDriven", ClientClass<CDOTA_Item_DataDriven>::InstancePtr },
   { "DT_DOTA_Item_Diffusal_Blade", ClientClass<CDOTA_Item_Diffusal_Blade>::InstancePtr },
   { "DT_DOTA_Item_Diffusal_Blade_Level2", ClientClass<CDOTA_Item_Diffusal_Blade_Level2>::InstancePtr },
   { "DT_DOTA_Item_EmptyBottle", ClientClass<CDOTA_Item_EmptyBottle>::InstancePtr },
   { "DT_DOTA_Item_Ethereal_Blade", ClientClass<CDOTA_Item_Ethereal_Blade>::InstancePtr },
   { "DT_DOTA_Item_ForceStaff", ClientClass<CDOTA_Item_ForceStaff>::InstancePtr },
   { "DT_DOTA_Item_Greevil_Blink", ClientClass<CDOTA_Item_Greevil_Blink>::InstancePtr },
   { "DT_DOTA_Item_Greevil_Whistle", ClientClass<CDOTA_Item_Greevil_Whistle>::InstancePtr },
   { "DT_DOTA_Item_Greevil_WhistleToggle", ClientClass<CDOTA_Item_Greevil_WhistleToggle>::InstancePtr },
   { "DT_DOTA_Item_MantaStyle", ClientClass<CDOTA_Item_MantaStyle>::InstancePtr },
   { "DT_DOTA_Item_Medallion_Of_Courage", ClientClass<CDOTA_Item_Medallion_Of_Courage>::InstancePtr },
   { "DT_DOTA_Item_Mystery_Toss", ClientClass<CDOTA_Item_Mystery_Toss>::InstancePtr },
   { "DT_DOTA_Item_Mystery_Vacuum", ClientClass<CDOTA_Item_Mystery_Vacuum>::InstancePtr },
   { "DT_DOTA_Item_Necronomicon", ClientClass<CDOTA_Item_Necronomicon>::InstancePtr },
   { "DT_DOTA_Item_Necronomicon_Level2", ClientClass<CDOTA_Item_Necronomicon_Level2>::InstancePtr },
   { "DT_DOTA_Item_Necronomicon_Level3", ClientClass<CDOTA_Item_Necronomicon_Level3>::InstancePtr },
   { "DT_DOTA_Item_Nian_Flag_Trap", ClientClass<CDOTA_Item_Nian_Flag_Trap>::InstancePtr },
   { "DT_DOTA_Item_ObserverWard", ClientClass<CDOTA_Item_ObserverWard>::InstancePtr },
   { "DT_DOTA_Item_Physical", ClientClass<CDOTA_Item_Physical>::InstancePtr },
   { "DT_DOTA_Item_PlaceBuilding", ClientClass<CDOTA_Item_PlaceBuilding>::InstancePtr },
   { "DT_DOTA_Item_PlaceBuilding_Free", ClientClass<CDOTA_Item_PlaceBuilding_Free>::InstancePtr },
   { "DT_DOTA_Item_PlaceBuilding_Grid", ClientClass<CDOTA_Item_PlaceBuilding_Grid>::InstancePtr },
   { "DT_DOTA_Item_PowerTreads", ClientClass<CDOTA_Item_PowerTreads>::InstancePtr },
   { "DT_DOTA_Item_QuellingBlade", ClientClass<CDOTA_Item_QuellingBlade>::InstancePtr },
   { "DT_DOTA_Item_Radiance", ClientClass<CDOTA_Item_Radiance>::InstancePtr },
   { "DT_DOTA_Item_Recipe_Veil_Of_Discord", ClientClass<CDOTA_Item_Recipe_Veil_Of_Discord>::InstancePtr },
   { "DT_DOTA_Item_Ring_Of_Basilius", ClientClass<CDOTA_Item_Ring_Of_Basilius>::InstancePtr },
   { "DT_DOTA_Item_RingOfAquila", ClientClass<CDOTA_Item_RingOfAquila>::InstancePtr },
   { "DT_DOTA_Item_Rune", ClientClass<CDOTA_Item_Rune>::InstancePtr },
   { "DT_DOTA_Item_SentryWard", ClientClass<CDOTA_Item_SentryWard>::InstancePtr },
   { "DT_DOTA_Item_Tango", ClientClass<CDOTA_Item_Tango>::InstancePtr },
   { "DT_DOTA_Item_TeleportScroll", ClientClass<CDOTA_Item_TeleportScroll>::InstancePtr },
   { "DT_DOTA_Item_TranquilBoots", ClientClass<CDOTA_Item_TranquilBoots>::InstancePtr },
   { "DT_DOTA_Item_Urn_Of_Shadows", ClientClass<CDOTA_Item_Urn_Of_Shadows>::InstancePtr },
   { "DT_DOTA_Item_Veil_Of_Discord", ClientClass<CDOTA_Item_Veil_Of_Discord>::InstancePtr },
   { "DT_DOTA_NeutralSpawner", ClientClass<CDOTA_NeutralSpawner>::InstancePtr },
   { "DT_DOTA_NPC_DataDriven", ClientClass<CDOTA_NPC_DataDriven>::InstancePtr },
   { "DT_DOTA_NPC_Observer_Ward", ClientClass<CDOTA_NPC_Observer_Ward>::InstancePtr },
   { "DT_DOTA_NPC_Observer_Ward_TrueSight", ClientClass<CDOTA_NPC_Observer_Ward_TrueSight>::InstancePtr },
   { "DT_DOTA_NPC_Techies_Minefield_Sign", ClientClass<CDOTA_NPC_Techies_Minefield_Sign>::InstancePtr },
   { "DT_DOTA_NPC_TechiesMines", ClientClass<CDOTA_NPC_TechiesMines>::InstancePtr },
   { "DT_DOTA_NPC_Treant_EyesInTheForest", ClientClass<CDOTA_NPC_Treant_EyesInTheForest>::InstancePtr },
   { "DT_DOTA_NPC_WitchDoctor_Ward", ClientClass<CDOTA_NPC_WitchDoctor_Ward>::InstancePtr },
   { "DT_DOTA_PhantomAssassin_Gravestone", ClientClass<CDOTA_PhantomAssassin_Gravestone>::InstancePtr },
   { "DT_DOTA_PlayerResource", ClientClass<CDOTA_PlayerResource>::InstancePtr },
   { "DT_DOTA_RoshanSpawner", ClientClass<CDOTA_RoshanSpawner>::InstancePtr },
   { "DT_DOTA_TempTree", ClientClass<CDOTA_TempTree>::InstancePtr },
   { "DT_DOTA_Tiny_ScepterTree", ClientClass<CDOTA_Tiny_ScepterTree>::InstancePtr },
   { "DT_DOTA_Unit_Announcer", ClientClass<CDOTA_Unit_Announcer>::InstancePtr },
   { "DT_DOTA_Unit_Announcer_Killing_Spree", ClientClass<CDOTA_Unit_Announcer_Killing_Spree>::InstancePtr },
   { "DT_DOTA_Unit_Brewmaster_PrimalEarth", ClientClass<CDOTA_Unit_Brewmaster_PrimalEarth>::InstancePtr },
   { "DT_DOTA_Unit_Brewmaster_PrimalFire", ClientClass<CDOTA_Unit_Brewmaster_PrimalFire>::InstancePtr },
   { "DT_DOTA_Unit_Brewmaster_PrimalStorm", ClientClass<CDOTA_Unit_Brewmaster_PrimalStorm>::InstancePtr },
   { "DT_DOTA_Unit_Broodmother_Spiderling", ClientClass<CDOTA_Unit_Broodmother_Spiderling>::InstancePtr },
   { "DT_DOTA_Unit_Broodmother_Web", ClientClass<CDOTA_Unit_Broodmother_Web>::InstancePtr },
   { "DT_DOTA_Unit_Courier", ClientClass<CDOTA_Unit_Courier>::InstancePtr },
   { "DT_DOTA_Unit_Earth_Spirit_Stone", ClientClass<CDOTA_Unit_Earth_Spirit_Stone>::InstancePtr },
   { "DT_DOTA_Unit_Elder_Titan_AncestralSpirit", ClientClass<CDOTA_Unit_Elder_Titan_AncestralSpirit>::InstancePtr },
   { "DT_DOTA_Unit_Fountain", ClientClass<CDOTA_Unit_Fountain>::InstancePtr },
   { "DT_DOTA_Unit_Greevil", ClientClass<CDOTA_Unit_Greevil>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Abaddon", ClientClass<CDOTA_Unit_Hero_Abaddon>::InstancePtr },
   { "DT_DOTA_Unit_Hero_AbyssalUnderlord", ClientClass<CDOTA_Unit_Hero_AbyssalUnderlord>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Alchemist", ClientClass<CDOTA_Unit_Hero_Alchemist>::InstancePtr },
   { "DT_DOTA_Unit_Hero_AncientApparition", ClientClass<CDOTA_Unit_Hero_AncientApparition>::InstancePtr },
   { "DT_DOTA_Unit_Hero_AntiMage", ClientClass<CDOTA_Unit_Hero_AntiMage>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Axe", ClientClass<CDOTA_Unit_Hero_Axe>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Bane", ClientClass<CDOTA_Unit_Hero_Bane>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Batrider", ClientClass<CDOTA_Unit_Hero_Batrider>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Beastmaster", ClientClass<CDOTA_Unit_Hero_Beastmaster>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Beastmaster_Beasts", ClientClass<CDOTA_Unit_Hero_Beastmaster_Beasts>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Beastmaster_Boar", ClientClass<CDOTA_Unit_Hero_Beastmaster_Boar>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Beastmaster_Hawk", ClientClass<CDOTA_Unit_Hero_Beastmaster_Hawk>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Bloodseeker", ClientClass<CDOTA_Unit_Hero_Bloodseeker>::InstancePtr },
   { "DT_DOTA_Unit_Hero_BountyHunter", ClientClass<CDOTA_Unit_Hero_BountyHunter>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Brewmaster", ClientClass<CDOTA_Unit_Hero_Brewmaster>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Bristleback", ClientClass<CDOTA_Unit_Hero_Bristleback>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Broodmother", ClientClass<CDOTA_Unit_Hero_Broodmother>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Centaur", ClientClass<CDOTA_Unit_Hero_Centaur>::InstancePtr },
   { "DT_DOTA_Unit_Hero_ChaosKnight", ClientClass<CDOTA_Unit_Hero_ChaosKnight>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Chen", ClientClass<CDOTA_Unit_Hero_Chen>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Clinkz", ClientClass<CDOTA_Unit_Hero_Clinkz>::InstancePtr },
   { "DT_DOTA_Unit_Hero_CrystalMaiden", ClientClass<CDOTA_Unit_Hero_CrystalMaiden>::InstancePtr },
   { "DT_DOTA_Unit_Hero_DarkSeer", ClientClass<CDOTA_Unit_Hero_DarkSeer>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Dazzle", ClientClass<CDOTA_Unit_Hero_Dazzle>::InstancePtr },
   { "DT_DOTA_Unit_Hero_DeathProphet", ClientClass<CDOTA_Unit_Hero_DeathProphet>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Disruptor", ClientClass<CDOTA_Unit_Hero_Disruptor>::InstancePtr },
   { "DT_DOTA_Unit_Hero_DoomBringer", ClientClass<CDOTA_Unit_Hero_DoomBringer>::InstancePtr },
   { "DT_DOTA_Unit_Hero_DragonKnight", ClientClass<CDOTA_Unit_Hero_DragonKnight>::InstancePtr },
   { "DT_DOTA_Unit_Hero_DrowRanger", ClientClass<CDOTA_Unit_Hero_DrowRanger>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Earthshaker", ClientClass<CDOTA_Unit_Hero_Earthshaker>::InstancePtr },
   { "DT_DOTA_Unit_Hero_EarthSpirit", ClientClass<CDOTA_Unit_Hero_EarthSpirit>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Elder_Titan", ClientClass<CDOTA_Unit_Hero_Elder_Titan>::InstancePtr },
   { "DT_DOTA_Unit_Hero_EmberSpirit", ClientClass<CDOTA_Unit_Hero_EmberSpirit>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Enchantress", ClientClass<CDOTA_Unit_Hero_Enchantress>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Enigma", ClientClass<CDOTA_Unit_Hero_Enigma>::InstancePtr },
   { "DT_DOTA_Unit_Hero_FacelessVoid", ClientClass<CDOTA_Unit_Hero_FacelessVoid>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Furion", ClientClass<CDOTA_Unit_Hero_Furion>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Gyrocopter", ClientClass<CDOTA_Unit_Hero_Gyrocopter>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Huskar", ClientClass<CDOTA_Unit_Hero_Huskar>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Invoker", ClientClass<CDOTA_Unit_Hero_Invoker>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Jakiro", ClientClass<CDOTA_Unit_Hero_Jakiro>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Juggernaut", ClientClass<CDOTA_Unit_Hero_Juggernaut>::InstancePtr },
   { "DT_DOTA_Unit_Hero_KeeperOfTheLight", ClientClass<CDOTA_Unit_Hero_KeeperOfTheLight>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Kunkka", ClientClass<CDOTA_Unit_Hero_Kunkka>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Legion_Commander", ClientClass<CDOTA_Unit_Hero_Legion_Commander>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Leshrac", ClientClass<CDOTA_Unit_Hero_Leshrac>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Lich", ClientClass<CDOTA_Unit_Hero_Lich>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Life_Stealer", ClientClass<CDOTA_Unit_Hero_Life_Stealer>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Lina", ClientClass<CDOTA_Unit_Hero_Lina>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Lion", ClientClass<CDOTA_Unit_Hero_Lion>::InstancePtr },
   { "DT_DOTA_Unit_Hero_LoneDruid", ClientClass<CDOTA_Unit_Hero_LoneDruid>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Luna", ClientClass<CDOTA_Unit_Hero_Luna>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Lycan", ClientClass<CDOTA_Unit_Hero_Lycan>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Magnataur", ClientClass<CDOTA_Unit_Hero_Magnataur>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Medusa", ClientClass<CDOTA_Unit_Hero_Medusa>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Meepo", ClientClass<CDOTA_Unit_Hero_Meepo>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Mirana", ClientClass<CDOTA_Unit_Hero_Mirana>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Morphling", ClientClass<CDOTA_Unit_Hero_Morphling>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Naga_Siren", ClientClass<CDOTA_Unit_Hero_Naga_Siren>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Necrolyte", ClientClass<CDOTA_Unit_Hero_Necrolyte>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Nevermore", ClientClass<CDOTA_Unit_Hero_Nevermore>::InstancePtr },
   { "DT_DOTA_Unit_Hero_NightStalker", ClientClass<CDOTA_Unit_Hero_NightStalker>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Nyx_Assassin", ClientClass<CDOTA_Unit_Hero_Nyx_Assassin>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Obsidian_Destroyer", ClientClass<CDOTA_Unit_Hero_Obsidian_Destroyer>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Ogre_Magi", ClientClass<CDOTA_Unit_Hero_Ogre_Magi>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Omniknight", ClientClass<CDOTA_Unit_Hero_Omniknight>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Oracle", ClientClass<CDOTA_Unit_Hero_Oracle>::InstancePtr },
   { "DT_DOTA_Unit_Hero_PhantomAssassin", ClientClass<CDOTA_Unit_Hero_PhantomAssassin>::InstancePtr },
   { "DT_DOTA_Unit_Hero_PhantomLancer", ClientClass<CDOTA_Unit_Hero_PhantomLancer>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Phoenix", ClientClass<CDOTA_Unit_Hero_Phoenix>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Puck", ClientClass<CDOTA_Unit_Hero_Puck>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Pudge", ClientClass<CDOTA_Unit_Hero_Pudge>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Pugna", ClientClass<CDOTA_Unit_Hero_Pugna>::InstancePtr },
   { "DT_DOTA_Unit_Hero_QueenOfPain", ClientClass<CDOTA_Unit_Hero_QueenOfPain>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Rattletrap", ClientClass<CDOTA_Unit_Hero_Rattletrap>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Razor", ClientClass<CDOTA_Unit_Hero_Razor>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Riki", ClientClass<CDOTA_Unit_Hero_Riki>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Rubick", ClientClass<CDOTA_Unit_Hero_Rubick>::InstancePtr },
   { "DT_DOTA_Unit_Hero_SandKing", ClientClass<CDOTA_Unit_Hero_SandKing>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Shadow_Demon", ClientClass<CDOTA_Unit_Hero_Shadow_Demon>::InstancePtr },
   { "DT_DOTA_Unit_Hero_ShadowShaman", ClientClass<CDOTA_Unit_Hero_ShadowShaman>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Shredder", ClientClass<CDOTA_Unit_Hero_Shredder>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Silencer", ClientClass<CDOTA_Unit_Hero_Silencer>::InstancePtr },
   { "DT_DOTA_Unit_Hero_SkeletonKing", ClientClass<CDOTA_Unit_Hero_SkeletonKing>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Skywrath_Mage", ClientClass<CDOTA_Unit_Hero_Skywrath_Mage>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Slardar", ClientClass<CDOTA_Unit_Hero_Slardar>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Slark", ClientClass<CDOTA_Unit_Hero_Slark>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Sniper", ClientClass<CDOTA_Unit_Hero_Sniper>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Spectre", ClientClass<CDOTA_Unit_Hero_Spectre>::InstancePtr },
   { "DT_DOTA_Unit_Hero_SpiritBreaker", ClientClass<CDOTA_Unit_Hero_SpiritBreaker>::InstancePtr },
   { "DT_DOTA_Unit_Hero_StormSpirit", ClientClass<CDOTA_Unit_Hero_StormSpirit>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Sven", ClientClass<CDOTA_Unit_Hero_Sven>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Techies", ClientClass<CDOTA_Unit_Hero_Techies>::InstancePtr },
   { "DT_DOTA_Unit_Hero_TemplarAssassin", ClientClass<CDOTA_Unit_Hero_TemplarAssassin>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Terrorblade", ClientClass<CDOTA_Unit_Hero_Terrorblade>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Tidehunter", ClientClass<CDOTA_Unit_Hero_Tidehunter>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Tinker", ClientClass<CDOTA_Unit_Hero_Tinker>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Tiny", ClientClass<CDOTA_Unit_Hero_Tiny>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Treant", ClientClass<CDOTA_Unit_Hero_Treant>::InstancePtr },
   { "DT_DOTA_Unit_Hero_TrollWarlord", ClientClass<CDOTA_Unit_Hero_TrollWarlord>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Tusk", ClientClass<CDOTA_Unit_Hero_Tusk>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Undying", ClientClass<CDOTA_Unit_Hero_Undying>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Ursa", ClientClass<CDOTA_Unit_Hero_Ursa>::InstancePtr },
   { "DT_DOTA_Unit_Hero_VengefulSpirit", ClientClass<CDOTA_Unit_Hero_VengefulSpirit>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Venomancer", ClientClass<CDOTA_Unit_Hero_Venomancer>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Viper", ClientClass<CDOTA_Unit_Hero_Viper>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Visage", ClientClass<CDOTA_Unit_Hero_Visage>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Warlock", ClientClass<CDOTA_Unit_Hero_Warlock>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Weaver", ClientClass<CDOTA_Unit_Hero_Weaver>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Windrunner", ClientClass<CDOTA_Unit_Hero_Windrunner>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Winter_Wyvern", ClientClass<CDOTA_Unit_Hero_Winter_Wyvern>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Wisp", ClientClass<CDOTA_Unit_Hero_Wisp>::InstancePtr },
   { "DT_DOTA_Unit_Hero_WitchDoctor", ClientClass<CDOTA_Unit_Hero_WitchDoctor>::InstancePtr },
   { "DT_DOTA_Unit_Hero_Zuus", ClientClass<CDOTA_Unit_Hero_Zuus>::InstancePtr },
   { "DT_DOTA_Unit_LoopingSound", ClientClass<CDOTA_Unit_LoopingSound>::InstancePtr },
   { "DT_DOTA_Unit_Nian", ClientClass<CDOTA_Unit_Nian>::InstancePtr },
   { "DT_DOTA_Unit_Roquelaire", ClientClass<CDOTA_Unit_Roquelaire>::InstancePtr },
   { "DT_DOTA_Unit_Roshan", ClientClass<CDOTA_Unit_Roshan>::InstancePtr },
   { "DT_DOTA_Unit_Roshan_Halloween", ClientClass<CDOTA_Unit_Roshan_Halloween>::InstancePtr },
   { "DT_DOTA_Unit_SpiritBear", ClientClass<CDOTA_Unit_SpiritBear>::InstancePtr },
   { "DT_DOTA_Unit_TargetDummy", ClientClass<CDOTA_Unit_TargetDummy>::InstancePtr },
   { "DT_DOTA_Unit_Undying_Tombstone", ClientClass<CDOTA_Unit_Undying_Tombstone>::InstancePtr },
   { "DT_DOTA_Unit_Undying_Zombie", ClientClass<CDOTA_Unit_Undying_Zombie>::InstancePtr },
   { "DT_DOTA_Unit_VisageFamiliar", ClientClass<CDOTA_Unit_VisageFamiliar>::InstancePtr },
   { "DT_DOTA_Wisp_Spirit", ClientClass<CDOTA_Wisp_Spirit>::InstancePtr },
   { "DT_DOTABaseAbility", ClientClass<CDOTABaseAbility>::InstancePtr },
   { "DT_DOTABaseGameMode", ClientClass<CDOTABaseGameMode>::InstancePtr },
   { "DT_DOTACameraBounds", ClientClass<CDOTACameraBounds>::InstancePtr },
   { "DT_DOTAFogOfWarTempViewers", ClientClass<CDOTAFogOfWarTempViewers>::InstancePtr },
   { "DT_DOTAFogOfWarWasVisible", ClientClass<CDOTAFogOfWarWasVisible>::InstancePtr },
   { "DT_DOTAGameManagerProxy", ClientClass<CDOTAGameManagerProxy>::InstancePtr },
   { "DT_DOTAGamerulesProxy", ClientClass<CDOTAGamerulesProxy>::InstancePtr },
   { "DT_DOTA_HoldoutNetworker", ClientClass<CDOTAHoldoutNetworker>::InstancePtr },
   { "DT_DOTAMinimapBoundary", ClientClass<CDOTAMinimapBoundary>::InstancePtr },
   { "DT_DOTAPlayer", ClientClass<CDOTAPlayer>::InstancePtr },
   { "DT_DOTAPropCustomTexture", ClientClass<CDOTAPropCustomTexture>::InstancePtr },
   { "DT_DotaQuest", ClientClass<CDotaQuest>::InstancePtr },
   { "DT_DotaQuestBase", ClientClass<CDotaQuestBase>::InstancePtr },
   { "DT_DotaSpecGraphPlayerData", ClientClass<CDOTASpecGraphPlayerData>::InstancePtr },
   { "DT_DOTASpectatorGraphManagerProxy", ClientClass<CDOTASpectatorGraphManagerProxy>::InstancePtr },
   { "DT_DotaSubquestBase", ClientClass<CDotaSubquestBase>::InstancePtr },
   { "DT_DOTATeam", ClientClass<CDOTATeam>::InstancePtr },
   { "DT_DotaTutorialNetworker", ClientClass<CDotaTutorialNetworker>::InstancePtr },
   { "DT_DOTAWearableItem", ClientClass<CDOTAWearableItem>::InstancePtr },
   { "DT_DynamicLight", ClientClass<CDynamicLight>::InstancePtr },
   { "DT_DynamicProp", ClientClass<CDynamicProp>::InstancePtr },
   { "DT_EconEntity", ClientClass<CEconEntity>::InstancePtr },
   { "DT_WearableItem", ClientClass<CEconWearable>::InstancePtr },
   { "DT_EntityDissolve", ClientClass<CEntityDissolve>::InstancePtr },
   { "DT_EntityFlame", ClientClass<CEntityFlame>::InstancePtr },
   { "DT_EntityFreezing", ClientClass<CEntityFreezing>::InstancePtr },
   { "DT_EntityParticleTrail", ClientClass<CEntityParticleTrail>::InstancePtr },
   { "DT_EnvAmbientLight", ClientClass<CEnvAmbientLight>::InstancePtr },
   { "DT_EnvDeferredLight", ClientClass<CEnvDeferredLight>::InstancePtr },
   { "DT_DetailController", ClientClass<CEnvDetailController>::InstancePtr },
   { "DT_EnvDOFController", ClientClass<CEnvDOFController>::InstancePtr },
   { "DT_EnvParticleScript", ClientClass<CEnvParticleScript>::InstancePtr },
   { "DT_EnvProjectedTexture", ClientClass<CEnvProjectedTexture>::InstancePtr },
   { "DT_QuadraticBeam", ClientClass<CEnvQuadraticBeam>::InstancePtr },
   { "DT_EnvScreenEffect", ClientClass<CEnvScreenEffect>::InstancePtr },
   { "DT_EnvScreenOverlay", ClientClass<CEnvScreenOverlay>::InstancePtr },
   { "DT_EnvTonemapController", ClientClass<CEnvTonemapController>::InstancePtr },
   { "DT_EnvWind", ClientClass<CEnvWind>::InstancePtr },
   { "DT_FireSmoke", ClientClass<CFireSmoke>::InstancePtr },
   { "DT_FireTrail", ClientClass<CFireTrail>::InstancePtr },
   { "DT_CFish", ClientClass<CFish>::InstancePtr },
   { "DT_FogController", ClientClass<CFogController>::InstancePtr },
   { "DT_Func_Dust", ClientClass<CFunc_Dust>::InstancePtr },
   { "DT_Func_LOD", ClientClass<CFunc_LOD>::InstancePtr },
   { "DT_FuncAreaPortalWindow", ClientClass<CFuncAreaPortalWindow>::InstancePtr },
   { "DT_FuncBrush", ClientClass<CFuncBrush>::InstancePtr },
   { "DT_FuncConveyor", ClientClass<CFuncConveyor>::InstancePtr },
   { "DT_FuncLadder", ClientClass<CFuncLadder>::InstancePtr },
   { "DT_FuncMoveLinear", ClientClass<CFuncMoveLinear>::InstancePtr },
   { "DT_FuncOccluder", ClientClass<CFuncOccluder>::InstancePtr },
   { "DT_FuncReflectiveGlass", ClientClass<CFuncReflectiveGlass>::InstancePtr },
   { "DT_FuncRotating", ClientClass<CFuncRotating>::InstancePtr },
   { "DT_FuncSmokeVolume", ClientClass<CFuncSmokeVolume>::InstancePtr },
   { "DT_FuncTrackTrain", ClientClass<CFuncTrackTrain>::InstancePtr },
   { "DT_GameRulesProxy", ClientClass<CGameRulesProxy>::InstancePtr },
   { "DT_HandleTest", ClientClass<CHandleTest>::InstancePtr },
   { "DT_InfoLadderDismount", ClientClass<CInfoLadderDismount>::InstancePtr },
   { "DT_InfoOverlayAccessor", ClientClass<CInfoOverlayAccessor>::InstancePtr },
   { "DT_LightGlow", ClientClass<CLightGlow>::InstancePtr },
   { "DT_MaterialModifyControl", ClientClass<CMaterialModifyControl>::InstancePtr },
   { "DT_MovieDisplay", ClientClass<CMovieDisplay>::InstancePtr },
   { "DT_ParticleFire", ClientClass<CParticleFire>::InstancePtr },
   { "DT_ParticlePerformanceMonitor", ClientClass<CParticlePerformanceMonitor>::InstancePtr },
   { "DT_ParticleSystem", ClientClass<CParticleSystem>::InstancePtr },
   { "DT_PhysBox", ClientClass<CPhysBox>::InstancePtr },
   { "DT_PhysBoxMultiplayer", ClientClass<CPhysBoxMultiplayer>::InstancePtr },
   { "DT_PhysicsProp", ClientClass<CPhysicsProp>::InstancePtr },
   { "DT_PhysicsPropMultiplayer", ClientClass<CPhysicsPropMultiplayer>::InstancePtr },
   { "DT_PhysMagnet", ClientClass<CPhysMagnet>::InstancePtr },
   { "DT_Plasma", ClientClass<CPlasma>::InstancePtr },
   { "DT_PointCamera", ClientClass<CPointCamera>::InstancePtr },
   { "DT_PointCommentaryNode", ClientClass<CPointCommentaryNode>::InstancePtr },
   { "DT_PoseController", ClientClass<CPoseController>::InstancePtr },
   { "DT_PostProcessController", ClientClass<CPostProcessController>::InstancePtr },
   { "DT_Precipitation", ClientClass<CPrecipitation>::InstancePtr },
   { "DT_PrecipitationBlocker", ClientClass<CPrecipitationBlocker>::InstancePtr },
   { "DT_Prop_Hallucination", ClientClass<CProp_Hallucination>::InstancePtr },
   { "DT_PropDoorRotating", ClientClass<CPropDoorRotating>::InstancePtr },
   { "DT_PropVehicleDriveable", ClientClass<CPropVehicleDriveable>::InstancePtr },
   { "DT_RagdollManager", ClientClass<CRagdollManager>::InstancePtr },
   { "DT_Ragdoll", ClientClass<CRagdollProp>::InstancePtr },
   { "DT_Ragdoll_Attached", ClientClass<CRagdollPropAttached>::InstancePtr },
   { "DT_RopeKeyframe", ClientClass<CRopeKeyframe>::InstancePtr },
   { "DT_SceneEntity", ClientClass<CSceneEntity>::InstancePtr },
   { "DT_ShadowControl", ClientClass<CShadowControl>::InstancePtr },
   { "DT_SlideshowDisplay", ClientClass<CSlideshowDisplay>::InstancePtr },
   { "DT_SmokeStack", ClientClass<CSmokeStack>::InstancePtr },
   { "DT_SpatialEntity", ClientClass<CSpatialEntity>::InstancePtr },
   { "DT_SpotlightEnd", ClientClass<CSpotlightEnd>::InstancePtr },
   { "DT_Sprite", ClientClass<CSprite>::InstancePtr },
   { "DT_SpriteOriented", ClientClass<CSpriteOriented>::InstancePtr },
   { "DT_SpriteTrail", ClientClass<CSpriteTrail>::InstancePtr },
   { "DT_StatueProp", ClientClass<CStatueProp>::InstancePtr },
   { "DT_SteamJet", ClientClass<CSteamJet>::InstancePtr },
   { "DT_Sun", ClientClass<CSun>::InstancePtr },
   { "DT_SunlightShadowControl", ClientClass<CSunlightShadowControl>::InstancePtr },
   { "DT_Team", ClientClass<CTeam>::InstancePtr },
   { "DT_TeamShowcaseEditorManager", ClientClass<CTeamShowcaseEditorManager>::InstancePtr },
   { "DT_TeamShowcasePlayer", ClientClass<CTeamShowcasePlayer>::InstancePtr },
   { "DT_TEArmorRicochet", ClientClass<CTEArmorRicochet>::InstancePtr },
   { "DT_BaseBeam", ClientClass<CTEBaseBeam>::InstancePtr },
   { "DT_TEBeamEntPoint", ClientClass<CTEBeamEntPoint>::InstancePtr },
   { "DT_TEBeamEnts", ClientClass<CTEBeamEnts>::InstancePtr },
   { "DT_TEBeamFollow", ClientClass<CTEBeamFollow>::InstancePtr },
   { "DT_TEBeamLaser", ClientClass<CTEBeamLaser>::InstancePtr },
   { "DT_TEBeamPoints", ClientClass<CTEBeamPoints>::InstancePtr },
   { "DT_TEBeamRing", ClientClass<CTEBeamRing>::InstancePtr },
   { "DT_TEBeamRingPoint", ClientClass<CTEBeamRingPoint>::InstancePtr },
   { "DT_TEBeamSpline", ClientClass<CTEBeamSpline>::InstancePtr },
   { "DT_TEBloodSprite", ClientClass<CTEBloodSprite>::InstancePtr },
   { "DT_TEBloodStream", ClientClass<CTEBloodStream>::InstancePtr },
   { "DT_TEBreakModel", ClientClass<CTEBreakModel>::InstancePtr },
   { "DT_TEBSPDecal", ClientClass<CTEBSPDecal>::InstancePtr },
   { "DT_TEBubbles", ClientClass<CTEBubbles>::InstancePtr },
   { "DT_TEBubbleTrail", ClientClass<CTEBubbleTrail>::InstancePtr },
   { "DT_TEClientProjectile", ClientClass<CTEClientProjectile>::InstancePtr },
   { "DT_TEDecal", ClientClass<CTEDecal>::InstancePtr },
   { "DT_TEDotaBloodImpact", ClientClass<CTEDotaBloodImpact>::InstancePtr },
   { "DT_TEDOTAProjectile", ClientClass<CTEDOTAProjectile>::InstancePtr },
   { "DT_TEDOTAProjectileLoc", ClientClass<CTEDOTAProjectileLoc>::InstancePtr },
   { "DT_TEDust", ClientClass<CTEDust>::InstancePtr },
   { "DT_TEDynamicLight", ClientClass<CTEDynamicLight>::InstancePtr },
   { "DT_TEEffectDispatch", ClientClass<CTEEffectDispatch>::InstancePtr },
   { "DT_TEEnergySplash", ClientClass<CTEEnergySplash>::InstancePtr },
   { "DT_TEExplosion", ClientClass<CTEExplosion>::InstancePtr },
   { "DT_TEFizz", ClientClass<CTEFizz>::InstancePtr },
   { "DT_TEFootprintDecal", ClientClass<CTEFootprintDecal>::InstancePtr },
   { "DT_TEFoundryHelpers", ClientClass<CTEFoundryHelpers>::InstancePtr },
   { "DT_TEGaussExplosion", ClientClass<CTEGaussExplosion>::InstancePtr },
   { "DT_TEGlowSprite", ClientClass<CTEGlowSprite>::InstancePtr },
   { "DT_TEImpact", ClientClass<CTEImpact>::InstancePtr },
   { "DT_TEKillPlayerAttachments", ClientClass<CTEKillPlayerAttachments>::InstancePtr },
   { "DT_TELargeFunnel", ClientClass<CTELargeFunnel>::InstancePtr },
   { "DT_TEMetalSparks", ClientClass<CTEMetalSparks>::InstancePtr },
   { "DT_TEMuzzleFlash", ClientClass<CTEMuzzleFlash>::InstancePtr },
   { "DT_TEParticleSystem", ClientClass<CTEParticleSystem>::InstancePtr },
   { "DT_TEPhysicsProp", ClientClass<CTEPhysicsProp>::InstancePtr },
   { "DT_TEPlayerDecal", ClientClass<CTEPlayerDecal>::InstancePtr },
   { "DT_TEProjectedDecal", ClientClass<CTEProjectedDecal>::InstancePtr },
   { "DT_TEShatterSurface", ClientClass<CTEShatterSurface>::InstancePtr },
   { "DT_TEShowLine", ClientClass<CTEShowLine>::InstancePtr },
   { "DT_Tesla", ClientClass<CTesla>::InstancePtr },
   { "DT_TESmoke", ClientClass<CTESmoke>::InstancePtr },
   { "DT_TESparks", ClientClass<CTESparks>::InstancePtr },
   { "DT_TESprite", ClientClass<CTESprite>::InstancePtr },
   { "DT_TESpriteSpray", ClientClass<CTESpriteSpray>::InstancePtr },
   { "DT_ProxyToggle", ClientClass<CTest_ProxyToggle_Networkable>::InstancePtr },
   { "DT_TestTraceline", ClientClass<CTestTraceline>::InstancePtr },
   { "DT_TEUnitAnimation", ClientClass<CTEUnitAnimation>::InstancePtr },
   { "DT_TEUnitAnimationEnd", ClientClass<CTEUnitAnimationEnd>::InstancePtr },
   { "DT_TEWorldDecal", ClientClass<CTEWorldDecal>::InstancePtr },
   { "DT_TFWearableItem", ClientClass<CTFWearableItem>::InstancePtr },
   { "DT_TriggerCamera", ClientClass<CTriggerCamera>::InstancePtr },
   { "DT_TriggerPlayerMovement", ClientClass<CTriggerPlayerMovement>::InstancePtr },
   { "DT_VGuiScreen", ClientClass<CVGuiScreen>::InstancePtr },
   { "DT_WaterBullet", ClientClass<CWaterBullet>::InstancePtr },
   { "DT_WaterLODControl", ClientClass<CWaterLODControl>::InstancePtr },
   { "DT_WORLD", ClientClass<CWorld>::InstancePtr },
   { "DT_DustTrail", ClientClass<DustTrail>::InstancePtr },
   { "DT_MovieExplosion", ClientClass<MovieExplosion>::InstancePtr },
   { "DT_NextBot", ClientClass<NextBotCombatCharacter>::InstancePtr },
   { "DT_ParticleSmokeGrenade", ClientClass<ParticleSmokeGrenade>::InstancePtr },
   { "DT_RocketTrail", ClientClass<RocketTrail>::InstancePtr },
   { "DT_SmokeTrail", ClientClass<SmokeTrail>::InstancePtr },
   { "DT_SporeExplosion", ClientClass<SporeExplosion>::InstancePtr },
   { "DT_SporeTrail", ClientClass<SporeTrail>::InstancePtr },
};

}
