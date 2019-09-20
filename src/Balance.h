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

struct ObjectInfo
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
	int32_t VillagerInteractState;            // todo: ENUM_VILLAGER_STATES
	int32_t VillagerInteractStateForBuilding; // todo: ENUM_VILLAGER_STATES
	float VillagerInteractDesire;
	float SacrificeValue;
	float ImpressiveValue;
	float AggressorValue;
	float VillagerImpressiveValue;
	float ArtifactMultiplier;
	float DrawImportance;
	float ComputerAttackDesire;
};

struct DetailSpellSeed: ObjectInfo
{
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

struct DetailAnimalInfo: ObjectInfo
{
	char unknown[256]; // no clue
	int32_t Dummy;
	int32_t speedGroup;  // todo: DETAIL_SPEED_GROUP
	int32_t collideType; // todo: DETAIL_COLLIDE_TYPE
	LivingType creatureType;
	LivingStates moveState;
	float life;
	float strength;
	float defence;
	int32_t startAge;
	int32_t grownUpAge;
	int32_t oldAge;
	int32_t retirementAge;
	int32_t isReacting; // todo: DETAIL_IS_REACTING
	int32_t isShepherdable;
	int32_t minFlockingValue;
	int32_t maxFlockingValue;
	AnimalInfo animalInfo;
	SexType sexType;
	MeshId meshHigh;
	MeshId meshStd;
	MeshId meshLow;
	int32_t defaultAnim; // todo: DETAIL_ANIM_TYPES
	int32_t hunger;
	int32_t thirst;
	int32_t sleep;
	int32_t needToBreed;
	float flockDistance;
	int32_t turnAngle; // todo: DETAIL_TURNANGLE_STATES
	int32_t viewAngle; // todo: DETAIL_TURNANGLE_STATES
	int32_t playerCanPickUp;
	int32_t needsTown;
	int32_t needsFoodTypes; // todo: DETAIL_FOOD_TYPE
	int32_t flocksCanMerge;
	float stalkingDistance;
	float attackDistance;
	float huntingDistance;
	int32_t sightDistance;
	int32_t farSightDistance;
	int32_t nearSightDistance;
	int32_t chaseTime;
	int32_t environment;
	int32_t domainInnerRadius;
	int32_t domainRadius;
	int32_t maxFlockSize;
	int32_t stayTime;
	float altitudeMin;
	float altitudeMax;
	float altitudeVariance;
	float altitudeMovementChange;
	float altitudeNormal;
	int32_t ageToScaleNormal; // todo: AGE_TO_SCALE_NORMAL
};

// 0x384 = 900
struct DetailCreatureInfo: ObjectInfo
{
	char padding[660];
};

struct DetailCreatureBalance
{
	float initialHeight;
	float numMinutesToGrowToMaxIfFullyHealthy;
	float energyDecreasePerGameTurn;
	float initialFatness;
	float fatnessDecayPerGameTurn;
	float fatnessMultiplierWhenEatingSomething;
	float initialStrength;
	float strengthDecayPerGameTurn;
	float numMinutesToBecomeFullyStrongFromHoldingSomethingHeavy;
	float initialCrawlingSpeed;
	float initialWalkingSpeed;
	float initialRunningSpeed;
	float lookTurnAccel;
	float exhaustionIncreasePerGameTurn;
	float exhaustionDecreaseWhenResting;
	float damageDefenceMultiplierBurn;
	float damageDefenceMultiplierCrush;
	float damageDefenceMultiplierHit;
	float lifeIncreaseWhenResting;
	int32_t numSecondsBeforeAgeIncrease;
	float pooMultiplier;
	float howManyTimesTheyNeedToLearnMultiplier;
	float alignmentChangeSpeed;
};

struct DetailCreatureDesireInitialCycleTime
{
	float creatureTypes[17];
};

struct DetailCreatureDevelopment
{
	char text[48];
	float howNearToStayToHome;
	float timeBetweenHelpPromptsDevelopmentCriteria;
	float frequencyOfOffScreenPrompts;
	CreatureDesires desiredAdded[10];
	CreatureDesires desireRemoved[4];
};

struct DetailCreatureDevelopsTime
{
	int32_t developmentPhases[14];
};

struct DetailCitadelInfo
{
	int32_t ContainerType;
	int32_t HeartInfo;
	int32_t PensStartX;
	int32_t PensStartZ;
	int32_t PensMaxSpiral;
	int32_t WorshipSiteStartX;
	int32_t WorsipSiteStartZ;
	int32_t MaxNo;
	int32_t MaxDistanceOfTownFromCitadelOfPygmyTown;
	int32_t PygmyTownMaxSpiral;
	int32_t HousesInPygmyTown;
	int32_t ImportanceOfBeingFarAwayFromOtherTowns;
	int32_t PrayerSiteAngle;
	float PrayerSiteDistance;
	float VirtualInfluenceMaxDistance;
	int32_t VirtualInfluenceMaxGameTicks;
	float VirtualInfluenceChantsToDouble;
};

struct DetailCitadelHeartInfo: ObjectInfo
{
	GroundInfo groundInfo;
	int32_t woodRequiredPerBuild;
	int32_t timeToBuild;
	int32_t scaffoldsRequired;
	int32_t maxVillagerNeededToBuild;
	float desireToBeBuilt;
	float desireToBeRepaired;
	float influence;
	int32_t citadelType; // DETAIL_CITADEL_TYPES
	MeshId meshType;     // DETAIL_MESH_TYPES
	float startLife;
	int32_t startStrength;
	float startDefence;
	int32_t startGoodness;
	int32_t startFollowers;
	int32_t maxFlockCount;
	float storyInfluence[5];
	float transferedDamageMultiplier;
};

struct DetailCreaturePenInfo: ObjectInfo
{
	GroundInfo groundInfo;
	int32_t woodRequiredPerBuild;
	int32_t timeToBuild;
	int32_t scaffoldsRequired;
	int32_t maxVillagerNeededToBuild;
	float desireToBeBuilt;
	float desireToBeRepaired;
	float influence;
	int32_t citadelType; // DETAIL_CITADEL_TYPES
	MeshId meshType;     // DETAIL_MESH_TYPES
	float startLife;
	int32_t startStrength;
	float startDefence;
	int32_t info; // DETAIL_PEN_INFO_TYPE
	float startPlacementDistace;
	float endPlacementDistace;
	int32_t placementAngle;
};

struct DetailWorshipSiteInfo: ObjectInfo
{
	GroundInfo groundInfo;
	int32_t woodRequiredPerBuild;
	int32_t timeToBuild;
	int32_t scaffoldsRequired;
	int32_t maxVillagerNeededToBuild;
	float desireToBeBuilt;
	float desireToBeRepaired;
	float influence;
	int32_t citadelType; // DETAIL_CITADEL_TYPES
	MeshId meshType;     // DETAIL_MESH_TYPES
	float startLife;
	int32_t startStrength;
	float startDefence;
	float radiusFromCitadel;
	MeshId baseMesh;
	int32_t PotForResourceFood; // todo: ENUM_POT_INFO
	int32_t PotForResourceWood; // todo: ENUM_POT_INFO
	float chantsPerVillager;
	float prayerSiteDistance;
	int32_t maxDancersVisible;
	float chantsToFillBattery;
	float eachVillagerAddToFillBattery;
	int32_t chantsToReserveForMaintaining;
	float artifactPowerupMultiplier;
};

struct DetailSpellIconInfo: ObjectInfo
{
	GroundInfo groundInfo;
	int32_t woodRequiredPerBuild;
	int32_t timeToBuild;
	int32_t scaffoldsRequired;
	int32_t maxVillagerNeededToBuild;
	float desireToBeBuilt;
	float desireToBeRepaired;
	float influence;
	MeshId mesh;
	float radiusFromCitadel;
	float gatheringChantAddPerGameTurn;
};

struct DetailAbodeInfo: ObjectInfo
{
	GroundInfo groundInfo;
	int32_t dummy1;
	int32_t dummy2;
	int32_t scaffoldsRequired;
	int32_t maxVillagerNeededToBuild;
	float desireToBeBuilt;
	float desireToBeRepaired;
	float influence;
	AbodeType abodeType;
	AbodeNumber abodeNumber;
	char debugStringTwo[48];
	TribeType tribeType;
	MeshId meshID;
	int32_t canBePhysicallyDamaged;
	float startLife;
	int32_t startStrength;
	float startDefence;
	int32_t startInfluence;
	int32_t maxVillagersInAbode;
	int32_t maxChildrenInAbode;
	int32_t startVillagersInAbode;
	int32_t startChildrenInAbode;
	int32_t startFood;
	int32_t startFoodRAnd;
	int32_t startWood;
	int32_t startWoodRAnd;
	int32_t howLongRuinLastsFor;
	int32_t potForResourceFood;
	int32_t potForResourceWood;
	float percentTooCrowded;
	MobileObjectInfo producesMobileObject;
	float maxNumMobileObjectsToProduce;
	float timeEachMobileObjectTakesToProduce;
	float emptyAbodeLifeReducer;
	int32_t populationWhenNeeded;
	float thresholdForStopBeingFunctional;
	int32_t toolTipsForBuild; // todo: ENUM_HELP_TEXT
	int32_t didYouKnow; // todo: ENUM_HELP_TEXT
	int32_t DYKCategory; // todo: ENUM_DYK_CATEGORY
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
static_assert(sizeof(DetailAnimalInfo) == 700, "DetailAnimalInfo size incorrect");
static_assert(sizeof(DetailCreatureInfo) == 900, "DetailCreatureInfo size incorrect");
static_assert(sizeof(DetailCreatureBalance) == 92, "DetailCreatureBalance size incorrect");
static_assert(sizeof(DetailCreatureDesireInitialCycleTime) == 68, "DetailCreatureDesireInitialCycleTime size incorrect");

} // namespace openblack
