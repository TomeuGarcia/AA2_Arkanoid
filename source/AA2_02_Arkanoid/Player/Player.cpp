#include "Player.h"

Player::Player(const char* name, const int& lives) 
	: _name(name), _lifeSystem(new LifeSystem(lives)),_score(0)
{

}

Player::~Player() 
{
	delete _lifeSystem;
	_lifeSystem = nullptr;
}

void Player::LoseLives(const int& amount)
{
	_lifeSystem->LoseLives(amount);
	
}

bool Player::DidLose()
{
	
	return _lifeSystem->HasNoLivesLeft();
}

void Player::LosePoints(const int& amount)
{

	_score >= amount ? _score -= amount : _score = 0;
}

void Player::GainPoints(const int& amount)
{
	_score += amount;
}

int Player::GetScore() const
{
	return _score;
}

bool operator==(const Player& player1, const Player& player2)
{
	return player1._name == player2._name;
}
