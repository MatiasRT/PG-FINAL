#ifndef PLAYERONE_H
#define PLAYERONE_H
#include "Character.h"
#include "BulletOne.h"
#include "Constants.h"
class PlayerOne : public Character {
	sf::Texture* texture;

	sf::SoundBuffer atkBuffer;
	sf::Sound atk;

	float delay;
public:
	PlayerOne();
	~PlayerOne();
	void Input(float deltaTime, bool& shoot) override;
	void Shoot() override;
};
#endif