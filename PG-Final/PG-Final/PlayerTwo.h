#ifndef PLAYERTWO_H
#define PLAYERTWO_H
#include "Character.h"
#include "BulletTwo.h"
#include "Constants.h"
class PlayerTwo : public Character {
	sf::Texture* texture;

	sf::SoundBuffer atkBuffer;
	sf::Sound atk;

	bool isFiring;
	float delay;
	float cooldown;

public:
	PlayerTwo();
	~PlayerTwo();
	void Input(float deltaTime) override;
	void Shoot() override;
};
#endif