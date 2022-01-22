#include "MainMenuScene.h"


MainMenuScene::MainMenuScene(SDL_Renderer* renderer, bool* isRunning)
	: _isRunning(isRunning), Scene(renderer), _controller(nullptr), _menuMusic(nullptr)
{
}

MainMenuScene::~MainMenuScene() 
{

}

void MainMenuScene::DoStart()
{
	_controller = new Keyboard("keyboard");
	_controller->AddActionKey(ActionName::START, SDLK_SPACE);
	_controller->AddActionKey(ActionName::RANKING, SDLK_r);
	_controller->AddActionKey(ActionName::QUIT, SDLK_ESCAPE);
	_controller->AddActionKey(ActionName::MUSIC_SWITCH, SDLK_m);
	InputHandler::GetInstance()->AddController(_controller);
	InitBackground();
	InitTexts();
	InitMenuMusic();
}

bool MainMenuScene::Update(const double& elapsedTime)
{
	if (_controller->GetButtonDown(ActionName::START)) {
		_nextScene = Scenes::GAME;
		return true;
	}
	else if (_controller->GetButtonDown(ActionName::RANKING)) {
		_nextScene = Scenes::RANKING;
		return true;
	}
	if (_controller->GetButtonDown(ActionName::QUIT)) {
		*_isRunning = false;
	}
	if (_controller->GetButtonDown(ActionName::MUSIC_SWITCH)) {
		AudioHandler::GetInstance()->AudioSwitch();
	}

	UpdateSceneGameObjects(elapsedTime);


	return false;
}

void MainMenuScene::Render() const
{
	RenderSceneGameObjects();
}

void MainMenuScene::End()
{
	InputHandler::GetInstance()->RemoveAllControllers();

	DeleteSceneGameObjects();

	AudioHandler::GetInstance()->MuteAudio();
	AudioHandler::GetInstance()->DeleteMusic(_menuMusic);
}

void MainMenuScene::InitBackground()
{
	ImageGameObject* background = new ImageGameObject(_renderer, "../../resources/assets/images/background.jpg",
		Vector2D<int>(0, 0), SCREEN_SIZE,Vector2D<int>(30, 30), Vector2D<int>(740, 435));

	AddSceneGameObject(background);
}

void MainMenuScene::InitTexts()
{
	SDL_Color white({ 255,255,255,255 });
	TextGameObject* title = new TextGameObject(_renderer, "Main Menu", white, Vector2D<int>(300, 100), 36);
	AddSceneGameObject(title);

	TextGameObject* playGameText = new TextGameObject(_renderer, "Space to Play Game", white, Vector2D<int>(50, 200), 24);
	AddSceneGameObject(playGameText);

	TextGameObject* rankingText = new TextGameObject(_renderer, "R to Ranking", white, Vector2D<int>(50, 300), 24);
	AddSceneGameObject(rankingText);

	TextGameObject* optionsText = new TextGameObject(_renderer, "M to play / stop audio", white, Vector2D<int>(50, 400), 24);
	AddSceneGameObject(optionsText);

	TextGameObject* quitText = new TextGameObject(_renderer, "Esc to Quit", white, Vector2D<int>(50, 500), 24);
	AddSceneGameObject(quitText);
}


void MainMenuScene::InitMenuMusic()
{
	_menuMusic = AudioHandler::GetInstance()->LoadMusic("../../resources/assets/audio/musicMenu.mp3");
	AudioHandler::GetInstance()->PlayMusic(_menuMusic);
}
