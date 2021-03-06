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
 *
 * The layout of a LND File is as follows:
 *
 * - 1052 byte header, containing ints and a 1024 table
 *         block count - number of blocks in block section (see below)
 *         look-up table - block index look-up table
 *         material count - number of materials in materials section (see below)
 *         country count - number of countries in country section (see below)
 *         block size - size of each block in blocks section (see below)
 *         material size - size of each material in materials section (see
 *                         below)
 *         country size - size of each country in country section (see below)
 *         low resolution count - number of low-resolution textures (see below)
 *
 * ------------------------ start of low resolution textures block -------------
 *
 * - variable size * low resolution count, each record contains:
 *         unknown 16 bytes - TODO(bwrsandman)
 *         texture size - Size of the S3 data plus the variable itself
 *         S3 texture data - Texture compressed using S3
 *
 * ------------------------ start of land block block --------------------------
 *
 * - block size (2520 bytes) * block count, each record contains:
 *         a 17 by 17 grid of cells, each cell contains:
 *                 r, g, b values of 1 byte each
 *                 1 byte luminosity value
 *                 1 byte altitude value
 *                 1 byte save color boolean
 *                 1 byte flag for properties where:
 *                         The upper 4 bits represent the country code
 *                         1 bit represents if there is water
 *                         1 bit represents if it is a coast line
 *                         1 bit represents if it is fully water TODO: Deep Water?
 *                         1 bit represents if there is a split
 *                 1 byte flag for sound effects
 *         index
 *         map X
 *         map Z
 *         block X
 *         block Z
 *         clipped
 *         frameVisibility
 *         highestAltitude
 *         useSmallBump
 *         forceLowResTex
 *         meshLOD
 *         meshBlending
 *         textureBlend
 *         meshLODType
 *         fog
 *         texPointer
 *         matPointer
 *         drawSomething
 *         specMatBeforePtr
 *         specMatAfterPtr
 *         transformUVBefore - a matrix
 *         transformUVAfter - a matrix
 *         nextSortingPtr
 *         valueSorting
 *         lowResTexture
 *         fu_lrs
 *         fv_lrs
 *         iu_lrs
 *         iv_lrs
 *         smallTextUpdated
 *
 * ------------------------ start of county block ------------------------------
 *
 * - country size (3076 bytes) * country count, each record contains:
 *         type - type of terrain
 *         sized 256 map, each record contains:
 *                 two material indices
 *                 coefficient
 *
 * ------------------------ start of material block ----------------------------
 *
 * - material size (131074 bytes) * material count, each record contains:
 *         type - type of terrain
 *         texture data - size of 256 by 256 of R5G5B5A1 encoded texels
 *
 * ------------------------ start of extra texture block -----------------------
 *
 * - 2 * 65536, each texture contains:
 *         noise - noise texture
 *         bump - bump map
 *
 * ------------------------ start of unaccounted block -------------------------
 *
 * // TODO(bwrsandman)
 *
 * ------------------------ end of file ----------------------------------------
 */

#include <lnd_file.h>

#include <cassert>
#include <fstream>
#include <stdexcept>

using namespace openblack::lnd;

LNDFile::LNDFile(): _isLoaded(false) {}

/// Error handling
void LNDFile::Fail(const std::string& msg)
{
	throw std::runtime_error("LND Error: " + msg + "\nFilename: " + _filename);
}

void LNDFile::ReadFile(std::istream& stream)
{
	assert(!_isLoaded);

	// Total file size
	std::size_t fsize = 0;
	if (stream.seekg(0, std::ios_base::end))
	{
		fsize = static_cast<std::size_t>(stream.tellg());
		stream.seekg(0);
	}

	if (fsize < sizeof(LNDHeader))
	{
		Fail("File too small to be a valid LND file.");
	}

	// First 1052 bytes
	stream.read(reinterpret_cast<char*>(&_header), sizeof(LNDHeader));

	if (_header.blockSize != sizeof(LNDBlock))
	{
		Fail("File has non standard block size got " + std::to_string(_header.blockSize) + " expected " + std::to_string(sizeof(LNDBlock)));
	}
	if (_header.materialSize != sizeof(LNDMaterial))
	{
		Fail("File has non standard material size got " + std::to_string(_header.materialSize) + " expected " + std::to_string(sizeof(LNDMaterial)));
	}
	if (_header.countrySize != sizeof(LNDCountry))
	{
		Fail("File has non standard country size got " + std::to_string(_header.countrySize) + " expected " + std::to_string(sizeof(LNDCountry)));
	}

	// Read low resolution textures
	_lowResolutionTextures.resize(_header.lowResolutionCount);
	for (auto& texture : _lowResolutionTextures)
	{
		stream.read(reinterpret_cast<char*>(&texture.header), sizeof(texture.header));
		texture.texels.resize(texture.header.size - sizeof(texture.header.size));
		stream.read(reinterpret_cast<char*>(texture.texels.data()), texture.texels.size() * sizeof(texture.texels[0]));
	}

	// Read Blocks
	// take away a block from the count, because it's not in the file?
	_blocks.resize(_header.blockCount - 1);
	if (static_cast<std::size_t>(stream.tellg()) + _blocks.size() * sizeof(_blocks[0]) > fsize)
	{
		Fail("Blocks are beyond the end of the file");
	}
	stream.read(reinterpret_cast<char*>(_blocks.data()), _blocks.size() * sizeof(_blocks[0]));

	// Read Countries
	_countries.resize(_header.countryCount);
	if (static_cast<std::size_t>(stream.tellg()) + _countries.size() * sizeof(_countries[0]) > fsize)
	{
		Fail("Countries are beyond the end of the file");
	}
	stream.read(reinterpret_cast<char*>(_countries.data()), _countries.size() * sizeof(_countries[0]));

	// Read Materials
	_materials.resize(_header.materialCount);
	if (static_cast<std::size_t>(stream.tellg()) + _materials.size() * sizeof(_materials[0]) > fsize)
	{
		Fail("Materials are beyond the end of the file");
	}
	stream.read(reinterpret_cast<char*>(_materials.data()), _materials.size() * sizeof(_materials[0]));

	// Read Extra textures (noise and bump map)
	if (static_cast<std::size_t>(stream.tellg()) + sizeof(_extra) > fsize)
	{
		Fail("Extra Textures are beyond the end of the file");
	}
	stream.read(reinterpret_cast<char*>(&_extra), sizeof(_extra));

	// Get all bytes that weren't read
	if (stream.peek() != EOF)
	{
		_unaccounted.resize(static_cast<std::size_t>(fsize - stream.tellg()));
		stream.read(reinterpret_cast<char*>(_unaccounted.data()), _unaccounted.size() * sizeof(_unaccounted[0]));
	}

	if (stream.peek() != EOF)
	{
		Fail("Parsing ended without reaching end of file");
	}
}

void LNDFile::WriteFile(std::ostream& stream) const
{
	// First 1052 bytes
	stream.write(reinterpret_cast<const char*>(&_header), sizeof(LNDHeader));

	// Write low resolution textures
	for (auto& texture : _lowResolutionTextures)
	{
		stream.write(reinterpret_cast<const char*>(&texture.header), sizeof(texture.header));
		stream.write(reinterpret_cast<const char*>(texture.texels.data()), texture.texels.size() * sizeof(texture.texels[0]));
	}

	// Write Blocks
	stream.write(reinterpret_cast<const char*>(_blocks.data()), _blocks.size() * sizeof(_blocks[0]));

	// Read Countries
	stream.write(reinterpret_cast<const char*>(_countries.data()), _countries.size() * sizeof(_countries[0]));

	// Read Materials
	stream.write(reinterpret_cast<const char*>(_materials.data()), _materials.size() * sizeof(_materials[0]));

	// Read Extra textures (noise and bump map)
	stream.write(reinterpret_cast<const char*>(&_extra), sizeof(_extra));

	// TODO(bwrsandman): Figure out what the unaccounted bytes are for and write
	//                   them to the file
	stream.write(reinterpret_cast<const char*>(_unaccounted.data()), _unaccounted.size() * sizeof(_unaccounted[0]));
}

void LNDFile::Open(const std::string& file)
{
	assert(!_isLoaded);

	_filename = file;

	std::ifstream stream(_filename, std::ios::binary);

	if (!stream.is_open())
	{
		Fail("Could not open file.");
	}

	ReadFile(stream);
}

void LNDFile::Write(const std::string& file)
{
	assert(!_isLoaded);

	_filename = file;

	std::ofstream stream(_filename, std::ios::binary);

	if (!stream.is_open())
	{
		Fail("Could not open file.");
	}

	// Prepare header
	_header.blockCount = static_cast<uint32_t>(_blocks.size() + 1);
	_header.materialCount = static_cast<uint32_t>(_materials.size());
	_header.countryCount = static_cast<uint32_t>(_countries.size());
	_header.blockSize = static_cast<uint32_t>(sizeof(LNDBlock));
	_header.materialSize = static_cast<uint32_t>(sizeof(LNDMaterial));
	_header.countrySize = static_cast<uint32_t>(sizeof(LNDCountry));
	_header.lowResolutionCount = static_cast<uint32_t>(_lowResolutionTextures.size());

	WriteFile(stream);
}
