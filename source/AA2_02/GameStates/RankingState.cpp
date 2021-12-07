#include "RankingState.h"

RankingState::RankingState(SDL_Renderer* renderer, Player* player1) : GameState(renderer), _player1(player1)
{
}


RankingState::~RankingState()
{
}

void RankingState::DoStart()
{
	std::cout << "RankingState::Start\n";
}

bool RankingState::Update(float elapsedTime)
{
	std::cout << "RankingState::Update\n";
	if (_player1->GetController()->GetButtonDown(ActionName::RESUME)) {
		_nextState = GameStates::MAIN_MENU;
		return true;
	}

	return false;
}

void RankingState::Render() const
{
	std::cout << "RankingState::Render\n";
}

void RankingState::End()
{
	std::cout << "RankingState::End\n";
}
