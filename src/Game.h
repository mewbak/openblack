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

#include "GameWindow.h"

#include <LHVM/LHVM.h>
#include <bgfx/bgfx.h>
#include <glm/glm.hpp>

#include <memory>
#include <string>
#include <vector>

namespace openblack
{
class Camera;
class FileSystem;
class GameWindow;
class Gui;
class MeshPack;
class LandIsland;
class Profiler;
class Renderer;
class L3DMesh;
class Sky;
class Water;

namespace lhscriptx
{
class Script;
}

namespace entities
{
class Registry;
}

struct Arguments
{
	std::string executablePath;
	int windowWidth;
	int windowHeight;
	bool vsync;
	openblack::DisplayMode displayMode;
	bgfx::RendererType::Enum rendererType;
	std::string gamePath;
	float scale;
};

class Game
{
public:
	struct Config
	{
		Config() {}

		bool wireframe {false};
		bool waterDebug {false};
		bool showProfiler {false};

		bool drawSky {true};
		bool drawWater {true};
		bool drawIsland {true};
		bool drawEntities {true};
		bool drawDebugCross {true};
		bool drawBoundingBoxes {false};
		bool drawStreams {false};

		float timeOfDay {1.0f};
		float bumpMapStrength {1.0f};
		float smallBumpMapStrength {1.0f};

		bool bgfxDebug {false};
	};

	Game(Arguments&& args);
	virtual ~Game();

	bool ProcessEvents();
	bool Update();
	void Run();

	void LoadMap(const std::string& name);
	void LoadLandscape(const std::string& name);

	void LoadVariables();

	void SetGamePath(const std::string& gamePath);
	const std::string& GetGamePath();

	GameWindow& GetWindow() { return *_window; }
	[[nodiscard]] const GameWindow& GetWindow() const { return *_window; }
	Camera& GetCamera() { return *_camera; }
	[[nodiscard]] Profiler& GetProfiler() const { return *_profiler; }
	[[nodiscard]] Renderer& GetRenderer() const { return *_renderer; }
	[[nodiscard]] Camera& GetCamera() const { return *_camera; }
	[[nodiscard]] Sky& GetSky() const { return *_sky; }
	[[nodiscard]] Water& GetWater() const { return *_water; }
	LandIsland& GetLandIsland() { return *_landIsland; }
	[[nodiscard]] LandIsland& GetLandIsland() const { return *_landIsland; }
	[[nodiscard]] L3DMesh& GetTestModel() const { return *_testModel; }
	MeshPack& GetMeshPack() { return *_meshPack; }
	[[nodiscard]] const LHVM::LHVM* GetLhvm() { return _lhvm.get(); }
	FileSystem& GetFileSystem() { return *_fileSystem; }
	entities::Registry& GetEntityRegistry() { return *_entityRegistry; }
	[[nodiscard]] entities::Registry& GetEntityRegistry() const { return *_entityRegistry; }
	[[nodiscard]] glm::mat4 GetModelMatrix() const;
	Config& GetConfig() { return _config; }
	[[nodiscard]] const Config& GetConfig() const { return _config; }
	[[nodiscard]] const glm::ivec2& GetMousePosition() const { return _mousePosition; }

	static Game* instance() { return sInstance; }

private:
	static Game* sInstance;

	std::string sGamePath; // path to Lionhead Studios Ltd/Black & White folder

	std::unique_ptr<GameWindow> _window;
	std::unique_ptr<Renderer> _renderer;
	std::unique_ptr<Gui> _gui;
	std::unique_ptr<Camera> _camera;
	std::unique_ptr<Profiler> _profiler;

	std::unique_ptr<FileSystem> _fileSystem;
	std::unique_ptr<LandIsland> _landIsland;
	std::unique_ptr<MeshPack> _meshPack;

	std::unique_ptr<L3DMesh> _testModel;
	std::unique_ptr<Sky> _sky;
	std::unique_ptr<Water> _water;
	std::unique_ptr<lhscriptx::Script> _scriptx;
	std::unique_ptr<LHVM::LHVM> _lhvm;
	std::unique_ptr<entities::Registry> _entityRegistry;

	Config _config;

	glm::ivec2 _mousePosition;
	glm::vec3 _intersection;

	glm::vec3 _modelPosition;
	glm::vec3 _modelRotation;
	glm::vec3 _modelScale;
};
} // namespace openblack
