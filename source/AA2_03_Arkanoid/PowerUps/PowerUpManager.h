#pragma once
#include "ExtraLengthPowerUp.h"
#include "MiniLengthPowerUp.h"
#include "../Player/Platform.h"
#include "PowerUpFactory.h"
#include <functional>


class PowerUpManager : public GameObject
{
public:
	PowerUpManager(SDL_Renderer* renderer, PowerUpData* powerUpData);
	~PowerUpManager();

	virtual void Update(const double& elapsedTime) override;
	virtual void Render() const override;

	void SetSpawnPowerUpCallback(std::function<void(PowerUp*)> spawnPowerUpCallback);
	void InstantiateAllPowerUp();

	void TrySpawnPowerUp(const Vector2D<float>& position, const Vector2D<float>& direction);

private:
	SDL_Renderer* _renderer;
	PowerUpFactory* _powerUpFactory;

	PowerUpCreateData _powerUpCreateData;
	float _powerUpSpawnChance;
	std::map<PowerUpType, PowerUp*> _powerUpInstances;

	std::function<void(PowerUp*)> _spawnPowerUpCallback;
};