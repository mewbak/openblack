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

#include <Balance.h>
#include <Common/FileSystem.h>
#include <Common/magic_enum.hpp>
#include <Game.h>
#include <spdlog/spdlog.h>

namespace openblack
{

void Balance::LoadVariables()
{
	auto file = Game::instance()->GetFileSystem().Open("Scripts/info.dat", FileMode::Read);

	// check magic header
	constexpr char kLionheadMagic[] = "LiOnHeAd";

	struct
	{
		char blockName[32];
		uint32_t blockSize;
		uint32_t position;
	} header;

	char magic[8];
	file->Read(magic, 8);
	if (!std::equal(kLionheadMagic, kLionheadMagic + 8, magic))
		throw std::runtime_error("invalid Lionhead file magic");

	char blockName[32];
	file->Read(blockName, 32);
	uint32_t size = file->ReadValue<uint32_t>();

	// GMagicInfo::LoadMagic
	spdlog::debug("DETAIL_MAGIC_GENERAL_INFO");
	for (auto i = 0; i < 10; i++)
	{
		auto info = file->ReadValue<MagicInfo>();
		spdlog::debug("[{}] MagicType={} : impressiveType={}", i, magic_enum::enum_name(info.magicType), magic_enum::enum_name(info.impressiveType));
	}

	// GMagicHealInfo::LoadMagic
	spdlog::debug("DETAIL_MAGIC_HEAL_INFO");
	for (auto i = 0; i < 2; i++)
	{
		auto info = file->ReadValue<MagicHealInfo>();
		spdlog::debug("[{}] MagicType={} : maxToHeal={}", i, magic_enum::enum_name(info.magicType), info.maxToHeal);
	}

	// GMagicTeleportInfo::LoadMagic
	spdlog::debug("DETAIL_MAGIC_TELEPORT_INFO");
	{
		auto info = file->ReadValue<MagicTeleportInfo>();
		spdlog::debug("[{}] MagicType={} : costPerKM={}", 0, magic_enum::enum_name(info.magicType), info.costPerKilometer);
	}

	// GMagicForestInfo::LoadMagic
	spdlog::debug("DETAIL_MAGIC_FOREST_INFO");
	{
		auto info = file->ReadValue<MagicForestInfo>();
		spdlog::debug("[{}] MagicType={} : finalNoTrees={}", 0, magic_enum::enum_name(info.magicType), info.finalNoTrees);
	}

	// GMagicResourceInfo::LoadMagic
	spdlog::debug("DETAIL_MAGIC_FOOD_INFO");
	for (auto i = 0; i < 2; i++)
	{
		auto info = file->ReadValue<MagicFoodInfo>();
		spdlog::debug("[{}] MagicType={} : resourceType={}", i, magic_enum::enum_name(info.magicType), magic_enum::enum_name(info.resourceType));
	}

	// GMagicStormAndTornadoInfo::LoadMagic
	spdlog::debug("DETAIL_MAGIC_STORM_AND_TORNADO_INFO");
	for (auto i = 0; i < 3; i++)
	{
		auto info = file->ReadValue<MagicStormAndTornadoInfo>();
		spdlog::debug("[{}] MagicType={} : rainAmount={}", i, magic_enum::enum_name(info.magicType), info.rainAmount);
	}

	// GMagicShieldInfo::LoadMagic
	spdlog::debug("DETAIL_MAGIC_SHIELD_ONE_INFO");
	for (auto i = 0; i < 2; i++)
	{
		auto info = file->ReadValue<MagicShieldOneInfo>();
		spdlog::debug("[{}] MagicType={} : shieldHeight={}", i, magic_enum::enum_name(info.magicType), info.shieldHeight);
	}

	// GMagicResourceInfo::LoadMagic
	spdlog::debug("DETAIL_MAGIC_WOOD_INFO");
	{
		auto info = file->ReadValue<MagicWoodInfo>();
		spdlog::debug("[{}] MagicType={} : resourceType={}", 0, magic_enum::enum_name(info.magicType), magic_enum::enum_name(info.resourceType));
	}

	// GMagicWaterInfo::LoadMagic
	spdlog::debug("DETAIL_MAGIC_WATER_INFO");
	for (auto i = 0; i < 2; i++)
	{
		auto info = file->ReadValue<MagicWaterInfo>();
		spdlog::debug("[{}] MagicType={}", i, magic_enum::enum_name(info.magicType));
	}

	// GMagicFlockFlyingInfo::LoadMagic
	spdlog::debug("DETAIL_MAGIC_FLOCK_FLYING_INFO");
	{
		auto info = file->ReadValue<MagicFlockFlyingInfo>();
		spdlog::debug("[{}] MagicType={} : numberToCreate={}", 0, magic_enum::enum_name(info.magicType), info.numberToCreate);
	}

	// GMagicFlockGroundInfo::LoadMagic
	spdlog::debug("DETAIL_MAGIC_FLOCK_GROUND_INFO");
	{
		auto info = file->ReadValue<MagicFlockGroundInfo>();
		spdlog::debug("[{}] MagicType={} : numberToCreate={}", 0, magic_enum::enum_name(info.magicType), info.numberToCreate);
	}

	// GMagicCreatureSpellInfo::LoadMagic
	spdlog::debug("DETAIL_MAGIC_CREATURE_SPELL_INFO");
	for (auto i = 0; i < 16; i++)
	{
		auto info = file->ReadValue<MagicCreatureSpellInfo>();
		spdlog::debug("[{}] MagicType={} text='{}'", i, magic_enum::enum_name(info.magicType), info.text);
	}

	// GMagicEffectInfo::LoadIt
	spdlog::debug("DETAIL_MAGIC_EFFECT_INFO");
	for (auto i = 0; i < 42; i++)
	{
		auto info = file->ReadValue<MagicEffectInfo>();
		spdlog::debug("[{}] debugString='{}'", magic_enum::enum_name(static_cast<MagicType>(i)), info.debugString);
	}

	// GSpellSeedInfo::LoadIt
	spdlog::debug("DETAIL_SPELL_SEEDS");
	for (auto i = 0; i < 30; i++)
	{
		auto info = file->ReadValue<DetailSpellSeed>();
		spdlog::debug("[{}] debugString='{}'", magic_enum::enum_name(static_cast<SpellSeedType>(i)), info.debugString);
	}

	// GAnimalInfo::LoadIt
	spdlog::debug("DETAIL_ANIMAL_INFO");
	for (auto i = 0; i < 31; i++)
	{
		auto info = file->ReadValue<DetailAnimalInfo>();
		spdlog::debug("[{}] debugString='{}'", magic_enum::enum_name(static_cast<AnimalInfo>(i)), info.debugString);
	}

	// CreatureInfo::LoadIt
	spdlog::debug("DETAIL_CREATURE_INFO");
	for (auto i = 0; i < 17; i++)
	{
		auto info = file->ReadValue<DetailCreatureInfo>();
		spdlog::debug("[{}] debugString='{}'", magic_enum::enum_name(static_cast<CreatureType>(i)), info.debugString);
	}

	// DifferentCreatureInfo::LoadIt
	spdlog::debug("DETAIL_CREATURE_BALANCE");
	for (auto i = 0; i < 17; i++)
	{
		auto info = file->ReadValue<DetailCreatureBalance>();
		spdlog::debug("[{}] initialHeight={}", magic_enum::enum_name(static_cast<CreatureType>(i)), info.initialHeight);
	}

	spdlog::debug("DETAIL_CREATURE_DESIRE_INITIAL_CYCLE_TIME");
	for (auto i = 0; i < 40; i++)
	{
		auto info = file->ReadValue<DetailCreatureDesireInitialCycleTime>();
		spdlog::debug("[Desire::{}] {}", magic_enum::enum_name(static_cast<CreatureDesires>(i)), info.creatureTypes[0]);
	}

	spdlog::debug("DETAIL_CREATURE_DEVELOPMENT");
	for (auto i = 0; i < 14; i++)
	{
		auto info = file->ReadValue<DetailCreatureDevelopment>();
	}

	spdlog::debug("DETAIL_CREATURE_DEVELOPS_TIME");
	for (auto i = 0; i < 17; i++)
	{
		auto info = file->ReadValue<DetailCreatureDevelopsTime>();
		spdlog::debug("[{}] = {}", magic_enum::enum_name(static_cast<CreatureType>(i)), info.developmentPhases[0]);
	}

	spdlog::debug("DETAIL_CITADEL_INFO");
	{
		auto info = file->ReadValue<DetailCitadelInfo>();
	}

	spdlog::debug("DETAIL_CITADEL_HEART_INFO");
	{
		auto info = file->ReadValue<DetailCitadelHeartInfo>();
	}

	spdlog::debug("DETAIL_CREATURE_PEN_INFO");
	for (auto i = 0; i < 5; i++)
	{
		auto info = file->ReadValue<DetailCreaturePenInfo>();
		spdlog::debug("{}", info.debugString);
	}

	spdlog::debug("DETAIL_WORSHIP_SITE_INFO");
	for (auto i = 0; i < 9; i++)
	{
		auto info = file->ReadValue<DetailWorshipSiteInfo>();
		spdlog::debug("{}", info.debugString);
	}

	spdlog::debug("DETAIL_SPELL_ICON_INFO");
	for (auto i = 0; i < 2; i++)
	{
		auto info = file->ReadValue<DetailSpellIconInfo>();
		spdlog::debug("{}", info.debugString);
	}

	spdlog::debug("DETAIL_ABODE_INFO");
	for (auto i = 0; i < 147; i++)
	{
		auto info = file->ReadValue<DetailAbodeInfo>();
		spdlog::debug("{} - Mesh: {}", info.debugString, magic_enum::enum_name(info.meshID));
	}


	// DETAIL_VILLAGER_INFO
	// DETAIL_SPECIAL_VILLAGER_INFO
	// DETAIL_TREE_INFO
	// DETAIL_MISC_INFO
	// DETAIL_HIGHLIGHT_INFO
	// DETAIL_MAP_SHIELD_INFO
	// DETAIL_BALL_INFO

	spdlog::debug("info.dat: read {} / {}", file->Position(), file->Size());

	// CreatureDesireForType::LoadIt
	// CreatureDevelopmentPhaseEntry::LoadIt
}
} // namespace openblack
