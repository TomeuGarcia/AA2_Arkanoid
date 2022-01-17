#pragma once
#include "ExtraLengthPowerUp.h"
#include "MiniLengthPowerUp.h"
#include "../Player/Platform.h"
#include "PowerUpFactory.h"
#include <functional>


class PowerUpManager : public GameObject
{
public:
	PowerUpManager(SDL_Renderer* renderer, PowerUpData* powerUpData, Platform* platform1, Platform* platform2);
	~PowerUpManager();

	virtual void Update(const double& elapsedTime) override;
	virtual void Render() const override;

	void SetSpawnPowerUpCallback(std::function<void(GameObject*)> spawnPowerUpCallback);

	void TrySpawnPowerUp(const Vector2D<float>& position, const Vector2D<float>& direction);
	void SpawnRandomPowerUp(const Vector2D<float>& position, const Vector2D<float>& direction);

private:
	void UpdatePlatformTimer(const double& elapsedTime, Platform* platform, float& timer);

	SDL_Renderer* _renderer;
	PowerUpFactory* _powerUpFactory;

	PowerUpCreateData _powerUpCreateData;
	float _powerUpSpawnChance;
	
	Platform* _platform1;
	float _timerPlatform1;
	Platform* _platform2;
	float _timerPlatform2;

	std::function<void(GameObject*)> _spawnPowerUpCallback;
};