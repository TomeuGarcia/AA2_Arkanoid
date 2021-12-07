#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>
#include <map>


#include "../Player/Player.h"

#include "../Inputs/InputHandler.h"
#include "../Inputs/Keyboard.h"

#include "../GameStates/GameState.h"
#include "../GameStates/SplashScreenState.h"
#include "../GameStates/MainMenuState.h"
#include "../GameStates/RankingState.h"
#include "../GameStates/GameRunningState.h"
#include "../GameStates/GamePausedState.h"
#include "../GameStates/GameOverState.h"

//#include "CollisionsHelper.h"
//#include "Vector2D.h"

class Game {

public:
	Game() = default;
	~Game();

	void Init();
	void InitStates();
	void InitSDL();
	void InitWindowAndRenderer();
	void InitFont();
	void InitAudioSDL();

	void InitPlayers();

	void HandleEvents();
	void Update(const double elapsedTime);
	void Render();
	void Release();

	bool IsRunning();

private:
	GameState* _currentGameState;
	std::map<GameStates, GameState*> _states;
	bool _isStateFinished;

	SDL_Window* _window;
	SDL_Renderer* _renderer;

	Player* _player1;
	Player* _player2;


	//Vector2D<int> _mousePosition;

	bool _isRunning;
};