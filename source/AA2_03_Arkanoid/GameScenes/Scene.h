#pragma once
#include <iostream>
#include "../Inputs/InputHandler.h"
#include "../GameObjects/ImageGameObject.h"
#include "../GameObjects/TextGameObject.h"
#include "../Constants/Constants.h"
#include "../Inputs/Keyboard.h"
#include "../Audio/AudioHandler.h"

enum class Scenes{NONE, SPLASH_SCREEN, MAIN_MENU, RANKING, GAME, QUIT};

class Scene {

public:
	Scene(SDL_Renderer* renderer) 
		: _nextScene(Scenes::NONE), _renderer(renderer), _sceneGameObjects() {}
	virtual ~Scene() = default;

	void Start() {
		_nextScene = Scenes::NONE;
		DoStart();
	}
	virtual bool Update(const double& elapsedTime) = 0;
	virtual void Render() const = 0;
	virtual void End() = 0;

	Scenes GetNextState() const { return _nextScene; }

protected:
	virtual void DoStart() = 0;
	void UpdateSceneGameObjects(const double& elapsedTime);
	void RenderSceneGameObjects() const;
	void DeleteSceneGameObjects();
	void AddSceneGameObject(GameObject* gameObject);

	Scenes _nextScene;
	SDL_Renderer* _renderer;

private:
	std::vector<GameObject*> _sceneGameObjects;
};