#include "RankingScene.h"

RankingScene::RankingScene(SDL_Renderer* renderer, Player* player1) : Scene(renderer), _player1(player1)
{
}


RankingScene::~RankingScene()
{
}

void RankingScene::DoStart()
{
	std::cout << "RankingScene::Start\n";
}

bool RankingScene::Update(float elapsedTime)
{
	std::cout << "RankingScene::Update\n";
	if (_player1->GetController()->GetButtonDown(ActionName::RESUME)) {
		_nextScene = Scenes::MAIN_MENU;
		return true;
	}

	return false;
}

void RankingScene::Render() const
{
	std::cout << "RankingScene::Render\n";
}

void RankingScene::End()
{
	std::cout << "RankingScene::End\n";
}