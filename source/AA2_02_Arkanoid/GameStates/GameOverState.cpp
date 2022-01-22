#include "GameOverState.h"


GameOverState::GameOverState(SDL_Renderer* renderer, Controller* controller, GameObjects* gameObjects, 
	RankingPlayer* rankingPlayer, FileManager* fileManager)
	: GameState(renderer, gameObjects), _controller(controller),_blackBackground(nullptr),_gameOverText(nullptr),
	_winnerText(nullptr), _goToRankingText(nullptr), _winnerRankingPlayer(rankingPlayer),
	_fileManager(fileManager), _rankingPlayers(nullptr), _rankingPlayerSet(nullptr), _sceneWasShown(false)
{
}

GameOverState::~GameOverState()
{
}


void GameOverState::DoStart()
{
	_sceneWasShown =false;
	InitBlackBackground();
	InitTexts();
}


bool GameOverState::Update(const double& elapsedTime)
{
	if (_sceneWasShown) {
		AskWinnerName(); // input stops execution string
		LoadRanking();
		if (UpdateRanking()) {
			StoreRanking();
		}
		_nextState = GameStates::QUIT_TO_RANKING;
		return true;
	}

	_blackBackground->Update(elapsedTime);
	_gameOverText->Update(elapsedTime);
	_winnerText->Update(elapsedTime);
	_goToRankingText->Update(elapsedTime);

	_sceneWasShown = true;

	return false;
}

void GameOverState::Render() const
{
	RenderGameObjects();
	_blackBackground->Render();
	_gameOverText->Render();
	_winnerText->Render();
	_goToRankingText->Render();
}

void GameOverState::End()
{
	delete _gameOverText;
	delete _winnerText;
	_gameObjects = nullptr;
	_winnerText = nullptr;
	delete _blackBackground;
	_blackBackground = nullptr;

	delete[] _rankingPlayers;
}
void GameOverState::InitBlackBackground()
{
	_blackBackground = new ImageGameObject(_renderer, "../../resources/assets/images/blackBackground.png",
		Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT), Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT), 150);
}
void GameOverState::InitTexts()
{
	SDL_Color white({ 255,255,255,255 });
	std::string winner{ std::string("Winner --> ") + _winnerRankingPlayer->_name.c_str() };

	_gameOverText = new TextGameObject(_renderer, "GAME OVER", white, Vector2D<int>(160, 200), 72);
	_winnerText =  new TextGameObject(_renderer, winner.c_str(), white, Vector2D<int>(170, 300), 36);
	_goToRankingText = new TextGameObject(_renderer, "Ranking Button L", white, Vector2D<int>(280, 350), 24);
}



void GameOverState::AskWinnerName()
{
	std::cout << "Enter winner name: ";
	std::cin >> _winnerRankingPlayer->_name;
}

void GameOverState::LoadRanking()
{
	_rankingPlayers = _fileManager->GetRankingData("../../resources/files/ranking.bin");
}

bool GameOverState::UpdateRanking()
{
	std::set<RankingPlayer> rankingPlayerSet(_rankingPlayers->begin(), _rankingPlayers->end());
	_rankingPlayerSet = &rankingPlayerSet;

	if (rankingPlayerSet.size() < RANKING_SIZE) {
		// Loop to update player score if player already exists in ranking with lesser score
		for (std::set<RankingPlayer>::reverse_iterator rit{ rankingPlayerSet.rbegin() }; rit != rankingPlayerSet.rend(); ++rit) {
			if (rit->_name == _winnerRankingPlayer->_name && rit->_score < _winnerRankingPlayer->_score) {
				rankingPlayerSet.insert(*_winnerRankingPlayer);
				rankingPlayerSet.erase(*rit);
				return true;
			}
		}
		rankingPlayerSet.insert(*_winnerRankingPlayer);
		return true;
	}
	else {

		for (std::set<RankingPlayer>::reverse_iterator rit{ rankingPlayerSet.rbegin() }; rit != rankingPlayerSet.rend(); ++rit) {
			// Add current player if a lesser score is found, then erase the smallest score
			if (rit->_score < _winnerRankingPlayer->_score) {
				rankingPlayerSet.insert(*_winnerRankingPlayer);
				rankingPlayerSet.erase(rankingPlayerSet.begin());
				return true;
			}
			// Update player score if player already exists in ranking with lesser score
			else if (rit->_name == _winnerRankingPlayer->_name && rit->_score < _winnerRankingPlayer->_score) {
				rankingPlayerSet.insert(*_winnerRankingPlayer);
				rankingPlayerSet.erase(*rit);
				return true;
			}
		}
	}

	return false;
}


void GameOverState::StoreRanking()
{
	delete[] _rankingPlayers;

	std::vector<RankingPlayer> rankingPlayers(_rankingPlayerSet->begin(), _rankingPlayerSet->end());
	_rankingPlayers = &rankingPlayers;
	
	_fileManager->StoreRankingData("../../resources/files/ranking.bin", _rankingPlayers);
}

