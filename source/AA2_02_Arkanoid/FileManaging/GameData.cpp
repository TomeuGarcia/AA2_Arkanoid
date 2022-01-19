#include "GameData.h"

BrickData::BrickData(const BrickType& brickType, const int& i, const int& j) 
	: _brickType(brickType), _x(i), _y(j) 
{}


PowerUpCreateData::PowerUpCreateData(const float& powerUpDuration, const float& powerUpSpeed,
	const float& sizeIncreasePercent, const float& sizeDecreasePercent, const float& speedIncreasePercent)
	: _powerUpDuration(powerUpDuration), _powerUpSpeed(powerUpSpeed), 
	_sizeIncreasePercent(sizeIncreasePercent/100.0f), _sizeDecreasePercent(sizeDecreasePercent/100.0f), _speedIncreasePercent(speedIncreasePercent/100.0f)
{}

PowerUpData::PowerUpData() 
	: _powerUpChancePercent(0),	_powerUpCreateData(0, 0, 0, 0, 0)
{}

PowerUpData::PowerUpData(const float& powerUpChancePercent, const float& powerUpDuration, const float& powerUpSpeed, 
	const float& sizeIncreasePercent, const float& sizeDecreasePercent, const float& speedIncreasePercent)
	: _powerUpChancePercent(powerUpChancePercent), 
	_powerUpCreateData(powerUpDuration, powerUpSpeed, sizeIncreasePercent, sizeDecreasePercent, speedIncreasePercent)
{}


GameData::GameData() : _platformSpeed(0), _ballSpeed(0), _levelBricks(), _brickPoints() , _brickStringToBrickType(), _powerUpData()
{
	_brickStringToBrickType[std::string("N")] = BrickType::NORMAL;
	_brickStringToBrickType[std::string("H")] = BrickType::HEAVY;
	_brickStringToBrickType[std::string("F")] = BrickType::FIX;
	_brickStringToBrickType[std::string("Normal")] = BrickType::NORMAL;
	_brickStringToBrickType[std::string("Heavy")] = BrickType::HEAVY;
	_brickStringToBrickType[std::string("Fix")] = BrickType::FIX;
}


void GameData::SetBrickInfo(std::string& brickType, const int& min, const int& max)
{
	_brickPoints[_brickStringToBrickType[brickType]] = { min, max };
}

void GameData::SetPlatformSpeed(const int& platformSpeed)
{
	_platformSpeed = platformSpeed;
}

void GameData::SetBallSpeed(const int& ballSpeed)
{
	_ballSpeed = ballSpeed;
}

void GameData::SetLevelBricks(const int& i, const int& j, std::string& type)
{
	_levelBricks.push_back(BrickData(_brickStringToBrickType[type], i, j));
}


int GameData::GetPlatformSpeed() { return _platformSpeed; }

int GameData::GetBallSpeed()
{
	return _ballSpeed;
}

std::list<BrickData> GameData::GetLevelBricks() { return _levelBricks; }

std::map<BrickType, std::pair<int, int>> GameData::GetBrickPoints() { return _brickPoints; }



void GameData::SetPowerUpData(const float& powerUpChancePercent, const float& powerUpDuration, const float& powerUpSpeed,
	const float& sizeIncreasePercent, const float& sizeDecreasePercent, const float& speedIncreasePercent)
{
	_powerUpData = PowerUpData(powerUpChancePercent, powerUpDuration, powerUpSpeed, sizeIncreasePercent,
		sizeDecreasePercent, speedIncreasePercent);
}


PowerUpData GameData::GetPowerUpData() const
{
	return _powerUpData;
}