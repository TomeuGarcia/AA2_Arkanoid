#include "RankingScene.h"

RankingScene::RankingScene(SDL_Renderer* renderer) 
	: Scene(renderer), _controller(nullptr), _fileManager(new FileManager())
{
}


RankingScene::~RankingScene()
{
}

void RankingScene::DoStart()
{
	_controller = new Keyboard("keyboard");
	_controller->AddActionKey(ActionName::RESUME, SDLK_ESCAPE);
	InputHandler::GetInstance()->AddController(_controller);
	InitBackground();
	InitRanking();
	InitTexts();
}


bool RankingScene::Update(const double& elapsedTime)
{
	if (_controller->GetButtonDown(ActionName::RESUME)) {
		_nextScene = Scenes::MAIN_MENU;
		return true;
	}

	UpdateSceneGameObjects(elapsedTime);

	return false;
}

void RankingScene::Render() const
{
	RenderSceneGameObjects();
}

void RankingScene::End()
{
	InputHandler::GetInstance()->RemoveAllControllers();
	_ranking.clear();
	DeleteSceneGameObjects();

	delete _fileManager;
	delete[] _rankingPlayerSet;
}

void RankingScene::InitBackground()
{
	ImageGameObject* _background = new ImageGameObject(_renderer, "../../resources/assets/images/background.jpg",
		Vector2D<int>(0, 0), SCREEN_SIZE, Vector2D<int>(30, 30), Vector2D<int>(740, 435));
	AddSceneGameObject(_background);
}

void RankingScene::InitTexts()
{
	SDL_Color white({ 255,255,255,255 });
	TextGameObject* title = new TextGameObject(_renderer, "Ranking:", white, Vector2D<int>(300, 100), 36);
	AddSceneGameObject(title);
	TextGameObject* mainMenuText = new TextGameObject(_renderer, "ESC to Menu", white, Vector2D<int>(580, 550), 24);
	AddSceneGameObject(mainMenuText);


	int i{ 0 };
	std::string nameAndScore("");
	for (std::set<RankingPlayer>::reverse_iterator rit{ _rankingPlayerSet->rbegin() }; rit != _rankingPlayerSet->rend(); ++rit, ++i) {

		nameAndScore = std::to_string(i + 1) + rit->_name + " - " + std::to_string(rit->_score);

		_ranking.push_back(new TextGameObject(_renderer, nameAndScore.c_str(),
			white, Vector2D<int>(320, 160 + i * (40)), 20));
		AddSceneGameObject(_ranking[i]);
	}

	for (; i < RANKING_SIZE; ++i) {

		nameAndScore = std::to_string(i + 1) + std::string(". ---");

		_ranking.push_back(new TextGameObject(_renderer, nameAndScore.c_str(),
			white, Vector2D<int>(320, 160 + i * (40)), 20));
		AddSceneGameObject(_ranking[i]);
	}

}

void RankingScene::InitRanking()
{
	std::vector<RankingPlayer>* _rankingPlayers = _fileManager->GetRankingData("../../resources/files/ranking.bin");

	std::set<RankingPlayer> rankingPlayerSet(_rankingPlayers->begin(), _rankingPlayers->end());
	_rankingPlayerSet = &rankingPlayerSet;
}

