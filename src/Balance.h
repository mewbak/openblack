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

#include <Enums.h>
#include <cstdint>

namespace openblack
{

class Balance {
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
};

struct MagicHealInfo : MagicInfo
{
	int32_t dummyVar;
	int32_t maxToHeal;
};

struct MagicTeleportInfo : MagicInfo
{
	int32_t costPerKilometer;
};

struct MagicForestInfo : MagicInfo
{
	int32_t finalNoTrees;
	int32_t startLife;
	int32_t growSpeed;
	int32_t decaySpeed;
	int32_t woodValueMultiplier;
};

struct MagicFoodInfo : MagicInfo
{
	ResourceType resourceType;
	int32_t resourceAmountFirstEvent;
	int32_t resourceAmountPerEvent;
	int32_t costPerUnit;
	int32_t poisoned;
};

struct MagicStormAndTornadoInfo : MagicInfo {
	int32_t minRadius;
	int32_t maxRadius;
	int32_t radiusForNormalCost;
	int32_t maxWindSpeed;
	int32_t rainAmount;
};

struct MagicShieldOneInfo : MagicInfo {
	// MinRadius	MaxRadius	RadiusForNormalCost	ChantCostPerImpactMomentum	ShieldHeight	RaiseWithScale	BobMagnitude
};
struct MagicWoodInfo : MagicInfo {
	// ResourceType:ENUM_RESOURCE_TYPE	ResourceAmountFirstEvent	ResourceAmountPerEvent	CostPerUnit	Poisoned
};
struct MagicWaterInfo : MagicInfo {
	// nothing
};
struct MagicFlockFlyingInfo : MagicInfo {
	// NumberToCreate	AlignmentSwitch	DistanceToTravel
};
struct MagicFlockGroundInfo : MagicInfo {
	// NumberToCreate	AlignmentSwitch	DistanceToTravel	HuntingRadius
};
struct MagicCreatureSpellInfo : MagicInfo {
	// ENUM_CREATURE_RECEIVE_SPELL_TYPE	Text:48	StartTransitionDuration	FinishTransitionDuration	TotalDuration	MaxDirnChangeWhenCtrCasting
};

} // namespace openblack
