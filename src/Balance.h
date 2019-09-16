/* openblack - A reimplementation of Lionhead's Black & White.
 *
 * openblack is the legal property of its developers, whose names
 * can be found in the AUTHORS.md file distributed with this source
 * distribution.
 *
 * openblack is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * openblack is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with openblack. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <AllMeshes.h>
#include <Enums.h>
#include <cstdint>

namespace openblack
{

class Balance
{
  public:
	static void LoadVariables();
};

// enums need to be int32_t?

struct MagicInfo
{
	MagicType magicType;
	ImmersionEffectType immersionEffectType;
	int32_t stopImmersion;
	float perceivedPower;
	ParticleType particleType;
	ImpressiveType impressiveType;
	SpellSeedType spellSeedType;
	GestureType gestureType;
	PowerUpType powerupType;
	CastRuleType castRuleType;
	int32_t isSpellSeedDrawnInHand;
	int32_t isSpellRecharged;
	int32_t isCreatureCastFromAbove;
	int32_t oneOffSpellIsPlayful;
	int32_t oneOffSpellIsAggressive;
	int32_t oneOffSpellIsCompassionate;
	int32_t oneOffSpellIsToRestoreHealth;
	ParticleType particleType2;
};

struct MagicHealInfo: MagicInfo
{
	float dummyVar;
	int32_t maxToHeal;
};

struct MagicTeleportInfo: MagicInfo
{
	float costPerKilometer;
};

struct MagicForestInfo: MagicInfo
{
	int32_t finalNoTrees;
	int32_t startLife;
	int32_t growSpeed;
	int32_t decaySpeed;
	int32_t woodValueMultiplier;
};

struct MagicFoodInfo: MagicInfo
{
	ResourceType resourceType;
	int32_t resourceAmountFirstEvent;
	int32_t resourceAmountPerEvent;
	int32_t costPerUnit;
	int32_t poisoned;
};

struct MagicStormAndTornadoInfo: MagicInfo
{
	float minRadius;
	float maxRadius;
	float radiusForNormalCost;
	float maxWindSpeed;
	float rainAmount;
};

struct MagicShieldOneInfo: MagicInfo
{
	int32_t minRadius;
	int32_t maxRadius;
	int32_t radiusForNormalCost;
	int32_t chantCostPerImpactMomentum;
	int32_t shieldHeight;
	int32_t raiseWithScale;
	int32_t bobMagnitude;
};

struct MagicWoodInfo: MagicInfo
{
	ResourceType resourceType;
	int32_t resourceAmountFirstEvent;
	int32_t resourceAmountPerEvent;
	int32_t costPerUnit;
	int32_t poisoned;
};

// nothing ?
struct MagicWaterInfo: MagicInfo
{
};

struct MagicFlockFlyingInfo: MagicInfo
{
	int32_t numberToCreate;
	int32_t alignmentSwitch;
	int32_t distanceToTravel;
};

struct MagicFlockGroundInfo: MagicInfo
{
	int32_t numberToCreate;
	int32_t alignmentSwitch;
	int32_t distanceToTravel;
	int32_t huntingRadius;
};

struct MagicCreatureSpellInfo: MagicInfo
{
	CreatureReceiveSpellType creatureReceiveSpellType;
	char text[48];
	int32_t startTransitionDuration;
	int32_t finishTransitionDuration;
	int32_t totalDuration;
	int32_t maxDirnChangeWhenCtrCasting;
};

struct MagicEffectInfo
{
	float effectBurn;
	float effectCrush;
	float effectHit;
	float effectHeal;
	float effectForce;
	float effectAlignmentModificaton;
	float effectBeliefModification;
	float radius;
	MeshId testMesh;
	char debugString[48];
	int32_t TimerWhenOneShot;
	int32_t TimerWhenPlayerCasting;
	int32_t TimerWhenCreatureCasting;
	int32_t TimerWhenComputerPlayerCasting;
	float initialChants;
	float costToCreate;
	float costPerEvent;
	float costPerGameTurn;
	float costPerShieldCollide;
	int32_t divideCostsByTribalPower;
	int32_t createReactionOnCast;
	int32_t createReactionOnEvent;
	Reaction reactionType;
	CreatureDesires perceivedPlayerDesire1;
	CreatureDesires perceivedPlayerDesire2;
	TownDesireInfo townDesireBeingHelped;
	float AgressiveRangeMin;
	float AgressiveRangeMax;
	float CalculatedCostForOneTurn;
	float CostForOneAppliedEffect;
	float CostInGameTurnsToCreateForOneVillager;
	float TempNoVillagers;
	float CostForTempVillagers;
	float CostInRealTimeToCreate;
	float ImpressiveValue;
	float CPImpressiveBalance;
	int32_t useTribalPowerMultiplier[9]; // TribeType
	int32_t isAggressiveSpellWhichIsUsedInCreatureFightArena;
	int32_t isDefensiveSpellWhichIsUsedInCreatureFightArena;
	int32_t HelpStartEnum;            // todo: ENUM_HELP_TEXT
	int32_t HelpEndEnum;              // todo: ENUM_HELP_TEXT
	int32_t CreatureNearlyLearntEnum; // todo: ENUM_HELP_TEXT
	int32_t CreatureLearntEnum;       // todo: ENUM_HELP_TEXT
	int32_t HelpMessage;              // todo: ENUM_HELP_SYSTEM_MESSAGE_SET
	int32_t HelpCondition;            // todo: ENUM_HELP_SYSTEM_CONDITION
	int32_t ToolTipsEnum;             // todo: ENUM_HELP_TEXT
	float AggressiveAttackValue;
	float ComputerCastDuration;
};

struct DetailSpellSeed
{
	ObjectType objectType;
	AlignmentType alignment;
	char debugString[48];
	SoundCollisionType collideSound;
	ImmersionEffectType immersion;
	int32_t helpStartEnum; // todo: ENUM_HELP_TEXT
	int32_t helpEndEnum;   // todo: ENUM_HELP_TEXT
	int32_t helpMessage;   // todo: ENUM_HELP_SYSTEM_MESSAGE_SET
	int32_t helpCondition; // todo: ENUM_HELP_SYSTEM_CONDITION
	int32_t helpInHand;    // todo: ENUM_HELP_SYSTEM_MESSAGE_SET
	int32_t handCondition; // todo: ENUM_HELP_SYSTEM_CONDITION
	float foodValue;
	int32_t woodValue;
	int32_t foodType; // todo: DETAIL_FOOD_TYPE
	float DefenceEffectBurn;
	float DefenceEffectCrush;
	float DefenceEffectHit;
	float DefenceEffectHeal;
	float DefenceEffectFlyAway;
	float DefenceEffectAlignmentModification;
	float DefenceEffectBeliefModification;
	float DefenceMultiplierBurn;
	float DefenceMultiplierCrush;
	float DefenceMultiplierHit;
	float DefenceMultiplierHeal;
	float DefenceMultiplierFlyAway;
	float DefenceMultiplierAlignmentModification;
	float DefenceMultiplierBeliefModification;
	float Weight;
	float HeatCapacity;
	float CombustionTemperature;
	float BurningPriority;
	int32_t CanCreatureUseForBuilding;
	int32_t CanCreatureInteractWithMe;
	int32_t CanCreatureAttackMe;
	int32_t CanCreaturePlayWithMe;
	int32_t CanCreatureInspectMe;
	int32_t CanCreatureGiveMeToLiving;
	int32_t CanCreatureBringMeBackToTheCitadel;
	int32_t VillagerInteractState; // todo: ENUM_VILLAGER_STATES
	int32_t VillagerInteractStateForBuilding; // todo: ENUM_VILLAGER_STATES
	float VillagerInteractDesire;
	float SacrificeValue;
	float ImpressiveValue;
	float AggressorValue;
	float VillagerImpressiveValue;
	float ArtifactMultiplier;
	float DrawImportance;
	float ComputerAttackDesire;
	GestureType SelectionGesture1;
	GestureType SelectionGesture2;
	GestureType SelectionGesture3;
	GestureType CastGesture;
	SpellCastType CastType;
	int32_t KeepInHand;
	int32_t TargetObjectDirectly;
	int32_t CanBeCastOnObject;
	int32_t Create;
	// Seed
	MagicType DefaultSpell;
	MagicType MagicTypePowerUpOne;
	MagicType MagicTypePowerUpTwo;
	MagicType MagicTypePowerUpThree;
	GestureType GestureTypePowerUpOne;
	GestureType GestureTypePowerUpTwo;
	GestureType GestureTypePowerUpThree;
	MeshId SpellSeedObjectIcon;
	float Scale;
	float ScaleInHand;
	float HoldLoweringMultiplier;
	float HoldRadiusMultiplier;
	float HoldYRotate;
	HoldType holdType;
	int32_t DrawAtGraspPos;
	float SeedMeshRaiseAmount;
	float SeedPSysRaiseAmount;
	int32_t DeletedOnceCast;
	float DecayRateIfNotAtFullPower;
	int32_t AutoTakeFromWorshipSite;
	ParticleType particleType;
	int32_t IsSpellSeedDrawOnHolder;
	int32_t IsUsedInGame;
	int32_t SortSpellSeed;
	int32_t ToolTipsEnum; // ENUM_HELP_TEXT
	int32_t ShowDirection;
	int32_t CreatureUsesInFight;
};

// size checks for Black & White 1, these will differ for CreatureIsle most likely
static_assert(sizeof(MagicInfo) == 72, "MagicInfo size incorrect");
static_assert(sizeof(MagicHealInfo) == 80, "MagicHealInfo size incorrect");
static_assert(sizeof(MagicTeleportInfo) == 76, "MagicTeleportInfo size incorrect");
static_assert(sizeof(MagicForestInfo) == 92, "MagicForestInfo size incorrect");
static_assert(sizeof(MagicFoodInfo) == 92, "MagicFoodInfo size incorrect");
static_assert(sizeof(MagicStormAndTornadoInfo) == 92, "MagicStormAndTornadoInfo size incorrect");
static_assert(sizeof(MagicShieldOneInfo) == 100, "MagicShieldOneInfo size incorrect");
static_assert(sizeof(MagicWoodInfo) == 92, "MagicWoodInfo size incorrect");
static_assert(sizeof(MagicWaterInfo) == 72, "MagicWaterInfo size incorrect");
static_assert(sizeof(MagicFlockFlyingInfo) == 84, "MagicFlockFlyingInfo size incorrect");
static_assert(sizeof(MagicFlockGroundInfo) == 88, "MagicFlockGroundInfo size incorrect");
static_assert(sizeof(MagicCreatureSpellInfo) == 140, "MagicCreatureSpellInfo size incorrect");

static_assert(sizeof(MagicEffectInfo) == 268, "MagicEffectInfo size incorrect");
static_assert(sizeof(DetailSpellSeed) == 384, "DetailSpellSeed size incorrect");

} // namespace openblack
