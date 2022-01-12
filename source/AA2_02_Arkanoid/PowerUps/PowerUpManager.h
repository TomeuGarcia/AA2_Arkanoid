#pragma once
#include "ExtraLengthPowerUp.h"
#include "MiniLengthPowerUp.h"
#include "../Player/Platform.h"
#include "PowerUpFactory.h"
#include <functional>


class PowerUpManager : public GameObject
{
public:
	PowerUpManager(PowerUpFactory* powerUpFactory, Platform* platform1, Platform* platform2, 
		const float& powerUpSpawnChance, const float& powerUpDuration);
	~PowerUpManager();

	virtual void Update(const double& elapsedTime) override;
	virtual void Render() const override;

	void SetSpawnPowerUpCallback(std::function<void(GameObject*)> spawnPowerUpCallback);
	void SpawnRandomPowerUp(const Vector2D<int> position);

private:
	void UpdatePlatformTimer(const double& elapsedTime, Platform* platform, float& timer);

	PowerUpFactory* _powerUpFactory;

	float _powerUpSpawnChance;
	float _powerUpDuration;
	
	Platform* _platform1;
	float _timerPlatform1;
	Platform* _platform2;
	float _timerPlatform2;

	std::function<void(GameObject*)> _spawnPowerUpCallback;
};