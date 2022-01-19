#include "PowerUpManager.h"

PowerUpManager::PowerUpManager(SDL_Renderer* renderer, PowerUpData* powerUpData)
	: _renderer(renderer), _powerUpFactory(new PowerUpFactory()), _powerUpCreateData(powerUpData->_powerUpCreateData),
	_powerUpSpawnChance(powerUpData->_powerUpChancePercent),
	_timerPlatform1(0), _timerPlatform2(0)
{
}

PowerUpManager::~PowerUpManager()
{
	delete _powerUpFactory;

	//_platform1 = nullptr;
	//_platform2 = nullptr;
}

void PowerUpManager::Update(const double& elapsedTime)
{
	//UpdatePlatformTimer(elapsedTime, _platform1, _timerPlatform1);
	//UpdatePlatformTimer(elapsedTime, _platform2, _timerPlatform2);
}

void PowerUpManager::Render() const
{
	return;
}

void PowerUpManager::SetSpawnPowerUpCallback(std::function<void(GameObject*)> spawnPowerUpCallback)
{
	_spawnPowerUpCallback = spawnPowerUpCallback;
}




void PowerUpManager::TrySpawnPowerUp(const Vector2D<float>& position, const Vector2D<float>& direction)
{
	if (rand() % 100 <= _powerUpSpawnChance) {
		SpawnRandomPowerUp(position, direction);
	}
}

void PowerUpManager::SpawnRandomPowerUp(const Vector2D<float>& position, const Vector2D<float>& direction)
{
	PowerUpType powerUpType = static_cast<PowerUpType>(rand() % static_cast<int>(PowerUpType::COUNT));
	
	PowerUp* createdPowerUp = _powerUpFactory->Create(powerUpType, _renderer, position, direction, &_powerUpCreateData);
	_spawnPowerUpCallback(createdPowerUp);
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
