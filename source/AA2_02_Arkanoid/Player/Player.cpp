#include "Player.h"

Player::Player(const int& lives) :_lifeSystem(new LifeSystem(lives)),_score(0)
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

bool Player::Lost()
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
