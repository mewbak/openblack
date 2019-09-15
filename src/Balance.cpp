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
#include <Game.h>
#include <Common/FileSystem.h>
#include <spdlog/spdlog.h>
#include <Common/magic_enum.hpp>

namespace openblack {
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

	spdlog::debug("info.dat: block name = {} = {} bytes", blockName, size);

	for (auto i = 0; i < 10; i++)
	{
		MagicInfo info;
		file->Read(&info, 0x48);

		spdlog::debug("[{}] MagicType={} = ImpressiveType={}", i, magic_enum::enum_name(info.magicType), magic_enum::enum_name(info.impressiveType));
	}

	// GMagicInfo: 0x48 bytes // DETAIL_MAGIC_GENERAL_INFO
	// 10

	// GMagicHealInfo: 0x48, 0x8 bytes // DETAIL_MAGIC_HEAL_INFO
	// GMagicTeleportInfo: 0x48, 0x8 bytes // DETAIL_MAGIC_TELEPORT_INFO

	// DETAIL_MAGIC_GENERAL_INFO
	// DETAIL_MAGIC_HEAL_INFO
	// DETAIL_MAGIC_TELEPORT_INFO
	// DETAIL_MAGIC_FOREST_INFO
	// DETAIL_MAGIC_FOOD_INFO
	// DETAIL_MAGIC_STORM_AND_TORNADO_INFO
	// DETAIL_MAGIC_SHIELD_ONE_INFO
	// DETAIL_MAGIC_WOOD_INFO
	// DETAIL_MAGIC_WATER_INFO
	// DETAIL_MAGIC_FLOCK_FLYING_INFO
	// DETAIL_MAGIC_FLOCK_GROUND_INFO
	// DETAIL_MAGIC_CREATURE_SPELL_INFO
}
}
