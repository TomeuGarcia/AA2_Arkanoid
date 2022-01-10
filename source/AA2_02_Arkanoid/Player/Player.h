#pragma once
#include "../Systems/LifeSystem.h"
class Player 
{
public:
	Player(const char* name, const int &lives);
	~Player();
	void LoseLives(const int &amount);
	bool DidLose();
	void LosePoints(const int& amount);
	void GainPoints(const int& amount);
	int GetScore() const;

	friend bool operator== (const Player& player1, const Player& player2);

private:
	std::string _name;
	LifeSystem* _lifeSystem;
	int _score;

};