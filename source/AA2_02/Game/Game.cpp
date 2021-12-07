#include "Game.h"

Game::~Game()
{
	delete _player1;

	Release();
}

void Game::Init()
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

void Game::InitStates()
{
	_isStateFinished = false;

	_states[GameStates::SPLASH_SCREEN] = new SplashScreenState;
	_states[GameStates::MAIN_MENU] = new MainMenuState(_player1);
	_states[GameStates::RANKING] = new RankingState(_player1);
	_states[GameStates::GAME_RUNNING] = new GameRunningState(_player1);
	_states[GameStates::GAME_PAUSED] = new GamePausedState(_player1);
	_states[GameStates::GAME_OVER] = new GameOverState();

	_currentGameState = _states[GameStates::SPLASH_SCREEN];
	_currentGameState->Start();
}

void Game::InitSDL()
{
	int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	bool isInitialized = result >= 0;

	if (!isInitialized) {
		SDL_GetError();
	}
}

void Game::InitWindowAndRenderer()
{
	int result = SDL_CreateWindowAndRenderer(512, 512, SDL_WINDOW_SHOWN, &_window, &_renderer);
	bool isInitialized = result >= 0;

	if (!isInitialized) {
		SDL_GetError();
	}
}

void Game::InitAudioSDL()
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

void Game::InitPlayers()
{
	_player1 = new Player;
}



void Game::InitFont()
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



void Game::HandleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			_isRunning = false;
		}

		InputHandler::GetInstance()->HandleEvents(&event);
	}
}

void Game::Update(const double elapsedTime)
{
	_isStateFinished = _currentGameState->Update(elapsedTime);
	if (_isStateFinished) {
		// Acabar estat actual
		_currentGameState->End();
		// Canviar d'estat
		_currentGameState = _states[_currentGameState->GetNextState()];
		// Començar nou estat
		_currentGameState->Start();
	}
}


void Game::Render()
{
	SDL_RenderClear(_renderer);

	SDL_RenderPresent(_renderer);
}


void Game::Release()
{
	Mix_CloseAudio();

	TTF_Quit();

	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool Game::IsRunning()
{
	return _isRunning;
}
