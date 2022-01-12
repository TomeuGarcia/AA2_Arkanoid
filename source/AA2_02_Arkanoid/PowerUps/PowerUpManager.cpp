#include "PowerUpManager.h"

PowerUpManager::PowerUpManager(PowerUpFactory* powerUpFactory, Platform* platform1, Platform* platform2, 
	const float& powerUpSpawnChance, const float& powerUpDuration)
	: _powerUpFactory(powerUpFactory),
	_platform1(platform1), _platform2(platform2), _powerUpSpawnChance(powerUpSpawnChance), 
	_powerUpDuration(powerUpDuration), _timerPlatform1(0), _timerPlatform2(0)
{
}

PowerUpManager::~PowerUpManager()
{
	_platform1 = nullptr;
	_platform2 = nullptr;
}

void PowerUpManager::Update(const double& elapsedTime)
{
	UpdatePlatformTimer(elapsedTime, _platform1, _timerPlatform1);
	UpdatePlatformTimer(elapsedTime, _platform2, _timerPlatform2);
}

void PowerUpManager::Render() const
{
	return;
}

void PowerUpManager::SetSpawnPowerUpCallback(std::function<void(GameObject*)> spawnPowerUpCallback)
{
	_spawnPowerUpCallback = spawnPowerUpCallback;
}

void PowerUpManager::SpawnRandomPowerUp(const Vector2D<int> position)
{
	PowerUpType powerUpType = static_cast<PowerUpType>(rand() % static_cast<int>(PowerUpType::COUNT));
	// Add rest of powerup factory create arguments
	//PowerUp* createdPowerUp = _powerUpFactory->Create(powerUpType);
}


void PowerUpManager::UpdatePlatformTimer(const double& elapsedTime, Platform* platform, float& timer)
{
	if (timer < 0)
		return;

	timer -= elapsedTime;
	if (timer <= 0) {
		platform->ResetSize();
		platform->ResetMoveSpeed();
	}
}
