#pragma once
#include "GameState.h"

class RankingState : public GameState {
public:
	RankingState(Player* player1);
	~RankingState();
	virtual void DoStart();
	virtual bool Update(float elapsedTime);
	virtual void Render() const;
	virtual void End();

private:
	Player* _player1;
};
