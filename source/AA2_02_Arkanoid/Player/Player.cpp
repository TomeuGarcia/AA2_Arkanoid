#include "Player.h"

Player::Player(const int& lives) :_lifeSystem(new LifeSystem(lives)),_score(0)
{

}

Player::~Player() 
{
	delete _lifeSystem;
	_lifeSystem = nullptr;
}

void Player::LoseLives(const int& quantity)
{
	_lifeSystem->LoseLives(quantity);
	
}

bool Player::Lost()
{
	
	return _lifeSystem->HasNoLivesLeft();
}

void Player::LosePoints(const int& quantity)
{

	_score >= quantity ? _score -= quantity : _score = 0;	
}

void Player::GainPoints(const int& quantity)
{
	_score += quantity;
}
