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

	spdlog::debug("DETAIL_MAGIC_GENERAL_INFO");
	for (auto i = 0; i < 10; i++)
	{
		auto info = file->ReadValue<MagicInfo>();
		spdlog::debug("[{}] MagicType={} : impressiveType={}", i, magic_enum::enum_name(info.magicType), magic_enum::enum_name(info.impressiveType));
	}

	spdlog::debug("DETAIL_MAGIC_HEAL_INFO");
	for (auto i = 0; i < 2; i++)
	{
		auto info = file->ReadValue<MagicHealInfo>();
		spdlog::debug("[{}] MagicType={} : maxToHeal={}", i, magic_enum::enum_name(info.magicType), info.maxToHeal);
	}

	spdlog::debug("DETAIL_MAGIC_TELEPORT_INFO");
	{
		auto info = file->ReadValue<MagicTeleportInfo>();
		spdlog::debug("[{}] MagicType={} : costPerKM={}", 0, magic_enum::enum_name(info.magicType), info.costPerKilometer);
	}

	spdlog::debug("DETAIL_MAGIC_FOREST_INFO");
	{
		auto info = file->ReadValue<MagicForestInfo>();
		spdlog::debug("[{}] MagicType={} : finalNoTrees={}", 0, magic_enum::enum_name(info.magicType), info.finalNoTrees);
	}

	spdlog::debug("DETAIL_MAGIC_FOOD_INFO");
	for (auto i = 0; i < 2; i++)
	{
		auto info = file->ReadValue<MagicFoodInfo>();
		spdlog::debug("[{}] MagicType={} : resourceType={}", i, magic_enum::enum_name(info.magicType), magic_enum::enum_name(info.resourceType));
	}

	spdlog::debug("DETAIL_MAGIC_STORM_AND_TORNADO_INFO");
	for (auto i = 0; i < 3; i++)
	{
		auto info = file->ReadValue<MagicStormAndTornadoInfo>();
		spdlog::debug("[{}] MagicType={} : rainAmount={}", i, magic_enum::enum_name(info.magicType), info.rainAmount);
	}

	spdlog::debug("DETAIL_MAGIC_SHIELD_ONE_INFO");
	for (auto i = 0; i < 2; i++)
	{
		auto info = file->ReadValue<MagicShieldOneInfo>();
		spdlog::debug("[{}] MagicType={} : shieldHeight={}", i, magic_enum::enum_name(info.magicType), info.shieldHeight);
	}

	spdlog::debug("DETAIL_MAGIC_WOOD_INFO");
	{
		auto info = file->ReadValue<MagicWoodInfo>();
		spdlog::debug("[{}] MagicType={} : resourceType={}", 0, magic_enum::enum_name(info.magicType), magic_enum::enum_name(info.resourceType));
	}

	spdlog::debug("DETAIL_MAGIC_WATER_INFO");
	for (auto i = 0; i < 2; i++)
	{
		auto info = file->ReadValue<MagicWaterInfo>();
		spdlog::debug("[{}] MagicType={}", i, magic_enum::enum_name(info.magicType));
	}

	spdlog::debug("DETAIL_MAGIC_FLOCK_FLYING_INFO");
	{
		auto info = file->ReadValue<MagicFlockFlyingInfo>();
		spdlog::debug("[{}] MagicType={} : numberToCreate={}", 0, magic_enum::enum_name(info.magicType), info.numberToCreate);
	}

	spdlog::debug("DETAIL_MAGIC_FLOCK_GROUND_INFO");
	{
		auto info = file->ReadValue<MagicFlockGroundInfo>();
		spdlog::debug("[{}] MagicType={} : numberToCreate={}", 0, magic_enum::enum_name(info.magicType), info.numberToCreate);
	}

	spdlog::debug("DETAIL_MAGIC_CREATURE_SPELL_INFO");
	for (auto i = 0; i < 16; i++)
	{
		auto info = file->ReadValue<MagicCreatureSpellInfo>();
		spdlog::debug("[{}] MagicType={} text='{}'", i, magic_enum::enum_name(info.magicType), info.text);
	}

	spdlog::debug("DETAIL_MAGIC_EFFECT_INFO");
	for (auto i = 0; i < 21; i++)
	{
		auto info = file->ReadValue<MagicEffectInfo>();

		int size = sizeof(MagicEffectInfo);

		//spdlog::debug("[{}] MagicType={} text='{}'", i, magic_enum::enum_name(info.), info.text);
	}
}
} // namespace openblack
