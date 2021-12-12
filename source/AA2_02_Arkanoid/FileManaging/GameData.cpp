#include "GameData.h"

BrickData::BrickData(const BrickType& brickType, const int& i, const int& j) : _brickType(brickType), _x(i), _y(j) {}


GameData::GameData() : _platformSpeed(0), _levelBricks(), _brickPoints() , _brickStringToBrickType()
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

void GameData::SetLevelBricks(const int& i, const int& j, std::string& type)
{
	_levelBricks.push_back(BrickData(_brickStringToBrickType[type], i, j));
}

int GameData::GetPlatformSpeed() { return _platformSpeed; }

std::list<BrickData> GameData::GetLevelBricks() { return _levelBricks; }

std::map<BrickType, std::pair<int, int>> GameData::GetBrickPoints() { return _brickPoints; }


