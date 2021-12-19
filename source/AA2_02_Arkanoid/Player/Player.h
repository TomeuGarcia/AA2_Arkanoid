#pragma once
#include "../Systems/LifeSystem.h"
class Player 
{
public:
	Player(const int &lives);
	~Player();
	void LoseLives(const int &quantity);
	bool Lost();
	void LosePoints(const int& quantity);
	void GainPoints(const int& quantity);


private:
	LifeSystem* _lifeSystem;
	int _score;



};