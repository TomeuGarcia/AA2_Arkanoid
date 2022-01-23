#pragma once
#include "../Systems/LifeSystem.h"
#include "../GameObjects/GameObject.h"

class PowerUp;
class Platform;

class Player : public GameObject
{
public:
	Player(const char* name, const int &lives);
	~Player();

	virtual void Update(const double& elapsedTime) override;
	virtual void Render() const override;

	void LoseLives(const int &amount);
	bool DidLose();
	void LosePoints(const int& amount);
	void GainPoints(const int& amount);
	int GetScore() const;

	void SetPlatform(Platform* platform);

	void StartPowerUpEffect(PowerUp* powerUp);

	friend bool operator== (const Player& player1, const Player& player2);

private:
	void UpdatePowerEffect(const double& elapsedTime);


	std::string _name;
	LifeSystem* _lifeSystem;
	int _score;

	Platform* _platform;
	float _powerUpTimer;

	PowerUp* _activePowerUp;
};