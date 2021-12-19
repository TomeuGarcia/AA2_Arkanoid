#pragma once
#include "../Systems/LifeSystem.h"
class Player 
{
public:
	Player(const int &lives);
	~Player();
	void LoseLives(const int &amount);
	bool Lost();
	void LosePoints(const int& amount);
	void GainPoints(const int& amount);
	int GetScore() const;

private:
	LifeSystem* _lifeSystem;
	int _score;

};