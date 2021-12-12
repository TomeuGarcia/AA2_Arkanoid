#include "SceneManager.h"

SceneManager::~SceneManager()
{
	delete _player1;
	delete _player2;
}

void SceneManager::Init()
{
	InitSDL();
	InitWindowAndRenderer();

	InitAudioSDL();

	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);

	InitFont();

	_isRunning = true;

	InitPlayers();
	InitStates();
}

void SceneManager::InitStates()
{
	_isSceneFinished = false;

	_scenes[Scenes::SPLASH_SCREEN] = new SplashScreenScene(_renderer);
	_scenes[Scenes::MAIN_MENU] = new MainMenuScene(_renderer, _player1);
	_scenes[Scenes::RANKING] = new RankingScene(_renderer, _player1);
	_scenes[Scenes::GAME] = new GameScene(_renderer, _player1, _player2);

	_currentScene = _scenes[Scenes::SPLASH_SCREEN];
	_currentScene->Start();
}

void SceneManager::InitSDL()
{
	int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	bool isInitialized = result >= 0;

	if (!isInitialized) {
		SDL_GetError();
	}
}

void SceneManager::InitWindowAndRenderer()
{
	int result = SDL_CreateWindowAndRenderer(512, 512, SDL_WINDOW_SHOWN, &_window, &_renderer);
	bool isInitialized = result >= 0;

	if (!isInitialized) {
		SDL_GetError();
	}
}

void SceneManager::InitAudioSDL()
{
	//Mix_OpenAudio(22050, AUDIO_S16, 2, 4096); // Inicia Audio
	//_audio = Mix_LoadWAV("resources/sound.wav");
	//int channelAudio = Mix_PlayChannel(-1, _audio, 0); // Reproduim audio sobre el primer canal disponible (-1), retorna -1 so no hi ha canal

	//if (channelAudio == -1) {
	//	SDL_GetError();
	//}

	//_music = Mix_LoadMUS("resources/sound.wav");
	//channelAudio = Mix_PlayMusic(_music, -1);

	//if (channelAudio == -1) {
	//	SDL_GetError();
	//}

	//_pauseMusic = false;
	//_resumeMusic = false;
	//_musicVolumeUp = false;
	//_musicVolumeDown = false;
	//_musicVolume = 128;
	//Mix_VolumeMusic(_musicVolume);

}

void SceneManager::InitPlayers()
{
	_player1 = new Player;
	_player1->InitController(SDLK_UP, SDLK_DOWN);

	_player2 = new Player;
	_player2->InitController(SDLK_w, SDLK_s);
}



void SceneManager::InitFont()
{
	//TTF_Init();
	//TTF_Font* font = TTF_OpenFont("resources/Roboto-Black.ttf", 32);
	//SDL_Color color = { 0, 150, 200 };

	//// Option 1.
	////SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "Hello world", color);

	//// Option 2.
	//SDL_Color backgroundColor = { 200, 200, 0, 255 * 0.3 };
	//SDL_Surface* surfaceMessage = TTF_RenderText_Shaded(font, "Hello world", color, backgroundColor);

	//// Option 3.
	////SDL_Surface* surfaceMessage = TTF_RenderText_Blended(font, "Hello world", color);

	//_textTexture = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);
	//SDL_FreeSurface(surfaceMessage);

	//TTF_SizeText(font, "Hello world", &_textRect.w, &_textRect.h);
	//_textRect.x = 0;
	//_textRect.y = 0;

}



void SceneManager::HandleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			_isRunning = false;
		}

		InputHandler::GetInstance()->HandleEvents(&event);
	}
}

void SceneManager::Update(const double elapsedTime)
{
	_isSceneFinished = _currentScene->Update(elapsedTime);
	if (_isSceneFinished) {
		// Acabar estat actual
		_currentScene->End();
		// Canviar d'estat
		_currentScene = _scenes[_currentScene->GetNextState()];
		// Començar nou estat
		_currentScene->Start();
	}
}


void SceneManager::Render()
{
	//SDL_RenderClear(_renderer);

	_currentScene->Render();

	//SDL_RenderPresent(_renderer);
}


void SceneManager::Release()
{
	Mix_CloseAudio();

	TTF_Quit();

	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool SceneManager::IsRunning()
{
	return _isRunning;
}
