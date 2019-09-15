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
	ParticleType particleType2;
};

struct MagicHealInfo : MagicInfo
{
	float dummyVar;
	int32_t maxToHeal;
};

struct MagicTeleportInfo : MagicInfo
{
	float costPerKilometer;
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

struct MagicStormAndTornadoInfo : MagicInfo
{
	float minRadius;
	float maxRadius;
	float radiusForNormalCost;
	float maxWindSpeed;
	float rainAmount;
};

struct MagicShieldOneInfo : MagicInfo
{
	int32_t minRadius;
	int32_t maxRadius;
	int32_t radiusForNormalCost;
	int32_t chantCostPerImpactMomentum;
	int32_t shieldHeight;
	int32_t raiseWithScale;
	int32_t bobMagnitude;
};

struct MagicWoodInfo : MagicInfo
{
	ResourceType resourceType;
	int32_t resourceAmountFirstEvent;
	int32_t resourceAmountPerEvent;
	int32_t costPerUnit;
	int32_t poisoned;
};

// nothing ?
struct MagicWaterInfo : MagicInfo {};

struct MagicFlockFlyingInfo : MagicInfo
{
	int32_t numberToCreate;
	int32_t alignmentSwitch;
	int32_t distanceToTravel;
};

struct MagicFlockGroundInfo : MagicInfo
{
	int32_t numberToCreate;
	int32_t alignmentSwitch;
	int32_t distanceToTravel;
	int32_t huntingRadius;
};

struct MagicCreatureSpellInfo : MagicInfo
{
	CreatureReceiveSpellType creatureReceiveSpellType;
	char text[48];
	int32_t startTransitionDuration;
	int32_t finishTransitionDuration;
	int32_t totalDuration;
    int32_t maxDirnChangeWhenCtrCasting;
};


};

} // namespace openblack
