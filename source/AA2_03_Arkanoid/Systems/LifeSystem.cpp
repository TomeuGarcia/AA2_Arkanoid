#include "LifeSystem.h"

LifeSystem::LifeSystem(const int& lives) : _maxLives(lives), _currentLives(lives){}

void LifeSystem::LoseLives(const int& amount)
{
	_currentLives >= amount ? _currentLives -= amount : _currentLives = 0;
	
	
}

bool LifeSystem::HasNoLivesLeft()
{
	return _currentLives==0;
}
