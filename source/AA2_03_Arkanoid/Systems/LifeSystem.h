#pragma once
#include <iostream>
class LifeSystem
{
private:
	int _maxLives;
	int _currentLives;
public:
	LifeSystem(const int &lives);
	~LifeSystem()=default;
	void LoseLives(const int &amount);
	bool HasNoLivesLeft();
};