#include "GameOverState.h"


GameOverState::GameOverState(SDL_Renderer* renderer, Controller* controller, GameObjects* gameObjects)
	: GameState(renderer, gameObjects), _controller(controller),_blackBackground(nullptr),_gameOverText(nullptr),
	_winnerText(nullptr), _goToRankingText(nullptr)
{
}

GameOverState::~GameOverState()
{
}


void GameOverState::DoStart()
{
	InitBlackBackground();
	InitTexts();
}


bool GameOverState::Update(const double& elapsedTime)
{
	if (_controller->GetButtonDown(ActionName::RESUME)) {
		_nextState = GameStates::QUIT_TO_RANKING;
		return true;
	}

	_blackBackground->Update(elapsedTime);
	_gameOverText->Update(elapsedTime);
	_winnerText->Update(elapsedTime);
	_goToRankingText->Update(elapsedTime);
	return false;
}

void GameOverState::Render() const
{
	SDL_RenderClear(_renderer);

	RenderGameObjects();
	_blackBackground->Render();
	_gameOverText->Render();
	_winnerText->Render();
	_goToRankingText->Render();

	SDL_RenderPresent(_renderer);
}

void GameOverState::End()
{
	delete _gameOverText;
	delete _winnerText;
	_gameObjects = nullptr;
	_winnerText = nullptr;
	delete _blackBackground;
	_blackBackground = nullptr;
}
void GameOverState::InitBlackBackground()
{
	_blackBackground = new ImageGameObject(_renderer, "../../resources/assets/images/blackBackground.png",
		Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT), Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT), 150);
}
void GameOverState::InitTexts()
{
	SDL_Color white({ 255,255,255,255 });
	_gameOverText = new TextGameObject(_renderer, "GAME OVER", white, Vector2D<int>(160, 200), 72);
	_winnerText =  new TextGameObject(_renderer, "Winner --> Player 1", white, Vector2D<int>(170, 300), 36);
	_goToRankingText = new TextGameObject(_renderer, "Ranking Button L", white, Vector2D<int>(280, 350), 24);
}