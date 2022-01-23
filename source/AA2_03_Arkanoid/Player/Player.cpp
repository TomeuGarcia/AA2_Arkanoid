#include "Player.h"
#include "../PowerUps/PowerUp.h"
#include "Platform.h"



Player::Player(const char* name, const int& lives)
	: _name(name), _lifeSystem(new LifeSystem(lives)),_score(0), 
	_powerUpTimer(0.0f), _activePowerUp(nullptr)
{
}

Player::~Player() 
{
	delete _lifeSystem;
	_lifeSystem = nullptr;
}

void Player::Update(const double& elapsedTime)
{
	UpdatePowerEffect(elapsedTime);
}

void Player::Render() const
{
	return;
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

void Player::SetPlatform(Platform* platform)
{
	_platform = platform;
}



void Player::StartPowerUpEffect(PowerUp* powerUp)
{
	_activePowerUp = powerUp;
	_powerUpTimer = powerUp->GetEffectDuration();
}

void Player::UpdatePowerEffect(const double& elapsedTime)
{
	if (_activePowerUp == nullptr)
		return;

	_powerUpTimer -= elapsedTime;
	if (_powerUpTimer <= 0) {
		_activePowerUp->DoFinishEffect(_platform);
		_activePowerUp = nullptr;
		_powerUpTimer == 0.0f;
	}
}



bool operator==(const Player& player1, const Player& player2)
{
	return player1._name == player2._name;
}
