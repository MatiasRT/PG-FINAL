#ifndef PLAYERONE_H
#define PLAYERONE_H
#include "Character.h"
#include "BulletOne.h"

class PlayerOne : public Character {
	sf::Texture* texture;

	sf::SoundBuffer atkBuffer;
	sf::Sound atk;

	bool isFiring;
	float delay;
	float cooldown;

public:
	PlayerOne();
	~PlayerOne();
	void Input(float deltaTime) override;
	void Shoot() override;
};
#endif