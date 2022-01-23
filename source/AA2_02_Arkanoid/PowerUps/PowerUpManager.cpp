#include "PowerUpManager.h"

PowerUpManager::PowerUpManager(SDL_Renderer* renderer, PowerUpData* powerUpData)
	: _renderer(renderer), _powerUpFactory(new PowerUpFactory()), _powerUpCreateData(powerUpData->_powerUpCreateData),
	_powerUpSpawnChance(powerUpData->_powerUpChancePercent), _powerUpInstances()
{
}

PowerUpManager::~PowerUpManager()
{
	delete _powerUpFactory;
}

void PowerUpManager::Update(const double& elapsedTime)
{
	return;
}

void PowerUpManager::Render() const
{
	return;
}

void PowerUpManager::SetSpawnPowerUpCallback(std::function<void(PowerUp*)> spawnPowerUpCallback)
{
	_spawnPowerUpCallback = spawnPowerUpCallback;
}


void PowerUpManager::InstantiateAllPowerUp()
{
	PowerUp* powerUp;
	for (int i{ 0 }; i < static_cast<int>(PowerUpType::COUNT); ++i) {
		powerUp = _powerUpFactory->Create(static_cast<PowerUpType>(i), _renderer, { 0,0 }, { 0,0 }, &_powerUpCreateData);
		_spawnPowerUpCallback(powerUp);
		_powerUpInstances[static_cast<PowerUpType>(i)] = powerUp;
		powerUp->SetActive(false);
	}

}



void PowerUpManager::TrySpawnPowerUp(const Vector2D<float>& position, const Vector2D<float>& direction)
{
	if (rand() % 100 <= _powerUpSpawnChance) {

		PowerUpType powerUpType = static_cast<PowerUpType>(rand() % static_cast<int>(PowerUpType::COUNT));

		if (!_powerUpInstances[powerUpType]->IsActive()) {
			_powerUpInstances[powerUpType]->ResetPositionAndDirection(position, direction);
			_powerUpInstances[powerUpType]->SetActive(true);
		}
	}
}

